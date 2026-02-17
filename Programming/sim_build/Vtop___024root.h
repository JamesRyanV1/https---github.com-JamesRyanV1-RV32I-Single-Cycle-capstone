// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*0:0*/ cpu__DOT__clk;
        CData/*0:0*/ cpu__DOT__rst;
        CData/*3:0*/ cpu__DOT__alu_ctrl;
        CData/*0:0*/ cpu__DOT__reg_write;
        CData/*3:0*/ cpu__DOT__inst_type;
        CData/*2:0*/ cpu__DOT__imm_type;
        CData/*0:0*/ cpu__DOT__memRead;
        CData/*0:0*/ cpu__DOT__memWrite;
        CData/*0:0*/ cpu__DOT__alu_zero;
        CData/*0:0*/ cpu__DOT__alu_last_bit;
        CData/*0:0*/ cpu__DOT__alu_source;
        CData/*4:0*/ cpu__DOT__rs1;
        CData/*4:0*/ cpu__DOT__rs2;
        CData/*6:0*/ cpu__DOT__opcode;
        CData/*2:0*/ cpu__DOT__func3;
        CData/*6:0*/ cpu__DOT__func7;
        CData/*4:0*/ cpu__DOT__rd;
        CData/*0:0*/ cpu__DOT__take_branch;
        CData/*2:0*/ cpu__DOT__pc_source;
        CData/*4:0*/ cpu__DOT__reg_destination;
        CData/*1:0*/ cpu__DOT__register_source;
        CData/*0:0*/ cpu__DOT__override;
        CData/*0:0*/ cpu__DOT__instruction_memory_inst__DOT__clk;
        CData/*0:0*/ cpu__DOT__instruction_memory_inst__DOT__write_enable;
        CData/*0:0*/ cpu__DOT__instruction_memory_inst__DOT__rst_data;
        CData/*0:0*/ cpu__DOT__branch_unit_inst__DOT__clk;
        CData/*0:0*/ cpu__DOT__branch_unit_inst__DOT__rst;
        CData/*2:0*/ cpu__DOT__branch_unit_inst__DOT__cntrl;
        CData/*0:0*/ cpu__DOT__branch_unit_inst__DOT__take_branch;
        CData/*0:0*/ cpu__DOT__pc_inst__DOT__clk;
        CData/*0:0*/ cpu__DOT__pc_inst__DOT__rst;
        CData/*0:0*/ cpu__DOT__pc_inst__DOT__branch;
        CData/*0:0*/ cpu__DOT__pc_inst__DOT__override;
        CData/*0:0*/ cpu__DOT__register_file_inst__DOT__clk;
        CData/*0:0*/ cpu__DOT__register_file_inst__DOT__rst;
        CData/*4:0*/ cpu__DOT__register_file_inst__DOT__rs1;
        CData/*4:0*/ cpu__DOT__register_file_inst__DOT__rs2;
        CData/*4:0*/ cpu__DOT__register_file_inst__DOT__rd;
        CData/*1:0*/ cpu__DOT__register_file_inst__DOT__register_source;
        CData/*0:0*/ cpu__DOT__register_file_inst__DOT__enableWrite;
        CData/*0:0*/ cpu__DOT__data_memory_inst__DOT__clk;
        CData/*0:0*/ cpu__DOT__data_memory_inst__DOT__write_enable;
        CData/*0:0*/ cpu__DOT__data_memory_inst__DOT__rst_data;
        CData/*0:0*/ cpu__DOT__alu_inst__DOT__clk;
        CData/*0:0*/ cpu__DOT__alu_inst__DOT__rst;
        CData/*0:0*/ cpu__DOT__alu_inst__DOT__alu_source;
        CData/*3:0*/ cpu__DOT__alu_inst__DOT__cntrl;
        CData/*0:0*/ cpu__DOT__alu_inst__DOT__zero;
        CData/*0:0*/ cpu__DOT__alu_inst__DOT__last_bit;
        CData/*1:0*/ cpu__DOT__alu_inst__DOT__shift_type;
        CData/*4:0*/ cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shamt;
        CData/*1:0*/ cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_type;
        CData/*3:0*/ cpu__DOT__alu_inst__DOT__logic_inst__DOT__cntrl;
        CData/*6:0*/ cpu__DOT__control_inst__DOT__op;
        CData/*2:0*/ cpu__DOT__control_inst__DOT__func3;
        CData/*6:0*/ cpu__DOT__control_inst__DOT__func7;
        CData/*0:0*/ cpu__DOT__control_inst__DOT__alu_zero;
        CData/*0:0*/ cpu__DOT__control_inst__DOT__alu_last_bit;
        CData/*1:0*/ cpu__DOT__control_inst__DOT__register_source;
        CData/*3:0*/ cpu__DOT__control_inst__DOT__alu_control;
        CData/*2:0*/ cpu__DOT__control_inst__DOT__imm_source;
        CData/*0:0*/ cpu__DOT__control_inst__DOT__mem_read;
    };
    struct {
        CData/*0:0*/ cpu__DOT__control_inst__DOT__mem_write;
        CData/*0:0*/ cpu__DOT__control_inst__DOT__reg_write;
        CData/*0:0*/ cpu__DOT__control_inst__DOT__alu_source;
        CData/*2:0*/ cpu__DOT__control_inst__DOT__pc_source;
        CData/*3:0*/ cpu__DOT__control_inst__DOT__alu_op;
        CData/*0:0*/ cpu__DOT__control_inst__DOT__jalr_override;
        CData/*0:0*/ cpu__DOT__sign_extender_inst__DOT__clk;
        CData/*0:0*/ cpu__DOT__sign_extender_inst__DOT__rst;
        CData/*2:0*/ cpu__DOT__sign_extender_inst__DOT__imm_type;
        CData/*0:0*/ cpu__DOT__decoder_inst__DOT__clk;
        CData/*0:0*/ cpu__DOT__decoder_inst__DOT__rst;
        CData/*3:0*/ cpu__DOT__decoder_inst__DOT__inst_type;
        CData/*4:0*/ cpu__DOT__decoder_inst__DOT__rd;
        CData/*4:0*/ cpu__DOT__decoder_inst__DOT__rs1;
        CData/*4:0*/ cpu__DOT__decoder_inst__DOT__rs2;
        CData/*2:0*/ cpu__DOT__decoder_inst__DOT__func3;
        CData/*6:0*/ cpu__DOT__decoder_inst__DOT__func7;
        CData/*2:0*/ cpu__DOT__decoder_inst__DOT__imm_type;
        CData/*6:0*/ cpu__DOT__decoder_inst__DOT__opcode;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__cpu__DOT__instruction_memory_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__cpu__DOT__pc_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__cpu__DOT__pc_inst__DOT__rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__cpu__DOT__register_file_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__cpu__DOT__data_memory_inst__DOT__clk__0;
        VL_IN(input_data,31,0);
        VL_OUT(cpu_out,31,0);
        IData/*31:0*/ cpu__DOT__input_data;
        IData/*31:0*/ cpu__DOT__cpu_out;
        IData/*31:0*/ cpu__DOT__regData;
        IData/*31:0*/ cpu__DOT__dData;
        IData/*31:0*/ cpu__DOT__data_address;
        IData/*31:0*/ cpu__DOT__regData1;
        IData/*31:0*/ cpu__DOT__regData2;
        IData/*31:0*/ cpu__DOT__alu_result;
        IData/*31:0*/ cpu__DOT__instruction;
        IData/*31:0*/ cpu__DOT__immediate;
        IData/*31:0*/ cpu__DOT__rd_data;
        IData/*31:0*/ cpu__DOT__pc_next;
        IData/*31:0*/ cpu__DOT__instruction_memory_inst__DOT__address;
        IData/*31:0*/ cpu__DOT__instruction_memory_inst__DOT__write_data;
        IData/*31:0*/ cpu__DOT__instruction_memory_inst__DOT__read_data;
        IData/*31:0*/ cpu__DOT__instruction_memory_inst__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ cpu__DOT__instruction_memory_inst__DOT__unnamedblk2__DOT__idx;
        IData/*31:0*/ cpu__DOT__instruction_memory_inst__DOT__unnamedblk3__DOT__idx;
        IData/*31:0*/ cpu__DOT__branch_unit_inst__DOT__d1;
        IData/*31:0*/ cpu__DOT__branch_unit_inst__DOT__d2;
        IData/*31:0*/ cpu__DOT__pc_inst__DOT__offset;
        IData/*31:0*/ cpu__DOT__pc_inst__DOT__rs1;
        IData/*31:0*/ cpu__DOT__pc_inst__DOT__jalr_imm;
        IData/*31:0*/ cpu__DOT__pc_inst__DOT__pc_out;
        IData/*31:0*/ cpu__DOT__pc_inst__DOT__pc;
        IData/*31:0*/ cpu__DOT__pc_inst__DOT__jalr_target;
        IData/*31:0*/ cpu__DOT__register_file_inst__DOT__alu_result;
        IData/*31:0*/ cpu__DOT__register_file_inst__DOT__pc_plus_4;
        IData/*31:0*/ cpu__DOT__register_file_inst__DOT__wd;
        IData/*31:0*/ cpu__DOT__register_file_inst__DOT__rd1;
        IData/*31:0*/ cpu__DOT__register_file_inst__DOT__rd2;
        IData/*31:0*/ cpu__DOT__register_file_inst__DOT__i;
        IData/*31:0*/ cpu__DOT__data_memory_inst__DOT__address;
        IData/*31:0*/ cpu__DOT__data_memory_inst__DOT__write_data;
        IData/*31:0*/ cpu__DOT__data_memory_inst__DOT__read_data;
        IData/*31:0*/ cpu__DOT__data_memory_inst__DOT__unnamedblk1__DOT__i;
    };
    struct {
        IData/*31:0*/ cpu__DOT__data_memory_inst__DOT__unnamedblk2__DOT__idx;
        IData/*31:0*/ cpu__DOT__data_memory_inst__DOT__unnamedblk3__DOT__idx;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__d1;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__immediate;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__rs2;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__alu_output;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__d2;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__add_result;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__shift_result;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__logic_result;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__adder_inst__DOT__a;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__adder_inst__DOT__b;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__adder_inst__DOT__sum;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__shifter_inst__DOT__a;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_result;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__logic_inst__DOT__a;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__logic_inst__DOT__b;
        IData/*31:0*/ cpu__DOT__alu_inst__DOT__logic_inst__DOT__logic_output;
        IData/*31:0*/ cpu__DOT__sign_extender_inst__DOT__inst;
        IData/*31:0*/ cpu__DOT__sign_extender_inst__DOT__ext_imm;
        IData/*31:0*/ cpu__DOT__decoder_inst__DOT__instruction;
        IData/*19:0*/ cpu__DOT__decoder_inst__DOT__immediate;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 16777216> cpu__DOT__instruction_memory_inst__DOT__mem;
        VlUnpacked<IData/*31:0*/, 32> cpu__DOT__register_file_inst__DOT__regs;
        VlUnpacked<IData/*31:0*/, 16777216> cpu__DOT__data_memory_inst__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };
    VlNBACommitQueue<VlUnpacked<IData/*31:0*/, 16777216>, false, IData/*31:0*/, 1> __VdlyCommitQueuecpu__DOT__instruction_memory_inst__DOT__mem;
    VlNBACommitQueue<VlUnpacked<IData/*31:0*/, 32>, false, IData/*31:0*/, 1> __VdlyCommitQueuecpu__DOT__register_file_inst__DOT__regs;
    VlNBACommitQueue<VlUnpacked<IData/*31:0*/, 16777216>, false, IData/*31:0*/, 1> __VdlyCommitQueuecpu__DOT__data_memory_inst__DOT__mem;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ cpu__DOT__instruction_memory_inst__DOT__WORDS = 0x01000000U;
    static constexpr IData/*31:0*/ cpu__DOT__data_memory_inst__DOT__WORDS = 0x01000000U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
