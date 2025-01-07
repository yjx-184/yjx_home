file://<WORKSPACE>/MyPractise/ex12/ex_map.scala
### dotty.tools.dotc.ast.Trees$UnAssignedTypeException: type of Ident(map3) is not assigned

occurred in the presentation compiler.

presentation compiler configuration:


action parameters:
offset: 608
uri: file://<WORKSPACE>/MyPractise/ex12/ex_map.scala
text:
```scala

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
        val map3[String,@@] =Map()
    }
}
```



#### Error stacktrace:

```
dotty.tools.dotc.ast.Trees$Tree.tpe(Trees.scala:74)
	dotty.tools.dotc.util.Signatures$.applyCallInfo(Signatures.scala:208)
	dotty.tools.dotc.util.Signatures$.computeSignatureHelp(Signatures.scala:104)
	dotty.tools.dotc.util.Signatures$.signatureHelp(Signatures.scala:88)
	dotty.tools.pc.SignatureHelpProvider$.signatureHelp(SignatureHelpProvider.scala:47)
	dotty.tools.pc.ScalaPresentationCompiler.signatureHelp$$anonfun$1(ScalaPresentationCompiler.scala:439)
```
#### Short summary: 

dotty.tools.dotc.ast.Trees$UnAssignedTypeException: type of Ident(map3) is not assigned