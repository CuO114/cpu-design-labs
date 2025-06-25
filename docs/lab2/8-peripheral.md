## 1. 接口概述

### 1.1 接口概念

&emsp;&emsp;接口是CPU与“外部世界”的 **连接电路**，负责在CPU与“外部世界”之间“**中转**”各种信息。

&emsp;&emsp;在计算机系统中，接口 **介于系统总线与外部设备之间**，可分为 **存储器接口** 和 **I/O接口** 两类——存储器接口是CPU与存储器（如主存）之间的连接电路；I/O接口则是CPU与外部设备之间的连接电路，如图9-1所示。

<center><img src = "../assets/9-1.png" width = 500></center>
<center>图9-1 计算机系统中的接口</center>

### 1.2 接口的作用与功能

&emsp;&emsp;当CPU需要从“外部世界”获取信息，或向其输出信息时，就需要依靠各式各样的外部设备。

&emsp;&emsp;现今使用最广泛的计算机是数字计算机。在数字计算机中，指令和数据都以数字信号“0”和“1”进行表示、传输、运算和存储。而外部设备不仅种类多、功能杂，其数据格式、工作原理也各不相同。为了使得CPU能够高效、规范地使用外部设备，我们需要为外部设备设计相应的接口，以适配外部设备和CPU之间的差异。

&emsp;&emsp;在计算机系统中，接口受CPU控制，外部设备则受接口控制，如图9-2所示。

<center><img src = "../assets/9-2.png" width = 308></center>
<center>图9-2 接口的作用</center>

!!! info "补充说明 :mega:"
    &emsp;&emsp;需要注意的是，对某些外设而言，图9-2中的数据信号线可能是单向的。

&emsp;&emsp;接口通常具有以下功能：

- <font color = #0060ff>**信号转换**</font>功能（预处理功能）

&emsp;&emsp;完成总线信号与I/O设备信号之间的转换，包括信号的逻辑关系、时序配合、电平转换、串并转换等。

- <font color = #0060ff>**数据缓存**</font>功能

&emsp;&emsp;I/O接口中含有寄存器、锁存器或其他缓存存储器，用于实现CPU和外设之间的数据缓存功能。接口中用于暂存数据的缓存器称为I/O接口对CPU的 **数据口**。

- <font color = #0060ff>**接受和执行CPU命令**</font>功能

&emsp;&emsp;I/O接口中含有存放CPU命令码的寄存器，该寄存器称为I/O接口对CPU的 **命令口**。接口工作时，将根据命令口中的命令码，产生相应的控制信号，控制外设完成不同的操作。

- <font color = #0060ff>**控制和监视外设执行**</font>功能

&emsp;&emsp;I/O接口中还含有存放外设状态信息的寄存器，该寄存器称为I/O接口对CPU的 **状态口**。接口工作时，将实时监视外设的执行状态，并适时更新状态寄存器。CPU通过读取状态口，即可获取外设的执行状态。有时I/O接口也需要根据状态寄存器的值来产生外设工作所需的控制信号。

- <font color = #0060ff>**设备选择**</font>功能（选址功能）

&emsp;&emsp;CPU通过不同的地址访问不同的I/O接口以及接口中的设备。I/O接口通过地址译码器，产生设备选择信号，以选择对应的外设与CPU进行通信。

!!! info "补充说明 :mega:"
    &emsp;&emsp;（1）接口和设备不一定是一对一的关系。一个接口可能含有多个数据口、命令口和状态口。

    &emsp;&emsp;（2）每一个数据口、命令口或状态口均可由CPU通过地址直接访问。

### 1.3 接口电路

&emsp;&emsp;I/O接口电路的核心是数据口、命令口、状态口和控制逻辑，其基本结构如图9-3所示。

<center><img src = "../assets/9-3.png" width = 560></center>
<center>图9-3 I/O接口电路的结构</center>

&emsp;&emsp;由图9-3可知，CPU通过系统总线实现与I/O接口电路的交互。显然，CPU需要通过地址来区分当前访问的是命令口、数据口还是状态口。

