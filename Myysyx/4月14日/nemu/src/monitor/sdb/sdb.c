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

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"

// ====================== 全局变量 ======================
static int is_batch_mode = false; //静态变量，标识是否处于批处理模式

// ====================== 函数声明 ======================
void init_regex();    //初始化正则表达式匹配
void init_wp_pool();  //初始化监视点池

// ====================== 输入处理 ======================
/* We use the `readline' library to provide more flexibility to read from stdin. */
/* 翻译：使用 `readline` 库从标准输入读取用户输入，提供更灵活的功能*/
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {    //释放上一次分配的内存，防止内存泄漏
    free(line_read); 
    line_read = NULL;
  }

  line_read = readline("(nemu) ");  //读取用户输入

  if (line_read && *line_read) {    //如果用户输入了非空字符串，则添加到历史记录中
    add_history(line_read);
  }

  return line_read;
}

// ====================== 命令处理函数 ======================
/* 继续执行程序 */
static int cmd_c(char *args) {      
  cpu_exec(-1);                     //让CPU继续执行，-1代表执行直到程序结束
  return 0;
}

/* 退出NEMU */
static int cmd_q(char *args) {      
  nemu_state.state = NEMU_QUIT;
  return -1;                        //返回-1表示需要退出
}

/* 显示帮助信息 */
static int cmd_help(char *args);    

/* 单步执行 */
static int cmd_si(char *args) {
  int n = 1;  //默认执行1条指令

  //如果用户提供了参数
  if (args != NULL) {
    //使用 sscanf() 解析参数，确保参数是一个整数
    if (sscanf(args, "%d", &n) != 1 || n <= 0) {  //如果解析失败或者n <= 0
      printf("Invalid argument for si: %s\n", args);
      return 0;
    }
  }

  cpu_exec(n);      //让CPU执行n条命令
  return 0;
}    

/* 处理info r命令， 打印寄存器状态*/
static int cmd_info_r(char *args) {
  printf("Registers:\n");
  isa_reg_display();//调用isa_reg_display()函数，打印所有寄存器的值
  return 0;
}

/* 处理info w命令， 打印打印监视点信息。*/
static int cmd_info_w(char *args) {
  WP *head = get_head();
  if (head == NULL) {
    printf("No active watchpoints.\n");
    return 0;
  }

  WP *wp = head;
  while (wp != NULL) {
    printf("Watchpoint %d: %s = %d (0x%x)\n", wp->NO, wp->expr, wp->value, wp->value);
    wp = wp->next;
  }
  return 0;
}

/*拓展info*/
static int cmd_info(char *args) {
  if (args == NULL) {
    printf("Error: 'info' command needs to be followed by a subcommand ('r' or 'w')\n" );
    return 0;
  }

  //根据子命令调用不同的函数
  if (strcmp(args, "r") == 0) {
    return cmd_info_r(args);
  } 
  else if (strcmp(args, "w") == 0) {
    return cmd_info_w(args);
  }
  else {
    printf("Unknown subcommand '%s' for 'info'.Supported subcommands: 'r' and 'w'.\n", args);
    return 0;
  }
}

/* 处理 扫描内存 的函数*/
static int cmd_x(char *args) {
  int n;                  //定义变量n，用来存储扫描的内存单元数量
  uint32_t start_addr;    //定义变量start_addr，用来存储内存扫描的起始地址

  if (sscanf(args, "%d %x", &n, &start_addr) != 2) {
    //如果参数格式不正确，返回错误信息,"格式错误。正确格式：x n EXPR"
    printf("Format Error. Correct format: x n EXPR\n");
    return 0;
  }

  //打印信息,"从地址 0x%x:\n 扫描内存"
  printf("Scanning memory from address 0x%x:\n", start_addr);

  //循环扫描指定数量的内存单元
  for (int i = 0; i < n; i++) {
    word_t data = vaddr_read(start_addr + i * 4, 4);  //计算当前扫描的内存地址，i是扫描次数，每次扫描4字节
  
    printf("0x%08x: %10d (0x%08x)\n", start_addr + i * 4, data, data); //打印地址和数据
  }
  return 0;
}

/* 处理 p EXPR 命令，计算表达式 EXPR 的值*/
static int cmd_p(char *args) {
  //检测用户是否输入了表达式
  if (args == NULL) {
    printf("Usage: p EXPR\n");  //提醒输入正确格式
    return 0;
  }

  //调用expr()函数计算表达式的值
  bool success;
  word_t result = expr(args, &success);

  //根据计算是否成功输出结果
  if (success) {
    //如果成功，输出表达式及其对应的值
    printf("%s = %d (0x%x)\n", args, result, result);
  } else {
    //如果失败，提示用户表达式无效
    printf("Invalid expression: %s\n", args);
  }
  return 0;
}

/* 处理w EXPR 命令，设置监视点*/
static int cmd_w(char *args) {
  //检测用户是否输入了表达式
  if (args == NULL) {
    printf("Usage: w EXPR\n");          //提醒输入正确格式
    return 0;
  }

  //求值表达式
  bool success;                         //表达式是否求值成功
  word_t value = expr(args, &success);  //调用expr函数进行求值
  if (success) {
    WP *wp = new_wp();                  //申请一个新的监视点
    wp->value = value;                  //将求值后的只传递给wp的value
    wp->expr = strdup(args);            //将表达式的字符串复制给wp的expr
    printf("Watchpoint %d: %s = %d (0x%x)\n", wp->NO, wp->expr, wp->value, wp->value);
  } else {
    printf("Invalid expression: %s\n", args);       //打印错误信息
  }
  return 0;
}

