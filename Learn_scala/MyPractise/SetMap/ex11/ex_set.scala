import scala.collection.mutable

object ex_set {
    def main(args: Array[String]): Unit = {
        /*set集合1-10*/
        //1.定义一个不可变set集合a，保存以下元素:10,20,30,10,50,40
        val a = Set(10,20,30,10,50,40)
        println(s"第一小题: $a")

        //2.获取集合a的大小
        println("第二小题:" + a.size)

        //3.遍历a集合
        for (t3 <- a)
        println("第三小题:" + t3)

        //4.删除元素50
        val t4 = a - 50
        println("第四小题 :" + t4)

        //5.a集合拼接set集合Set(60,80,90)
        val t5 = a ++ Set(60,80,90)
        println("第五小题:" + t5)

        //6.a集合拼接列表List(100,300,200)
        val t6 = a ++ List(100,200,300)
        println("第六小题:" + t6)

        //7.定义一个可变set集合b，初始元素为5,6,7,8
        val b = mutable.Set(5,6,7,8)
        println("第七小题:" + b)

        //8.b集合中使用+=添加元素9
        b += 9
        println("第八小题:" + b)

        //9.b集合中删除元素5
        b -= 5
        println("第九小题:" + b)

        //10.b集合使用add添加元素10
        b.add(10)
        println("第十小题:" + b)
    }
}
