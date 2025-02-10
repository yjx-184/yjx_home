import chisel3._
import chisel3.util._

class Timing extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(4.W))
    val seg = Output(UInt(8.W))
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
    .elsewhen(io.in === "b1010".U) { io.seg := "b0001_0001".U } // A
    .elsewhen(io.in === "b1011".U) { io.seg := "b1100_0001".U } // B
    .elsewhen(io.in === "b1100".U) { io.seg := "b0110_0011".U } // C
    .elsewhen(io.in === "b1101".U) { io.seg := "b1000_0101".U } // D
    .elsewhen(io.in === "b1110".U) { io.seg := "b0110_0001".U } // E
    .elsewhen(io.in === "b1111".U) { io.seg := "b0111_0001".U } // F
    .otherwise { io.seg := "b1111_1111".U } // 全灭
}

//顶层模块
class Top extends Module {
  val io = IO(new Bundle {
    val seg = Output(UInt(8.W))
  })

  //4位计数器
  val counter4 = RegInit(0.U(4.W))  //初始化为0

  //秒计数器
  val freq = 100000000                //FPGA时钟频率（100MHZ）
  val halfSecond = (freq / 2).U       //500毫秒计数周期
  //val halfSecond = 10.U                 //方便测试
  val secCounter = RegInit(0.U(27.W)) //秒计数器宽度足够存储100M

  val tick = Wire(Bool())             //用于生成计数脉冲
  tick := false.B

  when(secCounter === halfSecond - 1.U) {
    secCounter := 0.U                 //重置计数器
    tick := true.B                    //产生tick信号
  } .otherwise {                      //否则计数器自增
    secCounter := secCounter + 1.U
  }

  //使能计数器
  when(tick) {
    counter4 := counter4 + 1.U // 每次 tick 更新计数器
  }

  //实例化
  val timing = Module(new Timing)
  timing.io.in := counter4
  io.seg := timing.io.seg
}


object Top extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Top())
}
