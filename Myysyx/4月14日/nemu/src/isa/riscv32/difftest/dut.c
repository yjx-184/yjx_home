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
#include <cpu/difftest.h>
#include "../local-include/reg.h"

// 检查参考模型和DUT的寄存器状态是否一致
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  // 遍历所有通用寄存器
  for (int i = 0; i < sizeof(ref_r->gpr) / sizeof(ref_r->gpr[0]); i++) {
    if (ref_r->gpr[i] != cpu.gpr[i]) {
      printf("DiffTest: Register mismatch at PC= 0x%08x\n", pc);
      printf("Reg[%d]: REF = 0x%08x, DUT = 0x%08x\n", i, ref_r->gpr[i], cpu.gpr[i]);
      return false;
    }
  }

  // 比较PC
  if (ref_r->pc != cpu.pc) {
    printf("DiffTest: PC mismatch! REF = 0x%08x, DUT = 0x%08x\n", ref_r->pc, cpu.pc);
    return false;
  }

  return true;

}

// 连接 REF 和 DUT
void isa_difftest_attach() {
}
