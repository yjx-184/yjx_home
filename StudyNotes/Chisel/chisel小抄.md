

# chisel3.6快捷参考卡
## 该卡运算符号
c、p、x、y 是 Chisel 数据类型；n、m 是 Scala 整型；w(x)、w(y) 分别是 x 和 y 的位宽；minVal(x)、maxVal(x) 是 x 的最小值或最大值。  

## chisel关键词一览
### 1.基本数据类型 
**Bool:**  布尔类型，表示逻辑值(true或false)。  
**UInt:** 无符号整数类型，表示无符号整数。  
**SInt:** 有符号整数类型，表示带符号整数。  
**ChiselEnum:** 枚举类型，用于定义有限集合中的值（例如状态机的状态）。  
**Clock:** 时钟信号类型，用于表示时钟信号。  
**Reset:** 复位信号类型，用于表示复位信号。  
**AsyncReset:** 异步复位信号类型，用于表示异步复位信号。  
**Bundle:** 用于定义一个具有多个字段的复合数据类型。  
**Vec:** 向量类型，用于表示一组相同类型的信号。  
**Record:** 类似于Bundle，但是提供更多的灵活性，允许为字段指定不同的类型和宽度。  

### 2.硬件资源
**Reg:** 寄存器类型，表示带有状态的存储单元。  
**Mem:** 存储器类型，表示具有读取和写入功能的存储单元。  
**Wire:** 线网类型，表示没有状态的组合逻辑。  
**IO:** 用于定义模块的输入输出接口，通常用```IO(new Bundle {...})```来定义。  

### 3.输入输出类型
**Input:** 用于定义模块的输入端口。  
**Output:** 用于定义模块的输出端口。  
**Flipped:** 用于翻转端口的方向，将输入变为输出，或将输出变为输入。  

### 4.控制语句
**when:** 条件语句，类似于if，用于实现条件逻辑。  
**elsewhen:** when的扩展，用于在条件不成立时处理其他条件。  
**otherwise:** when的扩展，用于处理其他情况，相当于else。  
**switch:** 用于多条件选择，相当于scala中的match语句，用于实现多分支选择。  
**is:** 用于匹配某种条件，在switch或is语句判断值。  

### 5.模块类型 
**Module:** chisel中的模块，用于描述硬件设计的基本单元。  
**RawModule:** 原始模块类型，提供更多底层操作，通常用于一些需要更直接控制硬件设计的场景。  
**ExtModule:** 外部模块类型，表示与外部硬件或IP核连接的模块。  

## 使用scala的val来创建线网、实例等
```
val x = Wire(UInt())    //创建一个无符号整数类型的线网x
val y = x               //通过线网x驱动线网y
```  
## 更多构造器
**Bool()** ：Bool生成器，用于生成一个布尔类型。  
**true.B or false.B** ：布尔字面量。  
**UInt()** ：用于生成无符号整数类型。  
**UInt(32.W)** ：表示32位宽度的无符号整数。  
**29.U(6.W)** ：表示宽度为6的无符号字面量，值为29.  
**"hdead".U** ：表示16位宽度的无符号字面量，值为 0xDEAD。  

**BigInt("12346789ABCDEF", 16).U** ：用于表示一个大范围的无符号字面量。  
（不要使用 Scala Int 来创建字面量）

**SInt()** ：用于生成有符号整数类型。  
**SInt(64.W)** ：表示64位宽度的有符号整数。  
**-3.S** ：表示有符号整数字面量，值为-3.  
**3.S(2.W)** ：表示宽度为2位的有符号整数字面量，值为3.  

## 构造状态元素、寄存器
**Reg(UInt()):** 创建一个UInt寄存器。  
**RegInit(7.U(32.W)):** 32位寄存器，初始值为7。  
**RegNext(nextValue):** 寄存器在上升沿更新，且没有初始值。  
**RegNext(nextValue,3.U(32.W)):** 寄存器在上升沿更新，但初始值为3.  
**RegEnable(nextVal, enable):** 寄存器在上升沿更新，并且带有使能门。  
**RegEnable(next, init, enable):** 寄存器在上升沿更新，同时具有初始值和使能。  

