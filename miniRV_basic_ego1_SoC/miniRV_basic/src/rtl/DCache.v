`timescale 1ns / 1ps

`include "defines.vh"

// 主存地址位宽：32bit
// Cache容量：1KB
// Cache块大小：128bit (4*32bit)
// Cache块个数：64

module DCache(
    input  wire         cpu_clk,
    input  wire         cpu_rst,        // high active
    // Interface to CPU
    input  wire [ 3:0]  data_ren,       // 来自CPU的读使能信号
    input  wire [31:0]  data_addr,      // 来自CPU的地址（读、写共用）
    output reg          data_valid,     // 输出给CPU的数据有效信号
    output reg  [31:0]  data_rdata,     // 输出给CPU的读数据
    input  wire [ 3:0]  data_wen,       // 来自CPU的写使能信号
    input  wire [31:0]  data_wdata,     // 来自CPU的写数据
    output reg          data_wresp,     // 输出给CPU的写响应（高电平表示DCache已完成写操作）
    // Interface to Write Bus
    input  wire         dev_wrdy,       // 主存/外设的写就绪信号（高电平表示主存/外设可接收DCache的写请求）
    output reg  [ 3:0]  cpu_wen,        // 输出给主存/外设的写使能信号
    output reg  [31:0]  cpu_waddr,      // 输出给主存/外设的写地址
    output reg  [31:0]  cpu_wdata,      // 输出给主存/外设的写数据
    // Interface to Read Bus
    input  wire         dev_rrdy,       // 主存/外设的读就绪信号（高电平表示主存/外设可接收DCache的读请求）
    output reg  [ 3:0]  cpu_ren,        // 输出给主存/外设的读使能信号
    output reg  [31:0]  cpu_raddr,      // 输出给主存/外设的读地址
    input  wire         dev_rvalid,     // 来自主存/外设的数据有效信号
    input  wire [`DC_BLK_SIZE-1:0] dev_rdata // 来自主存/外设的读数据
);

`ifdef ENABLE_DCACHE    /******** 不要修改此行代码 ********/

    // TODO: 定义DCache读写状态机的状态及状态变量 (提前声明以供地址锁存逻辑使用)
    localparam R_IDLE  = 2'b00;
    localparam R_STAT0 = 2'b01;
    localparam R_STAT1 = 2'b11;
    reg [1:0] r_state, r_nstat;
    reg [3:0] ren_r;
    reg [31:0] read_addr_r; // 保存CPU原始读地址，避免块对齐后丢失字偏移

    localparam W_IDLE  = 2'b00;
    localparam W_STAT0 = 2'b01;
    localparam W_STAT1 = 2'b11;
    wire [133:0] cache_line_r;                     // 从DCache读出的Cache块
    reg [1:0] w_state, w_nstat;
    reg [3:0] wen_r;
    wire      wr_resp = dev_wrdy & (cpu_wen == 4'h0) ? 1'b1 : 1'b0;

    // Cache查找和回填始终使用CPU原始地址；cpu_raddr仅作为发往总线的地址。
    wire [31:0] current_addr   = (w_state != W_IDLE) ? cpu_waddr : 
                                 ((r_state != R_IDLE) ? read_addr_r : data_addr);
    wire        uncached      = (current_addr[31:16] == 16'hFFFF);

    wire [ 4:0] tag_from_cpu   = current_addr[14:10]; // 32KB主存地址的TAG字段
    wire [ 1:0] offset         = current_addr[3:2];   // 32位字偏移量
    wire        valid_bit      = (cache_line_r[133] === 1'b1); // Cache块的有效位
    wire [ 4:0] tag_from_cache = cache_line_r[132:128]; // Cache块的TAG字段

    wire hit_r = (tag_from_cache == tag_from_cpu) && valid_bit && !uncached && (r_state == R_STAT0); // 读命中
    wire hit_w = (tag_from_cache == tag_from_cpu) && valid_bit && !uncached && (w_state != W_IDLE);  // 写命中

    always @(*) begin
        data_valid = hit_r || (r_state == R_STAT1 && dev_rvalid);
        
        // TODO: 根据字偏移，选择Cache行中的某个32位字输出数据 
        if (hit_r) begin
            data_rdata = cache_line_r[offset * 32 +: 32];
        end else if (r_state == R_STAT1 && dev_rvalid) begin
            // 注意uncached访问时直接取低32位
            data_rdata = uncached ? dev_rdata[31:0] : dev_rdata[offset * 32 +: 32];
        end else begin
            data_rdata = 32'h0;
        end
    end

    reg  [127:0] wr_cache_data;                   // 写命中时写入DCache的数据块
    // DCache写使能：读缺失时写回进货块，写命中时修改指定字节
    wire         cache_we     = (r_state == R_STAT1 && dev_rvalid && !uncached) || 
                                (w_state == W_STAT1 && wr_resp && hit_w); 
    wire [ 5:0]  cache_index  = current_addr[9:4]; // 主存地址的Cache索引 / DCache存储体的地址
    wire [133:0] cache_line_w = (r_state == R_STAT1) ? {1'b1, current_addr[14:10], dev_rdata} :
                                                       {1'b1, current_addr[14:10], wr_cache_data}; // 待写入DCache的新Cache块

    // DCache存储体：Block MEM IP核
    blk_mem_gen_1 U_dsram (
        .clka   (cpu_clk),
        .wea    (cache_we),
        .addra  (cache_index),
        .dina   (cache_line_w),
        .douta  (cache_line_r)
    );

    // TODO: 编写DCache读状态机现态的更新逻辑
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) r_state <= R_IDLE;
        else         r_state <= r_nstat;
    end

    // TODO: 编写DCache读状态机的状态转移逻辑（注意处理uncached访问）
    always @(*) begin
        case (r_state)
            R_IDLE:  r_nstat = (|data_ren) ? R_STAT0 : R_IDLE;
            R_STAT0: r_nstat = hit_r ? R_IDLE : R_STAT1;
            R_STAT1: r_nstat = dev_rvalid ? R_IDLE : R_STAT1;
            default: r_nstat = R_IDLE;
        endcase
    end

    // TODO: 生成DCache读状态机的输出信号
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            cpu_ren     <= 4'h0;
            cpu_raddr   <= 32'h0;
            ren_r       <= 4'h0;
            read_addr_r <= 32'h0;
        end else begin
            case (r_state)
                R_IDLE: begin
                    if (|data_ren) begin
                        cpu_raddr   <= data_addr;
                        read_addr_r <= data_addr;
                        ren_r       <= data_ren;
                    end
                    cpu_ren <= 4'h0;
                end
                R_STAT0: begin
                    if (!hit_r) begin
                        cpu_ren   <= uncached ? ren_r : 4'hF;
                        // uncached保持原地址，cached需对齐到16字节块
                        cpu_raddr <= uncached ? cpu_raddr : {cpu_raddr[31:4], 4'b0000};
                    end else begin
                        cpu_ren   <= 4'h0;
                    end
                end
                R_STAT1: begin
                    if (cpu_ren != 4'h0 && dev_rrdy) begin
                        cpu_ren <= 4'h0;
                    end
                end
                default: cpu_ren <= 4'h0;
            endcase
        end
    end

    ///////////////////////////////////////////////////////////

    // TODO: 编写DCache写状态机的现态更新逻辑
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) w_state <= W_IDLE;
        else         w_state <= w_nstat;
    end

    // TODO: 编写DCache写状态机的状态转移逻辑（注意处理uncached访问）
    always @(*) begin
        case (w_state)
            W_IDLE:  w_nstat = (|data_wen) ? (dev_wrdy ? W_STAT1 : W_STAT0) : W_IDLE;
            W_STAT0: w_nstat = dev_wrdy ? W_STAT1 : W_STAT0;
            W_STAT1: w_nstat = wr_resp ? W_IDLE : W_STAT1;
            default: w_nstat = W_IDLE;
        endcase
    end

    // TODO: 生成DCache写状态机的输出信号
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            data_wresp <= 1'b0;
            cpu_wen    <= 4'h0;
            cpu_waddr  <= 32'h0;
            cpu_wdata  <= 32'h0;
            wen_r      <= 4'h0;
        end else begin
            case (w_state)
                W_IDLE: begin
                    data_wresp <= 1'b0;
                    if (|data_wen) begin
                        if (dev_wrdy) cpu_wen <= data_wen;
                        else          wen_r   <= data_wen;
                        
                        cpu_waddr <= data_addr;
                        cpu_wdata <= data_wdata;
                        // 保存当前写掩码，供写命中修改Cache时使用
                        wen_r     <= data_wen; 
                    end else begin
                        cpu_wen <= 4'h0;
                    end
                end
                W_STAT0: begin
                    cpu_wen <= dev_wrdy ? wen_r : 4'h0;
                end
                W_STAT1: begin
                    cpu_wen    <= 4'h0;
                    data_wresp <= wr_resp ? 1'b1 : 1'b0;
                end
                default: begin
                    data_wresp <= 1'b0;
                    cpu_wen    <= 4'h0;
                end
            endcase
        end
    end

    // TODO: 写命中时，只需修改Cache行中的其中一个字（即根据地址偏移、写使能、写数据等等生成wr_cache_data信号）。请在此实现之。
    always @(*) begin
        wr_cache_data = cache_line_r[127:0];
        if (wen_r[0]) wr_cache_data[offset*32 + 0  +: 8] = cpu_wdata[7:0];
        if (wen_r[1]) wr_cache_data[offset*32 + 8  +: 8] = cpu_wdata[15:8];
        if (wen_r[2]) wr_cache_data[offset*32 + 16 +: 8] = cpu_wdata[23:16];
        if (wen_r[3]) wr_cache_data[offset*32 + 24 +: 8] = cpu_wdata[31:24];
    end


    /******** 不要修改以下代码 ********/
`else

    // 保持原有直通逻辑不变...
    localparam R_IDLE  = 2'b00;
    localparam R_STAT0 = 2'b01;
    localparam R_STAT1 = 2'b11;
    reg [1:0] r_state, r_nstat;
    reg [3:0] ren_r;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        r_state <= cpu_rst ? R_IDLE : r_nstat;
    end

    always @(*) begin
        case (r_state)
            R_IDLE:  r_nstat = (|data_ren) ? (dev_rrdy ? R_STAT1 : R_STAT0) : R_IDLE;
            R_STAT0: r_nstat = dev_rrdy ? R_STAT1 : R_STAT0;
            R_STAT1: r_nstat = dev_rvalid ? R_IDLE : R_STAT1;
            default: r_nstat = R_IDLE;
        endcase
    end

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            data_valid <= 1'b0;
            cpu_ren    <= 4'h0;
        end else begin
            case (r_state)
                R_IDLE: begin
                    data_valid <= 1'b0;

                    if (|data_ren) begin
                        if (dev_rrdy)
                            cpu_ren <= data_ren;
                        else
                            ren_r   <= data_ren;

                        cpu_raddr <= data_addr;
                    end else
                        cpu_ren   <= 4'h0;
                end
                R_STAT0: begin
                    cpu_ren    <= dev_rrdy ? ren_r : 4'h0;
                end   
                R_STAT1: begin
                    cpu_ren    <= 4'h0;
                    data_valid <= dev_rvalid ? 1'b1 : 1'b0;
                    data_rdata <= dev_rvalid ? dev_rdata : 32'h0;
                end
                default: begin
                    data_valid <= 1'b0;
                    cpu_ren    <= 4'h0;
                end 
            endcase
        end
    end

    localparam W_IDLE  = 2'b00;
    localparam W_STAT0 = 2'b01;
    localparam W_STAT1 = 2'b11;
    reg  [1:0] w_state, w_nstat;
    reg  [3:0] wen_r;
    wire       wr_resp = dev_wrdy & (cpu_wen == 4'h0) ? 1'b1 : 1'b0;

    always @(posedge cpu_clk or posedge cpu_rst) begin
        w_state <= cpu_rst ? W_IDLE : w_nstat;
    end

    always @(*) begin
        case (w_state)
            W_IDLE:  w_nstat = (|data_wen) ? (dev_wrdy ? W_STAT1 : W_STAT0) : W_IDLE;
            W_STAT0: w_nstat = dev_wrdy ? W_STAT1 : W_STAT0;
            W_STAT1: w_nstat = wr_resp ? W_IDLE : W_STAT1;
            default: w_nstat = W_IDLE;
        endcase
    end

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            data_wresp <= 1'b0;
            cpu_wen    <= 4'h0;
        end else begin
            case (w_state)
                W_IDLE: begin
                    data_wresp <= 1'b0;

                    if (|data_wen) begin
                        if (dev_wrdy)
                            cpu_wen <= data_wen;
                        else
                            wen_r   <= data_wen;

                        cpu_waddr  <= data_addr;
                        cpu_wdata  <= data_wdata;
                    end else
                        cpu_wen    <= 4'h0;
                end
                W_STAT0: begin
                    cpu_wen    <= dev_wrdy ? wen_r : 4'h0;
                end
                W_STAT1: begin
                    cpu_wen    <= 4'h0;
                    data_wresp <= wr_resp ? 1'b1 : 1'b0;
                end
                default: begin
                    data_wresp <= 1'b0;
                    cpu_wen    <= 4'h0;
                end
            endcase
        end
    end

`endif

endmodule
