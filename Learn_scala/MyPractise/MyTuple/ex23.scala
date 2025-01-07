

object ex23 {
    def main(args: Array[String]): Unit = {
        //71: 创建一个元组Y1，内部含有zhangsan   biejing   20  true  四个数据
        val Y1 = ("zhangsan","beijing",20,true)
        println("71:" +  Y1)

        //72：获取元组Y1内的第二个元素（biejing）
        val t72 = Y1._2
        println("72:" + t72)

        //73:  创建一个元组Y2，内部含有(zhangsan ,lisi,wangwu,zhaoliu),
        //(20,30,40,50),(1,0,1,0)  3个数据(每个内部依然是元组)。
        val Y2 = (("zhangsan","lisi","wangwu","zhaoliu"),
                    (20,30,40,50),
                    (1,0,1,0))
        println("73:" + Y2)

        //74: 获取zhangsan,并输出
        val t74 = Y2._1._1
        println("74:" + t74)

        //75:获取lisi 的年龄,并输出
        val t75 = Y2._2._2
        println("75:" + t75)

        //76: 获取wangwu的性别,并输出
        val t76 = Y2._3._3
        println("76:" + t76)

        //77:定义一个迭代器iter1，数据为"Hadoop","Spark","Java"
        //78:遍历iter1，使用while循环并打印输出
        val iter1 = Iterator("Hadoop","Speak","Java")
        while (iter1.hasNext) {
            println("77,78:" + iter1.next())
        }

        //79:定义一个迭代器iter2，数据为10,20,20,30,34,50,60
        val iter2 = Iterator(10, 20, 20, 30, 34, 50, 60)

        // 将iter2转换为List，这样可以重复使用它
        val iter2List = iter2.toList
        
        // 打印最大值、最小值、长度
        println("80: " + iter2List.max)
        println("81: " + iter2List.min)
        println("82: " + iter2List.length)

        //83:合并iter2和iter1两个迭代器
        val value1 = iter1 ++ iter2
        while (value1.hasNext) {
            println("83: " + value1.next())
        }

        // 84: 丢弃iter2的前两个元素
        val t84 = iter2List.drop(2)
        println("84: " + t84.mkString(", "))

        /*
        87:变长数组的特点是什么？
        答：1.动态大小；2.提供高效的插入和删除操作；3.支持多种集合操作；4.扩展和收缩

        88：.创建没有初始元素的ArrayBuffer变长数组，语法结构是什么？
        import scala.collection.mutable.ArrayBuffer
        // 创建一个没有初始元素的空 ArrayBuffer
        val buffer = ArrayBuffer.empty[Int]  // 空的 Int 类型的变长数组

        90.在定义变长数组的时候需要导入哪个包？
        import scala.collection.mutable.ArrayBuffer

        



        */

    }
}