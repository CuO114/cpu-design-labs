// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaxi_master_tb.h for the primary calling header

#include "Vaxi_master_tb__pch.h"
#include "Vaxi_master_tb__Syms.h"
#include "Vaxi_master_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__0(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ __Vtask_axi_master_tb__DOT__send_read_data__0__base;
    __Vtask_axi_master_tb__DOT__send_read_data__0__base = 0;
    IData/*31:0*/ __Vtask_axi_master_tb__DOT__send_read_data__1__base;
    __Vtask_axi_master_tb__DOT__send_read_data__1__base = 0;
    // Body
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       93);
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       93);
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       93);
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       94);
    vlSelf->axi_master_tb__DOT__rst = 0U;
    vlSelf->axi_master_tb__DOT__dc_raddr = 0x20cU;
    vlSelf->axi_master_tb__DOT__ic_raddr = 0x100U;
    vlSelf->axi_master_tb__DOT__dc_ren = 0xfU;
    vlSelf->axi_master_tb__DOT__ic_ren = 0xfU;
    while ((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__dc_rrdy)))) {
        co_await vlSelf->__VtrigSched_h2a68ac7d__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] axi_master_tb.dc_rrdy)", 
                                                           "axi_master_tb.sv", 
                                                           102);
    }
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       103);
    vlSelf->axi_master_tb__DOT__dc_ren = 0U;
    while ((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__arvalid)))) {
        co_await vlSelf->__VtrigSched_he0e7847f__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] axi_master_tb.arvalid)", 
                                                           "axi_master_tb.sv", 
                                                           106);
    }
    if (VL_UNLIKELY(((((0x20cU != vlSelf->axi_master_tb__DOT__araddr) 
                       | (3U != (IData)(vlSelf->axi_master_tb__DOT__arlen))) 
                      | (2U != (IData)(vlSelf->axi_master_tb__DOT__arsize))) 
                     | (1U != (IData)(vlSelf->axi_master_tb__DOT__arburst))))) {
        VL_WRITEF("[%0t] %%Fatal: axi_master_tb.sv:108: Assertion failed in %Naxi_master_tb: bad DCache AR request\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("axi_master_tb.sv", 108, "");
    }
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       109);
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       109);
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__arvalid))))) {
        VL_WRITEF("[%0t] %%Fatal: axi_master_tb.sv:110: Assertion failed in %Naxi_master_tb: ARVALID did not wait for ARREADY\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("axi_master_tb.sv", 110, "");
    }
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       111);
    vlSelf->axi_master_tb__DOT__arready = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       113);
    vlSelf->axi_master_tb__DOT__arready = 0U;
    __Vtask_axi_master_tb__DOT__send_read_data__0__base = 0xd0000000U;
    while ((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__rready)))) {
        co_await vlSelf->__VtrigSched_h0713e9ff__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] axi_master_tb.rready)", 
                                                           "axi_master_tb.sv", 
                                                           78);
    }
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       80);
    vlSelf->axi_master_tb__DOT__rdata = __Vtask_axi_master_tb__DOT__send_read_data__0__base;
    vlSelf->axi_master_tb__DOT__rlast = 0U;
    vlSelf->axi_master_tb__DOT__rvalid = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       80);
    vlSelf->axi_master_tb__DOT__rdata = ((IData)(1U) 
                                         + __Vtask_axi_master_tb__DOT__send_read_data__0__base);
    vlSelf->axi_master_tb__DOT__rlast = 0U;
    vlSelf->axi_master_tb__DOT__rvalid = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       80);
    vlSelf->axi_master_tb__DOT__rdata = ((IData)(2U) 
                                         + __Vtask_axi_master_tb__DOT__send_read_data__0__base);
    vlSelf->axi_master_tb__DOT__rlast = 0U;
    vlSelf->axi_master_tb__DOT__rvalid = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       80);
    vlSelf->axi_master_tb__DOT__rdata = ((IData)(3U) 
                                         + __Vtask_axi_master_tb__DOT__send_read_data__0__base);
    vlSelf->axi_master_tb__DOT__rlast = 1U;
    vlSelf->axi_master_tb__DOT__rvalid = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       86);
    vlSelf->axi_master_tb__DOT__rvalid = 0U;
    vlSelf->axi_master_tb__DOT__rlast = 0U;
    while ((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__dc_rvalid)))) {
        co_await vlSelf->__VtrigSched_h7d977fc6__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] axi_master_tb.dc_rvalid)", 
                                                           "axi_master_tb.sv", 
                                                           116);
    }
    if (VL_UNLIKELY((0U != ((((0xd0000000U ^ vlSelf->axi_master_tb__DOT__dc_rdata[0U]) 
                              | (0xd0000001U ^ vlSelf->axi_master_tb__DOT__dc_rdata[1U])) 
                             | (0xd0000002U ^ vlSelf->axi_master_tb__DOT__dc_rdata[2U])) 
                            | (0xd0000003U ^ vlSelf->axi_master_tb__DOT__dc_rdata[3U]))))) {
        VL_WRITEF("[%0t] %%Fatal: axi_master_tb.sv:122: Assertion failed in %Naxi_master_tb: DCache burst assembly failed\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("axi_master_tb.sv", 122, "");
    }
    while ((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__ic_rrdy)))) {
        co_await vlSelf->__VtrigSched_he2e3d6bd__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] axi_master_tb.ic_rrdy)", 
                                                           "axi_master_tb.sv", 
                                                           124);
    }
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       125);
    vlSelf->axi_master_tb__DOT__ic_ren = 0U;
    while ((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__arvalid)))) {
        co_await vlSelf->__VtrigSched_he0e7847f__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] axi_master_tb.arvalid)", 
                                                           "axi_master_tb.sv", 
                                                           127);
    }
    if (VL_UNLIKELY(((0x100U != vlSelf->axi_master_tb__DOT__araddr) 
                     | (3U != (IData)(vlSelf->axi_master_tb__DOT__arlen))))) {
        VL_WRITEF("[%0t] %%Fatal: axi_master_tb.sv:129: Assertion failed in %Naxi_master_tb: bad ICache AR request\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("axi_master_tb.sv", 129, "");
    }
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       130);
    vlSelf->axi_master_tb__DOT__arready = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       132);
    vlSelf->axi_master_tb__DOT__arready = 0U;
    __Vtask_axi_master_tb__DOT__send_read_data__1__base = 0x10000000U;
    while ((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__rready)))) {
        co_await vlSelf->__VtrigSched_h0713e9ff__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] axi_master_tb.rready)", 
                                                           "axi_master_tb.sv", 
                                                           78);
    }
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       80);
    vlSelf->axi_master_tb__DOT__rdata = __Vtask_axi_master_tb__DOT__send_read_data__1__base;
    vlSelf->axi_master_tb__DOT__rlast = 0U;
    vlSelf->axi_master_tb__DOT__rvalid = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       80);
    vlSelf->axi_master_tb__DOT__rdata = ((IData)(1U) 
                                         + __Vtask_axi_master_tb__DOT__send_read_data__1__base);
    vlSelf->axi_master_tb__DOT__rlast = 0U;
    vlSelf->axi_master_tb__DOT__rvalid = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       80);
    vlSelf->axi_master_tb__DOT__rdata = ((IData)(2U) 
                                         + __Vtask_axi_master_tb__DOT__send_read_data__1__base);
    vlSelf->axi_master_tb__DOT__rlast = 0U;
    vlSelf->axi_master_tb__DOT__rvalid = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       80);
    vlSelf->axi_master_tb__DOT__rdata = ((IData)(3U) 
                                         + __Vtask_axi_master_tb__DOT__send_read_data__1__base);
    vlSelf->axi_master_tb__DOT__rlast = 1U;
    vlSelf->axi_master_tb__DOT__rvalid = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       84);
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       86);
    vlSelf->axi_master_tb__DOT__rvalid = 0U;
    vlSelf->axi_master_tb__DOT__rlast = 0U;
    while ((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__ic_rvalid)))) {
        co_await vlSelf->__VtrigSched_hb9f91d80__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] axi_master_tb.ic_rvalid)", 
                                                           "axi_master_tb.sv", 
                                                           135);
    }
    if (VL_UNLIKELY((0U != ((((0x10000000U ^ vlSelf->axi_master_tb__DOT__ic_rdata[0U]) 
                              | (0x10000001U ^ vlSelf->axi_master_tb__DOT__ic_rdata[1U])) 
                             | (0x10000002U ^ vlSelf->axi_master_tb__DOT__ic_rdata[2U])) 
                            | (0x10000003U ^ vlSelf->axi_master_tb__DOT__ic_rdata[3U]))))) {
        VL_WRITEF("[%0t] %%Fatal: axi_master_tb.sv:141: Assertion failed in %Naxi_master_tb: ICache burst assembly failed\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("axi_master_tb.sv", 141, "");
    }
    while ((0U != (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state))) {
        co_await vlSelf->__VtrigSched_h1ab5b9cb__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (2'h0 == axi_master_tb.dut.w_state))", 
                                                           "axi_master_tb.sv", 
                                                           144);
    }
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       145);
    vlSelf->axi_master_tb__DOT__dc_waddr = 0x303U;
    vlSelf->axi_master_tb__DOT__dc_wen = 8U;
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       149);
    vlSelf->axi_master_tb__DOT__dc_wen = 0U;
    while ((1U & (~ ((IData)(vlSelf->axi_master_tb__DOT__awvalid) 
                     & (IData)(vlSelf->axi_master_tb__DOT__wvalid))))) {
        co_await vlSelf->__VtrigSched_hd2015520__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (axi_master_tb.awvalid & axi_master_tb.wvalid))", 
                                                           "axi_master_tb.sv", 
                                                           151);
    }
    if (VL_UNLIKELY((((0x300U != vlSelf->axi_master_tb__DOT__awaddr) 
                      | (0U != (IData)(vlSelf->axi_master_tb__DOT__awlen))) 
                     | (8U != (IData)(vlSelf->axi_master_tb__DOT__wstrb))))) {
        VL_WRITEF("[%0t] %%Fatal: axi_master_tb.sv:153: Assertion failed in %Naxi_master_tb: bad write request\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("axi_master_tb.sv", 153, "");
    }
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       154);
    vlSelf->axi_master_tb__DOT__wready = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       156);
    vlSelf->axi_master_tb__DOT__wready = 0U;
    if (VL_UNLIKELY((1U & ((~ (IData)(vlSelf->axi_master_tb__DOT__awvalid)) 
                           | (IData)(vlSelf->axi_master_tb__DOT__wvalid))))) {
        VL_WRITEF("[%0t] %%Fatal: axi_master_tb.sv:158: Assertion failed in %Naxi_master_tb: AW/W handshakes are not independent\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("axi_master_tb.sv", 158, "");
    }
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       159);
    co_await vlSelf->__VtrigSched_h2fb1e198__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       159);
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__awvalid))))) {
        VL_WRITEF("[%0t] %%Fatal: axi_master_tb.sv:160: Assertion failed in %Naxi_master_tb: AWVALID did not wait for AWREADY\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("axi_master_tb.sv", 160, "");
    }
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       161);
    vlSelf->axi_master_tb__DOT__awready = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       163);
    vlSelf->axi_master_tb__DOT__awready = 0U;
    while ((1U & (~ (IData)(vlSelf->axi_master_tb__DOT__bready)))) {
        co_await vlSelf->__VtrigSched_h001289fd__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] axi_master_tb.bready)", 
                                                           "axi_master_tb.sv", 
                                                           165);
    }
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       166);
    vlSelf->axi_master_tb__DOT__bvalid = 1U;
    co_await vlSelf->__VtrigSched_h2fb1e249__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge axi_master_tb.clk)", 
                                                       "axi_master_tb.sv", 
                                                       168);
    vlSelf->axi_master_tb__DOT__bvalid = 0U;
    while ((0U != (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state))) {
        co_await vlSelf->__VtrigSched_h1ab5b9cb__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (2'h0 == axi_master_tb.dut.w_state))", 
                                                           "axi_master_tb.sv", 
                                                           170);
    }
    VL_WRITEF("AXI_MASTER_TB_PASS\n");
    VL_FINISH_MT("axi_master_tb.sv", 173, "");
}

