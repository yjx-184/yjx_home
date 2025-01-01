// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vhello_top.h"
#include "Vhello_top__Syms.h"

//============================================================
// Constructors

Vhello_top::Vhello_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vhello_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , sw{vlSymsp->TOP.sw}
    , led{vlSymsp->TOP.led}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vhello_top::Vhello_top(const char* _vcname__)
    : Vhello_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vhello_top::~Vhello_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vhello_top___024root___eval_debug_assertions(Vhello_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vhello_top___024root___eval_static(Vhello_top___024root* vlSelf);
void Vhello_top___024root___eval_initial(Vhello_top___024root* vlSelf);
void Vhello_top___024root___eval_settle(Vhello_top___024root* vlSelf);
void Vhello_top___024root___eval(Vhello_top___024root* vlSelf);

void Vhello_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vhello_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vhello_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vhello_top___024root___eval_static(&(vlSymsp->TOP));
        Vhello_top___024root___eval_initial(&(vlSymsp->TOP));
        Vhello_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vhello_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vhello_top::eventsPending() { return false; }

uint64_t Vhello_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vhello_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vhello_top___024root___eval_final(Vhello_top___024root* vlSelf);

VL_ATTR_COLD void Vhello_top::final() {
    Vhello_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vhello_top::hierName() const { return vlSymsp->name(); }
const char* Vhello_top::modelName() const { return "Vhello_top"; }
unsigned Vhello_top::threads() const { return 1; }
