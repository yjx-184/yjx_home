//练习四：控制台输入数字n，计算1加到n的所有奇数的和

object sum_odd {
    def main(args: Array[String]): Unit = {
        for(arg <- args)
        if(args.length != 1 || !args(0).forall(_.isDigit)) {
            println("请输入一个数字")
        } else {
            val n = args(0).toInt
            val result = mysum2(n, 0)
            println(s"1加到$n 的所有奇数的和是$result")
        }
    }

    def mysum2(n: Int, count: Int): Int = {
        if(n == 0) count                                //递归结束条件
        else if (n % 2 == 1) mysum2(n - 1, count + n)   //n为奇数时累加
        else mysum2(n - 1, count)                       //n为偶数时跳过
    }
}

/*
运行结果：
$ scalac sum_odd.scala
$ scala sum_odd 100
1加到100 的所有奇数的和是2500
$ scala sum_odd a
请输入一个数字
*/