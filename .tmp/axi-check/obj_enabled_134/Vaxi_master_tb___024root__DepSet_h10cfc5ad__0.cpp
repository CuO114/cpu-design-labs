// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi_master_tb.h for the primary calling header

#include "Vaxi_master_tb__pch.h"
#include "Vaxi_master_tb___024root.h"

VlCoroutine Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__0(Vaxi_master_tb___024root* vlSelf);
VlCoroutine Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__1(Vaxi_master_tb___024root* vlSelf);
VlCoroutine Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__2(Vaxi_master_tb___024root* vlSelf);

void Vaxi_master_tb___024root___eval_initial(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_initial\n"); );
    // Body
    Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__clk__0 
        = vlSelf->axi_master_tb__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__rst__0 
        = vlSelf->axi_master_tb__DOT__rst;
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__dc_rrdy__0 
        = vlSelf->axi_master_tb__DOT__dc_rrdy;
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__arvalid__0 
        = vlSelf->axi_master_tb__DOT__arvalid;
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__rready__0 
        = vlSelf->axi_master_tb__DOT__rready;
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__dc_rvalid__0 
        = vlSelf->axi_master_tb__DOT__dc_rvalid;
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__ic_rrdy__0 
        = vlSelf->axi_master_tb__DOT__ic_rrdy;
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__ic_rvalid__0 
        = vlSelf->axi_master_tb__DOT__ic_rvalid;
    vlSelf->__Vtrigprevexpr_h8b0285bd__0 = (0U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state));
    vlSelf->__Vtrigprevexpr_h56371ac2__0 = ((IData)(vlSelf->axi_master_tb__DOT__awvalid) 
                                            & (IData)(vlSelf->axi_master_tb__DOT__wvalid));
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__bready__0 
        = vlSelf->axi_master_tb__DOT__bready;
}

VL_INLINE_OPT VlCoroutine Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__2(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "axi_master_tb.sv", 
                                           7);
        vlSelf->axi_master_tb__DOT__clk = (1U & (~ (IData)(vlSelf->axi_master_tb__DOT__clk)));
    }
}

extern const VlUnpacked<CData/*1:0*/, 256> Vaxi_master_tb__ConstPool__TABLE_h71331e0b_0;

