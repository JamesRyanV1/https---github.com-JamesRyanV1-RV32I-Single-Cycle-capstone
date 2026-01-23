import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer

import helpers # for making instruction compilation easier
from helpers import compile_B_type, compile_R_type, compile_I_type, compile_S_type, compile_L_type

@cocotb.test()
async def loop(dut):
    """
    Tests a short loop program, described below kind of in my assembly psuedocode ( I dont know assembly)
    1: loads 100 into x1, 28 into x2, 0 into x3 
    2: adds 4 to x2 each loop iteration
    3: branch untill x1 > x2
    4: load x3 iteration count into memory address 8
    5: print memory at address 8 to terminal
    """

    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    # Reset dut
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst.value = 0 # pc 0
    await Timer(1, unit="ps")

    # preload data memory
    dut.data_memory_inst.mem[0].value = 0x00000064  # 100 in decimal
    dut.data_memory_inst.mem[1].value = 0x0000001C  # 28 in decimal
    dut.data_memory_inst.mem[2].value = 0x00000000 

    # program memory setup
    dut.instruction_memory_inst.mem[0].value = compile_L_type(1, 0, 0)        # lw x1, 0(x0)      ; Load 100 into x1
    dut.instruction_memory_inst.mem[1].value = compile_L_type(2, 0, 4)        # lw x2, 4(x0)      ; Load 28 into x2
    dut.instruction_memory_inst.mem[2].value = compile_L_type(3, 0, 8)        # lw x3, 8(x0)      ; Load 0 into x3
    dut.instruction_memory_inst.mem[3].value = compile_I_type(0b0010011, 3, 0b000, 3, 1)  # addi x3, x3, 1 ; x3 = x3 + 1
    dut.instruction_memory_inst.mem[4].value = compile_I_type(0b0010011, 2, 0b000, 2, 6)  # addi x2, x2, 4 ; x2 = x2 + 4
    dut.instruction_memory_inst.mem[5].value = compile_B_type(0b100, 2, 1, -12)  # BLT x2, x1, -12 (branch to PC=3)
    dut.instruction_memory_inst.mem[6].value = compile_I_type(0b0010011, 3, 0b000, 3, 4)  # addi x3, x3, 4 ; x3 = x3 + 4
    dut.instruction_memory_inst.mem[7].value = compile_S_type(0b0100011, 0b010, 0, 3, 8)        # sw x3, 8(x0)      ; Store x3 into address 8
    
    for i in range(150):  # Run enough cycles to complete the loop
        await RisingEdge(dut.clk)
        if i < 20:  # Debug first 20 cycles
            await ReadOnly()
            print(f"Cycle {i}: PC={dut.pc_next.value}, x1={dut.register_file_inst.regs[1].value}, x2={dut.register_file_inst.regs[2].value}, x3={dut.register_file_inst.regs[3].value}, take_branch={dut.take_branch.value}")
    await ReadOnly()
    print("Final memory at address): ", dut.data_memory_inst.mem[2].value.to_unsigned())