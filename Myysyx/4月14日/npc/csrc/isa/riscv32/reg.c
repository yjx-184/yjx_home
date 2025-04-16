#include <isa.h>
// #include "isa.h"


const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"
  // "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  // "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

//isa_reg_display函数用于显示所有寄存器的值
void isa_reg_display() {
  for(int i = 0; i < 16; i++) {     //遍历并打印每个寄存器的值
    printf("%-3s = 0x%08x\n", regs[i], cpu.gpr[i]);
  }
  // printf("%-3s = 0x%08x\n", "pc",cpu.pc);  //打印pc的值
  printf("%-3s = 0x%08x\n", "pc",curr_pc);
}

//is_reg_str2val函数将寄存器的名称则输出该寄存器的值
uint32_t isa_reg_str2val(const char *s, bool *success) {

  // 处理pc
  if (strcmp(s, "$pc") == 0) {
        *success = true;
        return cpu.pc;  // 读取 PC 的值
    }

  //处理0寄存器
  if (strcmp(s, "$0") == 0) {
    *success = true;
    return cpu.gpr[0];
  } else {
    s++;
    for(int i = 1; i < 16; i++) {     //遍历每个寄存器,跳过0寄存器
    if (strcmp(s, regs[i]) == 0) {  //找到对应寄存器的名称，返回寄存器的值
      *success = true;
      return cpu.gpr[i];
    }
  }
  }
  
  //没有找到匹配的寄存器名称，返回失败
  *success = false;
  return 0;
}