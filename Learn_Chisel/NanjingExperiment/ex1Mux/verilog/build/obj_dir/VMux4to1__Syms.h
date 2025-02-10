// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMUX4TO1__SYMS_H_
#define VERILATED_VMUX4TO1__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VMux4to1.h"

// INCLUDE MODULE CLASSES
#include "VMux4to1___024root.h"

// SYMS CLASS (contains all model state)
class VMux4to1__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VMux4to1* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VMux4to1___024root             TOP;

    // CONSTRUCTORS
    VMux4to1__Syms(VerilatedContext* contextp, const char* namep, VMux4to1* modelp);
    ~VMux4to1__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
