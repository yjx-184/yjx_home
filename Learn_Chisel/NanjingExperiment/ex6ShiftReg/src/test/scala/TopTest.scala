import chiseltest._
import chisel3._
import org.scalatest.flatspec.AnyFlatSpec

class TopTest extends AnyFlatSpec with ChiselScalatestTester {
    behavior of "Top"
    it should "pass" in {
        test(new Top).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
            //初始化时钟和复位信号
            dut.io.reset.poke(false.B)
            dut.io.clk.poke(false.B)
            dut.io.btn.poke(false.B)

            //复位后，检查随机输出
            dut.io.reset.poke(true.B)
            dut.io.clk.poke(true.B)

            //模拟时钟信号
            for(i <- 0 until 100) {
                dut.io.clk.poke(true.B)
                dut.clock.step(1)
                dut.io.clk.poke(false.B)
                dut.clock.step(1)

                if (i % 2 == 0) {
                    dut.io.btn.poke(true.B)     //模拟按钮按下
                } else {
                    dut.io.btn.poke(false.B)    //模拟按钮松开
                }

                println(s"生成的随机数: ${dut.io.seg_out.peek().litValue}")
            }    
        }
    }
}