!!! example "举个栗子 :chestnut:"
    &emsp;&emsp;假设某外设接口的基地址为`0xFFFF_FFA0`，且命令口、数据口和状态口的偏移地址分别为`2'b00`、`2'b01`和`2'b10`。
    
    &emsp;&emsp;当CPU想初始化该外设时（需要访问命令口），需要向`0xFFFF_FFA0`写入初始化命令。此时，地址`0xFFFF_FFA0`将通过系统地址总线传输到接口电路的地址译码器；初始化命令所对应的二进制编码数据将通过系统数据总线传输到接口电路的数据交叉开关；“写”信号将通过系统控制总线传输到接口电路的控制逻辑。然后，地址译码器对收到的`0xFFFF_FFA0`地址进行译码，发现<u>当前地址的高30位等于 **30'h3FFF_FFE8**</u> 且 <u>最低2位等于 **2'b00**</u>，<u>说明此时被访问的是控制寄存器</u>，则初始化命令将经过数据交叉开关，写入到控制寄存器。接下来，控制逻辑将根据控制寄存器的值，产生控制信号，控制外设完成初始化操作。
    
    &emsp;&emsp;类似地，当CPU想读取该外设的运行状态信息时（需要访问状态口），需要读取`0xFFFF_FFA2`地址。此时，地址`0xFFFF_FFA2`将通过系统地址总线传输到接口电路的地址译码器；“读”信号将通过系统控制总线传输到接口电路的控制逻辑。然后，地址译码器对`0xFFFF_FFA2`的地址进行译码，发现<u>当前地址的高30位等于 **30'h3FFF_FFE8**</u> 且 <u>最低2位等于 **2'b10**</u>，<u>说明此时被访问的是状态寄存器</u>。接下来，控制逻辑将产生控制信号，控制外设将最新的状态信息写入状态寄存器，然后状态寄存器的新值将经过数据交叉开关，写入到系统数据总线。



## 2. 基本外设

### 2.1 外设的编址方式

&emsp;&emsp;外设通常有独立编址、统一编址两种编址方式。所谓“独立”和“统一”是相对主存地址来讲的——独立编址模式中，外设的地址空间完全独立于主存地址空间之外；统一编址模式中，外设和主存共用同一片地址空间。

&emsp;&emsp;RISC-V指令集采用统一编址方式。在本课程中，32位的地址空间被划分成I/O地址空间和DRAM地址空间2部分 —— **最高4KB是I/O设备的地址空间（即0xFFFF_F000 ~ 0xFFFF_FFFF）**，其余则是DRAM存储器的地址空间（即0x0000_0000 ~ 0xFFFF_EFFF）。理论上，DRAM地址空间最大为4GB - 4KB，实际应考虑DRAM的物理存储器大小。

### 2.2 外设基地址定义

&emsp;&emsp;本课程中，规定外设基地址如表9-1所示。

<center>表9-1 基本外设基地址及端口说明</center>
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
    <td align="center">4×4键盘</td>
    <td align="center">1</td>
    <td align="center">0xFFFF_F010</td>
    <td align="center">只读</td>
    <td align="left">提供键值输入</td>
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
  <tr>
    <td align="center">按键开关</td>
    <td align="center">1</td>
    <td align="center">0xFFFF_F078</td>
    <td align="center">只读</td>
    <td align="left">提供外部输入</td>
  </tr>
</table>
</center>

### 2.3 常用外设简介

&emsp;&emsp;FPGA开发板通常具有一定的外设资源，包括12位VGA输出、10/100/1000Mbps以太网、蜂鸣器、麦克风、Micro SD卡、UART串口、矩阵键盘、数码管、LED、拨码开关、按键开关等。

&emsp;&emsp;以下介绍6种常用外设：7段数码管、计时器、拨码开关、LED、按键开关和4x4键盘。

#### 2.3.1 七段数码管

&emsp;&emsp;Minisys开发板有两个4位带小数点的七段数码管，其电路原理图如图9-4所示。其中，A7-A0是数码管8个位的使能信号（即 **位选信号**），而CA-CG及DP则对应各个位上的七个段以及小数点的触发信号（即 **段选信号**）。

!!! warning "注意数码管的有效电平"
    &emsp;&emsp;对 **Minisys开发板** 而言，位选信号和段选信号均为 **低电平有效**。
    
    &emsp;&emsp;对 **EGO1开发板** 而言，位选信号和段选信号均为 **高电平有效**。

<center><img src = "../assets/9-4.png" width = 500></center>
<center>图9-4 七段数码管与FPGA芯片的连接图</center>

&emsp;&emsp;数码管本质上是LED灯。图9-5以最后侧的A0数码管为例，说明了7段数码管的内部结构。

<center><img src = "../assets/9-5.png" width = 500></center>
<center>图9-5 七段数码管结构图</center>

&emsp;&emsp;在图9-5中，A0数码管的A段连接到DN1的CA引脚，B段连接到DN1的CB引脚，以此类推。CA-CG及DP均为低电平有效，且A7-A4、A3-A0分别共用一组段选信号。因此，如果给DN0的CA引脚提供低电平时，数码管A7-A4的A段将被同时点亮；如果给DN1的CB引脚提供低电平时，数码管A3-A0的B段将被同时点亮。

