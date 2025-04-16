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

#include "sdb.h"

#define NR_WP 32              //定义最大监视点数量

//定义监视点结构体
// typedef struct watchpoint {
//   int NO;                     //监视点编号
//   char *expr;                 //表达式字符串
//   word_t value;               //表达式当前值
//   struct watchpoint *next;    //指向下一个监视点的指针
  
//   /* TODO: Add more members if necessary 如果需要可以添加更多成员*/

// } WP;

static WP wp_pool[NR_WP] = {};          //定义监视点池数组，最大监视点数量为NR_WP
static WP *head = NULL, *free_ = NULL;  //head用于组织使用中的监视点结构的头指针, free_用于组织空闲的监视点结构的头指针

//获取head的函数
WP* get_head() {
  return head;
}

void init_wp_pool() {                   //初始化监视点池
  int i;
  for (i = 0; i < NR_WP; i ++) {        //初始化监视点池
    wp_pool[i].NO = i;                  //设置监视点编号
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);  //设置下一个监视点指针，最后一个监视点的next指针为NULL
  }

  head = NULL;                          //头指针初始化为NULL，表示当前没有使用中的监视点
  free_ = wp_pool;                      //空闲链表指向监视点池的第一个元素，表示所有监视点初始时都是空闲的
}

/* TODO: Implement the functionality of watchpoint 实现监视点功能 */

//从free_链表中返回一个空闲的监视点结构
WP* new_wp() {
  if (free_ == NULL) {
    assert(0);                          //如果没有空闲监视点，终止程序
  }

  WP *newwp = free_;                    //从空闲链表中提取一个监视点
  free_ = free_->next;                  //把头指针指向下一个 从空闲链表中去掉刚刚提取的

  newwp->next = head;                   //让newwp的next指向使用中链表的头部
  head = newwp;                         //更新使用中链表的头节点为newwp

  newwp->NO = head == NULL ? 0 : head->NO + 1; //设置监视点编号，编号递增

  return newwp;
}

//将wp归还到free_链表中
void free_wp(WP *wp) {
  if (wp == NULL) {                     //如果wp为空，直接返回
    return;
  }

  //从使用中链表移除wp
  if (head == wp) {                     //如果wp是激活链表的头节点
    head = head->next;                  //将激活链表头指针更新为下一个
  } else {
    //遍历整个激活列表查找wp的上一个节点
    WP *prev = head;
    while (prev != NULL && prev->next != wp) {
      prev = prev->next;                //没找到就继续下一个
    }

    if (prev != NULL) {                 //找到了wp前一个节点且不为空
      prev->next = wp->next;            //将prev的next指针指向wp的next，wp从激活链表中移除
    }
  }

  //把wp插入空闲链表的头部
  wp->next = free_;                     //wp的next指针指向空闲链表的头节点
  free_ = wp;                           //空闲链表的头指针指向wp
}

//检查监视点
void check_wp() {
    WP *current = head;                 //从监视点链表头部开始遍历
    bool triggered = false;             //标记是否有触发的监视点
    bool error_occurred = false;        //标记是否发生表达式求值错误

    //遍历所有已经设置的监视点
    while (current != NULL) {
        //检查表达式指针是否为空
        if (current->expr == NULL) {
          printf("Watchpoint %d has a NULL expression pointer.\n", current->NO);
          error_occurred = true;
          current = current->next;
          continue;
        }

        bool success;                   //标记是否求值成功
        word_t new_val = expr(current->expr, &success); //计算监视点当前值
        if (!success) {                                 // 如果发生表达式求值错误
            printf("Error evaluating expression '%s' for watchpoint %d.\n", current->expr, current->NO);
            error_occurred = true;
        } else {
            if (new_val != current->value) {            //如果监视点的值发生变化
                if (!triggered) {                       //如果这是第一个触发的监视点，打印错误信息
                    printf("Triggered watchpoints:\n"); //避免重复打印这一行
                    triggered = true;
                }
                printf("Watchpoint %d: %s\n", current->NO, current->expr);
                printf("Old value: %u (0x%x)\n", current->value, current->value);
                printf("New value: %u (0x%x)\n", new_val, new_val);
                current->value = new_val;               //更新监视点的值
            }
        }
        current = current->next;                        //移动到下一个监视点
    }

    //如果有任何监视点触发或表达式求值出错，暂停NEMU运行
    if (error_occurred || triggered) {
        nemu_state.state = NEMU_STOP;
    }
}