## ChiselEnum
ChiselEnum 是 Chisel 中用于定义枚举类型的工具。它允许你为有限数量的状态或选项定义符号常量，通常用于状态机或其他需要有限集合值的场景。  
```
object Op extends ChiselEnum {
    val load = Value(0x03.U)
    val imm = Value(0x013.U)
    ...
    val jal = Value(0x6f.U)
}
when (foo === Op.load)
{...}
.elsewhen(foo===Op.imm)
{...}
```  
## Aggregates（聚合类型） – Bundles and Vecs
### Anonymous bundle（匿名bundle）  
```
val myB = new Bundle (
    val myBool = Bool()
    val myInt = UInt(5.W)
)
```  
### Bundle class
```
class MyBundle extends Bundle {
    val myBool = Bool()
    val myInt = UInt(5.W)
}
val myB = new MyBundle
```  
### Extending a Bundle
```
class MyExtendeBundle extends MyBundle {
    val newField = UInt(10.W)
}
```  
### 带有方向的 Bundle（默认方向是 Output）
原文：Bundle with directions (default directionis Output)   
```
class MyBundle extends Bundle {
    val in = Input(Bool())
    val myInt = Output(UInt(5.W))
}
```  
### Create IO from bundle
```
val x = IO(new MyBundle)
```  

### 递归翻转 io 中的输入/输出方向
原文：Recursively flip input/output in io  
```
val fx = IO(Fliepped(new MyBundle))
```  
### 强制将方向统一为相同的方向
原文：Coerce direction to all the same direction  
```
val fx = IO(Output(new MyBundle))
```  

### 通过点（.）访问元素
原文：Access elements via dots  
```
val int1 = myB.myInt
myB.myBool := true.B
```  

## Vec构造器
**Vec(size: Int, typeGen: Data)：**创建一个类型为 typeGen 的 Vec，大小为 size。  
**VecInit.fill(size: Int, hwGen: Data)：** 创建一个 Vec 并初始化为 hwGen。  
**VecInit.tabulate(size: Int) { i => hwGen: Data }：** 创建一个 Vec，其中每个元素是通过 i 创建的 hwGen。hwGen 可以使用索引 i 来生成每个元素。  
**注意：** 始终创建 Reg(Vec*(...))，而不是 Vec*(...Reg())（是寄存器的 Vec，而不是 Vec 的寄存器）。  

**访问 Vec 元素** 
x := myVec(index: UInt) or myVec(index: Int)  
myVec(index: UInt) or myVec(index: Int) := y

**示例：** 初始化一个包含31个32位宽UInt元素的Vec，并将每个元素初始化为0.  
```
val regfile = RegInit(VecInit(Seq.fill(31)(0.U(32.W))))
```  

## Vec 上的特殊方法
**.forall(p: T => Bool): Bool** 对所有元素应用AND，表示所有元素是否满足条件p。  
**.exists(p: T => Bool): Bool** 布尔字面量。  
**.contains(x: T): Bool** 如果当前集合包含元素x，则返回true。  
**.count(p: T => Bool): UInt** 计算满足条件p为true的元素个数。  
**.indexWhere(p: T => Bool): UInt** 返回第一个满足条件p为true的索引。  
**.lastIndexWhere(p: T => Bool): UInt** 返回最后一个满足条件p为true的元素的索引。  
**.onlyIndexWhere(p: T => Bool): UInt** 返回最后一个满足条件p为true的元素的索引。  

## 连接说明（c 是消费者，p 是生产者）
**c := p** 基本连接，p 驱动 c。即 p 的输出连接到 c 的输入。  
**c :#= p** （强制单向连接）：将 p 中的所有成员连接到 c，不考虑对齐方式。即使它们的对齐方式不同，所有成员也会进行连接。  
**c :<= p** （对齐连接）：将 p 中所有未翻转（非 Flipped）的成员连接到 c 中对齐的成员。即仅连接对齐的、未翻转的成员。  
**c :>= p** 翻转连接方向）： 将 c 中所有翻转的成员连接到 p 中。  
**c :<>= p** （双向操作符）： 将 p 中所有对齐的 c 成员连接到 c 中；将 c 中所有翻转的 p 成员连接到 p 中。  
**.squeeze** 允许截断。  
**.waive** 允许缺失连接。  

