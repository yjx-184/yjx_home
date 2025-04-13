import chisel3._
import chisel3.util._

class BranchCond extends Module {
    val io = IO(new Bundle {
        val less = Input(UInt(1.W))
        val zero = Input(UInt(1.W))
        val branch = Input(UInt(3.W))   // 分支控制信号
        val pcasrc = Output(UInt(1.W))  // 选择 PC + 4 或 PC + imm
        val pcbsrc = Output(UInt(1.W))  // 选择 rs1 + imm
    })

    io.pcasrc := MuxCase("b1".U, Seq(    // PC + imm
        (io.branch === "b000".U) -> "b0".U, // PC + 4
        (io.branch === "b100".U && io.zero === "b0".U) -> "b0".U, // PC + 4
        (io.branch === "b101".U && io.zero === "b1".U) -> "b0".U, // PC + 4
        (io.branch === "b110".U && io.less === "b0".U) -> "b0".U, // PC + 4
        (io.branch === "b111".U && io.less === "b1".U) -> "b0".U, // PC + 4
    ))

    io.pcbsrc := MuxCase("b0".U, Seq(
        (io.branch === "b010".U) -> "b1".U  // rs1 + imm
    ))
    
}
