## 1. 线性反馈移位寄存器

&emsp;&emsp;线性反馈移位寄存器（LFSR，Linear Feedback Shift Register）是一种采用线性函数生成寄存器新值的移位寄存器，常用于生成随机数。

&emsp;&emsp;LFSR一般由移位寄存器和异或门构成，其典型结构如图2-1所示。在LFSR中，移位寄存器当前值的若干个比特通过异或门形成反馈回路，从而生成LFSR的新值。

<center><img src = "../assets/2-1.png" width = 550></center>
<center>图2-1 LFSR结构原理图</center>

&emsp;&emsp;在图2-1中，**LFSR的初始值称为种子**；而 **a~i~（0$\leq$i$<$n）的值只可能是0或1，表示对应的反馈线路是否生效**。

&emsp;&emsp;本实验需要生成8个4bit随机数并排序。同学们既可以通过32位LFSR生成32位随机数，然后拆分成8个4bit整数，也可以直接通过4位LFSR生成8个4bit随机数。

&emsp;&emsp;对于32位的LFSR，需令a~0~、a~1~、a~21~和a~31~等于1，对应的LFSR结构如图2-2所示。

<center><img src = "../assets/2-2.png" width = 450></center>
<center>图2-2 32位的LFSR结构图</center>

&emsp;&emsp;使用汇编程序实现LFSR的思路是：令某个寄存器（比如`s8`）为LFSR，读取计时器的值作为`s8`寄存器的初始值（即设置随机数种子）；然后通过逻辑运算或移位运算，分别取出`s8`的第0位、第1位、第21位和第31位，再将这4位经过异或后左移进`s8`。

&emsp;&emsp;类似地，对于4位的LFSR，则需令a~2~和a~3~等于1，对应的LFSR结构如图2-3所示。实现时，通过逻辑运算或移位运算，取出LFSR的第3位、第2位，再将其经过异或后左移进LFSR。

<center><img src = "../assets/2-3.png" width = 380></center>
<center>图2-3 4位的LFSR结构图</center>



## 2. miniRV指令集概述

### 2.1 通用寄存器

&emsp;&emsp;miniRV具有32个32位通用寄存器，与RV32I完全相同，如表2-1所示。

<center>表2-1 miniRV通用寄存器</center>

<center>

| 寄存器 | 助记符 | 释义 |
| :-: | :-: | :- |
| x0 | zero | 常数0，永远只返回0 (硬件0，只读不可写) |
| x1 | ra | 存放调用子程序(函数)时的返回地址 (Return Address) |
| x2 | sp | 堆栈指针。对它的调整必须显式地通过指令来实现，硬件不支持堆栈指针的调整 (Stack Pointer) |
| x3 | gp | 全局指针。某些运行时系统用来为static或extern变量提供简单的访问方式 (Global Pointer) |
| x4 | tp | 线程指针。多线程应用程序通过该寄存器来访问某个线程的本地数据 (Thread Pointer) |
| x5~x7 | t0~t2 | 存放临时变量，子程序(函数)使用时不自动保存这些寄存器的值，因此调用后它们的值可能被破坏 |
| x8 | s0/fp | 子程序用该寄存器做堆栈帧指针。子程序(函数)必须在返回前恢复这些寄存器的值以保证其没有变化 (Saved Register / Frame Pointer) |
| x9 | s1 | 子程序用寄存器。子程序(函数)必须在返回前恢复这些寄存器的值以保证其没有变化 (Saved Register) |
| x10~x11 | a0~a1 | 存放子程序(函数)调用时的整型参数或返回值 |
| x12~x17 | a2~a7 | 存放子程序(函数)调用时的整型参数 |
| x18~x27 | s2~s11 | 子程序用寄存器。子程序(函数)必须在返回前恢复这些寄存器的值以保证其没有变化 (Saved Register) |
| x28~x31 | t3~t6 | 存放临时变量，子程序(函数)使用时不自动保存这些寄存器的值，因此调用后它们的值可能被破坏 |

</center>

&emsp;&emsp;在汇编语言中，既可以通过寄存器号也可以通过助记符来引用一个寄存器。例如，汇编中的“x0”和“zero”均表示第0个寄存器；“x8”、“s0”和“fp”均表示第8个寄存器。

### 2.2 miniRV指令格式

&emsp;&emsp;miniRV指令集的指令格式与RISC-V完全相同，如图2-3所示。

<center><img src = "../../lab2/assets/2-1.png" width = 650></center>
<center>图2-3 miniRV指令格式</center>

&emsp;&emsp;miniRV指令的格式、功能、语法及解释汇总如表2-2所示。

<center>表2-2 miniRV指令总表</center>
<center><img src = "../../lab2/assets/t2-2.png"></center>



## 3. miniLA指令集概述

### 3.1 通用寄存器

&emsp;&emsp;miniLA具有32个32位通用寄存器，与LA32R完全相同，如表2-2所示。

<center>表2-2 miniLA通用寄存器</center>
<center>

| 寄存器 | 助记符 | 释义 |
| :-: | :-: | :- |
| r0 | zero | 常数0，永远只返回0 (硬件0，只读不可写) |
| r1 | ra | 存放调用子程序(函数)时的返回地址 (Return Address) |
| r2 | tp | 线程指针。多线程应用程序通过该寄存器来访问某个线程的本地数据 (Thread Pointer) |
| r3 | sp | 堆栈指针。对它的调整必须显式地通过指令来实现，硬件不支持堆栈指针的调整 (Stack Pointer) |
| r4~r5 | a0~a1 | 存放子程序(函数)调用时的整型参数或返回值 |
| r6~r11 | a2~a7 | 存放子程序(函数)调用时的整型参数 |
| r12~r20 | t0~t8 | 存放临时变量，子程序(函数)使用时不自动保存这些寄存器的值，因此调用后它们的值可能被破坏 |
| r21 | u0 | 其他通用寄存器 |
| r22 | fp / s9 | 子程序用该寄存器做堆栈帧指针。子程序(函数)必须在返回前恢复这些寄存器的值以保证其没有变化 (Frame Pointer)。或作为静态寄存器 |
| r23~r31 | s0~s8 | 静态寄存器 |

</center>

&emsp;&emsp;在miniLA架构中，指令集与通用寄存器存在正交关系，即所有的32个通用寄存器都可以被任意指令使用。

&emsp;&emsp;另外，在汇编语言中，既可以通过寄存器号也可以通过助记符来引用一个寄存器。例如，汇编中的“r0”和“zero”均表示第0个寄存器；“r3”和“sp”均表示第3个寄存器。

!!! danger "汇编使用寄存器的注意事项 :mega:"
    &emsp;&emsp;编写汇编时，在寄存器名称前添加`$`符号，如`$r0`、`$zero`等，否则LoongSonAssembler工具会报语法错误。

### 3.2 miniLA指令格式

&emsp;&emsp;miniLA指令的格式、功能、语法及解释汇总如表2-2A所示。

<center>表2-2 miniLA指令总表</center>
<center><img src = "../../lab2/assets/t2-2A.png"></center>


