&emsp;&emsp;前文在介绍理想流水线时，通过分析其时空图的特点，得出其取指逻辑如下列代码所示。

```verilog title="cpu_core.v" linenums="85"
// 复位信号发生边沿变化时首次取指; 上一条已取回，同时立即取下一条
assign ifetch_req  = first_req | ifetch_valid;
assign ifetch_addr = pc;
```

&emsp;&emsp;在流水线能够处理数据冒险、控制冒险，以及访存指令和乘除法指令之后，我们需要对取指逻辑进行相应的调整，才能保证CPU能够正确运行。

&emsp;&emsp;考虑以下两种情况：

### 情况1：流水线发生暂停

&emsp;&emsp;引起流水线暂停的指令是访存指令和乘除法指令。访存指令需要读写主存，而取指操作也需要读取主存。由于系统采用哈佛结构，因此理论上取指和数据访存互不干扰。

&emsp;&emsp;在实际的计算机系统中，通常只有L1 Cache采用哈佛结构，而L2、L3 Cache以及主存、硬盘都是指令和数据不加区分进行存储的冯·诺依曼结构。<u>我们的SoC系统最终也会采用冯·诺依曼结构的主存</u>。因此，若CPU在指令访存期间继续取指，则 ^^在ICache、DCache都发生缺失（或系统没有Cache）时，会出现取指请求和数据访问请求重叠的情况^^。这种情况会使得总线的设计变得复杂。

&emsp;&emsp;对于乘除法指令而言，流水线暂停期间不会出现访存请求重叠的情况。但是由于流水线的IF阶段和ID阶段都处于暂停状态，如果要让CPU继续取指，则需要增加指令缓存器，把流水线暂停期间取到的指令先缓存起来。等到流水线暂停解除之后，就能够直接执行这些指令。

&emsp;&emsp;简言之，如果是访存指令引起流水线暂停，则此时取指需要总线具备多个访存请求同时处理的能力；而如果是乘除法指令引起流水线暂停，则需要在CPU中增设指令缓存器。这些手段能够尽量保证流水线CPU的性能，但缺点是实现复杂度较高。最简单的处理方式是，在流水线暂停期间暂停取指。

&emsp;&emsp;实现时，我们需要 **在ID阶段检测到访存指令或乘除法指令时，就暂停取指**；此外，**在访存结束或乘除法运算完成后，恢复取指**，如下列代码所示。

```verilog title="cpu_core.v"
wire pause_ifetch  = (ldst_suspend | id_is_ld_st | ex_is_ld_st) & !ldst_done |
                     (mul_div_suspend | id_is_mul_div) & !mul_div_done;
wire resume_ifetch = ldst_done | mul_div_done;

assign ifetch_req  = !pause_ifetch & (first_req    |    // 复位后首次取指
                                      ifetch_valid |    // 上一条已取回，同时立即取下一条
                                      resume_ifetch);   // 数据访存或乘除运算结束，继续取指
assign ifetch_addr = pc;
```

&emsp;&emsp;其中，`ldst_suspend`是访存指令执行时产生的流水线暂停信号；`id_is_ld_st`、`ex_is_ld_st`分别是ID阶段、EX阶段执行的指令是否是访存指令的标志位信号；`ldst_done`是访存操作完成的标志位信号。其他依此类推。

&emsp;&emsp;`pause_ifetch`信号从访存指令或乘除法指令进入ID阶段开始有效，直到访存操作及乘除法运算结束时无效。在`pause_ifetch`有效期间，CPU暂停取指。

&emsp;&emsp;当访存操作结束（即`ldst_done`有效）或乘除法运算结束（即`mul_div_done`有效），`resume_ifetch`信号有效，此时CPU恢复取指。


### 情况2：分支预测失败

&emsp;&emsp;流水线默认预测指令不跳转，从而不停地顺序取指执行。当静态分支预测失败时，流水线需要清除IF阶段、ID阶段并 ^^使用EX阶段计算出的跳转目标地址重新取指^^。因此，我们的流水线CPU需要有一个指令发生跳转的标志位信号 —— 当这个标志位信号有效时，CPU需要发出取指请求，且取指的地址由EX阶段计算得出。

&emsp;&emsp;综合情况1，我们可以得到流水线CPU的取指逻辑如下列代码所示。

```verilog title="cpu_core.v" hl_lines="7 9"
wire pause_ifetch  = (ldst_suspend | id_is_ld_st | ex_is_ld_st) & !ldst_done |
                     (mul_div_suspend | id_is_mul_div) & !mul_div_done;
wire resume_ifetch = ldst_done | mul_div_done;

assign ifetch_req  = !pause_ifetch & (first_req    |    // 复位后首次取指
                                      ifetch_valid |    // 上一条已取回，同时立即取下一条
                                      ex_bj_f      |    // 静态分支预测错误，立即用正确的地址取指
                                      resume_ifetch);   // 数据访存或乘除运算结束，继续取指
assign ifetch_addr = ex_bj_f ? ex_bj_target : pc;
```

&emsp;&emsp;其中，`ex_bj_f`是EX阶段产生的指令跳转的标志位信号，而`ex_bj_target`则是EX阶段计算得出的跳转目标地址。
