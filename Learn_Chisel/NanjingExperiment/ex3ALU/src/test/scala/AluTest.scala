import chisel3._
import org.scalatest.flatspec.AnyFlatSpec
import chiseltest._

class AluTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Alu"
  it should "pass" in {
    test(new Alu).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      //遍历所有操作码op
      for(op <- 0 until 8) {

        //遍历所有4位补码
        for(a <- -8 until 8) {
          for(b <- -8 until 8) {
            dut.io.op.poke(op.U)
            dut.io.a.poke(a.S)
            dut.io.b.poke(b.S)

            //执行计算
            dut.clock.step(1)

            //打印计算结果
            println(s"op= $op, a= $a, b= $b -> result= ${dut.io.result.peek().litValue},  carry= ${dut.io.carry.peek().litValue}, overflow= ${dut.io.overflow.peek().litValue}")
          }
        }
      }  
    }
  }
}
