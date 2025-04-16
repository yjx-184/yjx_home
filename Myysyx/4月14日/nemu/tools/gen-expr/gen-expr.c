/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

//定义最大缓冲区大小
#define MAX_BUF_SIZE 65536

// this should be enough 这应该足够了
static char buf[65536] = {};            //用于存储生成的随机表达式
static char code_buf[65536 + 128] = {}; //存储生成的C代码

//代码模板，用于生成C程序
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  int result = %s; "         //这里会插入生成的表达式
"  printf(\"%%d\", result); " //输出表达式的结果
"  return 0; "
"}";


//函数声明
static uint32_t choose(uint32_t n);
static void check_buf_remainder(char *buffer, const char *append_str);
static void gen(char c);
static void rand_space();
static void gen_num();
static char gen_rand_op();
static void gen_rand_expr();

//随机选择
static uint32_t choose(uint32_t n) {
  return rand() % n;
}

//在生成的同时进行检查，防止缓冲区溢出
static void check_buf_remainder(char *buffer, const char *append_str ) {
  //检查当前缓冲区剩余空间是否足够追加新内容
  if (strlen(buffer) + strlen(append_str) <= MAX_BUF_SIZE ) {
    strcat(buffer, append_str);             //如果足够，追加内容
  } else {
    printf("Preventing buffer overflows!"); //否则提示防止缓冲区溢出
    exit(1);
  }
}

//生成一个字符并追加到 buf，用于添加括号和空格
static void gen(char c) {       
  int len = strlen(buf);              //获取当前缓冲区长度
  char tmp[2] = {c, '\0'};            //转换为字符串
  check_buf_remainder(buf, tmp);      //检查剩余缓冲区
  buf[len] = c;                       //在缓冲区末尾追加字符
  buf[len + 1] = '\0';                //添加字符串结束符
}

//随机生成空格
static void rand_space() {
  if (choose(2) == 0) {               //50%概率生成一个空格
    gen(' ');
  }
}

//生成数字并追加到buf
static void gen_num() {
  int32_t num = rand() % 10;          //生成一个随机数
  while (num == 0) {                  //如果生成了0,重新生成一个数字
    num = rand() % 10;           
  }
  char num_str[10];                   //用于存储数字的字符串
  sprintf(num_str, "%u", num);        //将数字转为字符串
  rand_space();                       //在数字后随机添加空格
  strcat(buf, num_str);               //将数字字符串追加到缓冲区
  check_buf_remainder(buf,num_str);   //检查缓冲区是否溢出
}

//生成运算符并追加到 buf
static char gen_rand_op() {           
  char ops[] = {'+', '-', '*', '/'};  //运算符数组
  char op = ops[choose(4)];           //随机选择一个运算符
  char op_str[2] = {op, '\0'};        //转换为字符串
  check_buf_remainder(buf, op_str);   //检查缓冲区是否溢出
  return op;
}

//生成一个随机表达式，并存储在缓冲区中
static void gen_rand_expr() {
  if (strlen(buf) > MAX_BUF_SIZE - 100) {
    return;  // 如果剩余空间不足以继续生成，停止生成
  }

  switch (choose(3)) {
    case 0: gen_num(); break;         //随机生成一个数字
    case 1: check_buf_remainder(buf, "("); gen('('); 
            gen_rand_expr(); 
            check_buf_remainder(buf, ")"); gen(')'); break; //生成带括号的表达式
    default: 
            gen_rand_expr();
            char op = gen_rand_op();
            if (op == '/') {
              gen_num();              //右边强制生成非零数字
            } 
            else {
              gen_rand_expr();
            }
            break;  //生成运算符连接的子表达式
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);                       //使用当前的时间作为随机种子
  srand(seed);                              //初始化随机数生成器
  int loop = 1;                             //默认循环次数为1
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);           //从命令行中读取循环次数
  }
  int i;
  for (i = 0; i < loop; i ++) {
    buf[0] = '\0';                          //只在初始使用时清空缓冲区
    gen_rand_expr();                        //生成随机表达式

    //检查buf中表达式是否合法
    if (strstr(buf, "/0") != NULL ||        //检查是否出现除0行为
        strstr(buf, ";")  != NULL ||        //检查是否出现分号
        buf[strlen(buf) - 1] == ')') {      //检查最后一位是不是')'
      i--;                                  //重新生成表达式
      continue;                             //跳过本次循环
    }
    sprintf(code_buf, code_format, buf);    //将生成的表达式插入代码模板中

    FILE *fp = fopen("/tmp/.code.c", "w");  //将生成的C代码写入临时文件
    assert(fp != NULL);                     //断言，确保文件打开成功
    fputs(code_buf, fp);                    //写入代码
    fclose(fp);

    // 如果出现除0,就会导致错误。
    int ret = system("gcc /tmp/.code.c -o /tmp/.expr"); //编译成功system接收到返回0的，编译失败接收到非0值
    if (ret != 0) continue;                 //如果编译失败，跳过本次循环

    fp = popen("/tmp/.expr", "r");          //执行编译后的程序
    assert(fp != NULL);                     //断言，确保执行成功

    int result;                             //读取程序的输出结果
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    if (result == 0) {
      i--;
      continue;
    }

    printf("%d %s\n", result, buf);
  }
  return 0;
}
