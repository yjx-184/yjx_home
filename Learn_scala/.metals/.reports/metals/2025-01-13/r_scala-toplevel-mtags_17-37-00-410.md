error id: file://<WORKSPACE>/MyPractise/summary/ex1/ex1.scala:[725..726) in Input.VirtualFile("file://<WORKSPACE>/MyPractise/summary/ex1/ex1.scala", "object ex1 {
    def main(args: Array[String]): Unit = {
        val sum_1 = myadd(3,5)    //方法的调用
        println(s"这是方法的调用: $sum_1") //s是插值器

        val add_MyFunction = (x: Int, y: Int) => x + y //函数的定义
        val sum_2 = add_MyFunction(4,5)
        println(s"这是函数的调用: $sum_2")
    }

    //定义变量使用var val。定义方法使用def
    def myadd(x: Int, y: Int): Int = {
        val result = x + y
        result
    }

/*
scala的数据结构：分为不可变集和可变集。
不可变集合：列表List，索引序列Vector，无序集合Set（元素唯一），映射Map，元组Tuple（固定数量，可以不同类型）。
可变集合：索引序列ArrayBuffer，链表结构ListBuffer，无序集合HashSet，键值对HashMap。
其他数据结构：Option（表示可能存在或不存在的值），Either（表示两种可能的值之一，通常是成功或失败），LazyList（惰性求值的列表，适合处理无限序列）
*/

    def 


/*
scala的控制结构：while，do while循环；if表达式；for表达式；try表达式处理异常；match表达式
*/
}")
file://<WORKSPACE>/file:<WORKSPACE>/MyPractise/summary/ex1/ex1.scala
file://<WORKSPACE>/MyPractise/summary/ex1/ex1.scala:30: error: expected identifier; obtained rbrace
}
^
#### Short summary: 

expected identifier; obtained rbrace