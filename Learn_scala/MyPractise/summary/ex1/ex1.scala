object ex1 {
    def main(args: Array[String]): Unit = {

        /*
        方法是定义在类、特质trait或对象object中的函数。使用关键字def。
        方法的特点：
        1.依附于类或对象。
        2.可以重载。
        3.可以访问类的成员。

        函数是一个可以赋值给变量的值，是一等公民，可以像其他值一样被传递，返回和操作。
        函数的特点：
        1.独立存在。
        2.可以作为值传递。
        3.支持高阶函数。
        4.类型明确
        */

        val sum_1 = myadd(3,5)    //方法的调用
        println(s"这是方法的调用: $sum_1") //s是插值器

        val add_MyFunction = (x: Int, y: Int) => x + y //函数的定义
        val sum_2 = add_MyFunction(4,5)
        println(s"这是函数的调用: $sum_2")
        println()

/*
scala的数据结构：分为不可变集和可变集。
不可变集合：列表List，索引序列Vector，无序集合Set（元素唯一），映射Map，元组Tuple（固定数量，可以不同类型）。
可变集合：索引序列ArrayBuffer，链表结构ListBuffer，无序集合HashSet，键值对HashMap。
其他数据结构：Option（表示可能存在或不存在的值），Either（表示两种可能的值之一，通常是成功或失败），LazyList（惰性求值的列表，适合处理无限序列）


Option 是一种用于处理可能存在或不存在的值的容器类型。它是scala标准库中用于替代null的一种更安全的方式。
其有两个子类：
        Some：表示存在一个值
        None：表示没有值
使用Option：
        1.模式匹配：是处理Option的常见方式。
        2.getOrElse方法用于获取Option中的值，如果Option是None，则返回默认值。
        3.使用map和flatMap。
        4.使用filter方法过滤Option的值。
        5.使用foreach方法用于对OPtion中的值执行副作用操作。
        6.使用isDefined和isEmpty。

*/
        //列表List
        /*
        列表三个基本操作：
        1.head    返回列表第一个元素。
        2.tail    返回一个列表，包含除了第一个元素以外的其他元素。
        3.isEmpty 在列表为空时返回true
        */
        //字符串列表
        val mysite: List[String] = List("a", "b", "c")
        //可简写：val mysite = List("a", "b", "c"),scala的类型推断
        println(s"1.这是一个字符串列表mysite: $mysite")

        //整数列表
        val mynums: List[Int] = List(1,2,3)
        println(s"2.这是一个整数列表mynums: $mynums")
        //可简写：val mynums = List(1,2,3)

        val listhead = mysite.head
        println(s"3.这是列表第一个基本操作,使用head返回列表第一个元素 $listhead")

        val listtail = mynums.tail
        println(s"4.tail返回一个列表,包含除了第一个元素以外的其他元素 $listtail")

        val listempty = mynums.isEmpty
        println(s"5.使用isEmpty判断 mynums是否为空 $listempty")
        println()


        //集合Set,元素唯一
        val myset1 = Set(4,5,6)
        println(s"6.这是一个集合myset1: $myset1")
        val myset2 = Set(4,6,7,8)
        println(s"7.这是一个集合myset2: $myset2")

        println("8.这是一个交集操作myset1.&(myset2):" + myset1.&(myset2))
        println()

        //映射Map
        /*
        Map也有三个基本操作：
        1.keys    返回Map所有的键key
        2.values  返回Map所有的值value
        3.isEmpty 在Map为空时返回true
        */
        val mymap = Map("zhangsan" -> 22, "lisi" -> 23, "wangwu" -> 24)
        println("9.这是一个映射mymap:" + mymap)

        val mymap1 = mymap.keys
        println("10.这是mymap的键" + mymap1)

        val mymap2 = mymap.values
        println("11.这是mymap的值" + mymap2)

        val mapempty = mymap.isEmpty
        println("12.判断mymap是否为空" + mapempty)
        println()

        //元组tuple
        val mytuple = (1, 3.14, "kunsile")
        println("13.这是一个元组mytuple:" + mytuple)
        println()

        //1加到100
        val sum1to100 = myadd2(100,0)
        println("14.使用递归代替循环,这是1加到100的结果:" + sum1to100)
        println()

        //try-catch-finally异常处理和match表达式的结合使用
        print("15.给不对的参数时: ")
        val result1 = mydivision(10,0)
        divisionresult(result1)

        val result2 = mydivision(10,2)
        print("16.当给的参数正常时: ")
        divisionresult((result2))

        println("17.使用模式守卫: ")
        val result3 = mydivision(10,5)
        divisionresult2(result2)
        divisionresult2(result3)

        println()
        println("接下来是样例类")
        //使用样例类
        val person1 = Person("zhouliu", 26)
        println("18.使用样例类(这里自动生成了apply方法):" + person1)

        println("19.样例类的模式匹配:")
        //样例类的模式匹配
        person1 match {
             case Person(name, age) => println(s"Name: $name, Age: $age")
        }

        //辅助构造方法
        println()
        println("20.下面是辅助构造方法的示例:")
        val person3 = new Persons("zhaoqi", 25)
        val person4 = new Persons("alielie")
        val person5 = new Persons()

        //泛型类
        println()
        println("21.泛型类的示例:")
        val intBox = new Box(42)
        val stringBox = new Box("Hello")

        println(intBox.getValue)
        println(stringBox.getValue)
        println("22.泛型方法的示例:")
        println("比较10和20" + mymax(10,20))
        println("比较apple和orange" + mymax("apple", "orange"))

        println()
        println("23.上界和下界的示例:")
        //合法的实例化
        val animalContainer = new Container(new Animal())
        val dogContainer = new Container(new Dog())
        val bianmuContainer = new Container(new Bianmu())

        println(animalContainer.makeSound)
        println(dogContainer.makeSound)
        println(bianmuContainer.makeSound)

        //非法实例化（编译错误）
        //val catContainer = new Container(new Cat())//因为Cat不是Bianmu的超类型

        println()
        println("24.型变的示例:")
        //协变测试
        val dogBox2: Box2[Dog] = new Box2(new Dog)
        val animalBox2: Box2[Animal] = dogBox2
        println(animalBox2.getValue.sound)

        //逆变测试
        val animaVet: Vet[Animal] = new Vet[Animal]
        val dogVet: Vet[Dog] = animaVet
        dogVet.treat(new Bianmu)

        //不变测试
        val dogCage: Cage[Dog] = new Cage(new Dog)
        dogCage.setValue(new Bianmu)
        println(dogCage.getValue.sound)

        //自类型
        println()
        println("25.自类型的示例:")
        val service = new MyService
        service.run()

        //复合类型
        println()
        println("26.复合类型的示例:")
        
        val duck = new Duck
        describe(duck)

        //常用的高阶函数
        println()
        println("27.常用的高阶函数")
        val my_map = mynums.map(x => x * x)
        println("map函数:" + my_map)
      
        val myfilter = mynums.filter(x => x % 2 == 0)
        println("filter函数:" + myfilter)

        val myreduce = mynums.reduce((x,y) => x + y)
        println("reduce函数:" + myreduce)

        val myfold = mynums.fold(0)((x,y) => x + y)
        println("fold函数:" + myfold)

        //内部类
        println()
        println("28.内部类的相关示例:")
        //创建内部类的实例，要先创建外部类的实例，然后通过外部类实例创建内部类实例。
        val outer = new Outer
        val inner = new outer.Inner
        inner.printOuterField()

        //多参数列表
        println()
        println("29.多参数列表相关示例:")
        //简单的多参数列表函数的使用
        val result_add1 = addlist(2)(4)
        println(result_add1)

        //部分应用函数
        //多参数列表的一个主要作用是部分应用函数，即固定部分参数，生成一个新的函数。
        val addTwo = addlist(2)(_)    //固定第一个参数
        val result_add2 = addTwo(3)      //调用新函数
        println(result_add2)
        //隐式参数
        implicit val defaultGreeting: String = "Hello"
        greet("zhangsan")
        //类型推断
        val sumfoldLeft = foldLeft(List(1, 2, 3))(0)(_ + _)
        println(sumfoldLeft)

    }

    //定义变量使用var val。定义方法使用def
    def myadd(x: Int, y: Int = 1): Int = {
        val result = x + y
        result
    }

    //除了泛型类，scala也支持泛型方法。泛型方法允许在方法中使用类型参数。
    //Ordering[T] 是 Scala 标准库中的一个特质.这里是隐式参数的语法
    //隐式参数的作用是让编译器自动查找并传递一个合适的值，而不需要显式地传递参数。
    def mymax[T](a: T, b: T)(implicit ord: Ordering[T]): T = {
        if (ord.gt(a, b)) a else b
    }

    //复合类型的方法
    def describe(obj: Flyable with Swimmable): Unit = {
        println(obj.fly)
        println(obj.swim)
    }

    //多参数列表示例
    //简单的多参数列表函数
    def addlist(x: Int)(y: Int): Int = x + y
    //隐式参数的例子
    def greet(name: String)(implicit greeting: String): Unit = {
        println(s"$greeting, $name")
    }
    //类型推断的例子
    def foldLeft[A, B](list: List[A])(initial: B)(f: (B, A) => B): B = {
        list.foldLeft(initial)(f)
    }





/*
scala的控制结构：while，do while循环；if表达式；for表达式；try表达式处理异常；match表达式
*/
    /*
    while 和 do while循环：
        由于while 和 do-while 循环的设计本质上是命令式编程的产物，所以要符合函数式编程的方式是
    用递归来替代使用循环。
    */
    //1加到100
    def myadd2(num: Int, count: Int): Int = {
        if(num == 0) count
        else myadd2(num - 1, count + num)
    }

    /*
    try-catch-finally用于异常处理，而match用于模式匹配，虽然是两种不同的控制结构，但二者经常结合使用。
    */
    def mydivision(a: Int, b: Int): Int = {
        try {
            a / b
        } catch {
            case e: ArithmeticException =>
                println("算术异常:除数不能为0")
                -1  //返回一个默认值
            case e: Exception =>
                println("读取文件时发生错误: " + (e.getMessage))
                throw e //重新抛出异常
        } finally {
            println("finally 块总是会执行")
        }
    }

    //match模式匹配
    def divisionresult(result: Int): Unit = {
        result match {
            case -1 => println("处理异常情况")
            case _ => println("计算结果为:" + result)
        }
    }
    /*
    模式守卫是一种在模式匹配中添加额外条件的方式。它允许在case分支中使用if语句进一步过滤匹配的条件
    */
    def divisionresult2(result: Int): Unit = {
        result match {
            case -1 => println("异常情况")
            case n if n % 2 == 0 => println("结果是一个偶数: " + result)
            case n => println("结果是一个奇数:" + result)
        }
    }


}



