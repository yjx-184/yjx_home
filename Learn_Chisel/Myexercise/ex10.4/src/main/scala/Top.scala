import chisel3._
import chisel3.util._
import circt.stage.ChiselStage 

class Top extends Module {
  val io = IO(new Bundle {
    val minorcar = Input(Bool())        //副干道车辆检测
    val timestate = Input(Bool())       //信号灯时间状态
    val minorLight = Output(UInt(2.W))  //副干道信号灯状态
    val mainLight = Output(UInt(2.W))   //主干道信号灯状态
  })

  //状态
  object State extends ChiselEnum {
    val MainGreen, MainOrange, AllRed, MinorGreen, MinorOrange = Value
  }
  import State._
  val stateReg = RegInit(MainGreen) //状态寄存器，初始为主干道绿灯

  //主干道和副干道信号灯状态默认输出
  io.mainLight := 0.U //默认红灯
  io.minorLight := 0.U

  //状态转移逻辑
  switch (stateReg) {
    is (MainGreen) {
      io.mainLight := 2.U   //主干道绿灯
      io.minorLight := 0.U  //副干道红灯
      when(io.minorcar === true.B) {   //检测到副干道有车辆
        stateReg := MainOrange
      }
    }
    is (MainOrange) {
      io.mainLight := 1.U
      io.minorLight := 0.U
      when(io.timestate) {
        stateReg := AllRed
      }
    }
    is (AllRed) {
      io.mainLight := 0.U
      io.minorLight := 0.U
      when(io.timestate) {
        stateReg := MinorGreen
      }
    }
    is (MinorGreen) {
      io.mainLight := 0.U
      io.minorLight := 2.U
      when(io.timestate & (io.minorcar === false.B)) {  //检测到小车离开
        stateReg := MinorOrange
      }
    }
    is (MinorOrange) {
      io.mainLight := 0.U
      io.minorLight := 1.U
      when(io.timestate) {
        stateReg := MainGreen
      }
    }
  }
}


object Top extends App {
  (new ChiselStage).emitVerilog(new Top())
}
