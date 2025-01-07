
object ex22 {
    def main(args: Array[String]): Unit = {
        //41:定义一个列表list1，内容为("a", "b" ,"c","d","e")
        val list1 = List("a", "b", "c", "d", "e")
        println("41:" + list1)

        //42:在list1列表开头添加元素t
        val t42 = "t" :: list1
        println("42:" + t42)

        //43:在列表开头添加指定列表List("m","n")的元素
        val t43 = "m, n" :: list1
        println("43" + t43)

        //44:在列表list1后添加元素1
        val t44 = list1 ++ "4"
        println("44:" + t44)

        //45:将列表的所有元素添加到 StringBuilder
        val sb1 = new StringBuilder()
        list1.foreach(sb1.append)
        println("45:" + sb1)

        //46:将列表的所有元素添加到 StringBuilder并指定分隔符为","
        sb1.clear()
        sb1.append(list1.mkString(", "))
        println("46:" + sb1.toString)

        //47:获取列表索引为0的元素
        val t47 = list1(0)
        println("47:" + t47)

        //48:检测列表中是否包含指定的元素a
        if (list1.contains("a")) {
            println("48:包含有'a'")
        } else {
            println("48:不包含'a'")
        }

        //49：向list1列表中追加数据"a"
        val t49 = list1 :+ "a"
        println("49:" + t49)

        //50:去除list1列表的重复元素,并返回新列表
        val t50 = t49.distinct
        println("50:" + t50)

        //51:list1丢弃前3个元素，并返回新列表
        val t51 = list1.drop(3)
        println("51:" + t51)

        //52:list1丢弃最后2个元素，并返回新列表
        val t52  = list1.dropRight(2)
        println("52:" + t52)

        //53:检测列表list1是否以指定a结尾
        val t53 = list1.endsWith("a")
        println("53是否以指定a结尾:" + t53)

        //54:判断是否是以指定a开始的列表list1
        val t54 = list1.startsWith("a")
        println("54是否以指定a结尾:" + t54)

        //55:获取list1列表的第一个元素
        val t55 = list1(0)
        println("55 list1列表的第一个元素:" + t55)

        //56:在list1中从指定位置 0 开始查找元素d第一次出现的位置
        val t56 = list1.indexOf("d", 0)
        println("56 d第一次出现的位置:" + t56)

        //57:list1返回所有元素，除了最后一个
        val t57 = list1.init
        println("57:" + t57)

        //58:检测列表list1是否为空
        val t58 = list1.isEmpty
        println("58 检测列表list1是否为空:" + t58)

        //59:返回list1列表最后一个元素
        val t59 = list1.last
        println("59 返回list1列表最后一个元素:" + t59)

        //60:返回list1所有元素，除了第一个
        val t60 = list1.tail
        println("60 返回list1所有元素,除了第一个:" + t60)

        //61：提取列表list1的前2个元素
        val t61 = list1.take(2)
        println("61 提取列表list1的前2个元素:" + t61 )

        //62：提取列表list1的后2个元素
        val t62 = list1.takeRight(2)
        println("62 提取列表list1的后2个元素: " + t62)

        //63:列表list1转换为数组
        val t63 = list1.toArray
        println("63: " + t63.mkString(", "))

        //64: list1转换为 Seq
        val t64 = list1.toSeq
        println("64:"+ t64)

        //65:list1转换为 Set
        val t65 = list1.toSet
        println("65:" + t65)

        //66：list1列表转换为字符串
        val t66 = list1.toString
        println("66:" + t66)

        //67:list1列表反转
        val t67 = list1.reverse
        println("67:" + t67)

        //68:list1列表排序
        val t68 = list1.sorted
        println("68:" + t68)

        //69:检测list1列表在指定位置1处是否包含指定元素a
        val t69 = list1.startsWith("a", 1)
        println("69:" + t69)

        //70:列表list1转换为数组
        val t70 = list1.toArray
        println("70:" + t70.mkString(", "))
    }
}
/*
运行结果：
41:List(a, b, c, d, e)
42:List(t, a, b, c, d, e)
43List(m, n, a, b, c, d, e)
44:List(a, b, c, d, e, 4)
45:abcde
46:a, b, c, d, e
47:a
48:包含有'a'
49:List(a, b, c, d, e, a)
50:List(a, b, c, d, e)
51:List(d, e)
52:List(a, b, c)
53是否以指定a结尾:false
54是否以指定a结尾:false
55 list1列表的第一个元素:a
56 d第一次出现的位置:3
57:List(a, b, c, d)
58 检测列表list1是否为空:false
59 返回list1列表最后一个元素:e
60 返回list1所有元素,除了第一个:List(b, c, d, e)
61 提取列表list1的前2个元素:List(a, b)
62 提取列表list1的后2个元素: List(d, e)
63: a, b, c, d, e
64:List(a, b, c, d, e)
65:Set(e, a, b, c, d)
66:List(a, b, c, d, e)
67:List(e, d, c, b, a)
68:List(a, b, c, d, e)
69:false
70:a, b, c, d, e

*/