VL_INLINE_OPT void Vaxi_master_tb___024root___act_comb__TOP__0(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___act_comb__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->axi_master_tb__DOT__ic_rrdy = 0U;
    vlSelf->axi_master_tb__DOT__dc_rrdy = 0U;
    if ((0U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__r_state))) {
        if ((1U & (~ (IData)((0U != (IData)(vlSelf->axi_master_tb__DOT__dc_ren)))))) {
            if ((0U != (IData)(vlSelf->axi_master_tb__DOT__ic_ren))) {
                vlSelf->axi_master_tb__DOT__ic_rrdy = 1U;
            } else if ((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__read_turn_dc)))) {
                vlSelf->axi_master_tb__DOT__ic_rrdy = 1U;
            }
        }
        if ((0U != (IData)(vlSelf->axi_master_tb__DOT__dc_ren))) {
            vlSelf->axi_master_tb__DOT__dc_rrdy = 1U;
        } else if ((1U & (~ (IData)((0U != (IData)(vlSelf->axi_master_tb__DOT__ic_ren)))))) {
            if (vlSelf->axi_master_tb__DOT__dut__DOT__read_turn_dc) {
                vlSelf->axi_master_tb__DOT__dc_rrdy = 1U;
            }
        }
    }
    vlSelf->axi_master_tb__DOT__dut__DOT__aw_fire = 
        ((IData)(vlSelf->axi_master_tb__DOT__awready) 
         & (IData)(vlSelf->axi_master_tb__DOT__awvalid));
    vlSelf->axi_master_tb__DOT__dut__DOT__w_fire = 
        ((IData)(vlSelf->axi_master_tb__DOT__wready) 
         & (IData)(vlSelf->axi_master_tb__DOT__wvalid));
    vlSelf->axi_master_tb__DOT__dut__DOT__read_last 
        = ((IData)(vlSelf->axi_master_tb__DOT__rlast) 
           | ((IData)(vlSelf->axi_master_tb__DOT__arlen) 
              == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__read_beat)));
    vlSelf->axi_master_tb__DOT__dut__DOT__w_next = 
        ((0U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state))
          ? ((0U != (IData)(vlSelf->axi_master_tb__DOT__dc_wen))
              ? 1U : 0U) : ((1U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state))
                             ? ((((IData)(vlSelf->axi_master_tb__DOT__dut__DOT__aw_done) 
                                  | (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__aw_fire)) 
                                 & ((IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_done) 
                                    | (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_fire)))
                                 ? 2U : 1U) : ((2U 
                                                == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state))
                                                ? (
                                                   ((IData)(vlSelf->axi_master_tb__DOT__bvalid) 
                                                    & (IData)(vlSelf->axi_master_tb__DOT__bready))
                                                    ? 0U
                                                    : 2U)
                                                : 0U)));
    __Vtableidx1 = (((IData)(vlSelf->axi_master_tb__DOT__dut__DOT__read_last) 
                     << 7U) | (((IData)(vlSelf->axi_master_tb__DOT__rready) 
                                << 6U) | (((IData)(vlSelf->axi_master_tb__DOT__rvalid) 
                                           << 5U) | 
                                          (((IData)(vlSelf->axi_master_tb__DOT__arready) 
                                            << 4U) 
                                           | ((((0U 
                                                 != 
                                                 ((IData)(vlSelf->axi_master_tb__DOT__dc_ren) 
                                                  | (IData)(vlSelf->axi_master_tb__DOT__ic_ren)))
                                                 ? 1U
                                                 : 0U) 
                                               << 2U) 
                                              | (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__r_state))))));
    vlSelf->axi_master_tb__DOT__dut__DOT__r_next = 
        Vaxi_master_tb__ConstPool__TABLE_h71331e0b_0
        [__Vtableidx1];
}

