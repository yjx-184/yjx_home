/*
 * This code is a minimal hardware described in Chisel.
 * 
 * Blinking LED: the FPGA version of Hello World
 */

import chisel3._

/**
 * The blinking LED component.
 */

class Hello extends Module {
  val io = IO(new Bundle {
    val sw = Input(UInt(2.W))         //2位输入
    val led = Output(UInt(1.W))       //1位输出
  })
  //计数器的最大值
  val CNT_MAX = (50000000 / 2 - 1).U

  val cntReg = RegInit(0.U(32.W))     //计数器寄存器
  val blkReg = RegInit(0.U(1.W))      //LED状态寄存器

  //计数器和状态翻转逻辑
  cntReg := cntReg + 1.U
  when(cntReg === CNT_MAX) {
    cntReg := 0.U
    blkReg := ~blkReg
  }
  //使用sw控制LED输出
  io.led := Mux(io.sw === 0.U, 0.U,    //sw = 0,LED关闭
                Mux(io.sw === 1.U, 1.U,//sw =1,LED常量
                    blkReg
                ))    //sw = 其他值，LED闪烁
}

  

/**
 * An object extending App to generate the Verilog code.
 */
object Hello extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Hello())
}
