// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi_master_tb.h for the primary calling header

#include "Vaxi_master_tb__pch.h"
#include "Vaxi_master_tb___024root.h"

VL_ATTR_COLD void Vaxi_master_tb___024root___eval_static__TOP(Vaxi_master_tb___024root* vlSelf);

VL_ATTR_COLD void Vaxi_master_tb___024root___eval_static(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_static\n"); );
    // Body
    Vaxi_master_tb___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vaxi_master_tb___024root___eval_static__TOP(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->axi_master_tb__DOT__clk = 0U;
    vlSelf->axi_master_tb__DOT__rst = 1U;
    vlSelf->axi_master_tb__DOT__ic_ren = 0U;
    vlSelf->axi_master_tb__DOT__ic_raddr = 0U;
    vlSelf->axi_master_tb__DOT__dc_wen = 0U;
    vlSelf->axi_master_tb__DOT__dc_waddr = 0U;
    vlSelf->axi_master_tb__DOT__dc_ren = 0U;
    vlSelf->axi_master_tb__DOT__dc_raddr = 0U;
    vlSelf->axi_master_tb__DOT__awready = 0U;
    vlSelf->axi_master_tb__DOT__wready = 0U;
    vlSelf->axi_master_tb__DOT__bvalid = 0U;
    vlSelf->axi_master_tb__DOT__arready = 0U;
    vlSelf->axi_master_tb__DOT__rdata = 0U;
    vlSelf->axi_master_tb__DOT__rlast = 0U;
    vlSelf->axi_master_tb__DOT__rvalid = 0U;
}

VL_ATTR_COLD void Vaxi_master_tb___024root___eval_final(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi_master_tb___024root___dump_triggers__stl(Vaxi_master_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vaxi_master_tb___024root___eval_phase__stl(Vaxi_master_tb___024root* vlSelf);

VL_ATTR_COLD void Vaxi_master_tb___024root___eval_settle(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vaxi_master_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("axi_master_tb.sv", 6, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vaxi_master_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi_master_tb___024root___dump_triggers__stl(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vaxi_master_tb___024root___act_comb__TOP__0(Vaxi_master_tb___024root* vlSelf);

VL_ATTR_COLD void Vaxi_master_tb___024root___eval_stl(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vaxi_master_tb___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vaxi_master_tb___024root___eval_triggers__stl(Vaxi_master_tb___024root* vlSelf);

VL_ATTR_COLD bool Vaxi_master_tb___024root___eval_phase__stl(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vaxi_master_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vaxi_master_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi_master_tb___024root___dump_triggers__act(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge axi_master_tb.clk or posedge axi_master_tb.rst)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge axi_master_tb.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge axi_master_tb.clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([changed] axi_master_tb.dc_rrdy)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([changed] axi_master_tb.arvalid)\n");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @([changed] axi_master_tb.rready)\n");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @([changed] axi_master_tb.dc_rvalid)\n");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @([changed] axi_master_tb.ic_rrdy)\n");
    }
    if ((0x100ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @([changed] axi_master_tb.ic_rvalid)\n");
    }
    if ((0x200ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @([changed] (2'h0 == axi_master_tb.dut.w_state))\n");
    }
    if ((0x400ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 10 is active: @([changed] (axi_master_tb.awvalid & axi_master_tb.wvalid))\n");
    }
    if ((0x800ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 11 is active: @([changed] axi_master_tb.bready)\n");
    }
    if ((0x1000ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 12 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi_master_tb___024root___dump_triggers__nba(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge axi_master_tb.clk or posedge axi_master_tb.rst)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge axi_master_tb.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge axi_master_tb.clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([changed] axi_master_tb.dc_rrdy)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([changed] axi_master_tb.arvalid)\n");
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @([changed] axi_master_tb.rready)\n");
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @([changed] axi_master_tb.dc_rvalid)\n");
    }
    if ((0x80ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @([changed] axi_master_tb.ic_rrdy)\n");
    }
    if ((0x100ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @([changed] axi_master_tb.ic_rvalid)\n");
    }
    if ((0x200ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @([changed] (2'h0 == axi_master_tb.dut.w_state))\n");
    }
    if ((0x400ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 10 is active: @([changed] (axi_master_tb.awvalid & axi_master_tb.wvalid))\n");
    }
    if ((0x800ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 11 is active: @([changed] axi_master_tb.bready)\n");
    }
    if ((0x1000ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 12 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vaxi_master_tb___024root___ctor_var_reset(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->axi_master_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__ic_rrdy = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__ic_ren = VL_RAND_RESET_I(4);
    vlSelf->axi_master_tb__DOT__ic_raddr = VL_RAND_RESET_I(32);
    vlSelf->axi_master_tb__DOT__ic_rvalid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->axi_master_tb__DOT__ic_rdata);
    vlSelf->axi_master_tb__DOT__dc_wen = VL_RAND_RESET_I(4);
    vlSelf->axi_master_tb__DOT__dc_waddr = VL_RAND_RESET_I(32);
    vlSelf->axi_master_tb__DOT__dc_rrdy = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__dc_ren = VL_RAND_RESET_I(4);
    vlSelf->axi_master_tb__DOT__dc_raddr = VL_RAND_RESET_I(32);
    vlSelf->axi_master_tb__DOT__dc_rvalid = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->axi_master_tb__DOT__dc_rdata);
    vlSelf->axi_master_tb__DOT__awaddr = VL_RAND_RESET_I(32);
    vlSelf->axi_master_tb__DOT__awlen = VL_RAND_RESET_I(8);
    vlSelf->axi_master_tb__DOT__awvalid = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__awready = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__wstrb = VL_RAND_RESET_I(4);
    vlSelf->axi_master_tb__DOT__wvalid = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__wready = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__bready = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__bvalid = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__araddr = VL_RAND_RESET_I(32);
    vlSelf->axi_master_tb__DOT__arlen = VL_RAND_RESET_I(8);
    vlSelf->axi_master_tb__DOT__arsize = VL_RAND_RESET_I(3);
    vlSelf->axi_master_tb__DOT__arburst = VL_RAND_RESET_I(2);
    vlSelf->axi_master_tb__DOT__arvalid = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__arready = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__rready = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->axi_master_tb__DOT__rlast = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__rvalid = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__dut__DOT__r_state = VL_RAND_RESET_I(2);
    vlSelf->axi_master_tb__DOT__dut__DOT__r_next = VL_RAND_RESET_I(2);
    vlSelf->axi_master_tb__DOT__dut__DOT__w_state = VL_RAND_RESET_I(2);
    vlSelf->axi_master_tb__DOT__dut__DOT__w_next = VL_RAND_RESET_I(2);
    vlSelf->axi_master_tb__DOT__dut__DOT__read_from_dc = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__dut__DOT__read_turn_dc = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__dut__DOT__read_beat = VL_RAND_RESET_I(8);
    vlSelf->axi_master_tb__DOT__dut__DOT__aw_done = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__dut__DOT__w_done = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__dut__DOT__read_last = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__dut__DOT__aw_fire = VL_RAND_RESET_I(1);
    vlSelf->axi_master_tb__DOT__dut__DOT__w_fire = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__dc_rrdy__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__arvalid__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__rready__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__dc_rvalid__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__ic_rrdy__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__ic_rvalid__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_h8b0285bd__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_h56371ac2__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__bready__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}