!!! info "关于EGO1开发板的数码管"
    &emsp;&emsp;EGO1开发板的8位数码管分为2组 —— 左边4位为第一组，右边4位为第二组。两组数码管具有各自独立的段选信号。实现时，可 **使用`assign`语句，令第二组数码管的段选信号始终等于第一组的段选信号**。

&emsp;&emsp;此外，每一位数码管都有一个使能信号，因此使能信号位宽为8（A[7:0]）。A[7:0]通过反相器接到对应数码管的每一个段的阳极上，因此A[7:0]也是低电平有效的。

#### 2.3.2 计时器

&emsp;&emsp;计时器也称定时器、定时计数器，是计算机硬件系统的常用外设。计时器能够实现 *ns* 级别的高精度计时，不仅能够给计算机系统提供时间基准，还能结合CPU的例外与中断处理机制，为操作系统的任务调度、延迟操作等功能提供底层硬件支持。

&emsp;&emsp;计时器的基本原理如图9-6所示。计数器0和计数器1均为32位计数器。计数器1在CPU时钟的驱动下不断地计数，直到计数值达到设定的阈值，此时计数器0的计数值加1，且计数器1被清零并重新开始计数。

<center><img src = "../assets/9-6.png" width = 350></center>
<center>图9-6 计时器电路原理图</center>

&emsp;&emsp;本课程的计时器外设具有2个端口（见表9-1），地址偏移量分别为`0x20`和`0x24`。`0x20`端口用于读取或修改计数器0的值，而`0x24`端口则用于设置阈值寄存器（即计时器分频系数）。

#### 2.3.3 拨码开关和LED

&emsp;&emsp;拨码开关和LED是最基本的输入输出设备，常用于辅助硬件调试。

&emsp;&emsp;拨码开关拨到下档时，表示向对应的FPGA引脚输入低电平，否则输入高电平。LED则是从对应的FPGA引脚接收到高电平时点亮，否则熄灭。

<center><img src = "../assets/9-7.png" width = 600></center>
<center>图9-7 Minisys开发板的拨码开关与LED电路图</center>

#### 2.3.4 按键开关

&emsp;&emsp;开发板共有6个按键开关 —— 1个复位按键和5个通用按键，如图9-8所示。当某一按键按下时，其对应的FPGA输入为1，否则为0。

<center><img src = "../assets/9-8.png" width = 400></center>
<center>图9-8 Minisys开发板的按键开关连接图</center>

&emsp;&emsp;按键开关内部包含金属弹簧，按下和弹起时，金属弹簧发生振动，从而导致电平不稳定，此种现象称为按键开关的抖动。一般可采用计数器延迟的方法进行消抖，其基本思路是，检测到按键开关信号发生变化时，启动计数器延迟10~15ms，并再次读取按键开关的电平，如图9-9所示。

<center><img src = "../assets/9-9.png" width = 100%></center>
<center>图9-9 按键信号的消抖原理示意图</center>

#### 2.3.5 4×4键盘

&emsp;&emsp;Minisys开发板的4×4键盘通过4根行选线和4根列选线连接到FPGA芯片，如图9-10所示。

<center><img src = "../assets/9-10.png" width = 500></center>
<center>图9-10 矩阵键盘的电路原理图</center>

&emsp;&emsp;4×4键盘的基本原理是行列扫描。实现时，可通过移位寄存器或计数器生成4位流水灯信号，输出到行信号，然后读取列信号。通过判断行信号与列信号的取值，即可得出被按下按键的坐标。然后把按键坐标映射到对应的键值，即需要在程序中对扫描得到的坐标行、列信号的各种组合方式进行翻译。



## 3. 带有外设的SoC架构

&emsp;&emsp;CPU通过总线桥实现了多个外设的控制。添加外设后，我们所设计的计算机系统，其顶层模块架构将形如图9-11所示。

<center><img src = "../assets/9-11.png" width = 500></center>
<center>图9-11 带有总线桥和外设的myCPU顶层模块结构图</center>

&emsp;&emsp;上一节“<a href="../7-bus/#3" target="_blank">系统总线-3.总线桥</a>”中讲到，总线桥具有中转功能，即将CPU的访问请求转发给相应的从设备。显然，总线桥可以用请求地址来查<a href="#22" target="_blank">表9-1</a>，从而判断需要把CPU的访问请求转发给哪个从设备。
