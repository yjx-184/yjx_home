import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import chisel3._

class TopTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Top"
  it should "pass" in {
    test(new Top).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>

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
        9 -> "b0000_1001".U,
        10 -> "b0001_0001".U,
        11 -> "b1100_0001".U,
        12 -> "b0110_0011".U,
        13 -> "b1000_0101".U,
        14 -> "b0110_0001".U,
        15 -> "b0111_0001".U
      )
      // 遍历所有可能的计数器值（0 到 15）
      for (i <- 0 until 16) {
        // 等待计数器更新
         while (dut.io.seg.peek().litValue != expectedResult(i).litValue) {
          dut.clock.step()
        }

        // 验证 7 段数码管显示是否正确
        dut.io.seg.expect(expectedResult(i))

        // 补齐二进制输出到 8 位
        val expectedResults = dut.io.seg.peek().litValue.toInt.toBinaryString
        val paddedSegValue = "0" * (8 - expectedResults.length) + expectedResults

        // 打印调试信息
        println(s"Counter: $i, Seg: $paddedSegValue")
        // 继续运行时钟
        dut.clock.step()
      }
    }
  }
}