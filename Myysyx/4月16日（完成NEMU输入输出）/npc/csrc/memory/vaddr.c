#include <isa.h>
#include <memory/paddr.h> //包含物理地址访问相关的头文件

//通过虚拟地址获取指令，返回对应物理地址数据
word_t vaddr_ifetch(vaddr_t addr, int len) {
  return paddr_read(addr,len); //调用paddr_read()函数从物理地址中读取数据
}

//通过虚拟地址读取数据
word_t vaddr_read(vaddr_t addr, int len) {
  return paddr_read(addr,len); //调用paddr_read()函数从物理地址中读取数据
}

//通过虚拟地址写入数据
void vaddr_write(vaddr_t addr, int len, word_t data) {
  paddr_write(addr, data, len); //调用paddr_write()函数将数据写入物理地址
}