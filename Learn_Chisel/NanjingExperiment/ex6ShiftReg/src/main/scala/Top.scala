import chisel3._
import chisel3.util._

class Top extends Module {
  val io = IO(new Bundle {
    val clk = Input(Bool())
    val reset = Input(Bool())
    val seg_out = Output(UInt(8.W))
  })
  //实例化Shiftreg模块
  val shiftreg = Module(new Shiftreg)
  //实例化Seg模块
  val seg = Module(new Seg)

  //连接Shiftreg模块的输出到Seg模块的输入
  seg.io.in := shiftreg.io.random_out(3, 0)


  //连接时钟和复位信号
  shiftreg.io.clk := io.clk
  shiftreg.io.reset := io.reset

  //将Seg模块的输出连接到Top模块的seg_out端口
  io.seg_out := seg.io.seg
}

class Shiftreg extends Module {
  val io = IO(new Bundle {
    val clk = Input(Bool())
    val reset = Input(Bool())
    val random_out = Output(UInt(8.W))
  })

  //定义一个8位寄存器,初始化11111111（避免全零）
  val shiftreg  = RegInit(0xff.U(8.W))

  //线性反馈公式：x8 = x4 ^ x3 ^ x2 ^x0
  val lfsr = shiftreg(4) ^ shiftreg(3) ^ shiftreg(2) ^ shiftreg(0)

  //复位信号
  when(io.reset) {
    shiftreg := 0xff.U
  } .elsewhen(io.clk) {
    shiftreg := Cat(lfsr, shiftreg(7, 1))
  }

  //输出
  io.random_out := shiftreg
}

class Seg extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(8.W))
    val seg = Output(UInt(8.W))
  })

  //定义十六进制字符
  val seg0  = "b11111100".U(8.W) // 显示 0
  val seg1  = "b01100000".U(8.W) // 显示 1
  val seg2  = "b11011010".U(8.W) // 显示 2
  val seg3  = "b11110010".U(8.W) // 显示 3
  val seg4  = "b01100110".U(8.W) // 显示 4
  val seg5  = "b10110110".U(8.W) // 显示 5
  val seg6  = "b10111110".U(8.W) // 显示 6
  val seg7  = "b11100000".U(8.W) // 显示 7
  val seg8  = "b11111110".U(8.W) // 显示 8
  val seg9  = "b11110110".U(8.W) // 显示 9
  val segA  = "b11101110".U(8.W) // 显示 A
  val segB  = "b00111110".U(8.W) // 显示 B
  val segC  = "b10011100".U(8.W) // 显示 C
  val segD  = "b01111010".U(8.W) // 显示 D
  val segE  = "b10011110".U(8.W) // 显示 E
  val segF  = "b10001110".U(8.W) // 显示 F

  //初始化
  io.seg := 0.U

  switch(io.in) {
    is(0.U) { io.seg := ~seg0 }
    is(1.U) { io.seg := ~seg1 }
    is(2.U) { io.seg := ~seg2 }
    is(3.U) { io.seg := ~seg3 }
    is(4.U) { io.seg := ~seg4 }
    is(5.U) { io.seg := ~seg5 }
    is(6.U) { io.seg := ~seg6 }
    is(7.U) { io.seg := ~seg7 }
    is(8.U) { io.seg := ~seg8 }
    is(9.U) { io.seg := ~seg9 }
    is(10.U) { io.seg := ~segA }
    is(11.U) { io.seg := ~segB }
    is(12.U) { io.seg := ~segC }
    is(13.U) { io.seg := ~segD }
    is(14.U) { io.seg := ~segE }
    is(15.U) { io.seg := ~segF }
  }
}

object Top extends App {
    (new chisel3.stage.ChiselStage).emitVerilog(new Top)
}