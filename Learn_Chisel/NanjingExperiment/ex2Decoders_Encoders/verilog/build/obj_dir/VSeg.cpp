// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSeg.h"
#include "VSeg__Syms.h"

//============================================================
// Constructors

VSeg::VSeg(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VSeg__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_in{vlSymsp->TOP.io_in}
    , io_sel{vlSymsp->TOP.io_sel}
    , io_out{vlSymsp->TOP.io_out}
    , io_seg{vlSymsp->TOP.io_seg}
    , io_valid{vlSymsp->TOP.io_valid}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VSeg::VSeg(const char* _vcname__)
    : VSeg(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VSeg::~VSeg() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VSeg___024root___eval_debug_assertions(VSeg___024root* vlSelf);
#endif  // VL_DEBUG
void VSeg___024root___eval_static(VSeg___024root* vlSelf);
void VSeg___024root___eval_initial(VSeg___024root* vlSelf);
void VSeg___024root___eval_settle(VSeg___024root* vlSelf);
void VSeg___024root___eval(VSeg___024root* vlSelf);

void VSeg::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSeg::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSeg___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VSeg___024root___eval_static(&(vlSymsp->TOP));
        VSeg___024root___eval_initial(&(vlSymsp->TOP));
        VSeg___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VSeg___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VSeg::eventsPending() { return false; }

uint64_t VSeg::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VSeg::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VSeg___024root___eval_final(VSeg___024root* vlSelf);

VL_ATTR_COLD void VSeg::final() {
    VSeg___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VSeg::hierName() const { return vlSymsp->name(); }
const char* VSeg::modelName() const { return "VSeg"; }
unsigned VSeg::threads() const { return 1; }
