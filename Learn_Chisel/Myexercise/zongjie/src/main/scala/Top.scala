/*
1.chisel的基础（scala语言，硬件描述）

2.chisel的核心概念（模块，IO端口，数据类型，连线wire，寄存器reg，组合逻辑，时序逻辑）

3.chisel的基本数据类型
Bool（）：true个false
UInt
SInt
ChiselEnum。枚举类型，定义有限状态机集合中的值。
Clock（）
Reset
Bundle
Vec

4.chisel的硬件资源
Reg：寄存器类型
Wire：线网类型
Mem：存储器类型
IO：用于定义输入输出端口。val io = IO(new Bundle{})


5.chisel的输入输出类型
    Input,Output

6.chisel的控制语句
when：条件语句，类似于if。
elsewhen：when的扩展，用于条件不成立时。
otherwise：处理其他情况。
switch：多条件选择，用于实现分支选择。
is

7.chisel如何创建线网、实例等
val x = Wire(UInt())
:=


8.构造状态元素、寄存器
    Reg(UInt())：创建一个UInit的寄存器
    RegInit(7.U(32.W))：初始化寄存器，初始值为7,宽度为32
    RegNext(nextValue)：寄存器在上升沿更新，且没有初始值
    RegNext(nextValue,3.U(32.W))：寄存器在上升沿更新，初始值为3,宽度为32
    RegEnable(next,enable)：寄存器在上升沿更新，具有使能门
    RegEnable(next, init,enable)：寄存器在上升沿更新，有初始值，也有使能门

9.状态机的状态枚举
object State extends ChiselEnum {
    val in1, in2
}
import State._


*/

//多路选择器Mux
import chisel3._    //导入chisel基本库
import chisel3.util._

class Mux4to1 extends Module {
    val io = IO(new Bundle {
        val in0 = Input(UInt(8.W))
        val in1 = Input(UInt(8.W))
        val in2 = Input(UInt(8.W))
        val in3 = Input(UInt(8.W))
        val sel = Input(UInt(2.W))
        val out = Output(UInt(8.W))
    })

    io.out := MuxCase(io.sel, 0.U, Seq(
        0.U -> io.in0,
        1.U -> io.in1,
        2.U -> io.in2,
        3.U -> io.in3
    ))
}

//译码器
class Decoder2to4 extends Module {
    val io = IO(new Bundle {
        val in = Input(UInt(2.W)) 
        val out = Output(UInt(4.W))
    })

    io.out = 0.U
    switch(io.in) {
        is(0.U) { io.out := "b0001".U } // 输入 00 -> 输出 0001
        is(1.U) { io.out := "b0010".U } // 输入 01 -> 输出 0010
        is(2.U) { io.out := "b0100".U } // 输入 10 -> 输出 0100
        is(3.U) { io.out := "b1000".U } // 输入 11 -> 输出 1000
    }
}

//编码器
class Encoder4to2 extends Module {
    val io = IO(new Bundle {
        val in = Input(UInt(4.W))
        val out = Output(UInt(2.W))
    })

    io.out := MuxCase(0.U, Seq(
        (io.in === "b0001".U) -> 0.U,
        (io.in === "b0010".U) -> 1.U,
        (io.in === "b0100".U) -> 2.U,
        (io.in === "b1000".U) -> 3.U
    ))
}

//加法器
class Adder extends Module {
    val io = IO(new Bundle {
        val a = Input(UInt(8.W))
        val b = Input(UInt(8.W))
        val sum = Output(UInt(8.W))
    })
    io.sum := io.a + io.b
}

//比较器
class Comparator extends Module {
    val io = IO(new Bundle {
        val a = Input(UInt(8.W))
        val b = Input(UInt(8.W))
        val eq = Output(Bool())
        val gt = Output(Bool())
        val lt = Output(Bool())
    })
    io.eq := io.a === io.b
    io.gt := io.a > io.b
    io.lt := io.a < io.b
}