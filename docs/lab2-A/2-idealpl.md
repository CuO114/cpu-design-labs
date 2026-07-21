&emsp;&emsp;理想流水线一般指流水线中不存在冲突或冒险（Hazzard）问题、不存在资源冲突，且进入流水线的指令相互之间不存在依赖关系或相关关系。

&emsp;&emsp;通过修改单周期CPU的数据通路，可以实现简易流水线CPU的设计。

## 1. 修改取指逻辑

&emsp;&emsp;在理想流水线中，每个流水线阶段都有一条指令正在执行，即流水线的时空图是稠密的。以“IF-ID-EX-MEM-WB”的RISC架构经典五级流水线为例，其理想流水线如图2-1所示。

<center><img src = "../assets/2-1.png" width = 550></center>
<center>图2-1 理想流水线的执行规律示意图</center>

&emsp;&emsp;观察图2-1可知，要想达到理想流水线的效果，必须在取到一条指令时（即`ifetch_valid`有效时），立即发出下一条指令的取指请求。比如，当指令 $I_0$ 在 $clk_1$ 取到机器码时，必须同时发出指令 $I_1$ 的取指请求。因此，我们需要把单周期CPU的取指逻辑修改成：

```verilog title="cpu_core.v" linenums="85"
// 复位信号发生边沿变化时首次取指; 上一条已取回，同时立即取下一条
assign ifetch_req  = first_req | ifetch_valid;
assign ifetch_addr = pc;
```

!!! question "指令什么时候在IF阶段？什么时候进入ID阶段？"
    &emsp;&emsp;**CPU发出某条指令的取指请求时，这条指令就处于IF阶段。**
    
    &emsp;&emsp;例如，在图2-1的 $clk_0$ 处，`ifetch_req`有效，假设此时`ifetch_addr`等于指令 $I_0$ 的地址，则 $I_0$ 处于IF阶段。

    &emsp;&emsp;**在CPU发出取指请求的下一拍开始，当指令机器码被取回到CPU时，指令就处于ID阶段。**
    
    &emsp;&emsp;例如，在图2-1中，指令 $I_0$ 在 $clk_0$ 取指，而`ifetch_valid`在下一拍 $clk_1$ 有效，因此 $I_0$ 在 $clk_1$ 进入ID阶段。
    


## 2. 单周期数据通路改造

!!! tip "对于具有一定复杂度的系统，先实现大体架构，然后再逐步考虑各种特殊情况"
    &emsp;&emsp;理想流水线是功能最简单的流水线，不能停顿，不能处理指令相关。
    
    &emsp;&emsp;实现理想流水线时，暂时不要考虑分支跳转、访存、乘除法、数据相关等情况。

&emsp;&emsp;以下以图2-2所示的单周期CPU为例，介绍如何将单周期CPU改造成“取指-译码-执行”的三级理想流水CPU。

<center><img src = "../../lab1/assets/5-1.png" width = 100%></center>
<center>图2-2 单周期CPU数据通路示例</center>

&emsp;&emsp;第一步，根据目标流水线的阶段构成，分割单周期CPU的数据通路，并在分割处加入流水寄存器，将各阶段之间的接口信号缓存起来，如图2-3所示。

<center><img src = "../assets/2-3.png" width = 100%></center>
<center>图2-3 分割单周期CPU数据通路</center>

&emsp;&emsp;第二步，修改写回逻辑，确保指令的执行结果能够写回到正确的寄存器。将原有的单周期数据通路“切割”成三个流水级之后，每个流水级都有一条指令在执行。假设在某个时刻，指令I~0~、I~1~、I~2~分别处于执行阶段、译码阶段和取指阶段。当执行阶段的指令I~0~需要写回时，寄存器堆的写使能信号、目标寄存器号和写数据信号都是由指令I~1~译码产生的。此时，若进行写回操作，则将发生指令I~0~的执行结果写回到指令I~1~的目标寄存器的错误。为了避免此错误发生，需要在指令I~0~从译码阶段进入到执行阶段时，将其写回的相关信号通过流水寄存器传递到执行阶段，如图2-4所示。

<center><img src = "../assets/2-4.png" width = 100%></center>
<center>图2-4 修改写回逻辑</center>

## 3. 理想流水线CPU的仿真测试

&emsp;&emsp;设计出理想流水线之后，可通过无指令相关性、无访存、无乘除法的简单程序进行仿真测试，从而初步验证流水线架构的正确性。

&emsp;&emsp;下面给出理想流水线的参考测试程序，同学们可根据实际情况修改其中的指令。

=== "miniRV"

    ```asm linenums="1"
    xori    t0, zero, 1
    ori     t1, zero, 2
    addi    t2, zero, 3
    lui     t4, 0x4
    auipc   t5, 0x0
    slti    t6, zero, 2
    add     s0, t0, t1
    ```

    &emsp;&emsp;把上述程序保存成.asm文件，在RARS中进行汇编，如图2-5所示。

    <center><img src = "../assets/2-5.png" width = 550></center>
    <center>图2-5 在RARS中汇编代码</center>

    &emsp;&emsp;依次点击“File” -> “Dump Memory...”，选择导出方式为16进制文本格式，如图2-6所示。

    <center><img src = "../assets/2-6.png" width = 100%></center>
    <center>图2-6 在RARS中汇编代码</center>

    &emsp;&emsp;打开导出的文本文件，复制文件内的指令机器码，参考<a href="../../lab1/3-parts/#32-block-memory" target=_blank>实验1-实验原理-功能部件设计-3.2 Block Memory的初始化</a>生成.coe文件并将其导入工程的IROM IP核当中，即可运行功能仿真对理想流水线CPU进行调试和验证。

=== "miniLA :dragon:"

    ```asm linenums="1"
    xori    t0, zero, 1
    ori     t1, zero, 2
    addi.w  t2, zero, 3
    lu12i.w t4, 0x4
    pcaddu12i t5, 0x0
    slti    t6, zero, 2
    add.w   s0, t0, t1
    ```

    &emsp;&emsp;复制上述代码到<a href="https://soc.ustc.edu.cn/Lars/" target=_blank>LARS工具</a>，依次点击汇编按钮和导出COE按钮，如图2-5A所示。

    <center><img src = "../assets/2-5A.png" width = 100%></center>
    <center>图2-5A 在RARS中汇编代码</center>

    &emsp;&emsp;参考<a href="../../lab1/3-parts/#32-block-memory" target=_blank>实验1-实验原理-功能部件设计-3.2 Block Memory的初始化-图3-8</a>，把下载的.coe文件导入工程的IROM IP核当中，即可运行功能仿真对理想流水线CPU进行调试和验证。
