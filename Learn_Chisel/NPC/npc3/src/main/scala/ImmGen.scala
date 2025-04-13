import chisel3._
import chisel3.util._

class ImmGen extends Module {
    val io = IO(new Bundle {
        val instin = Input(UInt(32.W))  // 32位指令输入
        val immop = Input(UInt(3.W))    // 立即数类型选择
        val immout = Output(SInt(32.W)) // 立即数扩展后输出
    })

    // 提取不同类型的立即数
    val immI = Cat(Fill(20, io.instin(31)), io.instin(31, 20)).asSInt // I 型
    val immS = Cat(Fill(20, io.instin(31)), io.instin(30, 25), io.instin(11, 7)).asSInt // S 型
    val immB = Cat(Fill(20, io.instin(31)), io.instin(7), io.instin(30, 25), io.instin(11, 8), 0.U(1.W)).asSInt // B 型
    val immU = Cat(io.instin(31, 12), 0.U(12.W)).asUInt.asSInt // U 型 
    val immJ = Cat(Fill(12, io.instin(31)), io.instin(19, 12), io.instin(20), io.instin(30, 21), 0.U(1.W)).asSInt // J 型

    // 选择正确的立即数
    io.immout := MuxLookup(io.immop, 0.S, Seq(
        0.U -> immI,  // I 型（addi, lw, jalr）
        1.U -> immS,  // S 型（sw, sb, sh）
        2.U -> immB,  // B 型（beq, bne）
        3.U -> immU,  // U 型（lui, auipc）
        4.U -> immJ   // J 型（jal）
    ))

}

