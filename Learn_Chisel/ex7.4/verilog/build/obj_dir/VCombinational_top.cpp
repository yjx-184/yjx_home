// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VCombinational_top.h"
#include "VCombinational_top__Syms.h"

//============================================================
// Constructors

VCombinational_top::VCombinational_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VCombinational_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , res{vlSymsp->TOP.res}
    , in{vlSymsp->TOP.in}
    , seg{vlSymsp->TOP.seg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VCombinational_top::VCombinational_top(const char* _vcname__)
    : VCombinational_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VCombinational_top::~VCombinational_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VCombinational_top___024root___eval_debug_assertions(VCombinational_top___024root* vlSelf);
#endif  // VL_DEBUG
void VCombinational_top___024root___eval_static(VCombinational_top___024root* vlSelf);
void VCombinational_top___024root___eval_initial(VCombinational_top___024root* vlSelf);
void VCombinational_top___024root___eval_settle(VCombinational_top___024root* vlSelf);
void VCombinational_top___024root___eval(VCombinational_top___024root* vlSelf);

void VCombinational_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCombinational_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VCombinational_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VCombinational_top___024root___eval_static(&(vlSymsp->TOP));
        VCombinational_top___024root___eval_initial(&(vlSymsp->TOP));
        VCombinational_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VCombinational_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VCombinational_top::eventsPending() { return false; }

uint64_t VCombinational_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VCombinational_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VCombinational_top___024root___eval_final(VCombinational_top___024root* vlSelf);

VL_ATTR_COLD void VCombinational_top::final() {
    VCombinational_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VCombinational_top::hierName() const { return vlSymsp->name(); }
const char* VCombinational_top::modelName() const { return "VCombinational_top"; }
unsigned VCombinational_top::threads() const { return 1; }