/*******************************************************************************/
/*
    在scala中有以下比较特殊的类：
        1.case class样例类
        2.trait特质
        3.object单例对象
        4.伴生对象
        5.密封类
        6.抽象类
        7.内部类
*/


/*
case class样例类

可以使用case class来定义样例类。
    使用场景：1.不可变数据建模：如表示用户、订单、配置等；2.模式匹配；3.值比较


样例类特性：
    1.自动生成 apply 方法（方便创建实例）
    2.自动生成 unapply 方法（支持模式匹配）
    3.自动生成 equals 和 hashCode 方法（值比较）
    4.自动生成 toString 方法
    5.不可变性，字段默认val
    6.自动生成 copy 方法

    //伴生对象
    object Person {
        //自动生成的apply方法
        def apply(name: String, age: Int): Person = new Person(name, age)

        //自动生成的unapply方法
        def unapply(p: Person): Option[(String, Int)] = Some(p.name, p.age)
    }
*/
case class Person(name: String, age: Int)


/*******************************************************************************/
/*
trait特质

特质用于class类之间共享程序结构和字段。类和对象可以扩展特质，但是特质不能被实例化，因此特质没有参数。

使用特质：用关键字extends来扩展特征。然后使用关键字override来实现trait特质里面的任何抽象成员。

与特质相关的点：
    *与多态的关系：特质是实现多态的重要工具。通过特质，可以定义抽象方法，子类或混入特质的类可以实现这些方法，从而实现运行时多态。
    *与继承的关系：特质可以被类继承（混入），一个类可以继承多个特质。
    *与组合的关系：特质可以用于实现组合，通过混入多个特质来组合不同的行为。
*/

