// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vaxi_master_tb__pch.h"

//============================================================
// Constructors

Vaxi_master_tb::Vaxi_master_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vaxi_master_tb__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vaxi_master_tb::Vaxi_master_tb(const char* _vcname__)
    : Vaxi_master_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vaxi_master_tb::~Vaxi_master_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vaxi_master_tb___024root___eval_debug_assertions(Vaxi_master_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vaxi_master_tb___024root___eval_static(Vaxi_master_tb___024root* vlSelf);
void Vaxi_master_tb___024root___eval_initial(Vaxi_master_tb___024root* vlSelf);
void Vaxi_master_tb___024root___eval_settle(Vaxi_master_tb___024root* vlSelf);
void Vaxi_master_tb___024root___eval(Vaxi_master_tb___024root* vlSelf);

void Vaxi_master_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vaxi_master_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vaxi_master_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vaxi_master_tb___024root___eval_static(&(vlSymsp->TOP));
        Vaxi_master_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vaxi_master_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vaxi_master_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vaxi_master_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vaxi_master_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vaxi_master_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vaxi_master_tb___024root___eval_final(Vaxi_master_tb___024root* vlSelf);

VL_ATTR_COLD void Vaxi_master_tb::final() {
    Vaxi_master_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vaxi_master_tb::hierName() const { return vlSymsp->name(); }
const char* Vaxi_master_tb::modelName() const { return "Vaxi_master_tb"; }
unsigned Vaxi_master_tb::threads() const { return 1; }
void Vaxi_master_tb::prepareClone() const { contextp()->prepareClone(); }
void Vaxi_master_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vaxi_master_tb::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vaxi_master_tb::trace()' called on model that was Verilated without --trace option");
}