## 数据上的操作符
```
                说明                                宽度
!x              取反                                1
x && y          与                                  1
x || y          或                                  1
x(n)            提取位，0 是最低有效位（LSB）           1
x(hi,lo)        提取位域                            hi - lo + 1
x << y          动态左移                            w(x) + maxVal(y)
x >> y          动态右移                            w(x) - minVal(y)
x << n          静态左移                            w(x) + n
x >> n          静态右移                            w(x) - n
Fill(n,x)       将 x 复制 n 次                      n * w(x)
Cat(x, y)       连接位                              w(x) + w(y)
Mux(c, x, y)    如果 c，则 x；否则 y                max(w(x), w(y))
~x              按位取反                            w(x)
x & y           按位与                              max(w(x), w(y))
x | y           按位或                              max(w(x), w(y))
x ^ y           按位异或                            max(w(x), w(y))
x === y         相等（全等）                        1
x =/= y         不等                                1
x + y           加法                                max(w(x),w(y))
x +% y          加法（另一种形式）                      max(w(x),w(y))
x +& y          加法（可能重复表示）                    max(w(x),w(y))+1
x - y           减法                                max(w(x),w(y))
x -% y          减法（另一种形式）                      max(w(x),w(y))
x -& y          减法（可能重复表示）                    max(w(x),w(y))+1
x * y           乘法                                w(x)+w(y)
x / y           除法                                    w(x)
x % y           取模                                    bits(maxVal(y)-1)
x > y           大于                                    1
x >= y          大于或等于                              1
x < y           小于                                    1
x <= y          小于或等于                              1
x >> y          算术右移                                w(x) - minVal(y)
x >> n          算术右移（重复）                        w(x) - n
x.andR          按位与约简                              1
x.orR           按位或约简                              1
x.xorR          按位异或约简                            max(w(x), w(y))
```  

## chisel代码生成
函数提供了代码块抽象。那些实例化或返回chisel类型的scala函数被称为代码生成器。另外：scala的if和for可以用于控制硬件生成，它们等价于verilog的if和for。
```
val number = Reg(if(canBeNegative) SInt() else UInt())
```  
这将根据scala变量canBeNegative的值，创建一个SInt 或 UInt 类型的寄存器。  

### 使用 when 构造代替单独的多路复用（mux）
```
when (condition1) {
    x := y
} .elseWhen (condition2) {
    x := x & y
    z := y
} .otherwise {
    x := z
}
```  

### 模块参数化
使用scala集合方法，在输入和输出之间插入n个类型为payload的寄存器。  
```
class Delay(n: Int, payloadType: Data) extends Module {
    val in = IO(Input(payloadType))
    val out = IO(Output(payloadType))
    out := (0 until n).foldLeft(in) {
        case (last, x) => RegNext(last)
    }
}
```  
### 实例化并连接到子模块
```
class Parent(n: Int, payloadType: Data) extends Module {
    val in = IO(Input(payloadType))
    val out = IO(Output(payloadType))
    val child = Module(new Delay(n, payloadType))
    child.in := in
    out := child.out
}
```  

## 类型转换
.asTypeOf 是硬件类型转换（适用于硬件数据或 Chisel 类型）。  
```
0.U.asTypeOf(new MyBundle())
```  
这表示将 0.U（一个无符号常量）转换为 MyBundle 类型的硬件信号。  

chiselTypeOf(...) 用于复制硬件的类型、参数和方向。  
```
val foo = IO(chiselTypeOf(bar))
```  
这表示将 bar 的类型（包括参数和方向）复制给 foo，并作为 IO 类型的接口。  

## 标准库 – 位检查
```
操作符                                  return     说明
PopCount(in:Bits)                       UInt    输入中热位（= 1）的数量
PopCount(in:Seq[Bool])                  UInt    输入中热位（= 1）的数量
Reverse(in:UInt)                        UInt    反转输入的位顺序
UIntToOH(in:UInt, [width:Int])          Bits    输入的one-hot 编码宽度输出宽度
OHToUInt(in:Bits)                       UInt    输入的 one-hot 的 UInt 表示
OHToUInt(in: Seq[Bool])                 UInt    输入的 one-hot 的 UInt 表示
PriorityEncoder(in:Bits)                UInt    输入中最低有效 1 的位置
PriorityEncoder(in:Iterable[Bool])      UInt    输入中最低有效 1 的位置
PriorityEncoderOH(in:Bits)              UInt    输入中热位的位位置
Mux1H(sel: Seq[Bool], in: Seq[Data])    Data    One-hot 多路复用器
Mux1H(sel: UInt, Seq[Data])             Data    One-hot 多路复用器
Mux1H(sel:UInt, in: UInt)               Data    One-hot 多路复用器
PriorityMux(in:Iterable[Bool,Bits])     Bits    优先级多路复用器

PriorityMux(sel:Bits/Iterable[Bool],    Bits    一个多路复用器树，使用 one-hot 选择
in:Iterable[Bits])                              或多个选择（其中优先选择第一个输入）
```  

