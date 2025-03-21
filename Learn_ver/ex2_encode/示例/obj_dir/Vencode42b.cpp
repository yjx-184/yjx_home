// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vencode42b.h"
#include "Vencode42b__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vencode42b::Vencode42b(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vencode42b__Syms(contextp(), _vcname__, this)}
    , en{vlSymsp->TOP.en}
    , x{vlSymsp->TOP.x}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vencode42b::Vencode42b(const char* _vcname__)
    : Vencode42b(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vencode42b::~Vencode42b() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vencode42b___024root___eval_debug_assertions(Vencode42b___024root* vlSelf);
#endif  // VL_DEBUG
void Vencode42b___024root___eval_static(Vencode42b___024root* vlSelf);
void Vencode42b___024root___eval_initial(Vencode42b___024root* vlSelf);
void Vencode42b___024root___eval_settle(Vencode42b___024root* vlSelf);
void Vencode42b___024root___eval(Vencode42b___024root* vlSelf);

void Vencode42b::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vencode42b::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vencode42b___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vencode42b___024root___eval_static(&(vlSymsp->TOP));
        Vencode42b___024root___eval_initial(&(vlSymsp->TOP));
        Vencode42b___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vencode42b___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vencode42b::eventsPending() { return false; }

uint64_t Vencode42b::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vencode42b::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vencode42b___024root___eval_final(Vencode42b___024root* vlSelf);

VL_ATTR_COLD void Vencode42b::final() {
    Vencode42b___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vencode42b::hierName() const { return vlSymsp->name(); }
const char* Vencode42b::modelName() const { return "Vencode42b"; }
unsigned Vencode42b::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vencode42b::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vencode42b___024root__trace_init_top(Vencode42b___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vencode42b___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vencode42b___024root*>(voidSelf);
    Vencode42b__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vencode42b___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vencode42b___024root__trace_register(Vencode42b___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vencode42b::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vencode42b::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vencode42b___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