VL_INLINE_OPT VlCoroutine Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__1(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x4c4b40ULL, 
                                       nullptr, "axi_master_tb.sv", 
                                       177);
    VL_WRITEF("[%0t] %%Fatal: axi_master_tb.sv:178: Assertion failed in %Naxi_master_tb: timeout\n",
              64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
    VL_STOP_MT("axi_master_tb.sv", 178, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaxi_master_tb___024root___dump_triggers__act(Vaxi_master_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vaxi_master_tb___024root___eval_triggers__act(Vaxi_master_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaxi_master_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaxi_master_tb___024root___eval_triggers__act\n"); );
    // Body
    CData/*0:0*/ __Vtrigcurrexpr_h8b0285bd__0;
    __Vtrigcurrexpr_h8b0285bd__0 = 0;
    CData/*0:0*/ __Vtrigcurrexpr_h56371ac2__0;
    __Vtrigcurrexpr_h56371ac2__0 = 0;
    __Vtrigcurrexpr_h8b0285bd__0 = (0U == (IData)(vlSelf->axi_master_tb__DOT__dut__DOT__w_state));
    __Vtrigcurrexpr_h56371ac2__0 = ((IData)(vlSelf->axi_master_tb__DOT__awvalid) 
                                    & (IData)(vlSelf->axi_master_tb__DOT__wvalid));
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->axi_master_tb__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__clk__0))) 
                                     | ((IData)(vlSelf->axi_master_tb__DOT__rst) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__rst__0)))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->axi_master_tb__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__clk__0))));
    vlSelf->__VactTriggered.set(2U, ((~ (IData)(vlSelf->axi_master_tb__DOT__clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__clk__0)));
    vlSelf->__VactTriggered.set(3U, ((IData)(vlSelf->axi_master_tb__DOT__dc_rrdy) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__dc_rrdy__0)));
    vlSelf->__VactTriggered.set(4U, ((IData)(vlSelf->axi_master_tb__DOT__arvalid) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__arvalid__0)));
    vlSelf->__VactTriggered.set(5U, ((IData)(vlSelf->axi_master_tb__DOT__rready) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__rready__0)));
    vlSelf->__VactTriggered.set(6U, ((IData)(vlSelf->axi_master_tb__DOT__dc_rvalid) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__dc_rvalid__0)));
    vlSelf->__VactTriggered.set(7U, ((IData)(vlSelf->axi_master_tb__DOT__ic_rrdy) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__ic_rrdy__0)));
    vlSelf->__VactTriggered.set(8U, ((IData)(vlSelf->axi_master_tb__DOT__ic_rvalid) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__ic_rvalid__0)));
    vlSelf->__VactTriggered.set(9U, ((IData)(__Vtrigcurrexpr_h8b0285bd__0) 
                                     != (IData)(vlSelf->__Vtrigprevexpr_h8b0285bd__0)));
    vlSelf->__VactTriggered.set(0xaU, ((IData)(__Vtrigcurrexpr_h56371ac2__0) 
                                       != (IData)(vlSelf->__Vtrigprevexpr_h56371ac2__0)));
    vlSelf->__VactTriggered.set(0xbU, ((IData)(vlSelf->axi_master_tb__DOT__bready) 
                                       != (IData)(vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__bready__0)));
    vlSelf->__VactTriggered.set(0xcU, vlSelf->__VdlySched.awaitingCurrentTime());
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
    vlSelf->__Vtrigprevexpr_h8b0285bd__0 = __Vtrigcurrexpr_h8b0285bd__0;
    vlSelf->__Vtrigprevexpr_h56371ac2__0 = __Vtrigcurrexpr_h56371ac2__0;
    vlSelf->__Vtrigprevexpr___TOP__axi_master_tb__DOT__bready__0 
        = vlSelf->axi_master_tb__DOT__bready;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(3U, 1U);
        vlSelf->__VactTriggered.set(4U, 1U);
        vlSelf->__VactTriggered.set(5U, 1U);
        vlSelf->__VactTriggered.set(6U, 1U);
        vlSelf->__VactTriggered.set(7U, 1U);
        vlSelf->__VactTriggered.set(8U, 1U);
        vlSelf->__VactTriggered.set(9U, 1U);
        vlSelf->__VactTriggered.set(0xaU, 1U);
        vlSelf->__VactTriggered.set(0xbU, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vaxi_master_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
