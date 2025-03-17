import chisel3._
import org.scalatest.flatspec.AnyFlatSpec
import chiseltest._

class NpcTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Npc"
  it should "pass" in {
    test(new Npc).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      var cycle = 0

      // 模拟直到遇到退出指令 (ebreak)
      while (dut.io.exit.peek().litToBoolean == false) {
        // 打印当前周期的 PC 值
        println(s"Cycle: $cycle, PC: 0x${dut.io.pc.peek().litValue.toString(16)}")
        
        // 打印寄存器值
        for (i <- 0 until 32) {
          // 使用 peek() 获取每个寄存器的值并打印
          println(s"Register x$i: 0x${dut.io.regFileOut(i).peek().litValue.toString(16)}")
        }

        // 步进一个时钟周期
        dut.clock.step(1)
        cycle += 1
      }

      println("Simulation finished!")
    }
  }
}
