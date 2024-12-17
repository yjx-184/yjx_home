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
