#ifndef __ISA_H
#define __ISA_H
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VNpc.h" 
#include "common.h"
#include "utils.h"
#include "isa-def.h"


// #define MEM_SIZE 33554432
extern VerilatedVcdC* tfp;
extern VNpc* top;
extern bool clk;
extern int sim_time;
extern bool simulation_initialized;
extern bool hit_good_trap;

extern void check_wp();


// 初始化设置
void init_monitor(int argc, char *argv[]);
void sim_exit();

// monitor
// extern unsigned char isa_logo[];
void init_isa();

// reg
extern CPU_state cpu;
extern uint32_t curr_pc;
void isa_reg_display();
uint32_t isa_reg_str2val(const char *s, bool *success);

// memory
enum { MMU_DIRECT, MMU_TRANSLATE, MMU_FAIL };
enum { MEM_TYPE_IFETCH, MEM_TYPE_READ, MEM_TYPE_WRITE };
enum { MEM_RET_OK, MEM_RET_FAIL, MEM_RET_CROSS_PAGE };

// extern "C" void dpi_fetch_inst(uint32_t pc);
// extern "C" void dpi_write_mem(uint32_t addr, uint32_t data);
extern "C" void dpi_end_simulation();
extern "C" void pmem_write(int waddr, unsigned char wmask, int wdata);
extern "C" uint32_t pmem_read(int raddr);


// interrupt/exception
vaddr_t isa_raise_intr(word_t NO, vaddr_t epc);
#define INTR_EMPTY ((word_t)-1)
word_t isa_query_intr();

// difftest
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc);
void isa_difftest_attach();
void init_difftest(char *ref_so_file, long img_size, int port);

// ELF符号节点链表
typedef struct ElfSymbolNode {
  char *name;                   // 符号名称
  uint32_t addr;                // 符号地址
  struct ElfSymbolNode * next;  // 指向下一个符号
} ElfSymbolNode;

// ELF符号表
typedef struct {
  char *strtab_data;            // 字符串表
  ElfSymbolNode *head;          // 符号链表的头指针
} ElfSymbolTable;
extern ElfSymbolTable elf_symtab;
void parse_elf(const char *elf_path);
void free_elf_symbols(ElfSymbolTable *symtab);


// ftrace
#if CONFIG_FTRACE
void ftrace_check();
#endif


#endif