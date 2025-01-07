//练习17:要求可以输入任意多个参数(数字类型)，将每个参数乘以100后放入数组并返回该数组。
//如：2, 4, 6 返回 Array(200, 400, 600)。

object ex_method6 {
    def main(args: Array[String]): Unit = {
        if(!args.forall(_.forall(_.isDigit))) {
            println("请输入数字类型参数")
        } else {
            val result = args.map(_.toInt * 100)
            println(result.mkString("Array(", ", ", ")"))
        }
    }
}