void Vaxi_master_tb___024root___eval_act(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_act\n"); );
    // Body
    if ((0xffeULL & vlSelf->__VactTriggered.word(0U))) {
        Vaxi_master_tb___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vaxi_master_tb___024root___nba_sequent__TOP__0(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__axi_master_tb__DOT__dut__DOT__read_from_dc;
    __Vdly__axi_master_tb__DOT__dut__DOT__read_from_dc = 0;
    CData/*0:0*/ __Vdly__axi_master_tb__DOT__dut__DOT__read_turn_dc;
    __Vdly__axi_master_tb__DOT__dut__DOT__read_turn_dc = 0;
    CData/*7:0*/ __Vdly__axi_master_tb__DOT__dut__DOT__read_beat;
    __Vdly__axi_master_tb__DOT__dut__DOT__read_beat = 0;
    CData/*0:0*/ __Vdly__axi_master_tb__DOT__rready;
    __Vdly__axi_master_tb__DOT__rready = 0;
    CData/*0:0*/ __Vdly__axi_master_tb__DOT__dut__DOT__aw_done;
    __Vdly__axi_master_tb__DOT__dut__DOT__aw_done = 0;
    CData/*0:0*/ __Vdly__axi_master_tb__DOT__dut__DOT__w_done;
    __Vdly__axi_master_tb__DOT__dut__DOT__w_done = 0;
    CData/*0:0*/ __Vdly__axi_master_tb__DOT__bready;
    __Vdly__axi_master_tb__DOT__bready = 0;
    // Body
    __Vdly__axi_master_tb__DOT__bready = vlSelf->axi_master_tb__DOT__bready;
    __Vdly__axi_master_tb__DOT__dut__DOT__w_done = vlSelf->axi_master_tb__DOT__dut__DOT__w_done;
    __Vdly__axi_master_tb__DOT__dut__DOT__aw_done = vlSelf->axi_master_tb__DOT__dut__DOT__aw_done;
    __Vdly__axi_master_tb__DOT__dut__DOT__read_from_dc 
        = vlSelf->axi_master_tb__DOT__dut__DOT__read_from_dc;
    __Vdly__axi_master_tb__DOT__rready = vlSelf->axi_master_tb__DOT__rready;
    __Vdly__axi_master_tb__DOT__dut__DOT__read_turn_dc 
        = vlSelf->axi_master_tb__DOT__dut__DOT__read_turn_dc;
    __Vdly__axi_master_tb__DOT__dut__DOT__read_beat 
        = vlSelf->axi_master_tb__DOT__dut__DOT__read_beat;
    if (vlSelf->axi_master_tb__DOT__rst) {
        __Vdly__axi_master_tb__DOT__dut__DOT__aw_done = 0U;
        __Vdly__axi_master_tb__DOT__dut__DOT__w_done = 0U;
        vlSelf->axi_master_tb__DOT__awaddr = 0U;
        vlSelf->axi_master_tb__DOT__awlen = 0U;
        vlSelf->axi_master_tb__DOT__awvalid = 0U;
        vlSelf->axi_master_tb__DOT__wstrb = 0U;
        vlSelf->axi_master_tb__DOT__wvalid = 0U;
        __Vdly__axi_master_tb__DOT__bready = 0U;
        __Vdly__axi_master_tb__DOT__dut__DOT__read_from_dc = 0U;
        __Vdly__axi_master_tb__DOT__dut__DOT__read_turn_dc = 0U;
        __Vdly__axi_master_tb__DOT__dut__DOT__read_beat = 0U;
        vlSelf->axi_master_tb__DOT__ic_rvalid = 0U;
        vlSelf->axi_master_tb__DOT__ic_rdata[0U] = 0U;
        vlSelf->axi_master_tb__DOT__ic_rdata[1U] = 0U;
        vlSelf->axi_master_tb__DOT__ic_rdata[2U] = 0U;
        vlSelf->axi_master_tb__DOT__ic_rdata[3U] = 0U;
        vlSelf->axi_master_tb__DOT__dc_rvalid = 0U;
        vlSelf->axi_master_tb__DOT__dc_rdata[0U] = 0U;
        vlSelf->axi_master_tb__DOT__dc_rdata[1U] = 0U;
        vlSelf->axi_master_tb__DOT__dc_rdata[2U] = 0U;
        vlSelf->axi_master_tb__DOT__dc_rdata[3U] = 0U;
        vlSelf->axi_master_tb__DOT__araddr = 0U;
        vlSelf->axi_master_tb__DOT__arlen = 0U;
        vlSelf->axi_master_tb__DOT__arsize = 2U;
        vlSelf->axi_master_tb__DOT__arburst = 1U;
        vlSelf->axi_master_tb__DOT__arvalid = 0U;
        __Vdly__axi_master_tb__DOT__rready = 0U;
        vlSelf->axi_master_tb__DOT__dut__DOT__w_state = 0U;
        vlSelf->axi_master_tb__DOT__dut__DOT__r_state = 0U;
    } else {
        if ((0U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state))) {
            __Vdly__axi_master_tb__DOT__dut__DOT__aw_done = 0U;
            __Vdly__axi_master_tb__DOT__dut__DOT__w_done = 0U;
            vlSelf->axi_master_tb__DOT__awvalid = 0U;
            __Vdly__axi_master_tb__DOT__bready = 0U;
            vlSelf->axi_master_tb__DOT__wvalid = 0U;
            if ((0U != (IData)(vlSelf->axi_master_tb__DOT__dc_wen))) {
                vlSelf->axi_master_tb__DOT__awaddr 
                    = (0xfffffffcU & vlSelf->axi_master_tb__DOT__dc_waddr);
                vlSelf->axi_master_tb__DOT__awlen = 0U;
                vlSelf->axi_master_tb__DOT__awvalid = 1U;
                vlSelf->axi_master_tb__DOT__wstrb = vlSelf->axi_master_tb__DOT__dc_wen;
                vlSelf->axi_master_tb__DOT__wvalid = 1U;
            }
        } else if ((1U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state))) {
            if ((((IData)(vlSelf->axi_master_tb__DOT__dut__DOT__aw_done) 
                  | (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__aw_fire)) 
                 & ((IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_done) 
                    | (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_fire)))) {
                __Vdly__axi_master_tb__DOT__bready = 1U;
            }
            if (vlSelf->axi_master_tb__DOT__dut__DOT__aw_fire) {
                vlSelf->axi_master_tb__DOT__awvalid = 0U;
                __Vdly__axi_master_tb__DOT__dut__DOT__aw_done = 1U;
            }
            if (vlSelf->axi_master_tb__DOT__dut__DOT__w_fire) {
                vlSelf->axi_master_tb__DOT__wvalid = 0U;
                __Vdly__axi_master_tb__DOT__dut__DOT__w_done = 1U;
            }
        } else if ((2U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state))) {
            if (((IData)(vlSelf->axi_master_tb__DOT__bvalid) 
                 & (IData)(vlSelf->axi_master_tb__DOT__bready))) {
                __Vdly__axi_master_tb__DOT__bready = 0U;
            }
        } else {
            vlSelf->axi_master_tb__DOT__awvalid = 0U;
            vlSelf->axi_master_tb__DOT__wvalid = 0U;
            __Vdly__axi_master_tb__DOT__bready = 0U;
        }
        vlSelf->axi_master_tb__DOT__ic_rvalid = 0U;
        vlSelf->axi_master_tb__DOT__dc_rvalid = 0U;
        if ((0U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__r_state))) {
            vlSelf->axi_master_tb__DOT__arvalid = 0U;
            __Vdly__axi_master_tb__DOT__rready = 0U;
            __Vdly__axi_master_tb__DOT__dut__DOT__read_beat = 0U;
            if ((0U != (IData)(vlSelf->axi_master_tb__DOT__dc_ren))) {
                __Vdly__axi_master_tb__DOT__dut__DOT__read_from_dc = 1U;
                __Vdly__axi_master_tb__DOT__dut__DOT__read_turn_dc = 0U;
                if ((0xffffU != (vlSelf->axi_master_tb__DOT__dc_raddr 
                                 >> 0x10U))) {
                    vlSelf->axi_master_tb__DOT__araddr 
                        = (0xfffffff0U & vlSelf->axi_master_tb__DOT__dc_raddr);
                    vlSelf->axi_master_tb__DOT__arlen = 3U;
                } else {
                    vlSelf->axi_master_tb__DOT__araddr 
                        = (0xfffffffcU & vlSelf->axi_master_tb__DOT__dc_raddr);
                    vlSelf->axi_master_tb__DOT__arlen = 0U;
                }
                vlSelf->axi_master_tb__DOT__arsize = 2U;
                vlSelf->axi_master_tb__DOT__arburst = 1U;
                vlSelf->axi_master_tb__DOT__arvalid = 1U;
                vlSelf->axi_master_tb__DOT__dc_rdata[0U] = 0U;
                vlSelf->axi_master_tb__DOT__dc_rdata[1U] = 0U;
                vlSelf->axi_master_tb__DOT__dc_rdata[2U] = 0U;
                vlSelf->axi_master_tb__DOT__dc_rdata[3U] = 0U;
            } else if ((0U != (IData)(vlSelf->axi_master_tb__DOT__ic_ren))) {
                __Vdly__axi_master_tb__DOT__dut__DOT__read_from_dc = 0U;
                __Vdly__axi_master_tb__DOT__dut__DOT__read_turn_dc = 1U;
                vlSelf->axi_master_tb__DOT__araddr 
                    = (0xfffffff0U & vlSelf->axi_master_tb__DOT__ic_raddr);
                vlSelf->axi_master_tb__DOT__arlen = 3U;
                vlSelf->axi_master_tb__DOT__arsize = 2U;
                vlSelf->axi_master_tb__DOT__arburst = 1U;
                vlSelf->axi_master_tb__DOT__arvalid = 1U;
                vlSelf->axi_master_tb__DOT__ic_rdata[0U] = 0U;
                vlSelf->axi_master_tb__DOT__ic_rdata[1U] = 0U;
                vlSelf->axi_master_tb__DOT__ic_rdata[2U] = 0U;
                vlSelf->axi_master_tb__DOT__ic_rdata[3U] = 0U;
            } else {
                __Vdly__axi_master_tb__DOT__dut__DOT__read_turn_dc 
                    = (1U & (~ (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__read_turn_dc)));
            }
        } else if ((1U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__r_state))) {
            if (vlSelf->axi_master_tb__DOT__arready) {
                vlSelf->axi_master_tb__DOT__arvalid = 0U;
                __Vdly__axi_master_tb__DOT__rready = 1U;
            }
        } else if ((2U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__r_state))) {
            if (((IData)(vlSelf->axi_master_tb__DOT__rvalid) 
                 & (IData)(vlSelf->axi_master_tb__DOT__rready))) {
                if (vlSelf->axi_master_tb__DOT__dut__DOT__read_from_dc) {
                    VL_ASSIGNSEL_WI(128,32,(0x7fU & 
                                            VL_SHIFTL_III(7,32,32, (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__read_beat), 5U)), vlSelf->axi_master_tb__DOT__dc_rdata, vlSelf->axi_master_tb__DOT__rdata);
                } else {
                    VL_ASSIGNSEL_WI(128,32,(0x7fU & 
                                            VL_SHIFTL_III(7,32,32, (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__read_beat), 5U)), vlSelf->axi_master_tb__DOT__ic_rdata, vlSelf->axi_master_tb__DOT__rdata);
                }
                if (vlSelf->axi_master_tb__DOT__dut__DOT__read_last) {
                    __Vdly__axi_master_tb__DOT__rready = 0U;
                    if (vlSelf->axi_master_tb__DOT__dut__DOT__read_from_dc) {
                        vlSelf->axi_master_tb__DOT__dc_rvalid = 1U;
                    } else {
                        vlSelf->axi_master_tb__DOT__ic_rvalid = 1U;
                    }
                } else {
                    __Vdly__axi_master_tb__DOT__dut__DOT__read_beat 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__read_beat)));
                }
            }
        } else {
            vlSelf->axi_master_tb__DOT__arvalid = 0U;
            __Vdly__axi_master_tb__DOT__rready = 0U;
        }
        vlSelf->axi_master_tb__DOT__dut__DOT__w_state 
            = vlSelf->axi_master_tb__DOT__dut__DOT__w_next;
        vlSelf->axi_master_tb__DOT__dut__DOT__r_state 
            = vlSelf->axi_master_tb__DOT__dut__DOT__r_next;
    }
    vlSelf->axi_master_tb__DOT__dut__DOT__aw_done = __Vdly__axi_master_tb__DOT__dut__DOT__aw_done;
    vlSelf->axi_master_tb__DOT__dut__DOT__w_done = __Vdly__axi_master_tb__DOT__dut__DOT__w_done;
    vlSelf->axi_master_tb__DOT__bready = __Vdly__axi_master_tb__DOT__bready;
    vlSelf->axi_master_tb__DOT__dut__DOT__read_from_dc 
        = __Vdly__axi_master_tb__DOT__dut__DOT__read_from_dc;
    vlSelf->axi_master_tb__DOT__dut__DOT__read_turn_dc 
        = __Vdly__axi_master_tb__DOT__dut__DOT__read_turn_dc;
    vlSelf->axi_master_tb__DOT__rready = __Vdly__axi_master_tb__DOT__rready;
    vlSelf->axi_master_tb__DOT__dut__DOT__read_beat 
        = __Vdly__axi_master_tb__DOT__dut__DOT__read_beat;
}

