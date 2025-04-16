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

#include <dlfcn.h>

#include <isa.h>
#include <cpu/cpu.h>
#include <memory/paddr.h>
#include <utils.h>
#include <difftest-def.h>

// 定义差分测试函数指针
void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

#ifdef CONFIG_DIFFTEST

static bool is_skip_ref = false;    // 是否跳过参考模型执行标志
static int skip_dut_nr_inst = 0;    // 需要跳过的DUT指令计数

// this is used to let ref skip instructions which
// can not produce consistent behavior with NEMU
// 这用于让参考模型跳过无法与NEMU产生一致行为的指令
void difftest_skip_ref() {
  is_skip_ref = true;
  // If such an instruction is one of the instruction packing in QEMU
  // (see below), we end the process of catching up with QEMU's pc to
  // keep the consistent behavior in our best.
  // Note that this is still not perfect: if the packed instructions
  // already write some memory, and the incoming instruction in NEMU
  // will load that memory, we will encounter false negative. But such
  // situation is infrequent.
  // 如果这样的指令是QEMU中的指令打包（见下文），
  // 我们结束与QEMU的PC同步过程，以保持尽可能一致的行为。
  // 请注意，这仍然不是完美的：如果打包的指令已经写入了一些内存，
  // 而NEMU中的即将执行的指令会加载该内存，我们将遇到假阴性。
  // 但这种情况发生的频率较低。
  skip_dut_nr_inst = 0;             // 重置跳过计数
}

// this is used to deal with instruction packing in QEMU.
// Sometimes letting QEMU step once will execute multiple instructions.
// We should skip checking until NEMU's pc catches up with QEMU's pc.
// The semantic is
//   Let REF run `nr_ref` instructions first.
//   We expect that DUT will catch up with REF within `nr_dut` instructions.
// 这是用来处理QEMU中的指令打包。有时让QEMU执行一次会执行多条指令。
// 我们应该跳过检查，直到NEMU的PC追赶上QEMU的PC。
// 其语义是：
//   让REF先运行nr_ref条指令。
//   我们期望DUT能够在nr_dut条指令内赶上REF。

// 处理QEMU指令打包情况的函数
// nr_ref: 参考模型需要执行的指令数
// nr_dut: DUT预期需要执行的指令数
void difftest_skip_dut(int nr_ref, int nr_dut) {
  skip_dut_nr_inst += nr_dut;       // 累计需要跳过的指令数

  // 让参考模型执行指定数量的指令
  while (nr_ref -- > 0) {
    ref_difftest_exec(1);
  }
}

// 初始化差分测试系统
// ref_so_file: 参考模型动态库路径
// img_size: 镜像文件大小
// port: 初始化端口号
void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  // 打开传入的动态库文件ref_so_file
  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  // 获取参考模型中的函数指针
  ref_difftest_memcpy = dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  // 初始化参考模型
  void (*ref_difftest_init)(int) = dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  // 初始化操作
  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF); // 同步初始寄存器状态到参考模型
}

// 寄存器检查函数
// ref: 参考模型的寄存器状态
// pc: 当前程序计数器值
static void checkregs(CPU_state *ref, vaddr_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) { // 调用ISA相关的寄存器检查
    nemu_state.state = NEMU_ABORT;        // 设置模拟器异常状态
    nemu_state.halt_pc = pc;              // 记录停止时的PC值
    isa_reg_display();                    // 显示ISA寄存器信息
  }
}

// 单步差分测试函数
// pc: 当前指令地址
// npc: 下一条指令地址
void difftest_step(vaddr_t pc, vaddr_t npc) {
  CPU_state ref_r;                                // 参考模型寄存器状态

  // 处理需要跳过DUT指令的情况
  if (skip_dut_nr_inst > 0) {
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT); // 从参考模型复制寄存器状态
    if (ref_r.pc == npc) {                        // 如果PC已经同步
      skip_dut_nr_inst = 0;                       // 重置跳过计数
      checkregs(&ref_r, npc);
      return;
    }
    skip_dut_nr_inst --;                          // 递减跳过计数
    if (skip_dut_nr_inst == 0)
      panic("can not catch up with ref.pc = " FMT_WORD " at pc = " FMT_WORD, ref_r.pc, pc);
    return;
  }

  // 处理需要跳过参考模型检查的情况
  if (is_skip_ref) {
    // to skip the checking of an instruction, just copy the reg state to reference design
    // 为了跳过对一条指令的检查，只需将寄存器状态复制到参考设计
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
    is_skip_ref = false;
    return;
  }

  // 常规差分测试流程
  ref_difftest_exec(1);                           // 让参考模型执行1条指令
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);   // 获取参考模型寄存器状态

  checkregs(&ref_r, pc);                          // 检查寄存器一致性
}
#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
#endif