## 标准库 – 有状态
### Counter(n: Int): Counter (简单计数器)
```
val c = new Counter(n)
val wrap = WireInit(false.B)
when(cond) { wrap := c.inc() } // .inc 在计数器溢出时返回 true

```  
### Counter(cond: UInt, n: Int): (UInt, Bool)
```
val countOn = true.B // 每个时钟周期增加计数器
val (counterValue, counterWrap) = Counter(countOn, 4)
when (counterValue === 3.U) {
  ...
}
```  
### Counter(r: Range, enable: Bool, reset: Bool): (UInt, Bool)
```
val (counterValue, counterWrap) = Counter(0 until 10 by 2)
when (counterValue === 4.U) {
  ...
}
```  
### LFSR（线性反馈移位寄存器）
LFSR(width: Int, increment: Bool, seed: Option[BigInt]): UInt  
```
val pseudoRandomNumber = LFSR(16)
```  

### 移位寄存器（ShiftRegister）
ShiftRegister(in: Data, n: Int[, en: Bool]): Data  
添加 n 个寄存器。  
```
val regDelayTwo = ShiftRegister(nextVal, 2, ena)
```  

## 标准库 – 接口
### DecoupledIO(gen: Data):
使用一个 ready-valid 接口封装 Bundle。  
接口：  
.ready：只读的 Bool 类型，表示是否准备好读取数据。  
.valid：Bool 类型，表示数据是否有效。  
.bits：有效负载数据。  

### ValidIO(gen: Data):
为 gen 类型的数据提供一个 valid 接口封装。  
接口：  
.valid：Bool 类型，表示数据是否有效。  
.bits：有效负载数据。  

### Queue(gen: Data, entries: Int, pipe: Boolean, flow: Boolean, useSyncReadMem: Boolean, hasFlush: Boolean):  
一个队列模块，提供了多个配置选项，控制数据存储、流控制、同步读取和刷新等行为。  
接口：  
io.enq：Flipped 的 ReadyValid[gen]，用于输入数据。  
io.deq：ReadyValid[gen]，用于输出数据。  
```
val q = (new Queue(UInt(), 16))
q.io.enq <> producer.io.out
consumer.Module io.in <> q.io.deq

```  
### Pipe(enqValid: Bool, enqBits: Data, [latency: Int]) 或 Pipe(enq: ValidIO, [latency: Int]):
用于延迟输入的模块。  
接口：  
io.in：Flipped 的 ReadyValid[gen]，表示输入数据。  
io.out：ReadyValid[gen]，表示输出数据。  
```
val foo = Module(new Pipe(UInt(8.W)), 4)
pipe.io.enq := producer.io
consumer.io := pipe.io.deq
```  

### Arbiter(gen: Data, n: Int):
连接多个生产者到一个消费者。  
接口：  
io.in：一个 Vec 类型的输入信号（Flipped 的 ReadyValid[gen]）。  
io.out：ReadyValid[gen]，表示消费者的输出。  

变种：  
RRArbiter（轮询仲裁器）  
LockingArbiter（锁定仲裁器）  
```
val arb = Module(new Arbiter(UInt(), 2))
arb.io.in(0) <> producer0.io.out
arb.io.in(1) <> producer1.io.out
consumer.io.in <> arb.io.out

```  
## 定义与实例
```
@instantiable
class Child extends Module {
    @public val in = IO(Input(Bool()))
    @public val out = IO(Output(Bool()))
    out := in
}
class Parent(n: Int, payloadType: Data) extends Module {
    val childDef = Definition(new Delay(n, payloadType))
    val in = IO(Input(payloadType))
    val out = IO(Output(payloadType))
    val child = Instance(childDef)
    child.in := in
    out := child.out
}
```  
