//练习15： 编写一个方法method4，要求能够输入一个大于0的数字参数，能够打印1到该数字范围内的所有偶数。

import scala.annotation.tailrec
object ex_method4 {
    def main(args: Array[String]): Unit = {
        if(!args.forall(_.forall(_.isDigit))) {
            println("请输入一个正确的数字")
        } else if(args(0).toInt <= 0) {
            println("请输入一个正确的数字")
        } else {
            method4(args(0).toInt, 1)
        }
    }

    @tailrec
    def method4(num: Int, count: Int): Unit = {
        if (count <= num){
            if(count % 2 == 0) println(count)
            method4(num, count + 1)
        }
    }
}
/*
运行结果：  
$ scalac ex_method4.scala
$ scala ex_method4 hello
请输入一个正确的数字
$ scala ex_method4 0
请输入一个正确的数字
$ scala ex_method4 10
2
4
6
8
10
*/