/* 删除监视点 */
static int cmd_d(char *args) {
  //检测用户是否输入了表达式
  if (args == NULL) {
    printf("Usage: d N\n");             //提醒输入正确格式
    return 0;
  }

  int wp_no;                                        //存储要删除的监视点编号
  if (sscanf(args, "%d", &wp_no) != 1) {            //解析监视点编号
    printf("Invalid argument for d: %s\n", args);   //解析失败输出错误信息
    return 0;
  }

  WP *head = get_head();
  WP *wp = head;                                    //从头节点开始查找要删除的监视点
  while (wp != NULL) {
    if (wp->NO == wp_no) {                          //找到指定编号的监视点
      free_wp(wp);                                  //调用free_wp函数删除监视点
      printf("Watchpoint %d deleted.\n", wp_no);
      return 0;
    }
    wp = wp->next;                                  //继续查找下一个监视点
  }
  printf("Watchpoint %d not found.\n", wp_no);      //没有找到监视点
  return 0;
}

/* 设置断点*/
static int cmd_b(char *args) {
  if (args == NULL) {
    printf("Usage: b ADDR\n");
    return 0;
  }

  bool success;
  word_t addr = expr(args, &success); //解析地址表达式
  if (!success) {
    printf("Invalid address: %s\n", args);
    return 0;
  }
  char expr_str[32];
  snprintf(expr_str, sizeof(expr_str), "$pc == %u", addr); // 构造表达式
  WP *wp = new_wp(); // 申请一个新的监视点
  wp->expr = strdup(expr_str);
  wp->value = 0; // 断点的值不重要

  printf("Breakpoint set at address 0x%x\n", addr);
  return 0;
}


// ====================== 命令表 ======================
/* 命令表结构体，包含命令名称、描述和处理函数 */
static struct {
  const char *name;                 //命令名称
  const char *description;          //命令描述
  int (*handler) (char *);          //处理该命令的函数指针
} cmd_table [] = {
  //显示所有支持的命令的信息
  { "help", "Display information about all supported commands", cmd_help },

  //继续执行程序
  { "c", "Continue the execution of the program", cmd_c },

  //退出NEMU
  { "q", "Exit NEMU", cmd_q },

  //执行n条指令（默认：1）
  { "si", "Step n instructions (default: 1)", cmd_si},

  //打印程序状态。使用 'r' 表示寄存器，使用 'w' 表示观察点
  { "info", "Print program status. Use 'r' for registers, 'w' for watchpoints", cmd_info },
  
  //扫描内存。格式：x N EXPR，其中 N 是要读取的 4 字节单元的数量，EXPR 是十六进制的起始地址。
  { "x", "Scan memory. Format: x N EXPR, where N is the number of 4-byte units to read and EXPR is the start address in hexadecimal.", cmd_x},

  //表达式求值。计算表达式的值，格式：p EXPR
  { "p", "Evaluate an expression, format: p EXPR", cmd_p },

  //设置监视点.格式：w EXPR
  { "w",  "Set monitoring point, format: w EXPR", cmd_w},

  //删除监视点
  { "d", "Delete a watchpoint. Usage: d N", cmd_d },

  //设置断点
  { "b", "Set a breakpoint at a specific address", cmd_b },

  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)    //计算命令表中的命令数量

// ====================== 命令实现 ======================
static int cmd_help(char *args) {   //“help”命令的实现
  /* extract the first argument  提取第一个参数 */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given  未提供参数时，列出所有命令 */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) { //查找是否有匹配的命令
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);  //没有找到命令
  }
  return 0;
}

// ====================== 批处理模式 ======================
/* 设置批处理模式 */
void sdb_set_batch_mode() {
  is_batch_mode = true;
}

// ====================== 主循环 ======================
/* SDB主循环，处理用户输入的命令 */
void sdb_mainloop() {
  if (is_batch_mode) {  //如果是批处理模式
    cmd_c(NULL);        //直接执行
    return;
  }

  /* 主循环，读取用户输入的命令 */
  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);              // 计算字符串结束的位置

    /* extract the first token as the command 提取第一个单词作为命令 */
    char *cmd = strtok(str, " "); // 将str按空格分割，并返回下一个非空的token，如果没有更多标记，则返回 NULL。
    if (cmd == NULL) { continue; }                  //如果为空，跳过本次循环

    /* treat the remaining string as the arguments, 将剩余的字符串作为参数，
     * which may need further parsing               这些参数可能需要进一步解析
     */
    char *args = cmd + strlen(cmd) + 1;             //跳过命令名和紧随其后的空格，指向参数的起始位置。
    if (args >= str_end) {                          //如args超出了str的范围，则设置为空
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;                                              //遍历命令列表
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {        // strcmp()是字符串比较函数，查找匹配命令
        if (cmd_table[i].handler(args) < 0) { return; } //执行命令处理函数，返回值<0则退出
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); } //打印错误信息
  }
}

// ====================== 初始化 ======================
void init_sdb() { //初始化SDB
  /* Compile the regular expressions. 编辑正则表达式 */
  init_regex();

  /* Initialize the watchpoint pool. 初始化监视点池 */
  init_wp_pool();
}
