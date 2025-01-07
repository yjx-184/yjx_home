//练习五：创建一个List val list0 = List（1，7，9，8，0，3，5，4，6，2）

object mylist1 {
    def main(args: Array[String]): Unit = {
        val List0 = List(1, 7, 9, 8, 0, 3, 5, 4, 6, 2)
        val result = for(x <- List0)yield x*10
        println(result)
    }
}