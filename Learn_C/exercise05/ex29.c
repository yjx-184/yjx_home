#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>

typedef int (*lib_function)(const char *data);

int main(int argc, char *argv[])
{
    int rc = 0;
    check(argc == 4, "使用情况：ex29 libex29.so 函数数据");

    char *lib_file = argv[1];
    char *func_to_run = argv[2];
    char *data = argv[3];

    void *lib = dlopen(lib_file, RTLD_NOW);
    check(lib != NULL, "无法打开库 %s: %s", lib_file, dlerror());

    lib_function func = dlsym(lib, func_to_run);
    check(func != NULL, "在库中未找到 %s 函数 %s: %s", func_to_run, lib_file, dlerror());

    rc = func(data);
    check(rc == 0, "函数 %s 返回 %d 个数据： %s", func_to_run, rc, data);

    rc = dlclose(lib);
    check(rc == 0, "关闭 %s失败", lib_file);

    return 0;

error:
    return 1;
}