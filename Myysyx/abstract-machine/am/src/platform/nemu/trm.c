#include <am.h>
#include <nemu.h>

// 声明外部符号_heap_start，用于指示堆区的起始位置
extern char _heap_start;

// 声明 main 函数，主函数的参数 args 是命令行参数
int main(const char *args);

// 结构用于指示堆区的起始和末尾
Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = MAINARGS_PLACEHOLDER; // 在 CFLAGS 中定义

// 用于输出一个字符
void putch(char ch) {
  outb(SERIAL_PORT, ch);  // 调用 outb() 将字符 ch 发送到串口端口 SERIAL_PORT
}

// 用于结束程序的运行
void halt(int code) {
  nemu_trap(code);        // 触发 NEMU 的特殊指令，向仿真器报告程序结束状态

  // should not reach here
  // 不应到达此处
  while (1);
}

// 用于进行TRM相关的初始化工作
void _trm_init() {
  // 调用 main 函数，并传入 mainargs 作为命令行参数
  int ret = main(mainargs);
  
  // main 函数返回后，调用 halt 终止程序，返回值 ret 作为退出码
  halt(ret);
}
