import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class TopTest extends AnyFlatSpec with ChiselScalatestTester {
    behavior of "Top"
    it should "主副干道信号灯应该正常运行" in {
        test(new Top).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
            //初始状态：主干道绿灯
            dut.io.minorcar.poke(false.B)   //副干道无车辆
            dut.io.timestate.poke(false.B)  //时间状态未触发
            dut.clock.step(10)
            dut.io.mainLight.expect(2.U)    //主干道绿灯
            dut.io.minorLight.expect(0.U)   //副干道红灯

            //检测到副干道有车辆
            dut.io.minorcar.poke(true.B)
            dut.clock.step(1)
            dut.io.mainLight.expect(1.U)    //主干道黄灯
            dut.io.minorLight.expect(0.U)   //副干道红灯


            //此时时间状态触发
            dut.io.timestate.poke(true.B)
            dut.clock.step(1)
            dut.io.mainLight.expect(0.U)    //主干道红灯
            dut.io.minorLight.expect(0.U)   //副干道红灯

            //继续模拟时间状态触发
            dut.io.timestate.poke(true.B)
            dut.clock.step(1)
            dut.io.mainLight.expect(0.U)    //主干道红灯
            dut.io.minorLight.expect(2.U)   //副干道绿灯

            //继续模拟时间状态触发,此时检测到小车离开
            dut.io.timestate.poke(true.B)
            dut.io.minorcar.poke(false.B)
            dut.clock.step(1)
            dut.io.mainLight.expect(0.U)    //主干道红灯
            dut.io.minorLight.expect(1.U)   //副干道黄灯

            //继续模拟时间状态触发
            dut.io.timestate.poke(true.B)
            dut.clock.step(1)
            dut.io.mainLight.expect(2.U)    //主干道绿灯
            dut.io.minorLight.expect(0.U)   //副干道红灯
            
            //回到初始状态
            dut.io.timestate.poke(false.B)  // 时间状态恢复初始值
            dut.io.minorcar.poke(false.B)   // 副干道无车辆
            dut.clock.step(10)              // 等待状态稳定
            dut.io.mainLight.expect(2.U)    // 主干道绿灯
            dut.io.minorLight.expect(0.U)   // 副干道红灯
        }
    }
}