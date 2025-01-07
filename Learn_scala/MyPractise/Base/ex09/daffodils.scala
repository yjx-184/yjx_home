//打印100到1000的的水仙花数。

object daffodils {
    def main(args: Array[String]): Unit = {
        val result = (100 to 999).filter(isDaffodil)
        println(s"100到1000以内的水仙花数: $result")
    }
    def isDaffodil(n: Int): Boolean = {
        val h = n / 100
        val t = n % 100 / 10
        val s = n % 10

        h*h*h + t*t*t + s*s*s == n
    }
}
/*
在了解水仙花数的定义以后，思路是对一个数进行判断，是就输出。需要用到布尔值以及filte方法来过滤。

运行结果：
$ scala daffodils
100到1000以内的水仙花数: Vector(153, 370, 371, 407)

*/