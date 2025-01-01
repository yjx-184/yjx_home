// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VTop_top.h"
#include "VTop_top__Syms.h"

//============================================================
// Constructors

VTop_top::VTop_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VTop_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , res{vlSymsp->TOP.res}
    , seg{vlSymsp->TOP.seg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VTop_top::VTop_top(const char* _vcname__)
    : VTop_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VTop_top::~VTop_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VTop_top___024root___eval_debug_assertions(VTop_top___024root* vlSelf);
#endif  // VL_DEBUG
void VTop_top___024root___eval_static(VTop_top___024root* vlSelf);
void VTop_top___024root___eval_initial(VTop_top___024root* vlSelf);
void VTop_top___024root___eval_settle(VTop_top___024root* vlSelf);
void VTop_top___024root___eval(VTop_top___024root* vlSelf);

void VTop_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTop_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VTop_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VTop_top___024root___eval_static(&(vlSymsp->TOP));
        VTop_top___024root___eval_initial(&(vlSymsp->TOP));
        VTop_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VTop_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VTop_top::eventsPending() { return false; }

uint64_t VTop_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VTop_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VTop_top___024root___eval_final(VTop_top___024root* vlSelf);

VL_ATTR_COLD void VTop_top::final() {
    VTop_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VTop_top::hierName() const { return vlSymsp->name(); }
const char* VTop_top::modelName() const { return "VTop_top"; }
unsigned VTop_top::threads() const { return 1; }
