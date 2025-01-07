object ex21 {
    def main(args: Array[String]): Unit = {
        //练习31：定义一个数字arr1内容为1-10
        val arr1 = Array(1,2,3,4,5,6,7,8,9,10)
        println("31:" + arr1.mkString(", "))

        //练习32：使用filter过滤器,过滤出来偶数
        val t32 = arr1.filter(_ % 2 == 0)
        println("32:" + t32.mkString(","))

        //练习33:使用map把arr1数组中每一个元素都取出来放到一个全新数组
        val t33 = arr1.map(_.toInt)
        println("33:" + t33.mkString(", "))

        //练习34：使用foreach打印出arr1数组中的元素
         println("34:")
        val t34 = arr1.foreach(println)
        
        //练习35：翻转数组arr1 
        println("35:" + arr1.reverse.mkString(", "))

        //练习36：修改数组arr1中下标为0的数据为100
        val t36 = arr1.map(_.toInt)
        t36(0) = 100
        println("36:" + t36.mkString(", "))

        //练习37:删除arr1数组下标为0的数据
        val t37 = arr1.tail
        println("37:" + t37.mkString(", "))

        //练习38：arr1数组从下标2开始,删除3个元素
        val t38 = arr1.take(2) ++ arr1.drop(5)
        println("38:" + t38.mkString(", "))

        //练习39:插入数据到arr1数组, 第一个参数是开始的位置,插入50,66,77
        val t39 = arr1.take(0) ++ Array(50,66,77) ++ arr1.drop(0)
        println("39:" + t39.mkString(", "))

        //练习40：对arr1数组进行降序排序
        val t40 = arr1.sorted.reverse
        println("40:" + t40.mkString(", "))
    }
}
/*
运行结果：
31:1, 2, 3, 4, 5, 6, 7, 8, 9, 10
32:2,4,6,8,10
33:1, 2, 3, 4, 5, 6, 7, 8, 9, 10
34:
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
35:10, 9, 8, 7, 6, 5, 4, 3, 2, 1
36:100, 2, 3, 4, 5, 6, 7, 8, 9, 10
37:2, 3, 4, 5, 6, 7, 8, 9, 10
38:1, 2, 6, 7, 8, 9, 10
39:50, 66, 77, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
40:10, 9, 8, 7, 6, 5, 4, 3, 2, 1

*/