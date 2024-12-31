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
