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
#include <memory/paddr.h>
#include <elf.h>

void init_rand();     //初始化随机数生成器
void init_log(const char *log_file);  //初始化日志系统，接受日志文件路径作为参数
void init_mem();      //初始化内存系统
void init_difftest(char *ref_so_file, long img_size, int port); //初始化差分测试系统，接受参考SO文件、映像大小，端口号作为参数
void init_device();   //初始化设备系统
void init_sdb();      //初始化简单调试器（SDB）
void init_disasm();   //初始化反汇编系统
void print_elf_symbol_table(ElfSymbolTable *symtab);

static void welcome() {//欢迎信息打印
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>   //用于解析命令行参数

void sdb_set_batch_mode();  //设置批处理模式

static char *log_file = NULL;     //日志文件路径
static char *diff_so_file = NULL; //差分测试的参考SO文件路径
static char *img_file = NULL;     //映像文件路径
static char *elf_file = NULL;     //ELF文件路径
static int difftest_port = 1234;  //差分侧视端口号，默认为1234

ElfSymbolTable elf_symtab = {0};


// ELF符号节点链表(被我放到了isa.h)
// typedef struct ElfSymbolNode {
//   char *name;                   // 符号名称
//   uint32_t addr;                // 符号地址
//   struct ElfSymbolNode * next;  // 指向下一个符号
// } ElfSymbolNode;

// ELF符号表
// typedef struct {
//   char *strtab_data;            // 字符串表
//   ElfSymbolNode *head;          // 符号链表的头指针
// } ElfSymbolTable;

/* 加载映像文件到内存，返回映像大小 */
static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096; // built-in image size 默认内置映像大小
  }

  FILE *fp = fopen(img_file, "rb");           //打开映像文件
  Assert(fp, "Can not open '%s'", img_file);  //如果文件打开失败，打印错误并退出

  fseek(fp, 0, SEEK_END);                     //移动到文件末尾，获取文件大小
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);                     //重新定位到开头
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);  //读取文件到内存
  assert(ret == 1);                           //确保读取成功

  fclose(fp);
  return size;
}

/* 解析ELF文件，获取符号表和字符串表*/
void parse_elf(const char *elf_path) {
  free_elf_symbols(&elf_symtab);
  // 打开ELF文件
  FILE *fp = fopen(elf_path, "rb");           
  Assert(fp, "Can not open '%s'", elf_path);  // 如果文件打开失败，打印错误并退出
  // printf("成功打开 ELF 文件: %s\n", elf_path);

  // 读取ELF文件头
  Elf32_Ehdr ehdr;                            // 定义ELF文件头结构体      
  if (fread(&ehdr, sizeof(ehdr), 1, fp) != 1) {       // 读取ELF文件头信息
    fprintf(stderr, "Error: 读取ELF文件头信息失败!\n");
    fclose(fp);
    return;
  }
    // printf("ELF 头信息读取成功: 入口地址 0x%x, 段头表偏移  0x%x, 段头表项个数 %d\n",
    //      ehdr.e_entry, ehdr.e_shoff, ehdr.e_shnum);

  Elf32_Shdr symtab = {0}, strtab = {0};      // 定义符号表和字符串表的变量并初始化
  Elf32_Sym sym;                              // 定义符号表项结构体
  elf_symtab.head = NULL;

  // 遍历节表，寻找符号表和字符串表
  fseek(fp, ehdr.e_shoff, SEEK_SET);          // 定位到节表,从文件开头到段表头的字节偏移
  for (int i = 0; i < ehdr.e_shnum; i++) {
    Elf32_Shdr shdr;                          // 定义节表项结构体   
    long current_pos = ftell(fp);             // 记录当前节表项起始位置
    if (fread(&shdr, sizeof(shdr), 1, fp) != 1) {     // 读取当前节表项
      fprintf(stderr, "Error: 读取当前节表项失败!\n");
      fclose(fp);
      return;
    }

    // 如果当前节表项是符号表，记录符号表和关联的字符串表
    if (shdr.sh_type == SHT_SYMTAB) {
      symtab = shdr;                          // 记录符号表的节头信息
      long saved_pos = ftell(fp);             // 保存当前节表项遍历的位置
      // uint32_t sh_link;      /* 关联段索引（如符号表的字符串表） */
      fseek(fp, ehdr.e_shoff + shdr.sh_link * sizeof(Elf32_Shdr), SEEK_SET);  //  找到字符串表所在的节头
      if (fread(&strtab, sizeof(strtab), 1, fp) != 1) { // 读取字符串表的节头信息
        fprintf(stderr, "Error: 读取字符串表的节头信息失败!\n");
        fclose(fp);
        return;
      }
      fseek(fp, saved_pos, SEEK_SET);         // 恢复文件指针到当前节表项末尾
      // printf("找到符号表: 在文件中的偏移 0x%x, 大小 %d, 每项大小 %d\n",
      //        symtab.sh_offset, symtab.sh_size, symtab.sh_entsize);
      // printf("找到字符串表: 在文件中的偏移 0x%x, 大小 %d\n",
      //        strtab.sh_offset, strtab.sh_size);
      break;
    }
    // 确保文件指针在遍历节表时能够正确移动到下一个节表项的起始位置。
    fseek(fp, current_pos + ehdr.e_shentsize, SEEK_SET);
  }

  // 读取字符串表
  elf_symtab.strtab_data = malloc(strtab.sh_size); // 为字符串表分配内存
  fseek(fp, strtab.sh_offset, SEEK_SET);           // 定位到字符串表在文件中的偏移位置 
  if (fread(elf_symtab.strtab_data, strtab.sh_size, 1, fp) != 1) {  // 读取字符串表数据
    fprintf(stderr, "Error: 读取字符串表数据失败!\n");
    fclose(fp);
    return;
  }
  // printf("字符串表读取成功\n");

  // 读取符号表
  fseek(fp, symtab.sh_offset, SEEK_SET);      // 定位到符号表在文件中的偏移位置
  int num_symbols = symtab.sh_size / symtab.sh_entsize; // 计算符号表项数量
  // printf("符号表中共有 %d 个符号\n", num_symbols);
  
  // 遍历符号表，提取函数符号并存入链表
  for (int i = 0; i < num_symbols; i++) {   
    if (fread(&sym, sizeof(sym), 1, fp) != 1) {
      fprintf(stderr, "Error: 读取当前符号表项失败!\n");    // 读取当前符号表项
      fclose(fp);
      return;
    }
    if (ELF32_ST_TYPE(sym.st_info) == STT_FUNC) {
      ElfSymbolNode *node = (ElfSymbolNode *)malloc(sizeof(ElfSymbolNode));
      node->addr = sym.st_value;         // 记录符号的地址
      node->name = strdup(elf_symtab.strtab_data + sym.st_name); // 记录符号的名称
      node->next = elf_symtab.head;           // 将新节点插入链表头部
      elf_symtab.head = node;                 // 更新链表头指针
      // printf("发现函数符号: 地址 0x%x, 名称 %s\n", node->addr, node->name);
    }
  }
  // 关闭文件
  fclose(fp);
}

