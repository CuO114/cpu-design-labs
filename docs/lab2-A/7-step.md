&emsp;&emsp;（1）把单周期CPU的工程及代码复制到另一个文件夹，然后划分单周期CPU的数据通路，并在模板工程上实现理想流水线CPU；

&emsp;&emsp;（2）使用无指令相关性、无访存、无乘除法的简单程序，对理想流水线CPU进行 ^^仿真测试^^；

&emsp;&emsp;（3）为理想流水线CPU增加冒险检测逻辑，并为分支跳转指令修改取指逻辑，使用 ^^默认预测不跳转^^ 的静态分支预测解决流水线的控制冒险；

&emsp;&emsp;（4）实现暂停法解决流水线冒险，并为访存指令和乘除法指令修改取指逻辑；

&emsp;&emsp;（5）修改流水线数据通路，实现数据前递法解决数据冒险；

&emsp;&emsp;（6）使用Trace测试框架，对具有冒险检测和处理功能的流水线CPU进行功能验证，使其通过Basic Trace测试；

!!! tip "如果需要在Vivado中运行功能仿真"
    &emsp;&emsp;使用<a href="../assets/bin2coe.py" target=_blank>bin2coe.py</a>脚本，可将Trace测试框架中的 `cdp-tests` / `bin` 文件夹下的.bin文件转换成.coe文件。

    &emsp;&emsp;参考<a href="../../lab1/3-parts/#32-block-memory" target=_blank>实验1-实验原理-功能部件设计-3.2 Block Memory的初始化-图3-8</a>，把.coe文件导入工程的IROM IP核当中，再运行功能仿真即可。

    &emsp;&emsp;如果xx.bin文件对应在 `cdp-tests` / `asm` 目录的xx.dump程序包含有数据段，则需要把.coe文件同时导入IROM和DRAM的IP核。

&emsp;&emsp;（7）与组员讨论协作，把流水线CPU集成到SoC，并使用AXI Trace调试和验证流水线SoC；

!!! tip "如果需要在Vivado中运行功能仿真"
    &emsp;&emsp;对于支持AXI总线的SoC，只需把.coe文件导入`bram_axi`的IP核即可运行功能仿真。

&emsp;&emsp;（8）与组员讨论协作，在SoC上完成CoreMark或LLAMA2推理程序的下板测试；

&emsp;&emsp;（9）尝试优化性能（比如提高频率、优化访存、优化运算等），减少CoreMark的运行时间，或提升LLAMA2的推理速率。

!!! info "CoreMark下板运行效果示例"
    &emsp;&emsp;SoC下板运行CoreMark的效果如图7-1所示。

    <center><img src = "../../lab2-B/assets/3-1.png" width = 550></center>
    <center>图7-1 CoreMark下板运行效果示意图</center>

    &emsp;&emsp;若CoreMark下板运行出现问题，可将<a href="../../lab2-B/5-ioupg/#2-io" target=_blank>C_TEST中的测试程序</a>逐一下板测试，并结合其代码进行调试。

!!! warning "注意：提升CPU时钟频率后，需相应修改C程序的频率参数"
    &emsp;&emsp;提高CPU时钟频率的方法见<a href="../../home/problems/#17-cpu" target=_blank>常见问题 - 1.7 如何提高CPU主频？</a>

    &emsp;&emsp;模板工程的CPU时钟默认为50MHz。改变频率后，需要相应地修改C程序中的频率参数，否则程序计时不准确。

    &emsp;&emsp;具体地，我们需要修改CoreMark源文件`core_portme.c`第36行的`MHZ`参数，使其等于实际的CPU频率：

    ```c title="c_test / 4_coremark / src / coremark / core_portme.c" linenums="36" hl_lines="1"
    #define MHZ 50     // CPU Clock Frequency
    #define CLOCKS_PER_SEC (1000000 * MHZ)
    ```
