// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfsm_mealy.h"
#include "Vfsm_mealy__Syms.h"

//============================================================
// Constructors

Vfsm_mealy::Vfsm_mealy(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfsm_mealy__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , in{vlSymsp->TOP.in}
    , out{vlSymsp->TOP.out}
    , sta{vlSymsp->TOP.sta}
    , btn{vlSymsp->TOP.btn}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vfsm_mealy::Vfsm_mealy(const char* _vcname__)
    : Vfsm_mealy(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfsm_mealy::~Vfsm_mealy() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfsm_mealy___024root___eval_debug_assertions(Vfsm_mealy___024root* vlSelf);
#endif  // VL_DEBUG
void Vfsm_mealy___024root___eval_static(Vfsm_mealy___024root* vlSelf);
void Vfsm_mealy___024root___eval_initial(Vfsm_mealy___024root* vlSelf);
void Vfsm_mealy___024root___eval_settle(Vfsm_mealy___024root* vlSelf);
void Vfsm_mealy___024root___eval(Vfsm_mealy___024root* vlSelf);

void Vfsm_mealy::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfsm_mealy::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfsm_mealy___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfsm_mealy___024root___eval_static(&(vlSymsp->TOP));
        Vfsm_mealy___024root___eval_initial(&(vlSymsp->TOP));
        Vfsm_mealy___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfsm_mealy___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vfsm_mealy::eventsPending() { return false; }

uint64_t Vfsm_mealy::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vfsm_mealy::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfsm_mealy___024root___eval_final(Vfsm_mealy___024root* vlSelf);

VL_ATTR_COLD void Vfsm_mealy::final() {
    Vfsm_mealy___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfsm_mealy::hierName() const { return vlSymsp->name(); }
const char* Vfsm_mealy::modelName() const { return "Vfsm_mealy"; }
unsigned Vfsm_mealy::threads() const { return 1; }
