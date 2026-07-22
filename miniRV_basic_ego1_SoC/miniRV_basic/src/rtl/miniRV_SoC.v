`timescale 1ns / 1ps

`include "defines.vh"

module miniRV_SoC(
    input  wire         fpga_clk,
    input  wire         fpga_rst,   // Low Active
    input  wire [15:0]  sw,
    output wire [15:0]  led,
    output wire [ 7:0]  dig_en,
    output wire [ 7:0]  dig_seg,    // {CA, CB, ..., CG, DP}
    output wire [ 7:0]  dig_seg1,
    input  wire         rx,
    output wire         tx
);



`ifdef RUN_TRACE
    wire sys_clk = fpga_clk;
    wire sys_rst = fpga_rst;
`else
    wire pll_clk1;
    wire pll_lock;
    wire sys_clk = pll_lock & pll_clk1;
    reg  sys_rst;
    always @(posedge fpga_clk) sys_rst <= !fpga_rst | !pll_lock;

    clk_wiz_0 U_clkgen (
        .clk_in1    (fpga_clk),
        .locked     (pll_lock),
        .clk_out1   (pll_clk1)
    );
`endif

    

    wire [31:0] cpu_awaddr ;
    wire [ 7:0] cpu_awlen  ;
    wire [ 2:0] cpu_awsize ;
    wire [ 1:0] cpu_awburst;
    wire        cpu_awvalid;
    wire        cpu_awready;
    wire [31:0] cpu_wdata  ;
    wire [ 3:0] cpu_wstrb  ;
    wire        cpu_wlast  ;
    wire        cpu_wvalid ;
    wire        cpu_wready ;
    wire        cpu_bready ;
    wire [ 1:0] cpu_bresp  ;
    wire        cpu_bvalid ;
    wire [31:0] cpu_araddr ;
    wire [ 7:0] cpu_arlen  ;
    wire [ 2:0] cpu_arsize ;
    wire [ 1:0] cpu_arburst;
    wire        cpu_arvalid;
    wire        cpu_arready;
    wire        cpu_rready ;
    wire [31:0] cpu_rdata  ;
    wire [ 1:0] cpu_rresp  ;
    wire        cpu_rlast  ;
    wire        cpu_rvalid ;

    cpu_top U_cpu (
        .cpu_clk        (sys_clk),
        .cpu_rst        (sys_rst),

        // AXI4 Master Interface
        // write address channel
        .m_axi_awaddr   (cpu_awaddr),
        .m_axi_awlen    (cpu_awlen),
        .m_axi_awsize   (cpu_awsize),
        .m_axi_awburst  (cpu_awburst),
        .m_axi_awvalid  (cpu_awvalid),
        .m_axi_awready  (cpu_awready),
        // write data channel
        .m_axi_wdata    (cpu_wdata),
        .m_axi_wstrb    (cpu_wstrb),
        .m_axi_wlast    (cpu_wlast),
        .m_axi_wvalid   (cpu_wvalid),
        .m_axi_wready   (cpu_wready),
        // write response channel
        .m_axi_bready   (cpu_bready),
        .m_axi_bresp    (cpu_bresp),
        .m_axi_bvalid   (cpu_bvalid),
        // read address channel
        .m_axi_araddr   (cpu_araddr),
        .m_axi_arlen    (cpu_arlen),
        .m_axi_arsize   (cpu_arsize),
        .m_axi_arburst  (cpu_arburst),
        .m_axi_arvalid  (cpu_arvalid),
        .m_axi_arready  (cpu_arready),
        // read data channel
        .m_axi_rready   (cpu_rready),
        .m_axi_rdata    (cpu_rdata),
        .m_axi_rresp    (cpu_rresp),
        .m_axi_rlast    (cpu_rlast),
        .m_axi_rvalid   (cpu_rvalid)
    );

    wire [31:0] bram_awaddr ;
    wire [ 7:0] bram_awlen  ;
    wire [ 2:0] bram_awsize ;
    wire [ 1:0] bram_awburst;
    wire        bram_awvalid;
    wire        bram_awready;
    wire [31:0] bram_wdata  ;
    wire [ 3:0] bram_wstrb  ;
    wire        bram_wlast  ;
    wire        bram_wvalid ;
    wire        bram_wready ;
    wire        bram_bready ;
    wire [ 1:0] bram_bresp  ;
    wire        bram_bvalid ;
    wire [31:0] bram_araddr ;
    wire [ 7:0] bram_arlen  ;
    wire [ 2:0] bram_arsize ;
    wire [ 1:0] bram_arburst;
    wire        bram_arvalid;
    wire        bram_arready;
    wire        bram_rready ;
    wire [31:0] bram_rdata  ;
    wire [ 1:0] bram_rresp  ;
    wire        bram_rlast  ;
    wire        bram_rvalid ;

    assign bram_awaddr  = cpu_awaddr ;
    assign bram_awlen   = cpu_awlen  ;
    assign bram_awsize  = cpu_awsize ;
    assign bram_awburst = cpu_awburst;
    assign cpu_awready  = bram_awready;
    assign bram_awvalid = cpu_awvalid;
    assign bram_wdata   = cpu_wdata  ;
    assign bram_wstrb   = cpu_wstrb  ;
    assign bram_wlast   = cpu_wlast  ;
    assign bram_wvalid  = cpu_wvalid ;
    assign cpu_wready   = bram_wready;
    assign cpu_bresp    = bram_bresp ;
    assign cpu_bvalid   = bram_bvalid;
    assign bram_bready  = cpu_bready ;
    assign bram_araddr  = cpu_araddr ;
    assign bram_arlen   = cpu_arlen  ;
    assign bram_arsize  = cpu_arsize ;
    assign bram_arburst = cpu_arburst;
    assign bram_arvalid = cpu_arvalid;
    assign cpu_arready  = bram_arready;
    assign bram_rready  = cpu_rready ;
    assign cpu_rdata    = bram_rdata ;
    assign cpu_rresp    = bram_rresp ;
    assign cpu_rlast    = bram_rlast ;
    assign cpu_rvalid   = bram_rvalid;

    bram_axi U_bram (
        .s_aclk         (sys_clk),
        .s_aresetn      (!sys_rst),
        .s_axi_awid     (4'h6),
        .s_axi_awaddr   (bram_awaddr ),
        .s_axi_awlen    (bram_awlen  ),
        .s_axi_awsize   (bram_awsize ),
        .s_axi_awburst  (bram_awburst),
        .s_axi_awready  (bram_awready),
        .s_axi_awvalid  (bram_awvalid),
        .s_axi_wdata    (bram_wdata  ),
        .s_axi_wstrb    (bram_wstrb  ),
        .s_axi_wvalid   (bram_wvalid ),
        .s_axi_wlast    (bram_wlast  ),
        .s_axi_wready   (bram_wready ),
        .s_axi_bready   (bram_bready ),
        .s_axi_bresp    (bram_bresp  ),
        .s_axi_bvalid   (bram_bvalid ),
        .s_axi_arid     (4'h6),
        .s_axi_araddr   (bram_araddr ),
        .s_axi_arlen    (bram_arlen  ),
        .s_axi_arsize   (bram_arsize ),
        .s_axi_arburst  (bram_arburst),
        .s_axi_arready  (bram_arready),
        .s_axi_arvalid  (bram_arvalid),
        .s_axi_rdata    (bram_rdata  ),
        .s_axi_rvalid   (bram_rvalid ),
        .s_axi_rlast    (bram_rlast  ),
        .s_axi_rready   (bram_rready ),
        .s_axi_rresp    (bram_rresp  )
    );

endmodule
