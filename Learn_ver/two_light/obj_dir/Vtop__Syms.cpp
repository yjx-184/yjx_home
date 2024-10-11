// Verilated -*- C++ -*-
// 描述: Verilator 输出: 符号表实现内部

#include "Vtop__Syms.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// 函数
Vtop__Syms::~Vtop__Syms()
{
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // 设置 Syms 类的内部状态
    , __Vm_modelp{modelp}
    // 设置模块实例
    , TOP{this, namep}
{
    // 配置时间单位 / 时间精度
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // 设置每个模块的子模块指针
    // 设置每个模块指向符号表的指针（用于公共函数）
    TOP.__Vconfigure(true);
}
