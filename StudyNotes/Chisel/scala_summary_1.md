- [第一部分：每章简述](#第一部分每章简述)
- [第二部分：对于书中的知识点整理](#第二部分对于书中的知识点整理)
  - [第1：scala的简介](#第1scala的简介)
    - [scala是什么](#scala是什么)
    - [scala的核心理念](#scala的核心理念)
    - [scala的特点](#scala的特点)
      - [scala是兼容的](#scala是兼容的)
      - [scala是精简的](#scala是精简的)
      - [scala是高级的](#scala是高级的)
      - [scala是静态类型的](#scala是静态类型的)
    - [表达式](#表达式)
      - [什么是表达式？](#什么是表达式)
      - [scala中常见的表达式类型](#scala中常见的表达式类型)
      - [表达式和语句的区别](#表达式和语句的区别)
  - [第2：scala入门](#第2scala入门)
    - [scala的变量](#scala的变量)
    - [scala的函数](#scala的函数)
    - [scala脚本](#scala脚本)
    - [用while做循环；用if做判断](#用while做循环用if做判断)
    - [用foreach和for遍历](#用foreach和for遍历)
      - [区别1：语法和使用方式](#区别1语法和使用方式)
      - [区别2：返回值](#区别2返回值)
      - [区别3：副作用和函数式编程风格](#区别3副作用和函数式编程风格)
      - [区别4：性能差异](#区别4性能差异)
      - [总结](#总结)
  - [第3：scala入门（续）](#第3scala入门续)
    - [用类型参数化数组](#用类型参数化数组)
    - [使用列表（列表和数组的区别）](#使用列表列表和数组的区别)
      - [1.实现方式](#1实现方式)
      - [2.不可变性](#2不可变性)
      - [3.性能](#3性能)
      - [4.类型推倒与泛型支持](#4类型推倒与泛型支持)
      - [5.使用场景](#5使用场景)
    - [元组](#元组)
      - [1. 元组的特点](#1-元组的特点)
      - [2.创建元组](#2创建元组)
      - [3.访问元组元素](#3访问元组元素)
      - [4.元组的常见操作](#4元组的常见操作)
      - [5.元组与函数](#5元组与函数)
      - [6.元组与集合](#6元组与集合)
      - [7.常见用途](#7常见用途)
      - [8.与 case class 的对比](#8与-case-class-的对比)
    - [使用集set和映射map](#使用集set和映射map)
      - [集set](#集set)
      - [映射map](#映射map)
      - [集set和map的关系](#集set和map的关系)
    - [函数式风格](#函数式风格)
      - [1.纯函数](#1纯函数)
      - [2.不可变性](#2不可变性-1)
      - [3.高阶函数](#3高阶函数)
      - [4.函数组合](#4函数组合)
      - [5.不可变数据结构](#5不可变数据结构)
      - [6.表达式优先](#6表达式优先)
      - [7.闭包](#7闭包)
      - [8.类型推导和泛型](#8类型推导和泛型)
      - [9.尾递归优化](#9尾递归优化)
      - [10.模式匹配](#10模式匹配)
  - [第4： 类和对象](#第4-类和对象)
    - [类](#类)
    - [字段](#字段)
    - [方法](#方法)
    - [样例类（简单介绍）](#样例类简单介绍)
    - [单例对象](#单例对象)



# 第一部分：每章简述
**scala入门：**             介绍了如何用scala完成一些基础的编程任务，但并不深入讲解它们是如何工作的。后面更多的展示了基本的编程任务，帮助快速上手scala。  
**类和对象：**               开始深入介绍scala，描述其基本的面向对象的组成部分，并指导如何编译并运行scala应用程序  
**基本类型和操作：**          介绍了scala基本类型、字面量和支持的操作，（操作符的）优先级和结合性，以及对应的富包装类  
**函数式对象：**             以函数式（即不可变）的分数为例，更深入地讲解scala面向对象的特性  
**内建的控制结构：**          展示了如何使用scala内建控制结构：if、while、for、try和match  
**函数和闭包：**             给出了对函数的深入介绍，而函数是对函数式编程最基本的组成部分  
**控制抽象：**               展示了如何通过定义自己的控制抽象来对scala基本的控制结构进行完善和补充  
**组合和继承：**             更进异步探讨scala对面向对象编程的支持。  
**scala的继承关系：**        解释了scala的继承关系，并探讨了通用方法和底类型等概念。  
**特质：**                  介绍了scala的混入mixin组合机制。本章展示了特质的工作原理，描述了特质的常见用法，并解释了特质相对于更传统的多重继承有哪些改进。  
**包和引入：**               讨论了大规模编程实践中我们会遇到的问题，包括顶级包、import语句，以及像protected和private那样的访问控制修饰符。  
**断言和测试：**             展示了scala的断言机制，介绍了用scala编程写测试的若干工具，特别是ScalaTest  
**样例类和模式匹配：**        介绍了这组孪生的结构，让你更好地编写规则的、开放式的数据结构。样例类和模式匹配在处理树形的递归数据时非常有用。  
**使用列表：**               详细地解释了列表这个在scala程序中使用最普遍的数据结构。  
**使用其他集合类：**          展示了如何使用基本的scala集合，如列表、数组、元组、集和映射。  
**可变对象：**               解释了可变对象，以及scala用来表示它们的语法。  
**类型参数化：**             用具体的示例解释了信息隐藏的技巧：为纯函数式队列设计的类。后面将对类型参数的型变进行说明，介绍了类型参数化对于信息隐藏的作用。  




# 第二部分：对于书中的知识点整理
## 第1：scala的简介
### scala是什么
&emsp;&emsp;scala是面向对象和函数式编程的结合。在scala中，函数值就是对象，而函数的类型就是可被子类继承的类。  

&emsp;&emsp;鉴于一切值都是对象，可以说Scala是一门纯面向对象的语言。对象的类型和行为是由类和特质来描述的。类可以由子类化和一种灵活的、基于混入mixin的组合机制（它可作为多重继承的简单替代方案）来扩展。  

&emsp;&emsp;鉴于一切函数都是值，又可以说Scala是一门函数式语言。Scala为定义匿名函数提供了轻量级的语法，支持高阶函数，允许函数嵌套及柯里化。Scala的样例类和内置支持的模式匹配代数模型在许多函数式编程语言中都被使用。对于那些并非类的成员函数，单例对象提供了便捷的方式去组织它们。  

&emsp;&emsp;此外，通过对提取器的一般扩展，Scala的模式匹配概念使用了right-ignoring序列模式，自然地延伸到XML数据的处理。其中，for表达式对于构建查询很有用。这些特性使得Scala成为开发web服务等程序的理想选择。  
***
### scala的核心理念
&emsp;&emsp;第一个理念： 函数是一等的值。在函数式编程语言中，函数值的低位跟整数、字符串等是相同的。可以将函数作为参数传递给其他函数，作为返回值返回它们，或者将它们保存在变量里。还可以在函数中定义另一个函数，就像在函数中定义整数那样。也可以在定义函数时不指定名字。  
&emsp;&emsp;第二个理念： 是程序中的操作应该将输入映射成输出值，而不是当场in place 修改数据。该理念的另一种表述是方法不应该有副作用。方法只能通过接收入参和返回结果这两种方式与外部环境通信。举例来说，java的string类的replace方法便符合这个描述：它接收一个字符串（对象本身）、两个字符，交出一个新的字符串，其中所有出现的入参第一个字符都被替换成了入参的第二个字符。调用replace并没有其他的作用。**像这样的方法被认为是“指称透明的”，意思是对于任何给定的输入，该方法调用都可以被其结果替换，同时不会影响程序的语义。**  
***
***
### scala的特点
#### scala是兼容的 
&emsp;&emsp;能够与java无缝互调，scala重度复用java的类型，也会对java原生的类型进行“再包装”。  

#### scala是精简的
&emsp;&emsp;scala编写的程序通常都比较短。有些代码根本不用写，类库都帮忙写好了。scala提供了大量的工具来定义功能强大的类库。可以捕获那些公共的行为，并将它们抽象出来。  

#### scala是高级的
&emsp;&emsp;scala提供的帮助在于提升接口设计的抽象级别，能够让人更好的管理复杂度。scala的函数字面量非常轻。  

#### scala是静态类型的
&emsp;&emsp;静态的类型系统根据变量和表达式所包含和计算的值的类型来对它们进行归类。scala和其他语言相比，一个重要的特点是它拥有非常先进的静态类型系统。scala不仅拥有和java类似的允许嵌套类的类型系统，它还允许使用泛型来对类型进行参数化，用交集来组合类型，以及用抽象类型来隐藏类型的细节。scala很好的解决了静态类型的两个常见痛点：通过类型推断规避了过于啰嗦的问题，通过模式匹配以及其他编写和组合类型的新方式避免了死板。  
***

### 表达式
&emsp;&emsp;在 Scala 中，表达式（Expression） 是一种计算结构，它会产生一个值，并且几乎所有代码结构都是表达式。这是 Scala 的一个关键特性，因为它是一个面向表达式的语言，与一些面向语句的语言（如 Java）形成对比。  

#### 什么是表达式？
表达式是可以计算并返回结果的代码块。  
表达式的求值不会修改外部状态，通常用来生成值。  
表达式在计算后总会有一个值（可能是 Unit）。  

#### scala中常见的表达式类型
**1.字面量表达式**  
**2.变量或常量引用**  
**3.算术和逻辑运算**  
**4.函数调用**  
**5.条件表达式**  
**6.代码块**  
**7.匹配表达式（模式匹配）**  
**8.匿名函数（Lambda表达式）**  
**9.循环表达式for**  
**10.异常处理表达式**  

#### 表达式和语句的区别
**表达式：**1,总有返回值；2.偏向于声明式风格。  
**语句：**1.用来执行动作，不返回值；2.通常会产生副作用（如修改变量或输出）；3.在scala中尽可能使用表达式。  


## 第2：scala入门  
### scala的变量
&emsp;&emsp;**val**  与java的final变量类似，一旦初始化就不能被重新赋值。  
&emsp;&emsp;**var**  与java的非final变量类似，在整个生命周期内var可以被重新赋值。

### scala的函数
&emsp;&emsp;在scala中，函数的定义从def开始：  
```
def 函数名(参数: 参数类型): 函数结果的类型 = {
    函数体
}
```  
函数是带有参数的表达式。  
你可以定义一个匿名函数（即没有名字），来返回一个给定整数加一的结果。  
```
(x: Int) => x + 1   //=>的左边是参数列表，右边是一个包含参数的表达式。
```  

你也可以给函数命名。  
```
val addOne = (x: Int) => x + 1
println(addOne(1))  //2
```  

函数可带有多个参数。  
```
val add = (x: Int, y: Int) => x + y
println(add(1, 2))  //3
```  

或者不带参数。  
```
val getTheAnswer = () =>42
println(getTheAnswer()) //42
```  

***

### scala脚本
&emsp;&emsp;scala脚本是以".scala"结尾的。  

***

### 用while做循环；用if做判断

***

### 用foreach和for遍历
在 Scala 中，foreach 和 for 都是用来遍历集合的常见方法，但它们有一些不同的特性和用法。
#### 区别1：语法和使用方式
&emsp;&emsp;foreach 是集合的方法，用于对集合中的每个元素执行一个操作。它是高阶函数，通常用于处理副作用（如打印、更新状态等），而不会返回值（也可以说是返回空Unit）。  
```
val numbers = List(1, 2, 3, 4, 5)
numbers.foreach(println)  // 对集合中的每个元素执行 println 操作
```  
&emsp;&emsp;for 是一种控制结构（表达式），用于生成循环或集合的推导，可以返回一个新的集合，也可以用于执行副作用。for 循环可以包含过滤条件和生成新集合的功能。  
```
val numbers = List(1, 2, 3, 4, 5)
for (num <- numbers) println(num)  // 对集合中的每个元素执行 println 操作
```  
#### 区别2：返回值
&emsp;&emsp;foreach 没有返回值，它是一个用于执行副作用的操作。返回类型为 Unit，即没有返回任何值。  
```
val numbers = List(1, 2, 3, 4, 5)
val result = numbers.foreach(println)  // result 的类型是 Unit
```  

&emsp;&emsp;for 可以作为一个表达式，返回一个值。可以通过 yield 关键字返回一个新的集合。
```
val numbers = List(1, 2, 3, 4, 5)
val squared = for (num <- numbers) yield num * num  // 返回一个新的集合
println(squared)  // List(1, 4, 9, 16, 25)
```  
&emsp;&emsp;**yield关键字** 是和for循环一起使用的。它在每个for循环迭代中存储一个变量。存储的变量组合在一起，以创建与for循环在同一时间运行的新结构。例如，在映射上使用yield会为列表，数组向量等提供类似的映射结构。  

#### 区别3：副作用和函数式编程风格
&emsp;&emsp;foreach 更倾向于函数式编程的副作用方法，常用于执行操作而不关心返回值。  
```
val numbers = List(1, 2, 3, 4, 5)
numbers.foreach { num =>
  // 执行一些副作用
  println(s"Number: $num")
}
```  
&emsp;&emsp;for 提供了一种灵活的方式，可以在包含条件的情况下遍历集合，也可以返回计算结果。for 表达式适合用于生成新的集合或处理复杂的逻辑。  
```
val numbers = List(1, 2, 3, 4, 5)
val evenSquares = for (num <- numbers if num % 2 == 0) yield num * num
println(evenSquares)  // List(4, 16)
```  
#### 区别4：性能差异
&emsp;&emsp;在大多数情况下，foreach 和 for 表现相似。但当你希望通过 yield 创建新的集合时，for 表达式会更灵活和有表现力。  

#### 总结
**foreach：** 用于执行副作用，返回 Unit，不能生成新的集合。
**for：** 可以作为表达式，支持 yield 返回新集合，也可以用于执行副作用，但更常用于需要条件或推导的场景。  

## 第3：scala入门（续）
### 用类型参数化数组  
**实例化：** 用new来实例化对象或类的实例。  
**参数化：** 在实例化对象时，可以用值和类型对其进行参数化。参数化的意思是在创建实例时对实例做“配置”。可以用值来参数化一个实例，也可以用类型来参数化一个实例（做法是在方括号里给出一个或多个类型）。  

示例：用类型参数化一个数组（不推荐做法）  
```
//一个类型为Array[String]的值（一个“字符串数组Array”）,被初始化长度为3的数组
val greetStrings = new Array[String](3) //注意当同时用类型和值来参数化一个实例时，先用方括号包起来的类型（参数），然后才是用圆括号包起来的值（参数）
greetString(0) = "Hello"
greetString(1) = ","
greetString(2) = "world!\n"
for (i <- 0 to 2)
    println(greetStrings(i))
```  

更精简的方式来创建和初始化数组：  
```
val numNames = Array("zero", "one", "two")
```  
&emsp;&emsp;由于传的是字符串，编译器推断出数组类型为Array[String]，这里使用了Array的伴生对象的apply方法，上面的代码等效为：  
```
val numNames: Array[String] = Array.apply("zero", "one", "two")
```  
***
### 使用列表（列表和数组的区别）  
&emsp;&emsp;函数式编程的最重要理念之一是方法不能有副作用。一个方法唯一要做的是计算并返回一个值。这样做的好处是方法不再互相纠缠在一起，因此变得可靠、更易复用。  
&emsp;&emsp;另一个好处（作为静态类型的编程语言）是类型检查器会检查方法的入参和出参，因此逻辑错误通常都以类型错误的形式出现。将这个函数式的哲学应用到对象的世界意味着让对象不可变。  
&emsp;&emsp;数组是一个拥有相同类型的对象的可变序列（可变对象），虽然无法在数组实例化以后改变其长度，但是却可以改变它的值。  
&emsp;&emsp;对于需要拥有相同类型的对象的不可变序列，可以使用scala的List类（列表）。和数组类似，一个List[String]只能包含字符串。  

&emsp;&emsp;在 Scala 中，列表（List） 和 数组（Array） 是两种常用的数据结构，但它们在实现方式、功能和使用场景上有明显的区别。

#### 1.实现方式
**列表List：** 1.是不可变的链表；2.每个元素包含两个部分：值和指向下一个元素的引用；3.头尾结构：List是有head和tail组成；4.典型操作是高效的头部追加或遍历。  
**数组Array：** 1.可变的连续内存块；2.元素通过索引村去，类似java的数组；3.支持快速的随机访问和更新。  

#### 2.不可变性
**列表List：** 1.是不可变的，任何修改操作都会返回一个新的列表，而原列表保持不变；2.适合函数式编程场景，能避免副作用  
**数组Array：** 1.是可变的，支持直接修改元素；2.修改操作会改变原数组的内容。

#### 3.性能
**列表List：**1.方伪呢首元素head和添加首元素：：的操作时间复杂度是O(1)；2随机访问或在末尾追加元素需要遍历列表，时间复杂度为O(n)；3.更适合需要频繁构造、分解列表的场景  
**数组Array：**1.访问或更新元素的时间复杂度是O(1)；2.插入或删除需要移动数据，操作复杂度可能是 O(n)；3.更适合需要频繁随机访问或更新元素的场景。  

#### 4.类型推倒与泛型支持
**列表List：**1.是泛型集合，类型可以是任意类型；2.编译器会进行类型推断，确保类型安全。  
```
val list: List[Int] = List(1, 2, 3)  // 整数列表
val mixedList = List(1, "two", 3.0) // 类型为 List[Any]
```  

**数组Array：**1.是具体类型的集合，可以存储基本类型或对象。  
```
val array: Array[Int] = Array(1, 2, 3)
```  
#### 5.使用场景
**列表List：** 1.偏向于不可变性，适合函数式编程风格；2.用于需要频繁构造、分解的场景，例如递归操作、批处理操作等。  
**数组Array：** 1.偏向于可变性，适合指令式编程风格；2.用于需要高效随机访问和更新元素的场景，例如处理大规模数据或实现底层算法。  
***
### 元组
&emsp;&emsp;在 Scala 中，元组（Tuple） 是一种轻量级的数据结构，用于将多个不同类型的值组合在一起。元组可以存储任意数量的元素，且每个元素的类型可以不同。  

#### 1. 元组的特点
**1.固定大小：** 元组的大小在声明时确定，不能动态改变。  
**2.异构性：** 元组中的每个元素可以是不同的类型。  
**3.不可变性：** 默认情况下，元组是不可变的。  
**4.快速存取：** 可以通过元素的索引或模式匹配访问元组的内容。  

#### 2.创建元组
```
val tuple2 = (1, "Scala")         // 一个包含两个元素的元组
val tuple3 = (1, "Scala", 3.14)   // 一个包含三个元素的元组
val tuple0 = ()                   // 一个空元组（Tuple0）
```  
#### 3.访问元组元素
**1.使用点操作（_n）:** 元组中的每个元素都有固定编号，从 _1 开始。  
```
val tuple = (1, "Scala", 3.14)
println(tuple._1)  // 输出：1
println(tuple._2)  // 输出：Scala
println(tuple._3)  // 输出：3.14
```  

**2.使用模式匹配:** 可以通过模式匹配解构元组并提取其值。  
```
val tuple = (1, "Scala", 3.14)
val (a, b, c) = tuple
println(a)  // 输出：1
println(b)  // 输出：Scala
println(c)  // 输出：3.14
```  

#### 4.元组的常见操作
**1. 元素个数**  
使用 productArity 获取元组中元素的个数。  
```
val tuple = (1, "Scala", 3.14)
println(tuple.productArity)  // 输出：3
```  

**2. 判断元素类型**  
使用模式匹配判断元组类型。  
```
val tuple = (1, "Scala")
tuple match {
  case (a: Int, b: String) => println(s"Int: $a, String: $b")
  case _ => println("Unknown tuple")
}
```  

**3. 转换为集合**  
可以将元组转换为列表、数组等集合类型。  
```
val tuple = (1, "Scala", 3.14)
val list = tuple.productIterator.toList
println(list)  // 输出：List(1, Scala, 3.14)
```  

#### 5.元组与函数
元组经常用作函数的输入或输出，用于返回多个值。  
**1. 函数返回元组**  
```
def getPersonInfo(): (String, Int) = {
  ("Alice", 25)  // 返回一个包含名字和年龄的元组
}
val (name, age) = getPersonInfo()
println(s"Name: $name, Age: $age")  // 输出：Name: Alice, Age: 25
```  

**2.使用元组作为函数参数**  
```
def printTuple(tuple: (Int, String)): Unit = {
  println(s"Int: ${tuple._1}, String: ${tuple._2}")
}
printTuple((42, "Hello"))  // 输出：Int: 42, String: Hello
```  

#### 6.元组与集合  
元组与集合的结合使用也很常见，例如在操作 Map 时：  
```
val map = Map(1 -> "Scala", 2 -> "Java", 3 -> "Python")

// 遍历 Map 时会得到 (键, 值) 的元组
map.foreach { case (key, value) =>
  println(s"Key: $key, Value: $value")
}
```  
#### 7.常见用途  
**函数返回多个值：** 用元组返回多个结果，代替定义额外的数据结构。  
**分组数据：** 将相关的数据分组，避免多个变量传递。  
**与集合结合：** 在 Map、分组操作（groupBy）等场景中，元组非常实用。

#### 8.与 case class 的对比
虽然元组方便快速存储多个值，但在规模较大的项目中，推荐使用 case class，因为：  
&emsp;&emsp;可读性：case class 提供命名字段，代码更清晰。  
&emsp;&emsp;类型安全：case class 明确每个字段的含义，而元组字段依赖位置。  

**总结：** 元组是 Scala 中的轻量级数据结构，适合临时组合数据或作为函数返回值，但在大型项目中应优先选择 case class。元组的灵活性和简单性使它在数据处理、函数式编程等场景中非常常用。  

### 使用集set和映射map
&emsp;&emsp;在scala中同时提供了集set和映射map的可变和不可变的不同选择，但使用同样的简单名字。对于集和映射而言，scala通过不同的类继承关系来区分可变和不可变版本。  
&emsp;&emsp;例如，scala的API包含了一个基础的特质trait来表示集set，在此基础上，还提供了两个子特质，一个用于表示可变集，另一个用于表示不可变集。  

#### 集set
定义：Set 是一个无序且不重复的元素集合。  
Scala 默认提供的是不可变集合 scala.collection.immutable.Set。  
如果需要可变集合，可以使用 scala.collection.mutable.Set。  

**不可变set**  
不可变集合在添加或删除元素时，会返回新的集合：  
```
val immutableSet = Set(1, 2, 3)
val newSet = immutableSet + 4  // 添加元素 4，返回新集合
println(immutableSet)         // 输出：Set(1, 2, 3)（原集合未变）
println(newSet)               // 输出：Set(1, 2, 3, 4)
```  

**可变Set**  
可变集合可以直接修改自身内容:  
```
import scala.collection.mutable
val mutableSet = mutable.Set(1, 2, 3)
mutableSet += 4         //修改集合，添加元素 4
mutableSet -= 2         //删除元素 2
println(mutableSet)     //输出：Set(1, 3, 4)
```  

**集合操作：**  
```
val setA = Set(1, 2, 3)
val setB = Set(3, 4, 5)

println(setA union setB)  // 并集：Set(1, 2, 3, 4, 5)
println(setA intersect setB)  // 交集：Set(3)
println(setA diff setB)  // 差集：Set(1, 2)
```  

#### 映射map
定义：Map 是键值对的集合，每个键（key）唯一，对应一个值（value）。  
Scala 默认提供不可变映射 scala.collection.immutable.Map。  
如果需要可变映射，可以使用 scala.collection.mutable.Map。  

**不可变map：**  
不可变映射在更新时会返回一个新的映射。  
```
val immutableMap = Map("a" -> 1, "b" -> 2)
val newMap = immutableMap + ("c" -> 3)  // 添加键值对
println(immutableMap)                  // 输出：Map(a -> 1, b -> 2)
println(newMap)                        // 输出：Map(a -> 1, b -> 2, c -> 3)
``` 
**可变Map:**  
可变映射可以直接修改内容。  
```
import scala.collection.mutable
val mutableMap = mutable.Map("x" -> 10, "y" -> 20)
mutableMap("z") = 30                  // 添加键值对
mutableMap -= "x"                     // 删除键值对
println(mutableMap)                   // 输出：Map(y -> 20, z -> 30)
```  

**常用操作：**
合并两个映射：  
```
val map1 = Map("a" -> 1, "b" -> 2)
val map2 = Map("b" -> 3, "c" -> 4)
val mergedMap = map1 ++ map2  // 合并映射，右侧映射的值覆盖左侧
println(mergedMap)           // 输出：Map(a -> 1, b -> 3, c -> 4)
```  

遍历键值对：  
```
val map = Map("a" -> 1, "b" -> 2)
map.foreach { case (key, value) =>
  println(s"Key: $key, Value: $value")
}
// 输出：
// Key: a, Value: 1
// Key: b, Value: 2
```  

#### 集set和map的关系
Map 可以看作是 Set 的扩展，Set 存储的是单一的值，而 Map 存储的是键值对。  
Map 的键形成一个 Set，每个键都唯一。  

### 函数式风格
函数式风格是一种以函数为核心、强调不可变性和无副作用的编程范式。它建立在数学函数的基础上，以下是函数式编程的一些重要理念：

#### 1.纯函数
纯函数是函数式编程的核心理念之一。  
定义：1.输出只依赖于输入，函数内部不依赖或修改外部状态；2.不产生副作用（如修改全局变量、文件操作或数据库操作等）。  
优点：1.易于测试和调试；2.提高代码的可预测性和重用性。  

示例：  
```
//函数的输出只取决于参数 a 和 b，没有副作用
def add(a: Int, b: Int): Int = a + b
```  

反例：  
```
//increment 是非纯函数，因为它依赖于外部的 counter，并修改了它的值
var counter = 0
def increment(): Int = {
  counter += 1
  counter
}
```  

#### 2.不可变性
数据一旦创建就不能修改，所有的数据变更都通过创建新的数据实现。通过不可变性，避免由于共享状态或并发引发的错误。如果需要改变数据，函数式编程会返回一个新的对象，而不是修改原对象。  
优点：1.更容易进行并发和并行计算;2.保证代码的可预见性和安全性。

示例：  
```
val list = List(1, 2, 3)
val newList = list.map(_ * 2)  // 原始列表 list 未修改
```  

#### 3.高阶函数
函数式编程认为函数是“一等公民”，可以像普通变量一样被传递、返回或存储。  
定义： 高阶函数是可以接受函数作为参数或返回函数的函数。  
优点：1.提高代码的抽象性和复用性;2.更容易实现复杂的逻辑。  

#### 4.函数组合
函数式编程强调将简单的函数组合成更复杂的功能。  
理念：1.小函数负责单一任务;2.使用函数组合器（如 compose 和 andThen）将小函数拼接成复杂的操作。  

示例：  
```
val addOne = (x: Int) => x + 1
val double = (x: Int) => x * 2
val combined = addOne.andThen(double)  // 先加1，再乘2
println(combined(3))  // 输出：8
```  

#### 5.不可变数据结构
不可变数据结构是函数式编程的基础，配合不可变性和纯函数使用。
特点：1.修改不可变数据会创建新的数据，而不是改变原数据;2.Scala 的 List、Map 等集合默认是不可变的。  
优点：1.并发安全;2.更容易推理程序行为。  

#### 6.表达式优先
函数式编程是一种表达式驱动的范式，每个代码块都产生一个值。  
理念：1.所有代码都有返回值，函数或代码块的最后一行就是其值;2.避免无返回值的命令式代码块。  

#### 7.闭包
函数式编程允许函数捕获其定义环境中的变量，这种特性称为闭包。  
定义:闭包是可以“捕获”自由变量并与之绑定的函数。  
优点：1.提供函数上下文的状态;2.有助于创建灵活的函数。  

示例：  
```
def multiplier(factor: Int) = (x: Int) => x * factor
val multiplyBy2 = multiplier(2)
println(multiplyBy2(5))  // 输出：10
```  

#### 8.类型推导和泛型
函数式编程语言（如 Scala）支持类型推导和泛型，使得代码既灵活又安全。  
特点：1.类型推导：编译器会自动推断表达式的类型，无需显式指定;2.泛型：函数和数据结构可以接受任意类型。  

示例：  
```
def identity[A](x: A): A = x
println(identity(42))      // 输出：42
println(identity("Scala")) // 输出：Scala
```  

#### 9.尾递归优化
尾递归是函数式编程的一种常见优化技术，用来提高递归效率。  
义： 尾递归是指递归调用是函数的最后一步，编译器可以将其优化为循环，从而避免栈溢出。  

示例：  
```
@scala.annotation.tailrec
def factorial(n: Int, acc: Int = 1): Int = {
  if (n <= 1) acc
  else factorial(n - 1, n * acc)
}
println(factorial(5))  // 输出：120
```  

#### 10.模式匹配
函数式编程中，模式匹配是一种强大的控制结构，用于解构和处理数据。  
特点：1.提高代码的可读性;2.替代传统的 switch 或 if-else。  

示例：  
```
val x: Any = 42
val result = x match {
  case i: Int => s"Integer: $i"
  case s: String => s"String: $s"
  case _ => "Unknown"
}
println(result)  // 输出：Integer: 42
```  
## 第4： 类和对象
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
&emsp;&emsp;对于结果类型为Unit的方法，上面add方法的执行目的是为了得到其副作用。副作用通常来说指的是改变方法外部的某种状态或者执行I/O的动作。对本例add而言，其副作用是给sum重新赋值。那些仅仅因为其副作用而被执行的方法被称作过程。  

### 类
&emsp;&emsp;类是对象的蓝本。一旦定义好了一个类，就可以用new关键字从这个类蓝本创建对象。在类定义中，会填入字段field和方法method，这些被统称为成员member。
***
### 字段
通过val和var定义的字段是指向对象的变量。字段保留了对象的状态，或者说数据。  

***
### 方法
方法的表现和行为和函数非常类似，但是它们之间有一些关键的差别。  
方法由def关键字定义。def后面跟着一个名字、参数列表、返回类型和方法体。  
```
def add(x: Int, y: Int): Int = x + y
println(add(1, 2))  //3
```   

方法可以接受多个参数列表。  
```
def addThenMultiply(x: Int, y: Int)(multipier: Int): Int = (x + y) * multiplier
println(addThenMultiply(1, 2)(3)) //9
```  

或者没有参数列表。  
```
def name: String = System.getProperty("user.name")
println("Hello," + name + "!")
```  

还有一些其他的区别，但是现在你可以认为方法就是类似于函数的东西。  

方法也可以有多行的表达式。
```
def getSquareString(input: Double): String = {
  val square = input * input
  square.toString
}
println(getSquareString(2.5)) // 6.25
```  
方法体的最后一个表达式就是方法的返回值。（Scala中也有一个return关键字，但是很少使用）  

### 样例类（简单介绍）
scala有一种特殊的类叫作样例类case class。默认情况下，样例类一般用于不可变对象，并且可作值比较。可以使用case class关键字来定义样例类。  
```
case class Point(x: Int, y: Int)  
```  

可以不用new关键字来实例化样例类。  
```
val point = Point(1, 2)
val antherPoint = Point(1, 2)
val yetAnotherPoint = Point(2, 2)
```  

并且它们的值可以进行比较。  
```
if (point == anotherPoint) {
  println(s"$point and $anotherPoint are the same.")
} else {
  println(s"$point and $anotherPoint are different.")
} // Point(1,2) and Point(1,2) are the same.

if (point == yetAnotherPoint) {
  println(s"$point and $yetAnotherPoint are the same.")
} else {
  println(s"$point and $yetAnotherPoint are different.")
} // Point(1,2) and Point(2,2) are different.
```  

### 单例对象
&emsp;&emsp;scala比java更面向对象的一点，是scala不允许有静态static成员。对此类场景，scala提供了单例对象。单例对象的定义看上去跟类定义很像，只不过class关键字换成了object关键字。  

下面例子中的单例对象包含一个方法：  
```
package logging

object Logger {
  def info(message: String): Unit = println(s"INFO: $message")
}
```    
方法info可以在程序中任何地方被引用。像这样创建功能性方法是单例对象的一种常见方法。  

下面让我们看看如何在另一个包中使用info方法：  
```
import logging.Logger.info

class Project(name: String, daysToComplete: Int)

class Test {
  val project1 = new Project("TPS Reports", 1)
  val project2 = new Project(Website redesign", 5)
  info("Created projects")  // Prints "INFO: Created projects"
}
```  

&emsp;&emsp;因为 import 语句 import logging.Logger.info，方法 info 在此处是可见的。  

&emsp;&emsp;import语句要求被导入的标识具有一个“稳定路径”，一个单例对象由于全局唯一，所以具有稳定路径。  

&emsp;&emsp;定义单例对象并不会定义类型（在scala的抽象层级上是这样的）。单例对象可以扩展自某个超类，还可以混入特质，还可以通过这些类型来调用它的方法，用这些类型的变量来引用它，还可以将它传入那些预期这些类型的入参的方法当中。   

&emsp;&emsp;当单例对象跟某个类同名的时候，它被称作这个类的伴生对象。必须在同一个源码文件中定义类和类的伴生对象。同时这个类又叫作这个单例对象的伴生类。**类和它的伴生对象能够互相访问对方的私有成员**。使用伴生对象来定义那些在伴生类中不依赖于实例化对象而存在的成员变量或者方法。  
```
//引入`scala.math` 包中的所有函数和常量（例如 `Pi` 和 `pow`）
import scala.math._

//定义一个不可变的 `Circle` 类，并为它添加一个 `radius` 属性（类型为 `Double`）。
case class Circle(radius: Double) {

  //导入伴生对象 `Circle` 的所有成员（用于在类中直接访问 `Circle` 对象的成员）。
  import Circle._

  // 定义一个方法 `area`，计算圆的面积，返回类型为 `Double`。
  def area: Double = calculateArea(radius)  //使用伴生对象中的方法，传入当前圆的半径
}

// 定义 `Circle` 的伴生对象，方便存放与 `Circle` 类相关的工具方法或静态成员。
object Circle {

  //私有方法
  private def calculateArea(radius: Double): Double = Pi *pow(radius, 2.0)
}

// 创建一个半径为 5.0 的圆实例，调用 `Circle` 的伴生类自动生成的 `apply` 方法。
val circle1 = Circle(5.0)

// 调用 `circle1` 的 `area` 方法，计算圆的面积。
// 这里调用了类中的 `area` 方法，而 `area` 方法进一步调用了伴生对象中的 `calculateArea`
circle1.area
```    
&emsp;&emsp;这里的class Circle 有一个成员 area 是和具体的实例化对象相关的，单例对象 object Circle 包含一个方法 calculateArea ，它在每一个实例化对象中都是可见的。    



