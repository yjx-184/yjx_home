
object ex_map {
    def main(args: Array[String]): Unit = {
        /*Map映射*/

        //11.构建一个映射map1,内容为"zhangsan" -> 20, "lisi" -> 18, "wangwu" -> "22"
        val map1 = Map("zhangsan" -> 20,
                        "lisi" -> 18,
                        "wangwu" -> 22)
        println("第11题:" + map1)

        //12.构建一个映射map2，内容为"zhangsan" -> 20, "lisi" -> 18, "wangwu" -> "22"
        val map2 = Map("zhangsan" -> 20,
                        "lisi" -> 18,
                        "wangwu" -> 22)
        println("第12题:" + map2)

        //13.构建一个空的映射map3,参数类型为Map[String, Int]
        val map3: Map[String, Int] = Map()
        println("第13题:" + map3)

        //14.获取map2中lisi的年龄
        val t14 = map2("lisi")
        println("第14题:" + t14)

        //15.获取所有的map2中的key值
        val t15 = map2.keys
        println("第15题:" + t15)

        //16.获取所有的map2中的value值
        val t16 = map2.values
        println("第16题:" + t16)

        //17.map2中新增一组数据：zhouliu,25
        val t17 = map2 + ("zhouliu" -> 25)
        println("第17题:" + t17)

        //18.map2中获取zhouliu的年龄，如果zhouliu不存在，则返回-1
        val t18 = map2.getOrElse("zhouliu", -1)
        println("第18题:" + t18)

        //19.map2遍历打印所有的key和value
        for (t19 <- map2)
        println("第19题:" + t19)

        //20.在map2中添加map1集合
        val t20 = map1 ++ map2
        println("第20题:" + t20)

    }
}