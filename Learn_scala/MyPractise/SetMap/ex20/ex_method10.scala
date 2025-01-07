//练习20：编写一个方法method10，要求有两个参数，两个参数都为大于0的数字，要求能够打印1到第一个参数数字范围内的所有数，在打印过程中遇到与第二个参数相乘大于200就停止。

object ex_method10 {
    def main(args: Array[String]): Unit = {
        if(args.length != 2 || !args.forall(_.forall(_.isDigit))) {
            println("请输入数字")
        } else {
            val num1 = args(0).toInt
            val num2 = args(1).toInt

            if (num1 <= 0 || num2 <= 0) {
                println("输入的参数必须大于0")
            } else {
                method10(num1, num2)
            }
        }
    }

    def method10(num1: Int, num2: Int, count: Int = 1): Unit = {
        if (count * num2 <= 200) {
            if (count <= num1) {
                println(count)
                method10(num1, num2, count + 1)
            }
        }
    }
}
/*
运行结果：
$ scala ex_method10 50 20
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