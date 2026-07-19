<style>
    pre {
        overflow-y: auto;
        max-height: 350px;
    }
</style>

&emsp;&emsp;AXI总线是常用的嵌入式总线协议。Vivado的IP核库提供了许多AXI接口的IP核，使用这些IP核可以很方便地实现外设的I/O接口电路。

## 1. 创建AXI协议转换器

&emsp;&emsp;本课程实现的外设对数据传输带宽无特别要求。Vivado为这类数据带宽不敏感的低速外设提供了支持数据读写功能的AXI GPIO IP核。我们将使用此IP核实现数码管、LED、拨码开关和计时器的I/O接口电路。

&emsp;&emsp;AXI GPIO IP核采用AXI4-Lite总线接口。AXI4-Lite是AXI4的精简版，信号更少、时序更简洁，但不支持猝发传输功能。

&emsp;&emsp;我们实现的总线控制器`axi_master`支持完整的AXI4总线协议。为了实现CPU通过AXI4接口访问AXI4-Lite接口的外设，我们需要使用Vivado提供的AXI协议转换器来将AXI4总线接口转换成AXI4-Lite的总线接口。

&emsp;&emsp;在SoC工程中，点击界面左侧的`IP Catalog`，搜索“`protocol`”。找到`AXI Protocol Converter`后双击打开IP核配置窗口。保持默认设置，直接点击OK按钮即可，如图6-1所示。

<center><img src = "../assets/6-1.png" width = 100%></center>
<center>图6-1 创建AXI Protocol Converter IP核</center>

&emsp;&emsp;下面以计时器和UART为例子，介绍外设I/O接口电路的设计方法。请同学们参照示例自行完成其余外设的I/O接口电路设计。



## 2. 计时器的I/O接口实现

&emsp;&emsp;在SoC工程的 `src` / `rtl` 目录，创建`timer_wrap.v`文件，并将其添加到SoC工程，如图6-2所示。

<center><img src = "../assets/6-2.png" width = 100%></center>
<center>图6-2 添加计时器I/O接口模块的源文件</center>

&emsp;&emsp;计时器不需要接收来自开发板上的开关输入，也不需要输出信号来驱动LED、数码管等等，因此`timer_wrap.v`只需要一组AXI Slave接口，如下列代码所示。

```verilog title="timer_wrap.v"
module timer_wrap(
    input  wire         aclk,
    input  wire         aresetn,
    input  wire [31:0]  s_axi_awaddr,
    input  wire [ 7:0]  s_axi_awlen,
    input  wire [ 2:0]  s_axi_awsize,
    input  wire [ 1:0]  s_axi_awburst,
    input  wire [ 0:0]  s_axi_awlock,
    input  wire [ 3:0]  s_axi_awcache,
    input  wire [ 2:0]  s_axi_awprot,
    input  wire [ 3:0]  s_axi_awregion,
    input  wire [ 3:0]  s_axi_awqos,
    input  wire         s_axi_awvalid,
    output wire         s_axi_awready,
    input  wire [31:0]  s_axi_wdata,
    input  wire [ 3:0]  s_axi_wstrb,
    input  wire         s_axi_wlast,
    input  wire         s_axi_wvalid,
    output wire         s_axi_wready,
    output wire [ 1:0]  s_axi_bresp,
    output wire         s_axi_bvalid,
    input  wire         s_axi_bready,
    input  wire [31:0]  s_axi_araddr,
    input  wire [ 7:0]  s_axi_arlen,
    input  wire [ 2:0]  s_axi_arsize,
    input  wire [ 1:0]  s_axi_arburst,
    input  wire [ 0:0]  s_axi_arlock,
    input  wire [ 3:0]  s_axi_arcache,
    input  wire [ 2:0]  s_axi_arprot,
    input  wire [ 3:0]  s_axi_arregion,
    input  wire [ 3:0]  s_axi_arqos,
    input  wire         s_axi_arvalid,
    output wire         s_axi_arready,
    output wire [31:0]  s_axi_rdata,
    output wire [ 1:0]  s_axi_rresp,
    output wire         s_axi_rlast,
    output wire         s_axi_rvalid,
    input  wire         s_axi_rready
);

    // TODO


endmodule
```

&emsp;&emsp;计时器的功能是给SoC提供硬件时间。在本课程中，我们使用一个64位的计数器来实现计时器，如下列代码所示。

```verilog title="timer_wrap.v"
    reg  [63:0] timer;
    always @(posedge aclk or negedge aresetn) begin
        timer <= !aresetn ? 64'h0 : timer + 64'h1;
    end
```

&emsp;&emsp;在本课程中，计时器的I/O接口电路只需要实现把计时器的值返回给CPU即可。

