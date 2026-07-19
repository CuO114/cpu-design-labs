## 1. 实验目的

&emsp;&emsp;（1）理解流水线CPU的结构及工作原理；

&emsp;&emsp;（2）理解流水线冲突产生的原因及其解决方法；

&emsp;&emsp;（3）掌握流水线CPU的设计与实现方法。



## 2. 实验内容

&emsp;&emsp;本实验要求改造实验1所设计的完整单周期CPU，从而实现支持miniRV或miniLA指令集的流水线CPU。

&emsp;&emsp;具体要求如下：

&emsp;&emsp;（1）<u>至少</u>实现 **五级** 流水线；

&emsp;&emsp;（2）支持miniRV或miniLA的全部指令；

&emsp;&emsp;（3）改造完整单周期CPU的数据通路，设计理想流水线CPU；

&emsp;&emsp;（4）实现静态分支预测，解决控制冒险；

&emsp;&emsp;（5）实现流水线暂停及数据前递机制，解决数据冒险；

&emsp;&emsp;（6）通过调试，使流水线CPU通过Basic Trace测试；

&emsp;&emsp;（7）与组员讨论协作，把流水线CPU集成到SoC，并使用AXI Trace调试和验证流水线SoC；

&emsp;&emsp;（8）与组员讨论协作，在SoC上完成CoreMark或LLAMA2推理程序的下板测试；

&emsp;&emsp;（9）尝试优化性能，减少CoreMark的运行时间，或提升LLAMA2的推理速率；

&emsp;&emsp;（10）模板工程默认给SoC提供50MHz的时钟，可根据实际情况自行调节频率（调节方法见<a href="../../lab1/3-parts/#11-ip" target=_blank>实验1-实验原理-功能部件设计-1.1节的图3-3</a>），要求单周期SoC频率 **^^不低于25MHz^^**、流水线SoC频率 **^^不低于50MHz^^**。

&emsp;&emsp;（11）下板检查时，要求不能有时序违例，如图0-1所示。

<center><img src = "../assets/0-1.png" width = 100%></center>
<center>图0-1 生成比特流后，出现时序违例的示意图</center>
