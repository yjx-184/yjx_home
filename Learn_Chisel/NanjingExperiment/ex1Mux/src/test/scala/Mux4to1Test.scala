import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import chisel3._

class Mux4to1Test extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Mux4to1Test"
  it should "pass" in {
    test(new Mux4to1).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      //依次测试Y为00,01,10,11的情况
      for((sel,expected) <- Seq(
        (0.U, 0.U),
        (1.U, 1.U),
        (2.U, 2.U),
        (3.U, 3.U)
      ))  {
        dut.io.Y.poke(sel)  //设置选择信号

        dut.io.X0.poke(0.U)
        dut.io.X1.poke(1.U)
        dut.io.X2.poke(2.U)
        dut.io.X3.poke(3.U)

        dut.io.F.expect(expected) //期望输出

        dut.clock.step()
      }
    }
  }
}
