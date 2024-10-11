// Verilated -*- C++ -*-
// 描述: Verilator 输出: 符号表内部头文件
//
// 内部细节；大多数调用程序不需要此头文件，
// 除非使用了 Verilator 的公共元注释。

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // 防护

#include "verilated.h"

// 包含模型类
#include "Vtop.h"

// 包含模块类
#include "Vtop___024root.h"

// 符号表类 (包含所有模型状态)
class Vtop__Syms final : public VerilatedSyms {
  public:
    // 内部状态
    Vtop* const __Vm_modelp;           // 指向模型的指针
    VlDeleter __Vm_deleter;            // 用于删除内部对象
    bool __Vm_didInit = false;         // 是否已初始化的标志

    // 模块实例状态
    Vtop___024root                 TOP; // 顶层模块实例

    // 构造函数
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // 方法
    const char* name() { return TOP.name(); } // 返回顶层模块的名称
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // 防护结束
