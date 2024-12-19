- [scala的继承关系](#scala的继承关系)
- [特质](#特质)
  - [特质如何工作](#特质如何工作)
  - [瘦接口和富接口](#瘦接口和富接口)
  - [示例：矩形对象](#示例矩形对象)
  - [Ordered特质](#ordered特质)
  - [作为可叠加修改的特质](#作为可叠加修改的特质)
  - [为什么不用多重继承](#为什么不用多重继承)
  - [要特质还是不要特质](#要特质还是不要特质)



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