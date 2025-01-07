- [7.输入处理](#7输入处理)
  - [7.1异步输入](#71异步输入)
  - [7.2防抖动](#72防抖动)
  - [7.3输入信号滤波](#73输入信号滤波)
  - [7.4使用函数合并输入处理](#74使用函数合并输入处理)
  - [7.5练习](#75练习)
    - [源代码部分](#源代码部分)
    - [测试代码](#测试代码)
    - [将生成的verilog与nvboard连接](#将生成的verilog与nvboard连接)
- [8.有限状态机](#8有限状态机)
  - [8.1基本有限状态机](#81基本有限状态机)
  - [8.2使用Mealy FSM产生快速输出](#82使用mealy-fsm产生快速输出)
  - [8.3Moore对比Mealy](#83moore对比mealy)
  - [8.4练习](#84练习)


# 7.输入处理
## 7.1异步输入
我们不能防止多稳态，但是我们可以容纳这个问题，一个经典的解法是在输入使用两个触发器。这个的假设是：当这个触发器在多稳态的时候，他会在一个周期后收敛到稳定，所以第二个触发器的建议和保持时间都不会被违反。  

**用于输入的同步器的chisel代码是一行代码实现的两个寄存器：**  
```
val btnSync = RegNext(RegNext(btn))
```  
所有的同步外部信号需要一个输入同步。我们也需要同步一个外部的重置信号。这个重置信号应该先通过两个触发器，再被其他触发器使用，作为重置信号。具体的重置信号零，需要同步到时钟。  

## 7.2防抖动
防抖动的chisel代码是同步器改进的。我们使用计数器生成一个采样，表达一个周期的tick信号。  
```
val FAC = 100000000/100
val btnDebReg = Reg(Bool())
val cntReg = RegInit(0.U(32.W))
val tick = cntReg === (FAC - 1).U

cntReg := cntReg + 1.U
when(tick) {
    cntReg := 0.U
    btnDebReg := btnSync
}
```  
首先，我们需要决定采样频率。以上的例子是加设一个100MHZ的时钟，和导致的采样频率位100HZ（假设震荡时间小与10ms）。最大计数器值是FAC，除法的隐子。我们定义一个寄存器btnDebReg用于防抖动的信号，只是没有重置的值。寄存器cntReg作为计数器，tick信号为真，当计数器到达了最大值，在那种情况下，when的条件是true，（1）计数器的重置是0,（2）防抖动寄存器存储输入采样，在我们的例子里，输入信号被称为btnSync。  

## 7.3输入信号滤波
滤掉一些毛刺的方法是使用大多数投票电路。在最简单的情况，我们做三次采样，并执行大多数投票。大多数函数是和中值函数相关的，也就是大多数的数值。在我们的例子里，我们使用防抖动采样，我们采用了大多数投票，在采样信号。大多数投票确保了信号可以比采样周期的稳定时间更长。  
![]( ./pic/大多数投票.png)  
例子中的大多数投票电路，包括3位移位寄存器，使能端被用于防抖动的tick信号触发，输出的三个寄存器反馈到大多数投票电路。大多数投票函数滤掉任何比采样信号变化短的信号。(这个大多数投票是很少需要的)以下chisel代码：  
```
val shiftReg = RegInit(0.U(3.W))
when(tick) {
    //左移并输入LSB
    shiftReg := Cat(shiftReg(1, 0), btnDebReg)
}

    //大多数投票
    val btnClean = (shiftReg(2) & shiftReg(1) | (shiftReg(2) & shiftReg(0)) | shiftReg(1) & shiftReg(0))
```  
为了使用我们精心处理的输入信号的输出，我们首先使用RegNext延迟元素检测上升沿，然后把这个信号和当前值btnClean比较，使能计数器自增。  
```
val risingEdge = btnClean & !RegNext(btnClean)

// 使用反弹的上升边缘和
// 过滤按钮进行计数
val reg = RegInit(0.U(8.W))
when(risingEdge) {
    reg := reg + 1.U
}
```  

## 7.4使用函数合并输入处理
为了总结输入处理，我们显示了更多的chisel代码，我们呈现的电路可能很小，但是这些是可复用搭建模块，我们把这些包裹成函数。同时也展示如何使用轻量级chisel函数把小的搭建模块抽象化，而不是整个模块。那些chisel函数创造了硬件实例，例如sync函数创造了两个触发器相互连接到输入。函数返回了第二个触发器的输出，如果有用的话，这些函数可以用来当作工具类的对象。  
```

def sync(v: Bool) = RegNext(RegNext(v)) //两级同步寄存器处理，消除亚稳态问题

def rising(v: Bool) = v & !RegNext(v)   //检测上升沿，当前值为高且前一个时钟周期值为低

//防抖动电路
def tickGen(fac: Int) = {                   //生成分频时钟信号
    val reg = RegInit(0.U(log2Up(fac).W))   //定义计数器，宽度取决于 fac 的对数向上取整
    val tick = reg === (fac - 1).U          //生成tick信号
    reg := Mux(tick, 0.U, reg + 1.U)        
    tick
}

//对输入信号进行三级滤波，当触发信号t为高时更新寄存器reg
//滤波结果是寄存器中最近三个信号值的“大多数投票”结果
def filter(v: Bool, t: Bool) = {
    val reg = RegInit(0.U(3.W))     //定义一个3位寄存器，初始化为0
    when(t) {                       //当触发信号t为高，更新寄存器内容，按位移方式添加新值v
        reg := Cat(reg(1, 0), v)
    }
    //返回寄存器中最近三次信号的“多数投票”结果
    (reg(2) & reg(1)) | (reg(2) & reg(0)) | (reg(1) & reg(0))
}

val btnSync = sync(btn)     //将按钮输入信号btn通过两级同步寄存器处理

val tick = tickGen(fac)     //生成一个分频时钟信号tick，频率为系统时钟的1/fac
val btnDeb = Reg(Bool())    //定义布尔寄存器，用于存储同步后的按钮信号
when(tick) {                //每当tick有效，对布尔寄存器btnDeb进行更新
    btnDeb := btnSync
}

val btnClean = filter(btnDeb, tick) //使用三级滤波器对去抖信号btnDeb进行一步清理
val risingEdge = rising(btnClean)   //检测清理后的按钮信号的上升沿

// 使用去抖后的按钮信号的上升沿触发计数器的加一操作
// 并对计数结果存储在 8 位寄存器 reg 中
val reg = RegInit(0.U(8.W))
when(risingEdge) {      //当检测到按钮清理信号的上升沿时，计数器加一
    reg := reg + 1.U
}
```  

该代码整体实现了如下功能：  
**1.按钮去抖：** 通过sync和filter对按钮输入信号进行同步和三级滤波，清除可能的抖动。  
**2.上升沿检测：** 使用rising检测清理后的按钮信号的上升沿。  
**3.分频生成信号：** tickGen根据输入参数fac生成分频信号，用作计数器和滤波触发信号。  
**4.计数功能：** 通过按钮上升沿触发计数器reg的加一操作，结果存储在寄存器中。  
实现了一个稳定的按钮输入信号处理和计数器逻辑。  

## 7.5练习
### 源代码部分
```
import chisel3._
import chisel3.util._


//顶层模块
class Top(fac : Int = 10000) extends Module {
  val io = IO(new Bundle {
    val btn = Input(Bool())
    val led = Output(UInt(8.W))
  })

  //输入同步器
  def sync(v: Bool) = RegNext(RegNext(v))
  val btnsync = sync(io.btn)              //将按钮信号通过输入同步器

  //防抖动电路（生成分频信号）
  def tickGen(fac: Int) = {
    val reg = RegInit(0.U(log2Up(fac).W))
    val tick = reg === (fac - 1).U
    reg := Mux(tick, 0.U, reg + 1.U)
    tick
  }
  val tick = tickGen(fac) //生成一个分频信号

  val btnDeb = Reg(Bool())  //定义布尔函数寄存器，存储同步后按钮信号
  when(tick) {              //当tick有效，根系布尔函数寄存器
    btnDeb := btnsync
  }

  //大多数投票
  def filter(v: Bool, t: Bool) = {
    val reg = RegInit(0.U(3.W))
    when(t) {
      reg := Cat(reg(1, 0), v)
    }
    (reg(2) & reg(0)) | (reg(2) & reg(1)) | (reg(1) & reg(0))
  }
  val btnClean = filter(btnDeb, tick) //滤波处理信号

  //边沿检测
  def rising(v: Bool): Bool = v & !RegNext(v) // 检测上升沿
  val risingEdge = rising(btnClean)           //检测清理后的按钮信号的上升沿

  //计数器逻辑
  val counter = RegInit(0.U(8.W))
  when(risingEdge) {
    counter := counter + 1.U
  }

  //输出到LED显示
  io.led := counter

}


object Top extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Top())
}

```  
### 测试代码
```
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
```  
**测试结果：**  
```
yjx@yjx-Lenovo-Legion-R7000-2020:~/Mystudy/yjx_learn/Learn_Chisel/Myexercise/ex9.5$ sbt test
[info] welcome to sbt 1.10.6 (Ubuntu Java 11.0.25)
[info] loading project definition from /home/yjx/Mystudy/yjx_learn/Learn_Chisel/Myexercise/ex9.5/project
[info] loading settings for project ex9-5 from build.sbt...
[info] set current project to ex9-5 (in build file:/home/yjx/Mystudy/yjx_learn/Learn_Chisel/Myexercise/ex9.5/)
[info] compiling 1 Scala source to /home/yjx/Mystudy/yjx_learn/Learn_Chisel/Myexercise/ex9.5/target/scala-2.12/test-classes ...
[info] TopTest:
[info] Top
[info] - should LED灯正确的进行闪烁
[info] Run completed in 5 seconds, 873 milliseconds.
[info] Total number of tests run: 1
[info] Suites: completed 1, aborted 0
[info] Tests: succeeded 1, failed 0, canceled 0, ignored 0, pending 0
[info] All tests passed.
[success] Total time: 10 s, completed Jan 2, 2025, 2:32:36 PM

```  
### 将生成的verilog与nvboard连接

# 8.有限状态机
有限状态机FSM是一个数字电路中的基本搭建模块。一个FSM可以被描述为一个states和（有限制的）状态条件state transitions。一个FSM有一个初始状态，这是在reset中被确定的。FSM也被称为同步时序电路。FSM的实现包括三个部分：（1）一个具有现在状态的寄存器。（2）组合逻辑根据目前状态和输入计算下一个状态。（3）组合逻辑能够计算FSM的输出。  

原则上，每个数字电路包含一个寄存器或是其他存储器元件用来储存状态，可以被称为一个FSM。但是这可能不实用。例如吧你的电脑描述为一个FSM。  
## 8.1基本有限状态机
使用chisel描述一个FSM：  
```
import chisel3._
import chisel3.util._

class SimpleFsm extends Module {
    val io = IO(new Bundle {
        val badEvent = Input(Bool())
        val clear = Input(Bool())
        val ringBell = Output(Bool())
    })

    //3个状态
    val green :: orange :: red :: Nil = Enum(3)

    //使用寄存器来存储当前状态，初始状态为green
    val stateReg = RegInit(green)

    //定义状态转移逻辑
    switch(stateReg) {              //根据stateReg选择当前状态
        is (green) {
            when(io.badEvent) {
                stateReg := orange
            }
        }
        is (orange) {
            when(io.badEvent) {
                stateReg := red
            } .elsewhen(io.clear) {
                stateReg := green
            }
        }
        is (red) {
            when (io.clear) {
                stateReg := green
            }
        }
    }
    
    io.ringBell := stateReg === red
}
```  
记住我们没有引入next_state作为寄存器输入，尽管这个在verilog或是VHDL是常见的。vrilog和VHDL的寄存器被表述为一个特定的形式，在一个组合框架并且不能赋值或是重复赋值。于是额外的信号，在组合框架被计算出来并连接给寄存器的输入。在chisel，寄存器是一个基础类型，可以通过组合框架免费使用。  

## 8.2使用Mealy FSM产生快速输出
在一个Moore FSM，输出值只取决于当前状态，那意味着输入改变可以被看成导致最早的下一个周期的输出改变。如果我们想要观察一个间接的改变，我们需要一个组合路径，从输入到输出。让我们像一个最小的例子，在边沿检测电路。我们可能以前看过这一行chisel代码：  
```
val risingEdge = din & !RegNext(din)
```  
![](./pic/FSM.png)  
图10.5表明Mealy FSM的状态图，用于边沿检测，作为状态寄存器，包含了只是一个D触发器，只有两个状态是可能的，在这个例子中是zero和one。  

作为Mealy FSM的输出，并不只是依赖于状态，也依赖于输入，我们不能描述输出作为状态圆的一部分。相反，状态间的转移函数和输入值和输出值是一起被标出的。注意到我们画本身的状态转移，例如，在状态0当输入是0,FSM停留在0,输出是0,FSM的上升沿产生1作为输出，只有当从状态0转移到1。在状态1,输出是0.我们想要一个对于每个输入的上升沿，产生单一周期的跳变。  
```
import chisel3._
import chisel3.util._

class RisingFsm extends Module {
    val io = IO(new Bundle {
        val din = Input(Bool())
        val risingEdge = Output(Bool())
    })

    //有两个状态
    val zero :: one :: Nil = Enum(2)

    //状态存储
    val stateReg = RegInit(zero)

    //输出默认值
    io.risingEdge := false.B

    //状态转移逻辑
    switch(stateReg) {
        is (zero) {
            when(io.din) {
                stateReg := one
                io.risingEdge := true.B
            }
        }
        is (one) {
            when(!io.din) {
                stateReg := zero
            }
        }
    }
}
```  
## 8.3Moore对比Mealy
![](./pic/FSM2.png)  
```
import chisel3._
import chisel3.util._

class RisingMooreFsm extends Module {
    val io = IO(new Bundle {
        val din = Input(Bool())
        val risingEdge = Output(Bool())
    })

    //有3种状态
    val zero :: puls :: one :: Nil = Enum(3)

    //状态存储
    val stateReg = RegNext(zero)

    //状态转移逻辑
    switch(stateReg) {
        is (zero) {
            when(io.din) {
                stateReg := puls
            }
        }
        is (puls) {
            when(io.din) {
                stateReg := one
            } .otherwise {
                stateReg := zero
            }
        }
        is(one) {
            when(!io.din) {
                stateReg := zero
            }
        }
    }
    io.rinsingEdge := stateReg === puls
}
```  
上面代码表明了Moore版本的上升沿检测电路。该版本使用了是 Mealy 或直接编码版本两倍数量的 D 触发器。因此，生成的下一状态逻辑也比 Mealy 或直接编码版本更复杂。  

![](./pic/FSM3.png)  
该图表明了Mealy和Moore版本的上升沿检测FSM。你可以看到Mealy输出紧紧跟随上升边沿，当Moore输出在时钟tick后上升。我们也可以看到Moore输出是一个时钟周期的宽度，而Mealy输出一般小于一个时钟周期。  

从以上的例子，可以发现Mealy FSM是更好的，因为它需要更少的状态（和逻辑），并比Moore反应更快。但是，在一个Mealy机器中，组合电路可能在更大规模的制造上存在麻烦。首先，具有一串通信FSM，这个组合通路可以很长。其次，如果FSM的通信形成一个圆圈，会造成组合回馈，在同步设计造成错误。由于具有状态寄存器的组合通路的一个切割形成的Moore FSM，上述问题在Moore FSM通信不存在。  

总结来说，Moore FSM在状态机间通信的组合是更好的，他们比Mealy FSM更加稳定。使用Mealy FSM只是当关注在相同周期的反应下更为重要。  

## 8.4练习