&emsp;&emsp;miniRV和miniLA都是32位的指令集架构，SoC的总线数据宽度也是32位。因此，CPU需要两次读操作才能获取计时器的值。

&emsp;&emsp;接下来，我们使用AXI GPIO IP核来获取计时器的值。

&emsp;&emsp;点击Vivado界面左侧的`IP Catalog`，搜索“`gpio`”。找到`AXI GPIO`后双击打开IP核配置窗口，按如图6-3所示进行配置。

<center><img src = "../assets/6-3.png" width = 100%></center>
<center>图6-3 添加AXI GPIO IP核</center>

&emsp;&emsp;如果GPIO需要输出功能，则勾选“All Outputs”。对计时器而言，选择“All Inputs”即可。

&emsp;&emsp;在`timer_wrap.v`中实例化AXI GPIO IP核，并把`timer`寄存器的值连接到IP核的输入端口，如下列代码所示。

```verilog title="timer_wrap.v"
    wire [31:0] timer_awaddr;
    wire        timer_awready;
    wire        timer_awvalid;
    wire [31:0] timer_wdata;
    wire        timer_wready;
    wire [ 3:0] timer_wstrb;
    wire        timer_wvalid;
    wire        timer_bready;
    wire [ 1:0] timer_bresp;
    wire        timer_bvalid;
    wire [31:0] timer_araddr;
    wire        timer_arready;
    wire        timer_arvalid;
    wire [31:0] timer_rdata;
    wire        timer_rready;
    wire [ 1:0] timer_rresp;
    wire        timer_rvalid;

    axi_gpio_0 U_timer (
        .s_axi_aclk         (aclk),
        .s_axi_aresetn      (aresetn),
        .s_axi_awaddr       (timer_awaddr),
        .s_axi_awready      (timer_awready),
        .s_axi_awvalid      (timer_awvalid),
        .s_axi_wdata        (timer_wdata),
        .s_axi_wready       (timer_wready),
        .s_axi_wstrb        (timer_wstrb),
        .s_axi_wvalid       (timer_wvalid),
        .s_axi_bready       (timer_bready),
        .s_axi_bresp        (timer_bresp),
        .s_axi_bvalid       (timer_bvalid),
        .s_axi_araddr       (timer_araddr),
        .s_axi_arready      (timer_arready),
        .s_axi_arvalid      (timer_arvalid),
        .s_axi_rdata        (timer_rdata),
        .s_axi_rready       (timer_rready),
        .s_axi_rresp        (timer_rresp),
        .s_axi_rvalid       (timer_rvalid),

        .gpio2_io_i         (timer[63:32]),
        .gpio_io_i          (timer[31:0])
    );
```

&emsp;&emsp;根据<a href="https://docs.amd.com/r/en-US/pg144-axi-gpio/Register-Space" target=_blank>AXI GPIO IP核的用户手册</a>，GPIO端口1的偏移地址是0x0000，GPIO端口2的偏移地址是0x0008，如表6-1所示。

<center>表6-1 AXI GPIO IP核的寄存器地址表</center>
<center><img src = "../assets/t6-1.png" width = 100%></center>

&emsp;&emsp;因此，CPU如果要读取`timer[31:0]`，就需要读取计时器外设的基地址 + 0x0000的偏移地址；同理，如果要读取`timer[63:32]`，就需要读取计时器外设的基地址 + 0x0008的偏移地址。

&emsp;&emsp;AXI GPIO IP核使得计时器的值能够通过AXI4 Lite协议来读取。在此基础上，把AXI协议转换器添加到计时器的I/O接口电路，就能实现CPU通过AXI4总线读取计时器。

&emsp;&emsp;在`timer_wrap.v`中实例化AXI Protocol Converter IP核，并将其与AXI GPIO IP核连接起来，如下列代码所示。

