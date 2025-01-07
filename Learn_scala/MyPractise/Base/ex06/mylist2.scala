//练习六：将list0中的偶数提取出来生成一个新的集合

object mylist2 {
    def main(args: Array[String]): Unit = {
        val List0 = List(1,7,9,8,0,3,5,4,6,2)
        val result = for{
            x <- List0
            if x % 2 == 0
        } yield x

        println(result)
    }
}