#include <cpu/cpu.h>

void sdb_mainloop();

void engine_start() {
    // nemu这里是有一个宏的

    sdb_mainloop();
}