```verilog title="timer_wrap.v"
    axi_protocol_converter_0 U_timer_converter (
        .aclk               (aclk),
        .aresetn            (aresetn),
        .s_axi_awaddr       (s_axi_awaddr),
        .s_axi_awlen        (s_axi_awlen),
        .s_axi_awsize       (s_axi_awsize),
        .s_axi_awburst      (s_axi_awburst),
        .s_axi_awlock       (s_axi_awlock),
        .s_axi_awcache      (s_axi_awcache),
        .s_axi_awprot       (s_axi_awprot),
        .s_axi_awregion     (s_axi_awregion),
        .s_axi_awqos        (s_axi_awqos),
        .s_axi_awvalid      (s_axi_awvalid),
        .s_axi_awready      (s_axi_awready),
        .s_axi_wdata        (s_axi_wdata),
        .s_axi_wstrb        (s_axi_wstrb),
        .s_axi_wlast        (s_axi_wlast),
        .s_axi_wvalid       (s_axi_wvalid),
        .s_axi_wready       (s_axi_wready),
        .s_axi_bresp        (s_axi_bresp),
        .s_axi_bvalid       (s_axi_bvalid),
        .s_axi_bready       (s_axi_bready),
        .s_axi_araddr       (s_axi_araddr),
        .s_axi_arlen        (s_axi_arlen),
        .s_axi_arsize       (s_axi_arsize),
        .s_axi_arburst      (s_axi_arburst),
        .s_axi_arlock       (s_axi_arlock),
        .s_axi_arcache      (s_axi_arcache),
        .s_axi_arprot       (s_axi_arprot),
        .s_axi_arregion     (s_axi_arregion),
        .s_axi_arqos        (s_axi_arqos),
        .s_axi_arvalid      (s_axi_arvalid),
        .s_axi_arready      (s_axi_arready),
        .s_axi_rdata        (s_axi_rdata),
        .s_axi_rresp        (s_axi_rresp),
        .s_axi_rlast        (s_axi_rlast),
        .s_axi_rvalid       (s_axi_rvalid),
        .s_axi_rready       (s_axi_rready),
        .m_axi_awaddr       (timer_awaddr),
        .m_axi_awvalid      (timer_awvalid),
        .m_axi_awready      (timer_awready),
        .m_axi_wdata        (timer_wdata),
        .m_axi_wstrb        (timer_wstrb),
        .m_axi_wvalid       (timer_wvalid),
        .m_axi_wready       (timer_wready),
        .m_axi_bresp        (timer_bresp),
        .m_axi_bvalid       (timer_bvalid),
        .m_axi_bready       (timer_bready),
        .m_axi_araddr       (timer_araddr),
        .m_axi_arvalid      (timer_arvalid),
        .m_axi_arready      (timer_arready),
        .m_axi_rdata        (timer_rdata),
        .m_axi_rresp        (timer_rresp),
        .m_axi_rvalid       (timer_rvalid),
        .m_axi_rready       (timer_rready)
    );
```

&emsp;&emsp;最后，在`miniRV_SoC.v`或`miniLA_SoC.v`中添加`timer_wrap`模块的实例化代码。

```verilog title="miniRV_SoC.v 或 miniLA_SoC.v"
    wire [31:0] tim_awaddr ;
    wire [ 7:0] tim_awlen  ;
    wire [ 2:0] tim_awsize ;
    wire [ 1:0] tim_awburst;
    wire        tim_awvalid;
    wire        tim_awready;
    wire [31:0] tim_wdata  ;
    wire [ 3:0] tim_wstrb  ;
    wire        tim_wlast  ;
    wire        tim_wvalid ;
    wire        tim_wready ;
    wire        tim_bready ;
    wire [ 1:0] tim_bresp  ;
    wire        tim_bvalid ;
    wire [31:0] tim_araddr ;
    wire [ 7:0] tim_arlen  ;
    wire [ 2:0] tim_arsize ;
    wire [ 1:0] tim_arburst;
    wire        tim_arvalid;
    wire        tim_arready;
    wire        tim_rready ;
    wire [31:0] tim_rdata  ;
    wire [ 1:0] tim_rresp  ;
    wire        tim_rlast  ;
    wire        tim_rvalid ;

    timer_wrap U_timer (
        .aclk           (sys_clk),
        .aresetn        (!sys_rst),
        .s_axi_awaddr   (tim_awaddr ),
        .s_axi_awlen    (tim_awlen  ),
        .s_axi_awsize   (tim_awsize ),
        .s_axi_awburst  (tim_awburst),
        .s_axi_awvalid  (tim_awvalid),
        .s_axi_awready  (tim_awready),
        .s_axi_wdata    (tim_wdata  ),
        .s_axi_wstrb    (tim_wstrb  ),
        .s_axi_wlast    (tim_wlast  ),
        .s_axi_wvalid   (tim_wvalid ),
        .s_axi_wready   (tim_wready ),
        .s_axi_bresp    (tim_bresp  ),
        .s_axi_bvalid   (tim_bvalid ),
        .s_axi_bready   (tim_bready ),
        .s_axi_araddr   (tim_araddr ),
        .s_axi_arlen    (tim_arlen  ),
        .s_axi_arsize   (tim_arsize ),
        .s_axi_arburst  (tim_arburst),
        .s_axi_arvalid  (tim_arvalid),
        .s_axi_arready  (tim_arready),
        .s_axi_rdata    (tim_rdata  ),
        .s_axi_rresp    (tim_rresp  ),
        .s_axi_rlast    (tim_rlast  ),
        .s_axi_rvalid   (tim_rvalid ),
        .s_axi_rready   (tim_rready )
    );
```



