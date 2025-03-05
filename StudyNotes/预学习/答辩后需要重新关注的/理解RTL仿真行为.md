- [Verilator使用指南](#verilator使用指南)
  - [Verilator的工作原理](#verilator的工作原理)
  - [Verilator 的编译命令](#verilator-的编译命令)
  - [自定义编译规则](#自定义编译规则)
- [理解RTL仿真行为](#理解rtl仿真行为)
  - [阅读verilator编译出的C++代码, 然后结合verilog代码, 理解仿真器进行仿真的时候都发生了什么](#阅读verilator编译出的c代码-然后结合verilog代码-理解仿真器进行仿真的时候都发生了什么)
    - [Verilator编译流程](#verilator编译流程)
    - [verilator编译后生成以下文件：](#verilator编译后生成以下文件)
    - [具体模块相关：](#具体模块相关)
    - [Makefile及相关编译文件：](#makefile及相关编译文件)
    - [仿真器运行时的过程（当运行仿真程序时，最终生成了可执行文件）](#仿真器运行时的过程当运行仿真程序时最终生成了可执行文件)
    - [verilator中的时钟事件](#verilator中的时钟事件)

# Verilator使用指南
## Verilator的工作原理
verilator 会根据 Verilog代码 生成 C/C++代码 和 指导编译的Makefile。生成的 C/C++代码 和 C/C++编写的测试激励文件 汇总成 完整的仿真程序 和 指导编译的Makefile一起编译成可执行文件。  

Verilator 的主要功能就是将 Verilog 代码转化为 SystemC 或 C++ 代码。以处理器的仿真为例：
* 首先，Verilator 将 Verilog 代码中并行的各个逻辑部件以合适的顺序串行化，使硬件设计转化为一个类似于处理器模拟器的软件；
* 接着，我们需要使用 C/C++ 编写激励文件。Verilator 为我们提供了顶层模块输入/输出引脚的接口，使我们得以对顶层模块的输入信号赋值或读取其输出信号。与使用 Vivado 仿真不同的是，我们可以实时地输出一些调试信息；要查看波形图时，需要将波形图导出到文件；
* 最后，Verilator 会生成一个 Makefile 脚本，利用 GCC 等编译器将生成的 C/C++ 文件和我们编写的激励文件编译成成用于仿真的可执行文件。  
## Verilator 的编译命令
Verilator 的编译命令如下：  
```
$ verilator <options> <verilog-file> <cpp-file>
```  
其中，<verilog_file> 是需要仿真的 Verilog 文件，<cpp_file> 是手动编写的 C++ 激励文件。<options> 是一些编译选项，这里列出一些常用的编译选项：  
* --cc：指定将 Verilog 代码转化为 C++ 代码；
* --exe：指定生成目标为可执行文件；
* --build：直接编译生成目标文件；
* --trace：导出波形文件时需要添加此选项；
* --top-module <top-module>：指定 Verilog 顶层模块；
* --Mdir <build-dir>：指定生成文件的目录；
* -CFLAGS <c-flags>：指定一个 GCC 的编译选项；
* -I <include-path>：可以指定一个包含路径。

## 自定义编译规则
Verilator 会生成一个 Makefile 文件用于指导编译，通常名字为 V<top-module>.mk。在指定 --build 选项时，直接使用 make 命令进行编译。  

有时候，我们需要自定义编译的规则。这时我们就不能使用 --build 选项自动编译，而是应当重写一个 Makefile，在其中使用 include 命令包含 Verilator 生成的 Makefile 文件。在执行时也需要先使用 Verilator 生成文件，再使用 Make 手动编译。  

# 理解RTL仿真行为
## 阅读verilator编译出的C++代码, 然后结合verilog代码, 理解仿真器进行仿真的时候都发生了什么
Verilator 是一个用于 Verilog 代码仿真的工具，它会将 Verilog 代码转换为 C++ 代码，并生成可以独立执行的仿真程序。  

### Verilator编译流程  
   当使用 verilator --cc --exe ... 进行编译时，会发生以下几个阶段：
   * 解析Verilog代码：verilator会解析verilog代码，检查语法，构建内部数据结构。
   * 转换为C++代码：将verilog代码转换为等效的C++代码，以提高仿真性能。
   * 编译C++代码：生成的C++代码被编译成可执行的仿真程序。 

### verilator编译后生成以下文件：  
* Vps2_top.h     :Vps2_top 模块的头文件。包括端口声明、构造函数、API方法和抽象方法实现。
* Vps2_top.cpp   :核心 C++ 代码，包含 Vps2_top 模块的实现。
* Vps2_top__Syms.h:符号表的头文件，定义了数据结构，包含所有子模块的引用。
* Vps2_top__Syms.cpp:符号表的实现，管理模块的层级结构和信号。
* Vps2_top__ConstPool_0.cpp：常量池，存储verilator发现的固定常量（如静态变量、查找表）等。

### 具体模块相关：  
* Vps2_top___024root.h:Vps2_top 顶层模块的 C++ 结构定义。定义了顶层模块Vps2_top___024root，包括输入信号、输出信号、内部信号、构造函数、析构函数和配置方法。
* Vps2_top___024root_Slow.cpp: Verilator输出的设计实现内部结构，负责初始化和管理verilog设计对应的C++模块。
* Vps2_top___024root__DepSet_hxxxxxxx__0.cpp / Vps2_top___024root__DepSet_hxxxxxxx__0__Slow.cpp： 这些通常是自动生成的代码块，用于处理模块之间的依赖关系。

### Makefile及相关编译文件：  
* Vps2_top.mk： Makefile，用于编译 Vps2_top 相关代码。
* Vps2_top_classes.mk： 额外的 Makefile 片段，定义 Verilator 生成的类信息。
* Vps2_top__ALL.cpp： 包含所有 Verilator 生成的代码（通常用于优化编译）。
* Vps2_top__ALL.o：编译后的目标文件。
* Vps2_top__ALL.a：打包后的静态库文件。
* Vps2_top__ALL.d：依赖文件。
* Vps2_top__ver.d：记录版本信息。
* Vps2_top__verFiles.dat：包含 Verilator 解析过的 Verilog 文件列表。

其他相关：
* ps2_top.o：与 ps2_top 模块相关的目标文件。
* ps2_top.d：该文件的依赖关系。


### 仿真器运行时的过程（当运行仿真程序时，最终生成了可执行文件）
* 初始化：verilator运行时库初始化；创建Vps2_top实例，并为信号和模块分配内存。
* 仿真循环：每个时钟周期，Verilator运行转换后的C++代码，模拟Verilog逻辑。可以使用eval()函数让verilator计算信号的状态。
* 输出结果： 用vl_printf()或者Verilated::time()记录仿真数据。启用了VerilatedVcdC，可以生成波形文件。

### verilator中的时钟事件 
verilator生成的程序是不会自动生成时钟的，我们需要在激励文件中设定时钟的行为，并通过顶层模块的输入传给要仿真的逻辑电路。这进一步解释了仿真不能检测出时序问题的原因：仿真程序的执行流是设定时钟与调用eval()方法的交替。在调用eval()方法计算出新的电路状态之前，时钟将不会被更新。




