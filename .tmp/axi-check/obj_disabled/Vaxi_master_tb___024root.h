// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaxi_master_tb.h for the primary calling header

#ifndef VERILATED_VAXI_MASTER_TB___024ROOT_H_
#define VERILATED_VAXI_MASTER_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vaxi_master_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaxi_master_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ axi_master_tb__DOT__clk;
    CData/*0:0*/ axi_master_tb__DOT__rst;
    CData/*0:0*/ axi_master_tb__DOT__ic_rrdy;
    CData/*3:0*/ axi_master_tb__DOT__ic_ren;
    CData/*0:0*/ axi_master_tb__DOT__ic_rvalid;
    CData/*3:0*/ axi_master_tb__DOT__dc_wen;
    CData/*0:0*/ axi_master_tb__DOT__dc_rrdy;
    CData/*3:0*/ axi_master_tb__DOT__dc_ren;
    CData/*0:0*/ axi_master_tb__DOT__dc_rvalid;
    CData/*7:0*/ axi_master_tb__DOT__awlen;
    CData/*0:0*/ axi_master_tb__DOT__awvalid;
    CData/*0:0*/ axi_master_tb__DOT__awready;
    CData/*3:0*/ axi_master_tb__DOT__wstrb;
    CData/*0:0*/ axi_master_tb__DOT__wvalid;
    CData/*0:0*/ axi_master_tb__DOT__wready;
    CData/*0:0*/ axi_master_tb__DOT__bready;
    CData/*0:0*/ axi_master_tb__DOT__bvalid;
    CData/*7:0*/ axi_master_tb__DOT__arlen;
    CData/*2:0*/ axi_master_tb__DOT__arsize;
    CData/*1:0*/ axi_master_tb__DOT__arburst;
    CData/*0:0*/ axi_master_tb__DOT__arvalid;
    CData/*0:0*/ axi_master_tb__DOT__arready;
    CData/*0:0*/ axi_master_tb__DOT__rready;
    CData/*0:0*/ axi_master_tb__DOT__rlast;
    CData/*0:0*/ axi_master_tb__DOT__rvalid;
    CData/*1:0*/ axi_master_tb__DOT__dut__DOT__r_state;
    CData/*1:0*/ axi_master_tb__DOT__dut__DOT__r_next;
    CData/*1:0*/ axi_master_tb__DOT__dut__DOT__w_state;
    CData/*1:0*/ axi_master_tb__DOT__dut__DOT__w_next;
    CData/*0:0*/ axi_master_tb__DOT__dut__DOT__read_from_dc;
    CData/*0:0*/ axi_master_tb__DOT__dut__DOT__read_turn_dc;
    CData/*7:0*/ axi_master_tb__DOT__dut__DOT__read_beat;
    CData/*0:0*/ axi_master_tb__DOT__dut__DOT__aw_done;
    CData/*0:0*/ axi_master_tb__DOT__dut__DOT__w_done;
    CData/*0:0*/ axi_master_tb__DOT__dut__DOT__read_last;
    CData/*0:0*/ axi_master_tb__DOT__dut__DOT__aw_fire;
    CData/*0:0*/ axi_master_tb__DOT__dut__DOT__w_fire;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_master_tb__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_master_tb__DOT__rst__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_master_tb__DOT__dc_rrdy__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_master_tb__DOT__arvalid__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_master_tb__DOT__rready__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_master_tb__DOT__dc_rvalid__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_master_tb__DOT__ic_rrdy__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_master_tb__DOT__ic_rvalid__0;
    CData/*0:0*/ __Vtrigprevexpr_h8b0285bd__0;
    CData/*0:0*/ __Vtrigprevexpr_h56371ac2__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__axi_master_tb__DOT__bready__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ axi_master_tb__DOT__ic_raddr;
    IData/*31:0*/ axi_master_tb__DOT__ic_rdata;
    IData/*31:0*/ axi_master_tb__DOT__dc_waddr;
    IData/*31:0*/ axi_master_tb__DOT__dc_raddr;
    IData/*31:0*/ axi_master_tb__DOT__dc_rdata;
    IData/*31:0*/ axi_master_tb__DOT__awaddr;
    IData/*31:0*/ axi_master_tb__DOT__araddr;
    IData/*31:0*/ axi_master_tb__DOT__rdata;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h2fb1e198__0;
    VlTriggerScheduler __VtrigSched_h2fb1e249__0;
    VlTriggerScheduler __VtrigSched_h2a68ac7d__0;
    VlTriggerScheduler __VtrigSched_he0e7847f__0;
    VlTriggerScheduler __VtrigSched_h0713e9ff__0;
    VlTriggerScheduler __VtrigSched_h7d977fc6__0;
    VlTriggerScheduler __VtrigSched_he2e3d6bd__0;
    VlTriggerScheduler __VtrigSched_hb9f91d80__0;
    VlTriggerScheduler __VtrigSched_h1ab5b9cb__0;
    VlTriggerScheduler __VtrigSched_hd2015520__0;
    VlTriggerScheduler __VtrigSched_h001289fd__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<13> __VactTriggered;
    VlTriggerVec<13> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vaxi_master_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vaxi_master_tb___024root(Vaxi_master_tb__Syms* symsp, const char* v__name);
    ~Vaxi_master_tb___024root();
    VL_UNCOPYABLE(Vaxi_master_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