/*******************************************************************************/
/*
单例对象

单例对象是一种特殊的类，又且只有一个实例。和惰性变量一样，单例对象是延迟创建的，当它第一次被使用时创建。

使用关键字object定义。

    单例对象的特点：1.只有一个实例；2.不能通过new实例化；3.可以直接调用

    单例对象的用途：
    1.工具类：可以定义工具方法，例如日志工具、教学工具等。
    2.工厂方法：可以实现工厂模式，提供创建实例的方法。
    3.伴生对象：单例对象和类同名，并且定义同一个文件中，就是类的伴生对象。伴生对象可以访问类的私有成员。
    4.入口点：单例对象可以包含main方法，作为程序的入口点。
*/

/*******************************************************************************/
/*
密封类

密封类限制了继承关系，要求所有子类必须定义在同一个文件中。密封类通常用于模式匹配，确保所有的子类都被处理。

密封类的定义：使用sealed关键字。
sealed class 类名{
    //字段和方法
}

密封类的特点：1.限制继承；2.模式匹配的完备性检查；3.适合表示封闭的类型层次结构。

密封类的使用场景：1.模式匹配，编译器会检查模式匹配是否完备；2.表示封闭的类型层次结构，如表示几何图形、表达式树、状态机等。
*/

/*******************************************************************************/
/*
抽象类
定义：是一种不能被直接实例化的类，通常用于定义一些通用的行为或结构，具体实现留给子类。
     使用abstract关键字定义。

抽象类可以包含：
    *抽象方法：没有方法体的方法。
    *具体方法：有方法体的方法。
    *字段：抽象类可以定义字段


抽象类与特质trait的区别：
    *多重继承：抽象类不支持多重继承，而trait支持多重继承。
    *构造函数：抽象类可以有构造函数，而trait不能有构造函数。
    *使用场景：抽象类用于定义通用的类结构，而trait用于定义可复用的行为
*/

