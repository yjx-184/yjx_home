



# 阅读chisel-book 跟着做第一个项目Hello
## Hello-world代码的解读
```
//导入Chisel库
import chisel3._

//定义一个名为Hello的硬件模块
class Hello extends Module {
  val io = IO(new Bundle {              //定义模块输入输出接口。led为输出端口
    val led = Output(UInt(1.W))         //led端口是1位的无符号整数，表示LED开关状态
  })
  val CNT_MAX = (50000000 / 2 - 1).U    //定义一个常量，表示计数器最大值

  val cntReg = RegInit(0.U(32.W))       //定义32位宽的寄存器cntReg，初始值为0
  val blkReg = RegInit(0.U(1.W))        //定义1位宽的寄存器blkReg，初始值为0

  cntReg := cntReg + 1.U                //每个时钟周期自增1
  when(cntReg === CNT_MAX) {
    cntReg := 0.U                       //重置计数器为0
    blkReg := ~blkReg                   //反转状态
  }
  io.led := blkReg                      //输出到LED控制端口io.led，从而控制LED状态
}

/**
 * 一个继承自 App 的对象，用于生成 Verilog 代码。
 */
object Hello extends App {
  // 创建一个 Chisel 编译器的实例 ChiselStage，然后调用 emitVerilog 方法
  // emitVerilog 会将硬件模块转换为 Verilog 代码并输出
  // 这里，我们将 Hello 模块的 Verilog 代码生成并输出
  (new chisel3.stage.ChiselStage).emitVerilog(new Hello())
}

```  
**val:** 表示定义了一个变量或者常量。  
## Hello-world的测试代码
```
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

```