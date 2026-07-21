<style>
    pre {
        overflow-y: auto;
        max-height: 350px;
    }
</style>

&emsp;&emsp;首先，为现有的单周期CPU工程创建副本，保存好原有代码及工程。后续所有操作均在副本工程上进行，下文称其为SoC工程。

## 1. 实现Cache

&emsp;&emsp;把计算机组成原理实验3所实现的ICache.v、DCache.v源文件拷贝到单周期SoC工程的 `src` / `rtl` 目录之内。

&emsp;&emsp;打开SoC工程，添加ICache、DCache模块到Design Sources，如图4-1所示。注意不要添加成Simulations Sources或Constraints。

<center><img src = "../assets/4-1.png" width = 100%></center>
<center>图4-1 添加Cache模块源文件</center>

&emsp;&emsp;打开`cpu_top.v`，删除原有的`Inst_ROM`和`Data_RAM`模块的实例化代码，并编写ICache、DCache模块的实例化代码。



## 2. 为SoC添加AXI总线接口

&emsp;&emsp;在SoC工程的 `src` / `rtl` 目录创建`axi_master.v`文件，并参照图4-1将其添加到工程当中。

&emsp;&emsp;编写总线控制器`axi_master`的模块定义：

```verilog title="axi_master.v"
`timescale 1ns / 1ps

`include "defines.vh"

module axi_master(
    input  wire         aclk,
    input  wire         areset,     // high active

    // ICache Interface
    output reg          ic_dev_rrdy,
    input  wire         ic_cpu_ren,
    input  wire [31:0]  ic_cpu_raddr,
    output reg          ic_dev_rvalid,
    output reg  [`IC_BLK_SIZE-1:0]  ic_dev_rdata,
    // DCache Interface
    output reg          dc_dev_wrdy,
    input  wire [ 3:0]  dc_cpu_wen,
    input  wire [31:0]  dc_cpu_waddr,
    input  wire [31:0]  dc_cpu_wdata,
    output reg          dc_dev_rrdy,
    input  wire         dc_cpu_ren,
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

    // TODO


endmodule
```

&emsp;&emsp;在`cpu_top.v`中添加`axi_master`模块的实例化代码：

```verilog title="cpu_top.v"
    axi_master U_aximaster (
        .aclk           (),
        .areset         (),

        // ICache Interface
        .ic_dev_rrdy    (),
        .ic_cpu_ren     (),
        .ic_cpu_raddr   (),
        .ic_dev_rvalid  (),
        .ic_dev_rdata   (),
        // DCache Interface
        .dc_dev_wrdy    (),
        .dc_cpu_wen     (),
        .dc_cpu_waddr   (),
        .dc_cpu_wdata   (),
        .dc_dev_rrdy    (),
        .dc_cpu_ren     (),
        .dc_cpu_raddr   (),
        .dc_dev_rvalid  (),
        .dc_dev_rdata   (),

        // AXI4 Master Interface
        // write address channel
        .m_axi_awaddr   (),
        .m_axi_awlen    (),
        .m_axi_awsize   (),
        .m_axi_awburst  (),
        .m_axi_awready  (),
        .m_axi_awvalid  (),
        // write data channel
        .m_axi_wdata    (),
        .m_axi_wready   (),
        .m_axi_wstrb    (),
        .m_axi_wlast    (),
        .m_axi_wvalid   (),
        // write response channel
        .m_axi_bready   (),
        .m_axi_bresp    (),
        .m_axi_bvalid   (),
        // read address channel
        .m_axi_araddr   (),
        .m_axi_arlen    (),
        .m_axi_arsize   (),
        .m_axi_arburst  (),
        .m_axi_arready  (),
        .m_axi_arvalid  (),
        // read data channel
        .m_axi_rdata    (),
        .m_axi_rready   (),
        .m_axi_rresp    (),
        .m_axi_rlast    (),
        .m_axi_rvalid   ()
    );
