// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
// 这是 Verilator 生成的主要模型头文件。
// 该头文件应由所有实例化设计的源文件包含。
// 在 Verilator 手册中可以找到示例。

#ifndef VERILATED_VLIGHT_H_
#define VERILATED_VLIGHT_H_  // 宏定义防止重复包含

#include "verilated.h"

class Vlight__Syms;  // 前置声明，表示符号表类
class Vlight___024root;  // 前置声明，表示模型的根实例类

// 这个类是与 Verilated 模型交互的主要接口
class Vlight VL_NOT_FINAL : public VerilatedModel {
  private:
    // 符号表，持有完整的模型状态（该类拥有它）
    Vlight__Syms* const vlSymsp;

  public:

    // 端口
    // 应用代码可以通过这些信号来读写，从而将新值传播到 Verilated 模型内或从模型内读取。
    VL_IN8(&clk,0,0);  // 时钟信号输入，1位宽
    VL_IN8(&rst,0,0);  // 复位信号输入，1位宽
    VL_OUT16(&led,15,0);  // 输出信号，表示16位的LED输出

    // 单元
    // 公开的以允许访问被 `verilator public` 标记的项目。
    // 否则，应用代码可以将这些内容视为内部项。

    // 根实例指针，允许访问模型的内部，
    // 包括内联的 `verilator public_flat_*` 项目。
    Vlight___024root* const rootp;

    // 构造函数
    /// 构造模型；由应用程序代码调用
    /// 如果 contextp 是空的，则模型将使用默认的全局上下文
    /// 如果名称是 ""，则会创建一个不可见的单一模型包装器，相对于 DPI 作用域名称来说。
    explicit Vlight(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vlight(const char* name = "TOP");
    /// 销毁模型；由应用程序代码调用（通常是隐式调用）
    virtual ~Vlight();
  private:
    VL_UNCOPYABLE(Vlight);  ///< 不允许复制

  public:
    // API 方法
    /// 评估模型。当输入更改时，应用程序必须调用此方法。
    void eval() { eval_step(); }
    /// 当每个时间步骤调用多个单元/模型时进行评估。
    void eval_step();
    /// 当使用 eval_step() 进行跟踪时，在时间步结束时进行评估。
    /// 在所有 eval() 调用之后，时间改变之前，应用程序必须调用此方法。
    void eval_end_step() {}
    /// 仿真完成，运行最终块。应用程序在完成时必须调用此方法。
    void final();
    /// 是否有计划处理的事件？
    bool eventsPending();
    /// 返回下一个时间槽的时间。如果 `!eventsPending()` 则中止。
    uint64_t nextTimeSlot();
    /// 检索此模型实例的名称（如构造函数中传递的）。
    const char* name() const;

    // VerilatedModel 中的抽象方法
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // 防止重复包含
