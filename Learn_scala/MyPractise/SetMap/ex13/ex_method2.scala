
/*
练习13：编写一个方法method2，输入名字，判断该名字是否为laowang，
如果是返回true，如果不是返回false（不使用return）
*/

object ex_method2 {
    def main(args: Array[String]): Unit = {
        val n = method2(args(0))
        println(n)
    }

    def method2(name: String): Boolean = {
        name == "laowang"
    }
}

/*
运行结果：
$ scala ex_method2 laowang
true
$ scala ex_method2 lao
false
*/