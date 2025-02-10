import chisel3._
import chisel3.util._

//二位四选一
class Mux4to1 extends Module {
  val io = IO(new Bundle {
    val X0 = Input(UInt(2.W))
    val X1 = Input(UInt(2.W))
    val X2 = Input(UInt(2.W))
    val X3 = Input(UInt(2.W))
    val Y = Input(UInt(2.W))
    val F = Output(UInt(2.W))
  })

  io.F := MuxCase(0.U, Seq(
    (io.Y === "b00".U) -> io.X0,
    (io.Y === "b01".U) -> io.X1,
    (io.Y === "b10".U) -> io.X2,
    (io.Y === "b11".U) -> io.X3
  ))


}


object Mux4to1 extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Mux4to1())
}
