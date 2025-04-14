#ifndef __SDB_H__
#define __SDB_H__
#include "isa.h"

// 定义监视点结构体
typedef struct watchpoint {
  int NO;                     // 监视点编号
  char *expr;                 // 表达式字符串
  uint32_t value;               // 表达式当前值
  struct watchpoint *next;    // 指向下一个监视点的指针
} WP;

WP* get_head();
uint32_t expr(char *e, bool *success);
WP* new_wp();
void free_wp(WP *wp);
void check_wp();

#endif