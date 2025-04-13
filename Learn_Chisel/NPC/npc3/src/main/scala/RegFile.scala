import chisel3._
import chisel3.util._

class RegFile extends Module {
    val io = IO(new Bundle {
        // val wrclk = Input(Clock())      // 写入时钟
        val ra    = Input(UInt(4.W))    // 读取端口 A 地址(16个寄存器)
        val rb    = Input(UInt(4.W))    // 读取端口 B 地址
        val rw    = Input(UInt(4.W))    // 写入端口地址
        val busw  = Input(UInt(32.W))   // 写入数据
        val regwr = Input(UInt(1.W))    // 写使能信号
        val busa  = Output(UInt(32.W))  // 读取端口 A 数据
        val busb  = Output(UInt(32.W))  // 读取端口 B 数据
        val regsout = Output(Vec(16, UInt(32.W)))

        val reg_rw = Output(UInt(32.W))
    })

    // 16 个 32 位寄存器，x0 恒为 0
    val regs = RegInit(VecInit(Seq.fill(16)(0.U(32.W))))

    // 组合逻辑读取寄存器
    io.busa := Mux(io.ra === 0.U, 0.U, regs(io.ra)) // x0 恒为 0
    io.busb := Mux(io.rb === 0.U, 0.U, regs(io.rb))
    
  //  withClock(io.wrclk) {
    when(io.regwr.asBool && io.rw =/= 0.U) {
      regs(io.rw) := io.busw
    }
  // }
    io.regsout := regs
    io.reg_rw := regs(io.rw)
}

