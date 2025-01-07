import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class TopTest extends AnyFlatSpec with ChiselScalatestTester {
    behavior of "Top"
    it should "主副干道信号灯应该正常运行" in {
        test(new Top) { dut =>
            //初始状态：主干道绿灯
            dut.io.minorcar.poke(false.B)
            dut.io.timestate.poke(false.B)
            dut.clock.step(10)
            dut.io.mainLight.expect(2.U)
            dut.io.minorLight.expect(0.U)

            //检测到副干道有车辆
            dut.io.minorcar.poke(true.B)
            dut.clock.step(1)
            dut.io.mainLight.expect(2.U)

            //主干道黄灯
            dut.io.timestate.poke(true.B)
            dut.clock.step(1)
            dut.io.mainLight.expect(1.U)

            //全部都是红灯
            dut.clock.step(1)
            dut.io.mainLight.expect(0.U)
            dut.io.minorLight.expect(0.U)

            //副干道绿灯
            dut.clock.step(1)
            dut.io.minorLight.expect(2.U)
        }
    }
}