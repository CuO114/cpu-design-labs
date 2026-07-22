`timescale 1ns / 1ps
`include "defines.vh"

// 主存地址位宽：32bit
// Cache容量：1KB
// Cache块大小：128bit / 4 * 32bit
// Cache块个数：64

module ICache(
    input  wire         cpu_clk,
    input  wire         cpu_rst,        // high active
    // Interface to CPU
    input  wire         inst_rreq,      // 来自CPU的取指请求
    input  wire [31:0]  inst_addr,      // 来自CPU的取指地址
    output reg          inst_valid,     // 输出给CPU的指令有效信号（读指令命中）
    output reg  [31:0]  inst_out,       // 输出给CPU的指令
    // Interface to Read Bus
    input  wire         dev_rrdy,       // 主存就绪信号（高电平表示主存可接收ICache的读请求）
    output reg  [ 3:0]  cpu_ren,        // 输出给主存的读使能信号
    output reg  [31:0]  cpu_raddr,      // 输出给主存的读地址
    input  wire         dev_rvalid,     // 来自主存的数据有效信号
    input  wire [`IC_BLK_SIZE-1:0] dev_rdata // 来自主存的读数据
);
`ifdef ENABLE_ICACHE /******** 不要修改此行代码 ********/

    wire [133:0] cache_line_r;
    wire [ 4:0]  tag_from_cpu   = inst_addr[14:10]; // 32KB主存地址的TAG字段
    wire [ 1:0]  offset         = inst_addr[3:2];   // 32位字偏移量

    wire         valid_bit      = (cache_line_r[133] === 1'b1) ? 1'b1 : 1'b0; // Cache块的有效位
    wire [ 4:0]  tag_from_cache = cache_line_r[132:128]; // Cache块的TAG字段

    // TODO: 定义ICache状态机的状态及状态变量

    wire         hit            = (tag_from_cache == tag_from_cpu) && valid_bit;

    localparam IDLE  = 2'b00;
    localparam STAT0 = 2'b01; 
    localparam STAT1 = 2'b11; 
    reg [1:0] state, nstat;

    always @(*) begin
        if (state == STAT0 && hit) begin
            inst_valid = 1'b1;
            inst_out   = cache_line_r[offset * 32 +: 32];
        end else if (state == STAT1 && dev_rvalid && (cpu_raddr[31:4] == inst_addr[31:4])) begin
            inst_valid = 1'b1;
            inst_out   = dev_rdata[offset * 32 +: 32]; 
        end else begin
            inst_valid = 1'b0;
            inst_out   = 32'h00000000;
        end
    end

    wire         cache_we     = (state == STAT1) && dev_rvalid; // ICache存储体的写使能信号
    wire [ 5:0]  cache_index  = (state == STAT1) ? cpu_raddr[9:4] : inst_addr[9:4]; // 主存地址的Cache索引 / ICache存储体的地址
    wire [133:0] cache_line_w = {1'b1, cpu_raddr[14:10], dev_rdata}; // 待写入ICache的新Cache块

    // ICache存储体：Block MEM IP核
    blk_mem_gen_1 U_isram (
        .clka   (cpu_clk),
        .wea    (cache_we),
        .addra  (cache_index),
        .dina   (cache_line_w),
        .douta  (cache_line_r)
    );

    // 现态
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) state <= IDLE;
        else         state <= nstat;
    end

    // 状态转移
    always @(*) begin
        case (state)
            IDLE:    nstat = inst_rreq ? STAT0 : IDLE;
            STAT0:   nstat = hit ? IDLE : STAT1;
            STAT1:   nstat = dev_rvalid ? IDLE : STAT1;
            default: nstat = IDLE;
        endcase
    end

    // 输出信号
    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            cpu_ren   <= 4'h0;
            cpu_raddr <= 32'h0;
        end else begin
            case (state)
                IDLE: begin
                    cpu_ren <= 4'h0;
                end
                STAT0: begin
                    if (!hit) begin
                        cpu_ren   <= 4'hF; 
                        cpu_raddr <= {inst_addr[31:4], 4'b0000};
                    end else begin
                        cpu_ren   <= 4'h0;
                    end
                end
                STAT1: begin
                    if (cpu_ren != 4'h0 && dev_rrdy) begin
                        cpu_ren <= 4'h0;
                    end
                end
                default: cpu_ren <= 4'h0;
            endcase
        end
    end

    /******** 不要修改以下代码 ********/
`else

    localparam IDLE  = 2'b00;
    localparam STAT0 = 2'b01;
    localparam STAT1 = 2'b11;
    reg [1:0] state, nstat;
    always @(posedge cpu_clk or posedge cpu_rst) state <= cpu_rst ? IDLE : nstat;

    always @(*) begin
        case (state)
            IDLE:    nstat = inst_rreq ? (dev_rrdy ? STAT1 : STAT0) : IDLE;
            STAT0:   nstat = dev_rrdy ? STAT1 : STAT0;
            STAT1:   nstat = dev_rvalid ? IDLE : STAT1;
            default: nstat = IDLE;
        endcase
    end

    always @(posedge cpu_clk or posedge cpu_rst) begin
        if (cpu_rst) begin
            inst_valid <= 1'b0;
            cpu_ren    <= 4'h0;
        end else begin
            case (state)
                IDLE: begin
                    inst_valid <= 1'b0;
                    cpu_ren    <= (inst_rreq & dev_rrdy) ? 4'hF : 4'h0;
                    cpu_raddr  <= inst_rreq ? {inst_addr[31:2], 2'b00} : 32'h0;
                end
                STAT0: begin
                    cpu_ren    <= dev_rrdy ? 4'hF : 4'h0;
                end
                STAT1: begin
                    cpu_ren    <= 4'h0;
                    inst_valid <= dev_rvalid ? 1'b1 : 1'b0;
                    inst_out   <= dev_rvalid ? dev_rdata[31:0] : 32'h0;
                end
                default: begin
                    inst_valid <= 1'b0;
                    cpu_ren    <= 4'h0;
                end
            endcase
        end
    end

`endif
endmodule
