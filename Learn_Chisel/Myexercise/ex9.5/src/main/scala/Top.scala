import chisel3._
import chisel3.util._


//顶层模块
class Top(fac : Int = 10000) extends Module {
  val io = IO(new Bundle {
    val btn = Input(Bool())
    val led = Output(UInt(8.W))
  })

  //输入同步器
  def sync(v: Bool) = RegNext(RegNext(v))
  val btnsync = sync(io.btn)              //将按钮信号通过输入同步器

  //防抖动电路（生成分频信号）
  def tickGen(fac: Int) = {
    val reg = RegInit(0.U(log2Up(fac).W))
    val tick = reg === (fac - 1).U
    reg := Mux(tick, 0.U, reg + 1.U)
    tick
  }
  val tick = tickGen(fac) //生成一个分频信号

  val btnDeb = Reg(Bool())  //定义布尔函数寄存器，存储同步后按钮信号
  when(tick) {              //当tick有效，根系布尔函数寄存器
    btnDeb := btnsync
  }

  //大多数投票
  def filter(v: Bool, t: Bool) = {
    val reg = RegInit(0.U(3.W))
    when(t) {
      reg := Cat(reg(1, 0), v)
    }
    (reg(2) & reg(0)) | (reg(2) & reg(1)) | (reg(1) & reg(0))
  }
  val btnClean = filter(btnDeb, tick) //滤波处理信号

  //边沿检测
  def rising(v: Bool): Bool = v & !RegNext(v) // 检测上升沿
  val risingEdge = rising(btnClean)           //检测清理后的按钮信号的上升沿

  //计数器逻辑
  val counter = RegInit(0.U(8.W))
  when(risingEdge) {
    counter := counter + 1.U
  }

  //输出到LED显示
  io.led := counter

}


object Top extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Top())
}
