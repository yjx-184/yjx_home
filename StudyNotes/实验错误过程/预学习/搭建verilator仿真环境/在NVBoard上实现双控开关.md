# 问题：称是引脚错误
## 报错现场
```
yjx@yjx-Lenovo-Legion-R7000-2020:~/ysyx-workbench/npc$ make
python3 /home/yjx/ysyx-workbench/nvboard/scripts/auto_pin_bind.py constr/top.nxdc /home/yjx/ysyx-workbench/npc/build/auto_bind.cpp
Line 2: Error: Invalid multi-pin assignment
make: *** [Makefile:28: /home/yjx/ysyx-workbench/npc/build/auto_bind.cpp] Error 1
```
## 问题描述
top.nxdc 文件的第 2 行中，有一个无效的多引脚分配，导致生成绑定代码时出现问题。
## 解决过程
通过阅读源代码，猜测可能与top.nxdc 文件关系不大。于是返回sim.cpp文件进行查看。定位到了关于引脚函数的位置。错误源代码如下：
```
static TOP_NAME dut;

//声明引脚绑定函数
void nvboard_bind_all_pins(TOP_NAME* top);
```

当我改成如下却成功了：
```
static TOP_NAME dut;

//声明引脚绑定函数
void nvboard_bind_all_pins(Vtop* top);
```
于是我认为出错的原因在于 TOP_NAME 宏的定义没有正确执行。定位到了Makefile文件，发现我没有设置宏定义，于是添加上去
```
TOPNAME = top
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
```
此时输出执行成功。