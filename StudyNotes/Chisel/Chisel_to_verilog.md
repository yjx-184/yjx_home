- [chisel工具流](#chisel工具流)
- [简单的LED闪烁控制](#简单的led闪烁控制)
  - [chisel部分](#chisel部分)
  - [生成的verilog文件](#生成的verilog文件)
- [七段显示器驱动实验](#七段显示器驱动实验)
  - [Chisel](#chisel)
  - [生成的Verilog代码](#生成的verilog代码)

# chisel工具流
![](./pic/chisel工具流程.png) 

首先，有了Chisel源码后，Scala的编译器基于Chisel、Scala的库将我们的代码生成Java类文件*.class，也就是字节码文件。这类文件可以在标准的JVM（java虚拟机）上直接执行。  

其次，用Chisel驱动执行这个字节码文件会生成FIRRTL文件*.fir。这个FIRRTL全称：Flexible Intermediate Representation for RTL，即RTL的可变中间表示，是数字电路的中间表示。FIRRTL编译器可以在点路上执行一些转换，是Chisel到其他硬件描述语言的关键桥梁，如果想理解更高阶的Chisel的内容甚至为Chisel开源代码做贡献，那就需要深入学习FIRRTL了。

接着，readle是一个FIRRTL的解释器，用于电路的仿真。配合Chisel测试器，它可以用于调试和测试Chisel电路。根据输出的断言信息我们可以得到测试的结果。Treadle还可以生成波形文件，即*.vcd。

最后，回到FIRRTL编译器部分，Verilog Emitter也是FIRRTL变换之一，可以用*.fir生成可综合的Verilog代码*.v。

# 简单的LED闪烁控制
目的是实现一个简单的LED闪烁控制模块。
## chisel部分
```
import chisel3._                      //导入chisel的基本库

class Hello extends Module {          //模块定义
  val io = IO(new Bundle {   //Bundle是Chisel用来组织多个信号的容器，相当于一个信号的集合。
    val sw = Input(UInt(2.W))         //2位输入
    val led = Output(UInt(1.W))       //1位输出
  })
  //计数器的最大值
  val CNT_MAX = (50000000 / 2 - 1).U

  val cntReg = RegInit(0.U(32.W))     //计数器寄存器
  val blkReg = RegInit(0.U(1.W))      //LED状态寄存器

  //计数器和状态翻转逻辑
  cntReg := cntReg + 1.U
  when(cntReg === CNT_MAX) {
    cntReg := 0.U
    blkReg := ~blkReg
  }
  //使用sw控制LED输出
  io.led := Mux(io.sw === 0.U, 0.U,    //sw = 0,LED关闭
                Mux(io.sw === 1.U, 1.U,//sw =1,LED常量
                    blkReg
                ))    //sw = 其他值，LED闪烁
}

object Hello extends App {
  //使用ChiselStage类将Hello模块转换成Verilog代码。
  //emitVerilog会将该模块得Chisel描述生成对应得Verilog代码。
  (new chisel3.stage.ChiselStage).emitVerilog(new Hello())
}

```  
## 生成的verilog文件
```
//模块定义部分
module Hello(
  input        clock,
  input        reset,
  input  [1:0] io_sw,
  output       io_led
);

//条件编译部分
`ifdef RANDOMIZE_REG_INIT   //条件编译宏，用于在硬件仿真中初始化寄存器的随机值。
  reg [31:0] _RAND_0;       //这两个是用来存储随机数的寄存器
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT

  //寄存器定义和信号声明
  reg [31:0] cntReg; // @[Hello.scala 21:23]
  reg  blkReg; // @[Hello.scala 22:23]
  wire [31:0] _cntReg_T_1 = cntReg + 32'h1; // @[Hello.scala 25:20]
  wire  _io_led_T_2 = io_sw == 2'h1 | blkReg; // @[Hello.scala 32:20]

  //组合逻辑部分
  //assign io_led 语句定义了 io_led 输出的逻辑。它的值取决于 io_sw 和 blkReg 的状态。
  assign io_led = io_sw == 2'h0 ? 1'h0 : _io_led_T_2; // @[Hello.scala 31:16]

  //时序逻辑部分
  always @(posedge clock) begin   //描述同步逻辑，时钟上升沿触发。
    if (reset) begin // @[Hello.scala 21:23]
      cntReg <= 32'h0; // @[Hello.scala 21:23]
    end else if (cntReg == 32'h17d783f) begin // @[Hello.scala 26:28]
      cntReg <= 32'h0; // @[Hello.scala 27:12]
    end else begin
      cntReg <= _cntReg_T_1; // @[Hello.scala 25:10]
    end
    if (reset) begin // @[Hello.scala 22:23]
      blkReg <= 1'h0; // @[Hello.scala 22:23]
    end else if (cntReg == 32'h17d783f) begin // @[Hello.scala 26:28]
      blkReg <= ~blkReg; // @[Hello.scala 28:12]
    end
  end

//随机化相关宏定义
//这部分是关于随机化寄存器和存储器初始化 以及 仿真期间的一些设置。
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN     //启用时，会随机化无效的赋值。
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN     //启用时，会随机化无效的赋值操作。
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT           //启用时，会随机初始化寄存器。
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT           //启用时，会随机初始化内存。
`define RANDOMIZE
`endif
`ifndef RANDOM     //如果未定义 RANDOM，则将其定义为 $random。$random 是一个系统函数。
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT           //内存初始化相关的整数声明。
  integer initvar;
`endif
`ifndef SYNTHESIS                   //与合成相关的条件。
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif

//随机初始化部分（initial 块）
//如果启用了 RANDOMIZE_REG_INIT，则 cntReg 和 blkReg 会在仿真开始时被赋予随机值。
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  cntReg = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  blkReg = _RAND_1[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial

//条件宏和编译指令
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule

```  
# 七段显示器驱动实验
## Chisel
```
import chisel3._                      //导入chisel基础库

class Combinational extends Module {  //定义模块
  val io = IO(new Bundle {            //信号集合
    val in = Input(UInt(4.W))         //输入，4位
    val seg = Output(UInt(8.W))       //输出，8位
  })

  //默认值
  io.seg := "b1111_1111".U

  
  when(io.in === "b0000".U) { io.seg := "b0000_0011".U } // 0
    .elsewhen(io.in === "b0001".U) { io.seg := "b1001_1111".U } // 1
    .elsewhen(io.in === "b0010".U) { io.seg := "b0010_0101".U } // 2
    .elsewhen(io.in === "b0011".U) { io.seg := "b0000_1101".U } // 3
    .elsewhen(io.in === "b0100".U) { io.seg := "b1001_1001".U } // 4
    .elsewhen(io.in === "b0101".U) { io.seg := "b0100_1001".U } // 5
    .elsewhen(io.in === "b0110".U) { io.seg := "b0100_0001".U } // 6
    .elsewhen(io.in === "b0111".U) { io.seg := "b0001_1111".U } // 7
    .elsewhen(io.in === "b1000".U) { io.seg := "b0000_0001".U } // 8
    .elsewhen(io.in === "b1001".U) { io.seg := "b0000_1001".U } // 9
    .otherwise { io.seg := "b1111_1111".U } // 全灭
}


object Combinational extends App {
  //使用ChiselStage类将Hello模块转换成Verilog代码。
  //emitVerilog会将该模块得Chisel描述生成对应得Verilog代码。
  (new chisel3.stage.ChiselStage).emitVerilog(new Combinational())
}

```  
## 生成的Verilog代码
下面是根据上面的chisel源码生成的Verilog代码，在chisel源码中，使用的是 when和.elsewhen 这种条件赋值的构造，chisel编译器生成了以下的串连的三元运算符,如同真值表一样。在后面使用switch/is语句时，也是生成这种和真值表一样的串连的三元运算符的形式。  
```
module Combinational(
  input        clock,
  input        reset,
  input  [3:0] io_in,
  output [7:0] io_seg
);
  wire [7:0] _GEN_0 = io_in == 4'h9 ? 8'h9 : 8'hff; // @[Combinational.scala 22:{36,45} 23:25]
  wire [7:0] _GEN_1 = io_in == 4'h8 ? 8'h1 : _GEN_0; // @[Combinational.scala 21:{36,45}]
  wire [7:0] _GEN_2 = io_in == 4'h7 ? 8'h1f : _GEN_1; // @[Combinational.scala 20:{36,45}]
  wire [7:0] _GEN_3 = io_in == 4'h6 ? 8'h41 : _GEN_2; // @[Combinational.scala 19:{36,45}]
  wire [7:0] _GEN_4 = io_in == 4'h5 ? 8'h49 : _GEN_3; // @[Combinational.scala 18:{36,45}]
  wire [7:0] _GEN_5 = io_in == 4'h4 ? 8'h99 : _GEN_4; // @[Combinational.scala 17:{36,45}]
  wire [7:0] _GEN_6 = io_in == 4'h3 ? 8'hd : _GEN_5; // @[Combinational.scala 16:{36,45}]
  wire [7:0] _GEN_7 = io_in == 4'h2 ? 8'h25 : _GEN_6; // @[Combinational.scala 15:{36,45}]
  wire [7:0] _GEN_8 = io_in == 4'h1 ? 8'h9f : _GEN_7; // @[Combinational.scala 14:{36,45}]
  assign io_seg = io_in == 4'h0 ? 8'h3 : _GEN_8; // @[Combinational.scala 13:{29,38}]
endmodule

```  


