import chisel3._
import chisel3.util._

class AluAccu(size: Int) extends Module {
  val io = IO(new Bundle {
    val op = Input(UInt(3.W))       // 操作符输入
    val din = Input(UInt(size.W))   // 输入数据
    val enaMask = Input(UInt(4.W))  // 掩码使能
    val enaByte = Input(Bool())     // 字节使能
    val enaHalf = Input(Bool())     // 半字使能
    val off = Input(UInt(2.W))      // 偏移量输入
    val accu = Output(UInt(size.W)) // 累加器输出
  })

  val accuReg = RegInit(0.U(size.W))  // 累加器初始化为0

  val op = io.op            // 操作符
  val a = accuReg           // 累加器值
  val b = io.din            // 输入数据
  val res = WireDefault(a)  // 计算结果默认是累加器值

  // 操作码
  val nop = 0
  val add = 1
  val sub = 2
  val and = 3
  val or = 4
  val xor = 5
  val ld = 6
  val shr = 7

  switch(op) {
    is(nop.U) {
      res := a
    }
    is(add.U) {
      res := a + b
    }
    is(sub.U) {
      res := a - b
    }
    is(and.U) {
      res := a & b
    }
    is(or.U) {
      res := a | b
    }
    is(xor.U) {
      res := a ^ b
    }
    is(ld.U) {
      res := b
    }
    is(shr.U) {
      res := a >> 1
    }
  }

  // 提取字节和半字的值
  val byte = WireDefault(res(7, 0))
  val half = WireDefault(res(15, 0))

  // 根据偏移量选择不同的字节/半字
  when(io.off === 1.U) {
    byte := res(15, 8)
  } .elsewhen(io.off === 2.U) {
    byte := res(23, 16)
    half := res(31, 16)
  } .elsewhen(io.off === 3.U) {
    byte := res(31, 24)
  } .otherwise {
    byte := res(7, 0)
    half := res(15, 0)
  }

  // 符号扩展
  val signExt = Wire(SInt(size.W))

  when(io.enaByte) {
    signExt := byte.asSInt  // 如果启用字节模式，进行符号扩展
  } .otherwise {
    signExt := half.asSInt  // 否则进行半字符号扩展
  }

  // 针对缺失的子字节赋值进行的工作区
  val split = Wire(Vec(4, UInt(8.W))) // 将结果拆分为4个8位的子字节
  for (i <- 0 until 4) {
    split(i) := Mux(io.enaMask(i), res(8 * i + 7, 8 * i), accuReg(8 * i + 7, 8 * i))
  }

  // 根据字节、半字使能和掩码进行累加器的值的更新
  when((io.enaByte || io.enaHalf) && io.enaMask.orR) {
    accuReg := signExt.asUInt   // 更新为符号扩展后的值
  } .otherwise {
    accuReg := Cat(split.reverse)  // 否则更新为新拆分后的值
  }
  io.accu := accuReg              // 输出累加器值
}