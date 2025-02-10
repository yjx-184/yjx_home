import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import chisel3._

class SegTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Seg"
  it should "pass" in {
    test(new Seg).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      //测试输入为0时，valid应该为0,out也应该为000
      dut.io.in.poke(0.U)
      dut.io.sel.poke(true.B)
      dut.clock.step()
      dut.io.valid.expect(0.U)
      dut.io.out.expect(0.U)
      dut.io.seg.expect("b0000001".U)

      //测试使能为0时，输入为1,valid应该为1,但out应该为0,seg为0
      dut.io.in.poke(1.U)
      dut.io.sel.poke(false.B)
      dut.clock.step()
      dut.io.valid.expect(1.U)
      dut.io.out.expect(0.U)
      dut.io.seg.expect(0.U)

      //测试使能为1时，输入为1,valid应该为1,out为0,seg显示b1111110
      dut.io.in.poke(1.U)
      dut.io.sel.poke(true.B)
      dut.clock.step()
      dut.io.valid.expect(1.U)
      dut.io.out.expect(0.U)
      dut.io.seg.expect("b0000001".U)

      // 测试 in = 0b00000100，valid应该为1，out 应该是 010
      dut.io.in.poke("b00000100".U)
      dut.clock.step()
      dut.io.valid.expect(1.U)
      dut.io.out.expect("b010".U)
      dut.io.seg.expect("b0010010".U)  // 显示 2

      //测试是否优先
      dut.io.in.poke("b00000110".U)
      dut.clock.step()
      dut.io.valid.expect(1.U)
      dut.io.out.expect("b010".U)
      dut.io.seg.expect("b0010010".U)  // 显示 2

      // 测试 in = 0b10000000，out 应该是 111
      dut.io.in.poke("b10000000".U)
      dut.clock.step()
      dut.io.valid.expect(1.U)
      dut.io.out.expect("b111".U)
      dut.io.seg.expect("b0001111".U)  // 显示 7
    }
  }
}
