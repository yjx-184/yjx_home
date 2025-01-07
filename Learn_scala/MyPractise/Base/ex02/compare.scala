//练习2,比较两个整型大小

object compare {
    def main(args: Array[String]): Unit = {

        if (args.length != 2 || !args.forall(_.forall(_.isDigit))) {
            println("请输入两个整型数字作为参数！")
        } else {
            val x = args(0).toInt
            val y = args(1).toInt

            val larger = com(x, y)
            println(s"较大数是: $larger")
        }
        }

        def com(x: Int, y: Int): Int = {
            if (x > y) x else y
    }
}
/*
运行结果：
$ scala compare 4 5
较大数是: 5
$ scala compare 4 s
请输入两个整型数字作为参数！
*/