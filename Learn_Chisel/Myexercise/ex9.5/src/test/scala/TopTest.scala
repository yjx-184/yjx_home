import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class TopTest extends AnyFlatSpec with ChiselScalatestTester {
    behavior of "Top"
    it should "LED灯正确的进行闪烁" in {
        test(new Top(fac = 10)) { dut =>
            dut.clock.setTimeout(100000)

           //初始化输入和检查初始状态
           dut.io.btn.poke(false.B) //初始按钮状态为低
           dut.clock.step(10)       //运行几个周期稳定状态
           dut.io.led.expect(0.U)   //初始计数器为0

           //模拟按钮按下并保持一段时间
           dut.io.btn.poke(true.B)
           dut.clock.step(20000)
           dut.io.led.expect(1.U)

           //按钮送开后，再次按下
           dut.io.btn.poke(false.B)
           dut.clock.step(20000)
           dut.io.btn.poke(true.B)
           dut.clock.step(20000)
           dut.io.led.expect(2.U)

           //快速切换按钮状态（测试抖动情况）
           for (_ <- 0 until 5) {
            dut.io.btn.poke(true.B)
            dut.clock.step(5)
            dut.io.btn.poke(false.B)
            dut.clock.step(5)
           } 
           dut.clock.step(20000)    //等待防抖电路处理
           dut.io.led.expect(2.U)

           //再次按下按钮
           dut.io.btn.poke(true.B)
           dut.clock.step(20000)
           dut.io.led.expect(3.U)
        
        }
    }
}