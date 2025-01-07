//练习18：编写一个方法method7，要求输入一个数字，如果数字大于150则抛出异常，并捕获该异常，捕获异常后打印The number is greater than 150。

object ex_method7 {
    def main(args: Array[String]): Unit = {
        if(!args.forall(_.forall(_.isDigit))) {
            println("请输入一个数字")
        } else {
            try {
                val num = args(0).toInt
                method7(num)
            } catch {
                case ex: Exception => println(ex.getMessage)
            }
        }
    }
    def method7(num: Int): Unit = {
        if (num > 150) {
            throw new Exception("这个数字超过了150")
        } else {
            println("这个数字合格")
        }
    }
}
/*
$ scalac ex_method7.scala
$ scala ex_method7 100
这个数字合格
$ scala ex_method7 151
这个数字超过了150

*/