/*******************************************************************************/
/*
内部类
内部类是指定义在另一个类或对象内部的类。
*/
//内部类的基本语法：定义在另一个类的内部，可以直接访问外部类的成员。
class Outer {
    private val outerField: Int = 42

    class Inner {
        def printOuterField(): Unit = {
            println("外部类的值:" + outerField)
        }
    }
}




/*******************************************************************************/
/*
隐式转换

scala的隐式转换是一种强大的特性，允许在编译时自动将一种类型转换为另一种类型。隐式转换通常用于现有类搞的功能，或者在类型不匹配时自动进行转换。

隐式转换的基本概念：隐式转换是通过定义隐式函数来实现。当编译器发现类型不匹配时，它会查找作用域内的隐式函数，尝试将类型转换为所需的类型。

隐式转换函数通常使用implicit关键字定义。
例如：
implicit def intToString(x: Int): String = x.toString

隐式转换的使用说明：当编译器需要String类型，但提供了Int类型，它会自动调用这个隐式函数。

scala还提供了隐式类，隐式参数。

隐式转换的作用域：1.当前作用域中；2.伴生对象中；3.导入的包或对象中。
*/

/*******************************************************************************/
/*
方法重载
定义：是指在同一个类中定义多个同名方法，但这些方法的参数列表（参数类型、参数数量或参数顺序）必须不同，
     方法重载是一种 静态多态（编译时多态），因为它是在编译时根据参数列表决定调用哪个方法。

与方法重载相关的点：
    *与多态的关系：方法重载是多态的一种形式（静态多态），但它仅限于同一个类中的方法。
    *与特质的关系：特质中可以定义重载方法，子类或混入特质的类可以调用这些方法。
    *与继承的关系：子类可以重载父类的方法，但必须满足参数列表不同的条件。
*/

