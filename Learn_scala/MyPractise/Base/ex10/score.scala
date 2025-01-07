//练习10：学习成绩 >= 90分的同学用A表示，60-89之间的用B表示。60以下用C表示

object score {
    def main(args: Array[String]): Unit = {
        if(!args.forall(_.forall(_.isDigit))) {
            println("请输入一个有效成绩")
        } else {
            val n = args(0).toInt
            if (n > 100 || n <0) {
                println("请输入一个有效成绩(0-100)")
            } else {
                val grade = if (n >= 90) "A"
                            else if (n >= 60) "B"
                            else "C"
                println(s"成绩是 $grade")
            }
        }
    }
}