/*练习19
 定义一个名为method9的方法，有三个参数，前两个为数字类型，最后一个参数为f1函数
 （该函数类型参数接受两个数字类型参数，返回值也是数字类型），
 该method9方法返回值为数字类型。定义一个函数f1两个参数分别为x,y都为数字类型，执行返回结果是两个参数的和
*/

object ex_method9 {
    def main(args: Array[String]): Unit = {
        val f1: (Int, Int) => Int = (x, y) => x + y

        val a = args(0).toInt
        val b = args(1).toInt

        val result = method9(a, b, f1)
        println(s"结果是$result")
    }

    def method9(a: Int, b: Int, f: (Int, Int) => Int): Int = {
        f(a,b)
    }
}
/*
$ scalac ex_method9.scala
$ scala ex_method9 2 3
结果是5
*/