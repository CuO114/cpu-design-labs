`timescale 1ns / 1ps

`include "defines.vh"

module axi_master(
    input  wire         aclk,
    input  wire         areset,     // high active

    // ICache Interface
    output reg          ic_dev_rrdy,
    input  wire [ 3:0]  ic_cpu_ren,
    input  wire [31:0]  ic_cpu_raddr,
    output reg          ic_dev_rvalid,
    output reg  [`IC_BLK_SIZE-1:0]  ic_dev_rdata,
    // DCache Interface
    output reg          dc_dev_wrdy,
    input  wire [ 3:0]  dc_cpu_wen,
    input  wire [31:0]  dc_cpu_waddr,
    input  wire [31:0]  dc_cpu_wdata,
    output reg          dc_dev_rrdy,
    input  wire [ 3:0]  dc_cpu_ren,
    input  wire [31:0]  dc_cpu_raddr,
    output reg          dc_dev_rvalid,
    output reg  [`DC_BLK_SIZE-1:0]  dc_dev_rdata,

    // AXI4 Master Interface
    // write address channel
    output reg  [31:0]  m_axi_awaddr,
    output reg  [ 7:0]  m_axi_awlen,
    output reg  [ 2:0]  m_axi_awsize,
    output reg  [ 1:0]  m_axi_awburst,
    output reg          m_axi_awvalid,
    input  wire         m_axi_awready,
    // write data channel
    output reg  [31:0]  m_axi_wdata,
    output reg  [ 3:0]  m_axi_wstrb,
    output wire         m_axi_wlast,
    output reg          m_axi_wvalid,
    input  wire         m_axi_wready,
    // write response channel
    output reg          m_axi_bready,
    input  wire [ 1:0]  m_axi_bresp,
    input  wire         m_axi_bvalid,
    // read address channel
    output reg  [31:0]  m_axi_araddr,
    output reg  [ 7:0]  m_axi_arlen,
    output reg  [ 2:0]  m_axi_arsize,
    output reg  [ 1:0]  m_axi_arburst,
    output reg          m_axi_arvalid,
    input  wire         m_axi_arready,
    // read data channel
    output reg          m_axi_rready,
    input  wire [31:0]  m_axi_rdata,
    input  wire [ 1:0]  m_axi_rresp,
    input  wire         m_axi_rlast,
    input  wire         m_axi_rvalid
);

    localparam [1:0] R_IDLE = 2'd0;
    localparam [1:0] R_ADDR = 2'd1;
    localparam [1:0] R_DATA = 2'd2;

    localparam [1:0] W_IDLE = 2'd0;
    localparam [1:0] W_SEND = 2'd1;
    localparam [1:0] W_RESP = 2'd2;

    reg [1:0] r_state, r_next;
    reg [1:0] w_state, w_next;
    reg       read_from_dc;
    reg       read_turn_dc;
    reg [7:0] read_beat;
    reg       aw_done;
    reg       w_done;

    wire ic_read_req = |ic_cpu_ren;
    wire dc_read_req = |dc_cpu_ren;
    wire read_last   = m_axi_rlast || (read_beat == m_axi_arlen);
    wire aw_fire     = m_axi_awvalid && m_axi_awready;
    wire w_fire      = m_axi_wvalid && m_axi_wready;

    assign m_axi_wlast = 1'b1;

    // Only one idle client is offered proactively. Once a request appears,
    // READY follows that request so the cache can observe its acceptance.
    always @(*) begin
        ic_dev_rrdy = 1'b0;
        dc_dev_rrdy = 1'b0;

        if (r_state == R_IDLE) begin
            if (dc_read_req)
                dc_dev_rrdy = 1'b1;
            else if (ic_read_req)
                ic_dev_rrdy = 1'b1;
            else if (read_turn_dc)
                dc_dev_rrdy = 1'b1;
            else
                ic_dev_rrdy = 1'b1;
        end
    end

    always @(*) begin
        case (r_state)
            R_IDLE:  r_next = (dc_read_req || ic_read_req) ? R_ADDR : R_IDLE;
            R_ADDR:  r_next = m_axi_arready ? R_DATA : R_ADDR;
            R_DATA:  r_next = (m_axi_rvalid && m_axi_rready && read_last) ? R_IDLE : R_DATA;
            default: r_next = R_IDLE;
        endcase
    end

    always @(*) begin
        case (w_state)
            W_IDLE:  w_next = (|dc_cpu_wen) ? W_SEND : W_IDLE;
            W_SEND:  w_next = ((aw_done || aw_fire) && (w_done || w_fire)) ? W_RESP : W_SEND;
            W_RESP:  w_next = (m_axi_bvalid && m_axi_bready) ? W_IDLE : W_RESP;
            default: w_next = W_IDLE;
        endcase
    end

    always @(posedge aclk or posedge areset) begin
        if (areset) begin
            r_state       <= R_IDLE;
            read_from_dc  <= 1'b0;
            read_turn_dc  <= 1'b0;
            read_beat     <= 8'h0;
            ic_dev_rvalid <= 1'b0;
            ic_dev_rdata  <= {`IC_BLK_SIZE{1'b0}};
            dc_dev_rvalid <= 1'b0;
            dc_dev_rdata  <= {`DC_BLK_SIZE{1'b0}};
            m_axi_araddr  <= 32'h0;
            m_axi_arlen   <= 8'h0;
            m_axi_arsize  <= 3'b010;
            m_axi_arburst <= 2'b01;
            m_axi_arvalid <= 1'b0;
            m_axi_rready  <= 1'b0;
        end else begin
            r_state       <= r_next;
            ic_dev_rvalid <= 1'b0;
            dc_dev_rvalid <= 1'b0;

            case (r_state)
                R_IDLE: begin
                    m_axi_arvalid <= 1'b0;
                    m_axi_rready  <= 1'b0;
                    read_beat     <= 8'h0;

                    if (dc_read_req) begin
                        read_from_dc  <= 1'b1;
                        read_turn_dc  <= 1'b0;
                        if ((`DC_BLK_LEN > 1) && (dc_cpu_raddr[31:16] != 16'hFFFF)) begin
                            m_axi_araddr <= {dc_cpu_raddr[31:4], 4'b0000};
                            m_axi_arlen  <= `DC_BLK_LEN - 1;
                        end else begin
                            m_axi_araddr <= {dc_cpu_raddr[31:2], 2'b00};
                            m_axi_arlen  <= 8'h0;
                        end
                        m_axi_arsize  <= 3'b010;
                        m_axi_arburst <= 2'b01;
                        m_axi_arvalid <= 1'b1;
                        dc_dev_rdata  <= {`DC_BLK_SIZE{1'b0}};
                    end else if (ic_read_req) begin
                        read_from_dc  <= 1'b0;
                        read_turn_dc  <= 1'b1;
                        if (`IC_BLK_LEN > 1)
                            m_axi_araddr <= {ic_cpu_raddr[31:4], 4'b0000};
                        else
                            m_axi_araddr <= {ic_cpu_raddr[31:2], 2'b00};
                        m_axi_arlen   <= `IC_BLK_LEN - 1;
                        m_axi_arsize  <= 3'b010;
                        m_axi_arburst <= 2'b01;
                        m_axi_arvalid <= 1'b1;
                        ic_dev_rdata  <= {`IC_BLK_SIZE{1'b0}};
                    end else begin
                        read_turn_dc <= ~read_turn_dc;
                    end
                end

                R_ADDR: begin
                    if (m_axi_arready) begin
                        m_axi_arvalid <= 1'b0;
                        m_axi_rready  <= 1'b1;
                    end
                end

                R_DATA: begin
                    if (m_axi_rvalid && m_axi_rready) begin
                        if (read_from_dc)
                            dc_dev_rdata[read_beat*32 +: 32] <= m_axi_rdata;
                        else
                            ic_dev_rdata[read_beat*32 +: 32] <= m_axi_rdata;

                        if (read_last) begin
                            m_axi_rready <= 1'b0;
                            if (read_from_dc)
                                dc_dev_rvalid <= 1'b1;
                            else
                                ic_dev_rvalid <= 1'b1;
                        end else begin
                            read_beat <= read_beat + 1'b1;
                        end
                    end
                end

                default: begin
                    m_axi_arvalid <= 1'b0;
                    m_axi_rready  <= 1'b0;
                end
            endcase
        end
    end

    always @(*) begin
        dc_dev_wrdy = (w_state == W_IDLE);
    end

    always @(posedge aclk or posedge areset) begin
        if (areset) begin
            w_state       <= W_IDLE;
            aw_done       <= 1'b0;
            w_done        <= 1'b0;
            m_axi_awaddr  <= 32'h0;
            m_axi_awlen   <= 8'h0;
            m_axi_awsize  <= 3'b010;
            m_axi_awburst <= 2'b01;
            m_axi_awvalid <= 1'b0;
            m_axi_wdata   <= 32'h0;
            m_axi_wstrb   <= 4'h0;
            m_axi_wvalid  <= 1'b0;
            m_axi_bready  <= 1'b0;
        end else begin
            w_state <= w_next;

            case (w_state)
                W_IDLE: begin
                    aw_done       <= 1'b0;
                    w_done        <= 1'b0;
                    m_axi_awvalid <= 1'b0;
                    m_axi_wvalid  <= 1'b0;
                    m_axi_bready  <= 1'b0;

                    if (|dc_cpu_wen) begin
                        m_axi_awaddr  <= {dc_cpu_waddr[31:2], 2'b00};
                        m_axi_awlen   <= 8'h0;
                        m_axi_awsize  <= 3'b010;
                        m_axi_awburst <= 2'b01;
                        m_axi_awvalid <= 1'b1;
                        m_axi_wdata   <= dc_cpu_wdata;
                        m_axi_wstrb   <= dc_cpu_wen;
                        m_axi_wvalid  <= 1'b1;
                    end
                end

                W_SEND: begin
                    if (aw_fire) begin
                        m_axi_awvalid <= 1'b0;
                        aw_done       <= 1'b1;
                    end
                    if (w_fire) begin
                        m_axi_wvalid <= 1'b0;
                        w_done       <= 1'b1;
                    end
                    if ((aw_done || aw_fire) && (w_done || w_fire))
                        m_axi_bready <= 1'b1;
                end

                W_RESP: begin
                    if (m_axi_bvalid && m_axi_bready)
                        m_axi_bready <= 1'b0;
                end

                default: begin
                    m_axi_awvalid <= 1'b0;
                    m_axi_wvalid  <= 1'b0;
                    m_axi_bready  <= 1'b0;
                end
            endcase
        end
    end


endmodule