/*******************************************************************************/
/*
组合
定义：是指通过将多个对象组合在一起来构建更复杂的对象。组合是一种“has-a”关系，强调对象之间的协作，而不是继承关系。

与组合相关的点：
    *与多态的关系：组合可以通过委托实现多态。例如，一个类可以包含另一个类的实例，并调用其方法。
    *与特质的关系：特质可以用于实现组合。通过混入多个特质，可以为类添加不同的行为。
    *与继承的关系：组合是继承的替代方案，通常更灵活且易于维护。
*/

/*******************************************************************************/
/*
继承
定义：是指一个类从另一个类（父类）继承属性和方法。继承是一种“is-a”关系，强调类之间的层次结构。

与继承相关的点：
    *与多态的关系：继承是实现运行时多态的基础。子类可以重写父类的方法，从而在运行时根据对象的实际类型调用相应的方法。
    *与特质的关系：特质可以被类继承，一个类可以继承多个特质
    *与组合的关系：继承和组合时两种不同的代码复用方式。继承强调类之间的层次关系，而组合强调对象之间的协作。
*/

/*******************************************************************************/
/*
多态
定义：是指同一操作作用于不同的对象时，可以有不同的行为。

scala中的多态主要通过以下方式实现：
        1.子类型多态（通过继承和重写方法实现）
        2.参数多态（通过泛型实现）
        3.特设多态（通过类型类和隐式转换实现）

与多态相关的点：
    *与方法重载的关系：方法重载是静态多态的一种形式。
    *与特质的关系：特质是实现多态的重要工具，通过特质可以定义抽象方法，子类或混入特质的类可以实现这些方法。
    *与继承的关系：继承是实现运行时多态的基础。
    *与组合的关系：组合可以通过委托实现多态。
*/

/*******************************************************************************/

/*
主构造方法：
    *主构造方法是类定义的一部分，其参数直接放在类名后面。
    *每个类必须有一个主构造方法。
    *主构造方法的代码会执行类定义中的所有语句。

辅助构造方法：
    *辅助构造方法通过def this(...)定义。
    *辅助构造方法必须直接或间接调用主构造方法。
    *辅助构造方法可以重载，提供多种初始化对象的方式。
*/
class Persons(name: String, age: Int) {
    //主构造方法
    println(s"创造了人类: $name, $age")

    //辅助构造方法1
    def this(name: String) = {
        this(name, 0)   //调用主构造方法
        println("调用辅助构造函数1")
    }

    //辅助构造方法2
    def this() = {
        this("不知道")  //调用辅助构造方法1
        println("调用辅助构造函数2")
    }
}


/*******************************************************************************/
/*
泛型类
定义：指可以接受类型参数的类。泛型类在集合类中被广泛使用。
说明：允许编写通用的、类型安全的代码。通过泛型，可以定义适用于多种类型的类、方法和函数，而无需为每种类型编写重复的代码。

基本语法：通过类型参数实现，类型参数用方括号[]表示。

*/

//示例：泛型类
class Box[T](value: T) {
    def getValue: T = value
}

