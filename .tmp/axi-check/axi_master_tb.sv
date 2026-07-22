`timescale 1ns/1ps
`include "defines.vh"

module axi_master_tb;
    reg clk = 0;
    reg rst = 1;
    always #5 clk = ~clk;

    wire ic_rrdy;
    reg [3:0] ic_ren = 0;
    reg [31:0] ic_raddr = 0;
    wire ic_rvalid;
    wire [`IC_BLK_SIZE-1:0] ic_rdata;
    wire dc_wrdy;
    reg [3:0] dc_wen = 0;
    reg [31:0] dc_waddr = 0;
    reg [31:0] dc_wdata = 0;
    wire dc_rrdy;
    reg [3:0] dc_ren = 0;
    reg [31:0] dc_raddr = 0;
    wire dc_rvalid;
    wire [`DC_BLK_SIZE-1:0] dc_rdata;

    wire [31:0] awaddr;
    wire [7:0] awlen;
    wire [2:0] awsize;
    wire [1:0] awburst;
    wire awvalid;
    reg awready = 0;
    wire [31:0] wdata;
    wire [3:0] wstrb;
    wire wlast;
    wire wvalid;
    reg wready = 0;
    wire bready;
    reg [1:0] bresp = 0;
    reg bvalid = 0;
    wire [31:0] araddr;
    wire [7:0] arlen;
    wire [2:0] arsize;
    wire [1:0] arburst;
    wire arvalid;
    reg arready = 0;
    wire rready;
    reg [31:0] rdata = 0;
    reg [1:0] rresp = 0;
    reg rlast = 0;
    reg rvalid = 0;

    axi_master dut (
        .aclk(clk), .areset(rst),
        .ic_dev_rrdy(ic_rrdy), .ic_cpu_ren(ic_ren),
        .ic_cpu_raddr(ic_raddr), .ic_dev_rvalid(ic_rvalid),
        .ic_dev_rdata(ic_rdata),
        .dc_dev_wrdy(dc_wrdy), .dc_cpu_wen(dc_wen),
        .dc_cpu_waddr(dc_waddr), .dc_cpu_wdata(dc_wdata),
        .dc_dev_rrdy(dc_rrdy), .dc_cpu_ren(dc_ren),
        .dc_cpu_raddr(dc_raddr), .dc_dev_rvalid(dc_rvalid),
        .dc_dev_rdata(dc_rdata),
        .m_axi_awaddr(awaddr), .m_axi_awlen(awlen),
        .m_axi_awsize(awsize), .m_axi_awburst(awburst),
        .m_axi_awvalid(awvalid), .m_axi_awready(awready),
        .m_axi_wdata(wdata), .m_axi_wstrb(wstrb),
        .m_axi_wlast(wlast), .m_axi_wvalid(wvalid),
        .m_axi_wready(wready), .m_axi_bready(bready),
        .m_axi_bresp(bresp), .m_axi_bvalid(bvalid),
        .m_axi_araddr(araddr), .m_axi_arlen(arlen),
        .m_axi_arsize(arsize), .m_axi_arburst(arburst),
        .m_axi_arvalid(arvalid), .m_axi_arready(arready),
        .m_axi_rready(rready), .m_axi_rdata(rdata),
        .m_axi_rresp(rresp), .m_axi_rlast(rlast),
        .m_axi_rvalid(rvalid)
    );

    task automatic send_read_data(input [31:0] base);
        integer beat;
        begin
            wait (rready);
            for (beat = 0; beat < `DC_BLK_LEN; beat = beat + 1) begin
                @(negedge clk);
                rdata  = base + beat;
                rlast  = (beat == (`DC_BLK_LEN - 1));
                rvalid = 1;
                @(posedge clk);
            end
            @(negedge clk);
            rvalid = 0;
            rlast  = 0;
        end
    endtask

    initial begin
        repeat (3) @(posedge clk);
        @(negedge clk);
        rst = 0;

        // Hold both requests: DCache must win, ICache must remain pending.
        dc_raddr = 32'h0000_020c;
        ic_raddr = 32'h0000_0100;
        dc_ren = 4'hf;
        ic_ren = 4'hf;
        wait (dc_rrdy);
        @(negedge clk);
        dc_ren = 0;

        wait (arvalid);
`ifdef ENABLE_DCACHE
        if (araddr !== 32'h0000_0200 || arlen !== (`DC_BLK_LEN - 1) || arsize !== 3'd2 || arburst !== 2'b01)
`else
        if (araddr !== 32'h0000_020c || arlen !== (`DC_BLK_LEN - 1) || arsize !== 3'd2 || arburst !== 2'b01)
`endif
            $fatal(1, "bad DCache AR request");
        repeat (2) @(posedge clk);
        if (!arvalid) $fatal(1, "ARVALID did not wait for ARREADY");
        @(negedge clk);
        arready = 1;
        @(negedge clk);
        arready = 0;
        send_read_data(32'hd000_0000);
        wait (dc_rvalid);
`ifdef ENABLE_DCACHE
        if (dc_rdata !== 128'hd0000003_d0000002_d0000001_d0000000)
`else
        if (dc_rdata !== 32'hd0000000)
`endif
            $fatal(1, "DCache burst assembly failed");

        wait (ic_rrdy);
        @(negedge clk);
        ic_ren = 0;
        wait (arvalid);
        if (araddr !== 32'h0000_0100 || arlen !== (`IC_BLK_LEN - 1))
            $fatal(1, "bad ICache AR request");
        @(negedge clk);
        arready = 1;
        @(negedge clk);
        arready = 0;
        send_read_data(32'h1000_0000);
        wait (ic_rvalid);
`ifdef ENABLE_ICACHE
        if (ic_rdata !== 128'h10000003_10000002_10000001_10000000)
`else
        if (ic_rdata !== 32'h10000000)
`endif
            $fatal(1, "ICache burst assembly failed");

        // Accept W before AW and verify that each VALID is independent.
        wait (dc_wrdy);
        @(negedge clk);
        dc_waddr = 32'h0000_0303;
        dc_wdata = 32'ha5a5_5a5a;
        dc_wen = 4'b1000;
        @(negedge clk);
        dc_wen = 0;
        wait (awvalid && wvalid);
        if (awaddr !== 32'h0000_0300 || awlen !== 0 || !wlast || wstrb !== 4'b1000)
            $fatal(1, "bad write request");
        @(negedge clk);
        wready = 1;
        @(negedge clk);
        wready = 0;
        if (!awvalid || wvalid) $fatal(1, "AW/W handshakes are not independent");
        repeat (2) @(posedge clk);
        if (!awvalid) $fatal(1, "AWVALID did not wait for AWREADY");
        @(negedge clk);
        awready = 1;
        @(negedge clk);
        awready = 0;
        wait (bready);
        @(negedge clk);
        bvalid = 1;
        @(negedge clk);
        bvalid = 0;
        wait (dc_wrdy);

        $display("AXI_MASTER_TB_PASS");
        $finish;
    end

    initial begin
        #5000;
        $fatal(1, "timeout");
    end
endmodule