```

&emsp;&emsp;为`cpu_top.v`添加AXI总线的Master接口：

```verilog title="cpu_top.v"
module cpu_top(
    input  wire         cpu_clk,
    input  wire         cpu_rst,        // high active

    // AXI4 Master Interface
    // write address channel
    output wire [31:0]  m_axi_awaddr,
    output wire [ 7:0]  m_axi_awlen,
    output wire [ 2:0]  m_axi_awsize,
    output wire [ 1:0]  m_axi_awburst,
    input  wire         m_axi_awready,
    output wire         m_axi_awvalid,
    // write data channel
    output wire [31:0]  m_axi_wdata,
    input  wire         m_axi_wready,
    output wire [ 3:0]  m_axi_wstrb,
    output wire         m_axi_wlast,
    output wire         m_axi_wvalid,
    // write response channel
    output wire         m_axi_bready,
    input  wire [ 1:0]  m_axi_bresp,
    input  wire         m_axi_bvalid,
    // read address channel
    output wire [31:0]  m_axi_araddr,
    output wire [ 7:0]  m_axi_arlen,
    output wire [ 2:0]  m_axi_arsize,
    output wire [ 1:0]  m_axi_arburst,
    input  wire         m_axi_arready,
    output wire         m_axi_arvalid,
    // read data channel
    input  wire [31:0]  m_axi_rdata,
    output wire         m_axi_rready,
    input  wire [ 1:0]  m_axi_rresp,
    input  wire         m_axi_rlast,
    input  wire         m_axi_rvalid
);
```

&emsp;&emsp;根据信号名，把`cpu_top`模块的AXI Master接口信号，连接到`axi_master`模块的实例。

&emsp;&emsp;打开`miniRV_SoC.v`或`miniLA_SoC.v`，为`cpu_top`模块的实例添加AXI接口信号连接：

```verilog title="miniRV_SoC.v 或 miniLA_SoC.v"
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
```



## 3. 创建AXI接口的主存模块

&emsp;&emsp;在SoC工程中，点击界面左侧的`IP Catalog`，搜索“`block`”。找到`Block Memory Generator`后双击打开IP核配置窗口，如图4-2所示。

<center><img src = "../assets/4-2.png" width = 100%></center>
<center>图4-2 创建`bram_axi`的主存IP核</center>

&emsp;&emsp;设置IP核的名称为“`bram_axi`”，设置接口类型为AXI4，并且设置存储类型为`Simple Dual Port RAM`。

&emsp;&emsp;在图4-2中，点击切换到“`Port A Options`”标签页，按图4-3所示配置IP核的数据位宽及存储深度（即数据单元的个数）。

<center><img src = "../assets/4-3.png" width = 500></center>
<center>图4-3 配置主存IP核的数据位宽及容量</center>

&emsp;&emsp;继续点击切换到“`Other Options`”标签页，勾选“`Load init File`”，并通过Browse按钮选择SoC工程的 `src` / `coe` 目录下的`lw.coe`或`ld.w.coe`；然后继续勾选“`Fill Remaining Memory Locations`”，并取消“`Enable Safety Circuit`”，如图4-4所示。

<center><img src = "../assets/4-4.png" width = 100%></center>
<center>图4-4 使用.coe初始主存IP核</center>

&emsp;&emsp;`lw.coe`或`ld.w.coe`是使用上一节实验步骤中的`bin2coe.py`脚本对 `cdp-tests` / `bin` 中的`lw.bin`或`ld.w.bin`进行转换得到的。

&emsp;&emsp;接下来，在`miniRV_SoC.v`或`miniLA_SoC.v`中实例化并连接`bram_axi` IP核：

```verilog title="miniRV_SoC.v 或 miniLA_SoC.v"
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
```



## 4. 实现总线控制器`axi_master`

&emsp;&emsp;基于Cache的接口时序，以及AXI的读时序和写时序，分别设计`axi_master`处理读请求、写请求的状态机，绘制出对应的状态转换图。

&emsp;&emsp;打开`axi_master.v`，使用状态机的“三段式”结构时序AXI的读通道、写通道。

&emsp;&emsp;上一小节我们使用了`lw.coe`或`ld.w.coe`程序来初始化主存IP核。阅读 `cdp-tests` / `asm` 中的<a href="https://gitee.com/hitsz-cslab/cdp-tests/blob/miniRV/asm/lw.dump" target=_blank>`lw.dump`</a>或<a href="https://gitee.com/hitsz-cslab/cdp-tests/blob/miniLA/asm/ld.w.dump" target=_blank>`ld.w.dump`</a>反汇编代码可知，程序中只有读访存指令，没有写访存指令。因此，CPU执行该程序时，只会向主存发出读数据请求。

&emsp;&emsp;为了降低实现难度，建议同学们在实现总线控制器`axi_master`的时候，先实现读通道（AR、R通道）。在Vivado中通过`lw.coe`或`ld.w.coe`程序的功能仿真测试后，再实现写通道（AW、W、B通道）。

&emsp;&emsp;在读通道、写通道均已实现之后，可使用`bin2coe.py`脚本把`sw.bin`或`st.w.bin`转换成.coe文件，然后将其导入`bram_axi`的IP核，再进行功能仿真测试。

!!! tip "调试建议"
    &emsp;&emsp;实现`axi_master`后，首次在Vivado运行功能仿真之前，建议先通过`defines.vh`头文件禁用Cache。等通过仿真测试之后，启用Cache并再次进行调试。