/*
类型边界
scala的泛型支持类型边界，用于限制类型参数的取值范围。

上界：上界限制类型参数必须是某个类型的子类型。像T <: A这样声明的类型上界表示类型变量T应该是类型A的子类。
下界：下界限制类型参数必须是某个类型的超类型。术语 B >: A 表示类型参数 B 或抽象类型 B 是类型 A 的超类型。
     在大多数情况下，A 将是类的类型参数，而 B 将是方法的类型参数。
*/
class Animal {
    def sound: String = "动物的声音"
}
class Dog extends Animal {
    override def sound: String = "汪"
}
class Cat extends Animal {
    override def sound: String = "喵"
}
class Bianmu extends Dog {
    override def sound: String = "边牧狗的叫声"
}

//T >: Bianmu表示类型参数T必须是Bianmu或其超类型（下界）
//T <: Animal表示类型参数T必须是Animal或其子类型（上界）
//因此，T的取值范围是Bianmu到Animal之间的类型。
class Container[T >: Bianmu <: Animal](value: T) {
    def getValue: T = value
    def makeSound: String = value.sound
}

/*
型变
scala的泛型支持型变，用于描述泛型类型的子类型关系。型变分为三种：
    *协变:[+T] 表示泛型类型与类型参数同向变化。如果 A 是 B 的子类型，那么 Container[A] 是 Container[B] 的子类型。
    *逆变:[-T] 表示泛型类型与类型参数反向变化。如果 A 是 B 的子类型，那么 Container[B] 是 Container[A] 的子类型。
    *不变:[T]  表示泛型类型与类型参数无关
*/

//协变容器类:
class Box2[+T](val value: T) {
    def getValue: T = value
    //协变类型不能写入数据
    //def setValue(newValue: T): Unit = {}  //编译错误
}

//逆变容器类:
class Vet[-T <: Animal] {
    def treat(animal: T): Unit = println("Treating animal: " + {animal.sound})
    //逆变类型不能读取数据
    //def getAnimal: T = new Animal     //编译错误
}

//不变容器类:
class Cage[T](var value: T) {
    def getValue: T = value
    def setValue(newValue: T): Unit = value = newValue
}

/*******************************************************************************/
/*
自类型
自类型是一种声明依赖关系的语法，用于指定一个特质trait或类必须混入另一个特质或类。
自类型通过this: Type => 的语法来表示，它强制要求当前特质或类在使用时必须与指定的类型一起混入。

自类型的主要作用是:
    1.声明依赖关系：明确表示一个特质A依赖于另一个特质B。
    2.解决菱角继承问题：在多重继承中避免冲突。
    3.提供更多灵活的组合方式：允许动态地组合特质。
*/
trait Logger {
    def log(message: String): Unit
}

trait Service {
    this: Logger => //Service 必须混入Logger
    def run(): Unit = {
        log("Service正在运行")
    }
}
class MyService extends Service with Logger {
    def log(message: String): Unit = println(message)
}

/*******************************************************************************/
/*
复合类型
定义：是指将多个类型组合在一起形成的新类型。复合类型通常用来表示一个对象同时满足多个类型的特性。
     scala的复合类型通过with关键字将多个类型连接起来，表示“同时是这些类型”。

复合类型的语法：
T1 with T2 with T3 with Tn

复合类型与继承的区别
复合类型和多重继承（通过extends和with）有相似之处，但他们有以下区别：
    1.继承：
        *通过extends和with实现多重继承。
        *子类会继承父类的所有成员。
        *是静态的，编译时确定。
    2.复合类型：
        *通过with将多个类型组合在一起。
        *不继承成员，只是表示对象同时满足多个类型的特性。
        *是动态的，可以在运行时组合。
*/
//复合类型
trait Flyable {
    def fly: String = "Flying"
}
trait Swimmable {
    def swim: String = "Swimming"
}


class Duck extends Flyable with Swimmable

