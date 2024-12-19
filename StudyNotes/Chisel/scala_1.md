- [scala的介绍](#scala的介绍)
  - [介绍](#介绍)
    - [scala简介](#scala简介)
    - [函数式编程的量大核心理念](#函数式编程的量大核心理念)
    - [scala的特点](#scala的特点)
      - [scala是兼容的](#scala是兼容的)
      - [scala是精简的](#scala是精简的)
      - [scala是高级的](#scala是高级的)
      - [scala是静态类型的](#scala是静态类型的)
- [scala入门](#scala入门)
  - [定义变量](#定义变量)
    - [val](#val)
    - [var](#var)
  - [定义函数](#定义函数)
  - [使用类型参数化数组](#使用类型参数化数组)
  - [使用列表](#使用列表)
  - [使用元组](#使用元组)
  - [使用集和映射](#使用集和映射)
  - [识别函数式编程风格](#识别函数式编程风格)
- [类和对象](#类和对象)
  - [类、字段和方法](#类字段和方法)
  - [分号判断](#分号判断)
  - [单例对象](#单例对象)
  - [scala应用程序](#scala应用程序)
  - [App特质](#app特质)
- [基础类型和操作](#基础类型和操作)
  - [字符串字面量](#字符串字面量)
  - [字符串插值](#字符串插值)
- [函数式对象](#函数式对象)
  - [Rational类的规格定义](#rational类的规格定义)
  - [构建Rational](#构建rational)
  - [重新实现toString方法](#重新实现tostring方法)
  - [检查前置条件](#检查前置条件)
  - [添加字段](#添加字段)
  - [自引用](#自引用)
  - [辅助构造方法](#辅助构造方法)
  - [私有字段和方法](#私有字段和方法)
  - [定义操作符](#定义操作符)
  - [scala中的标识符](#scala中的标识符)
  - [方法重载](#方法重载)
  - [隐式转换](#隐式转换)
- [内建的控制结构](#内建的控制结构)
  - [if表达式](#if表达式)
  - [while循环](#while循环)
  - [for表达式](#for表达式)
    - [遍历集合](#遍历集合)
    - [过滤](#过滤)
    - [嵌套迭代](#嵌套迭代)
    - [中途变量绑定](#中途变量绑定)
    - [产出一个新的集合](#产出一个新的集合)
  - [用try表达式实现异常处理](#用try表达式实现异常处理)
    - [抛出异常](#抛出异常)
    - [捕获异常](#捕获异常)
    - [finally字句](#finally字句)
    - [交出值](#交出值)
  - [match表达式](#match表达式)
  - [没有break和continue的日子](#没有break和continue的日子)
  - [变量作用域](#变量作用域)
  - [对指令式代码进行重构](#对指令式代码进行重构)
- [函数和闭包](#函数和闭包)
  - [方法](#方法)
  - [局部函数](#局部函数)
  - [一等函数](#一等函数)
  - [函数字面量的简写形式](#函数字面量的简写形式)
  - [占位符语法](#占位符语法)
  - [部分应用的函数](#部分应用的函数)
  - [闭包](#闭包)
  - [特殊的函数调用形式](#特殊的函数调用形式)
  - [尾递归](#尾递归)
    - [跟踪尾递归函数](#跟踪尾递归函数)
    - [尾递归的局限](#尾递归的局限)
- [组合和继承](#组合和继承)
  - [抽象类](#抽象类)
  - [定义无参方法](#定义无参方法)
  - [扩展类](#扩展类)
  - [重写方法和字段](#重写方法和字段)
  - [定义参数化字段](#定义参数化字段)
  - [调用超类构造方法](#调用超类构造方法)
  - [使用override修饰符](#使用override修饰符)
  - [多态和动态绑定](#多态和动态绑定)
  - [声明final成员](#声明final成员)
  - [使用组合和继承](#使用组合和继承)
  - [实现above、beside和toString](#实现abovebeside和tostring)
  - [定义工厂对象](#定义工厂对象)



# scala的介绍
## 介绍
### scala简介
&emsp;&emsp;scala是面向对象和函数式编程的结合。在scala中，函数值就是对象，而函数的类型就是可被子类继承的类。
### 函数式编程的量大核心理念
&emsp;&emsp;第一个理念： 函数是一等的值。在函数式编程语言中，函数值的低位跟整数、字符串等是相同的。可以将函数作为参数传递给其他函数，作为返回值返回它们，或者将它们保存在变量里。还可以在函数中定义另一个函数，就像在函数中定义整数那样。也可以在定义函数时不指定名字。  
&emsp;&emsp;第二个理念： 是程序中的操作应该将输入映射成输出值，而不是当场in place 修改数据。该理念的另一种表述是方法不应该有副作用。方法只能通过接收入参和返回结果这两种方式与外部环境通信。举例来说，java的string类的replace方法便符合这个描述：它接收一个字符串（对象本身）、两个字符，交出一个新的字符串，其中所有出现的入参第一个字符都被替换成了入参的第二个字符。调用replace并没有其他的作用。**像这样的方法被认为是“指称透明的”，意思是对于任何给定的输入，该方法调用都可以被其结果替换，同时不会影响程序的语义。**
### scala的特点
#### scala是兼容的 
&emsp;&emsp;能够与java无缝互调，scala重度复用java的类型，也会对java原生的类型进行“再包装”。  
#### scala是精简的
&emsp;&emsp;scala编写的程序通常都比较短。有些代码根本不用写，类库都帮忙写好了。scala提供了大量的工具来定义功能强大的类库。可以捕获那些公共的行为，并将它们抽象出来。  
#### scala是高级的
&emsp;&emsp;scala提供的帮助在于提升接口设计的抽象级别，能够让人更好的管理复杂度。scala的函数字面量非常轻。  
#### scala是静态类型的
&emsp;&emsp;静态的类型系统根据变量和表达式所包含和计算的值的类型来对它们进行归类。scala和其他语言相比，一个重要的特点是它拥有非常先进的静态类型系统。scala不仅拥有和java类似的允许嵌套类的类型系统，它还允许使用泛型来对类型进行参数化，用交集来组合类型，以及用抽象类型来隐藏类型的细节。scala很好的解决了静态类型的两个常见痛点：通过类型推断规避了过于啰嗦的问题，通过模式匹配以及其他编写和组合类型的新方式避免了死板。

# scala入门
## 定义变量
### val
&emsp;&emsp;val与java的final变量类似，一旦初始化就不能被重新赋值。  

### var
&emsp;&emsp;var与java的非final变量类似，在整个生命周期内var可以被重新赋值

## 定义函数
函数的定义从**def** 开始。  
```
def max(x: Int, y: Int) = {
    if (x > y) x
    else y
}
```

## 使用类型参数化数组
&emsp;&emsp;在scala中，可以用new来实例化对象或类的实例。当你用scala实例化对象时，可以用值和类型来对其进行参数化。参数化的意思是在创建实例对实例做“配置”。可以用值来参数化一个实例，做法是在构造方法的括号中传入对象参数。例如，scala代码将实例化一个新的java.math.BigInteger,并用值“12345”来对它进行参数化：
```
val big = new java.math.BigInteger("12345")
```

## 使用列表
&emsp;&emsp;函数式编程的重要理念之一是方法不能有副作用。一个方法唯一要做的是计算并返回一个值。这样做的好处是方法不再互相纠缠在一起，因此变得可靠、更易复用。  
创建列表的方法：  
```
val oneTwoThree = List(1, 2, 3)
```  

&emsp;&emsp;List有方法叫“:::”,用于列表拼接。  

&emsp;&emsp;“::”表示在已有列表的最前面添加一个新的元素。  

&emsp;&emsp;表示空列表的快捷方式是Nil

## 使用元组
&emsp;&emsp;一个又用的容器对象是元组tuple。元组可以容纳不同类型的元素。元组的用法很简单：要实例化一个新的元组，只需要将对象放在圆括号当中，用逗号隔开即可。一旦实例化好一个元组，可以用英文句号、下画线和从1开始的序列号来访问每一个元素。  
```
val pair = (99, "Luftballons")
        println(pair._1)
        println(pair._2)
```  

## 使用集和映射
数组永远是可变的，列表永远是不可变的。scala提供了集set和映射map的可变和不可变的不同选择。对于集和映射而言，scala通过不同的类继承关系来区分可变和不可变版本。  

创建不可变集的默认方式：  
```
var jetSet = Set("Boeing", "Airbus")
jetSet += "Lear"
println(jetSet.contains("Cessna"))
```  

可变集需要做一次引入import:  
```
import scala.collection.mutable
val movieSet = mutable.Set("Hitch", "Poltergeist")
movieSet += "Shrek"
println(movieSet)
```  

不可变的映射：  
```
val romanNumeral = Map(
    1 -> "I", 2-> "II", 3 -> "III"
)
println(romanNumeral(3))
```

可变映射：  
```
import scala.collection.mutable
val treasureMap = mutable.Map[Int, String]()
        treasureMap += (1 -> "Go to island.")
        treasureMap += (2 -> "Find big X on ground.")
        treasureMap += (3 -> "Dig.")
        println(treasureMap(2))
```  

## 识别函数式编程风格
一个显著的标志是：如果代码包含任何var变量，它通常是指令式风格；而如果代码完全没有var，那么可能就是函数式的。  

# 类和对象
## 类、字段和方法
&emsp;&emsp;类是对象的蓝本。一旦定义好了一个类，就可以用 new 关键字从这个类蓝本创建对象。在类定义中，可以填入字段和方法，这些被统称为成员。通过val,car定义的字段是指向对象的变量，通过def定义的方法则包含了可执行的代码。  
```
//这是一个类定义
class ChecksumAccumulator {
    var sum = 0
}

//实例化
val acc = new ChecksumAccumulator
val csa = new ChecksumAccumulator
```  
另一个最终版本：  
```
class ChecksumAccumulator {
    private var sum = 0
    def add(b: byte) : Unit = { sum += b}
    def checksum() : Int = ~(sum & 0xFF) + 1
}
```  

&emsp;&emsp;这里的private表示私有，用来防止外部直接访问字段。私有字段只能被定义在同一个类中的方法访问。公共访问public是scala的默认访问级别。  
&emsp;&emsp;比较好的做法是，如同上面代码对类中声明为公有的方法显式地给出结果类型。对于结果类型为Unit的方法，如ChecksumAccumulator的add方法，执行的目的是为了得到其副作用。副作用通常来说指的是改变方法外部的某种状态或者执行I/O的动作。对本例子的add而言，其副作用是给usm重新赋值。那些仅仅因为其副作用而被执行的方法被称作过程。  

## 分号判断
&emsp;&emsp;在scala中，分号是可选的不是必需的。如果是同一行包含多条语句，那么分号就是必要的了。  

## 单例对象
&emsp;&emsp;scala比java更面向对象的一点是scala的类不允许有静态成员。对此类使用场景，scala提供了单例对象。单例对象的定义看上去跟类定义很像，只不过class关键字被换成了object关键字。当单例对象跟某个类共用同一个名字时，它被称作这个类的伴生对象。必须在同一个源码文件中定义类和类的伴生对象。同时，类又叫作这个单例对象的伴生类。**类和它的伴生对象可以互相访问对方的私有成员。** 单例对象不仅仅用来存放静态方法。它是一等的对象。可以把单例对象的名称想像成附加在对象身上的“名字标签”。  
&emsp;&emsp;定义单例对象并不会定义类型（在scala的抽象层是这样的）。当只有ChecksumAccumulator的对象定义时，并不能定义一个类型为ChecksumAccumulator的变量。确切的说，名为ChecksumAccumulator的类型是由这个单例对象的伴生类来定义的。  
&emsp;&emsp;类和单例对象的一个区别是单例对象不接收参数，而类可以。由于你没法用new实例化单例对象，也就没有任何手段来向它传参。每个单例对象都是通过一个静态变量引用合成类的实例来实现的，因此单例对象在初始化的语义上跟java的静态成员是一致的。

## scala应用程序
&emsp;&emsp;要运行一个scala程序，必须提供一个独立对象的名称。这个独立对象需要包含一个main方法，该方法接收一个Array[String]作为参数，结果类型为Unit。任何带有满足正确签名的main方法的独立对象都能被用作应用程序的入口。  

## App特质
&emsp;&emsp;scala提供了一个特质scala.App，可以帮助节省敲键盘的动作。如：  
```
import ChecksumAccumulato.calcuate
object FallWinterSpringSummer extends App {
    for (Season <- List("fall", "winter", "spring"))
        println(season + ":" + calculate(season))
}
```
# 基础类型和操作
## 字符串字面量
&emsp;&emsp;字符串字面量由双引号包起来的字符组成：  
```
scala> val hello = "hello"
hello: String = hello
```
&emsp;&emsp;双引号中字符的语法跟字符字面量一样。比如：  
```
scala> val escapes = "\\\"\'"
escapes: String = \"'
```

## 字符串插值
&emsp;&emsp;scala包括了一个灵活的机制来支持字符串插值，允许在字符串字面量中嵌入表达式。如：  
```
val name = "reader"
println(s"Hello, $name!")
```
&emsp;&emsp;表达式s"Hello, $name!"是一个被处理的字符串字面量。由于字母s出现在首个双引号前，scala将使用s这个字符串插值器来处理该字面量。s插值器会对内嵌的每个表达式求值，对求值结果调用toString，替换掉字面量中那些表达式。因此，s"Hello, $name!"会交出"Hello,reader!"  
&emsp;&emsp;在被处理的字符串字面中，可以随时用美元符$开始一个表达式。如果表达式包含了非标识符字符，就必须将它放到花括号内，左花括号需要紧跟美元符。如：  
```
scala> s"The answer is ${6 * 7}
res0: String = The answer is 42
```
&emsp;&emsp;scala默认还提供了另外两种字符串插值器：raw和f。raw字符串插值器的行为和s类似，不过它不识别字符转移序列。比如，如下语句将打印四个反斜杆而不是两个：  
```
println(raw"\\\\")
```  
&emsp;&emsp;f字符串插值器允许你给内嵌的表达式加上printf风格的指令。需要将指令放在表达式之后，以百分号%开始，使用java.util.Formatter中给的语法。如可以这样来格式化Pi：  
```
scala> f"${math.Pi}%.5f"
res1: String = 3.14159
```

# 函数式对象
## Rational类的规格定义
```
scala> val oneHalf = new Rational(1, 2)
oneHalf: Rational = 1/2  
```  

## 构建Rational
```
class Rational(n: Int, d: Int)
```
&emsp;&emsp;如果一个类没有定义体，并不需要给出空的花括号（想给也可以）。类名Rational后的圆括号中的标识符n和d称作类参数。scala编译器会采集到这两个类参数，并且创建一个主构造方法，接收同样的这两个参数。  
&emsp;&emsp;**注意：** 这个Rational示例突出显示了java和scala的一个区别。在java中，类有构造方法，构造方法可以接收参数；而在scala中，类可以直接接收参数，scala的表示法更为精简（类定义体内可以直接使用类参数，不需要定义字段并编写将构造方法参数赋值给字段的代码）。  

## 重新实现toString方法
&emsp;&emsp;toString的主要意图是帮助成需要在调试输出语句、日志消息、测试失败报告，以及解释器和调试器输出中给出相应的信息。可以使用Rational类添加toString方法来重写默认的实现，如：  
```
class Rational(n: Int, d: Int) {
    override def toString = s"$n/$d"
}
```  
&emsp;&emsp;在方法定义之前的override修饰符表示前一个方法定义被重写覆盖了。由于Rational（有理数）现在可以漂亮地显示了，我们移除了先前版本的Rational中拿端用于测试的println语句。现在在解释器中测试Rational的新行为：  
```
scala> val x = new Rational(1,3)
x: Rational = 1/3
```  

## 检查前置条件
&emsp;&emsp;可以对主构造方法定义一个前置条件，来对传入方法或构造方法的值进行约束。如分母不能为0,该方法是调用require：  
```
class Rational(n: Int, d: Int) {
    require(d != 0)
    override def toString = s"$n/$d"
}
```
&emsp;&emsp;require方法接收一个boolean的参数。如果传入参数为true，require会正常返回，否则会阻止对象的构建。  

## 添加字段
&emsp;&emsp;想要实现加法，需要添加两个字段，numer和denom，分别用类参数n和d的值初始化。还修改了toString和add方法的实现，使用这两个字段，而不是参数。
```
class Rational(n: Int, d Int) {
    require(d != 0)
    val numer: Int = n
    val denom: Int = d
    override def toString = "$numer/$denom"
    def add(that: Rational): Rational = 
        new Rational(
            numer * that.denom + that.numer * denom,
            denom * that.denom 
        ) 
}
```  
&emsp;&emsp;效果：  
```
scala> val oneHalf = new Rational(1,2)
oneHalf: Rational = 1/2

scala> val twoThirds = new Rational(2,3)
twoThirds: Rational = 2/3

scala> oneHalf add twoThirds
res2: Rational = 7/6
```  
&emsp;&emsp;现在还能实现以前做不到的事情，那就是从对象外部访问分子和分母的值。只需要访问公共的numer和denom字段即可：  
```
scala> val r = new Rational(1,2)
r: Rational = 1/2

scala> r.numer
res3: Int = 1

scala> r.denom
res4: Int = 2
```

## 自引用
&emsp;&emsp;关键字this指向当前执行方法的调用对象，当被用在构造方法里的时候，指向被构造的对象实例。举例来说，我们可以添加一个lessThan方法，来测试给定的Rational是否小于某个传入的参数：  
```
def lessThan(that: Rational) = 
    this.numer * that.denom < that.numer * this.denom
```  
&emsp;&emsp;在这里，this.numer指向执行lessThan调用的对象的分子。也可以省去this前缀，只写numer。这两种表示法都是等效的。  
&emsp;&emsp;再举例一个不能省去this，假定我们要给Rational添加一个max方法，返回给定的有理数和参数之间较大的那个：  
```
def max(that: Rational) = 
    if (this.lessThan(that)) that else this
```  
&emsp;&emsp;在这里，第一个this可以省去，单是第二个this代表了当测试返回false时该方法的结果；如果不写this，就没有可返回的结果了。  

## 辅助构造方法
&emsp;&emsp;有时需要给某个类定义多个构造方法。在scala中，主构造方法之外的构造方法称为辅助构造方法，如想要分母为1时，直接表示分子： 
辅助构造方法以def this(...)开始。 
```
class Rational(n: Int, d: Int) {
    require(d != 0)
    val numer: Int = n
    val denom: Int = d
    def this(n: Int) = this(n, 1)   //辅助构造方法
    override def toSrting = "$numer/$denom"
    def add(that: Rational): Rational = 
        new Rational(
            numer * that.denom + that.numer * denom,
            denom * that.denom
        )
}
```
&emsp;&emsp;在scala中，每个辅助构造方法都必须首先调用同一个类的另一个构造方法。换句话说，scala每个辅助构造方法的第一条语句都必须时这样的形式："this(...)"。被调用的这个构造方法要么是主构造方法，要么是另一个出现在发起调用的构造方法之前的另一个辅助构造方法。这个规则是净效应是scala的每个构造方法最终都会调用该类的主构造方法。这样一来，主构造方法就是类的单一入口。  

## 私有字段和方法
&emsp;&emsp;我们希望正规化，在得到结果的时候提供化简，就需要对分子和分母分别除以最大公约数，以下是实现方法：  
```
class Rational(n: Int, d: Int) {
    require(d != 0)
    private val g = gcd(n.abs, d.abs)
    val numer: Int = n / g
    val denom: Int = d / g
    def this(n: Int) = this(n, 1)   //辅助构造方法
    def add(that: Rational): Rational = 
        new Rational(
            numer * that.denom + that.numer * denom,
            denom * that.denom
        )
    override def toSrting = "$numer/$denom"
    private def gcd(a: Int, b: Int): Int = 
    if (b == 0) a else gcd(b, a % b)
}
```  
&emsp;&emsp;在这里我们添加了一个私有的字段g，并修改了numer和denom的初始化器（初始化器是初始化某个变量的代码。例如，用来初始化nemer的"n / g"）。由于g是私有的，我们只能从类定义内部访问它，从外面访问不到。我们还添加了一个私有的方法gcd，计算传入的两个Int参数的最大公约数。比如gcd（12,8）返回4.为了确保g永远是正数，我们传入n和d的绝对值，取绝对值使用abs方法。  

## 定义操作符
&emsp;&emsp;想要自然的使用算术操作符来操作，第一步是将add替换成通常的那个数学符号。这么做直截了当，因为在scala中 + 是一个合法的标识符。可以简单地定义一个名为+的方法。  
```
class Rational(n: Int, d: Int) {
    require(d != 0)
    private val g = gcd(n.abs, d.abs)
    val numer: Int = n / g
    val denom: Int = d / g
    def this(n: Int) = this(n, 1)   //辅助构造方法
    def + (that: Rational): Rational = 
        new Rational(
            numer * that.denom + that.numer * denom,
            denom * that.denom
        )
    def * (that: Rational): Rational = 
        new Rational(numer * that.numer, denom * that.denom)
    override def toSrting = "$numer/$denom"
    private def gcd(a: Int, b: Int): Int = 
    if (b == 0) a else gcd(b, a % b)
}
```  
结果如下：  
```
scala> val x = new Rational(1,2)
x: Rational = 1/2

scala> val y = new Rational(2,3)
y: Rational = 2/3

scala> x + y
res7: Rational = 7/6
```    
&emsp;&emsp;另一个值的注意的点是，按照scala的操作符优先级，对于Rational来说，*方法会比+方法绑得更紧。换句话说，涉及Rational的 + 和 * 操作，其行为会按照我们预期的那样：  
```
scala> x + x * y
res9: Rational = 5/6

scala> (x + x) * y
res10: Rational = 2/3

scala> x ( x * y)
res11: Rational = 5/6
```  
## scala中的标识符
&emsp;&emsp;scala遵循了java使用驼峰命名法命名标识法的传统。字段、方法参数、局部变量和函数的驼峰命名应该以小写字母打头，比如length、flatMap和s等。类和特质的驼峰命名应该以大写字母打头，例如BigInt、List和UnbalancedTreeMap  

## 方法重载
```
class Rational(n: Int, d: Int) {
    require(d != 0)
    private val g = gcd(n.abs, d.abs)
    val numer = n / g
    val denom = d / g
    def this(n: Int) = this(n, 1)
    def + (that: Rational): Rational = 
        new Rational(
            numer * that.denom + that.numer * denom,
            denom * that.denom
        )

    def + (i: Int): Rational = 
        new Rational(numer + i * denom, denom)

    def - (that: Rational): Rational = 
        new Rational(
        numer * that.denom - that.numer * denom,
        denom * that.denom
        )

    def - (i: Int): Rational = 
        new Rational(numer - i * denom, denom)

    def * (that: Rational): Rational = 
        new Rational(numer * that.numer, denom * that.denom)

    def * (i: Int): Rational = 
        new Rational(numer * i , denom)

    def / (that: Rational): Rational = 
        new Rational(numer * that.denom, denom * that.numer)

    def / (i: Int): Rational = 
        new Rational(numer, denom * i)

    override def toSting = "$numer/$denom"

    private def gcd(a: Int, b: Int): Int = 
    if (b ==0) a else gcd(b, a % b)
    
}
```
&emsp;&emsp;现在每个算术方法都有两个版本：一个接收有理数作为参数，另一个则接收整数。换句话说，每个方法名都哦被“重载”了，因为每个方法名都被用于多个方法。举例来说+这个方法名被同时用于接收Rational的方法和另一个接收Int的方法。在处理方法调用时，编译器会选取重载方法中正确匹配的入参类型的版本。  

## 隐式转换
scala可以创建一个隐式转换，在需要时自动将整数转换成有理数。可以往解释器里添加行：  
```
scala> implicit def intToRational(x: Int) = new Rational(x)
```
这将会定义一个从Int到Rational的转换方法。在方法名前面的implicit修饰符告诉编译器，可以在某些场景自动应用这些转换。  

# 内建的控制结构
&emsp;&emsp;scala只有为数不多的几个内建的控制结构：if、while、for、try、match和函数调用。  

## if表达式
和其他语言if没有区别，只是更简洁，使用val函数式风格。  
```
val filename = 
    if (!args.isEmpty) args(0) else "default.txt"
```  

## while循环
和其他语言while没有区别。  
以下是循环计算最大公约数
```
def gcdLoop(x: Long, y: Long):Long = {
    var a = x
    var b = y
    while (a != 0) {
        val temp = a
        a = b % a
        b = temp
    }
    b
}
```  
scala也有do-while循环，和while类似，只不过是在循环体之后执行条件检查。如示例用do-while来复述从标准输入读取的文本行，直到读到空行为止：  
```
var line = ""
do {
    line = readLine
    println("Read:" + line)
} while (line != "")
```    
另一种求两个数的最大公约数的方法，区别于gcdLoop指令式风格，用到了var和while循环，而gcd是更加具有函数式风格的，用到了递归。  
```
def gcd(x: Long, y: Long): Long = 
    if (y == 0) x else gcd(y, x % y)
```  
## for表达式  
### 遍历集合
&emsp;&emsp;用for能做到的最简单的事，是遍历某个集合的所有元素。
```
val filesHere = (new java.io.File(".")).listFiles
for (file <- filesHere)
    println(file)
```  
&emsp;&emsp;通过"file <- filesHere"这样的生成器语法，将会遍历filefHere的元素。  

### 过滤
&emsp;&emsp;有时不想完整地遍历集合，想把他过滤成一个子集。这时可以给for表达式添加过滤器filter，过滤器是for表达式的圆括号中的一个if字句。如：  
```
val filesHere = (new java.io.File(".")).listFiles
for (file <- filesHere if file.getName.endsWith(".scala"))
    println(file)
```  
&emsp;&emsp;想要随意包含更多的过滤器，直接添加if语句即可。  

### 嵌套迭代
&emsp;&emsp;如果添加多个<-字句，将得到嵌套的“循环”。如示例的for表达式有两个嵌套迭代。外部循环遍历filesHere，内部循环遍历每个以.scala结尾的file的fileLines(file)。  
```
def fileLines(file: java.io.FIle) = 
    scala.io.Source.fromFIle(file).getLines().toArray
def grep(pattern: String) = 
    for (
        file <- filesHere
        if file.getName.endsWith(".scala");
        line <- fileLines(file)
        if line.trim.matches(pattern)
    ) println(s"$file:${line.trim}")
    grep(".*gcd.*")
```  

### 中途变量绑定
&emsp;&emsp;前一例中line.trim重复了两次。这并不是一个无谓的计算，如果想要只计算一次，可以用 = 来将表达式的结果绑定到新的变量上。被绑定的这个变量引入和使用起来都跟val一样。  
```
def grep(pattern: String) = 
    for {
        file <- filesHere
        if file.getName.endsWith(".scala")
        trimmed = line.trim
        if trimmed.matches(pattern)
    } println(s"$file:$trimmed")
    grep(".*gcd.*")
```  

### 产出一个新的集合
&emsp;&emsp;虽然目前为止所有示例都是对遍历到的值进行操作然后忘掉它们，也完全可以在每次迭代中生成一个可以被记住的值。具体做法是在for表达式的代码体之前加上关键字yield。如：函数识别出.scala文件并将他们保存在数组中。  
```
def scalaFiles = 
    for {
        file <- filesHere
        if file.getName.endsWith(".scala")
    } yield file
```  
&emsp;&emsp;for表达式的代码体每次被执行，都会产出一个值，本例中就是file。当for表达式执行完毕后，其结果将包含所有交出的值，包含在一个集合当中。结果集合的类型基于迭代字句中处理的集合种类。在本例中，结果是Array[FIle]，因为filesHere是个数组，而交出的表达式类型为File。  
&emsp;&emsp;要小心yield关键字的位置。for-yield表达式的语法如下：  
&emsp;&emsp;for 字句 yield 代码体  
&emsp;&emsp;yield关键字必须出现在整个代码体之前。哪怕代码体是由花括号包起来的，也要将yield放在花括号之前，而不是在代码快最后一个表达式前面。

## 用try表达式实现异常处理
&emsp;&emsp;scala的异常处理跟其他语言类似。方法除了正常地返回某个值，也可以通过抛出异常终止执行。方法的调用方要么捕获并处理这个异常，要么自我终止，让异常传播到更上层调用方。异常通过这种方式传播，逐个展开调用栈，直到某个方法处理该异常或者没有更多方法为止。  

### 抛出异常  
&emsp;&emsp;在scala中抛出异常跟java看上去一样：  
```
throw new IllegalArgumentException
```  
&emsp;&emsp;虽然看上去有些自相矛盾，在scala中throw是一个有结果类型的表达式。如：  
```
val half = 
    if (n % 2 == 0)
        n / 2
    else
        throw new RuntimeException("n must be eveb")
```

### 捕获异常
&emsp;&emsp;可以使用如下例子来捕获异常。catch字句的语法之所以是这样的，为的是与scala的一个重要组成部分，**模式匹配** ，保持一致。  
```
import java.io.FIleReader
import java.io.FileNotFoundException
import java.io.IOException
try {
    val f = new FileReader("input.txt)
    //使用并关闭文件
} catch {
    case ex: FileNotFoundExeption => // 处理找不到文件的情况
    case ex: IOException => // 处理其他I/O错误
}
```
&emsp;&emsp;这个try-catch表达式跟其他带有异常处理的语言一样。首先代码体会被执行，如果抛出异常，则会依次尝试每个catch字句。  

### finally字句
&emsp;&emsp;可以将那些不论是否抛出异常都想执行的代码以表达式的形式包在finally字句里。例如，想要确保某个打开的文件要被正确关闭，哪怕某个方法因为抛出了异常而退出：  
```
import java.io.FileReader
val file = new FileReader("input.txt")
try {
    //使用文件
} finally {
    file.close() //关闭文件
}
```  
### 交出值
&emsp;&emsp;和scala的大多数其他控制结构一样，try-catch-finally最终返回一个值。如果没有异常抛出，整个表达式的结果就是try字句的结果；如果有异常抛出且被捕获时，整个表达式的结果就是对应的catch字句的结果；而如果有异常抛出但没有被捕获，整个表达式就没有结果。如果有finally字句，该字句计算出来的值会被丢弃。finally字句一般用来执行清理工作，比如关闭文件。通常来说，它们不应该改变主代码体或catch字句中计算出来的值。  
&emsp;&emsp;跟java一样，当finally字句包含一个显示的返回语句，或者抛出某个异常，那么这个返回值或异常将会“改写”任何在之前的try代码快或某个catch字句中产生的值。例如，在下面这个可以做成这样的函数定义中：  
```
def f(): INt = try return1 finally return 2
```  
交出值的例子：  
```
import java.net.URL
import java.net.MalformedURLException
def urlFOr(path: String) = 
    try {
        new URL(path)
    } catch {
        case e: MakfirnedURLException =>
            new URL("http://www.scala-lang.org")
    }

```    
调用f()得到2.相反如果是如下代码：  
```
def g(): Int = try 1 finally 2

```  
&emsp;&emsp;调用g()将得到1,这两个函数的行为都很可能让多数程序员感到意外。因此，最好避免在finally字句中返回值，最好将finally字句用来确保某些副作用发生，比如关闭一个打开的文件。  

##  match表达式
&emsp;&emsp;scala的match表达式可以让人从若干可选项中选择，就像其他语言中的switch语句那样。一般而言，match表达式让你用任意的模式来选择。抛开一般的形式不谈，目前我们只需要直到可以用match来从多个可选项中进行选择即可。  
```
val firstArg = if (args.length > 0) args(0) else ""
firstArg match {
    case "salt" => println("pepper")
    case "chips" => println("salsa")
    case "eggs" => println("bacon")
    case _ => println("hun?")
}
```  
&emsp;&emsp;scala的match表达式和java的switch相比，有一些重要的区别。其中一个区别是任何常量、字符串等都可以用作样例，而不仅仅限于java的case语句支持的整型、枚举和字符串常量。在上面的例子中，可选项是字符串。  
&emsp;&emsp;另一个区别是每个可选项中没有break。在scala中break是隐含的，并不会出现某个可选项执行完继续执行下一个可选项的情况。这通常是我们预期的（不会直通下一个可选项），代码因此变得更短，也避免了一类代码错误的源头。  
&emsp;&emsp;不过scala的match表达式跟java的switch相比显著的不同，在于match表达式会返回值。在前一例子中，match表达式的每个可选项都打印出一个值。如果将打印语句换成交出某个值，相应的代码也能工作，如下面例子所示。从这个match表达式得到的结果被保存在变量friend中。这样的代码不仅更短，它还将两件不同的事情解耦例如：首先选择食物，然后再将食物打印出来：  
```
val firstArg = if (!args.isEmpty) args(0) else ""
val friend = 
    firstArg match {
        case "salt" => "pepper"
        case "chips" => "salsa"
        case "eggs" => "bacon"
        case _ => "hun?"
    }
println(friend)
```
## 没有break和continue的日子
&emsp;&emsp;最简单的方法是使用if换掉每个continue，用布尔值换掉每个break。布尔值表示包含它的while循环是否继续。例如，假定你要检索参数列表，找一个以".scala"结尾但不以连字符开头的字符串。  
```
var i = 0
var foundIt = false
while (i < args.length && !foundIt) {
    if (!args(i).startsWith("-")) {
        if (args(i).endsWith(".scala"))
        foundIt = ture
    }
    i = i + 1
}
```  
使用递归的方法：  
```
def searchFrom(i: Int): Int = 
    if (i >= args.length) -1
    else if (args(i).startsWith("-")) searchFrom(i + 1)
    else if (args(i).endWith(".scala")) i
    else searchFrom(i + 1)
val i = searchFrom(0)
```

## 变量作用域
scala和java的区别在于，scala允许在嵌套的作用域内定义同名的变量，从概念上讲，解释器会对录入的每一条语句创建一个新的作用域，如下：  
```
val a = 1;
{
    val a = 2;
    {
        println(a)
    }
}
```  
这会打印出2.  

## 对指令式代码进行重构
&emsp;&emsp;打印乘法表，函数式风格：  
```
//以序列的形式返回一行
def makeRowSeq(row: Int) = 

    //遍历列号从1到10
    for (col <- 1 to 10) yield {

        //计算当前行列的乘积，并将转换成字符串
        val prod = (row * col).toString

        //根据乘积长度计算填充的空格
        val padding = " " * (4 - prod.length)
        padding + prod
    }

//以字符串形式返回一行
//调用函数生成当前行的数字序列，通过mkString拼接为一个字符串
def makeRow(row: Int) = makeRowSeq(row).mkString

//以每行占一个文本行的字符串的形式返回表格
def multiTable() = {
    val tableSeq =  // 行字符串的序列
        for (row <- 1 to 10)
        yield makeRow(row)
    tableSeq.mkString("\n")
}
```  

# 函数和闭包
&emsp;&emsp;scala提供了好几种java中没有的方法来定义函数。除了方法，还有嵌套函数、函数字面量和函数值。  
## 方法
&emsp;&emsp;定义函数最常用的方式是作为某个对象的成员，这样的函数被称为**方法**。例如下面展示了两个方法，合在一起读取给定名称的文件并打印出所有超过指定长度的行。在被打印的每一行之前都加上该行所在的文件名。  
```
//导入scala标准库中用于处理文件输入的io.Source对象
import scala.io.Source

//定义一个对象LongLines包含处理文件和处理行的方法
object LongLines {

    //处理指定文件，filename为文件名，width为指定的行宽限制
    def processFile(filename: String, width: Int) = {

        //打开文件并获取其内容作为source对象
        val source = Source.fromFile(filename)

        //遍历文件中的每一行
        for (line <- source.getLines())

            //调用私有方法processLine来处理每一行
            processLine(filename, width, line)
    }

    //定义一个私有方法来处理每一行
    //filename为文件名，width为行宽限制，line为当前行内容
    private def processLine(filename: String,
        width: Int, line: String) = {

            //如果当前行的长度操作指定的宽度
            if (line.length > width)

                //打印文件名和去掉首尾空格的行内容
                println(filename + ":" + line.trim)
        }
}
```
## 局部函数
&emsp;&emsp;可以在某个函数内部定义函数，就如同局部变量一样，这样的局部函数只在包含它的代码快中可见。  

## 一等函数
&emsp;&emsp;scala支持一等函数。不仅可以定义函数并调用它们，，还可以用匿名的字面量来编写函数并将它们作为值进行传递。函数字面量被编译成类，并在运行时实例化成函数值。因此，函数字面量和函数值的区别在于，函数字面量存在于源码，而函数值以对象形式存在于运行时。这跟类（源码）与对象（运行时）的区别很相似。  

## 函数字面量的简写形式
&emsp;&emsp;scala提供了多个省去冗余信息，更简要地编写函数的方式。  
&emsp;&emsp;一种是让代码变得更简要的方式是略去参数类型声明。  
&emsp;&emsp;另一种是去除源码中无用字符的方式是省去某个靠类型推断的参数两侧的圆括号。  

## 占位符语法
为了让函数字面量更加精简，还可以使用下画线作为占位符，用来表示一个或多个参数，只要满足每个参数只在函数字面量中出现一次即可。例如， _ > 0是一个非常短的表示法，表示一个检查某个值是否大于0的函数：  
```
scala> someNumbers.filer(_ > 0)
res7: List[Int] = List(5, 10)
```
## 部分应用的函数
&emsp;&emsp;虽然前面的例子用下画线替换掉单独的参数，也可以用下画线替换整个参数列表。例如，对于println(_),也可以写成println _ 。  

## 闭包
&emsp;&emsp;本章到目前为止，所有的函数字面量示例，都只是引用了传入的参数。例如，在(x: Int) => x > 0 中,唯一在函数体x > 0 中引用到的变量是x，即这个函数的唯一参数。不过也可以引用其他地方定义的变量：  
```
(x: Int) => x + more
```  
&emsp;&emsp;这个函数将"more"也作为入参，不过more是哪里来的？从这个函数的角度来看，more是一个自由变量，因为函数字面量本身并没有给more赋予任何含义。相反x是一个绑定变量，因为他在该函数的上下文里有明确的含义：它被定义为该函数的唯一参数，一个Int。如果单独使用这个函数字面量，而并没有在任何处于作用域内的地方定义more，编译器将会报错：  
```
scala> (x: Int) => x + more
error: not found: value more
```  
&emsp;&emsp;另一方面，只要能找到名为more的变量，同样的函数字面量就能正常工作：  
```
scala> var more = 1
more: Int = 1

scala> val addMore = (x: Int) => x + more
addMore: Int => Int = <function1>

scala> addMore(10)
res16: Int = 11
```  
&emsp;&emsp;运行时从这个函数字面量创建出来的函数值（对象）被称作闭包。该名称源于”捕获“其自由变量从而”闭合“该函数字面量的动作。  

## 特殊的函数调用形式
**重复参数：**scala允许标识出函数的最后一个参数可以被重复。这让我们可以对函数传入一个可变长度的参数列表。要表示这样一个重复参数，需要在参数的类型之后加上一个星号*例如：  
```
scala> def echo(args: String*) = 
    for (arg <- args) println(arg)
echo: (args: String*)Unit

scala> echo()
scala>echo("one")
one

scala>echo("hello", "world!")
hello
world!
```  
**带名字的参数：**  

**缺省参数值：**  

## 尾递归  
### 跟踪尾递归函数
&emsp;&emsp;尾递归函数并不会在每次调用时构建一个新的栈帧，所有的调用都会在同一个栈帧中执行。这一点可能会出乎检查某个失败程序的栈跟踪信息的程序员的意料。  

### 尾递归的局限
&emsp;&emsp;在scala使用尾递归时比较受限的，因为用JVM指令集实现更高级形式的尾递归非常困难。scala只能对那些直接尾递归调用自己的函数做优化。如果递归调用时简介的，scala则无法优化它们。  

&emsp;&emsp;尾递归优化仅适用于某个方法或嵌套函数在最后一部操作中直接调用自己，并且没有经过函数值或其他中间环节的常和。

# 组合和继承
&emsp;&emsp;对比类之间的两个最基本的关系：组合和继承。组合的意思是一个类可以包含对另一个类的引用，利用这个被引用类来帮助它完成任务；而继承是超类/子类的关系。  
&emsp;&emsp;除此之外，还有抽象垒、无参方法、类的扩展、重写方法和字段、参数化字段、调用超类的构造方法、多态和动态绑定、不可重写的成员和类，以及工厂对象和方法。  

## 抽象类
```
abstract class Element {
    def contents: Array[String]
}
```  
&emsp;&emsp;在这个类中，contents被声明为一个没有实现的方法。换句话说，这个方法是Element类的抽象abstract成员。一个包含抽象成员的类本身也要声明为抽象的，做法是在class关键字之前协商abstract修饰符：  
```
abstract class Element ...
```  
&emsp;&emsp;修饰符abstract表明该类可以拥有那些没有实现的抽象成员。因此不能直接实例化一个抽象类。  

## 定义无参方法
```
abstract class Element {
    def contents: Array[String]
    def height: Int = contents.length
    def width: Int = if (height == 0) 0 else contents(0).length
}
```  
&emsp;&emsp;这样的无参方法在scala非常常见。对此那些用空的圆括号定义的方法，被称作空圆括号方法。推荐的做法是对于没有参数且通过读取所在对象字段的方式访问可变状态的情况下尽量使用无参方法。这样的做法支持所谓的统一访问原则：使用方代码不应受到某个属性是用字段还是用方法实现的影响。  
&emsp;&emsp;scala对于混用无参方法和空括号方法的处理非常灵活。具体来说，可以用空括号方法重写无参方法，也可以反过来。还可以在调用某个不需要入参的方法时省去空括号。从原理上讲，可以对scala所有无参函数调用都去掉空括号。不过仍建议在被调用的方法不仅只代表接收该调用的对象的某个属性时加上空括号。举例来说，空括号的适用场景包括该方法执行I/O、写入可重新赋值的变量(var)、读取接收该调用对象字段之外的var（无论时直接还是间接地使用了可变对象）。  
&emsp;&emsp;总结下来，scala鼓励我们将那些不接收参数也没有副作用的方法定义为无参方法（即省去空括号）。同样，对于有副作用的方法，不应该省去空括号，因为省掉括号以后这个方法调用看上去就像是字段选择。  

## 扩展类
&emsp;&emsp;想要实例化一个元素，我们需要创建一个扩展来自Element的子类，并实现contents这个抽象方法，以下是可能的做法：  
```
class ArrayElement(const: Array[String]) extends Element {
    def contents: Array[String] = conts
}
```  
&emsp;&emsp;这样的extends字句有两个作用：它使得ArrayElement类从Element类继承所有非私有的成员， 并且它也让ArrayElement的类型称为Element类型的子类型。子类型的意思是子类的值可以被用在任何需要超类的值的场合。例如：  
```
val e: Element = new ArrayElement(Array("hello"))
```  

## 重写方法和字段
&emsp;&emsp;统一访问原则只是scala比java在处理字段和方法上更加统一的一个方面。另一个区别是 scala中字段和方法属于同一个命名空间。这使得用字段重写无参方法变为可能。举例来说，可以将ArrayElement类中的contents实现从方法改成字段，这并不需要修改Element类中的contents定义，例如：  
```
class ArrayElement(conts: Array[String]) extends Element {
    val contents: Array[String] = conts
}
```  
&emsp;&emsp;scala的命名空间分别是：值（字段、方法、包和单例对象）以及类型（类和特质）  

## 定义参数化字段
&emsp;&emsp;可以通过将参数和字段合并成**参数化字段**，可以避免一些不必要的冗余和重复。如：  
```
class ArrayElement(
    val contents: Array[String]
    ) extends Element
```  
&emsp;&emsp;注意，先在contents参数前面放了一个val。这是同时定义参数和同名字段的简写方式。具体来说，ArrayElement类现在具备一个（不能被重新赋值的）contents字段。该字段可以被外界访问。该字段被初始化为参数的值。  

## 调用超类构造方法
&emsp;&emsp;现在拥有一个由两个类组成的完整系统：一个抽象类Element，这个类又被另一个具体垒ArrayElement扩展。如果使用方可能要创建一个由字符串给出的单行组成的布局元素。面向对象的编程让我们很容易用新的数据变种来扩展一个已有的系统，只需要添加子类即可。举例来说，下面示例给出了一个扩展自ArrayElement的LineElement类：  
```
class LineELement(s: String) extends ArrayELement(Array(s)) {
    override def width = s.length
    override def height = 1
}
```  
## 使用override修饰符
&emsp;&emsp;注意，LineElement的width和height的定义前面都带上了override修饰符。scala要求我们在所有重写父类具体成员的成员之前加上这个修饰符。而如果某个成员并不重写或继承基类中的某个成员，这个修饰符则是禁用的。这样的规则为编译器提供了有用的信息，帮助我们避免某些难以捕获的错误，让系统得以更安全地进化。  

## 多态和动态绑定
&emsp;&emsp;在前面中，类型为Element的变量可以指向一个类型为ArrayElement的对象。这个现象叫作**多态** ，意思是“多个形状”或“多种形式”。  

## 声明final成员
&emsp;&emsp;有时在设计类继承关系的过程中，想要确保某个成员不能被子类继承。在scala中，跟java一样，可以通过在成员前面加上final修饰符来实现。  
```
class ArrayElement extends Element {
    final override def demo() = {
        println("ArrayElement's implementation invoked")
    }
}
```  
&emsp;&emsp;有了这个版本的ArrayElement，在其子类LineElement中尝试重写的话就会编译错误。  
&emsp;&emsp;如果想要整个类没有子类，可以简单地将类声明为final，例如：  
```
final class ArrayElement extends Element {
    override def demo() = {
        println("ArrayElement's implementation invoked")
    }
}
```  
&emsp;&emsp;有了这个任何想要定义其子类都会编译失败。  

## 使用组合和继承
&emsp;&emsp;组合和继承是两种用其他已有的类来定义新类的方式。如果你主要追求的是代码复用，一般来说应当优先选择组合而不是继承。只有继承才会受到脆弱基类问题的困扰，会在修改超类时不小心破坏了子类的代码。  

## 实现above、beside和toString
&emsp;&emsp;想要实现Element类的above方法。将某个元素放在另一个“上面”意味着将两个元素的值拼接在一起。第一版的above方法可能是这样的：  
```
def above(tha: Element): Element = 
    new ArrayElement(this.contents ++ that.contents)
```  
&emsp;&emsp;其中++这个操作将两个数组拼接在一起。scala中的数组是用java的数组表示的，不过支持更多的方法。具体来说，scala的数组可以转换成scala.Seq类的实例，这个类代表了类似于序列的结构，包含了访问和转换序列的若干方法。事实上，上面这个代码不够用，因为它并不允许将宽度不同的元素叠在一起。不过为了让事情保持简单，目前将不理会这个问题，记得需要每次传入相同长度元素给above。  
&emsp;&emsp;下一个要实现的方法是beside。要把两个元素并排放在一起，将创建一个新的元素。在这个元素中，每一行都是由两个元素的对应行拼接起来的。跟之前一样，为了让事情保持简单，一开始假定两个元素有相同的高度，设计出如下方案：  
```
def beside(that: Element): Element = {
    val contents = new Array[String](this.contents.length)
    for (i <- 0 until this.contents.length)
        contents(i) = this.contents(i) + that.contents(i)
    new ArrayElement(contens)
}
```  
&emsp;&emsp;这个beside方法首先分配一个新的数组contents，用this。contens和that.contents对应的数组元素拼接的字符串数组填充。最后产生一个新的包含新的contents的ArrayElement。  
&emsp;&emsp;虽然这个beside的实现可以解决问题，但这是一个指令式风格编写的。换一种方式：  
```
new ArrayElement(
    for (
        (line1, line2) <- this.contents zip that.contents
    ) yield line1 + line2
)
```  
&emsp;&emsp;当这三个方法组合一起就得到Element类：  
```
//定义一个抽象类
abstract class Element {

    //声明一个抽象方法，返回一个字符串数组
    def contents: Array[String]

    //定义一个方法width，用于计算元素的宽度
    def width: Int = 

        //如果高度为0,宽度返回0；否则取第一行字符串的长度
        if (height == 0) 0 else contents(0).length

    //定义一个方法height，用于计算元素的高度
    def height: Int = contents.length

    //定义一个方法above，用于在当前元素的上方叠加另一个元素
    def above(that: Element): Element = 

        //使用两个元素的内容拼接在一起生成新的 ArrayElement 对象
        new ArrayElement(this.contents ++ that.contents)

    //定义一个方法beside，用于将当前元素与另一个元素拼接
    def beside(that: Element): Element = 
        new ArrayElement(
            //使用for，将两个内容数组对应行拼接成新的行
            for (
                (line1, line2) <- this.contents zip that.contents
            ) yield line1 + line2
        )
        //重写toString方法，将元素的内容数组用换行符连接成字符串
        override def toString = contents mkString "\n"
}
```  

## 定义工厂对象
&emsp;&emsp;工厂对象包含创建其他对象的方法。使用方用这些工厂方法来构造对象，而不是直接用new构建对象。这种做法的好处是对象创建逻辑可以被集中起来，而对象是如何用具体的类表示的可以被隐藏起来。这样即可以让类库更容易被使用方理解，因为暴露的细节更少，同时还提供了更多的机会让你在未来在不破坏使用方代码的前提下改变类库的实现。  
&emsp;&emsp;为布局元素构建工厂的第一个任务是选择在哪里放置放置工厂方法。工厂方法应该作为某个单例对象的成员，还是类的成员？包含工厂方法的对象或类应该如何命名？可能性有很多。直接的方案是创建一个Element类的伴生对象，作为布局元素的工厂对象。这样，你只需要暴露Element这组类/对象给使用方，并将ArrayElement,LineElement和UniformElement这三类实现类隐藏起来。  
&emsp;&emsp;如下示例按照这个机制做出的Element对象设计。Element对象包含了三个重载的elem方法，每个方法构建不同种类的布局对象。  
```
object Element {
    def elem(contents: Array[String]): Element = 
        new ArrayElement(contents)
    def elem(chr: Char, width: Int, height: Int): Element = 
        new UniformElement(chr, width, height)
    def elem(line: String): Element = 
        new LineElement(line)
}
```  
&emsp;&emsp;有了这些工厂方法以后，我们有理由将Element类的实现做一些改变，让它用elem工厂方法，而不是直接显式地创建新的ArrayELement。为了在调用工厂方法时不显式给出Element这个单例对象名称的限定词，我们将在源码文件顶部引如Element.elem。换句话说，我们在Element类中不再用Element.elem来调用工厂方法，而是引入Element.elem，这样我们就可以用他们的简单名字，即elem 来调用工厂方法了。下面例子就是调整后的：  
```
import Element.elem
abstract class Element {
    def contents: Array[String]
    def width: Int = 
        if (height == 0) 0 else contents(0).length
    def height: Int = contents.length
    def above(that: Element): Element = 
        elem(this.contents ++ that.contents)
    def beside(that: ELement): Element = 
        elem(
            for (
                (line1, line2) <- this.contents zip that.contents
            ) yield line1 + line2
        )
        override def toString = contents mkString "\n"
}
```  
&emsp;&emsp;除此之外，有了工厂方法后，ArrayElement,LineElement,UniformElement这些子类可以变成私有的，因为它们不再需要被使用方直接访问了。在scala中，可以在其他类或单例对象中定义类和单例对象。将Element的子类编程私有的方式之一是将它们放在Element单例对象中并声明为私有。这些类在需要时仍可以被拿三个elem工厂方法访问到。  
```
object Element {
    private class ArrayElement(val contents) extends Element
    private class LineElement(s: String) extends Element {
        val contents = Array(s)
        override def width = s.length
        override def height = 1
    }

    private class UniformElement(
        ch: Char,
        override val width: Int,
        override val height: Int
    ) extends Element {
        private val line = ch.toString * width
        def contents = Array.fill(height)(line)
    }
    def elem(contents: Array[String]): Element = 
        new ArrayElement(contents)
    def elem(chr: Char, width: Int, height: Int): Element = 
        new UniformElement(chr, width, height)
    def elem(line: String): Element = 
        new LineElement(line)
}
```  

