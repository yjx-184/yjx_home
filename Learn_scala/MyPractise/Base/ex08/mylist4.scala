//练习八：在控制台输入一组参数，从中提取数字形成一个list0,再对list0中的奇数乘10生成一个新的集合。

object mylist4 {
    def main(args: Array[String]): Unit = {
        val List0 = args.filter(_.forall(_.isDigit)).map(_.toInt).toList
        println(List0)

        val result = for{
            x <- List0
            if x % 2 != 0
        } yield x * 10
        println(result)
    }
}
/*
使用filter是scala集合的一个高阶方法，用于根据指定条件筛选集合中的元素，返回一个满足条件的新集合。  

运行结果：
$ scala mylist4 1 2 3 4 5 6 7 8 9 10
List(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
List(10, 30, 50, 70, 90)
*/