- [前言](#前言)



# 前言 
You may already be versed in debugging Bash scripts (see How to Debug Bash Scripts if you are not familiar with debugging Bash yet), yet how to debug C or C++? Let’s explore.  

GDB is a long-standing and comprehensive Linux debugging utility, which would take many years to learn if you wanted to know the tool well. However, even for beginners, the tool can be very powerful and useful when it comes to debugging C or C++.  

For example, if you’re a QA engineer and would like to debug a C program and binary your team is working on and it crashes, you can use GDB to obtain a backtrace (a stack list of functions called – like a tree – which eventually led to the crash). Or, if you are a C or C++ developer and you just introduced a bug into your code, then you can use GDB to debug variables, code and more! Let’s dive in!  

你可能已经熟悉如何调试Bash脚本（如果你还不熟悉Bash脚本调试，可以参考《如何调试Bash脚本》），但如何调试C或C++呢？让我们来探讨一下。  

GDB是一个历史悠久且功能全面的Linux调试工具，如果你想深入了解这个工具，可能需要花费多年时间。然而，即使对于初学者来说，GDB在调试C或C++时也非常强大且实用。  

例如，如果你是一名QA工程师，想要调试团队正在开发的C程序和二进制文件，并且程序崩溃了，你可以使用GDB获取回溯信息（即函数调用的堆栈列表，类似于树状结构，最终导致崩溃）。或者，如果你是一名C或C++开发人员，刚刚在代码中引入了一个bug，那么你可以使用GDB来调试变量、代码等！让我们开始吧！  

***
***
**In this tutorial you will learn:**  
*How to install and use the GDB utility from the command line in Bash  
*How to do basic GDB debugging using the GDB console and prompt  
*Learn more about the detailed output GDB produces  

**在本教程中，您将学习：**  
如何在Bash命令行中安装和使用GDB工具。  
如何使用GDB控制台和提示符进行基本的GDB调试。  
深入了解GDB生成的详细输出信息。  

***
***
# 软件需求与使用的约定
| **Category** | **Details**                                                                                      |
|--------------|--------------------------------------------------------------------------------------------------|
| **System**   | Linux Distribution-independent                                                                   |
| **Software** | Bash and GDB command lines, Linux-based system                                                   |
| **Other**    | The GDB utility can be installed using the commands provided below                               |
| **Conventions** | `#` – requires linux-commands to be executed with root privileges either directly as a root user or by use of `sudo` command <br> `$` – requires linux-commands to be executed as a regular non-privileged user |  

| **类别**   | **需求、约定或软件版本**                                                                                         |
|------------|---------------------------------------------------------------------------------------------------------------|
| **系统**   | 与Linux发行版无关                                                                                              |
| **软件**   | Bash和GDB命令行，基于Linux的系统                                                                                |
| **其他**   | GDB工具可以使用下面提供的命令安装                                                                              |
| **约定**   | `#` – 需要以root权限执行Linux命令，可以直接作为root用户或使用`sudo`命令 <br> `$` – 需要以普通非特权用户身份执行Linux命令 |


# 设置GDB和测试程序
For this article, we will look at a small test.c program in the C development language, which introduces a division-by-zero error in the code. The code is a bit longer then what is needed in real life (a few lines would do, and no function use would be required), but this was done on purpose to highlight how function names can be seen clearly inside GDB when debugging.  
在本文中，我们将使用C语言编写的一个小型测试程序 test.c，该程序在代码中引入了一个除以零的错误。代码比实际需要的稍长一些（实际上几行代码就足够了，也不需要函数调用），但这是为了突出在GDB调试时如何清晰地查看函数名称。  

Let’s first install the tools we will require using sudo apt install (or sudo yum install if you use a Red Hat based distribution):  
首先，我们使用 sudo apt install（如果您使用的是基于Red Hat的发行版，可以使用 sudo yum install）安装所需的工具：  
```
sudo apt install gdb build-essential gcc
```  

The build-essential and gcc are going to help you compile the test.c C program on your system.  
build-essential 和 gcc 将帮助您在系统上编译 test.c 程序。  

Next, let us define the test.c script as follows (you can copy and paste the following into your favorite editor and save the file as test.c):  
接下来，我们定义 test.c 脚本如下（您可以将其复制并粘贴到您喜欢的编辑器中，并将文件保存为 test.c）： 
```
int actual_calc(int a, int b){
  int c;
  c=a/b;
  return 0;
}

int calc(){
  int a;
  int b;
  a=13;
  b=0;
  actual_calc(a, b);
  return 0;
}

int main(){
  calc();
  return 0;
}
```  
A few notes about this script: You can see that when the main function will be started (the main function is the always the main and first function called when you start the compiled binary, this is part of the C standard), it immediately calls the function calc, which in turn calls atual_calc after setting a few variables a and b to 13 and 0 respectively.  
关于此脚本的一些说明：您可以看到，当 main 函数启动时（main 函数始终是启动编译后的二进制文件时首先调用的主函数，这是C标准的一部分），它会立即调用 calc 函数，而 calc 函数在将变量 a 和 b 分别设置为 13 和 0 后，会调用 actual_calc 函数。  


# 执行脚本并配置核心转储
Let us now compile this script using gcc and execute the same:  
现在，让我们使用 gcc 编译这个脚本并执行它：  
```
$ gcc -ggdb test.c -o test.out
$ ./test.out
Floating point exception (core dumped)
```  
The -ggdb option to gcc will ensure that our debugging session using GDB will be a friendly one; it adds GDB specific debugging information to the test.out binary. We name this output binary file using the -o option to gcc, and as input we have our script test.c.  
gcc 的 -ggdb 选项将确保我们使用 GDB 进行调试时会更加友好；它会向 test.out 二进制文件中添加 GDB 特定的调试信息。我们使用 gcc 的 -o 选项命名输出二进制文件，并将 test.c 脚本作为输入。  

When we execute the script we immediately get a cryptic message Floating point exception (core dumped). The part we are interested for the moment is the core dumped message. If you do not see this message (or if you do see the message but cannot locate the core file), you can setup better core dumping as follows:  
当我们执行脚本时，立即会收到一条神秘的消息 Floating point exception (core dumped)。目前我们感兴趣的部分是 core dumped 消息。如果您没有看到此消息（或者看到了消息但找不到核心文件），可以按如下方式设置更好的核心转储：  
```
if ! grep -qi 'kernel.core_pattern' /etc/sysctl.conf; then
  sudo sh -c 'echo "kernel.core_pattern=core.%p.%u.%s.%e.%t" >> /etc/sysctl.conf'
  sudo sysctl -p
fi
ulimit -c unlimited
```  
Here we are first making sure there is no Linux Kernel core pattern (kernel.core_pattern) setting made yet in /etc/sysctl.conf (the configuration file for setting system variables on Ubuntu and other operating systems), and – provided no existing core pattern was found – add a handy core file name pattern (core.%p.%u.%s.%e.%t) to the same file.  
在这里，我们首先确保 /etc/sysctl.conf（Ubuntu 和其他操作系统中用于设置系统变量的配置文件）中尚未设置 Linux 内核核心模式（kernel.core_pattern），如果未找到现有的核心模式，则向该文件添加一个方便的核心文件名模式（core.%p.%u.%s.%e.%t）。  

The sysctl -p command (to be executed as root, hence the sudo) next ensures the file is immediately reloaded without requiring a reboot. For more information on the core pattern, you can see the Naming of core dump files section which can be accessed by using the man core command.  
接下来，sysctl -p 命令（需要以 root 权限执行，因此使用 sudo）确保文件立即重新加载，而无需重启。有关核心模式的更多信息，您可以通过 man core 命令访问“核心转储文件命名”部分。  

Finally, the ulimit -c unlimited command simply sets the core file size maximum to unlimited for this session. This setting is not persistent across restarts. To make it permanent, you can do:  
最后，ulimit -c unlimited 命令仅为此会话将核心文件大小最大值设置为无限制。此设置在重启后不会持久化。要使其永久生效，您可以执行以下操作：  
```
sudo bash -c "cat << EOF > /etc/security/limits.conf
* soft core unlimited
* hard core unlimited
EOF
```  
Which will add * soft core unlimited and * hard core unlimited to /etc/security/limits.conf, ensuring there are no limits for core dumps.  
这将在 /etc/security/limits.conf 中添加 * soft core unlimited 和 * hard core unlimited，确保核心转储没有限制。  

When you now re-execute the test.out file you should see the core dumped message and you should be able to see a core file (with the specified core pattern), as follows:  
现在，当您重新执行 test.out 文件时，您应该会看到 core dumped 消息，并且能够看到一个核心文件（具有指定的核心模式），如下所示：  
```
$ ls
core.1341870.1000.8.test.out.1598867712  test.c  test.out
```  

Let’s next examine the metadata of the core file:  
接下来，我们检查核心文件的元数据：  
```
$ file core.1341870.1000.8.test.out.1598867712
core.1341870.1000.8.test.out.1598867712: ELF 64-bit LSB core file, x86-64, version 1 (SYSV), SVR4-style, from './test.out', real uid: 1000, effective uid: 1000, real gid: 1000, effective gid: 1000, execfn: './test.out', platform: 'x86_64'
```  
We can see that this is a 64-Bit core file, which user ID was in use, what the platform was, and finally what executable was used. We can also see from the filename (.8.) that it was a signal 8 which terminated the program. Signal 8 is SIGFPE, a Floating point exception. GDB will later show us that this is a arithmetic exception.  
我们可以看到这是一个 64 位核心文件，显示了使用的用户 ID、平台信息以及使用的可执行文件。我们还可以从文件名（.8.）中看到，是信号 8 终止了程序。信号 8 是 SIGFPE，即浮点异常。稍后 GDB 将向我们显示这是一个算术异常。  

# 使用 GDB 分析核心转储
Let’s open the core file with GDB and assume for a second we do not know what happened (if you’re a seasoned developer, you may have already seen the actual bug in the source!):  
让我们使用 GDB 打开核心文件，并假设暂时不知道发生了什么（如果你是经验丰富的开发者，可能已经在源代码中看到了实际的 bug！）：  
```
$ gdb ./test.out ./core.1341870.1000.8.test.out.1598867712
GNU gdb (Ubuntu 9.1-0ubuntu1) 9.1
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./test.out...
[New LWP 1341870]

Core was generated by `./test.out'.
Program terminated with signal SIGFPE, Arithmetic exception.

#0  0x000056468844813b in actual_calc (a=13, b=0) at test.c:3
3     c=a/b;
(gdb)
```  
As you can see, on the first line we called gdb with as first option our binary and as second option the core file. Simply remember binary and core. Next we see GDB initialize, and we are presented with some information.  
如你所见，在第一行，我们用 gdb 调用了二进制文件和核心文件，二进制文件作为第一个选项，核心文件作为第二个选项。只需记住二进制文件和核心文件。接着，我们看到 GDB 初始化，并展示了一些信息。  

If you see a warning: Unexpected size of section.reg-xstate/1341870’ in core file.` or similar message, you may ignore it for the time being.  
如果你看到警告：“核心文件中意外的 section.reg-xstate/1341870 大小”或类似信息，可以暂时忽略它。  

We see that the core dump was generated by test.out and were are told that the signal was an SIGFPE, arithmetic exception. Great; we already know something is amiss with our mathematics, and perhaps not with our code!  
我们看到核心转储是由 test.out 生成的，并且我们被告知信号是 SIGFPE，即算术异常。很好；我们已经知道问题出在我们的数学计算上，可能和代码本身无关！  

Next we see the frame (please think about a frame like a procedure in code for the time being) on which the program terminated: frame #0. GDB adds all sorts of handy information to this: the memory address, the procedure name actual_calc, what our variable values were, and even at one line (3) of which file (test.c) the issue happened.  
接下来，我们看到程序终止时的帧（请暂时将帧理解为代码中的一个过程）：帧 #0。GDB 为此添加了各种有用的信息：内存地址、过程名称 actual_calc、变量值，甚至在文件 test.c 中的第 3 行出现了问题。  

Next we see the line of code (line 3) again, this time with the actual code (c=a/b;) from that line included. Finally we are presented with a GDB prompt.  
然后，我们再次看到代码行（第 3 行），这次包含了该行的实际代码（c=a/b;）。最后，我们看到 GDB 提示符。

The issue is likely very clear by now; we did c=a/b, or with variables filled in c=13/0. But human cannot divide by zero, and a computer can’t therefore either. As no-one told a computer how to divide by zero, an exception occurred, an arithmetic exception, a floating point exception / error.  
问题可能现在已经非常清楚了；我们做了 c=a/b，或者用变量填充就是 c=13/0。但人类不能除以零，计算机也不能。因此，由于没有告诉计算机如何处理除以零，发生了异常，即算术异常，浮点异常 / 错误。  

# 回溯
So let’s see what else we can discover about GDB. Let’s look at a few basic commands. The fist one is the one you are most likely to use most often: bt:  
那么让我们看看还能发现关于 GDB 的哪些内容。让我们来看一些基本命令。第一个命令是你最可能最常用的命令：bt：  
```
(gdb) bt
#0  0x000056468844813b in actual_calc (a=13, b=0) at test.c:3
#1  0x0000564688448171 in calc () at test.c:12
#2  0x000056468844818a in main () at test.c:17
```  
This command is a shorthand for backtrace and basically gives us a trace of the current state (procedure after procedure called) of the program. Think about it like a reverse order of things that happened; frame #0 (the first frame) is the last function which was being executed by the program when it crashed, and frame #2 was the very first frame called when the program was started.  
这个命令是 backtrace 的简写，基本上给我们提供了程序当前状态的回溯（按调用的过程逐步显示）。可以把它想象成发生的事情的逆序；帧 #0（第一个帧）是程序崩溃时正在执行的最后一个函数，而帧 #2 是程序启动时第一个被调用的帧。

We can thus analyze what happened: the program started, and main() was automatically called. Next, main() called calc() (and we can confirm this in the source code above), and finally calc() called actual_calc and there things went wrong.  
因此，我们可以分析发生了什么：程序启动后，main() 被自动调用。接着，main() 调用了 calc()（我们可以在上面的源代码中确认这一点），最后 calc() 调用了 actual_calc，然后问题发生了。

Nicely, we can see each line at which something happened. For example, the actual_calc() function was called from line 12 in test.c. Note that it is not calc() which was called from line 12 but rather actual_calc() which makes sense; test.c ended up executing to line 12 as far as the calc() function is concerned, as this is where the calc() function called actual_calc().  
很高兴的是，我们可以看到每一行发生了什么。例如，actual_calc() 函数是从 test.c 的第 12 行调用的。请注意，调用的是 actual_calc() 而不是 calc()，这很有道理；就 calc() 函数而言，test.c 执行到了第 12 行，因为这是 calc() 调用 actual_calc() 的地方。

Power user tip: if you use multiple threads, you can use the command thread apply all bt to obtain a backtrace for all threads which were running as the program crashed!  
高级用户提示：如果你使用多个线程，可以使用命令 thread apply all bt 来获取程序崩溃时所有线程的回溯.  

# 帧检查
If we want, we can inspect each frame, the matching source code (if it is available), and each variable step by step:  
如果我们愿意，我们可以逐步检查每一帧、匹配的源代码（如果可用），以及每个变量：  
```
(gdb) f 2
#2  0x000055fa2323318a in main () at test.c:17
17    calc();
(gdb) list
12    actual_calc(a, b);
13    return 0;
14  }
15  
16  int main(){
17    calc();
18    return 0;
19  }
(gdb) p a
No symbol "a" in current context.
```  

Here we ‘jump into’ frame 2 by using the f 2 command. f is a short hand for the frame command. Next we list the source code by using the list command, and finally try to print (using the p shorthand command) the value of the a variable, which fails, as at this point a was not defined yet at this point in the code; note we are working at line 17 in the function main(), and the actual context it existed in within the bounds of this function/frame.  
这里我们通过使用 f 2 命令“跳入”帧 2。f 是 frame 命令的简写。接着，我们使用 list 命令列出源代码，最后尝试打印（使用 p 命令简写）变量 a 的值，但失败了，因为此时变量 a 在代码中还没有定义；注意，我们正处于 main() 函数的第 17 行，并且变量 a 存在的实际上下文是在该函数/帧的范围内。  

Note that the source code display function, including some of the source code displayed in the previous outputs above, is only available if the actual source code is available.  
请注意，源代码显示功能（包括上面输出中显示的部分源代码）仅在实际源代码可用时才会出现。  

Here we immediately also see a gotcha; if the source code is different then the code which the binary was compiled from, one can be easily misled; the output may show non-applicable / changed source. GDB does not check if there is a source code revision match! It is thus of paramount importance that you use the exact same source code revision as the one from which your binary was compiled.  
这里我们立即看到一个陷阱；如果源代码与编译二进制文件时使用的源代码不同，可能会导致误导；输出可能显示不适用或已更改的源代码。GDB 不会检查源代码版本是否匹配！因此，使用与编译二进制文件时完全相同的源代码版本至关重要。  

An alternative is to not use the source code at all, and simply debug a particular situation in a particular function, using a newer revision of the source code. This often happens for advanced developers and debuggers who likely do not need too many clues about where the issue may be in a given function and with provided variable values.  
另一种选择是完全不使用源代码，而是仅调试特定函数中的特定情况，使用更新版本的源代码。这通常发生在高级开发者和调试人员身上，他们可能不需要太多关于给定函数中问题所在和提供的变量值的线索。  

Let’s next examine frame 1:  
接下来，让我们检查帧 1：  
```
(gdb) f 1
#1  0x000055fa23233171 in calc () at test.c:12
12    actual_calc(a, b);
(gdb) list
7   int calc(){
8     int a;
9     int b;
10    a=13;
11    b=0;
12    actual_calc(a, b);
13    return 0;
14  }
15  
16  int main(){
```  
Here we can again see plenty of information being output by GDB which will aid the developer in debugging the issue at hand. Since we are now in calc (on line 12), and we have already initialized and subsequently set the variables a and b to 13 and 0 respectively, we can now print their values:  
在这里，我们再次可以看到 GDB 输出了大量信息，这些信息将帮助开发者调试当前的问题。由于我们现在位于 calc 函数（第 12 行），并且已经初始化并分别将变量 a 和 b 设置为 13 和 0，我们现在可以打印它们的值：  
```
(gdb) p a
$1 = 13
(gdb) p b
$2 = 0
(gdb) p c
No symbol "c" in current context.
(gdb) p a/b
Division by zero
```  

Note that when we try and print the value of c, it still fails as again c is not defined up to this point (developers may speak about ‘in this context’) yet.  
请注意，当我们尝试打印变量 c 的值时，仍然会失败，因为到此时 c 仍未定义（开发者可能会说“在这个上下文中”）.  

Finally, we look into frame #0, our crashing frame:  
最后，我们查看帧 #0，即崩溃帧：  
```
(gdb) f 0
#0  0x000055fa2323313b in actual_calc (a=13, b=0) at test.c:3
3     c=a/b;
(gdb) p a
$3 = 13
(gdb) p b
$4 = 0
(gdb) p c
$5 = 22010
```  
All self evident, except for the value reported for c. Note that we had defined the variable c, but had not given it an initial value yet. As such c is really undefined (and it was not filled by the equation c=a/b yet as that one failed) and the resulting value was likely read from some address space to which the variable c was assigned (and that memory space was not initialized/cleared yet).  
一切都显而易见，除了报告的 c 的值。请注意，我们确实定义了变量 c，但还没有给它初始值。因此，c 实际上是未定义的（而且它尚未通过 c=a/b 进行赋值，因为那一步失败了），最终的值很可能是从分配给变量 c 的某个地址空间读取的（而该内存空间还没有初始化/清除）。  

# 结论
Conclusion
Great. We were able to debug a core dump for a C program, and we leaned the basics of GDB debugging in the meantime. If you are a QA engineer, or a junior developer, and you have understood and learned everything in this tutorial well, you are already quite a bit ahead of most QA engineers, and potentially other developers around you.  
太好了。我们成功地调试了一个 C 程序的核心转储，并在此过程中学习了 GDB 调试的基础知识。如果你是 QA 工程师，或者是初级开发者，并且已经很好地理解并掌握了本教程中的所有内容，那么你已经领先于大多数 QA 工程师，甚至可能比你周围的其他开发者更有优势。

# 常用命令总结
1. 基本操作
gdb <program> ：启动 GDB 并加载程序
run (r) ：运行程序
quit (q) ：退出 GDB
help (h) ：查看帮助
2. 断点管理
break <行号> (b <行号>) ：在指定行号设置断点
break <函数名> (b <函数名>) ：在函数入口设置断点
info breakpoints (i b) ：查看所有断点
delete <编号> (d <编号>) ：删除指定编号的断点
enable <编号> / disable <编号> ：启用/禁用断点
clear <行号> ：清除指定行的断点
3. 运行控制
next (n) ：执行下一行（不进入函数）
step (s) ：单步执行（进入函数）
continue (c) ：继续运行直到下一个断点
finish ：运行直到当前函数返回
until <行号> ：运行到指定行号
return ：提前返回当前函数
4. 查看信息
backtrace (bt) ：查看调用栈
frame <编号> ：切换到指定栈帧
info locals ：查看当前函数的局部变量
info registers (i r) ：查看寄存器值
info threads (i th) ：查看线程信息
5. 变量与表达式
print <变量> (p <变量>) ：打印变量值
print/x <变量> ：以十六进制格式打印
display <变量> ：每次单步执行时自动显示变量值
set var <变量>=<值> ：修改变量值
watch <变量> ：监视变量，变量值变化时暂停程序
6. 内存查看
x/<格式> <地址> ：查看内存
x/10xw $sp ：查看栈指针附近 10 个 4 字节的值（十六进制）
x/5i $pc ：查看当前指令
x/s <地址> ：查看字符串
7. 调试共享库
info sharedlibrary (i sh) ：查看加载的共享库
break <库文件>:<函数> ：在共享库中的函数设置断点
set environment <变量>=<值> ：设置环境变量
8. GDB 进阶
attach <PID> ：附加到正在运行的进程
detach ：分离调试的进程
core <core 文件> ：加载 core dump 进行调试
thread <编号> ：切换到指定线程
set follow-fork-mode <mode> ：调试 fork 子进程
parent ：跟踪父进程
child ：跟踪子进程