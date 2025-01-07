/*
练习14：编写一个方法method3，要求能够输入一个大于0的数字参数，
能够打印1到该数字范围内的所有数。
*/
import scala.annotation.tailrec
object ex_method3 {
    def main(args: Array[String]): Unit = {
        if(!args.forall(_.forall(_.isDigit))) {
            println("请输入一个正确的数字")
        } else if (args(0).toInt <= 0) {
            println("请输入一个正确的数字")
        } else {
            val result = method3(args(0).toInt, 1)
        }
    }

    @tailrec
    def method3(num: Int, count: Int): Unit = {
        if(count <= num) {
            println(count)
            method3(num, count + 1)
        }
    }
}

/*
运行结果：
$ scalac ex_method3.scala
$ scala ex_method3 -10
请输入一个正确的数字
$ scala ex_method3 a
请输入一个正确的数字
$ scala ex_method3 10
1
2
3
4
5
6
7
8
9
10

*/