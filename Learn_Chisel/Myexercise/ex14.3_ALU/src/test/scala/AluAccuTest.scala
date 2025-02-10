import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

object Alu {
    def alu(a:Int, b: Int, op: Int): Int = {
        op match {
            case 0 => a
            case 1 => a + b
            case 2 => a - b
            case 3 => a & b
            case 4 => a | b
            case 5 => a ^ b
            case 6 => b
            case 7 => a >>> 1
            case _ => -123 // This shall not happen
        }
    }
}

class AluAccuTest extends AnyFlatSpec with ChiselScalatestTester {
    // 一些有趣的极端情况
    val interesting = Seq(1, 2, 4, 123, 0, -1, -2, 0x80000000, 0x7fffffff)

    // 定义一个函数来测试一对输入
    def testOne(dut: AluAccu, a: Int, b: Int, fun: Int): Unit = {
        dut.io.op.poke(6.U)             // 设置操作码为加载
        dut.io.enaMask.poke("b1111".U)  // 设置启用掩码
        dut.io.din.poke((a.toLong & 0x00ffffffffL).U)   // 设置输入a，并确保只取低32位
        dut.clock.step(1)               // 时钟前进一步

        dut.io.op.poke(fun.U(3.W))           // 设置操作码为fun
        dut.io.din.poke((b.toLong & 0x00ffffffffL).U)   // 设置输入b，并确保只取低32位
        dut.clock.step(1)               // 时钟前进一步

        dut.io.accu.expect((Alu.alu(a, b, fun).toLong & 0x00ffffffffL).U)  // 检查输出是否正确
    }

    //定义一个测试函数，接受一组值
    def test(dut: AluAccu, values: Seq[Int]) = {
        //遍历所有可能的操作码(0到7)
        for(fun <- 0 to 7) {
            //对每个输入值a进行测试
            for(a <- values) {
                //对每个输入值b进行测试
                for(b <- values) {
                    testOne(dut, a, b, fun) //调用testOne函数进行单次测试
                }
            }
        }
    }

    //主测试
    "AluAccu" should "pass all tests" in {
    test(new AluAccu(32)) { dut =>
      test(dut, interesting)  // 使用极端情况值进行测试
    }
  }
}