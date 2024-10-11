// Verilated -*- C++ -*-
// 说明：Verilator 输出：主模型头文件
//
// 该头文件应被所有实例化设计的源文件包含。
// 这里的类随后会被构造以实例化设计。
// 参见 Verilator 手册中的示例。

#ifndef VERILATED_VTOP_H_
#define VERILATED_VTOP_H_  // guard

#include "verilated.h"

class Vtop__Syms;
class Vtop___024root;

// 此类是 Verilated 模型的主要接口
class Vtop VL_NOT_FINAL : public VerilatedModel {
  private:
    // 符号表保存完整的模型状态（由此类拥有）
    Vtop__Syms* const vlSymsp;

  public:

    // 端口
    // 应用代码写入和读取这些信号以将新值传播到 Verilated 模型内/外。
    VL_IN8(&a,0,0);
    VL_IN8(&b,0,0);
    VL_OUT8(&f,0,0);

    // 单元
    // 公开访问 /* verilator public */ 项目。
    // 否则，应用代码可以将这些内容视为内部项。

    // 根实例指针，允许访问模型内部，
    // 包括内联的 /* verilator public_flat_* */ 项目。
    Vtop___024root* const rootp;

    // 构造函数
    /// 构造模型；由应用代码调用
    /// 如果 contextp 为 null，则模型将使用默认的全局上下文
    /// 如果 name 为空字符串 ""，则会创建一个
    /// 在 DPI 范围名称中不可见的单模型包装器。
    explicit Vtop(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtop(const char* name = "TOP");
    /// 销毁模型；由应用代码调用（通常隐式调用）
    virtual ~Vtop();
  private:
    VL_UNCOPYABLE(Vtop);  ///< 不允许复制

  public:
    // API 方法
    /// 评估模型。输入改变时应用程序必须调用此函数。
    void eval() { eval_step(); }
    /// 当每个时间步调用多个单元/模型时进行评估。
    void eval_step();
    /// 在一个时间步结束时进行评估以进行跟踪，当使用 eval_step() 时调用。
    /// 应用程序必须在所有 eval() 调用后且在时间改变之前调用。
    void eval_end_step() {}
    /// 仿真完成，执行最终块。应用程序必须在仿真完成时调用此函数。
    void final();
    /// 是否有计划处理的事件？
    bool eventsPending();
    /// 返回下一个时间槽的时间。如果 !eventsPending() 则中止。
    uint64_t nextTimeSlot();
    /// 检索此模型实例的名称（与构造函数传递的名称相同）。
    const char* name() const;

    // 从 VerilatedModel 抽象的方法

    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
