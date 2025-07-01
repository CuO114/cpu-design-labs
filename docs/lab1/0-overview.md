## 1. 实验目的

&emsp;&emsp;（1）熟练掌握RISC-V或LoongArch汇编语言，熟悉并理解相应的指令系统；

&emsp;&emsp;（2）了解程序在单周期RISC-V或LoongArch SoC中的运行过程；

&emsp;&emsp;（3）进一步熟悉RARS、Logisim等汇编和模拟仿真工具的使用。



## 2. 实验内容

### 题目1：基本输入输出

&emsp;&emsp;在提供的Logisim SoC电路中，运行示例程序 **Exercise1.asm**（如果选择miniLA指令集，则运行示例程序 **Exercise1A.asm**），并阅读该程序源码，分析程序功能，结合注释提示，学习汇编程序访问I/O接口及外设的方法。

&emsp;&emsp;SoC电路具有数码管、计时器、LED和拨码开关4个外设。在本课程中，这些外设的I/O接口地址如表1-1所示。

<center>表1-1 本课程所涉及的外设</center>
<center>
<table>
  <tr>
    <th align="center">外设</th>
    <th align="center">端口数</th>
    <th align="center">端口地址</th>
    <th align="center">端口属性</th>
    <th align="center">端口功能</th>
  </tr>
  <tr>
    <td align="center">数码管</td>
    <td align="center">1</td>
    <td align="center">0xFFFF_F000</td>
    <td align="center">写</td>
    <td align="left">显示接收到的数据</td>
  </tr>
  <tr>
    <td rowspan=2 style="text-align: center; vertical-align: middle;">计时器</td>
    <td rowspan=2 style="text-align: center; vertical-align: middle;">2</td>
    <td align="center">0xFFFF_F020</td>
    <td align="center">读/写</td>
    <td align="left">读取或修改32位计时器的值</td>
  </tr>
  <tr>
    <td align="center">0xFFFF_F024</td>
    <td align="center">写</td>
    <td align="left">设置计时器时钟的分频系数</td>
  </tr>
  <tr>
    <td align="center">LED</td>
    <td align="center">1</td>
    <td align="center">0xFFFF_F060</td>
    <td align="center">写</td>
    <td align="left">显示接收到的数据</td>
  </tr>
  <tr>
    <td align="center">拨码开关</td>
    <td align="center">1</td>
    <td align="center">0xFFFF_F070</td>
    <td align="center">只读</td>
    <td align="left">提供外部输入</td>
  </tr>
</table>
</center>

!!! info "计时器的分频系数 :question:"
    &emsp;&emsp;计时器的分频系数用于控制计时频率。若分频系数为 $N (N \ge 0)$，则计时频率为SoC时钟频率的 $\frac{1}{N+1}$。

&emsp;&emsp;按照实验步骤运行程序，掌握汇编程序从汇编到运行的过程，并熟悉Logisim等工具的操作。

### 题目2：随机数排序

&emsp;&emsp;运用miniRV或miniLA指令集，编写随机数排序程序。

&emsp;&emsp;程序以最低2位拨码开关`SW[1:0]`为输入，以数码管和最低位LED为输出。程序的功能要求如图1-1所示。

<center><img src = "../assets/1-1.png" width = 520></center>
<center>图1-1 程序功能要求的示意图</center>

&emsp;&emsp;该程序具有5个阶段：

- 【阶段0】初始化后，不断读取32位计时器的值，并显示到数码管。  
&emsp;&emsp;&emsp;&emsp;&ensp;`SW[1:0]==2'd1`时进入阶段1。

- 【阶段1】以计时器最新值作为随机数种子，在数码管显示种子的值。种子只需设定一次。  
&emsp;&emsp;&emsp;&emsp;&ensp;`SW[1:0]==2'd2`时进入阶段2。

- 【阶段2】不断生成8个4bit随机数的数组，并显示到数码管。  
&emsp;&emsp;&emsp;&emsp;&ensp;`SW[1:0]==2'd3`时进入阶段3。

- 【阶段3】对最新的数组进行排序，排序完成后点亮`LED[0]`。此阶段不改变数码管显示内容。  
&emsp;&emsp;&emsp;&emsp;&ensp;`SW[1:0]==2'd0`时进入阶段4。

- 【阶段4】在数码管显示排序后的数组，程序结束。

!!! warning "注意 :teacher:"
    &emsp;&emsp;^^程序最终要在FPGA开发板上用你实现的CPU来运行和演示^^，因此 **编写程序时，不要使用你不准备实现的指令**。比如，后续设计CPU如果不实现16条附加指令，则编写程序时，只使用<a href="../2-step_rv/#21-risc-v-soc" target=_blank>实验步骤 - 2.1节 - 表3-1</a>所示的必做指令。

    &emsp;&emsp;同理，如果使用miniLA指令集，编写程序时也 **不要使用你不准备实现的指令**。如果后续设计CPU时不实现附加指令，则编写本题目时，只使用<a href="../2-step_la/#21-loongarch-soc" target=_blank>实验步骤 - 2.1节 - 表3-a</a>所示的必做指令。

&emsp;&emsp;编写程序时，可先在数据段定义变量，用于提供输入的测试数据以及记录输出的结果，并在此基础上完成程序的调试。^^调试完毕后，再将提供输入数据的变量地址改成拨码开关的I/O地址、将保存运算结果的地址改成数码管的I/O地址即可^^。


