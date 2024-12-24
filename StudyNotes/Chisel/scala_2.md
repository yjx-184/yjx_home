- [scala的继承关系](#scala的继承关系)
- [特质](#特质)
  - [特质如何工作](#特质如何工作)
  - [瘦接口和富接口](#瘦接口和富接口)
  - [示例：矩形对象](#示例矩形对象)
  - [Ordered特质](#ordered特质)
  - [作为可叠加修改的特质](#作为可叠加修改的特质)
  - [为什么不用多重继承](#为什么不用多重继承)
  - [要特质还是不要特质](#要特质还是不要特质)
- [包和引入](#包和引入)
  - [将代码放进包里](#将代码放进包里)
  - [对相关代码的精简访问](#对相关代码的精简访问)
  - [引入](#引入)
  - [隐式引入](#隐式引入)
  - [访问修饰符](#访问修饰符)
    - [私有成员](#私有成员)
    - [受保护成员](#受保护成员)
    - [公共成员](#公共成员)
  - [包对象](#包对象)
- [断言和测试](#断言和测试)
  - [断言](#断言)
  - [用scala写测试](#用scala写测试)
  - [基于性质的测试](#基于性质的测试)
- [样例类和模式匹配](#样例类和模式匹配)
  - [一个简单的例子](#一个简单的例子)
    - [样例类](#样例类)
    - [模式匹配](#模式匹配)
    - [对比match和switch](#对比match和switch)
  - [模式的种类](#模式的种类)
    - [通配模式](#通配模式)
    - [常量模式](#常量模式)
    - [变量模式](#变量模式)
    - [构造方法模式](#构造方法模式)
    - [序列模式](#序列模式)
    - [元组模式](#元组模式)
    - [带类型的模式](#带类型的模式)
- [使用列表](#使用列表)
  - [List字面量](#list字面量)
  - [List类型](#list类型)
  - [构建列表](#构建列表)
  - [列表的基本操作](#列表的基本操作)
  - [列表模式](#列表模式)
  - [List类的初阶方法](#list类的初阶方法)
    - [拼接两个列表](#拼接两个列表)
    - [分治原则](#分治原则)
    - [获取列表长度：length](#获取列表长度length)
    - [访问列表的末端：init和last](#访问列表的末端init和last)
    - [反转列表：reverse](#反转列表reverse)
    - [前缀和后缀：drop、take和splitAt](#前缀和后缀droptake和splitat)
    - [元素选择：apply和indices](#元素选择apply和indices)
    - [扁平化列表的列表：flatten](#扁平化列表的列表flatten)
    - [将列表zip起来：zip和unzip](#将列表zip起来zip和unzip)
    - [显示列表：toString和mkString](#显示列表tostring和mkstring)
    - [转换列表：iterator、toArray、copyToArray](#转换列表iteratortoarraycopytoarray)
- [使用其他集合类](#使用其他集合类)
  - [序列](#序列)
    - [列表](#列表)
    - [数组](#数组)
    - [列表缓冲](#列表缓冲)
    - [数组缓冲](#数组缓冲)
    - [字符串（通过StringOps）](#字符串通过stringops)
  - [集和映射](#集和映射)
- [可变对象](#可变对象)
  - [什么是可变对象](#什么是可变对象)
  - [可被重新赋值的变量和属性](#可被重新赋值的变量和属性)
  - [用描述数字电路的语言](#用描述数字电路的语言)
  - [Simulation API](#simulation-api)
  - [电路模拟](#电路模拟)
    - [Wire类](#wire类)
    - [inverter方法](#inverter方法)
    - [andGate,orGate方法](#andgateorgate方法)
  - [结语](#结语)
- [类型参数化](#类型参数化)
  - [函数式队列](#函数式队列)
  - [信息隐藏](#信息隐藏)
    - [私有构造方法和工厂方法](#私有构造方法和工厂方法)
  - [型变注解](#型变注解)



# scala的继承关系
&emsp;&emsp;在scala中，每个类都继承同一个名为“Any”的超类。由于每个类都是Any的子类，在Any中定义的方法是“全类型的”：它们可以在任何对象上被调用。scala还在继承关系的底部定义了一些有趣的类，Null和Nothing，它们本质上是作为通用的子类存在。  
&emsp;&emsp;由于每个类都继承自Any，scala程序中的每个对象都可以用==、！=或equals来比较，用##或hashCode做哈希，以及用toString做格式化。相等和不相等（==和！=）在Any类中声明为final，所以它们不能被子类重写。  

# 特质
&emsp;&emsp;特质是scala代码复用的基础单元。特质将方法和字段定义封装起来，然后通过将它们混入类的方法来实现复用。它不同于类继承，类继承要求每个类都继承自一个（明确的）超类，而类可以同时混入任意数量的特质。  
## 特质如何工作
&emsp;&emsp;特质的定义跟类的定义很像，除了关键字trait。  
```
trait Philosophical {
    def philosophize() = {
        println("I consume memory, therefore I am!")
    }
}
```  
&emsp;&emsp;该特质名为Philosophical。它并没有声明一个超类，因此跟类一样，有一个默认的超类AnyRef。它定义了一个名为philosophize的方法，这个方法是具体的。这只是个简单的特质，只是为了展示特质的工作原理。  
&emsp;&emsp;一旦特质被定义好，我们就可以用extends或with关键字将它混入到类中。scala程序员混入特质，而不是从特质继承，因为混入特质跟其他取他编程语言中的多重继承有重要的区别。举例来说，下一个示例展示了一个用extends混入了Philosophical特质的类：  
```
class Frog extends Philosophical {
    override def toString = "green"
}
```  
&emsp;&emsp;如果想要将特质混入一个显式继承自某个超类的类，可以用extends来给出这个超类，并用with来混入特质。下面例子，如果想要混入多个特质，可以用with字句进行添加。例如，如果有一个HasLegs特质，也可以同时混入Philosophical和HasLegs特质。  
```
class Animal
class Frog extends Animal with Philosophical {
    override def toString = "green"
}
```
混入多个特质：  
```
class Animal
trait HasLegs
class Frog extends Animal with Philosophical with HasLegs {
    override def toString = "green"
}
```  
&emsp;&emsp;特质可以声明字段并保持状态。事实上，在特质定义中可以做任何在类定义中做的事，语法也完全相同，除了以下两种情况：  
&emsp;&emsp;首先，特质不能有任何“类”参数（即那些传入类的主构造方法的参数）。  
&emsp;&emsp;另一个类和特质的区别在于类中的super调用是静态绑定的，而在特质中super是动态绑定的。如果在类中编写"super.toString"这样的代码，你会确切地知道实际调用的是哪一个实现。在你定义特质的时候并没有被定义。具体是哪个实现被调用，在每次该特质被混入到某个具体的类时，都会重新判定。这里的super看上去有些奇特的行为时特质能实现可叠加修改的关键。  

## 瘦接口和富接口  
&emsp;&emsp;特质的一个主要用途时自动给类添加基于已有方法的新方法。也就是说，特质可以丰富一个瘦接口让它成为富接口。  
&emsp;&emsp;瘦接口和富接口代表我们在面向对象设计中经常面临的取舍，在接口实现者和使用者之间的权衡。富接口有很多方法，对调用方而言十分方便。使用者可以选择完全匹配它们需求的功能的方法。而瘦接口的方法较少，因而实现起来更容易。不过瘦接口的使用方需要编写更多的代码。由于可供选择的方法较少，他们可能被迫选择一个不那么匹配需求的方法，然后编写额外的代码来使用它。  
&emsp;&emsp;给特质添加具体方法让瘦接口和富接口之间的取舍变得严重倾向于富接口。不同于java，给scala特质添加具体方法时一次性的投入。只需要在特质中实现这些方法一次，而不需要在每个混入该特质的类中重新实现一遍。因此，跟其他没有特质的语言相比，在scala中实现富接口的代价更小。  
&emsp;&emsp;要用特质来丰富某个接口，只需要定义一个拥有为数不多的抽象方法（借口中瘦的部分）和可能数量很多的具体方法（这些具体方法基于那些抽象方法编写）的特质。然后，你就可以将这个增值特质混入到某个类，在类中实现接口中瘦的部分，最终得到一个拥有完整接口实现的类。  

## 示例：矩形对象
```
class Point(val x: Int, val: Int)
class Rectangle(val topLeft: Point, val bottomRight: Point) {
    def left = topLeft.x
    def right = bottomRight.x
    def width = right - left
    //更多的几何方法等等
}
```  
&emsp;&emsp;这里的Rectangle类在主构造方法中接收两个point：分别表示在左上角和右下角的坐标。它接下来实现了许多遍历方法，比如Left、right和width，做法是对这两个坐标进行简单的计算。  
&emsp;&emsp;图形库可能会有的另一个类时2D图形组建：  
```
abstract class Component {
    def topLeft: Point
    def bottomRight: Point

    def left = topLeft.x
    def right = bottomRight.x
    def width = right - left
    //更多的方法....
}
```  
&emsp;&emsp;注意上面两个类left、right和width的定义完全一致。  
&emsp;&emsp;这些重复代码可以用增值特质来消除。这个特质将会包含两个抽象方法：一个返回对象左上角的坐标，另一个返回右下角的坐标。然后它就可以提供所有其他集合查询相关方法的具体实现。  
```
trait Rectangular {
    def topLeft: Point
    def bottomRight: Point

    def left = topLeft.x
    def right = bottomRight.x
    def width = right - left
    //更多的方法...
}
```  
&emsp;&emsp;Component类可以混入这个特质来获取所有由Rectangular提供的几何查询方法：  
```
abstract class Component extends Rectamgular {
    //其他方法
}
```  

&emsp;&emsp;同理，Ractangle自己也可以混入这个特质：  
```
class Rectangle(val topLeft: Point, val bottomRight: Point) 
    extends Rctangular {
        //...
    }
```  
&emsp;&emsp;有了这些定义，就可以创建一个Rectangle并调用其几何查询方法，比如width和left：  
```
scala> val rect = new Rectangle(new Point(1, 1),
        new Point(10, 10))
rect: Rectangle = Rectangle@5f5da68c

scala> rect.left
res2: Int = 1

scala> rect.right
res3: Int = 10

scala> rect.width
res4: Int = 9
```  

## Ordered特质
&emsp;&emsp;在scala中专门提供了特质较Ordered，使用的方法时将所有单独的比较方法替换成compare方法。Ordered特质为你定义了< 、> 、<= 和 >=，这些方法都是基于你提供的compare来实现的。因此Ordered特质允许你只实现一个compare方法来增强某个类，让他拥有完整的比较操作。  
&emsp;&emsp;以下使用Ordered特质来对Rational定义比较操作的代码：  
```
class Rational(n: Int, d: Int) extends Ordered[Rational] {
    //...

    def compare(that: Rational) = 
        (this.numer * that.denom) - (that.numer * this.denom)
}
```  
&emsp;&emsp;只需要做两件事。首先，这个版本的Rational混入了Ordered特质。与你看到过的其他特质不同，Ordered要求你在混入时传入一个类型参数。，当混入这个特质时必须混入Ordered[C]，其中C是你要比较的元素。在本例中，Rational混入的是Ordered[Rational]。  
&emsp;&emsp;你需要做的第二件事是定义一个用来比较两个对象的compare方法，该方法应该比较接收者，即this，和作为采纳数传入该方法的对象。如果两个对象相同将返回0；如果接收者比入参小，应该返回负值；如果接收者比入参大，则返回正值。  

## 作为可叠加修改的特质
&emsp;&emsp;特质的一个主要用途：将瘦接口转化成富接口。另一个用途：为类提供可叠加的修改。特质让你修改类的方法，而它们的实现方式允许你将这些修改叠加起来。  

## 为什么不用多重继承
&emsp;&emsp;特质是一种从多个像类一样的结构继承的方式，不过它们跟许多其他语言中的多重继承有着重大的区别。其中一个区别尤为重要：对super的解读。在多重继承中，super调用的方法在调用发生的地方就已经确定了。而特质中的super调用的方法取决于类和混入该类的特质的线性化。正是这个差别让前面介绍的可叠加修改变为了可能。  

## 要特质还是不要特质
&emsp;&emsp;当你实现某个可复用的行为集合时，都需要决定是用特质还是抽象垒。对这个决定，我们并没有某种确定的规则。  
&emsp;&emsp;如果某个行为不会被复用，用具体的类。毕竟它并不是可复用的行为。如果某个行为可能被用于多个互不相关的类，用特质。只有特质才能被混入类继承关系中位于不同组成部分的类。  
&emsp;&emsp;想要从java代码中继承某个行为，用抽象类。由于带有实现的特质并没有与之贴近的java比，因此从java类继承特质会比较别扭。不过从java类继承scala类跟继承java类几乎一样。不过有一个例外，如果某个scala特质只有抽象方法，它会被直接翻译成java的接口，因此可以放心定义这样的特质，哪怕预期会有java代码继承它。

# 包和引入
&emsp;&emsp;在处理程序，尤其是大型程序时，减少耦合是很重要的。所谓的耦合，指的是程序不同部分依赖其他部分的程度。低耦合能减少程序某个局部的某哦个看似无害的改动对其他部分造成严重后果的风险。减少耦合的一种方式是以模块化的风格编写代码。  
## 将代码放进包里  
&emsp;&emsp;在scala中，可以通过两种方式将代码放进包里。第一种方式是在文件顶部放置一个package字句，让整个文件的内容放进指定的包：  
```
package bobsrockets.navigation
class Navigator
```  
&emsp;&emsp;示例中的paclage子句将Navigator类放入了名为bobsrockets.navigation的包。  
&emsp;&emsp;另一种是将scala代码放进包的方式更像C#的命名空间。可以在package子句之后加上一段用花括号包起来的代码块，这个代码块包含了进入该包的定义。这个语法称为打包。下面的例子与上面的例子效果一样：  
```
package bobsrockets.navigation {
    class Navigator
}
```  
&emsp;&emsp;这个方法可以让我们在一个文件里包含多个包的内容，举例来说可以把某个类的测试代码跟原始代码放在同一个文件里，不过分成不同的包，如：  
```
package bobsrockets {
    package navigation {
        //位于bobsrocket.navigation包中
        class Navigator
        package tests {
            //位于bobsrocket.navigation.tests
            class NavigatorSuite
        }
    }
}
```  

## 对相关代码的精简访问
&emsp;&emsp;我们把代码按照包层次结构划分以后，不仅有助于人们浏览代码，同时也在高速编译器，同一个包中的代码之间存在某种相关性。在访问同一个包的代码时，scala允许我们使用简短的，不带限定前缀的名称。

## 引入
&emsp;&emsp;在scala中，我们可以用import子句引入包和它们的成员。被引入的项目可以用FIle这样的简单名词访问，而不需要限定名称，比如java.io.FIle。如：  
```
package bobsdelights
abstract class Fruit(
    val name: String,
    val color: String
)
object Fruits {
    object Apple extends Fruit("apple", "red")
    object Orange extends Fruit(orange", "orange")
    object Pear extends Fruit("pear", "yellowish")
    val menu = List(Apple, Orange, Pear)
}
```  
&emsp;&emsp;import子句使得某个包或对象的成员可以只用它们的名字访问，而不需要在前面加上包名或对象名。下面是一些简单的例子：  
```
//到Fruit 的便捷访问
import bobsdelights.Fruit

//到bobsdelights所有成员的便捷访问
import bobsdedlights._

//到Fruits所有成员的便捷访问
import bobsdelights.Fruits._
```  
&emsp;&emsp;第一个对应java的单类引入，而第二个对应java的按需引入。唯一区别是scala的按需引入跟在后面的是下画线_而不是星号*。第三个引入子句对应java对类静态字段的引入。  

**scala的灵活引入**： 跟java相比，scala的import子句要灵活得多。主要的区别有三点，在scala中，引入可以：出现在任意位置、引用对象（不论是单例还是常规对象），而不只是包、让你重命名并隐藏某些被引入的成员。  

## 隐式引入
&emsp;&emsp;scala对每个程序都隐式低添加了一些引入。本质上，这好比每个扩展名为".scala"的源码文件的顶部都添加了如下三行引入子句：  
```
import java.lang._  //java.lang包的全部内容
import scala._      //scala包的全部内容
import Predef._     //Predef对象的全部内容
```  
## 访问修饰符
&emsp;&emsp;包、类或对象的成员可以标上private和protected这样的访问修饰符。这些修饰符将对成员的访问限定在特定的代码区域。  
### 私有成员
&emsp;&emsp;scala对私有成员的处理跟java类似。标为private的成员只在包含该定义的类或对象内部可见。在scala中，这个规则同样适用于内部类。  

### 受保护成员
&emsp;&emsp;跟java相比，scala对protected成员的访问也更严格。在scala中，protected的成员只能从定义该成员的子类访问。

### 公共成员
&emsp;&emsp;scala并没有专门的修饰符用来标记公共成员：任何没有比被标为private或protected的成员都是公共的。  

## 包对象
&emsp;&emsp;到目前为止，见过能添加到包里的代码有类、特质和孤立对象。这些是放在包内顶层最常见的定义。不过scala允许你放在包级别的并非只有上述这些——任何能放在类级别的定义，都能放在包级别。如果有某个希望在整个包都能用的助手方法、大可将它放在包的顶层。  
&emsp;&emsp;具体的做法是把定义放在包对象当中。每个包都允许有一个包对象，任何被放在包对象里的定义都会被当作这个包的本身的成员。  

# 断言和测试
## 断言
&emsp;&emsp;在scala中，断言的写法是对预定义方法assert的调用。如果condition不满足，表达式assert（condition）将抛出AssertionError。assert还有另一个版本：assert(condition, explanation)，首先检查condition是否满足 。如果不满足那就抛出包含给定explanation的AssertionError。explanation的类型是Any，因此可以传入任何对象。assert方法将调用explanation的toString方法来获取一个字符串的解释放入AssertionError。  

## 用scala写测试
&emsp;&emsp;用scala写测试有很多选择比如ScalaTest,specs2和ScalaCheck。  
&emsp;&emsp;ScalaTest是最灵活的scala测试框架：可以很容易地定制它来解决不同的问题。ScalaTest的灵活性意味着团队可以使用任何最能满足他们需求的测试风格。  
&emsp;&emsp;ScalaTest的核心概念是套件suite，即测试的集合。所谓的测试可以是任何带有名称，可以被启动，并且要么成功，要么失败，要么被暂停，要么被取消的代码。在ScalaTest中，Suite特质是核心组合单元。Suite声明了一组“生命周期”方法，定义了运行测试的默认方法，我们也可以重些这些方法来对测试的编写和运行进行定制。  

## 基于性质的测试  
&emsp;&emsp;scala的另一个有用的测试工具是ScalaCheck，这能够指定被测试的代码必须满足的性质。对每个性质，ScalaCheck都会生成数据并执行断言，检查代码是否满足该性质，示例给出了一个混入了ScalaCheck PropertyChecks特质的AnyWordSpec的ScalaTest中使用ScalaCheck的例子：  
```
import org.scalatest.wordspec.AnyWordSpec
import org.scalatestplus.scalacheck.ScalaCheck.PropertyCHecks
import org.scalatest.matchers.mustMatchers._

class ElementSpec extends WordSpec with PropertyChecks {
    "elem result" must {
        "have passed width" in {
            forAll { (w: Int) =>
            whenever (w > 0) {
                elem('x', w, 3).width must equal (w)
                }
            }
        }
    }
}
```  
&emsp;&emsp;AnyWordSpec是一个ScalaTest的风格类。ScalaCheck PropertyChecks特质提供了若干forAll方法，让你可以将基于性质的测试跟传统的基于断言或基于匹配器的测试混合在一起。在本例中，我们检查了一个elem工厂必须满足的性质。ScalaCheck的性质在代码中表现为以参数形式接收性质断言所需的数据的函数值。这些数据将由ScalaCHeck代我们生成。whenever 子句表达的意思是，只要左边的表达式为true，那么右边的表达式也必须为true。只需要这么一小段代码，ScalaCheck就会帮助我们生成数百条w可能的取值并对每一个执行测试，尝试找出不满足该性质的值。  

# 样例类和模式匹配
&emsp;&emsp;样例类和模式匹配这组孪生语法结构为我们编写规则的、未封装的数据结构提供支持。这两个语法结构对于表达树形的递归数据尤其有用。样例类是scala用来对对象进行模式匹配而并不需要大量的样板代码的方法。笼统地说，你要做的就是对那些你希望能做模式匹配的类加上一个case关键字。  

## 一个简单的例子
&emsp;&emsp;假定需要编写一个操作算术表达式的类库，可能这个类库是正在设计的某个领域的特性语言的一部分。解决这个问题的第一步是定义输入数据。为保持简单，我们将注意力几种在由变量、数、以及一元和二元操作符组成的算术表达式上。用scala的类层次结构来表述：  
（定义样例类）  
```
abstract class Expr
case class Var(name: String) extends Expr
case class Number(num: Double) extends Expr
case class UnOp(operator: String, arg: Expr) extends Expr
case class BinOp(operator: String,
    left: Expr, right: Expr) extends Expr
```  
&emsp;&emsp;这个层次结构包括一个抽象的基类Expr和四个子类，每一个都表示我们要考虑的一种表达式。所有五个类的定义体都是空的。  

### 样例类
&emsp;&emsp;上面的示例，每个子类都有case修饰符，带有这种修饰符的类称作样例类。用上这个修饰符会让scala编译器对我们的类添加一些语法上的便利。  
&emsp;&emsp;首先，它会添加一些跟类同名的工厂方法。这意味着我们可以用Var("x")来构造一个Var对象，而不用稍长版本的new Var("x")：
```
scala> val v = Var("x")
v: Var = Var(x)
```  
&emsp;&emsp;当需要嵌套定义时，工厂方法尤为有用，由于代码中不再到处落满new关键字，可以一眼就看明白表达式的结构：  
```
scala> val op = BinOp("+", Number(1), v)
op: BinOp = BinOp(+,Number(1.0), Var(x))
```  
&emsp;&emsp;其次，第二个语法上的便利时参数列表中的参数都隐式地获得了一个val前缀，因此会被当作字段处理。  
&emsp;&emsp;再次，编译器会帮我们以“自然”的方式实现toString、hashCode和equals方法。这些方法分别会打印、哈希、比较包含类及所有入参的整颗树。由于scala的 == 总是代理给equals方法，这意味着以样例类表示的元素总是以结构法的方式做比较：  
```
scala> println(op)
BinOp(+,Number(1.0), Var(x))

scala> op.right == Var("x")
res3: Boolean = true
```  
&emsp;&emsp;最后，编译器还会添加一个copy方法用于制作修改过的拷贝。这个方法可以用于制作除一两个属性不同之外其余完全相同的该类的新实例。这个方法用到了带名字的参数和默认参数。我们用带名字的参数给出想要做的修改。对于任何你没有给出的参数，都会用老对象中的原值。  

### 模式匹配
&emsp;&emsp;假定我们想简化前面展示的算术表达式。可用的简化规则非常多，以下只列举一部分：  
```
UnOp("-", UnOp("-", e)) => e    //双重取负
BinOp("-", e,Number(0)) => e    //加0
BinOp("*", e,Number(1)) => e    //乘1
```  
&emsp;&emsp;用模式匹配的话，这些规则可以被看成是一个scala编写的简化函数的核心逻辑。  

### 对比match和switch
&emsp;&emsp;记住三个区别：首先，scala的match是一个表达式（也就是说它总是能得到一个值）。其次，scala的可选分支不会贯穿到下一个case。最后，如果没有一个模式匹配上会抛出名为MatchError的异常。这意味着需要确保所有的case被覆盖到，哪怕这意味着需要添加一个什么都不做的默认case。  

## 模式的种类
### 通配模式
&emsp;&emsp;通配模式(_)会匹配任何对象。  

### 常量模式
&emsp;&emsp;常量模式仅匹配自己。任何的字面两都可以作为常量模式使用。同时，任何val或单例对象也可以被当作常量模式使用。Nil这个单例对象能且仅能匹配空列表。  

### 变量模式
&emsp;&emsp;变量模式匹配任何对象，这一点跟通配模式相同。不过不同于通配模式的是，scala将对应的变量绑定成匹配上的对象。在绑定之后，你就可以用这个变量来对对象做进一步的处理。  

### 构造方法模式  
&emsp;&emsp;构造方法模式是真正体现出模式匹配威力的地方。这样的一个模式将首先检查被匹配的对象是否是以这个名称命名的样例类的实例，然后再检查这个对象的构造方法参数是否匹配这些额外给出的模式。  
&emsp;&emsp;这些额外的模式意味着scala的模式支持深度匹配。这样的模式不仅检查给出的对象的顶层，还会进一步检查对象的内容是否匹配额外的模式要求。由于额外的模式也可能是构造方法模式，用它们来检查对象内部时可以到任意的深度。  

### 序列模式
&emsp;&emsp;就跟与样例类匹配一样，也可以跟序列类型做匹配，比如List或Array。使用的语法是相同的，不过现在可以在模式中给出任意数量的元素。如果想要匹配一个序列，但又不想给出多长，可以用_*作为模式的最后一个元素。  

### 元组模式
&emsp;&emsp;我们还可以匹配元组。形入(a,b,c)这样的模式能匹配任意的三元组。  

### 带类型的模式
&emsp;&emsp;可以用带类型的模式来代替类型测试和类型转换。  


# 使用列表
## List字面量
&emsp;&emsp;列表和数组很像，不过还是有区别的。首先，列表是不可变的，就是说，列表的元素不能通过赋值改变。其次，列表的结构是递归的，而数组是平的。  

## List类型
&emsp;&emsp;跟数组一样，列表是**同构** 的：同一个列表的所有元素都必须是相同的类型。  
&emsp;&emsp;scala的列表类型是**协变** 的：对每一组类型S和T，如果S是T的子类型，那么List[S] 就是List[T]的子类型。  

## 构建列表
&emsp;&emsp;所有的列表都构建自两个基础的构建单元： Nil和::。Nil表示空列表。中缀操作符：：表示在列表前追加元素。这个操作符是右结合的。  

## 列表的基本操作
&emsp;&emsp;对列表的所有操作都可以用下面这三项来表述：  
head：返回列表的第一个元素  
tail：返回列表中除第一个元素之外的所有元素
isEmpty：返回列表是否为空列表  

&emsp;&emsp;这些操作在List类中定义为方法。  

## 列表模式
&emsp;&emsp;列表也可以用模式匹配解开。列表模式可以逐一对应到列表表达式。我们即可以用List(...)这样的模式来匹配列表的所有元素，也可以用：：操作符和Nil常量一点点地将列表解开。  
&emsp;&emsp;使用模式使用基本方法head、tail和isEmpty来解开列表的变通方式，例如，我们再次实现插入排序，不过这一次用模式匹配：  
```
def isort(xs: List[Int]): List[Int] = xs match {
    case List() => List()
    case x :: xs1 => insert(x,isort(xs1))
}
def insert(x: Int, xs: List[Int]): List[Int] = xs match {
    case List() => List(x)
    case y :: ys => if (x <= y) x :: xs
                    else y :: insert(x, ys)
}
```  
## List类的初阶方法  
### 拼接两个列表
&emsp;&emsp;：：：

### 分治原则

### 获取列表长度：length

### 访问列表的末端：init和last

### 反转列表：reverse

### 前缀和后缀：drop、take和splitAt

### 元素选择：apply和indices  

### 扁平化列表的列表：flatten

### 将列表zip起来：zip和unzip

### 显示列表：toString和mkString

### 转换列表：iterator、toArray、copyToArray

# 使用其他集合类
## 序列
&emsp;&emsp;序列类型可以用来处理一次排列分组的数据。由于元素是有次序的，可以向序列获取第1个元素、第2个元素等等。  

### 列表
&emsp;&emsp;最重要的序列类型是List类。列表支持在头部快速添加和移除条目，不过并不提供快速的按下标访问的功能，因为实现这个功能需要线性地遍历列表。
&emsp;&emsp;这样的特性组合听上去可能很奇怪，但其实对于很多算法而言都非常适合。快速的头部添加和移除意味着模式匹配很顺畅。而列表的不可变性质帮助我们开发正确、高效的算法，因为不需要复制列表。  

### 数组
&emsp;&emsp;数组允许我们保存一个序列的元素，并使用从零开始的下标高效地访问（获取或更新）指定位置的元素值。  
&emsp;&emsp;scala数组的的表现形式跟java数组一致。因此，我们可以无缝地使用那些返回数组的java方法。  

### 列表缓冲
&emsp;&emsp;List类提供对列表头部的快速访问，对尾部访问则没那么高效。因此，当我们需要往列表尾部追加元素来构建列表时，通常要考虑反过来往头部追加元素，追加完成以后，再调用reverse来获得我们想要的顺序。  
&emsp;&emsp;另一种避免reverse操作的可选方案是使用ListBuffer。这是一个可变对象，帮助我们再需要追加元素来构建列表时可以更高效。ListBuffer提供了常量时间的往后追加和往前追加的操作。我们可以用+=操作符来往后追加元素，用+=：来往前追加元素。

### 数组缓冲
ArrayBuffer跟数组很像，除了可以额外地从序列头部或尾部添加或移除元素。所有的Array操作再ArrayBuffer都可用，不过由于实现的包装，会稍慢一些。新的添加和移除操作平均而言是常量时间的。不过偶尔会需要线性的时间，这是因为其实需要不时地分配新的数组来保存缓冲的内容。  

### 字符串（通过StringOps）
&emsp;&emsp;我们需要了解另一个序列是StringOps，它实现了很多序列方法。由于Predef有一个从String到StringOps的隐式转换，可以将任何字符串当作序列来处理。  

## 集和映射

# 可变对象
## 什么是可变对象
&emsp;&emsp;我们甚至不需要查看对象的实现就能观察到纯函数式对象和可变对象的主要区别。当调用某个纯函数式对象的方法或获取它的字段时，我们总是能得到相同的结果。  
```
val cs = List('a', 'b', 'c')
```  
&emsp;&emsp;对cs.head的调用总是返回‘a’。这一点哪怕从列表被定义到发起cs.head调用之前发生了任意数量的操作，也不会改变。  
&emsp;&emsp;另一方面，对于可变对象而言，方法调用或字段访问的结果可能取决于之前这个对象被执行了哪些操作。可变对象的一个不错的例子就是银行账户。  
```
class BankAccount {
    //定义一个私有变量bal：余额
    private var bal: Int = 0

    //定义一个方法：balance：余额
    def balance: Int = bal

    //定义一个方法：deposit：存款操作
    def deposit(amount: Int) = {
        require(amount > 0)
        bal += amount
    }

    //定义一个方法：withdraw：取款操作
    def withdraw(amount: Int): Boolean = 

        //如果取款金额大于余额，则输出false
        if (amount > bal) false
        else {
            bal -=amount
            ture
        }
}
```  

## 可被重新赋值的变量和属性
&emsp;&emsp;我们可以对一个可被重新赋值的变量做两种基本操作：获取它的值和将它设为新值。在诸如JavaBeans的类库中，这些操作通常被包装成单独的getter和setter方法，我们需要显式定义这些方法。  
&emsp;&emsp;在scala中，每一个非私有的var成员都隐式地定义了对应的getter和setter方法。不过这些getter和setter方法的命名跟java的习惯不一样。var x的getter方式只是命名为“x”，而它的setter方式命名为“x_="。
&emsp;&emsp;举例来说，如果出现在类中，如下的var定义：var hour = 12  
&emsp;&emsp;除了定义一个可被重新赋值的字段，还将生成一个名为"hour"的getter和一个名为"hour_="的setter。其中的字段总是被标记为private[this]，意味着这个字段只能从包含它的对象中访问。而getter和setter则拥有跟原来的var相同的可见性。如果原先的var定义是公有的，那么它的getter和stter也是公有的；如果原先的var定义是protected，那么它的getter和setter也是protected；以此类推。  
&emsp;&emsp;举例来说，参考下面示例的Time类，它定义了两个公有的var,hour和mintue：  
```
class Time {
    var hour = 12
    var minute = 0
}
```  
&emsp;&emsp;这个实现将与下面示例的类定义完全等效。下面的定义中，局部字段h和m的名称是随意的，只要不跟已经甬道的名称冲突即可。  
```
class Time {
    private[this] var h = 12
    private[this] var m = 0
    def hour: Int = h
    def hout_=(x: Int) = { h = x}
    def mintue: Int = m
    def mintue_=(x: Int) = { m = x}
}
```  
&emsp;&emsp;这个将var展开成getter和setter的机制有趣的一点在于我们仍然可以直接定义getter和stter，而不是定义一个var。通过直接定义这些访问方法，可以按照自己的意愿来解释变量访问和赋值的操作。  
&emsp;&emsp;某些语言对于这些类似变量的值有特殊的语法表示，它们不同于普通变量的地方再与getter和setter可以被重新定义。例如C#有属性来承担这个角色。从效果上讲，scala总是将变量解读为stter和getter方法的这个做法，让我们不需要特殊语法的情况下获得了跟C#属性一样的能力。  
&emsp;&emsp;属性可以有很多用途，setter可以强调一个恒定的规则，防止变量被赋予非法值。我们还可以用属性来记录所有对变量getter和setter的访问。或者将变量和事件集成起来，比如当变量被修改时都去通知那些订阅了该事件的订阅者方法。  
&emsp;&emsp;有时候，定义不跟任何字段关联的getter和setter也是有用的，scala允许我们这样做。举例来说，下面示例给出了Thermometer类，这个类封装了一个表示温度的变量，可以被读取和更新。温度可以用摄氏和华氏来表示。这个类允许我们用任意一种标度来获取和设置温度。  
```
class Thermometer {

    //定义了变量celsius，用来包含摄氏度的温度。一开始被设置成默认值。
    var celsius: Float = _

    //getter方法定义
    def fahrenheit = celsius * 9 / 5 +32

    //setter方法定义
    def fahrenheit_= (f: Float) = {
        celsius = (f - 32) * 5 / 9
    }
    override def toString = fahrenheit + "F/" + celsius + "C"
}
```  
&emsp;&emsp;以上两个访问的都是同一个温度变量，但是以华氏表示，并没有单独的变量以华氏度保存温度。华氏度的getter和setter方法回自动与摄氏度做必要的转换。  
```
scala> val t = new Thermometer
t: Thermometer = 32.0F/0.0C

scala> t.celsius = 100
t.celsius: Flloat = 100.0

scala> t
res3: Thermometer = 212.0F/100.0C

scala> t.fahrenheit = -40
t.fahrenheit: Float = -40.0

scala> t
res4: Thermometer = -40.0F/-40.0C
```  

## 用描述数字电路的语言
&emsp;&emsp;我们从描述数字电路的“小型语言”开始。数字电路由线wire和功能箱function box 组成。线负责传递信号signal，而功能箱对信号进行转换。信号以布尔值表示：true代表信号开启，false代表信号关闭。
&emsp;&emsp;我们将用下列scala类和函数来表述数字电路的元素。首先，有一个wire类来表示线。可以像这样构建线：  
```
val a = new Wire
val b = new Wire
val c = new Wire
```  
或者：  
```
val a, b ,c = Wire
```  
&emsp;&emsp;其次，还有三个过程procedure可以用来“制作”我们需要的基本的门：  
```
def incerter(input: Wire, output: Wire)
def andGate(a1: Wire, a2: Wire, output: Wire)
def orGate(o1: Wire, o2: Wire, output:Wire)
```  
&emsp;&emsp;考虑到scala对于函数式的强调，有个不太寻常的地方是这些过程是以副作用的形式来构建门的。举例来说，调用inverter(a, b)会在a和b两条线之间放置一个反转器。我们会发现这种通过副作用进行构建的方式让我们比较容易逐步构建出复杂的电路。除此之外，尽管方法通常都以动词命名，这里的方法命名用的都是名词，表示它们构建出来的门。这体现出的是DSL的声明性：它应该描述电路本身，而不是制作线路的行为。  
&emsp;&emsp;通过这些基本的门可以构建更复杂的功能箱。比如下面构建的半加器。halfAdder方法接收两个输入信号a和b，产出一个由"s = (a + b) % 2"的和（sum）s，以及一个由"c = (a + b) / 2"的进位信号carry c。  
```
def halfAdder(a: Wire, b: Wire, s: Wire, c: Wire) = {
    val d, e = new Wire
    orGate(a, b, d)
    andGate(a. b. c)
    inverter(c, e)
    andGate(d, e, s)
}
```  
&emsp;&emsp;注意，halfAdder也是一个参数化的功能箱。可以使用halfAdder来构建更复杂的电路。如下面定义了一字节的全加器，接收两个输入信号a和b，以及一个低位进位cin，产出一个"sum = (a + b + cin) % 2"定义的输出和，以及一个由“cout = (a + b + cin) / 2"定义的高位进位输出信号。  
```
def fullAdder(a: Wire, b: Wire, cin: Wire, sum: Wire, cout: Wire) = {
    val s, c1, c2 = new Wire
    halfAdder(a, cin, s, c1)
    halfAdder(b, s, sum, c2)
    orGate(c1, c2, cout)
}
```  
&emsp;&emsp;Wire和inverter、andGate、orGate函数构成了用户用来定义数字电路的小型语言。这是内部DSL绝佳示例。一个在宿主语言中以类库形式定义（而非独立实现）的领域特定语言。  
&emsp;&emsp;我们的电路DSL实现仍需要打磨。由于用DSL定义电路的目的是模拟这个电路，我们有理由将这个DSL基于一个通用的离散时间模拟来实现。  

## Simulation API
```
//定义一个抽象类，用来模拟调度系统
abstract class Simulation {

    //定义一个类型，表示不带参数且返回值为Unit的函数
    type Action = () => Unit

    //定义一个样例类，表示一个工作项
    case class WorkItem(time: Int, action: Action)

    // 定义一个私有变量 `curtime`，表示当前时间，初始值为 0。
    private var curtime = 0

    // 定义一个公开方法 `currentTime`，返回当前时间。
    def currentTime: Int = curtime

    // 定义一个私有变量 `agenda`，表示工作项的列表，初始为空
    private var agenda: List[WorkItem] = List()

    // 定义一个私有方法 `insert`，将一个工作项按时间顺序插入到工作列表中
    private def insety(ag: List[WorkItem], item: WorkItem): List[WorkItem] = {
        // 如果列表为空，或者当前工作项的时间早于第一个工作项，则将其插入到列表前端。
        if (ag.isEmpty || item.time < ag.head.time) item :: ag

         // 否则递归处理，继续检查列表的剩余部分
        else ag.head :: insert(ag.tail, item)
    }

    // 定义一个方法 `afterDelay`，用于在指定的延迟时间后安排执行某个操作。
    def afterDelay(delay: Int)(block: => Unit) ={

        // 创建一个新的工作项，时间为当前时间加延迟时间，操作为传入的代码块。
        val item = WorkItem(currentTime + delay, () => block)

         // 将新工作项插入到工作列表中。
        agenda = insert(agenda, item)
    }

    // 定义一个私有方法 `next`，执行下一个工作项。
    private def next() = {
        // 对 `agenda` 模式匹配，假设其非空（`@unchecked` 表示忽略警告）。
        (agenda: @unchecked) match {
            // 如果列表非空，取出第一个工作项并将其余部分赋值给 `rest`。
            case item :: rest =>

                // 更新工作列表。
                agenda = rest
                // 更新当前时间为当前工作项的时间。
                curtime = item.time
                // 执行当前工作项的操作
                item.action()
        }
    }
    // 定义一个方法 `run`，用于运行模拟。
    def run() = {
        // 在时间为 0 的时候安排一个操作，表示模拟的开始。
        afterDelay(0) {
            println("*** simulation started, time = " + currentTime + " ***")
        }
        // 当工作列表不为空时，依次执行工作项。打
        while (!agenda.isEmpty) next()
    }
}
```  
&emsp;&emsp;模拟API如上面所示。它包含了org.stairwaybook.simlulation包的Simulation类。具体的模拟类库继承自这个类，并补充扩展领域特定的功能。  
&emsp;&emsp;离散事件模拟在指定的事件执行用户定义的动作。所有具有模拟子类定义的动作都如下类型的：type Action = () => Unti
&emsp;&emsp;这条语句将Action定义为接收空参数列表并返回Unit的过程类型的别名。动作被执行的事件是模拟时间，跟实际的“挂钟”时间无关，模拟时间简单地以整数表示，当前的模拟时间保存在私有变量里：private var curtime: Int = 0  
&emsp;&emsp;这个变量有一个公有的访问方法，用于获取当前时间：def currentTime: Int = curtime  
&emsp;&emsp;这样的私有变量和公有访问方法的组合用来确保当前时间不会被SImulation类外部修改。毕竟，你并不想让你的模拟对象来操纵当前时间，除非你的模拟场景要考虑时间旅行。  

## 电路模拟
&emsp;&emsp;电路DSL由表示线的类和创建与门、或门和反转器的方法构成。所有这些都包含在BasicCiruitSimulation类中，这个类继承自模拟框架。  
```
package org.stairwaybook.simulation

//声明一个抽象类BasicCircuitSimulation，继承自 Simulation 抽象类。
abstract class BasicCiruitSimulation extends Simulation {

    //声明三个抽象方法来表示基本门的延迟
    def InverterDelay: Int
    def AndGateDelay: Int
    def OrGateDelay: Int

    // 定义一个类 Wire，表示电路中的导线。
    class Wire {
        
        private var sigVal = false                  // 私有变量 sigVal，存储导线的当前信号，初始值为 false。
        private var actions: List[Action] = List()  // 私有变量 actions，存储与该导线相关的操作列表。
        def getSignal = sigVal                      //返回线的当前信号
        def setSignal(s: Boolean) =                 //将线的信号设置为s
            if (s != sigVal) {                      // 如果新信号值与当前信号值不同，则更新信号值，并触发所有相关操作。
                sigVal = s
                actions foreach (_ ())              // 遍历 actions 列表并执行每个操作。
            }

        // 方法 addAction，用于向导线添加一个新的操作。
        // 将操作添加到 actions 列表，并立即执行该操作。
        def addAction(a: Action) = {
            actions = a :: actions
            a()
        }
    }

    // 方法 inverter，定义一个反相器（Inverter）的行为。
    // 输入为 input 导线，输出为 output 导线。
    def inverter(input: Wire, output:Wire) = {
        def invertAction() = {                      // 定义反相器的具体操作。
            val inputSig = input.getSignal          // 获取输入导线的当前信号。
            afterDelay(InverterDelay) {             // 在反相器延迟后设置输出信号。
                output setSignal !inputSig          // 输出信号为输入信号的反值。
            }
        }
        input addAction invertAction                // 将反相操作添加到输入导线的操作列表中。
    }

    // 方法 andGate，定义一个与门（AND Gate）的行为。
    // 输入为 a1 和 a2 两根导线，输出为 output 导线。
    def andGate(a1: WIre, a2: Wire, output: Wire) = {

         
        def andAction() = {                         // 定义与门的具体操作。
            val a1Sig = a1.getSignal                // 获取第一根输入导线的信号。
            val a2Sig = a2.getSignal                // 获取第二根输入导线的信号。
            afterDelay(AndGateDelay) {              // 在与门延迟后设置输出信号。
                output setSignal (a1Sig & a2Sig)    // 输出信号为两个输入信号的逻辑与
            }
        }
        a1 addAction andAction                      // 将与操作添加到第一根输入导线的操作列表中。
        a2 addAction andAction                      // 将与操作添加到第二根输入导线的操作列表中。
    }

    // 方法 orGate，定义一个或门（OR Gate）的行为。
    // 输入为 o1 和 o2 两根导线，输出为 output 导线。
    def orGate(o1: Wire, 02: Wire, output: Wire) = {

        // 定义或门的具体操作。
        def orAction() = {
            val o1Sig = o1.getSignal                // 获取第一根输入导线的信号。
            val o2Sig = o2.getSignal                // 获取第二根输入导线的信号。
            afterDelay(OrGateDelay) {               // 在或门延迟后设置输出信号。
                output setSignal (o1Sig | o2Sig)    // 输出信号为两个输入信号的逻辑或。
            }
            o1 addAction orAction                   // 将或操作添加到第一根输入导线的操作列表中。
            o2 addAction orAction                   // 将或操作添加到第二根输入导线的操作列表中。
        }

        // 方法 probe，用于监视导线的信号变化。
        // 输入为导线的名称 name 和需要监视的导线 wire。
        def probe(name: String, wire: Wire) = {

            // 定义监视操作。
            def probeAction() = {

                // 打印导线的名称、当前时间和新信号值。
                println(name + " " + currentTime + " new-value = " + wire.getSignal)
            }
            wire addAction probeAction  // 将监视操作添加到导线的操作列表中。
        }
    }
}
```  
### Wire类
&emsp;&emsp;线的状态由两个私有变量决定。sigVal变量表示当前的信号，而actions表示当前附加到线上的动作过程。唯一有趣的方法实现是setSignal：当线的信号发生变化时，新的值被存在变量sigVal中。不只如此，所有附加到线上的动作都会被执行。注意执行这个操作的简写语法："actions foreach(_())"，这段代码会对actions列表中的每个元素应用函数"_()"。正如我们所说，函数"_()"时"f => f()“的简写，它接收一个函数并将它应用到空的参数列表。  

### inverter方法
&emsp;&emsp;创建反转器的唯一作用是一个动作安装到输入线上。这个动作在安装时执行一次，然后每次输入变化时都会再次执行。这个动作的效果时设置反转器的输出值为与输入相反的值。由于反转器有延迟，这个变化只有在输入值变更后的InverterDelay的模拟时间过后才会被执行。  
&emsp;&emsp;该方法的作用是将invertAction添加到输入线。这个动作在执行时会读取输入信号并安装另一个将输出信号反转的动作到模拟日程中。后一个动作将在InverterDelay的模拟时间后执行。  

### andGate,orGate方法
&emsp;&emsp;与门的实现跟反转器的实现类似。与门的目的是输出其输出信号的逻辑与结果。这应该在两个输入中任何一个发生变化后的AndGateDelay模拟时间后发生。andGate方法的作用是添加一个andAction到两个输入线a1和a2.当这个动作被调用时，同时获取两个输入信号并安装另一个动作，将output信号设置为输入信号的逻辑与。后一个动作将在AndGateDelay所指定的模拟时间后执行。注意当任意一根输入线的信号变化时，输出都需要被重新计算。这就是为什么同一个andAction会被同时安装到输入线a1和a2.orGate的实现也类似，不过它执行的是逻辑或，而不是逻辑与计算。  

## 结语
&emsp;&emsp;本章将两种乍看上去毫不相干的技巧结合到了一起：可变状态和高阶函数。可变状态用于模拟那些状态随时间改变的物理实体。而高阶函数在模拟框架中用来指定的模拟时间执行动作。高阶函数还在电路模拟中被当作触发器使用，它们跟状态变化关联起来。在这个过程中，还看到了一种简单的方式，以类库的形式定义领域特定语言。

# 类型参数化
&emsp;&emsp;类型参数化让我们能够编写泛型的类和特质。例如，集set是泛型，接受一个类型参数：定义为Set[T]。这样，具体的集的实例可以是Set[String],Set[Int]等，不过它必须是某种类型的集。与java不同，scala并不允许原生类型，sclala要求我们给出类型参数。型变定义了参数化类型的继承关系，以Set[String]为例，型变定义了它是不是Set[AnyRef]的子类型。  

## 函数式队列
&emsp;&emsp;函数式队列是一个数据结构，它支持三种操作：  
```
head        //返回队列的第一个元素
tail        //返回除第一个元素以外的队列
enqueue     //返回一个将给定元素追加到队尾的新队列
```  
基本的函数式队列：  
```

//定义一个泛型类Queue，表示队列。
class Queue[T](
    private val leading: List[T],   //leading，队列前部的元素列表，先进先出
    private val trailing: List[T]   //trailing，队列后部元素列表（后进先出）
) {
    private def mirror =            //需要时trailing的内容反转并移到leading

    //如果为空则将trailing反转后作为新的leading
    if (leading.isEmpty) new Queue(trailing.reverse, Nil)
    //否则。直接返回当前队列
    else this

    //方法head，返回队列的第一个元素
    def head = mirror.leading.head

    //方法tail，返回除了第一个元素的其他元素
    def tail = {
        val q = mirror
        new Queue(q.leading.tail, q.trailing)
    }

    //方法enqueue，用于将新元素添加到队列的末尾
    //创建一个新的队列，将新月速添加到trailing列表的前端
    def enqueue(x: T) = new Queue(leading, x :: trailing)
}
```  
## 信息隐藏
### 私有构造方法和工厂方法
&emsp;&emsp;在java中，我们可以通过标记为private来隐藏构造方法。在scala中，主构造方法并没有显式的定义，它是通过类参数和类定义体隐式地定义的。尽管如此，还时可以通过在参数列表前加上private修饰符来隐藏主构造方法：  
```
class Queue[T] private (
    private val leading: List[T],
    private val trailing: List[T])
```  
&emsp;&emsp;类名和参数之间的private修饰符表示Queue的构造方法是私有的：它只能从类本身及伴生对象访问。类名Queue依然是公有的，因此可以把它当作类型来使用，但不能调用其构造方法。  
&emsp;&emsp;既然Queue类的主构造方法不能从使用方代码调用，我们需要别的方式来创建新的队列。一种可能的方式是添加一个辅助构造方法，就像这样“def this() = this(Nul, Nil)”
&emsp;&emsp;前一例子中给出的辅助构造方法构建一个空的队列。我们可以再提炼一下，让辅助构造方法接收一组初始队列元素：def this(elems: T*) = this(elem.toList, Nil)  
&emsp;&emsp;另一种可能是添加一个工厂方法来从这样一组初始元素来构建队列。一种不错的实现方式是定义一个跟Queue类同名的对象，并提供apply方法，如：  
```
object Queue {
    //用初始值XS构造队列
    def apply[T](xs: T*) = new Queue[T](xs.toList, Nil)
}
```  
&emsp;&emsp;通过将这个对象跟Queue类放在同一个源文件中，我们就让对象成为了Queue类的伴生对象。伴生对象拥有与对应伴生类相同的访问权限。因此Queue对象的apply方法可以创建一个新的Queue，尽管Queue类的构造方法是私有的。  
&emsp;&emsp;注意，由于这个工厂方法的名称是apply，使用方代码可以用诸如Queue(1, 2, 3)这样的表达式来创建队列。这个表达式会展开成Queue.apply(1, 2, 3)，因为Queue是对象而不是函数。这样一来，Queue在使用方看来，就像是全局定义的工厂方法一样。实际上，scala并没有全局可见的方法，每个方法都必须被包含在某个对象或某个类当中。不过，通过在全局对象中使用名为apply的方法，可以支持看上去像是全局方法的使用模式。  

**备选方案：私有类：**  
&emsp;&emsp;私有构造方法和私有成员只是隐藏类的初始化和内部表现形式的一种方式。另一种更激进的方式是隐藏类本身，并且只暴露一个反映类的公有接口特质。  
&emsp;&emsp;下面实例实现了这样一种设计。其中定义了一个Queue特质，声明了方法head，tail和enqueue。所有这三种方法都实现在子类QueueImpl中，这个子类的信息跟之前一样，不过采用了不同的技巧。跟之前逐个隐藏构造方法和成员方法不同，这个版本隐藏了整个实现类。  
```
//定义一个泛型的Queue特质，用于表示队列的接口
trait Queue[T] {
    def head: T                 //抽象方法head，返回队列第一个元素
    def tail: Queue[T]          //抽象方法tail，返回去掉队首后的队列
    def enqueue(x: T): Queue[T] //抽象方法，向队列尾部添加一个元素并返回新队列
}

//伴生对象，提供辅助方法来创建队列
object Queue {

    //apply方法，用于根据变长参数创建一个队列实例
    //将可变参数转化为队列，并调用QueueImpl来构建队列
    def apply[T](xs: T*): Queue[T] = new QueueImpl[T](xs: toList, Nil)

    private class QueueImpl[T](         //定义一个私有内部类，实现队列具体逻辑
        private val leading: List[T],   //私有字段，存储队列前部元素，按顺序排序
        private val trailing: List[T]   //私有字段，存储队列后部元素，逆序排序
    ) extends Queue[T] {

        //私有方法mirror，用于将trailing的元素反转并转移到leading
        def mirror = 
            //如果leading为空，则将trailing反转后作为新的leading
            if (leading.isEmpty) new QueueImpl(trailing.reverse, Nil)
            //否则直接返回当前队列实例
            else this
        
        def head: T = mirror.leading.head   //实现head方法，返回队列首个元素
        def tail: QueueImpl[T] = {          //实现tail方法，返回除队首元素
            val q = mirror                  //确保leading不为空

            //创建一个新的QueueImpl，去掉leading的第一个元素。
            new QueueImpl(q.leading.tail, q.trailing)
        }
        //实现enqueue方法，在队尾添加新元素，创建新的队列，将元素添加到trailing前端
        def enqueue(x: T) = new QueueImpl(leading, x :: trailing)
    }
}
```  
## 型变注解
&emsp;&emsp;上面示例的Queue是一个特质，而不是一个类型。Queue不是类型，因为它接收一个类型参数。因此，我们并不能创建类型位Queue的变量。反而，Queue特质让我们可以指定参数化的类型，比如Queue[String],Queue[Int],Queue[AnyRef]等：  
```
scala> def doesCompile(q: Queue[AnyRef]) = {}
doesCompile: (q: Queue[AnyRef])Unit
```  
&emsp;&emsp;所以Queue是一个特质，而Queue[String]是一个类型。Queue也被称作类型构造方法，因为我们可以通过指定类型参数来构造一个类型（这根通过指定值参数来构造对象实例的普通构造方法的道理是一样的）。类型构造方法Queue能够“生成”成组的类型，包括Queue[Int],Queue[String],Queue[AnyRef]。