/*******************************************************************************/
/*
注解
scala的 注解 是一种元数据机制，用于为代码添加额外的信息。
注解可以附加到类、方法、字段、参数等代码元素上，供编译器、工具或运行时环境使用。

1.注解的基本语法：使用 @ 符号定义，语法如下：
    @AnnotationName
    class MyClass
    
    @AnnotationName
    def myMethod(): Unit = {}

    @AnnotationName
    val myField: Int = 42


2.scala内置注解
@deprecated:    标记某个方法或类已过时，编译器会发出警告。

@throws:        标记方法可能抛出的异常。

@unchecked:     告诉编译器忽略某些检查（如模式匹配的穷尽性检查）。

@tailrec:       确保方法是尾递归，编译器会优化尾递归。

@inline:        提示编译器内联方法（将方法调用替换为方法体）。

*/

/*******************************************************************************/
/*
高阶函数

高阶函数是指使用其他函数作为参数、或者返回一个函数作为结果的函数。
约定，使用函数值作为参数，或者返回值为函数值的“函数”和“方法”，均称之为“高阶函数”。

常用的高阶函数：
1.map       对集合中的每个元素应用一个函数，并返回一个新的集合。
2.filter    根据给定的条件（一个返回布尔值的函数）过滤集合中的元素。
3.reduce    将集合中的元素通过一个二元函数组合成一个值。
4.fold      类似于reduce，但它允许你指定一个初始值。

*/


/*******************************************************************************/
/*
提取器
scala的提取器是一种用于模式匹配的机制，它允许你从对象中提取出特定的值。
提取器通常与unapply方法关联，该方法用于将对象解构为其组成部分。

1.提取器的基本概念：
    提取器是一个带有unapply方法的对象。unapply方法接受一个对象并返回一个Option类型的结果，
通常是Option[Tuple]，表示提取的结果。如果提取成功返回Smoe，否则返回None。

*/



/*******************************************************************************/
/*
多参数列表（柯里化）
scala支持多参数列表，也称为柯里化。多参数列表允许你将函数的参数分成多个列表，每个列表用括号分隔。

1.多参数列表的基本语法：
def functionName(param1: Type1)(param2: Type2): ReturnType = {
    //函数体    
}
调用时，参数按列表依次传递：
functionName(value1)(value2)

2.多参数列表的使用场景
    *隐式参数 隐式参数implicit与其他参数分开。隐式参数通常放到最后一个参数列表。
    *类型推断 多参数列表可以帮助scala编译器更好的推断类型。
*/


/*******************************************************************************/
/*
scala的并发与future

1.Future的基本概念
*future是一个异步计算的结果。它允许你启动一个计算并在未来某个时间点获取结果，而不会阻塞当前线程。
*future是不可变的，一旦创建，它的值就不能被修改。
*future的计算是异步的，默认情况下会在全局的线程池中执行。

2.创建Future
使用future需要导入scala.concurrent.Future
和scala.concurrent.ExecutionCoontext.Implicits.global(默认的全局执行上下文)
*/



/*******************************************************************************/
/*
匿名函数
匿名函数是一种没有名称的函数，通常用于简化代码或作为参数传递给高阶函数。匿名函数也称为Lambda表达式。

匿名函数的基本语法
(参数列表) => 函数体
    参数列表：可以是一个或多个参数，用逗号隔开。
    函数体：可以是单行表达式，也可以是多行代码快。
*/



/*******************************************************************************/
/*
模式匹配
模式匹配是scala中一种强大且灵活的特性，用于检查数据的结构或内容，并根据匹配的结果执行相应的逻辑。

模式匹配的用途：
    1.结构数据：从复杂的数据结构（如case class，tuple，list等）中提取值。
    2.条件分支：根据不同的条件执行不同的逻辑，比if-else更间接和直观。
    3.类型检查：可以匹配不同的类型，并根据类型执行相应的操作。
    4.处理可选值：常用于处理Option类型，避免null检查。
    
模式匹配的实现：通过match关键字实现。如：
value match {
  case pattern1 => result1
  case pattern2 => result2
  ...
  case _ => defaultResult
}

模式守卫是使用if表达式进行过滤匹配结果。
*/