- [c语言练习](#c语言练习)
  - [练习2 用Make来代替Python](#练习2-用make来代替python)
  - [练习3 格式化输出](#练习3-格式化输出)
    - [man 3 printf](#man-3-printf)
  - [练习4 valgrind介绍](#练习4-valgrind介绍)
  - [练习5 一个c程序的结构](#练习5-一个c程序的结构)
  - [练习6 变量类型](#练习6-变量类型)
  - [练习7 更多变量和一些算术](#练习7-更多变量和一些算术)
  - [练习8 大小和数组](#练习8-大小和数组)
  - [练习9 数组和字符串](#练习9-数组和字符串)
  - [练习10 字符串数组和循环](#练习10-字符串数组和循环)
  - [练习11 While循环和布尔表达式](#练习11-while循环和布尔表达式)
  - [练习12 If，Else If，Else](#练习12-ifelse-ifelse)
  - [练习13 Switch语句](#练习13-switch语句)
  - [练习14 编写并使用函数](#练习14-编写并使用函数)
  - [练习15 指针](#练习15-指针)
  - [练习16 结构体和指向它们的指针](#练习16-结构体和指向它们的指针)
  - [练习17 堆和栈的内存分配](#练习17-堆和栈的内存分配)
    - [附加题](#附加题)
  - [练习18 函数指针](#练习18-函数指针)
  - [练习32 双向链表](#练习32-双向链表)
  - [练习33 链表算法](#练习33-链表算法)
  - [练习42 栈和队列](#练习42-栈和队列)
  - [练习44 环形缓冲区](#练习44-环形缓冲区)



# c语言练习
## 练习2 用Make来代替Python
1. 语法规则：  
```
目标 ... : 依赖 ...
   命令1
   命令2
```  
2. 变量：
   * 定义变量： VAR = value
   * 使用变量： $(VAR)
```
CC = gcc
CFLAGS = -Wall

hello: hello.c
   $(CC) $(CFLAGS) -o hello hello.c
```  
3. 伪目标
   * 伪目标不代表实际文件，通常执行一些操作。
   * 使用.PHONY声明伪目标
```
.PHONY: clean
clean:
   rm -f hello
```  
4. 自动变量
   * $@: 当前目标
   * $<: 第一个依赖
   * $^: 所有依赖
```
hello: hello.c
   $(CC) $(CFLAGS) -o $@ $<
```  
5. 模式规则
   使用通配符 % 来匹配文件名。
```
%.o: %.c
   $(CC) $(CFLAGS) -c $< -0 $@
```  
6. 函数
   $(wildcard pattern): 匹配文件。
```
SRC = $(wildcard ./*.c)
```  
匹配当前目录下所有.c文件，并将其赋值给SRC变量。  
7. 条件判断
   ifeq:判断两个值是否相等。
   ifneq：判断两个值是否不相等。
   ifdef：判断变量是否已定义（非空）。
   ifndef：判断变量是否为未定义（或为空）
```
ifeq ($(OS), Windows_NT)
   RM = del
else
   RM = rm -f
endif
```  
8. 包含其他Makefile
   使用include包含其他Makefile
9. 默认目标
    Makefile的第一个目标是默认目标，通常命名为all
10. 多目标规则
    可以为多个目标定义相同的规则。
```
file1 file2 file3:
   touch $@
```  
touch：如果目标不存在就建立，存在就访问和修改时间为当前时间

11. 命令前缀
    @：不显示命令本身。
    -：忽略命令的错误。
```
clean:
   -rm -f *.o
```  
12. 递归Make
    在子目录中调用Make
```
subdir:
   $(MAKE) -C subdir
```  
13. 文件查找路径
    使用 VPATH 或 vpath 指定文件查找路径。
```
VPATH = src:include
```  
14. 并行执行
    使用-j选项并行执行任务。
```
make -j4
```  
15. 隐式规则
    Makefile有一些内置的隐式规则，例如从.c文件生成,o文件。
```
%.o: %c
   $(CC) $(CFLAGS) -c $< -o $@
```  
16. 清理构建产物
    通常定义一个clean目标来删除构建产物
```
.PHONY: clean
clean:
   rm -f *.o hello
```  
17. 依赖生成
    使用-MMD选项自动生成依赖文件
```
CFLAGS += -MMD
-include $(OBJECTS:.o=.d)
```  
18. 多配置支持
    通过变量支持不同的构建配置（如Debug 和 Release）。
```
ifeq ($(BUILD),debug)
   CFLAGS += -g
else
   CFLAGS += -02
endif
```  
19. 调试
    使用-n选项显示但补执行命令。
    使用-p选项打印数据库（变量和规则）
```
make -n
make -p
```  
20. 文件存在检查
    使用if检查文件是否存在
```
ifeq ($(wildcard config.mk),)
   $(error config.mk not found)
endif
```
21. 目标依赖顺序
    使用 | 指定顺序依赖（不检查时间戳）
```
all: | dir1 dir2
```  
22. 多架构支持
    通过变量支持不同的架构。
```
ifeq ($(ARCH),x86)
    CFLAGS += -m32
else ifeq ($(ARCH),x64)
    CFLAGS += -m64
endif
```  
23. 默认目标设置
    使用 .DEFAULT_GOAL 设置默认目标。
```
.DEFAULT_GOAL := all
```  

## 练习3 格式化输出
练习3在示例中，展示了格式化输出的一些使程序崩溃的错误。同时也希望我们学会使用makefile。  

### man 3 printf
名称 printf, fprintf, dprintf, sprintf, snprintf, vprintf, vfprintf, vdprintf, vsprintf, vsnprintf - 格式化输出转换  
```
   int printf(const char *format, ...);
   /* format：格式化字符串，指定输出格式，可能包含普通文本和格式说明符（如 %d、%s 等）。
      ...（可变参数）：要格式化输出的值，对应 format 中的格式说明符。
      返回值：成功时返回写入的字符总数，失败时返回负值。
   */

   int fprintf(FILE *stream, const char *format, ...);
   /* stream：指定输出流，如 stdout（标准输出）或 stderr（标准错误）。
      其余参数与 printf 相同。
   */
   
   int dprintf(int fd, const char *format, ...);
   /* fd：文件描述符（如 1 代表标准输出，2 代表标准错误）。
      其余参数与 printf 相同。
   */

   int sprintf(char *str, const char *format, ...);
   /* str：目标字符串，格式化后的结果将被写入其中（需确保 str 足够大，避免溢出）。
      其余参数与 printf 相同。
   */

   int snprintf(char *str, size_t size, const char *format, ...);
   /* str：目标字符串。
      size：str 的大小，最多写入 size-1 个字符，并在末尾自动加 \0 终止符，防止缓冲区溢出。
      其余参数与 printf 相同。
   */


//这些函数与上面的 printf 系列功能相同，但不接受可变参数，而是接受 va_list 类型的参数（用于处理变长参数列表）。
   #include <stdarg.h>

   int vprintf(const char *format, va_list ap);
   /* ap：va_list 类型，存储可变参数列表（需用 va_start、va_arg 和 va_end 处理）。
      其余参数与 printf 相同。
   */

   int vfprintf(FILE *stream, const char *format, va_list ap);
   /* stream：指定输出流。
      ap：可变参数列表。
      其余参数与 printf 相同。
   */

   int vdprintf(int fd, const char *format, va_list ap);
   /* fd：文件描述符。
      ap：可变参数列表。
      其余参数与 printf 相同。
   */

   int vsprintf(char *str, const char *format, va_list ap);
   /* str：目标字符串（需确保足够大，避免溢出）。
      ap：可变参数列表。
      ap：可变参数列表。
      其余参数与 printf 相同。
   */

   int vsnprintf(char *str, size_t size, const char *format, va_list ap);
   /* str：目标字符串。
      size：str 的大小，最多写入 size-1 个字符，并在末尾加 \0 终止符。
      ap：可变参数列表。
      其余参数与 printf 相同。
   */

   //这些 v 开头的函数适用于自定义格式化输出函数或当参数数量未知时（如封装 printf）。
```  
描述：  
printf() 函数族根据下面描述的格式生成输出。函数 printf() 和 vprintf() 将输出写入标准输出流 stdout；fprintf() 和 vfprintf() 将输出写入指定的输出流；sprintf()、snprintf()、vsprintf() 和 vsnprintf() 将输出写入字符数组 str。  

dprintf() 与 fprintf() 类似，但它将输出写入文件描述符 fd，而不是 stdio 流。   
snprintf() 和 vsnprintf() 最多写入 size 个字节（包括终止的空字节 '\0'）到 str。  
vprintf()、vfprintf()、vdprintf()、vsprintf() 和 vsnprintf() 分别等价于 printf()、fprintf()、dprintf()、sprintf() 和 snprintf()，但它们使用 va_list 代替可变数量的参数。这些函数不会调用 va_end 宏。由于它们会调用 va_arg 宏，因此在调用后 ap 的值是未定义的。详见 stdarg(3)。  

所有这些函数都根据格式字符串的控制进行输出，该格式字符串指定了如何转换后续参数（或通过 stdarg(3) 访问的可变参数）以进行输出。  
C99 和 POSIX.1-2001 规定，如果调用 sprintf()、snprintf()、vsprintf() 或 vsnprintf() 可能导致对象之间发生重叠拷贝（例如，目标字符串数组和提供的输入参数引用同一个缓冲区），则结果是未定义的。  

格式字符串的格式  
格式字符串是一个字符字符串，以其初始转换状态（如果有）开始和结束。格式字符串由零个或多个指令组成：普通字符（非 %），它们将被直接复制到输出流；以及转换说明符，每个转换说明符都会获取零个或多个后续参数。每个转换说明符由字符 % 引入，并以转换说明符结尾。在此之间可以包含（按顺序）零个或多个标志、一个可选的最小字段宽度、一个可选的精度和一个可选的长度修饰符。  

## 练习4 valgrind介绍
简单介绍了Valgrind，以及如何使用。实验中，教程给的Valgrind安装包我出现了问题，后来下载了版本比较新的Valgrind。  

## 练习5 一个c程序的结构
这里希望我们去阅读代码并理解其中意思。

## 练习6 变量类型
这里的练习给我们展示了变量类型。  

整数：使用int声明，使用%d来打印。  
浮点：使用float或double声明，使用%f来打印。  
字符：使用char来声明，以周围带有'（单引号）的单个字符来表示，使用%c来打印。  
字符串（字符数组）：使用char name[]来声明，以周围带有"的一些字符来表示，使用%s来打印。  

输出十六进制： %x
输出八进制： %o
打印空字符串: '\0'

## 练习7 更多变量和一些算术
示例中的代码展示了：C语言的基本数据类型 int，double，long，char。整型与浮点型计算，以及隐式类型转换。  

unsigned表示：无符号整数，不存储负数，只存正数和 0。  

区别：  
int（有符号）：范围 -2147483648 到 2147483647（32 位）  
unsigned int（无符号）：范围 0 到 4294967295（32 位）  

为什么 char 可以和 int 相乘？  
在 C 语言中，char 本质上是一个 小的整数类型，通常占 1 字节（8 位）。  
在算术运算时，char 会被提升为 int（整型提升）。  

## 练习8 大小和数组
这个练习介绍了c语言中的数组、字符串和sizeof关键字。然后介绍了数组和字符串的初始化方式，通过sizeof计算数据类型和数组的大小，也说明c语言的字符串是char数组，并通过'\0'进行终止。根据实验希望使程序崩溃，程序可能会出现一些未定义行为或出现段错误。  

1.将full_name最后的'\0'去掉，并重新运行它，在valgrind下再运行一遍。现在将full_name的定义从main函数中移到它的上面，尝试在Valgrind下运行它来看看是否能得到一些新的错误。有些情况下，你会足够幸运，不会得到任何错误。  
 把'\0'去掉，printf将无法检测到终止符，可能访问内存中其他数据，导致输出未知字符。   
 如果把full_name变量定义到main之外，会把full_name变量变成全局变量。  

2.将areas[0]改为areas[10]并打印，来看看Valgrind会输出什么。  
 areas只有5个元素，areas[10]访问的是未初始化的内存，可能会输出未知值。如果访问到未非法地址，会导致段错误。  

3.访问name[10]  
 name[10]访问的是越界的字符数组，也会输出随机字符或者导致崩溃。  

## 练习9 数组和字符串
这个实验介绍了数组与字符串在c语言中的相似性和内存布局。数组可以通过部分初始化来自动填充余下的元素为0。字符数组既可以用逐个字符初始化，也可以直接用字符串字面值初始化，后者会自动在末尾加上'\0'作为终止符。在C语言中，字符串本质上就是一个以'\0'结尾的字符数组printf用%s格式输出时会依据'\0'来判断字符串的结束位置。不同的初始化方式（如char name[4] = {'a'} 与 char *another = "Zed"）会产生不同的存储效果，但最终打印结果表现为字符串。使用printf与sizeof可以查看数组中每个元素所占空间、数组总大小以及数组元素的个数，从而帮助理解底层内存如何分配与访问。

如果对int类型数组numbers中使用%c打印，编译器可能会发出类型不匹配警告。但是我在实验过程中没有报错，而是输出了空。通过valgrind检查也没有显示有错误。 

反过来使用%d打印char类型数组中的元素，最后打印的是该字符的ASCII。  
如果是打印整个数组则提示报错warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘char *’ [-Wformat=]

3.其它方式打印数组：  
对于字符数组：可以使用 %s、逐个使用 %c、或将数组转换为指针传递给函数。  

4.如果一个字符数组占四个字节，一个整数也占4个字节，你可以像整数一样使用整个 name 吗？如何用“黑魔法”实现它？  
 由于name是一个字符数组，其内存布局与整数相似，均占4个字节。可以进行如下操作，但是这种属于不安全的类型转换。  
```
int value = *(int *)name;
printf("%d\n", value);
```  

## 练习10 字符串数组和循环
这里实验主要介绍了如何使用数组中的字符串和使用for循环来遍历处理字符串数组。  

## 练习11 While循环和布尔表达式
这里实验主要介绍了while循环的使用和布尔表达式的工作原理，同时展示了while和for循环的区别。  

如果忘记初始化int i，那么循环条件可能使用一个随机值，导致访问非法内存从而导致崩溃或者是未定义行为。  

1.倒序循环  
```
for (i = argc - 1; i >= 0; i--) {
    printf("arg %d: %s\n", i, argv[i]);
}
```  

2.复制到states  
```
int i = 0;
while(i < argc && i < num_states) {
    states[i] = argv[i];
    i++;
}
```  

3.研究字符串复制是否真的发生  
如果只是复制指针，那么我们就没有复制字符串的实际内容，而是使指针指向同一个地址。想要复制真正的字符串，需要使用到strcpy()或者strncpy()函数，分配足够的内存然后逐字符复制。  

## 练习12 If，Else If，Else
这里实验主要是介绍了If，Else If，Else的基本使用方法。argv[0]是程序本身的名称。  

## 练习13 Switch语句
这里实验主要是介绍了Switch语句的基本用法。使用时要注意一定要写default分支，用于处理所有没有匹配到case的情况，防止遗漏输入。  

当if代码外面写break：  
```
case 'y':
                if(i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                }
                break;
```  
这里无论if判断结果如何，都会执行break跳出switch语句。这里保证了switch语句遇到y时会停止，不会贯穿到default分支或下一个case。  

当if代码内写break：  
```
case 'y':
                if(i > 2) {
                    // it's only sometimes Y
                    printf("%d: 'Y'\n", i);
                    break;
                }              
```  
这里当遇到y或Y时：如果 i > 2：执行 if 内部的代码，打印 "Y"，然后执行 break 跳出 switch。如果 i <= 2：if 条件为假，不会执行 break，于是 switch 不会中断，会继续执行后面的代码。  
这可能导致错误的输出：当 i <= 2 时，'y' 会被当作未匹配的情况处理，而默认打印一条 “not a vowel” 的消息。  

## 练习14 编写并使用函数
这里实验主要是介绍如何编写并使用自己的函数，从而扩展程序的功能。其中包括：前向声明，在文件开头通过前向声明告诉编译器会有哪些函数的定义； 函数的定义与调用。通过定义函数能将程序拆分成多个模块，使代码更清晰与易于维护； 参数传递与数组处理。  

man strlen:  
名称  
strlen - 计算字符串的长度  

概要：  
```
#include <string.h>

 size_t strlen(const char *s);
```  
strlen() 函数计算由 s 指向的字符串的长度，不包括终止空字节 ('\0')。  
返回值：strlen() 函数返回 s 指向的字符串中字节的个数。  


man isalpha  
名称
isalnum, isalpha, isascii, isblank, iscntrl, isdigit, isgraph,  
islower, isprint, ispunct, isspace, isupper, isxdigit,  
isalnum_l, isalpha_l, isascii_l, isblank_l, iscntrl_l, isdigit_l,  
isgraph_l, islower_l, isprint_l, ispunct_l, isspace_l, isupper_l,  
isxdigit_l - 字符分类函数  

概要：  
```
   int isalnum(int c);  
   int isalpha(int c);  
   int iscntrl(int c);  
   int isdigit(int c);  
   int isgraph(int c);  
   int islower(int c);  
   int isprint(int c);  
   int ispunct(int c);  
   int isspace(int c);  
   int isupper(int c);  
   int isxdigit(int c);  

   int isascii(int c);  
   int isblank(int c);  

   int isalnum_l(int c, locale_t locale);  
   int isalpha_l(int c, locale_t locale);  
   int isblank_l(int c, locale_t locale);  
   int iscntrl_l(int c, locale_t locale);  
   int isdigit_l(int c, locale_t locale);  
   int isgraph_l(int c, locale_t locale);  
   int islower_l(int c, locale_t locale);  
   int isprint_l(int c, locale_t locale);  
   int ispunct_l(int c, locale_t locale);  
   int isspace_l(int c, locale_t locale);  
   int isupper_l(int c, locale_t locale);  
   int isxdigit_l(int c, locale_t locale);  

   int isascii_l(int c, locale_t locale);  
```  

描述：  
这些函数检查 c（必须是无符号字符的值或 EOF）是否属于特定的字符类别，并依据指定的区域设置进行分类。没有 "_l" 后缀的函数基于当前区域设置进行检查。带有 "_l" 后缀的函数使用 locale 对象 locale 进行检查。如果 locale 是特殊的 LC_GLOBAL_LOCALE（参见 duplocale(3)），
或者不是有效的区域设置对象句柄，则这些函数的行为未定义。  
```
   以下列表说明了没有 "_l" 后缀的函数的操作，  
   带有 "_l" 后缀的函数仅在使用 locale 对象进行检查时有所不同。  

   isalnum()  
          检查是否为字母或数字字符；等价于 (isalpha(c) || isdigit(c))。  

   isalpha()  
          检查是否为字母字符；在标准 "C" 语言环境下，  
          等价于 (isupper(c) || islower(c))。  
          在某些语言环境中，可能会有额外的字母字符，即既不是大写也不是小写的字符。  

   isascii()  
          检查 c 是否为 7 位无符号字符，并且属于 ASCII 字符集。  

   isblank()  
          检查是否为空白字符，即空格或制表符。  

   iscntrl()  
          检查是否为控制字符。  

   isdigit()  
          检查是否为数字（0 到 9）。  

   isgraph()  
          检查是否为可打印字符（但不包括空格）。  

   islower()  
          检查是否为小写字母。  

   isprint()  
          检查是否为可打印字符（包括空格）。  

   ispunct()  
          检查是否为可打印字符，且既不是空格也不是字母或数字字符。  

   isspace()  
          检查是否为空白字符。在 "C" 和 "POSIX" 语言环境下，  
          这些字符包括：空格、换页符 ('\f')、换行符 ('\n')、  
          回车符 ('\r')、水平制表符 ('\t') 和垂直制表符 ('\v')。  

   isupper()  
          检查是否为大写字母。  

   isxdigit()  
          检查是否为十六进制数字，即 0-9、a-f、A-F 之一。  

```  
返回值：如果字符 c 属于测试的类别，则返回非零值，否则返回 0。

## 练习15 指针
这里的实验主要介绍了指针的基本概念以及指针和数组的关系。通过四种不同的方式访问和打印数组的数据，包括使用索引访问数组、指针加偏移、指针作为数组使用，以及利用指针算术操作遍历数组。  

指针的基本概念：1.指针存储的是地址，它指向某个变量的内存位置。 2.int *ptr表示ptr是一个指向int类型变量的指针。 3.char **ptr表示ptr是一个指向char *类型的指针。  

指针和数组的关系：1.数组名ages本质上是一个指针，指向数组的首地址。 2.ages[i] 和 *(ages + i) 是等价的。 3.cur_age[i] 和 *(cur_age + i) 也是等价的。 4.指针可以像数组一样使用，例如 cur_age[i]，但 sizeof(cur_age) 仅返回指针的大小，而 sizeof(ages) 返回整个数组的大小。  

指针运算：1.ptr + i 会移动 i * sizeof(type) 字节。 2.ptr++ 让 ptr 指向下一个元素（指针向前移动一个 sizeof(type)）。 3.(cur_age - ages) < count 计算指针之间的偏移量。  

指针的实际用途：1.处理动态内存分配（例如 malloc）。 2.通过指针传递大块数据，提高效率。 3.解析数据结构，如字符串、文件、网络协议。  

## 练习16 结构体和指向它们的指针
这个实验主要是介绍结构体及其指针，并结合动态内存分配来进行内存管理喔、指针操作以及如何使用结构体来组织数据。  

1.传递NULL给Person_destroy，程序会执行assert(who != NULL); 程序因为断言而失败崩溃。  
2.忘记调用Person_destroy，然后用Valgrind运行，Valgrind会报告内存泄露，提示malloc申请的内存没有被free释放。  
3.在Person_destroy里忘记free(who->name)，malloc 分配了但没 free（即 strdup(name) 申请的字符串泄露了）。泄露的字节数等于字符串的长度 + 1（因为 strdup 也会分配 \0）。  

man strcpy  
名称 strcpy, strncpy - 复制字符串  
概要：  
```
#include <string.h>

    char *strcpy(char *dest, const char *src);
    /* dest：目标字符串，表示复制后的字符串存放的位置。这个缓冲区必须足够大，能够容纳src 字符串以及终止符 '\0'。
       src：源字符串，表示需要被复制的字符串。 
    */


    char *strncpy(char *dest, const char *src, size_t n);
    /* dest：目标字符串，表示复制后的字符串存放的位置。同样，缓冲区要足够大，能够容纳复制的内容。
       src：源字符串，表示需要被复制的字符串。
       n：最多复制的字节数。这个参数指定了从 src 字符串中复制的最大字节数。如果 src 中的字符串小于 n，则会在目标字符串末尾补充空字节 '\0'，直到写满 n 字节。如果 src 字符串长于 n，则只会复制前 n 个字节。
    */
```  
总结：  
strcpy 会复制整个源字符串（包括终止符）。  
strncpy 复制源字符串的前 n 个字符，且可能不会复制终止符，取决于 src 的长度。  

描述：  
strcpy() 函数将 src 所指向的字符串（包括终止的空字节 '\0'）复制到 dest 所指向的缓冲区中。源字符串和目标字符串不得重叠，且目标字符串 dest 必须足够大以容纳复制的内容。需要小心缓冲区溢出！  
strncpy() 函数与 strcpy() 类似，不同的是最多复制 n 个字节的 src 内容。警告：如果在 src 的前 n 个字节中没有空字节，则目标字符串 dest 不会以 null 终止。  
如果 src 的长度小于 n，strncpy() 会向 dest 写入额外的空字节，以确保总共写入 n 个字节。  
一个简单的 strncpy() 实现如下：  
```
char * strncpy(char *dest, const char *src, size_t n) { 
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)
               dest[i] = src[i];
           for ( ; i < n; i++)
               dest[i] = '\0';

           return dest;
       }
```

所以附加题：  
```
void Person_create(struct Person *who, const char *name, int age, int height, int weight)
{
    strncpy(who->name, name, sizeof(who->name )- 1);
    who->name[sizeof(who->name) - 1] = '\0';
    who->age = age;
    who->height = height;
    who->weight = weight;
}

int main(int argc, char *argv[])
{
    //栈上结构体实例
    struct Person joe;
    struct Person frank;

    //----
}
```  
在 C 语言中，内存分配有两种主要方式：使用 malloc 从堆上分配内存和在栈上分配内存。它们各自有不同的特点，适用于不同的场景。  

1.堆内存分配（malloc）  
内存管理：使用 malloc 函数从堆上动态分配内存。堆内存的生命周期由程序员控制，必须显式地使用 free 释放，否则会发生内存泄漏。  
内存分配大小：malloc 允许程序在运行时根据需要动态分配内存大小。这对于处理不确定或变化的数据结构（如动态数组、链表等）非常有用。  
适用场景：当你不知道在编译时所需内存的确切大小，或者需要在函数间传递数据，且数据的生命周期超出当前作用域时，堆内存是更好的选择。  

缺点：  
内存分配和释放需要显式操作，容易忘记释放内存而导致内存泄漏。  
堆内存的分配和释放比栈内存要慢，因为它需要在内存管理系统中进行更多的操作。  


2.栈内存分配  
内存管理：栈内存由编译器自动管理。当函数调用时，局部变量被分配到栈上，函数返回时自动销毁，无需显式地释放内存。  
内存分配大小：栈内存的大小是固定的，由编译时确定。如果需要分配的内存过大，可能会导致栈溢出错误。通常适用于较小的、生命周期短的数据结构。  
适用场景：适用于函数内部的局部变量，且这些变量的生命周期仅限于函数的执行周期。栈内存分配速度非常快，因为它是通过简单的指针操作来管理的。  

缺点：  
栈内存的大小是有限制的，一般受到系统的栈大小限制，如果过多地使用栈内存，可能会导致栈溢出。  
栈内存的生命周期有限，不能用于存储需要在函数返回后继续使用的数据。  

## 练习17 堆和栈的内存分配
这个实验确实是增加了难度，帮助我们深入理解堆和栈的内存分配，并展示了如何如何使用动态内存分配和结构体来管理复杂的数据。例子通过实现一个简易的数据库系统，结合了堆和栈内存的使用，帮助我们理解这两种内存分配方式在实际编程中的应用。  
教程的例子主要是：  
**1.内存分配**  
* 堆内存分配：通过malloc动态分配内存，对Database结构体进行堆内存分配，需要显式地管理内存释放，避免内存泄漏。  
* 栈内存分配：一些局部变量（例如struct Address）分配在栈上，自动由编译器管理内存的分配和释放。  
**2.数据库管理**  
* 程序实现了一个小型的数据库系统，能够创建、读取、更新、删除和列出地址记录。每条记录都保存在 struct Address 结构体中，数据库的结构由 struct Database 来组织。  
* 数据库内容通过文件进行持久化，使用 fopen, fread, fwrite, fclose 等标准库文件操作函数进行文件读写。  

**3.错误处理**  
通过 die 函数处理程序中的错误，出现错误时会调用 exit 终止程序运行，并使用 errno 和 perror 来提供详细的错误信息。  

**4.结构体和指针**  
* 使用结构体来组织和管理数据。通过结构体的指针操作实现对数据库记录的修改和访问，理解了指针在内存管理中的重要性。  
* 例如，使用 conn->db->rows[i] 访问特定记录。  

注意事项：  
1.使用 malloc 分配内存时，内存不会自动释放，必须显式调用 free 来释放内存，防止内存泄漏。  
2.栈内存由编译器自动管理，适用于函数内的局部变量；而堆内存适用于动态分配的、大量数据的管理。  

例子中的主要函数：  
```
die(const char *message)：                  用于错误处理，打印错误信息并退出程序。
Address_print(struct Address *addr)：       打印单个地址记录。
Database_load(struct Connection *conn)：    从文件加载数据库。
Database_open(const char *filename, char mode)：打开数据库连接。
Database_close(struct Connection *conn)：   关闭数据库连接并释放内存。
Database_write(struct Connection *conn)：   将数据库写入文件。
Database_create(struct Connection *conn)：  创建一个空的数据库。
Database_set(struct Connection *conn, int id, const char *name, const char *email)：设置指定ID的地址记录。
Database_get(struct Connection *conn, int id)：获取并打印指定ID的地址记录。
Database_delete(struct Connection *conn, int id)：删除指定ID的地址记录。
Database_list(struct Connection *conn)：    列出所有已设置的地址记录。
```  

**man fread:**  
名称 fread, fwrite - 二进制流输入/输出  
概要：  
```
#include <stdio.h>

   size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
   /* ptr:一个指向存储读取数据的内存区域的指针。fread 将从 stream 中读取的数据存储到这个内存区域。
      size:每个数据项的大小，以字节为单位。例如，如果要读取一个 int 类型的数据，size 就是 sizeof(int)。
      nmemb:要读取的数据项的数量。即希望从文件中读取多少个数据项。
      stream:指向 FILE 类型的指针，表示要从中读取数据的文件流。
   */

   size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                 FILE *stream);
    /* ptr:一个指向存储待写入数据的内存区域的指针。fwrite 从这个内存区域读取数据并写入到 stream 中。
       size:每个数据项的大小，以字节为单位。例如，如果要写入一个 int 类型的数据，size 就是 sizeof(int)。
       nmemb:要写入的数据项的数量。即希望向文件中写入多少个数据项。
       stream:指向 FILE 类型的指针，表示要向其中写入数据的文件流。
    */
```  
返回值：  
fread 返回实际读取的数据项数量。如果返回值少于 nmemb，可能是遇到了文件结束或发生了错误。  
fwrite 返回实际写入的数据项数量。如果返回值少于 nmemb，可能是发生了错误或磁盘空间不足等问题。  

**man fflush:**  
名称:fflush - 刷新流  
摘要：  
```
#include <stdio.h>

int fflush(FILE *stream);
```  
描述:  
对于输出流，fflush() 强制将所有用户空间缓冲区中的数据通过流底层的写函数写出。  
对于与可定位文件关联的输入流（例如磁盘文件，但不包括管道或终端），fflush() 丢弃那些已从底层文件获取但尚未被应用程序消耗的缓冲数据。  
流的打开状态不会受到影响。    
如果 stream 参数为 NULL，fflush() 会刷新所有已打开的输出流。  

返回值：成功时返回 0；否则返回 EOF，并设置 errno 来指示错误。  

**man perror**  
名称:perror - 打印系统错误消息  
```
#include <stdio.h>

void perror(const char *s);

#include <errno.h>

const char * const sys_errlist[];
int sys_nerr;
int errno;       /* 实际上并非以这种方式声明；请参阅 errno(3) */
```  
perror() 函数会在标准错误输出 (stderr) 上打印一条消息，描述最近一次调用系统或库函数时遇到的错误。  


### 附加题
1. die函数需要接收conn变量作为参数，以便执行清理并关闭它。  
2. 修改代码，使其接收参数作为MAX_DATA和MAX_ROWS，将它们储存在Database结构体中，并且将它们写到文件。这样就可以创建任意大小的数据库。  
3. 向数据库添加更多操作，比如find。

一开始我想直接把MAX_DATA和MAX_ROWS作为变量，然后通过命令行进行修改参数从而达到目的，后来编译时出现报错，必须要确定好大小，因此改用malloc动态分配内存。  

所以我做了一下修改：
1. 对结构体Address，将name和email改为char *类型的指针。  
2. 对结构体Database，添加了两个int类型成员max_data每条记录中name和email字段的最大长度，max_rows是数据库中最大记录数。  
3. 对函数Database_open，在函数签名中添加了max_data,max_rows。并且函数内初始化了它们，同时也添加了，分配内存给存储所有地址记录的数组。接着初始化每条记录，并给name和email分配内存。  
4. 对函数Database_create，修改为根据max_rows和max_data动态初始化数据库。为每条记录的name和email分配内存，并使用memset将其初始化为空字符串，保证数据的安全性。  
5. 对函数Database_load，从文件中读取max_data和max_rows，并根据这些值动态分配内存。读取每条记录的id,set,name,email，并为其分配内存，确保数据正确加载。  
6. 对函数Database_write，将max_data和max_rows写入文件，以便在加载时能够正确恢复数据库配置。写入每条记录的id,set,name,email，确保数据能够正确保存。  
7. 对函数Database_delete，修改为释放name和email的内存，并重新分配内存，同时避免导致内存泄漏。  
8. 对函数Database_close，修改为释放所有动态分配的内存，包括每一条记录的name和email，以及rows数组和数据库结构喔本身，确保没有内存泄漏。  
9. 对组函数main，修改了参数解析的逻辑，支持在创建数据库时指定max_data和max_rows.同时根据操作类型动态调整参数索引，确保正确解析id,name,email。  
10. 添加了函数Database_find，通过遍历数据库中所有记录，并且每次循环都通过conn->db->rows[i]来获取当前记录的指针addr。检查所有addr->set被设置为1的，和使用strstr函数检查addr->name 和 addr->email是否有包含关键字keyword。最后打印匹配记录。  


## 练习18 函数指针
这个练习主要是介绍了函数指针的使用。函数指针是：指向函数的指针，它存储的是函数的地址，可以通过它来调用函数。  

定义函数指针：  
```
返回类型 (*指针变量名)(参数列表);
```  

修改ex18代码可能会导致程序崩溃或者行为异常。修改字符串只印象数出，不影响程序逻辑。传递错误函数，可能导致栈损坏或排序逻辑错误。传递NULL会直接Segmentation Fault段错误。  

## 练习32 双向链表
**数据结构是什么**  
“数据结构”这个名称自己就能够解释。它是具有特性模型的数据组织方法。这一模型可能设计用于以新的方法处理数据，也可能只是用于将它们更高效地储存在磁盘上。这本书中我会遵循一些简单的模式来构建可用的数据结构：  
* 定义一个结构的主要“外部结构”。  
* 定义一个结构的内容，通常是带有链接的节点。  
* 创建函数操作它们的函数。  
  
**双向链表**  
单向链表通过指向下一个或上一个元素的节点来工作。“双向”链表持有全部这两个指针，而“单向”链表只持有下一个元素的指针。  

由于每个节点都有下一个和上一个元素的指针，并且你可以跟踪联保的第一个和最后的元素，你就可以快速地执行一些操作。任何涉及到插入和删除元素的操作会非常快。它对大多数人来说也易于实现。  

链表的主要缺点是，遍历它涉及到处理沿途每个单个的指针。这意味着搜索、多数排序以及迭代元素会表较慢。这也意味着你不能直接跳过链表的随机一部分。如果换成数组，你就可以直接索引到它的中央，但是链表不行。也就是说如果你想要访问第十个元素，你必须经过1~9。  

在后续的实验中，我给教程上的代码添加注释，以便阅读理解。  


1. 研究双向和单向链表，以及什么情况下其中一种优于另一种。
```
单向链表：
    特点：只能从头节点开始顺序访问，无法直接访问前一个节点
    优点：占用内存少，每个节点只需要存储一个指针。
    缺点：无法从尾部向头部遍历链表；删除节点复杂，需要知道它的前驱节点。

双向链表：
    特点：每个节点包含一个指向下一个节点的指针next和指向前一个节点的prev，可以从头或尾节点遍历
    优点：双向遍历；删除节点简单。
    缺点：占用内存多，每个节点要存储两个指针。
```   
**单向链表** 适用于内存较为紧张的环境或只需要简单头部插入和删除操作的应用。  
**双向链表** 适用于频繁在中间或尾部插入、删除节点的情况，或者需要从两端进行遍历的情况，但由于额外的内存开销和操作复杂性，在需要频繁更新节点内容的场景下可能不如单向链表高效。  

2. 研究双向链表的限制。例如，虽然它们对于插入和删除元素很高效，但是对于变量元素比较慢。  
**双向链表的“变量元素比较慢”问题**   
双向链表的“变量元素比较慢”的问题并不在于链表本身，而是由于其内部的更新操作和指针维护。每次插入或删除节点时，除了更新当前节点的指针，还需要更新相邻节点的指针。对于需要频繁修改链表元素内容的应用（比如频繁修改链表节点的值），双向链表的维护开销可能导致性能瓶颈。  
例如，如果有大量的插入、删除或更新操作，双向链表的两个指针需要在每个操作中同时更新，这增加了每个操作的时间和复杂度。  

**双向链表的限制**  
* 内存开销：如上所述，每个节点都需要存储两个指针（next 和 prev），因此双向链表的内存消耗比单向链表大。这对于存储非常大数据量的链表时，会产生显著的内存压力。  
* 更新操作的复杂性：尽管双向链表提供了在O(1)时间内插入和删除节点的能力，但如果需要频繁更新指针（如修改next 或 prev），代码变得更加复杂。这是因为每次插入或删除节点时，除了当前节点的指针，还需要更新相邻节点的指针。  
* 复杂度增加：节点比单向链表的节点多了一个指针（prev），这导致了代码的复杂性增加。需要小心处理插入、删除操作中next和prev的更新，尤其是边界情况（例如链表的头部和尾部节点）。  
* 性能问题：在某些情况下，如果插入和删除操作是偶尔发生，而大部分时间链表仅用于遍历和查找，双向链表可能不如单向链表高效。双向链表额外的指针存储和更新操作可能会影响性能，尤其是在对每个节点进行频繁遍历时。  

3. 还缺少什么你能想到的操作？比如复制、连接、分割等等。实现这些操作，并且为它们编写单元测试。  
想要实现复制，其步骤就是：首先，创建一个新的空链表new_list。然后，遍历原链表list并将每个节点的值通过List_push方法添加到new_list中。List_push会将新的值插入新链表的尾部。最后，完成遍历后返回新的链表new_list。如果在创建新的链表或添加节点的过程中出现内存分配错误，函数会释放new_list并返回null。  

想要实现连接，其步骤是：首先检查list2是否为空。如果为空什么也不做，直接返回。如果list1为空，那么直接将list2的头节点和尾节点赋给list1。这种情况意味着list1变成了list2,不需要额外的连接操作。然后判断如果list1不是为空，list2也不是为空，则将list1的尾节点next指针指向list2的头节点，并更新list2的头节点的prev指针指向list1的尾节点。之后，更新list1的尾节点为list2的尾节点，合并两个链表的长度。最后，清空list2节点信息将list2->first、list2->last 和 list2->count设置为初始状态），因为list2的内容已经被合并到list1中。  

想要实现分割，需要指定索引位置index处分成两个链表，其步骤是：首先检查索引是否有效，index应该在0和链表长度减1之间。如果无效返回null。接着，创建一个新的空链表new_list，遍历原链表，找到索引位置index对应的节点。然后，将原链表从这个节点处分成两个部分，新链表new_list的头节点是node，尾节点是原链表的尾节点。更新原链表的尾节点为node的前一个节点，并将node的prev指针设为null，断开与原链表的连接。最后更新list和new_list的节点数量，确保它们正确反映了各自包含的元素数量。如果在创建新链表或修改链表结构的过程中出现内存问题，函数会释放new_list并返回null。

## 练习33 链表算法
这里的实验主要是通过实现和测试两种排序算法（冒泡排序和归并排序）来学习和理解如何在链表上操作数据。  

实验中我们具体做了：
1. 实现两种排序算法： **冒泡排序** 一种简单的排序算法，通过多次遍历链表并交换相邻节点的值来实现排序。 **归并排序** 一种更高小的排序算法，通过递归地将链表分成两半，分别排序后再合并。 
2. 编写单元测试：实验提供了一套完成的单元测试代码，用于验证排序算法的正确性。测试包括对未排序链表，已排序链表和空链表的排序。  

结果：  
```
yjx@yjx-Lenovo-Legion-R7000-2020:~/Mystudy/yjx_learn/Learn_C/exercise33$ make clean all
cc -g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG  -fPIC   -c -o src/lcthw/list_algos.o src/lcthw/list_algos.c
cc -g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG  -fPIC   -c -o src/lcthw/list.o src/lcthw/list.c
Running unit tests:
----
运行中: ./tests/list_algos_tests
所有测试通过
测试运行: 2
tests/list_algos_tests PASS
```  

为什么对链表排序十分麻烦？  
对链表排序之所以麻烦，主要是由于链表的数据结构特性和操作限制导致的。相比于数组或其他数据结构，链表在排序时面临以下几个主要问题：  
1. **随机访问的缺失**  
   数组：可以通过下标直接访问元素时间复杂度为O(1)。  
   链表：只能从头节点开始逐个遍历，访问第n个元素的时间复杂度为O(n)。  
   影响：在排序算法中（如快速排序、归并排序），通常需要频繁访问中间元素或随机位置的元素，而链表的随机访问效率极低。例如，归并排序需要将链表分成两半，而找到链表的中间节点需要遍历整个链表。  
2. **交换操作的复杂性**  
   数组：交换两个元素的值非常简单，只需要通过下标直接修改。  
   链表：交换两个节点的值需要修改指针，操作复杂且容易出错。  
   影响：在冒泡排序中，每次比较后可能需要交换相邻节点的值。链表的交换操作需要修改前后节点的指针，增加了实现的复杂性。如果直接交换节点的值，虽然简单，但可能不符合链表的“逻辑结构”，尤其是在节点存储复杂数据时。  
3. **递归和分治算法的实现困难**
   数组：可以很容易地将数组分成多个子数组进行递归操作。  
   链表：分割链表需要遍历链表找到中间节点，且递归操作会频繁创建和销毁链表，增加了时间和空间复杂度。  
   影响：归并排序在链表上的实现需要额外的空间来存储分割后的子链表，且递归深度较大时可能导致栈溢出。快速排序在链表上的实现更加复杂，因为需要频繁修改指针。  
4. **空间复杂度较高**  
   数组：许多排序算法（如快速排序、堆排序）可以在原地排序，空间复杂度为O(1)。  
   链表：排序算法通常需要额外的空间来存储临时链表或递归调用栈。  
   影响：归并排序在链表上的实现需要额外的空间来存储合并后的链表。如果使用递归实现，递归调用栈也会占用额外的空间。  
5. **指针操作的复杂性**
   数组：排序时只需要关注元素的值，不需要关心元素的存储位置。  
   链表：排序时需要频繁修改节点的指针，操作复杂且容易出错。  
   影响：在排序过程中，链表的指针需要被正确维护，否则可能导致链表断裂或循环。例如，在归并排序中，合并两个子链表时需要仔细处理指针的指向。  
6. **性能问题**
   数组：许多排序算法（如快速排序、堆排序）的时间复杂度为O(n log n)，且常数因子较小。  
   链表：排序算法的时间复杂度通常较高，且常数因子较大。  
   影响：链表的排序算法通常比数组慢，尤其是在数据量较大时。例如，冒泡排序在链表上的时间复杂度仍然是O(n^2)，但由于指针操作的复杂性，实际运行时间可能更长。  
7. **边界情况的处理**  
   数组：边界情况（如空数组、单个元素数组）通常比较容易处理。  
   链表：边界情况（如空链表、单个节点链表）需要额外注意指针的处理。  
   影响：在实现排序算法时，需要额外处理链表的边界情况，增加了代码的复杂性。例如，归并排序需要检查链表是否为空或只有一个节点。  

总结：  
对链表排序之所以麻烦，主要是因为链表的以下特性：  
* 无法随机访问，导致查找中间节点或分割链表时需要遍历。  
* 指针操作复杂，交换节点或合并链表时需要仔细维护指针。  
* 空间复杂度较高，许多排序算法需要额外的空间。  
* 性能较差，排序算法的时间复杂度通常较高。  

## 练习42 栈和队列
这里的实现主要是通过实现栈（Stack）和队列（Queue）这两种基本的数据结构。  

实验的具体操作：  
1. **实现栈stack**  
   栈是一种**后进先出（LIFO）**的数据结构，只允许在一端（通常称为“栈顶”）进行插入（压栈）和删除（弹栈）操作。    

   实现以下功能：  
   * Stack_create：创建栈。  
   * Stack_destroy：销毁栈。  
   * Stack_push：将元素压入栈。  
   * Stack_pop：从栈中弹出元素。  
   * Stack_peek：查看栈顶元素但不弹出。  
   * Stack_count：获取栈中元素的数量。
  
2. **实现队列Queue**  
   队列是一种**先进先出（FIFO）**的数据结构，允许在一端（队尾）插入元素，在另一端（队头）删除元素。  

   实现以下功能：  
   * Queue_create：创建队列。  
   * Queue_destroy：销毁队列。  
   * Queue_send：将元素插入队尾。  
   * Queue_recv：从队头删除并返回元素。  
   * Queue_peek：查看队头元素但不删除。  
   * Queue_count：获取队列中元素的数量。  
  
DArray 是 动态数组（Dynamic Array），它是一种可以动态调整大小的数组数据结构。与静态数组（如C语言中的普通数组）不同，动态数组可以根据需要自动扩展或收缩其容量，从而更灵活地管理内存。  

动态数组的特点：  
1. 动态扩容：当数组的容量不足以存储新元素时，动态数组会自动分配更大的内存空间，并将原有数据复制到新空间中。扩容通常以一定的倍数（如2倍）进行，以平摊扩容的成本。   
2. 随机访问：和普通数组一样，动态数组支持通过下标（索引）直接访问元素，时间复杂度为O(1)。  
3. 尾部操作高效：在动态数组的尾部插入或删除元素的时间复杂度为O(1)（假设不需要扩容）。中间或头部插入或删除元素的时间复杂度为O(n)，因为需要移动后续元素。  
4. 内存连续：动态数组的元素在内存中是连续存储的，这与链表不同。  
   
实现以下功能：  
* DArray_create：创建一个动态数组。
* DArray_destroy：销毁动态数组，释放内存。
* DArray_clear：清除数组内容（释放每个元素的内存），但不销毁数组本身。
* DArray_expand：扩展数组的容量。
* DArray_contract：收缩数组的容量到实际使用量。
* DArray_push：向数组中添加一个元素。
* DArray_pop：从数组中弹出一个元素。
* DArray_clear_destroy：清除并销毁数组（先清除内容，再销毁数组）。
* DArray_set：设置数组中某个位置的元素。
* DArray_get：获取数组中某个位置的元素。
* DArray_remove：移除数组中某个位置的元素并返回该元素。
* DArray_new：为数组中新元素分配内存。
* DArray_free：释放某个元素的内存。  


## 练习44 环形缓冲区
这个练习主要是实现并测试一个环形缓冲区（Ring Buffer），这是一种用于处理异步 I/O 的高效数据结构。环形缓冲区可以在固定大小的内存空间中循环存储数据，适用于需要高效读写操作的场景，如网络通信、音频处理等。  

教程给出的例子：  

1. 实现环形缓冲区：  
   定义一个RingBuffer结构体，包含以下字段：  
   * buffer：存储数据的缓冲区。
   * length：缓冲区的总长度。
   * start：数据的起始位置。
   * end：数据的结束位置。  
  
   实现了环形缓冲区的核心功能：  
   * 创建和销毁：RingBuffer_create 和 RingBuffer_destroy。
   * 读写操作：RingBuffer_write 和 RingBuffer_read。
   * 辅助功能：RingBuffer_empty、RingBuffer_full、RingBuffer_available_data 和 RingBuffer_available_space。
   * 字符串操作：RingBuffer_gets 用于从缓冲区读取字符串。

2. 宏定义：  
   提供了一些宏来简化环形缓冲区的操作，例如：
   * RingBuffer_available_data：计算缓冲区中可读取的数据量。
   * RingBuffer_available_space：计算缓冲区中可写入的空间。
   * RingBuffer_commit_read 和 RingBuffer_commit_write：更新 start 和 end 指针。

环形缓冲区的工作原理：  
1. 循环存储：环形缓冲区的核心思想是通过 start 和 end 指针在固定大小的缓冲区中循环移动。当数据到达缓冲区末尾时，指针会回到缓冲区的开头，从而实现“循环”存储。  
2. 高效读写：写入数据时，数据从 end 指针位置开始存储，end 指针向后移动。读取数据时，数据从 start 指针位置开始读取，start 指针向后移动。当 start 或 end 指针到达缓冲区末尾时，它们会回到开头，继续操作。
3. 边界处理：当缓冲区满时，写入操作会失败。当缓冲区空时，读取操作会失败。通过 RingBuffer_empty 和 RingBuffer_full 可以检查缓冲区的状态。  

**POSIX的技巧**  
POSIX（Portable Operating System Interface，可移植操作系统接口）是一组标准，定义了操作系统应该提供的接口和行为，以确保软件在不同操作系统之间的可移植性。POSIX 标准涵盖了许多方面，包括文件操作、进程管理、线程、信号、内存管理等。  

在环形缓冲区（Ring Buffer）的上下文中，提到“POSIX 的技巧”通常指的是利用 POSIX 标准中提供的一些系统调用或特性来优化环形缓冲区的实现。以下是一些常见的 POSIX 技巧，可能用于环形缓冲区的实现或优化：  
1. 内存映射（Memory Mapping）：使用 mmap 系统调用将文件或匿名内存映射到进程的地址空间。在环形缓冲区中，可以使用 mmap 将一块内存映射为虚拟的环形空间，从而避免手动管理缓冲区的循环逻辑。例如，映射一块两倍于实际需要的内存空间，并在逻辑上将其视为环形缓冲区。好处是简化了环形缓冲区的实现。提高了性能，因为内存映射可以直接操作内存，而不需要通过系统调用读写数据。  
2. 共享内存（Shared Memory）：使用 POSIX 共享内存（shm_open 和 mmap）在多个进程之间共享环形缓冲区。在生产者-消费者模型中，多个进程可以通过共享内存访问同一个环形缓冲区。好处是避免了进程间通信（IPC）的开销。提高了数据交换的效率。
