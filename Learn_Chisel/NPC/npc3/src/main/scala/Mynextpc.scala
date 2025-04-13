import chisel3._
import chisel3.util._

class Mynextpc extends Module {
    val io = IO(new Bundle {
        val imm = Input(SInt(32.W))
        val rs1 = Input(UInt(32.W))
        val pc  = Input(UInt(32.W))
        val pcasrc = Input(UInt(1.W))
        val pcbsrc = Input(UInt(1.W))
        val nextpc = Output(UInt(32.W))
    })

    val pca = Mux(io.pcasrc === "b1".U, io.imm.asUInt, 4.U)
    val pcb = Mux(io.pcbsrc === "b1".U, io.rs1, io.pc)
    io.nextpc := pca + pcb
}

