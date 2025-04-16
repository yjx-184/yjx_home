#include <memory/host.h>
#include <memory/paddr.h>         //包含物理地址操作相关的头文件
// #include <device/mmio.h>          //包含设备内存映射IO操作相关的头文件
#include <isa.h>                  //包含ISA指令集架构相关的头文件
#include <cpu/cpu.h>

static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};  //使用静态数组方式分配物理内存

#if CONFIG_MTRACE
// 定义内存追踪的起始和结束地址
static paddr_t mtrace_start = 0;
static paddr_t mtrace_end = 0xFFFFFFFF;

// 初始化内存追踪功能，解析配置中的地址范围
void init_mtrace() {
  const char *range = "CONFIG_MTRACE_ADDR_RANGE";
  if (range) {
    sscanf(range, "%x,%x", &mtrace_start, &mtrace_end);
  }
}

// 检查地址是否在内存追踪范围内
static inline bool in_mtrace_range(paddr_t addr) {
  return addr >= mtrace_start && addr <= mtrace_end;
}
#endif

//将物理地址转换为主机内存地址，物理地址到主机地址的转换，偏移量由配置的基地址决定
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
//将主机内存地址转换为物理地址，主机地址到物理地址的转换，基于物理内存起始位置的偏移
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

//处理越界访问物理内存情况
static void out_of_bound(paddr_t addr) {
#if CONFIG_CN
  Log("地址 = " FMT_PADDR " 超出了物理内存范围 [" FMT_PADDR ", " FMT_PADDR "] 当前 pc = \n" FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
#else
  Log("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = \n" FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);         //输出错误信息并触发panic
#endif
}

// 从内存中读取
extern "C" word_t pmem_read(int raddr) {
    // 总是读取地址为`raddr & ~0x3u`的4字节返回
    // raddr = raddr & ~0x3;
    // len = 4;
    uint32_t ret = host_read(guest_to_host(raddr), 4); //从物理内存对应位置读取数据
    return ret;

}

// 向内存写入数据
extern "C" void pmem_write(int waddr, unsigned char wmask, int wdata) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  // waddr = waddr & ~0x3u;
  if (!in_pmem(waddr)) {
    out_of_bound(waddr);
    return; // 退出函数，避免进一步写入
  }

  #if CONFIG_MTRACE
    if (in_mtrace_range(waddr)) { // 如果启用了内存追踪且地址在追踪范围内
      printf("[MTRACE] Write waddr = %#010x, wmask = %2d, wdata = %#010x\n", waddr, wmask, wdata);
    }
  #endif

  // 执行写操作
  for (int i = 0; i < 4; i++) {
    if ((wmask >> i) & 1) {
      host_write(guest_to_host(waddr + i), 1, (wdata >> (i*8)) & 0xFF);
    }
  }

}





//初始化物理内存，分配内存并设置随机数（如果配置了随机填充）
void init_mem() {
// #if   defined(CONFIG_PMEM_MALLOC)
//   pmem = malloc(CONFIG_MSIZE);  //动态分配内存
//   assert(pmem);                 //确保内存分配成功
// #endif
  // IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE)); //配置了随机填充时，将物理内存填充为随机值
#if CONFIG_MEM_RANDOM
    memset(pmem, rand(), CONFIG_MSIZE);  // 配置了随机填充时，将物理内存填充为随机值
#endif

#if CONFIG_CN
  Log("物理内存地址范围：[" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
#else
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);//打印物理内存的地址范围
#endif
#if CONFIG_MTRACE
  init_mtrace();  // 初始化内存追踪功能
#endif
}

//从物理地址读取数据，如果地址在物理内存范围内，则直接读取，否则检查是否为MMIO设备
word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) {          // 检查地址是否在物理内存范围内
    word_t ret = pmem_read(addr);  // 读取数据
#if CONFIG_MTRACE
    if (in_mtrace_range(addr)) {        // 如果启用了内存追踪且地址在追踪范围内
      printf("[MTRACE] Read  raddr = %#010x, len = %4d, rdata = %#010x\n", addr, len, ret);
    }
#endif
    return ret;                         // 返回读取的数据
  }
  // IFDEF(CONFIG_DEVICE, return mmio_read(addr));     //配置了设备时，调用设备的内存映射IO读取函数
  #if CONFIG_DEVICE
    return mmio_read(addr);
#endif
  
  out_of_bound(addr); //如果地址超出范围，调用越界处理函数
  return 0;
}

//向物理地址写入数据，如果地址在物理内存范围内，则直接写入，否则检查是否为MMIO设备
void paddr_write(int waddr, int len, int wdata) {

    pmem_write(waddr, len, wdata);        // 写入数据
    return;

    // IFDEF(CONFIG_DEVICE, mmio_write(waddr, len, wdata); return);         //如果地址超出范围，调用越界处理函数
    #if CONFIG_DEVICE
          mmio_write(waddr, len, wdata); 
          return;
    #endif 

}