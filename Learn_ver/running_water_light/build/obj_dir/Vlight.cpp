// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)
// Verilator 输出：模型实现（与设计无关的部分）

#include "Vlight.h"
#include "Vlight__Syms.h"

//============================================================
// 构造函数

Vlight::Vlight(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}  // 初始化基类 VerilatedModel，传入上下文指针
    , vlSymsp{new Vlight__Syms(contextp(), _vcname__, this)}  // 创建符号表，保存整个模型的状态
    , clk{vlSymsp->TOP.clk}  // 时钟信号指向符号表中的顶层模块 clk
    , rst{vlSymsp->TOP.rst}  // 复位信号指向符号表中的顶层模块 rst
    , led{vlSymsp->TOP.led}  // LED 输出指向符号表中的顶层模块 led
    , rootp{&(vlSymsp->TOP)}  // 根实例指针指向符号表中的顶层模块
{
    // Register model with the context
    // 在上下文中注册模型
    contextp()->addModel(this);
}

Vlight::Vlight(const char* _vcname__)
    : Vlight(Verilated::threadContextp(), _vcname__)  // 使用默认上下文构造 Vlight 对象
{
}

//============================================================
// 析构函数

Vlight::~Vlight() {
    delete vlSymsp;  // 删除符号表，释放内存
}

//============================================================
// 评估函数

#ifdef VL_DEBUG
void Vlight___024root___eval_debug_assertions(Vlight___024root* vlSelf);  // 声明调试断言函数
#endif  // VL_DEBUG
void Vlight___024root___eval_static(Vlight___024root* vlSelf);  // 声明静态评估函数
void Vlight___024root___eval_initial(Vlight___024root* vlSelf);  // 声明初始评估函数
void Vlight___024root___eval_settle(Vlight___024root* vlSelf);  // 声明稳定态评估函数
void Vlight___024root___eval(Vlight___024root* vlSelf);  // 声明评估函数

void Vlight::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlight::eval_step\n"); );  // 输出调试信息
#ifdef VL_DEBUG
    // 调试断言
    Vlight___024root___eval_debug_assertions(&(vlSymsp->TOP));  // 调用调试断言
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();  // 清理所有之前的对象
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {  // 如果尚未初始化
        vlSymsp->__Vm_didInit = true;  // 标记已初始化
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););  // 输出初始调试信息
        Vlight___024root___eval_static(&(vlSymsp->TOP));  // 静态评估
        Vlight___024root___eval_initial(&(vlSymsp->TOP));  // 初始评估
        Vlight___024root___eval_settle(&(vlSymsp->TOP));  // 稳定态评估
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););  // 输出调试信息，任务0开始
    Verilated::mtaskId(0);  // 设置任务ID
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););  // 输出调试信息，开始评估
    Vlight___024root___eval(&(vlSymsp->TOP));  // 进行评估
    // 评估清理
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);  // 清理任务消息队列
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);  // 结束评估
}

//============================================================
// 事件和定时
bool Vlight::eventsPending() { return false; }  // 检查是否有待处理的事件

uint64_t Vlight::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");  // 如果没有延迟，报告错误
    return 0;
}

//============================================================
// 实用程序

const char* Vlight::name() const {
    return vlSymsp->name();  // 返回模型实例的名称
}

//============================================================
// 调用 final 块

void Vlight___024root___eval_final(Vlight___024root* vlSelf);  // 声明最终评估函数

VL_ATTR_COLD void Vlight::final() {
    Vlight___024root___eval_final(&(vlSymsp->TOP));  // 调用最终评估
}

//============================================================
// VerilatedModel 抽象方法的实现

const char* Vlight::hierName() const { return vlSymsp->name(); }  // 返回层次名称
const char* Vlight::modelName() const { return "Vlight"; }  // 返回模型名称
unsigned Vlight::threads() const { return 1; }  // 返回线程数，默认为1
