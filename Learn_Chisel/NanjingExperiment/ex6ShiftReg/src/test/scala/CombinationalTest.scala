import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import chisel3._

class CombinationalTestTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Combinational"
  it should "pass" in {
    test(new Combinational).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      //定义输入到七段码的期望输出映射
      val expectedResult = Map(
        0 -> "b0000_0011".U,
        1 -> "b1001_1111".U,
        2 -> "b0010_0101".U,
        3 -> "b0000_1101".U,
        4 -> "b1001_1001".U,
        5 -> "b0100_1001".U,
        6 -> "b0100_0001".U,
        7 -> "b0001_1111".U,
        8 -> "b0000_0001".U,
        9 -> "b0000_1001".U
      )

      //测试输入0到9
      for ((input, expected) <- expectedResult) {
        dut.io.in.poke(input.U)     //输入值
        dut.clock.step(1)            //运行一个时钟周期
        dut.io.seg.expect(expected) //验证输出是否正确
      }

      //测试输入10,期望输出全灭
      dut.io.in.poke(10.U)
      dut.clock.step(1)
      dut.io.seg.expect("b1111_1111".U)
    }
  }
}
