//练习16：要求能够输入一个大于0的数字参数，能够打印1到该数字范围内的所有奇数，并且该奇数不能被5整除。

import scala.annotation.tailrec
object ex_method5 {
    def main(args: Array[String]): Unit = {
        if(!args.forall(_.forall(_.isDigit))) {
            println("请输入一个正确的数字")
        } else if (args(0).toInt <= 0) {
            println("请输入一个正确的数字")
        } else {
            method5(args(0).toInt, 1)
        }
    }

    @tailrec
    def method5(num: Int, count: Int): Unit = {
        if (count <= num) {
            if (count % 2 !=0 && count % 5 != 0) println(count)
            method5(num, count + 1)
        }
    }
}
/*
运行结果：
$ scala ex_method5 hello
请输入一个正确的数字
$ scala ex_method5 0
请输入一个正确的数字
$ scala ex_method5 5
1
3
$ scala ex_method5 12
1
3
7
9
11
$ scala ex_method5 15
1
3
7
9
11
13
*/