import chisel3._
import chisel3.util._

class EbreakDetector extends BlackBox {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val pc = Input(UInt(32.W))
    val exit = Output(Bool())  // 新增 exit 信号
  })
}

class Npc extends Module {
  val io = IO(new Bundle {
    val pc = Output(UInt(32.W))
    val inst = Output(UInt(32.W))
    val exit = Output(Bool())
  })

  val instMem = VecInit(Seq(
    "h00200093".U(32.W), // addi x1, x0, 2
    "h00300113".U(32.W), // addi x2, x0, 3
    "h00408193".U(32.W), // addi x3, x1, 4
    "h00510213".U(32.W), // addi x4, x2, 5
    "h00100073".U(32.W)  // ebreak 指令
  ))

  val pc = RegInit(0.U(32.W))
  val inst = RegInit(0.U(32.W))
  io.pc := pc
  io.inst := inst

  // 使用BlackBox来检测ebreak指令
  val ebreakDetector = Module(new EbreakDetector)
  ebreakDetector.io.inst := inst
  ebreakDetector.io.pc := pc

  // 将BlackBox中的exit信号输出到模块的exit端口
  io.exit := ebreakDetector.io.exit

  // 模拟指令执行
  when(!io.exit) {
    pc := pc + 4.U
    inst := instMem((pc - "h80000000".U) >> 2)
  }
}

object Npc extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Npc)
}
