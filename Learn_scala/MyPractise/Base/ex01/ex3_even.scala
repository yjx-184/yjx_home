/*
1.编写scala程序，完成以下功能： 假设有整型变量x，判断x是否为偶数，若为偶数，
则在控制台上打印“输入的数值是偶数”。无论x是否为偶数，最后都要在控制台上输出x的值
*/

object ex3_even {
    def main(args: Array[String]): Unit = {
        for (arg <- args)
        if (!arg.forall(_.isDigit)){
            println("输入有问题，请输出纯数字！")
        } else {
            val x = arg.toInt
            if ((x % 2) == 0) {
                println("输入的数值是偶数")
            } else {
                println(x)
            }
        }   
    }
}
/*
运行结果：
$ scala ex3_even 4 5 hello 8
输入的数值是偶数
5
输入有问题，请输出纯数字！
输入的数值是偶数
*/