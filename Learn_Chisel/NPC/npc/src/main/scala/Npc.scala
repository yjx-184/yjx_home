import chisel3._
import chisel3.util._

class Npc extends Module {
  val io = IO(new Bundle {
    val exit = Output(Bool())
    val pc   = Output(UInt(32.W))
    val regFileOut = Output(Vec(32, UInt(32.W)))
  })

  // 定义常量
  val PC_START = 0x80000000L.U(32.W)  // PC初始值
  val REG_ZERO = 0.U(32.W)     // x0寄存器

  // 寄存器文件
  val regFile = RegInit(VecInit(Seq.fill(32)(0.U(32.W))))

  // PC
  val pc = RegInit(PC_START)

  // 指令寄存器
  val instMem = VecInit(Seq(
    "h00200093".U(32.W), // addi x1, x0, 2  (x1 = 0 + 2)
    "h00300113".U(32.W), // addi x2, x0, 3  (x2 = 0 + 3)
    "h00408193".U(32.W), // addi x3, x1, 4  (x3 = 2 + 4)
    "h00510213".U(32.W), // addi x4, x2, 5  (x4 = 3 + 5)
    "h00100073".U(32.W)  // 停止指令 (ebreak)
  ))

  // 取指
  val inst = instMem((pc - PC_START) >> 2)

  // 译码
  val op = inst(6, 0)
  val rd = inst(11, 7)
  val rs1 = inst(19,15)
  val imm = inst(31, 20)

  // 立即数扩展
  val imm_sext = Cat(Fill(20, imm(11)), imm)

  // 执行
  val aluOut = WireInit(0.U(32.W))
  aluOut := regFile(rs1) + imm_sext

  // 写回寄存器
  when(op === "b0010011".U) {
    when(rd =/= 0.U) {
      regFile(rd) := aluOut
    }
  }

  // 更新PC
  pc := pc + 4.U
  io.pc := pc

  // 输出寄存器文件
  io.regFileOut := regFile

  // 结束
  io.exit := (inst === "h00100073".U)

}

object Npc extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Npc)
}
