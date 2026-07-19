&emsp;&emsp;（1）把单周期CPU的工程及代码复制到另一个文件夹，然后在其基础上开发总线控制器和I/O接口电路；

&emsp;&emsp;（2）把计算机组成原理实验3所实现的ICache、DCache模块集成到单周期CPU的工程当中；

&emsp;&emsp;（3）使用状态机实现AXI总线控制器模块`axi_master`，添加总线桥和主存IP核；

&emsp;&emsp;（4）完成I/O接口编程的C_TEST测试程序，并使用提供的SoC比特流进行下板测试；

&emsp;&emsp;（5）至少实现 ^^拨码开关^^、^^LED^^、^^数码管^^、^^UART^^ 和 ^^计时器^^ 共5个外设的I/O接口电路；

&emsp;&emsp;（6）使用Trace测试框架，对包含AXI总线控制器和I/O接口的单周期SoC进行功能验证，使其通过AXI Trace测试；

!!! tip "调试建议"
    &emsp;&emsp;首次使用包含AXI总线的SoC运行Trace测试时，建议先通过`defines.vh`头文件禁用Cache。等通过AXI Trace测试之后，启用Cache并再次进行调试。

!!! tip "如果需要在Vivado中运行功能仿真"
    &emsp;&emsp;使用<a href="../assets/bin2coe.py" target=_blank>bin2coe.py</a>脚本，可将Trace测试框架中的 `cdp-tests` / `bin` 文件夹下的.bin文件转换成.coe文件。

    &emsp;&emsp;参考<a href="../../lab1/3-parts/#32-block-memory" target=_blank>实验1-实验原理-功能部件设计-3.2 Block Memory的初始化-图3-8</a>，把.coe文件导入`bram_axi`的IP核当中，再运行功能仿真即可。

&emsp;&emsp;（7）与组员讨论协作，把流水线CPU集成到SoC，并使用AXI Trace调试和验证流水线SoC；

&emsp;&emsp;（8）与组员讨论协作，在SoC上完成CoreMark或LLAMA2推理程序的下板测试；

&emsp;&emsp;（9）尝试优化性能（比如提高频率、优化访存、优化运算等），减少CoreMark的运行时间，或提升LLAMA2的推理速率。

!!! info "CoreMark运行效果示例"
    &emsp;&emsp;SoC下板运行CoreMark的效果如图3-1所示。

    <center><img src = "../assets/3-1.png" width = 550></center>
    <center>图3-1 CoreMark下板运行效果示意图</center>

    &emsp;&emsp;若CoreMark下板运行出现问题，可将<a href="../../lab2-B/5-ioupg/#2-io" target=_blank>C_TEST中的测试程序</a>逐一下板测试，并结合其代码进行调试。

!!! warning "注意：提升CPU时钟频率后，需相应修改C程序的频率参数"
    &emsp;&emsp;提高CPU时钟频率的方法见<a href="../../home/problems/#17-cpu" target=_blank>常见问题 - 1.7 如何提高CPU主频？</a>

    &emsp;&emsp;模板工程的CPU时钟默认为50MHz。改变频率后，需要相应地修改C程序中的频率参数，否则程序计时不准确。

    &emsp;&emsp;具体地，我们需要修改CoreMark源文件`core_portme.c`第36行的`MHZ`参数，使其等于实际的CPU频率：

    ```c title="c_test / 4_coremark / src / coremark / core_portme.c" linenums="36" hl_lines="1"
    #define MHZ 50     // CPU Clock Frequency
    #define CLOCKS_PER_SEC (1000000 * MHZ)
    ```
