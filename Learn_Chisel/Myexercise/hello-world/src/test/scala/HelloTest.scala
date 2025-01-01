//导入chiseltest库，提供了用于Chisel模块单元测试的API
import chiseltest._
//导入scalatest中的AnyFlatSpec类，提供了一种简单的测试样式
import org.scalatest.flatspec.AnyFlatSpec

//定义HelloTest类，继承了AnyFlatSpec和ChiselScalatestTester
class HelloTest extends AnyFlatSpec with ChiselScalatestTester {

  behavior of "Hello"   //设置测试行为，意思是要对名为"Hello"的模块进行测试

  //定义一个测试用例，测试目标是 "Hello" 模块的 LED 状态变化
  it should "pass" in {

    //使用 ChiselTest 提供的 test 函数来测试 Hello 模块
    test(new Hello) { c =>
      c.clock.setTimeout(0)                   //设置时钟超时时间为0,时钟不会自动推进
      var ledStatus = BigInt(-1)              //定义变量ledStatus跟踪上一次LED状态
      println("Start the blinking LED")       //输出信息表明测试开始
      for (_ <- 0 until 100) {                //for循环100次，表示100个时钟周期
        c.clock.step(10000)                   //每次让时钟前进10000个周期

        //获取当前时刻LED状态，通过c.io.led.peek().litValue访问LED输出端口的值
        val ledNow = c.io.led.peek().litValue

        //根据LED状态来选择输出字符"o" else "*"表示LED关闭或者开启
        val s = if (ledNow == 0) "o" else "*"

        //如果有变化打赢状态并更新ledStatus
        if (ledStatus != ledNow) {
          System.out.println(s)
          ledStatus = ledNow
        }
      }
      //表示测试结束
      println("\nEnd the blinking LED")
    }
  }
}
