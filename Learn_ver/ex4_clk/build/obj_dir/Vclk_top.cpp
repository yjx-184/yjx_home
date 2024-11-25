// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vclk_top.h"
#include "Vclk_top__Syms.h"

//============================================================
// Constructors

Vclk_top::Vclk_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vclk_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , sta{vlSymsp->TOP.sta}
    , seg_tens{vlSymsp->TOP.seg_tens}
    , seg_units{vlSymsp->TOP.seg_units}
    , led_o{vlSymsp->TOP.led_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vclk_top::Vclk_top(const char* _vcname__)
    : Vclk_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vclk_top::~Vclk_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vclk_top___024root___eval_debug_assertions(Vclk_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vclk_top___024root___eval_static(Vclk_top___024root* vlSelf);
void Vclk_top___024root___eval_initial(Vclk_top___024root* vlSelf);
void Vclk_top___024root___eval_settle(Vclk_top___024root* vlSelf);
void Vclk_top___024root___eval(Vclk_top___024root* vlSelf);

void Vclk_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vclk_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vclk_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vclk_top___024root___eval_static(&(vlSymsp->TOP));
        Vclk_top___024root___eval_initial(&(vlSymsp->TOP));
        Vclk_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vclk_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vclk_top::eventsPending() { return false; }

uint64_t Vclk_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vclk_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vclk_top___024root___eval_final(Vclk_top___024root* vlSelf);

VL_ATTR_COLD void Vclk_top::final() {
    Vclk_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vclk_top::hierName() const { return vlSymsp->name(); }
const char* Vclk_top::modelName() const { return "Vclk_top"; }
unsigned Vclk_top::threads() const { return 1; }
