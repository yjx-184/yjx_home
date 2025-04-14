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

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <common.h>
#include <stdio.h>
#include <utils.h>

// 定义日志打印宏 Log，用于在调试时打印出当前文件名、行号和函数名，方便定位问题
#define Log(format, ...) \
    _Log(ANSI_FMT("[%s:%d %s] " format, ANSI_FG_BLUE) "\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)

// 断言宏 Assert，若条件 cond 为 false，则打印错误信息，并终止程序
#define Assert(cond, format, ...) \
  do { \
    if (!(cond)) { \
      /* 如果是 AM 目标平台，使用 printf 输出错误信息，否则使用 fprintf 输出到 stderr */ \
      MUXDEF(CONFIG_TARGET_AM, printf(ANSI_FMT(format, ANSI_FG_RED) "\n", ## __VA_ARGS__), \
        (fflush(stdout), fprintf(stderr, ANSI_FMT(format, ANSI_FG_RED) "\n", ##  __VA_ARGS__))); \
      /* 若不是 AM 目标，则刷新日志文件指针，确保错误信息及时写入 */ \
      IFNDEF(CONFIG_TARGET_AM, extern FILE* log_fp; fflush(log_fp)); \
      /* 调用 assert_fail_msg() 以提供更详细的错误信息 */ \
      extern void assert_fail_msg(); \
      assert_fail_msg(); \
      /* 触发标准 assert 断言，终止程序 */ \
      assert(cond); \
    } \
  } while (0)

// panic 宏，遇到严重错误时终止程序，等效于 Assert(0, ...)
#define panic(format, ...) Assert(0, format, ## __VA_ARGS__)

// TODO 宏，表示未完成的功能，调用时直接 panic 终止程序
#define TODO() panic("please implement me")

#endif
