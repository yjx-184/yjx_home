import chisel3._
import chisel3.util._

class Seg extends Module {
    val io = IO(new Bundle {
        val in = Input(UInt(8.W))
        val sel = Input(Bool())
        val out = Output(UInt(3.W))
        val seg = Output(UInt(7.W))
        val valid = Output(UInt(1.W))
    })

    //优先编码器
    val encodedOut = Wire(UInt(3.W))

    when(io.in(7)) {
        encodedOut := 7.U
    } .elsewhen(io.in(6)) {
        encodedOut := 6.U
    } .elsewhen(io.in(5)) {
        encodedOut := 5.U
    } .elsewhen(io.in(4)) {
        encodedOut := 4.U
    } .elsewhen(io.in(3)) {
        encodedOut := 3.U
    } .elsewhen(io.in(2)) {
        encodedOut := 2.U
    } .elsewhen(io.in(1)) {
        encodedOut := 1.U
    } .otherwise {
        encodedOut := 0.U
    }

    io.out := encodedOut

    //指示位：有任何一个输入时为1,没有输入时为0
    io.valid := io.in.orR

    // 七段数码管译码
    io.seg := 0.U(7.W) // 默认值为 0

    when(io.sel) {
        switch(io.out) {
            is(0.U) { io.seg := "b0000001".U(7.W) } // 0
            is(1.U) { io.seg := "b1001111".U(7.W) } // 1
            is(2.U) { io.seg := "b0010010".U(7.W) } // 2
            is(3.U) { io.seg := "b0000110".U(7.W) } // 3
            is(4.U) { io.seg := "b1001100".U(7.W) } // 4
            is(5.U) { io.seg := "b0100100".U(7.W) } // 5
            is(6.U) { io.seg := "b0100000".U(7.W) } // 6
            is(7.U) { io.seg := "b0001111".U(7.W) } // 7
        }
    }
        
}

object Seg extends App {
    (new chisel3.stage.ChiselStage).emitVerilog(new Seg)
}