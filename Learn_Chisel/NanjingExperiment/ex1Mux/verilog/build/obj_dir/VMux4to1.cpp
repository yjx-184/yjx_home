// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VMux4to1.h"
#include "VMux4to1__Syms.h"

//============================================================
// Constructors

VMux4to1::VMux4to1(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VMux4to1__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_X0{vlSymsp->TOP.io_X0}
    , io_X1{vlSymsp->TOP.io_X1}
    , io_X2{vlSymsp->TOP.io_X2}
    , io_X3{vlSymsp->TOP.io_X3}
    , io_Y{vlSymsp->TOP.io_Y}
    , io_F{vlSymsp->TOP.io_F}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VMux4to1::VMux4to1(const char* _vcname__)
    : VMux4to1(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VMux4to1::~VMux4to1() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VMux4to1___024root___eval_debug_assertions(VMux4to1___024root* vlSelf);
#endif  // VL_DEBUG
void VMux4to1___024root___eval_static(VMux4to1___024root* vlSelf);
void VMux4to1___024root___eval_initial(VMux4to1___024root* vlSelf);
void VMux4to1___024root___eval_settle(VMux4to1___024root* vlSelf);
void VMux4to1___024root___eval(VMux4to1___024root* vlSelf);

void VMux4to1::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMux4to1::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VMux4to1___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VMux4to1___024root___eval_static(&(vlSymsp->TOP));
        VMux4to1___024root___eval_initial(&(vlSymsp->TOP));
        VMux4to1___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VMux4to1___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VMux4to1::eventsPending() { return false; }

uint64_t VMux4to1::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VMux4to1::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VMux4to1___024root___eval_final(VMux4to1___024root* vlSelf);

VL_ATTR_COLD void VMux4to1::final() {
    VMux4to1___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VMux4to1::hierName() const { return vlSymsp->name(); }
const char* VMux4to1::modelName() const { return "VMux4to1"; }
unsigned VMux4to1::threads() const { return 1; }
