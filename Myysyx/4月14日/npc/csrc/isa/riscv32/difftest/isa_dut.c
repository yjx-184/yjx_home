#include <isa.h>
#include <cpu/difftest.h>
#include "../local-include/reg.h"
#include <cpu/cpu.h>


// 检查参考模型和DUT的寄存器状态是否一致
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  for (int i = 0; i < 16; i++) {
    if (!difftest_check_reg(reg_name(i), pc, ref_r->gpr[i], cpu.gpr[i])) {
      return false;
    }
  }

  if (!difftest_check_reg("pc", pc, ref_r->pc, curr_pc)) {
  // if (!difftest_check_reg("pc", pc, ref_r->pc, cpu.pc)) {
    return false;
  }

  return true;
}

// 连接 REF 和 DUT
void isa_difftest_attach() {
}