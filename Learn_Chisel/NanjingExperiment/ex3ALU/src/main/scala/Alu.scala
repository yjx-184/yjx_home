import chisel3._
import chisel3.util._

class Alu extends Module {
  val io = IO(new Bundle {
    val op = Input(UInt(3.W))
    val a = Input(SInt(4.W))
    val b = Input(SInt(4.W))
    val carry = Output(Bool())
    val zero = Output(Bool())
    val overflow = Output(Bool())
    val result = Output(SInt(4.W))
  })

  //Alu结果寄存
  val result = Wire(SInt(4.W))
  val carry = Wire(Bool())
  val overflow = Wire(Bool())

  //初始化
  result := 0.S
  carry := false.B
  overflow := false.B

  //操作码
  val add = 0
  val sub = 1
  val not = 2
  val and = 3
  val or = 4
  val xor = 5
  val les = 6
  val equ = 7

  switch(io.op) {
    is(add.U) {
      val sum = io.a +& io.b  //+&带进位运算符
      result := sum(3, 0).asSInt
      carry := sum(4)

      //溢出判断公式：如果 A 和 B 同号，但结果与 A 符号不同，则溢出。
      overflow := (io.a(3) === io.b(3)) && (io.a(3) =/= result(3))
    }
    is(sub.U) {
      val diff = io.a -& io.b
      result := diff(3, 0).asSInt
      carry := diff(4)

      //溢出判断类似加法，只不过 A 和 B 符号不同才可能溢出。
      overflow := (io.a(3) =/= io.b(3)) && (io.a(3) =/= result(3))
    }
    is(not.U) {
      result := ~io.a
    }
    is(and.U) {
      result := io.a & io.b
    }
    is(or.U) {
      result := io.a | io.b
    }
    is(xor.U) {
      result := io.a ^ io.b
    }
    is(les.U) {
      result := Mux(io.a < io.b, 1.S, 0.S)
    }
    is(equ.U) {
      result := Mux(io.a === io.b, 1.S, 0.S)
    }
  }

  //输出结果
  io.result := result
  io.carry := carry
  io.zero := (result === 0.S)
  io.overflow := overflow
}

object Alu extends App {
    (new chisel3.stage.ChiselStage).emitVerilog(new Alu)
}