## 3. UART的I/O接口实现

&emsp;&emsp;UART可以直接使用AXI Uartlite IP核来实现其I/O接口电路。

&emsp;&emsp;点击Vivado界面左侧的IP Catalog，搜索“`uart`”。找到AXI Uartlite后双击打开IP核配置窗口，按如图6-4所示进行配置。

<center><img src = "../assets/6-4.png" width = 100%></center>
<center>图6-4 创建AXI Uartlite IP核</center>

&emsp;&emsp;其中，波特率设置为115200，而 **频率则需要与CPU时钟频率一致**（模板工程默认为50MHz）。^^若后续通过优化提高了CPU主频，必须相应地修改AXI Uartlite IP核的输入时钟频率^^，否则串口将不能正常工作。

&emsp;&emsp;创建`uart_wrap.v`，添加AXI Uartlite IP核与AXI Protocol Converter IP核的实例化代码，然后把`tx`、`rx`信号添加到模块接口信号列表即可，其他与计时器相同，此处不再赘述。



## 4. 创建总线桥模块

&emsp;&emsp;到目前为止，SoC工程存在1个AXI总线的主设备（即CPU），以及6个从设备（主存和5个外设）。为了使得主设备能够同时连接多个从设备，我们需要在SoC工程中添加支持AXI协议的总线桥，即AXI Crossbar。

&emsp;&emsp;点击Vivado界面左侧的IP Catalog，搜索“cross”。找到AXI Crossbar后双击打开IP核配置窗口，如图6-5所示。

<center><img src = "../assets/6-5.png" width = 100%></center>
<center>图6-5 创建AXI总线桥模块</center>

&emsp;&emsp;设置Master接口的数量为6，然后点击切换到“`Address`”标签页，按图6-6所示设置主存和外设I/O接口的基址及地址范围。

<center><img src = "../assets/6-6.png" width = 100%></center>
<center>图6-6 为主存及外设I/O接口分配地址空间</center>

&emsp;&emsp;接下来，在`miniRV_SoC.v`或`miniLA_SoC.v`中实例化总线桥，并把主存模块和外设I/O接口电路与总线桥连接起来，如下列代码所示。

