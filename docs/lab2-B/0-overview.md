## 1. 实验目的

&emsp;&emsp;（1）熟悉SoC的架构及工作原理；

&emsp;&emsp;（2）理解系统总线的工作原理，掌握总线控制器的设计与实现方法；

&emsp;&emsp;（3）熟悉I/O接口电路的结构及工作原理，掌握其设计与实现方法。



## 2. 实验内容

&emsp;&emsp;本实验要求在FPGA开发板（芯片型号、引脚约束等详见<a href="../../home/fpga/" target=_blank>开发板使用须知</a>）上，基于单周期或流水线CPU，设计实现支持运行CoreMark或LLAMA2推理程序的SoC（System on Chip，片上系统）。

&emsp;&emsp;具体要求如下：

&emsp;&emsp;（1）为CPU实现ICache和DCache；

&emsp;&emsp;（2）使用<u>状态机</u>设计实现支持AXI协议的总线控制器；

&emsp;&emsp;（3）为SoC添加总线桥及主存模块；

&emsp;&emsp;（4）完成 ^^I/O接口测试程序^^ 的编写，并在SoC上完成这些程序的 ^^下板测试^^；

&emsp;&emsp;（5）实现外设I/O接口电路，至少支持5个外设：^^拨码开关^^、^^LED^^、^^数码管^^、^^UART^^、^^计时器^^；

&emsp;&emsp;（6）通过调试，使单周期CPU及SoC通过AXI Trace测试；

&emsp;&emsp;（7）与组员讨论协作，把流水线CPU集成到SoC，并使用AXI Trace调试和验证流水线SoC；

&emsp;&emsp;（8）与组员讨论协作，在SoC上完成CoreMark或LLAMA2推理程序的下板测试；

&emsp;&emsp;（9）尝试优化性能，减少CoreMark的运行时间，或提升LLAMA2的推理速率；

&emsp;&emsp;（10）模板工程默认给SoC提供50MHz的时钟，可根据实际情况自行调节频率（调节方法见<a href="../../lab1/3-parts/#11-ip" target=_blank>实验1-实验原理-功能部件设计-1.1节的图3-3</a>），要求单周期SoC频率 **^^不低于25MHz^^**、流水线SoC频率 **^^不低于50MHz^^**。

&emsp;&emsp;（11）下板检查时，要求不能有时序违例，如图0-1所示。

<center><img src = "../../lab2-A/assets/0-1.png" width = 100%></center>
<center>图0-1 生成比特流后，出现时序违例的示意图</center>
