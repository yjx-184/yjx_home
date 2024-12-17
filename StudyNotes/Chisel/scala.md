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

