// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadd1.h"
#include "Vadd1__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vadd1::Vadd1(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadd1__Syms(contextp(), _vcname__, this)}
    , a_i{vlSymsp->TOP.a_i}
    , b_i{vlSymsp->TOP.b_i}
    , c_i{vlSymsp->TOP.c_i}
    , s_i{vlSymsp->TOP.s_i}
    , c_o{vlSymsp->TOP.c_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vadd1::Vadd1(const char* _vcname__)
    : Vadd1(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadd1::~Vadd1() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadd1___024root___eval_debug_assertions(Vadd1___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd1___024root___eval_static(Vadd1___024root* vlSelf);
void Vadd1___024root___eval_initial(Vadd1___024root* vlSelf);
void Vadd1___024root___eval_settle(Vadd1___024root* vlSelf);
void Vadd1___024root___eval(Vadd1___024root* vlSelf);

void Vadd1::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadd1::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadd1___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadd1___024root___eval_static(&(vlSymsp->TOP));
        Vadd1___024root___eval_initial(&(vlSymsp->TOP));
        Vadd1___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadd1___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vadd1::eventsPending() { return false; }

uint64_t Vadd1::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vadd1::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadd1___024root___eval_final(Vadd1___024root* vlSelf);

VL_ATTR_COLD void Vadd1::final() {
    Vadd1___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadd1::hierName() const { return vlSymsp->name(); }
const char* Vadd1::modelName() const { return "Vadd1"; }
unsigned Vadd1::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vadd1::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vadd1___024root__trace_init_top(Vadd1___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vadd1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd1___024root*>(voidSelf);
    Vadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vadd1___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vadd1___024root__trace_register(Vadd1___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadd1::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vadd1::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vadd1___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
