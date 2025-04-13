import chisel3._
import chisel3.util._

class Mypc extends Module {
    val io = IO(new Bundle{
        val nextpc = Input(UInt(32.W))
        val wrclk  = Input(Clock())
        val pc = Output(UInt(32.W))
    })

    val pcReg = RegInit(0x80000000L.U(32.W))
    withClock(io.wrclk) {
            pcReg := io.nextpc
    }
    io.pc := pcReg
}
