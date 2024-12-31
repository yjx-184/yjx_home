import scala.io.Source

//定义一个对象
object countchars2 {
    
    def main(args : Array[String]) : Unit = {

        //定义一个函数，计算字符串s的长度转化为字符串，其字符串长度是多少。
        def widthOfLength(s: String) = s.length.toString.length

        //判断命令行参数是否是有效提供文件名
        if (args.length > 0 ) {

            // 使用 `Source.fromFile` 打开用户提供的文件名（`args(0)`）。
            // `getLines()` 逐行读取文件内容，返回一个迭代器。
            // `toList` 将迭代器转换为一个不可变的 List。
            val lines = Source.fromFile(args(0)).getLines().toList

            //// 使用 `reduceLeft` 方法找到文件中最长的一行。
            val longestLine = lines.reduceLeft(

                // `reduceLeft` 会从左向右遍历 `lines`，`a` 是当前最长的行，`b` 是下一行。
                // 比较 `a` 和 `b` 的长度，将更长的行作为新的结果继续比较，最终得到最长的一行。
                (a,b) => if (a.length > b.length) a else b
            )

            // 计算最长一行的长度表示的字符串长度。
            val maxWidth = widthOfLength(longestLine)

             // 遍历文件的每一行。
            for (line <- lines) {

                // 计算当前行的长度字符串需要多少空格填充，确保对齐打印
                 // `numSpaces` 是最大宽度与当前行长度宽度的差。
                val numSpaces = maxWidth - widthOfLength(line)

                // 创建一个包含 `numSpaces` 个空格的字符串，用于对齐。
                val padding = " " * numSpaces

                // 按指定格式打印当前行的信息：
                // 先打印填充的空格，再打印当前行的长度（右对齐），然后打印竖线和行内容。
                println(padding + line.length + " | " + line)
            }
        }
        else
            Console.err.println("Please enter filename")
    }
}
