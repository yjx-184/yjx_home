//练习七：控制台输入一组数字生成一个集合，然后在把集合乘10生成新的集合

object mylist3 {
    def main(args: Array[String]): Unit = {
        if (!args.forall(_.forall(_.isDigit))) {
            println("请输入一组数字")
        } else {
            val List0 = args.map(_.toInt).toList
            println(s"生成的整型集合 $List0")

            val result = for(x <- List0) yield x*10
            println(s"将整型集合乘10后的新集合 $result")
        }
    }
}
/*
问题1：
一开始在提取生成整型数组时，使用的代码是：val List0 = args.toList。

导致在乘10后，得到的是List(1111111111, 2222222222, 3333333333, 4444444444, 5555555555, 6666666666)
而不是预期的List(10,20,30,40,50,60)。

原因1：
args 是一个 Array[String]，调用 toList 只是将 String 类型的数组转换为 List[String]，并没有将字符串转换为整数。
因此在后续操作中，对字符串进行了x * 10就是重复拼接了。

解决1：
使用：val List0 = args.map(_.toInt).toList
args是一个字符串数组，其值是Array("1","2","3","4","5","6")

.map(_.toInt)
map是scala集合的高阶函数方法，用于对集合中每个元素应用一个函数，并返回新的集合，
这里的_.toInt是一个匿名函数，它将对每个字符串转换为整型。_表示集合中每个元素。
使用后的结果：Array(1,2,3,4,5,6)

.toList
这是一个方法，将数组Array[Int]转换为列表List[Int]
结果：List(1,2,3,4,5,6)
*/

/*
运行结果：
$ scala mylist3 1 2 3 4 5 6
生成的整型集合 List(1, 2, 3, 4, 5, 6)
将整型集合乘10后的新集合 List(10, 20, 30, 40, 50, 60)
*/