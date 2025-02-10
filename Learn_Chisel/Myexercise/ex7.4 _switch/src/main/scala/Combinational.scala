import chisel3._
import chisel3.util._

class Combinational extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(4.W))
    val seg = Output(UInt(8.W))
  })

  // 默认值
  io.seg := "b1111_1111".U  // 默认显示全灭
  
  // 使用 switch/is
  switch(io.in) {
    is("b0000".U) { io.seg := "b0000_0011".U } // 0
    is("b0001".U) { io.seg := "b1001_1111".U } // 1
    is("b0010".U) { io.seg := "b0010_0101".U } // 2
    is("b0011".U) { io.seg := "b0000_1101".U } // 3
    is("b0100".U) { io.seg := "b1001_1001".U } // 4
    is("b0101".U) { io.seg := "b0100_1001".U } // 5
    is("b0110".U) { io.seg := "b0100_0001".U } // 6
    is("b0111".U) { io.seg := "b0001_1111".U } // 7
    is("b1000".U) { io.seg := "b0000_0001".U } // 8
    is("b1001".U) { io.seg := "b0000_1001".U } // 9
    //default { io.seg := "b1111_1111".U } // 全灭
  }
}

object Combinational extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Combinational())
}
