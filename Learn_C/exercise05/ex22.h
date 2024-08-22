#ifndef _ex22_h
#define _ex22_h

// 使 ex22.c 中的 THE_SIZE 可供其他 .c 文件使用
extern int THE_SIZE;

// 获取并设置 ex22.c 中的内部静态变量
int get_age();
void set_age(int age);

// 更新 update_ratio 内的静态变量
double update_ratio(double ratio);

void print_size();

#endif // !_ex22_h