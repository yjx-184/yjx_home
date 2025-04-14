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

#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>

#include <memory/vaddr.h>   //因出现隐式声明的错误，故在此添加该头文件（实现cmd_x时添加）

// 定义监视点结构体
typedef struct watchpoint {
  int NO;                     // 监视点编号
  char *expr;                 // 表达式字符串
  word_t value;               // 表达式当前值
  struct watchpoint *next;    // 指向下一个监视点的指针
} WP;

WP* get_head();
word_t expr(char *e, bool *success);
WP* new_wp();
void free_wp();
void check_wp();
#endif
