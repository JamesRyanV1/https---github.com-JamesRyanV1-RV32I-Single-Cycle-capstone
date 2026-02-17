// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_cpu);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__alu_inst);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__branch_unit_inst);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__control_inst);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__data_memory_inst);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__decoder_inst);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__instruction_memory_inst);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__pc_inst);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__register_file_inst);
    __Vhier.remove(&__Vscope_cpu, &__Vscope_cpu__sign_extender_inst);
    __Vhier.remove(&__Vscope_cpu__alu_inst, &__Vscope_cpu__alu_inst__adder_inst);
    __Vhier.remove(&__Vscope_cpu__alu_inst, &__Vscope_cpu__alu_inst__logic_inst);
    __Vhier.remove(&__Vscope_cpu__alu_inst, &__Vscope_cpu__alu_inst__shifter_inst);
    __Vhier.remove(&__Vscope_cpu__data_memory_inst, &__Vscope_cpu__data_memory_inst__unnamedblk1);
    __Vhier.remove(&__Vscope_cpu__data_memory_inst, &__Vscope_cpu__data_memory_inst__unnamedblk2);
    __Vhier.remove(&__Vscope_cpu__data_memory_inst, &__Vscope_cpu__data_memory_inst__unnamedblk3);
    __Vhier.remove(&__Vscope_cpu__instruction_memory_inst, &__Vscope_cpu__instruction_memory_inst__unnamedblk1);
    __Vhier.remove(&__Vscope_cpu__instruction_memory_inst, &__Vscope_cpu__instruction_memory_inst__unnamedblk2);
    __Vhier.remove(&__Vscope_cpu__instruction_memory_inst, &__Vscope_cpu__instruction_memory_inst__unnamedblk3);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(318);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_cpu.configure(this, name(), "cpu", "cpu", "cpu", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__alu_inst.configure(this, name(), "cpu.alu_inst", "alu_inst", "alu", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__alu_inst__adder_inst.configure(this, name(), "cpu.alu_inst.adder_inst", "adder_inst", "alu_adder", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__alu_inst__logic_inst.configure(this, name(), "cpu.alu_inst.logic_inst", "logic_inst", "alu_logic", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__alu_inst__shifter_inst.configure(this, name(), "cpu.alu_inst.shifter_inst", "shifter_inst", "alu_shifter", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__branch_unit_inst.configure(this, name(), "cpu.branch_unit_inst", "branch_unit_inst", "branch_unit", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__control_inst.configure(this, name(), "cpu.control_inst", "control_inst", "control", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__data_memory_inst.configure(this, name(), "cpu.data_memory_inst", "data_memory_inst", "dataMemory", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__data_memory_inst__unnamedblk1.configure(this, name(), "cpu.data_memory_inst.unnamedblk1", "unnamedblk1", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_cpu__data_memory_inst__unnamedblk2.configure(this, name(), "cpu.data_memory_inst.unnamedblk2", "unnamedblk2", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_cpu__data_memory_inst__unnamedblk3.configure(this, name(), "cpu.data_memory_inst.unnamedblk3", "unnamedblk3", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_cpu__decoder_inst.configure(this, name(), "cpu.decoder_inst", "decoder_inst", "decoder", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__instruction_memory_inst.configure(this, name(), "cpu.instruction_memory_inst", "instruction_memory_inst", "dataMemory", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__instruction_memory_inst__unnamedblk1.configure(this, name(), "cpu.instruction_memory_inst.unnamedblk1", "unnamedblk1", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_cpu__instruction_memory_inst__unnamedblk2.configure(this, name(), "cpu.instruction_memory_inst.unnamedblk2", "unnamedblk2", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_cpu__instruction_memory_inst__unnamedblk3.configure(this, name(), "cpu.instruction_memory_inst.unnamedblk3", "unnamedblk3", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_cpu__pc_inst.configure(this, name(), "cpu.pc_inst", "pc_inst", "pc", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__register_file_inst.configure(this, name(), "cpu.register_file_inst", "register_file_inst", "registerFile", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cpu__sign_extender_inst.configure(this, name(), "cpu.sign_extender_inst", "sign_extender_inst", "signExtender", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_cpu);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__alu_inst);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__branch_unit_inst);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__control_inst);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__data_memory_inst);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__decoder_inst);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__instruction_memory_inst);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__pc_inst);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__register_file_inst);
    __Vhier.add(&__Vscope_cpu, &__Vscope_cpu__sign_extender_inst);
    __Vhier.add(&__Vscope_cpu__alu_inst, &__Vscope_cpu__alu_inst__adder_inst);
    __Vhier.add(&__Vscope_cpu__alu_inst, &__Vscope_cpu__alu_inst__logic_inst);
    __Vhier.add(&__Vscope_cpu__alu_inst, &__Vscope_cpu__alu_inst__shifter_inst);
    __Vhier.add(&__Vscope_cpu__data_memory_inst, &__Vscope_cpu__data_memory_inst__unnamedblk1);
    __Vhier.add(&__Vscope_cpu__data_memory_inst, &__Vscope_cpu__data_memory_inst__unnamedblk2);
    __Vhier.add(&__Vscope_cpu__data_memory_inst, &__Vscope_cpu__data_memory_inst__unnamedblk3);
    __Vhier.add(&__Vscope_cpu__instruction_memory_inst, &__Vscope_cpu__instruction_memory_inst__unnamedblk1);
    __Vhier.add(&__Vscope_cpu__instruction_memory_inst, &__Vscope_cpu__instruction_memory_inst__unnamedblk2);
    __Vhier.add(&__Vscope_cpu__instruction_memory_inst, &__Vscope_cpu__instruction_memory_inst__unnamedblk3);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"cpu_out", &(TOP.cpu_out), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"input_data", &(TOP.input_data), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst", &(TOP.rst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_ctrl", &(TOP.cpu__DOT__alu_ctrl), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_last_bit", &(TOP.cpu__DOT__alu_last_bit), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_result", &(TOP.cpu__DOT__alu_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_source", &(TOP.cpu__DOT__alu_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"alu_zero", &(TOP.cpu__DOT__alu_zero), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"cpu_out", &(TOP.cpu__DOT__cpu_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"dData", &(TOP.cpu__DOT__dData), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"data_address", &(TOP.cpu__DOT__data_address), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"func3", &(TOP.cpu__DOT__func3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu.varInsert(__Vfinal,"func7", &(TOP.cpu__DOT__func7), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu.varInsert(__Vfinal,"imm_type", &(TOP.cpu__DOT__imm_type), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu.varInsert(__Vfinal,"immediate", &(TOP.cpu__DOT__immediate), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"input_data", &(TOP.cpu__DOT__input_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"inst_type", &(TOP.cpu__DOT__inst_type), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu.varInsert(__Vfinal,"instruction", &(TOP.cpu__DOT__instruction), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"memRead", &(TOP.cpu__DOT__memRead), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"memWrite", &(TOP.cpu__DOT__memWrite), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"opcode", &(TOP.cpu__DOT__opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu.varInsert(__Vfinal,"override", &(TOP.cpu__DOT__override), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"pc_next", &(TOP.cpu__DOT__pc_next), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"pc_source", &(TOP.cpu__DOT__pc_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu.varInsert(__Vfinal,"rd", &(TOP.cpu__DOT__rd), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu.varInsert(__Vfinal,"rd_data", &(TOP.cpu__DOT__rd_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"regData", &(TOP.cpu__DOT__regData), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"regData1", &(TOP.cpu__DOT__regData1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"regData2", &(TOP.cpu__DOT__regData2), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu.varInsert(__Vfinal,"reg_destination", &(TOP.cpu__DOT__reg_destination), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu.varInsert(__Vfinal,"reg_write", &(TOP.cpu__DOT__reg_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"register_source", &(TOP.cpu__DOT__register_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu.varInsert(__Vfinal,"rs1", &(TOP.cpu__DOT__rs1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu.varInsert(__Vfinal,"rs2", &(TOP.cpu__DOT__rs2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu.varInsert(__Vfinal,"rst", &(TOP.cpu__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu.varInsert(__Vfinal,"take_branch", &(TOP.cpu__DOT__take_branch), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"add_result", &(TOP.cpu__DOT__alu_inst__DOT__add_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"alu_output", &(TOP.cpu__DOT__alu_inst__DOT__alu_output), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"alu_source", &(TOP.cpu__DOT__alu_inst__DOT__alu_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__alu_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"cntrl", &(TOP.cpu__DOT__alu_inst__DOT__cntrl), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"d1", &(TOP.cpu__DOT__alu_inst__DOT__d1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"d2", &(TOP.cpu__DOT__alu_inst__DOT__d2), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"immediate", &(TOP.cpu__DOT__alu_inst__DOT__immediate), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"last_bit", &(TOP.cpu__DOT__alu_inst__DOT__last_bit), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"logic_result", &(TOP.cpu__DOT__alu_inst__DOT__logic_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"rs2", &(TOP.cpu__DOT__alu_inst__DOT__rs2), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"rst", &(TOP.cpu__DOT__alu_inst__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"shift_result", &(TOP.cpu__DOT__alu_inst__DOT__shift_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"shift_type", &(TOP.cpu__DOT__alu_inst__DOT__shift_type), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu__alu_inst.varInsert(__Vfinal,"zero", &(TOP.cpu__DOT__alu_inst__DOT__zero), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__alu_inst__adder_inst.varInsert(__Vfinal,"a", &(TOP.cpu__DOT__alu_inst__DOT__adder_inst__DOT__a), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst__adder_inst.varInsert(__Vfinal,"b", &(TOP.cpu__DOT__alu_inst__DOT__adder_inst__DOT__b), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst__adder_inst.varInsert(__Vfinal,"sum", &(TOP.cpu__DOT__alu_inst__DOT__adder_inst__DOT__sum), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst__logic_inst.varInsert(__Vfinal,"a", &(TOP.cpu__DOT__alu_inst__DOT__logic_inst__DOT__a), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst__logic_inst.varInsert(__Vfinal,"b", &(TOP.cpu__DOT__alu_inst__DOT__logic_inst__DOT__b), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst__logic_inst.varInsert(__Vfinal,"cntrl", &(TOP.cpu__DOT__alu_inst__DOT__logic_inst__DOT__cntrl), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu__alu_inst__logic_inst.varInsert(__Vfinal,"logic_output", &(TOP.cpu__DOT__alu_inst__DOT__logic_inst__DOT__logic_output), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst__shifter_inst.varInsert(__Vfinal,"a", &(TOP.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__a), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst__shifter_inst.varInsert(__Vfinal,"shamt", &(TOP.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shamt), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu__alu_inst__shifter_inst.varInsert(__Vfinal,"shift_result", &(TOP.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__alu_inst__shifter_inst.varInsert(__Vfinal,"shift_type", &(TOP.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_type), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu__branch_unit_inst.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__branch_unit_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__branch_unit_inst.varInsert(__Vfinal,"cntrl", &(TOP.cpu__DOT__branch_unit_inst__DOT__cntrl), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__branch_unit_inst.varInsert(__Vfinal,"d1", &(TOP.cpu__DOT__branch_unit_inst__DOT__d1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__branch_unit_inst.varInsert(__Vfinal,"d2", &(TOP.cpu__DOT__branch_unit_inst__DOT__d2), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__branch_unit_inst.varInsert(__Vfinal,"rst", &(TOP.cpu__DOT__branch_unit_inst__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__branch_unit_inst.varInsert(__Vfinal,"take_branch", &(TOP.cpu__DOT__branch_unit_inst__DOT__take_branch), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"alu_control", &(TOP.cpu__DOT__control_inst__DOT__alu_control), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"alu_last_bit", &(TOP.cpu__DOT__control_inst__DOT__alu_last_bit), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"alu_op", &(TOP.cpu__DOT__control_inst__DOT__alu_op), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"alu_source", &(TOP.cpu__DOT__control_inst__DOT__alu_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"alu_zero", &(TOP.cpu__DOT__control_inst__DOT__alu_zero), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"func3", &(TOP.cpu__DOT__control_inst__DOT__func3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"func7", &(TOP.cpu__DOT__control_inst__DOT__func7), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"imm_source", &(TOP.cpu__DOT__control_inst__DOT__imm_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"jalr_override", &(TOP.cpu__DOT__control_inst__DOT__jalr_override), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"mem_read", &(TOP.cpu__DOT__control_inst__DOT__mem_read), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"mem_write", &(TOP.cpu__DOT__control_inst__DOT__mem_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"op", &(TOP.cpu__DOT__control_inst__DOT__op), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"pc_source", &(TOP.cpu__DOT__control_inst__DOT__pc_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"reg_write", &(TOP.cpu__DOT__control_inst__DOT__reg_write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__control_inst.varInsert(__Vfinal,"register_source", &(TOP.cpu__DOT__control_inst__DOT__register_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu__data_memory_inst.varInsert(__Vfinal,"WORDS", const_cast<void*>(static_cast<const void*>(&(TOP.cpu__DOT__data_memory_inst__DOT__WORDS))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__data_memory_inst.varInsert(__Vfinal,"address", &(TOP.cpu__DOT__data_memory_inst__DOT__address), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__data_memory_inst.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__data_memory_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__data_memory_inst.varInsert(__Vfinal,"mem", &(TOP.cpu__DOT__data_memory_inst__DOT__mem), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,16777215 ,31,0);
        __Vscope_cpu__data_memory_inst.varInsert(__Vfinal,"read_data", &(TOP.cpu__DOT__data_memory_inst__DOT__read_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__data_memory_inst.varInsert(__Vfinal,"rst_data", &(TOP.cpu__DOT__data_memory_inst__DOT__rst_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__data_memory_inst.varInsert(__Vfinal,"write_data", &(TOP.cpu__DOT__data_memory_inst__DOT__write_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__data_memory_inst.varInsert(__Vfinal,"write_enable", &(TOP.cpu__DOT__data_memory_inst__DOT__write_enable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__data_memory_inst__unnamedblk1.varInsert(__Vfinal,"i", &(TOP.cpu__DOT__data_memory_inst__DOT__unnamedblk1__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_cpu__data_memory_inst__unnamedblk2.varInsert(__Vfinal,"idx", &(TOP.cpu__DOT__data_memory_inst__DOT__unnamedblk2__DOT__idx), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_cpu__data_memory_inst__unnamedblk3.varInsert(__Vfinal,"idx", &(TOP.cpu__DOT__data_memory_inst__DOT__unnamedblk3__DOT__idx), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__decoder_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"func3", &(TOP.cpu__DOT__decoder_inst__DOT__func3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"func7", &(TOP.cpu__DOT__decoder_inst__DOT__func7), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"imm_type", &(TOP.cpu__DOT__decoder_inst__DOT__imm_type), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"immediate", &(TOP.cpu__DOT__decoder_inst__DOT__immediate), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,19,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"inst_type", &(TOP.cpu__DOT__decoder_inst__DOT__inst_type), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"instruction", &(TOP.cpu__DOT__decoder_inst__DOT__instruction), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"opcode", &(TOP.cpu__DOT__decoder_inst__DOT__opcode), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,6,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"rd", &(TOP.cpu__DOT__decoder_inst__DOT__rd), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"rs1", &(TOP.cpu__DOT__decoder_inst__DOT__rs1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"rs2", &(TOP.cpu__DOT__decoder_inst__DOT__rs2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu__decoder_inst.varInsert(__Vfinal,"rst", &(TOP.cpu__DOT__decoder_inst__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__instruction_memory_inst.varInsert(__Vfinal,"WORDS", const_cast<void*>(static_cast<const void*>(&(TOP.cpu__DOT__instruction_memory_inst__DOT__WORDS))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__instruction_memory_inst.varInsert(__Vfinal,"address", &(TOP.cpu__DOT__instruction_memory_inst__DOT__address), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__instruction_memory_inst.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__instruction_memory_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__instruction_memory_inst.varInsert(__Vfinal,"mem", &(TOP.cpu__DOT__instruction_memory_inst__DOT__mem), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1,1 ,0,16777215 ,31,0);
        __Vscope_cpu__instruction_memory_inst.varInsert(__Vfinal,"read_data", &(TOP.cpu__DOT__instruction_memory_inst__DOT__read_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__instruction_memory_inst.varInsert(__Vfinal,"rst_data", &(TOP.cpu__DOT__instruction_memory_inst__DOT__rst_data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__instruction_memory_inst.varInsert(__Vfinal,"write_data", &(TOP.cpu__DOT__instruction_memory_inst__DOT__write_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__instruction_memory_inst.varInsert(__Vfinal,"write_enable", &(TOP.cpu__DOT__instruction_memory_inst__DOT__write_enable), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__instruction_memory_inst__unnamedblk1.varInsert(__Vfinal,"i", &(TOP.cpu__DOT__instruction_memory_inst__DOT__unnamedblk1__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_cpu__instruction_memory_inst__unnamedblk2.varInsert(__Vfinal,"idx", &(TOP.cpu__DOT__instruction_memory_inst__DOT__unnamedblk2__DOT__idx), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_cpu__instruction_memory_inst__unnamedblk3.varInsert(__Vfinal,"idx", &(TOP.cpu__DOT__instruction_memory_inst__DOT__unnamedblk3__DOT__idx), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,0,1 ,31,0);
        __Vscope_cpu__pc_inst.varInsert(__Vfinal,"branch", &(TOP.cpu__DOT__pc_inst__DOT__branch), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__pc_inst.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__pc_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__pc_inst.varInsert(__Vfinal,"jalr_imm", &(TOP.cpu__DOT__pc_inst__DOT__jalr_imm), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__pc_inst.varInsert(__Vfinal,"jalr_target", &(TOP.cpu__DOT__pc_inst__DOT__jalr_target), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__pc_inst.varInsert(__Vfinal,"offset", &(TOP.cpu__DOT__pc_inst__DOT__offset), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__pc_inst.varInsert(__Vfinal,"override", &(TOP.cpu__DOT__pc_inst__DOT__override), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__pc_inst.varInsert(__Vfinal,"pc", &(TOP.cpu__DOT__pc_inst__DOT__pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__pc_inst.varInsert(__Vfinal,"pc_out", &(TOP.cpu__DOT__pc_inst__DOT__pc_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__pc_inst.varInsert(__Vfinal,"rs1", &(TOP.cpu__DOT__pc_inst__DOT__rs1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__pc_inst.varInsert(__Vfinal,"rst", &(TOP.cpu__DOT__pc_inst__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"alu_result", &(TOP.cpu__DOT__register_file_inst__DOT__alu_result), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__register_file_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"enableWrite", &(TOP.cpu__DOT__register_file_inst__DOT__enableWrite), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"i", &(TOP.cpu__DOT__register_file_inst__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"pc_plus_4", &(TOP.cpu__DOT__register_file_inst__DOT__pc_plus_4), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"rd", &(TOP.cpu__DOT__register_file_inst__DOT__rd), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"rd1", &(TOP.cpu__DOT__register_file_inst__DOT__rd1), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"rd2", &(TOP.cpu__DOT__register_file_inst__DOT__rd2), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"register_source", &(TOP.cpu__DOT__register_file_inst__DOT__register_source), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"regs", &(TOP.cpu__DOT__register_file_inst__DOT__regs), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1,1 ,31,0 ,31,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"rs1", &(TOP.cpu__DOT__register_file_inst__DOT__rs1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"rs2", &(TOP.cpu__DOT__register_file_inst__DOT__rs2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"rst", &(TOP.cpu__DOT__register_file_inst__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__register_file_inst.varInsert(__Vfinal,"wd", &(TOP.cpu__DOT__register_file_inst__DOT__wd), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__sign_extender_inst.varInsert(__Vfinal,"clk", &(TOP.cpu__DOT__sign_extender_inst__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cpu__sign_extender_inst.varInsert(__Vfinal,"ext_imm", &(TOP.cpu__DOT__sign_extender_inst__DOT__ext_imm), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__sign_extender_inst.varInsert(__Vfinal,"imm_type", &(TOP.cpu__DOT__sign_extender_inst__DOT__imm_type), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,2,0);
        __Vscope_cpu__sign_extender_inst.varInsert(__Vfinal,"inst", &(TOP.cpu__DOT__sign_extender_inst__DOT__inst), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cpu__sign_extender_inst.varInsert(__Vfinal,"rst", &(TOP.cpu__DOT__sign_extender_inst__DOT__rst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
    }
}