VL_INLINE_OPT void Vaxi_master_tb___024root___nba_comb__TOP__0(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___nba_comb__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->axi_master_tb__DOT__dut__DOT__aw_fire = 
        ((IData)(vlSelf->axi_master_tb__DOT__awready) 
         & (IData)(vlSelf->axi_master_tb__DOT__awvalid));
    vlSelf->axi_master_tb__DOT__dut__DOT__w_fire = 
        ((IData)(vlSelf->axi_master_tb__DOT__wready) 
         & (IData)(vlSelf->axi_master_tb__DOT__wvalid));
    vlSelf->axi_master_tb__DOT__dut__DOT__read_last 
        = ((IData)(vlSelf->axi_master_tb__DOT__rlast) 
           | ((IData)(vlSelf->axi_master_tb__DOT__arlen) 
              == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__read_beat)));
    vlSelf->axi_master_tb__DOT__ic_rrdy = 0U;
    vlSelf->axi_master_tb__DOT__dc_rrdy = 0U;
    if ((0U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__r_state))) {
        if ((1U & (~ (IData)((0U != (IData)(vlSelf->axi_master_tb__DOT__dc_ren)))))) {
            if ((0U != (IData)(vlSelf->axi_master_tb__DOT__ic_ren))) {
                vlSelf->axi_master_tb__DOT__ic_rrdy = 1U;
            } else if ((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__read_turn_dc)))) {
                vlSelf->axi_master_tb__DOT__ic_rrdy = 1U;
            }
        }
        if ((0U != (IData)(vlSelf->axi_master_tb__DOT__dc_ren))) {
            vlSelf->axi_master_tb__DOT__dc_rrdy = 1U;
        } else if ((1U & (~ (IData)((0U != (IData)(vlSelf->axi_master_tb__DOT__ic_ren)))))) {
            if (vlSelf->axi_master_tb__DOT__dut__DOT__read_turn_dc) {
                vlSelf->axi_master_tb__DOT__dc_rrdy = 1U;
            }
        }
    }
    vlSelf->axi_master_tb__DOT__dut__DOT__w_next = 
        ((0U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state))
          ? ((0U != (IData)(vlSelf->axi_master_tb__DOT__dc_wen))
              ? 1U : 0U) : ((1U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state))
                             ? ((((IData)(vlSelf->axi_master_tb__DOT__dut__DOT__aw_done) 
                                  | (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__aw_fire)) 
                                 & ((IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_done) 
                                    | (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_fire)))
                                 ? 2U : 1U) : ((2U 
                                                == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state))
                                                ? (
                                                   ((IData)(vlSelf->axi_master_tb__DOT__bvalid) 
                                                    & (IData)(vlSelf->axi_master_tb__DOT__bready))
                                                    ? 0U
                                                    : 2U)
                                                : 0U)));
    __Vtableidx1 = (((IData)(vlSelf->axi_master_tb__DOT__dut__DOT__read_last) 
                     << 7U) | (((IData)(vlSelf->axi_master_tb__DOT__rready) 
                                << 6U) | (((IData)(vlSelf->axi_master_tb__DOT__rvalid) 
                                           << 5U) | 
                                          (((IData)(vlSelf->axi_master_tb__DOT__arready) 
                                            << 4U) 
                                           | ((((0U 
                                                 != 
                                                 ((IData)(vlSelf->axi_master_tb__DOT__dc_ren) 
                                                  | (IData)(vlSelf->axi_master_tb__DOT__ic_ren)))
                                                 ? 1U
                                                 : 0U) 
                                               << 2U) 
                                              | (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__r_state))))));
    vlSelf->axi_master_tb__DOT__dut__DOT__r_next = 
        Vaxi_master_tb__ConstPool__TABLE_h71331e0b_0
        [__Vtableidx1];
}

