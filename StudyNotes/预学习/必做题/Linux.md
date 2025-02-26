- [](#)


# Linux系统的安装和基本使用习题
## 基本使用习题
### 课程概览与shell
```
$ echo $SHELL
/bin/bash
$ mkdir missing

$ cd missing
yjx@yjx-Lenovo-Legion-R7000-2020:~/Mystudy/yjx_learn/Learn_Linux/课程概览与shell
/missing$ man touch
$ touch semester
yjx@yjx-Lenovo-Legion-R7000-2020:~/Mystudy/yjx_learn/Learn_Linux/课程概览与shell
/missing$ echo '#!/bin/sh' > semester
$ echo curl --head -- silent https://missing.csail.mit.edu
curl --head -- silent https://missing.csail.mit.edu
$ echo curl --head -- silent https://missing.csail.mit.edu > semester
$ ./semester
bash: ./semester: Permission denied
yjx@yjx-Lenovo-Legion-R7000-2020:~/Mystudy/yjx_learn/Learn_Linux/课程概览与shell
/missing$ ls
semester
$ ls -l
total 4
-rw-rw-r-- 1 yjx yjx 52  2月 24 15:12 semester
$ chmod 777 semester
$ ./semester
HTTP/1.1 200 OK
Content-Length: 1026
Accept-Ch: sec-ch-prefers-color-scheme
Cache-Control: no-store, max-age=0
Connection: keep-alive
Content-Type: text/html; charset=utf-8
Critical-Ch: sec-ch-prefers-color-scheme
Date: Mon, 24 Feb 2025 07:14:22 GMT
Keep-Alive: timeout=4
Proxy-Connection: keep-alive
Set-Cookie: parking_session=32110311-8dce-497b-b768-7a3c47c8d9c6; expires=Mon, 24 Feb 2025 07:29:23 GMT; path=/
Vary: sec-ch-prefers-color-scheme
X-Adblock-Key: MFwwDQYJKoZIhvcNAQEBBQADSwAwSAJBANDrp2lz7AOmADaN8tA50LsWcjLFyQFcb/P2Txc58oYOeILb3vBw7J6f4pamkAQVSQuqYsKx3YzdUHCvbVZvFUsCAwEAAQ==_rbwAx3tAQSN/xhOL0noQQM6korNubXk5brapsETUknOvhCy7bCqghUaRSzmvXf1KYrW8XVfPVVt+2Gd7/oUnJw==
X-Request-Id: 32110311-8dce-497b-b768-7a3c47c8d9c6

HTTP/1.1 200 Connection established

HTTP/2 200 
server: GitHub.com
content-type: text/html; charset=utf-8
last-modified: Sat, 01 Feb 2025 18:13:13 GMT
access-control-allow-origin: *
etag: "679e6439-205d"
expires: Mon, 24 Feb 2025 03:38:56 GMT
cache-control: max-age=600
x-proxy-cache: MISS
x-github-request-id: E2C4:293227:592074:5DF10A:67BBE777
accept-ranges: bytes
age: 0
date: Mon, 24 Feb 2025 07:14:24 GMT
via: 1.1 varnish
x-served-by: cache-nrt-rjtf7700049-NRT
x-cache: HIT
x-cache-hits: 0
x-timer: S1740381264.480273,VS0,VE226
vary: Accept-Encoding
x-fastly-request-id: 15bcadbe03566da4a21547886787d39257bc71d2
content-length: 8285

$ ./semester | grep last-modified > ../last-modified.txt
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0  1026    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0  8285    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0

$ cat /sys/class/power_supply/BAT0/capacity
100

```  
### bash一些常用知识
#### 1.脚本基础 
脚本文件：1.文件名通常为``` .sh ``` 2.第一行指定解释器： ``` #!/bin/bash ``` 3.赋予执行权限： ``` chmod +x xxx.sh ``` 4.运行脚本： ``` ./xxx.sh ``` 或 ``` bash xxx.sh ``` 注释使用#，  多行注释：使用 : ``` <<EOF ... EOF 或 <<COMMENT ... COMMENT。```

#### 2.变量
定义变量：  
变量名=值（等号两边不能有空格）：name="John"。  
使用变量：$name 或 ${name}。  

特殊变量：  
$0：脚本名称。  
$1, $2, ...：脚本参数。  
$#：参数个数。  
$?：上一条命令的退出状态（0 表示成功，非 0 表示失败）。  
$* 和 $@：所有参数。  

环境变量：  
查看环境变量：env 或 printenv。  
设置环境变量：export VAR=value。  

#### 3.字符串操作
定义字符串：  
单引号：原样输出，不解析变量：str='Hello, $name'。  
双引号：解析变量和转义字符：str="Hello, $name"。  

字符串操作：  
获取长度：${#str}。  
截取子串：${str:start:length}。  
替换：${str/old/new}（替换第一个匹配）或 ${str//old/new}（替换所有匹配）。  
删除前缀/后缀：${str#prefix} 或 ${str%suffix}。  

#### 4.数组
定义数组：  
array=("a" "b" "c")。  
访问元素：${array[0]}。  
访问所有元素：${array[@]} 或 ${array[*]}。  
数组长度：${#array[@]}。  

#### 5.条件判断
基本语法：  
```
if [ condition ]; then
    commands
elif [ condition ]; then
    commands
else
    commands
fi
```  
常用条件：  
字符串比较：=（相等），!=（不等），-z（为空），-n（非空）。  
数字比较：-eq（等于），-ne（不等于），-gt（大于），-lt（小于）。  
文件测试：-e（存在），-f（是文件），-d（是目录），-r（可读），-w（可写）。  

逻辑运算符：  
&&（与），||（或），!（非）。  

#### 6.循环
for循环：  
```
for var in list; do
    commands
done
```  

while循环:  
```
while [ condition ]; do
    commands
done
```  

until循环：  
```
until [ condition ]; do
    commands
done
```  

reak 和 continue：  
break：退出循环。  
continue：跳过本次循环。  

#### 7.函数
定义函数：  
```
function_name() {
    commands
}
```  

调用函数：  
```
function_name arg1 arg2
```  

#### 8. 输入输出
输出：  
echo "Hello"：打印文本。  
printf "Hello, %s\n" $name：格式化输出。  

输入：  
read var：从标准输入读取内容到变量。  
重定向：  
'>'：覆盖输出到文件。  
'>>'：追加输出到文件。  
<：从文件读取输入。  
2>：重定向错误输出。  
&>	将标准输出和标准错误输出都覆盖写入文件。  
&>>	将标准输出和标准错误输出都追加到文件。  


#### 9.命令执行
命令替换：
'`command`'或 $(command)：将命令的输出作为变量值。  
管道：  
command1 | command2：将 command1 的输出作为 command2 的输入。  
后台执行：  
command &：在后台运行命令。  

#### 10.调试与错误处理
调试：  
set -x：开启调试模式，打印执行的每一行命令。  
set +x：关闭调试模式。  

错误处理：  
set -e：脚本遇到错误时立即退出。  
trap "commands" ERR：捕获错误并执行指定命令。  

#### 11.常用工具
grep：文本搜索。  
sed：流编辑器，用于文本替换。  
awk：文本处理工具。  
cut：按列提取文本。  
sort：排序文本。  
uniq：去重。  

### Shell工具和脚本
$man ls  
我们在查阅后根据题目需求找到：  
```
-a, --all
显示所有文件，包括以 . 开头的隐藏文件。

-h, --human-readable
配合 -l 和 -s 选项，使用 1K 234M 2G 等易读格式显示文件大小。

-c
配合 -lt：按 ctime（状态信息最后修改时间）排序并显示。
配合 -l：显示 ctime 并按名称排序。
否则：按 ctime 排序，最新的文件优先。

--color[=WHEN]
颜色高亮输出，WHEN 可选 always（始终）、auto（自动）或 never（不使用）。
```  

结果：  
```
/missing$ ls -l -a -h -c --color
total 12K
drwxrwxr-x 2 yjx yjx 4.0K  2月 24 15:10 .
drwxrwxr-x 3 yjx yjx 4.0K  2月 24 15:16 ..
-rwxrwxrwx 1 yjx yjx   52  2月 24 15:14 semester
```  

3.假设您有一个命令，它很少出错。因此为了在出错时能够对其进行调试，需要花费大量的时间重现错误并捕获输出。 编写一段 bash 脚本，运行如下的脚本直到它出错，将它的标准输出和标准错误流记录到文件，并在最后输出所有内容。 加分项：报告脚本在失败前共运行了多少次。  
阅读代码：0到100随机数赋值给n，然后如果n不等于42,打印"Something went wrong"，然后重定向错误输出，结束程序。  
以下是答案，它设置了一个变量count初始化为0,调用echo输出重定向到out.log覆盖原有内容（实际上就是清空），当true时，将buggy.sh重定向输出到out.log，如果 上一个命令不等于0（没成功），则获取out.log然后输入"failed after $count times"，break出来，继续循环。

```

 #!/usr/bin/env bash
 count=0
 echo > out.log

 while true
 do
     ./buggy.sh &>> out.log
     if [[ $? -ne 0 ]]; then
         cat out.log
         echo "failed after $count times"
         break
     fi
     ((count++))
 done

```  

第4题：  
```find . -type f -name "*.html" -print0 | xargs -0 zip xxx.zip ```
在当前目录下递归查找所有后缀为.html的文件，使用-print0选项以null字符分割结果。使用xargs -0从标准输入中读取以null字符分割的文件列表，并作为参数传递给zip命令。  