```verilog title="miniRV_SoC.v 或 miniLA_SoC.v"
`ifdef RUN_TRACE
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
`else
    axi_crossbar_0 U_bridge (
        .aclk               (sys_clk),
        .aresetn            (!sys_rst),
        .s_axi_awaddr       (cpu_awaddr ),
        .s_axi_awlen        (cpu_awlen  ),
        .s_axi_awsize       (cpu_awsize ),
        .s_axi_awburst      (cpu_awburst),
        .s_axi_awvalid      (cpu_awvalid),
        .s_axi_awready      (cpu_awready),
        .s_axi_awlock       (1'b0       ),
        .s_axi_awcache      (4'h0       ),
        .s_axi_awprot       (3'h0       ),
        .s_axi_awqos        (4'h0       ),
        .s_axi_wdata        (cpu_wdata  ),
        .s_axi_wstrb        (cpu_wstrb  ),
        .s_axi_wlast        (cpu_wlast  ),
        .s_axi_wvalid       (cpu_wvalid ),
        .s_axi_wready       (cpu_wready ),
        .s_axi_bresp        (cpu_bresp  ),
        .s_axi_bvalid       (cpu_bvalid ),
        .s_axi_bready       (cpu_bready ),
        .s_axi_araddr       (cpu_araddr ),
        .s_axi_arlen        (cpu_arlen  ),
        .s_axi_arsize       (cpu_arsize ),
        .s_axi_arburst      (cpu_arburst),
        .s_axi_arvalid      (cpu_arvalid),
        .s_axi_arready      (cpu_arready),
        .s_axi_arlock       (1'b0       ),
        .s_axi_arcache      (4'h0       ),
        .s_axi_arprot       (3'h0       ),
        .s_axi_arqos        (4'h0       ),
        .s_axi_rdata        (cpu_rdata  ),
        .s_axi_rresp        (cpu_rresp  ),
        .s_axi_rlast        (cpu_rlast  ),
        .s_axi_rvalid       (cpu_rvalid ),
        .s_axi_rready       (cpu_rready ),
        .m_axi_awaddr       ({tim_awaddr , uart_awaddr , digled_awaddr , led_awaddr , sw_awaddr , bram_awaddr }),
        .m_axi_awlen        ({tim_awlen  , uart_awlen  , digled_awlen  , led_awlen  , sw_awlen  , bram_awlen  }),
        .m_axi_awsize       ({tim_awsize , uart_awsize , digled_awsize , led_awsize , sw_awsize , bram_awsize }),
        .m_axi_awburst      ({tim_awburst, uart_awburst, digled_awburst, led_awburst, sw_awburst, bram_awburst}),
        .m_axi_awvalid      ({tim_awvalid, uart_awvalid, digled_awvalid, led_awvalid, sw_awvalid, bram_awvalid}),
        .m_axi_awready      ({tim_awready, uart_awready, digled_awready, led_awready, sw_awready, bram_awready}),
        .m_axi_wdata        ({tim_wdata  , uart_wdata  , digled_wdata  , led_wdata  , sw_wdata  , bram_wdata  }),
        .m_axi_wstrb        ({tim_wstrb  , uart_wstrb  , digled_wstrb  , led_wstrb  , sw_wstrb  , bram_wstrb  }),
        .m_axi_wlast        ({tim_wlast  , uart_wlast  , digled_wlast  , led_wlast  , sw_wlast  , bram_wlast  }),
        .m_axi_wvalid       ({tim_wvalid , uart_wvalid , digled_wvalid , led_wvalid , sw_wvalid , bram_wvalid }),
        .m_axi_wready       ({tim_wready , uart_wready , digled_wready , led_wready , sw_wready , bram_wready }),
        .m_axi_bresp        ({tim_bresp  , uart_bresp  , digled_bresp  , led_bresp  , sw_bresp  , bram_bresp  }),
        .m_axi_bvalid       ({tim_bvalid , uart_bvalid , digled_bvalid , led_bvalid , sw_bvalid , bram_bvalid }),
        .m_axi_bready       ({tim_bready , uart_bready , digled_bready , led_bready , sw_bready , bram_bready }),
        .m_axi_araddr       ({tim_araddr , uart_araddr , digled_araddr , led_araddr , sw_araddr , bram_araddr }),
        .m_axi_arlen        ({tim_arlen  , uart_arlen  , digled_arlen  , led_arlen  , sw_arlen  , bram_arlen  }),
        .m_axi_arsize       ({tim_arsize , uart_arsize , digled_arsize , led_arsize , sw_arsize , bram_arsize }),
        .m_axi_arburst      ({tim_arburst, uart_arburst, digled_arburst, led_arburst, sw_arburst, bram_arburst}),
        .m_axi_arvalid      ({tim_arvalid, uart_arvalid, digled_arvalid, led_arvalid, sw_arvalid, bram_arvalid}),
        .m_axi_arready      ({tim_arready, uart_arready, digled_arready, led_arready, sw_arready, bram_arready}),
        .m_axi_rdata        ({tim_rdata  , uart_rdata  , digled_rdata  , led_rdata  , sw_rdata  , bram_rdata  }),
        .m_axi_rresp        ({tim_rresp  , uart_rresp  , digled_rresp  , led_rresp  , sw_rresp  , bram_rresp  }),
        .m_axi_rlast        ({tim_rlast  , uart_rlast  , digled_rlast  , led_rlast  , sw_rlast  , bram_rlast  }),
        .m_axi_rvalid       ({tim_rvalid , uart_rvalid , digled_rvalid , led_rvalid , sw_rvalid , bram_rvalid }),
        .m_axi_rready       ({tim_rready , uart_rready , digled_rready , led_rready , sw_rready , bram_rready })
    );
`endif

    bram_axi U_bram (
        ......
    );

`ifndef RUN_TRACE
    switch_wrap U_switch (
        ......
        .switch         (sw)
    );

    led_wrap U_led (
        ......
        .led_o          (led)
    );

    digled_wrap U_digled (
        ......
        .dig_en         (dig_en),
        .dig_seg        (dig_seg)       // {CA, CB, ..., CG, DP}
    );

    uart_wrap U_uart (
        ......
        .tx             (tx),
        .rx             (rx)
    );

    timer_wrap U_timer (
        ......
    );
`endif
```

&emsp;&emsp;注意，Trace测试框架不支持IP核仿真，因此必须通过`RUN_TRACE`宏定义对代码进行条件编译 —— 在运行Trace测试时，CPU的AXI接口与主存模块`bram_axi`直接相连，而在其他情形下，CPU通过AXI Crossbar实现6个从设备的访问。



## 5. 下板测试

&emsp;&emsp;在虚拟机中，编译上一节编写的C_TEST测试程序，把生成的.coe文件导入`bram_axi` IP核，生成比特流并下板测试。
