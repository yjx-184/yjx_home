// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSEG__SYMS_H_
#define VERILATED_VSEG__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VSeg.h"

// INCLUDE MODULE CLASSES
#include "VSeg___024root.h"

// SYMS CLASS (contains all model state)
class VSeg__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VSeg* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VSeg___024root                 TOP;

    // CONSTRUCTORS
    VSeg__Syms(VerilatedContext* contextp, const char* namep, VSeg* modelp);
    ~VSeg__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
