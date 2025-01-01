import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import chisel3._ 

class HelloTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "Hello"
  it should "pass" in {
    test(new Hello) { c =>
      c.clock.setTimeout(0)
      var ledStatus = BigInt(-1)
      println("Start the blinking LED test with sw control")

      //测试不同sw值对LED的影响
      for (swVal <- 0 to 3) { //遍历sw的值
        println(s"Testing sw = $swVal:")
        c.io.sw.poke(swVal.U) //设置sw的值

        for (_ <- 0 until 50) { //在每个sw状态下模拟若干时钟周期
          c.clock.step(10000) //快速推进时钟
          val ledNow = c.io.led.peek().litValue
          val s = if (ledNow == 0) "o" else "*" //输出LED状态
          if (ledStatus != ledNow) {
            System.out.print(s) //当前状态发生变化时打印
            ledStatus = ledNow
          }
        }
        println() //换行分割不同se值的输出
      }
      println("End the blinking LED test")
    }
  }
}
