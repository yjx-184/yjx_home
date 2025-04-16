#include <dlfcn.h>
#include <capstone/capstone.h> // Capstone 反汇编库
#include <common.h>
#include <cassert>

// 定义函数指针，用于动态加载 Capstone 库中的函数
static size_t (*cs_disasm_dl)(csh handle, const uint8_t *code,
    size_t code_size, uint64_t address, size_t count, cs_insn **insn);
static void (*cs_free_dl)(cs_insn *insn, size_t count);

static csh handle;  // Capstone 库的句柄，用于后续反汇编操作

// 初始化反汇编器
void init_disasm() {
  void *dl_handle;
  // 动态加载 Capstone 库
  dl_handle = dlopen("/home/yjx/ysyx-workbench/npc/tools/capstone/repo/libcapstone.so.5", RTLD_LAZY);
  assert(dl_handle);  // 确保库加载成功

  // 获取 cs_open 函数的地址
  // cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = NULL;
  // cs_open_dl = dlsym(dl_handle, "cs_open");
  // assert(cs_open_dl); // 确保函数地址获取成功
  cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = nullptr;
  cs_open_dl = (cs_err (*)(cs_arch, cs_mode, csh *))dlsym(dl_handle, "cs_open");
  assert(cs_open_dl);

  // 获取 cs_disasm 函数的地址
  // cs_disasm_dl = dlsym(dl_handle, "cs_disasm");
  // assert(cs_disasm_dl); // 确保函数地址获取成功
  cs_disasm_dl = (size_t (*)(csh, const uint8_t*, size_t, uint64_t, size_t, cs_insn **))dlsym(dl_handle, "cs_disasm");
  assert(cs_disasm_dl); // 确保函数地址获取成功

  // 获取 cs_free 函数的地址
  // cs_free_dl = dlsym(dl_handle, "cs_free");
  // assert(cs_free_dl); // 确保函数地址获取成功
  cs_free_dl = (void (*)(cs_insn*, size_t))dlsym(dl_handle, "cs_free");
  assert(cs_free_dl); // 确保函数地址获取成功

  // 固定使用 RISC-V 架构
  cs_arch arch = CS_ARCH_RISCV;
  // 固定使用 RISC-V 模式
  // cs_mode mode = CS_MODE_RISCV32 | CS_MODE_RISCVC;
  cs_mode mode = static_cast<cs_mode>(CS_MODE_RISCV32 | CS_MODE_RISCVC);
  // cs_mode mode = CS_MODE_RISCV32;

  // 初始化 Capstone 库
  int ret = cs_open_dl(arch, mode, &handle);
  assert(ret == CS_ERR_OK); // 确保初始化成功

}

// 反汇编函数
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
	cs_insn *insn;  // 用于存储反汇编结果
  // 调用 Capstone 反汇编函数
	size_t count = cs_disasm_dl(handle, code, nbyte, pc, 0, &insn);
  assert(count == 1); // 确保反汇编成功且只反汇编一条指令
  // // 修改断言为错误处理
  //   if(count != 1) {
  //       snprintf(str, size, "[bad inst 0x%08x]", *(uint32_t *)code);
  //       printf("Disasm failed at PC=0x%lx: code=0x%08x\n", pc, *(uint32_t *)code);
  //       return;
  //   }
  // 将反汇编结果（指令助记符）写入 str
  int ret = snprintf(str, size, "%s", insn->mnemonic);
  // 如果指令有操作数，将操作数追加到 str
  if (insn->op_str[0] != '\0') {
    snprintf(str + ret, size - ret, "\t%s", insn->op_str);
  }
  // 释放反汇编结果占用的内存
  cs_free_dl(insn, count);
}
