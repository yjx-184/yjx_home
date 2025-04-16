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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

extern word_t expr(char *e, bool *success);   //pa1_2测试用例需要继承expr()函数

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

//=================== pa1_2 测试用例---开始 ===================
  // /* 打开输入文件 input */
  // FILE *fp = fopen("tools/gen-expr/build/input", "r");
  // if (!fp) {
  //   printf("Failed to open input file.\n");
  //   return 1;                                            //文件打开失败
  // }

  // char line[65536];                                      //用于存储每一行的输入
  // char expr_buf[65536];                                  //用于存储表达式
  // word_t expected_result;                                //用于存储期望结果
  // bool success;                                          //存储expr()函数的执行状态

  // while (fgets(line, sizeof(line), fp)) {                //逐行输入文件
  //   printf("从input读取的行:%s", line);                    //打印读取到的行

  //   //使用 sscanf 解析期望结果和表达式
  //   //%u：解析一个无符号整数（期望结果）
  //   //%1023[^\n]：解析剩余的部分作为表达式（直到行末）
  //   if (sscanf(line, "%u %1023[^\n]", &expected_result, expr_buf) == 2) {
  //     printf("输入到expr函数的表达式是:%s\n", expr_buf);    //打印输入到expr函数的表达式
  //     word_t computed_result = expr(expr_buf, &success);//调用expr函数计算值

  //     if (success) {                                    //检查计算结果
  //       if (computed_result == expected_result) {
  //         printf("其结果是：%d(与期望结果一致)\n", computed_result);
  //       } else {
  //         printf("其结果是：%d(与期望结果 %d 不一致)\n", computed_result, expected_result);
  //       }
  //     } else {
  //       printf("其结果是：无效表达式\n");
  //     }
  //   } else {
  //     printf("错误：输入行格式不正确\n");                   //如果解析出错打印错误信息
  //   }
  //   printf("\n");  // 分隔不同的测试用例
  // }
  // fclose(fp);  // 关闭文件
//=================== pa1_2 测试用例---结束 ===================

  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}
