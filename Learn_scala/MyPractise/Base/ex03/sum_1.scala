//练习三：控制台输入数字n，计算1加到n的和

object sum_1 {
    def main(args: Array[String]): Unit = {
        //判断输入是不是一个数字
        if (args.length != 1 || !args.forall(_.forall(_.isDigit))) {
            println("请输入一个整型数字作为参数！")
        } else {
            val n = args(0).toInt
            val result = mysum(n, 0)
            println(s"1加到$n 的和是： $result")
        }
    }

    //使用递归进行求和，并且使用尾递归优化，避免使用额外的栈空间，减少栈溢出的风险。
    def mysum(n: Int, count: Int): Int = {
        if (n == 0) count 
        else mysum(n - 1, count + n)
    }
}