void Vaxi_master_tb___024root___eval_nba(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vaxi_master_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0xfffULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vaxi_master_tb___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vaxi_master_tb___024root___timing_resume(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h2fb1e198__0.resume("@(posedge axi_master_tb.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h2fb1e249__0.resume("@(negedge axi_master_tb.clk)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h2a68ac7d__0.resume("@([changed] axi_master_tb.dc_rrdy)");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_he0e7847f__0.resume("@([changed] axi_master_tb.arvalid)");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h0713e9ff__0.resume("@([changed] axi_master_tb.rready)");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h7d977fc6__0.resume("@([changed] axi_master_tb.dc_rvalid)");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_he2e3d6bd__0.resume("@([changed] axi_master_tb.ic_rrdy)");
    }
    if ((0x100ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hb9f91d80__0.resume("@([changed] axi_master_tb.ic_rvalid)");
    }
    if ((0x200ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h1ab5b9cb__0.resume("@([changed] (2'h0 == axi_master_tb.dut.w_state))");
    }
    if ((0x400ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hd2015520__0.resume("@([changed] (axi_master_tb.awvalid & axi_master_tb.wvalid))");
    }
    if ((0x800ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h001289fd__0.resume("@([changed] axi_master_tb.bready)");
    }
    if ((0x1000ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vaxi_master_tb___024root___timing_commit(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h2fb1e198__0.commit("@(posedge axi_master_tb.clk)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h2fb1e249__0.commit("@(negedge axi_master_tb.clk)");
    }
    if ((! (8ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h2a68ac7d__0.commit("@([changed] axi_master_tb.dc_rrdy)");
    }
    if ((! (0x10ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_he0e7847f__0.commit("@([changed] axi_master_tb.arvalid)");
    }
    if ((! (0x20ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h0713e9ff__0.commit("@([changed] axi_master_tb.rready)");
    }
    if ((! (0x40ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h7d977fc6__0.commit("@([changed] axi_master_tb.dc_rvalid)");
    }
    if ((! (0x80ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_he2e3d6bd__0.commit("@([changed] axi_master_tb.ic_rrdy)");
    }
    if ((! (0x100ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hb9f91d80__0.commit("@([changed] axi_master_tb.ic_rvalid)");
    }
    if ((! (0x200ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h1ab5b9cb__0.commit("@([changed] (2'h0 == axi_master_tb.dut.w_state))");
    }
    if ((! (0x400ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hd2015520__0.commit("@([changed] (axi_master_tb.awvalid & axi_master_tb.wvalid))");
    }
    if ((! (0x800ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h001289fd__0.commit("@([changed] axi_master_tb.bready)");
    }
}

void Vaxi_master_tb___024root___eval_triggers__act(Vaxi_master_tb___024root* vlSelf);

bool Vaxi_master_tb___024root___eval_phase__act(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<13> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vaxi_master_tb___024root___eval_triggers__act(vlSelf);
    Vaxi_master_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vaxi_master_tb___024root___timing_resume(vlSelf);
        Vaxi_master_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vaxi_master_tb___024root___eval_phase__nba(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vaxi_master_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi_master_tb___024root___dump_triggers__nba(Vaxi_master_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi_master_tb___024root___dump_triggers__act(Vaxi_master_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vaxi_master_tb___024root___eval(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vaxi_master_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("axi_master_tb.sv", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vaxi_master_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("axi_master_tb.sv", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vaxi_master_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vaxi_master_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vaxi_master_tb___024root___eval_debug_assertions(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