/* 释放 ELF 符号表 */
void free_elf_symbols(ElfSymbolTable *symtab) {
    free(symtab->strtab_data);
    ElfSymbolNode *curr = symtab->head;
    while (curr) {
        ElfSymbolNode *next = curr->next;
        free(curr->name);
        free(curr);
        curr = next;
    }
    symtab->head = NULL;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},  //批处理模式
    {"log"      , required_argument, NULL, 'l'},  //日志文件
    {"diff"     , required_argument, NULL, 'd'},  //差分测试文件
    {"port"     , required_argument, NULL, 'p'},  //差分测试端口
    {"help"     , no_argument      , NULL, 'h'},  //帮助信息
    {"elf"      , required_argument, NULL, 'e'},  // ELF文件路径
    {0          , 0                , NULL,  0 },  //结束符
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:e:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;      //设置批处理模式
      case 'p': sscanf(optarg, "%d", &difftest_port); break;  //设置端口号
      case 'l': log_file = optarg; break;         //设置日志文件路径
      case 'd': diff_so_file = optarg; break;     //设置差分测试参考SO文件
      case 'e': elf_file = optarg; break;         //设置ELF文件路径
      case 1: img_file = optarg; break;           //设置映像文件路径
      
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-e,--elf=ELF_FILE       load ELF file\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}
//初始化监控系统（包括命令行参数解析、内存、设备等初始化
void init_monitor(int argc, char *argv[]) {
  /* Perform some global initialization. 执行一些全局初始化 */

  /* Parse arguments. 解析命令行参数 */
  parse_args(argc, argv);

  /* Set random seed. 设置随机数种子 */
  init_rand();

  /* Open the log file. 打开日志文件  */
  init_log(log_file);

  /* Initialize memory. 初始化内存 */
  init_mem();

  /* Initialize devices. 初始化设备（如果配置了设备） */
  IFDEF(CONFIG_DEVICE, init_device());

  /* Perform ISA dependent initialization. 执行与ISA相关的初始化 */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. 加载映像到内存，这将覆盖内置映像*/
  long img_size = load_img();

  /* ELF文件*/
  if (elf_file) {
    parse_elf(elf_file);
  }

  /* Initialize differential testing. 初始化差分测试系统*/
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. 初始化简单调试器（SDB*/
  init_sdb();

  IFDEF(CONFIG_ITRACE, init_disasm());//如果配置了指令跟踪，初始化反汇编


  /* Display welcome message. 打印欢迎信息 */
  welcome();
}
#else // CONFIG_TARGET_AM
static long load_img() {                //如果是目标平台AM，则加载内嵌的二进制映像
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;  //计算映像的大小
  Log("img size = %ld", size);          //打印映像大小
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);  //将二进制映像复制到内存
  return size;
}

void am_init_monitor() {                //AM平台初始化监控
  init_rand();                          //初始化随机数
  init_mem();                           //初始化内存
  init_isa();                           //初始化ISA
  load_img();                           //加载映像
  IFDEF(CONFIG_DEVICE, init_device());  //如果配置了设备，初始化设备
  welcome();                            //打印欢迎信息
}
#endif
