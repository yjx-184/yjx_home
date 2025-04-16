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

#include <utils.h>

NEMUState nemu_state = { .state = NEMU_STOP };  //定义NEMU全局状态变量，并初始化NEMU_STOP

int is_exit_status_bad() {  //判断状态是否异常，以下是正常退出
  int good = (nemu_state.state == NEMU_END && nemu_state.halt_ret == 0) ||  //1.程序正常结束
    (nemu_state.state == NEMU_QUIT);  //2.手动结束
  return !good; //正常状态返回0,否则返回非零
}
