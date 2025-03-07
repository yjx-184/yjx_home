- [先认识计算机](#先认识计算机)
- [深入理解nemu](#深入理解nemu)
  - [框架代码初探](#框架代码初探)
    - [nemu/目录下的源文件组织如下(并未列出所有文件):](#nemu目录下的源文件组织如下并未列出所有文件)
    - [NEMU ISA相关的API说明文档](#nemu-isa相关的api说明文档)
  - [准备第一个客户程序](#准备第一个客户程序)
    - [读完这里的讲义，我们总结](#读完这里的讲义我们总结)
  - [运行第一个客户程序](#运行第一个客户程序)
  - [重做优雅地退出](#重做优雅地退出)
  - [就是这么简单](#就是这么简单)
  - [基础设施: 简易调试器](#基础设施-简易调试器)
    - [解析命令](#解析命令)
    - [单步执行](#单步执行)
    - [打印寄存器](#打印寄存器)
    - [扫描内存](#扫描内存)
  - [表达式求值](#表达式求值)
    - [算术表达式的词法分析](#算术表达式的词法分析)
    - [实现算术表达式求值](#实现算术表达式求值)
  - [表达式生成器的前置细节问题（算思考题）](#表达式生成器的前置细节问题算思考题)
  - [除0的确切行为](#除0的确切行为)
  - [实现监视点池的管理](#实现监视点池的管理)
  - [思考题：为什么要使用static？](#思考题为什么要使用static)
  - [实现监视点](#实现监视点)



# 先认识计算机
(虽然看起来是抄了一遍，但其实还是为了结合讲义把具体的过程做一遍，然后进行总结，主要还是为了方便回忆orz)
简单的计算机：  
**CPU：**  CPU是负责处理数据的核心电路单元，程序的执行全靠它。但只有存储器的计算机还是不能进行计算. 自然地, CPU需要肩负起计算的重任, 先驱为CPU创造了运算器, 这样就可以对数据进行各种处理了. 
**指令：** 用来指示CPU对数据进行何种处理。  

计算机就只需要做一件事情:
```
while (1) {
  从PC指示的存储器位置取出指令;
  执行指令;
  更新PC;
}
```  
我们只要将一段指令序列放置在存储器中, 然后让PC指向第一条指令, 计算机就会自动执行这一段指令序列, 永不停止.

# 深入理解nemu
## 框架代码初探
根据讲义，当前只需要关心NEMU子项目中的内容。NEMU主要有4个模块构成: monitor, CPU, memory, 设备。  

CPU（中央处理单元）是计算机的大脑，负责执行程序中的指令，进行算术运算、逻辑运算、数据传输和控制操作。它通过从内存中读取指令并执行来处理任务，核心部件包括算术逻辑单元（ALU）、控制单元（CU）和寄存器。  

Memory（内存）用于存储计算机运行时所需的程序、数据和指令。它提供快速访问的存储空间，分为主存（如RAM）和辅助存储（如硬盘）。主存直接与CPU连接，存储正在执行的程序和数据；辅助存储用于长期保存数据。内存的速度通常远快于硬盘，但存储容量较小。  

Monitor(监视器)模块是为了方便地监控客户计算机的运行状态而引入的. 它除了负责与GNU/Linux进行交互(例如读入客户程序)之外, 还带有调试器的功能, 为NEMU的调试提供了方便的途径. 从概念上来说, monitor并不属于一个计算机的必要组成部分, 但对NEMU来说, 它是必要的基础设施. 如果缺少monitor模块, 对NEMU的调试将会变得十分困难.  

### nemu/目录下的源文件组织如下(并未列出所有文件):
```
nemu
├── configs                    # 预先提供的一些配置文件
├── include                    # 存放全局使用的头文件
│   ├── common.h               # 公用的头文件
│   ├── config                 # 配置系统生成的头文件, 用于维护配置选项更新的时间戳
│   ├── cpu
│   │   ├── cpu.h
│   │   ├── decode.h           # 译码相关
│   │   ├── difftest.h
│   │   └── ifetch.h           # 取指相关
│   ├── debug.h                # 一些方便调试用的宏
│   ├── device                 # 设备相关
│   ├── difftest-def.h
│   ├── generated
│   │   └── autoconf.h         # 配置系统生成的头文件, 用于根据配置信息定义相关的宏
│   ├── isa.h                  # ISA相关
│   ├── macro.h                # 一些方便的宏定义
│   ├── memory                 # 访问内存相关
│   └── utils.h
├── Kconfig                    # 配置信息管理的规则
├── Makefile                   # Makefile构建脚本
├── README.md
├── resource                   # 一些辅助资源
├── scripts                    # Makefile构建脚本
│   ├── build.mk
│   ├── config.mk
│   ├── git.mk                 # git版本控制相关
│   └── native.mk
├── src                        # 源文件
│   ├── cpu
│   │   └── cpu-exec.c         # 指令执行的主循环
│   ├── device                 # 设备相关
│   ├── engine
│   │   └── interpreter        # 解释器的实现
│   ├── filelist.mk
│   ├── isa                    # ISA相关的实现
│   │   ├── mips32
│   │   ├── riscv32
│   │   ├── riscv64
│   │   └── x86
│   ├── memory                 # 内存访问的实现
│   ├── monitor
│   │   ├── monitor.c
│   │   └── sdb                # 简易调试器
│   │       ├── expr.c         # 表达式求值的实现
│   │       ├── sdb.c          # 简易调试器的命令处理
│   │       └── watchpoint.c   # 监视点的实现
│   ├── nemu-main.c            # 你知道的...
│   └── utils                  # 一些公共的功能
│       ├── log.c              # 日志文件相关
│       ├── rand.c
│       ├── state.c
│       └── timer.c
└── tools                      # 一些工具
    ├── fixdep                 # 依赖修复, 配合配置系统进行使用
    ├── gen-expr
    ├── kconfig                # 配置系统
    ├── kvm-diff
    ├── qemu-diff
    └── spike-diff
```  
### NEMU ISA相关的API说明文档
为了提高性能, 这些API也可以通过宏定义实现, 但本文档还是以C变量或函数的方式列出, 以给出变量或函数的类型.  

**全局类型:** 
* ```word_t;``` 表示与ISA字长等长的无符号类型, 在32位的ISA中为uint32_t, 在64位的ISA中为uint64_t.
* ```sword_t;``` 表示与ISA字长等长的有符号类型, 在32位的ISA中为int32_t, 在64位的ISA中为int64_t.
* ```char *FMT_WORD;``` word_t类型对应的十六进制格式化说明符, 在32位的ISA中为"0x%08x", 在64位的ISA中为"0x%016lx".

**Monitor相关:**  
* ```unsigned char isa_logo[];``` 用于在未实现指令的报错信息中提示开发者阅读相关的手册.
* ```word_t RESET_VECTOR;``` 表示PC的初始值.
* ```void init_isa();``` 在monitor初始化时调用, 进行至少如下ISA相关的初始化工作:设置必要的寄存器初值, 如PC等; 加载内置客户程序

**寄存器相关:**  
```
struct {
  // ...
  word_t pc;
} CPU_state;
```  
寄存器结构的类型定义, 其中必须包含一个名为pc, 类型为word_t的成员.  

* ```CPU_state cpu;``` 寄存器结构的全局定义.
* ```void isa_reg_display();``` 用于打印寄存器当前的值.
* ```word_t isa_reg_str2val(const char *name, bool *success);``` 若存在名称为name的寄存器, 则返回其当前值, 并设置success为true; 否则设置success为false.


**指令执行相关:**
```
struct {
  // ...
} ISADecodeInfo;
```  
用于存放ISA相关的译码信息, 会嵌入在译码信息结构体Decode的定义中.  

* ```int isa_exec_once(Decode *s);``` 取出s->pc指向的指令并译码执行, 同时更新s->snpc.

**虚拟内存相关:**  
```int isa_mmu_check(vaddr_t vaddr, int len, int type);```   
检查当前系统状态下对内存区间为[vaddr, vaddr + len), 类型为type的访问是否需要经过地址转换.   
  其中type可能为:
  * MEM_TYPE_IFETCH: 取指令;
  * MEM_TYPE_READ: 读数据;
  * MEM_TYPE_WRITE: 写数据

函数返回值可能为:  
* MMU_DIRECT: 该内存访问可以在物理内存上直接进行;
* MMU_TRANSLATE: 该内存访问需要经过地址转换;
* MMU_FAIL: 该内存访问失败, 需要抛出异常(如RISC架构不支持非对齐的内存访问)

```paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type);```  
对内存区间为[vaddr, vaddr + len), 类型为type的内存访问进行地址转换. 函数返回值可能为:  
* pg_paddr | MEM_RET_OK: 地址转换成功, 其中pg_paddr为物理页面的地址(而不是vaddr翻译后的物理地址)
* MEM_RET_FAIL: 地址转换失败, 原因包括权限检查失败等不可恢复的原因, 一般需要抛出异常
* MEM_RET_CROSS_PAGE: 地址转换失败, 原因为访存请求跨越了页面的边界

**中断异常相关：**  
```vaddr_t isa_raise_intr(word_t NO, vaddr_t epc);``` 抛出一个号码为NO的异常, 其中epc为触发异常的指令PC, 返回异常处理的出口地址.  
```word_t isa_query_intr();``` 查询当前是否有未处理的中断, 若有则返回中断号码, 否则返回INTR_EMPTY.  

**DiffTest相关:**  
```bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc);``` 检查当前的寄存器状态是否与ref_r相同, 其中pc为cpu.pc的上一条动态指令的PC, 即cpu.pc的旧值. 如果状态相同, 则返回true, 否则返回false.  
```void isa_difftest_attach();``` 将当前的所有状态同步到REF, 并在之后的执行中开启DiffTest.  

## 准备第一个客户程序
 NEMU是一个用来执行客户程序的程序, 但客户程序一开始并不存在于客户计算机中. 我们需要将客户程序读入到客户计算机中, 这件事是monitor来负责的. 于是NEMU在开始运行的时候, 首先会调用init_monitor()函数(在nemu/src/monitor/monitor.c中定义) 来进行一些和monitor相关的初始化工作.  
 ```
//初始化监控系统（包括命令行参数解析、内存、设备等初始化
void init_monitor(int argc, char *argv[]) {
  /* 执行一些全局初始化 */

  /* 解析命令行参数 */
  parse_args(argc, argv);

  /*设置随机数种子 */
  init_rand();

  /* 打开日志文件  */
  init_log(log_file);

  /* 初始化内存 */
  init_mem();

  /* 初始化设备（如果配置了设备） */
  IFDEF(CONFIG_DEVICE, init_device());

  /* 执行与ISA相关的初始化 */
  init_isa();

  /* 加载映像到内存，这将覆盖内置映像*/
  long img_size = load_img();

  /* 初始化差分测试系统*/
  init_difftest(diff_so_file, img_size, difftest_port);

  /* 初始化简单调试器（SDB*/
  init_sdb();

  IFDEF(CONFIG_ITRACE, init_disasm());//如果配置了指令跟踪，初始化反汇编

  /* 打印欢迎信息 */
  welcome();
}
 ```  

接下来monitor会调用init_isa()函数(在nemu/src/isa/$ISA/init.c中定义), 来进行一些ISA相关的初始化工作.  

第一项工作就是将一个内置的客户程序读入到内存中. 为了理解这项工作, 我们还需要理清三个问题:
1. 客户程序是什么? 我们知道, 程序是由指令构成的, 而不同ISA的指令也各不相同(想象一下用不同的语言来表达"你好"的意思), 因而程序本身肯定是ISA相关的. 因此, 我们把内置客户程序放在nemu/src/isa/$ISA/init.c中. 内置客户程序的行为非常简单, 它只包含少数几条指令, 甚至算不上在做一些有意义的事情。
2. 内存是什么? 我们可以把内存看作一段连续的存储空间, 而内存又是字节编址的(即一个内存位置存放一个字节的数据), 在C语言中我们就很自然地使用一个uint8_t类型的数组来对内存进行模拟. NEMU默认为客户计算机提供128MB的物理内存(见nemu/src/memory/paddr.c中定义的pmem),
3. 需要将客户程序读入到内存的什么位置? 为了让客户计算机的CPU可以执行客户程序, 因此我们需要一种方式让客户计算机的CPU知道客户程序的位置. 我们采取一种最简单的方式: 约定. 具体地, 我们让monitor直接把客户程序读入到一个固定的内存位置RESET_VECTOR. RESET_VECTOR的值在nemu/include/memory/paddr.h中定义.  

***
内置程序（nemu/src/isa/$ISA/init.c）：   
```
#include <isa.h>
#include <memory/paddr.h>

// 这个数组与 uint8_t 类型不一致，
// 但由于我们不会直接访问这个数组，所以没问题
static const uint32_t img [] = {
  0x00000297,  // auipc t0,0                  -- 将当前PC值加上偏移量0，并存储到t0寄存器
  0x00028823,  // sb  zero,16(t0)             -- 将零寄存器的值（0）存入t0+16地址的内存
  0x0102c503,  // lbu a0,16(t0)               -- 从t0+16地址读取一个字节并存入a0寄存器
  0x00100073,  // ebreak (used as nemu_trap)  -- 触发异常，通常用于调试或设置断点
  0xdeadbeef,  // some data                   -- 一些数据
};

static void restart() {
  /* 设置初始的程序计数器（PC）。 */
  cpu.pc = RESET_VECTOR;

  /* 零寄存器（x0）的值始终是0。 */
  cpu.gpr[0] = 0;
}

void init_isa() {
  /* 加载内置程序映像。 */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));

  /* 初始化虚拟计算机系统。 */
  restart();
}
```  
在这个代码中，模拟了一个虚拟计算机的初始化过程，并加载了一些简单的指令和数据提供后续执行。  
* img 数组：包含了一些指令和数据，模拟了一个简单的程序。这些指令通过memcpy被加载道内存中，供虚拟计算机执行。
* restart()函数：设置程序计数器为复位向量RESET_VECTOR，并将零寄存器的值设为0。
* init_isa() 函数：加载程序映像并初始化虚拟计算机系统，调用restart()来进行初始化。

**根据讲义的意思，我们确实是看到了monitor直接把客户程序加载到RESET_VECTOR。这样 CPU 复位后会从 RESET_VECTOR 处开始执行指令，模拟一个计算机的启动过程。**  

guest_to_host()函数在nemu/src/memory/paddr.c中定义：  
```
//将物理地址转换为主机内存地址，物理地址到主机地址的转换，偏移量由配置的基地址决定
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
```  

init_isa()的第二项任务是初始化寄存器, 这是通过restart()函数来实现的. 在CPU中, 寄存器是一个结构化特征较强的存储部件, 在C语言中我们就很自然地使用相应的结构体来描述CPU的寄存器结构. 不同ISA的寄存器结构也各不相同, 为此我们把寄存器结构体CPU_state的定义放在nemu/src/isa/$ISA/include/isa-def.h中, 并在nemu/src/cpu/cpu-exec.c中定义一个全局变量cpu. 初始化寄存器的一个重要工作就是设置cpu.pc的初值, 我们需要将它设置成刚才加载客户程序的内存位置, 这样就可以让CPU从我们约定的内存位置开始执行客户程序了. 对于mips32和riscv32, 它们的0号寄存器总是存放0, 因此我们也需要对其进行初始化.

### 读完这里的讲义，我们总结
在NEMU运行时，monitor负责初始化整个模拟环境，其中包括调用 init_isa()进行相关的初始化。这个过程主要涉及 **加载客户程序** 和 **初始化CPU** ，确保CPU可以正确执行指令。  
init_isa() 的两个主要任务：
1. 加载内置客户程序：img数组存储了一组 RISC-V 指令，作为一个简单的客户程序。 通过 guest_to_host(RESET_VECTOR)计算出RESET_VECTOR在NEMU内存中的实际地址，并将img复制到该位置。这样，客户程序就被加载到RESET_VECTOR处。
2. 初始化CPU：restart()负责初始化 CPU 的状态。(1) cpu.pc = RESET_VECTOR;设置pc为RESET_VECTOR，确保 CPU 从这个位置开始执行代码。 (2) cpu.gpr[0] = 0;初始化零寄存器，确保它的值始终为0。

## 运行第一个客户程序
Monitor的初始化工作结束后, main()函数会继续调用engine_start()函数 (在nemu/src/engine/interpreter/init.c中定义). 代码会进入简易调试器(Simple Debugger)的主循环sdb_mainloop() (在nemu/src/monitor/sdb/sdb.c中定义), 并输出NEMU的命令提示符:  
```
(nemu)
```  

简易调试器是monitor的核心功能, 我们可以在命令提示符中输入命令, 对客户计算机的运行状态进行监控和调试. 框架代码已经实现了几个简单的命令, 它们的功能和GDB是很类似的.

在命令提示符后键入c后, NEMU开始进入指令执行的主循环cpu_exec() (在nemu/src/cpu/cpu-exec.c中定义). cpu_exec()又会调用execute(), 后者模拟了CPU的工作方式: **不断执行指令** . 具体地, 代码将在一个for循环中不断调用exec_once()函数, 这个函数的功能就是我们在上一小节中介绍的内容: 让CPU执行当前PC指向的一条指令, 然后更新PC.
execute()函数 和 exec_once()函数：  
```
/* 执行n条指令 | 模拟了CPU的工作方式: 不断执行指令 */
static void execute(uint64_t n) {
  Decode s;                                       //定义解码结构体，用于存储指令信息
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);                        //执行单跳指令
    g_nr_guest_inst ++;                           //增加已执行指令的计数
    trace_and_difftest(&s, cpu.pc);               //进行指令追踪和DiffTest
    if (nemu_state.state != NEMU_RUNNING) break;  //如果CPU状态不是运行中，则退出循环
    IFDEF(CONFIG_DEVICE, device_update());        //如果启用了设备仿真，则更新设备状态
  }
}
```  

CPU 执行指令的核心流程： 取指； 译码与执行； 更新 PC。我们深入exec_once()函数（部分，在这里删除了指令追踪Instruction Tracing，而专注查看cpu的工作流程）：  
```
/* 执行单条指令 | 让CPU执行当前PC指向的一条指令, 然后更新PC.*/
static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;         //设置当前指令的PC
  s->snpc = pc;       //设置下一条指令的PC
  isa_exec_once(s);   //解析并执行该指令
  cpu.pc = s->dnpc;   //更新CPU的PC（下一条指令地址）
}
```  
***  
isa_exec_once(s)函数，位于src/isa/riscv32/inst.c。 这里主要是实现了一个简单的 RISC-V 指令解码与执行流程，包括指令的解码、操作数的提取、指令类型的匹配执行，并执行每条指令，模拟CPU执行过程。根据讲义，并没有继续深入了，后面pa2会说明：  
```
// 解码并执行指令函数
static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;  // 设置下一条指令的PC

// 定义指令匹配宏
#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  int rd = 0; \
  word_t src1 = 0, src2 = 0, imm = 0; \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}
  // 开始指令匹配
  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));

  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) 是 $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // 重置$zero寄存器为0

  return 0;
}

// 执行一条指令的函数
int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);  // 获取下一条指令
  return decode_exec(s);                  // 解码并执行指令
}
```  
***  

由于刚才我们运行NEMU的时候并未给出客户程序的镜像文件, 此时NEMU将会运行上文提到的内置客户程序. NEMU将不断执行指令, 直到遇到以下情况之一, 才会退出指令执行的循环:  
* 达到要求的循环次数.
* 客户程序执行了nemu_trap指令. 这是一条虚构的特殊指令, 它是为了在NEMU中让客户程序指示执行的结束而加入的, NEMU在ISA手册中选择了一些用于调试的指令, 并将nemu_trap的特殊含义赋予它们. 例如在riscv32的手册中, NEMU选择了ebreak指令来充当nemu_trap. 为了表示客户程序是否成功结束, nemu_trap指令还会接收一个表示结束状态的参数. 当客户程序执行了这条指令之后, NEMU将会根据这个结束状态参数来设置NEMU的结束状态, 并根据不同的状态输出不同的结束信息, 主要包括
  * HIT GOOD TRAP - 客户程序正确地结束执行
  * HIT BAD TRAP - 客户程序错误地结束执行
  * ABORT - 客户程序意外终止, 并未结束执行
当你看到NEMU输出类似以下的内容时(不同ISA的pc输出值会有所不同):  
```nemu: HIT GOOD TRAP at pc = 0x8000000c```  
说明客户程序已经成功地结束运行. NEMU会在cpu_exec()函数的最后打印执行的指令数目和花费的时间, 并计算出指令执行的频率. 但由于内置客户程序太小, 执行很快就结束了, 目前无法计算出有意义的频率, 将来运行一些复杂的程序时, 此处输出的频率可以用于粗略地衡量NEMU的性能.  

退出cpu_exec()之后, NEMU将返回到sdb_mainloop(), 等待用户输入命令. 但为了再次运行程序, 你需要键入q退出NEMU, 然后重新运行.

内存通过在nemu/src/memory/paddr.c中定义的大数组pmem来模拟. 在客户程序运行的过程中, 总是使用vaddr_read()和vaddr_write() (在nemu/src/memory/vaddr.c中定义)来访问模拟的内存. vaddr, paddr分别代表虚拟地址和物理地址. 这些概念在将来才会用到, 目前不必深究, 但从现在开始保持接口的一致性可以在将来避免一些不必要的麻烦.

## 重做优雅地退出
之前已经实现过了，这一次主要还是做一个简单的梳理，重新分析问题的同时，也把整个运行过程中所遇到的函数进行分析学习。  

先从主函数开始：
* 在main()函数的开始，首先会调用init_monitor()函数来进行一些和monitor相关的初始化工作。
* 在初始化工作结束后，main()函数继续调用engine_start()函数,
* 这时候就会进入简易调试器（SDB）的主循环sdb_mainloop()，此时我们到了nemu/src/monitor/sdb/sdb.c中。
* sdb_mainloop()函数下有一个for主循环，通过rl_gets()函数来读取用户的输入，
* 这时候我输入:q 。那么此时str为'q',cmd也只有'q'，
* 然后进入遍历命令列表，根据strcmp()字符串比较函数来匹配cmd_table[i].name，如果q等于q， 那么strcmp()返回0表示匹配成功，
* 结构体的int (*handler) (char *) 函数指针就会指向cmd_table[i].handler(args) 函数，也就是cmd_q函数，执行完这个函数后return -1
* 结果是 < 0， 返回了return，主循环for (char *str; (str = rl_gets()) != NULL; )结束，
* 然后sdb_mainloop()函数的执行结束，
* 然后engine_start()函数的执行结束，
* 最后返回到main()函数，到return is_exit_status_bad();


梳理完整个运行过程，正常来说，main()函数的正常退出是return 0.讲义希望我们正常退出，那么就说明is_exit_status_bad()函数需要返回0.我们进入is_exit_status_bad()函数，可以看到这里的返回值是return !good;而good又是有一个判断。这里和NEMU全局状态有关系。想要改正错误，就需要在前面的运行过程中，重新设置NEMU的状态nemu_state.state。所以，就可以确定问题出现在cmd_q函数少了一部分逻辑：nemu_state.state = NEMU_QUIT；


## 就是这么简单
事实上, TRM的实现已经都蕴含在上述的介绍中了。
* 存储器是个在nemu/src/memory/paddr.c中定义的大数组
* PC和通用寄存器都在nemu/src/isa/$ISA/include/isa-def.h中的结构体中定义
* 加法器在... 嗯, 这部分框架代码有点复杂, 不过它并不影响我们对TRM的理解, 我们还是在PA2里面再介绍它吧
* TRM的工作方式通过cpu_exec()和exec_once()体现

在NEMU中, 我们只需要一些很基础的C语言知识就可以理解最简单的计算机的工作方式, 真应该感谢先驱啊.

## 基础设施: 简易调试器
### 解析命令
这一次详细一点。  

进入主循环后。首先，来看rl_gets()函数，首先释放上一次分配的内存，防止内存泄漏；然后通过readline()读取用户输入。接着检查用户是否非空，将非空字符串添加到历史记录中。最后返回输入的字符串。  
这里用到了 **readline()函数：**  
* 函数原型： char *strtok(char *str, const char *delimiters);
* 参数解释： *prompt：提示字符串，显示在输入行之前（例如 readline("(nemu) ")则会显示：(nemu) ）。
* 返回值：   返回用户输入的一行字符串（以 \0 结尾）。需要调用者手动释放内存（使用 free()）。
* 常用功能： 最常用的功能就是通过上, 下方向键翻阅历史记录。行编辑，支持光标移动、删除字符、插入字符等编辑操作。提供类似文本编辑器的体验。

接下来的步骤是，*str_end是计算字符串结束的位置，这是后续检查args是否超过str的范围。然后，使用strtok()函数，将str按空格分割，并返回下一个非空的token，如果没有更多标记，则返回 NULL。如果cmd为空则跳过本次循环。接着，跳过命令名和紧随其后的空格， *args指向参数的起始位置。  
这里做一个演示,加入我输入了info r：  
```
str = "info r"
cmd = "info"   （指向 "info" 的 'i'）
strlen(cmd) = 4
cmd + strlen(cmd) = 指向 'o' 之后的位置（即空格）
cmd + strlen(cmd) + 1 = 指向 'r'
args = "r"
```  

在将字符串解析成cmd和args后，这时候就会遍历命令列表，使用strcmp()是字符串比较函数，查找匹配命令。匹配成功后，结构体中的函数指针就会指向相应的函数执行函数。

### 单步执行
单步执行的功能十分简单, 而且框架代码中已经给出了模拟CPU执行方式的函数, 你只要使用相应的参数去调用它就可以了。在cmd_c()函数中调用了cpu_exec(-1);（-1表示一个很大的数，程序会执行到结束。），cpu_exec(n)函数是让CPU执行指定数量的指令。所以想要单步执行，那么就是n设置为1。在GDB中点s，也是单步执行，因此我需要在cmd_si中默认执行1条指令。如果用户输入了其他参数，则使用sscanf()函数对args进行解析，确保参数是一个整数.  

讲义中提到：NEMU默认会把单步执行的指令打印出来(这里面埋了一些坑, 你需要RTFSC看看指令是在哪里被打印的)。我们输入si，跟着nemu程序来找找看。  
* 进入cmd_si()函数后，经过判断后这里调用cpu_exec(n)，默认执行1条执行
* 进入cpu_exec(1)函数后，会调用execute(1)，执行1条指令。
* 在execute(1)中,n被赋值为1,所以这里循环遍历为1次，执行完单条指令后pc值更新，并且增加已执行指令的计数，而后到了trace_and_difftest(&s, cpu.pc);函数。
* 在trace_and_difftest(&s, cpu.pc);函数,我们会看到这里有一些宏定义：CONFIG_ITRACE_COND 配置_指令_追踪。上面一条```if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }``` 是启用指令追踪，记录日志。 ```if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }``` 需要打印指令，则输出。似乎讲义所说的“指令是在哪里被打印”，就是在这里被打印了。

这里还有一个需要注意的点就是 ```g_print_step ```。在结构体中这里是```static bool g_print_step = false;```默认为关。在cpu_exec()函数的开始，我们就能够看到```g_print_step = (n < MAX_INST_TO_PRINT);``` 这里就有判断了，而```MAX_INST_TO_PRINT``` 我们在最上面设置了10. 因此n为1,小于10.所以启用单步打印。```CONFIG_ITRACE``` 我们在配置文件中可以看到是1,被启用了。

**sscanf()函数的介绍：**  
* 函数原型： int sscanf(const char *str, const char *format, ...);
* 参数解释： *str:源字符串，从中提取。 *format：格式化字符串，指定如何解析str中的数据。 *...:可变参数，用于存储提取的数据。通常是变量的地址。
* 返回值 ：  成功时，返回成功匹配并赋值的 **输入项的数量** ； 如果输入失败或到达字符串末尾，则返回 EOF，通常是-1。
* 常用功能： 从字符串中按照指定格式提取数据。

### 打印寄存器
框架代码中已经提供了API，只需要执行info r之后, 就调用isa_reg_display(), 在里面直接通过printf()输出所有寄存器的值即可。  

### 扫描内存
这里是先简化了，先实现一个简单的版本: 规定表达式EXPR中只能是一个十六进制数, 例如：  
```
x 10 0x80000000
```  
解析出待扫描内存的起始地址之后, 就可以使用循环将指定长度的内存数据通过十六进制打印出来。  
如何访问内存，之前讲义中也有提到：  
*  物理内存的起始地址 ： riscv32, 其CONFIG_MBASE将会被定义成0x80000000. 将来CPU访问内存时, 我们会将CPU将要访问的内存地址映射到pmem中的相应偏移位置, 这是通过nemu/src/memory/paddr.c中的guest_to_host()函数实现的。
*  **在运行第一个客户程序中** 提到：内存通过在nemu/src/memory/paddr.c中定义的大数组pmem来模拟. 在客户程序运行的过程中, 总是使用vaddr_read()和vaddr_write() (在nemu/src/memory/vaddr.c中定义)来访问模拟的内存. vaddr, paddr分别代表虚拟地址和物理地址. 这些概念在将来才会用到, 目前不必深究, 但从现在开始保持接口的一致性可以在将来避免一些不必要的麻烦.
  
根据讲义，我们可以分析接下来需要做什么，10表示需要扫描多少个内存单元，0x80000000表示需要扫描的起始地址。访问内存也是使用vaddr_read()函数，因为这里是使用RISC-V 32位架构，一个指令通常是4字节，所以思路就很明确了，从起始地址开始，每4个字节读取一次：``` word_t data = vaddr_read(start_addr + i * 4, 4);//计算当前扫描的内存地址，i是扫描次数，每次扫描4字节``` 

## 表达式求值
### 算术表达式的词法分析
首先了解一下 **正则表达式** 。在c语言中，反斜杆\ 本身是转义字符，因此想要在字符串中使用\，必须要用 \ \  进行转义，\ \ * 代表 \ *  , 而\ * 实际上是 * 。一句话总结，\ \的目的是为了把\ 给转义了。

所以：
`\(`：在正则表达式中，`\(` 表示匹配一个实际的左括号 `(`。在 C 语言字符串中，`\` 需要转义，所以写成 `"\\("`。

`\)`：在正则表达式中，`\)` 表示匹配一个实际的右括号 `)`。在 C 语言字符串中，`\` 需要转义，所以写成 `"\\)"`。

`\*`：在正则表达式中，`\*` 表示匹配一个实际的星号 `*`。在 C 语言字符串中，`\` 需要转义，所以写成 `"\\*"`。

`\+`：在正则表达式中，`\+` 表示匹配一个实际的加号 `+`。在 C 语言字符串中，`\` 需要转义，所以写成 `"\\+"`。

`\$`：在正则表达式中，`\$` 表示匹配一个实际的美元符号 `$`。在 C 语言字符串中，`\` 需要转义，所以写成 `"\\$"`。

man 了一手regexec():  
**函数原型：** ```int regexec(const regex_t *preg, const char *string, size_t nmatch,regmatch_t pmatch[], int eflags);```  
**参数解析：**  
* **const regex_t *preg:** 这是一个指向预编译的正则表达式模式缓冲区的指针。
* **const char *string:**  这是一个指向以 null 结尾的字符串的指针，该字符串将与 preg 中存储的正则表达式进行匹配。
* **size_t nmatch:** 这是 pmatch 数组的大小，表示 regexec() 可以填充的匹配位置数量。如果在 regexec() 执行过程中匹配到多个子表达式，nmatch 就决定了 pmatch 数组可以容纳多少个匹配位置。
* **regmatch_t pmatch[]:** 这是一个数组，regexec() 会在其中填充匹配信息。每个 regmatch_t 结构表示一个子表达式的匹配位置，它包含两个字段：1. rm_so：子表达式匹配开始的位置（偏移量）。 2. rm_eo：子表达式匹配结束的位置（偏移量），即匹配文本后第一个字符的位置。  
* **pmatch[0]** 存储整个正则表达式匹配的位置，pmatch[i] 存储第 i 个子表达式的匹配位置。
* **int eflags:** 这是一个执行标志，用于控制匹配行为。它是多个标志按位或（bitwise-OR）的结果，常见的标志包括：1. REG_NOTBOL：行首匹配操作符（^）总是失败匹配，表示字符串的开头不应该当作行的开始。 2.REG_NOTEOL：行尾匹配操作符（$）总是失败匹配，表示字符串的结尾不应该当作行的结束。  
**返回值：**regexec() 成功匹配时返回零，失败时返回 REG_NOMATCH。

阅读了讲义后，我们得知，token类型的规则会在简易调试器初始化的时候通过init_regex()被编译成一些用于进行pattern匹配的内部信息, 这些内部信息是被库函数使用的, 而且它们会被反复使用, 但你不必关心它们如何组织. 但如果正则表达式的编译不通过, NEMU将会触发assertion fail, 此时你需要检查编写的规则是否符合正则表达式的语法。暂时先不用考虑init_regex()，那么在expr.c文件中的内容就有：  
1. 表示不同token的，枚举类型enum。
2. 定义正则表达是规则的rule。（这里是我们需要添加规则的）
3. 一个用于存储编译后的正则表达式 ```static regex_t re[NR_REGEX] = {};```
4. 一个token结构体，type表示token的类型（整数）， str用来存储token的字符串值。
5. tokens 是用于存储解析出来的 token； nr_token 记录当前解析出的 token 数量。
6. make_token 词法分析函数。工作方式：position变量来指示当前处理到的位置, 并且按顺序尝试用不同的规则来匹配当前位置的字符串. 当一条规则匹配成功, 并且匹配出的子串正好是position所在位置的时候, 我们就成功地识别出一个token, Log()宏会输出识别成功的信息。**需要做的是**将识别出的token信息记录下来(一个例外是空格串), 我们使用Token结构体来记录token的信息。
7. 最后，expr()函数，计算表达式的值。

那么现在我们整理一下思路，实现词法分析的步骤。
* 在make_token()函数中，定义了position指示当前处理到的位置，i是循环次数标记，pmatch存储regexec()函数的匹配结果。
* 到了while这里，```e[position] != '\0'``` 是C语言中的一种表示方式，通常表示访问字符数组 e 中索引为 position 的元素。按顺序尝试用不同的规则来匹配当前位置的字符串。
* 到了if这里，regexec()函数 返回 0 表示匹配成功。然后Log()宏会输出识别成功的信息。```position += substr_len```会移动解析位置。
* 到了switch，根据rules[i].token_type进行匹配。将匹配到的子串处理成对应的 token 类型并将其存入 tokens 数组。
  * 匹配到数字则将type设置为TK_NUM，并将substr_start复制到tokens[nr_token].str 中。
  * 匹配到运算符则直接记录type： tokens[nr_token].type = rules[i].token_type;

### 实现算术表达式求值
这里并没有根据讲义使用递归实现。  

1. 使用priority() 函数来定义各个运算符的优先级，数字越大优先级越高。然后，使用compute() 函数来执行具体的运算逻辑。
2. 先进行词法分析处理，将输入字符串转换为Token数组。我们建立了两个栈：运算符栈和操作数栈。
3. for循环遍历token数组，使用```Token t = tokens[i];``` 来获取当前的token。
4. 根据t.type 来处理
   * 如果当前的t.type为TK_NUM（数字），使用sscanf()将t.str的内容格式化为整数并压入操作数栈： ```sscanf(t.str, "%d", &num_stack[++num_top]);```
   * 如果当前的t.type为TK_LPAREN（左括号），则直接将左括号压入运算符栈 ```op_stack[++op_top] = t.type;```
   * 如果当前的t.type为TK_RPAREN（右括号），则弹出并计算，直到左括号。
     * 如果 运算符栈 弹出 一元运算符，则从 操作数栈中 弹出 操作数a 计算后，将 结果压入操作数栈。
     * 如果 运算符栈 弹出 二元运算符，则从 操作数栈中 弹出 操作数a 和操作数b，使用compute(a, 0, op)计算后 ，将 结果压入操作数栈。
     * 最后从运算符栈中弹出左括号。
   * 然后，当我们当前遇到一个运算符，需要根据运算符的优先级来处理计算```while (op_top >= 0 && priority(op_stack[op_top]) >= priority(t.type))```，如果栈顶运算符的优先级大于或等于当前运算符的优先级，则需要先计算栈顶的运算符。
     * 如果 运算符栈 弹出 一元运算符，则从 操作数栈中 弹出 操作数a 计算后，将 结果压入操作数栈。
     * 如果 运算符栈 弹出 二元运算符，则从 操作数栈中 弹出 操作数a 和操作数b，使用compute(a, 0, op)计算后 ，将 结果压入操作数栈。
     * 最后将当前运算符压入运算符栈。
5. 遍历完token数组后，当前token中没有运算符了，我们现在处理栈内剩余的运算符。
   * 如果 运算符栈 弹出 一元运算符，则从 操作数栈中 弹出 操作数a 计算后，将 结果压入操作数栈。
   * 如果 运算符栈 弹出 二元运算符，则从 操作数栈中 弹出 操作数a 和操作数b，使用compute(a, 0, op)计算后 ，将 结果压入操作数栈。
6. 直到栈中只有一个最终结果，把success设置为true，并返回计算结果。 

## 表达式生成器的前置细节问题（算思考题）
1. **如何保证表达式进行无符号运算?**  
在gen_num()生成的数组是uint32_t类型。同时在sprintf(num_str, "%u", num); 确保它是无符号格式。由于操作数都是无符号整数，锁于整个表达式的计算也是无符号运算。

2. **如何随机插入空格？**  
定义一个函数来生成空格，然后在数字gen_num()随机生成的时候调用这个生成空格函数，一起写入，实现插入空格。  

3. **如何生成长表达式, 同时不会使buf溢出?**  
在生成表达式时检查buf的剩余空间。如果剩余空间足够则继续追加。在 gen_rand_expr()的开始也先检查一次buf。    
**strcat :** char *strcat(char *dest, const char *src);`strcat()` 函数将 `src` 字符串附加到 `dest` 字符串的末尾，覆盖 `dest` 末尾的终止空字符（`\0`），然后添加一个新的终止空字符。两个字符串不能重叠，且 `dest` 字符串必须有足够的空间来存放结果。如果 `dest` 空间不足，程序行为不可预测；缓冲区溢出是攻击安全程序的常见途径。

4. **如何过滤求值过程中有除0行为的表达式？**
我对于生成过程想到以下方法：1.避免生成数字0； 2.如果选择到了除法，除号确保除数不为0,如果为0重新生成一个非0数字。 

## 除0的确切行为
如果生成的表达式有除0行为, 你编写的表达式生成器的行为又会怎么样呢?

1. 如果生成的表达式中确实有除0行为，编译器会报错或程序崩溃，异常，因为除0是一个未定义的行为。如果真的存在除0行为，可以在main函数中，检查表达式是否有/0行为，如果有就重新生成一个(使用strstr()函数查找‘/0’，找不到返回NULL)。
2. system编译生成代码，如果生成的代码包含除零行为，编译会成功，但执行时会失败。  
在 popen执行时，如果发生除零错误，popen 会返回一个非零的错误码，程序会跳过本次循环并继续生成下一个表达式。

## 实现监视点池的管理
简易调试器允许用户同时设置多个监视点, 删除监视点, 因此我们最好使用链表将监视点的信息组织起来。同时框架代码也给我们定义好了结构体。我们后续需要添加必要成员。（现在先看池的实现）  

同时，也使用“池”的数据结构来管理监视点结构体。框架代码中也定义了监视点结构的池wp_pool，还有两个链表head和free_，其中head用于组织使用中的监视点结构, free_用于组织空闲的监视点结构, init_wp_pool()函数会对两个链表进行初始化.  

其中new_wp()从free_链表中返回一个空闲的监视点结构, free_wp()将wp归还到free_链表中, 这两个函数会作为监视点池的接口被其它函数调用. 需要注意的是, 调用new_wp()时可能会出现没有空闲监视点结构的情况, 为了简单起见, 此时可以通过assert(0)马上终止程序。  
在这里补充一下链表的一点小用法：  
```
// 将节点 p 插入到链表的头部，实现头插法。
void insert(link p)
{
  if (!list2 || !list2->head) return; // 如果链表2为空，直接返回
    
  link p = list2->head;               // 获取链表2的头节点
  list2->head = p->next;              // 更新链表2的头指针，去掉 p

	p->next = head;                     // 让 p 的 next 指向当前链表的头节点
	head = p;                           // 更新头节点为 p
}

// 从单链表中删除指定节点 p
void delete(link p)
{
    if (!p || !head) return;                // 处理空指针情况
    link pre;
    if (p == head) {                        // 如果要删除的是头节点
        head = p->next;                     // 直接将 head 指向下一个节点
        return;
    }
    for (pre = head; pre; pre = pre->next)  // 遍历链表寻找 p 的前驱节点
        if (pre->next == p) {               // 找到了 p 的前驱节点
            pre->next = p->next;            // 让前驱的 next 跳过 p
            return;
        }
}
```  

根据上面提到的链表操作，来实现WP* new_wp();和void free_wp(WP *wp);的操作。

## 思考题：为什么要使用static？
static的作用主要是先定作用域，将变量只能在当前源文件下访问。防止外部的操作导致影响这里的实现。确保监视点状态在整个生命周期内有效，不被销毁或重复初始化。  

## 实现监视点
通过讲义描述，我们需要实现以下功能：  
1. 当用户给出一个待监视表达式时，需要通过new_wp()申请一个空闲的监视点结构, 并将表达式记录下来。
2. 在trace_and_difftest()函数(在nemu/src/cpu/cpu-exec.c中定义)的最后扫描所有的监视点。
3. 每当cpu_exec()的循环执行完一条指令, 都会调用一次trace_and_difftest()函数. 在扫描监视点的过程中, 你需要对监视点的相应表达式进行求值(你之前已经实现表达式求值的功能了),
4. 并比较它们的值有没有发生变化, 若发生了变化, 程序就因触发了监视点而暂停下来, 你需要将nemu_state.state变量设置为NEMU_STOP来达到暂停的效果.
5. 最后输出一句话提示用户触发了监视点, 并返回到sdb_mainloop()循环中等待用户的命令.

根据需求，我们需要在原来的监视点结构体上扩展一些成员来满足我们的需求。expr用于存储监视的表达式，value用于存储监视的值。

**添加监视点命令：**
我们需要在sdb.c文件中添加相关命令。
1. 首先检查是否输出表达式。
2. 然后调用expr()函数计算当前表达式的值。
3. 如果计算成功，通过new_wp()函数申请一个新的监视点
4. 将表达式的字符串复制给wp的expr```wp->expr = strdup(args);```
5. 输出监视点信息

**检查监视点：**  
讲义所提供的步骤也很明确了，就是cpu_exec()的循环执行完一条指令，就调用一次trace_and_difftest()函数，在扫描监视点的过程中对监视点相应表达式进行求值，然后进行对比。因此我们需要在这里添加一个函数用于检查监视点的变化。由于监视点池都使用了static关键字，所以检查监视点的函数就在watchpoint.c文件中定义。  
**check_wp()函数 | 检查监视点**
这个函数需要做什么呢？根据讲义描述，对所有监视点遍历，并计算，将结果与所记录的结果进行对比，如果有变化则输出新旧值，然后暂停NEMU运行。  
1. 首先遍历所有使用中的监视点，用current来指向head```WP *current = head;```，current用于访问使用中的监视点。使用while关键字遍历：``` while (current != NULL)```。（如果没有current，直接使用head，就只会检查第一个监视点，而不会检查后续的监视点。）
2. 进入遍历循环中，需要先检查表达式指针是否为空。如果当前监视点没有存储有效的表达式，这可能导致访问到空指针，将null传递给expr()函数。后续也在expr中检查了null的情况。
3. 调用expr()函数计算当前值。```word_t new_val = expr(current->expr, &success);```
4. 如果不成功，则提示表达式求值错误。
5. 成功后则将计算的值与之前进行对比，如果发生变化，则输出：
   * 输出当前监视点编号，以及监视的表达式
   * 输出旧值
   * 输出新值
   * 最后将监视点中存储值 更新为变化后的新值
6. 移动到下一个监视点。
7. 如果有任何监视点触发或表达式求值出错，暂停NEMU运行。```if (error_occurred || triggered) { nemu_state.state = NEMU_STOP; }``` 。


**删除监视点命令：**
1. 首先检查是否输入正确格式。
2. 解析监视点的编号。
3. 通过get_head()函数来访问使用中监视点链表。
4. 遍历链表找到指定编号后，调用free_wp()函数删除监视点
5. 输出信息


