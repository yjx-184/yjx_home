

1.chisel基础
    *scala语言：chisel是基于scala，因此熟悉scala的基本语法和特性是前提。
    *硬件描述：chisel用于描述硬件电路，支持模块化设计。

2.chisel核心概念
    *模块module：chisel的基本构建块，类似于verilog的模块。每个模块可以包含输入输出和内部逻辑。
    *IO端口：适用IO类定义模块的输入输出端口。
    *数据类型：chisel提供多种硬件数据类型，如UInt无符号整数，SInt有符号整数，Bool布尔类型等。
    *连线wire：用于在模块内部连接信号的临时变量。
    *寄存器Reg：用于定义时序逻辑中的寄存器。
    *组合逻辑：使用scala的表达式和操作符描述组合逻辑。
    *时序逻辑：使用Reg和when等结构描述时序逻辑。

3.chisel操作符
    *位操作：与&，或|，非~，异或^
    *算术操作：+,-,*,/,%
    *比较操作：===,=/=,>,<,>=,<=
    *移位操作：<<,>>

4.chisel控制结构
    *when/elsewhen/otherwise:用于条件逻辑的描述。
    *switch/is：用于多路选择逻辑的描述。
    *for循环：用于生成重复的硬件结构。

5.chisel高级特性
    *参数化设计：通过scala的参数化特性，可以设计可配置的硬件模块。
    *BUndle：用于定义复杂的数据结构，类似于c语言的结构体。
    *Vec：用于定义向量或数组。
    *Mem：用于定义存储器，支持同步和异步存储器。

6.chisel测试
    *ChiselTest：chisel提供了测试框架，用于编写和运行硬件测试。
    *PeekPokeTester：用于在仿真中驱动输入信号并检查输出信号。


基本语法：  
1.模块定义
```
import chisel3._    //导入chisel基本库

class MyModule extends Module {
    val io = IO(new Bundle {
        val in = Input(UInt(8.W))
        val out = Output(UInt(8.W))
    })
    io.out := io.in
}
```  

2.组合逻辑：  
```
//基本运算
val a = Wire(UInt(8.W))
val b = Wire(UInt(8.W))
val c = a + b   // 加法
val d = a & b   // 按位与
val e = a === b // 等于比较
```  

多路选择器Mux：  
```
import chisel3.util._
val sel = Wire(Bool())
val result = Mux(sel, a, b) //sel为true返回a
```  

3.时序逻辑：  
寄存器Reg：  
```
val reg = RegInit(0.U(8.W)) //初始化寄存器
reg := reg + 1.U
```  

移位寄存器  
```
val shiftReg = RegNext(io.in, 0.U)  //时钟上升沿后，输入值存入寄存器
```  
4.控制结构：  
```
//when-else
when(io.in === 0.U) {
  io.out := 10.U
}.elsewhen(io.in === 1.U) {
  io.out := 20.U
}.otherwise {
  io.out := 30.U
}

//switch-case
switch(io.in) {
  is(0.U) { io.out := 10.U }
  is(1.U) { io.out := 20.U }
  default { io.out := 30.U }
}

```  

5.参数化设计
```
//参数化模块,通过n: Int 参数化数据宽度。
class Adder(n: Int) extends Module {
  val io = IO(new Bundle {
    val a = Input(UInt(n.W))
    val b = Input(UInt(n.W))
    val sum = Output(UInt(n.W))
  })
  io.sum := io.a + io.b
}
```  

生成多个实例
```
val adder8  = Module(new Adder(8))
val adder16 = Module(new Adder(16))
```  

6.有限状态机  
```
//状态
  object State extends ChiselEnum {
    val MainGreen, MainOrange, AllRed, MinorGreen, MinorOrange = Value
  }
  import State._
  val stateReg = RegInit(MainGreen) //状态寄存器，初始为主干道绿灯

  switch() {
    is() {}
    is() {}
  }
```  

7.测试  
```
import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class MyModuleTester extends AnyFlatSpec with ChiselScalatestTester {
  "MyModule" should "pass" in {

//在test(new MyModule)后加.withAnnotations(Seq(WriteVcdAnnotation))可生成波形文件。
    test(new MyModule) { dut =>
      dut.io.in.poke(3.U)
      dut.clock.step(1)
      dut.io.out.expect(3.U)
    }
  }
}
```  

8.生成verilog:  
```
object Top extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Top())
}

```  

教材所展示的结构有：  
1.多路复用器Mux  
2.译码器  
3.编码器  
4.寄存器  
5.计数器  
6.移位寄存器  
7.状态机





