# tests a short program that uses several instructions one clock cycle each.

# lw, addi, sw.


import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer


def compileLW(rd, rs1, imm):
    """Compile a lw instruction."""
    opcode = 0b0000011
    func3 = 0b010
    inst = (imm << 20) | (rs1 << 15) | (func3 << 12) | (rd << 7) | opcode
    return inst
def compileADDI(rd, rs1, imm):
    """Compile an addi instruction."""
    opcode = 0b0010011
    func3 = 0b000
    inst = (imm << 20) | (rs1 << 15) | (func3 << 12) | (rd << 7) | opcode
    return inst
def compileSW(rs2, rs1, imm):
    """Compile a sw instruction."""
    opcode = 0b0100011
    func3 = 0b010
    imm11_5 = (imm >> 5) & 0x7F
    imm4_0 = imm & 0x1F
    inst = (imm11_5 << 25) | (rs2 << 20) | (rs1 << 15) | (func3 << 12) | (imm4_0 << 7) | opcode
    return inst
def compileBGT(rs1, rs2, imm):
    """Compile a bgt instruction."""
    opcode = 0b1100011
    func3 = 0b011
    imm12 = (imm >> 12) & 0x1
    imm10_5 = (imm >> 5) & 0x3F
    imm4_1 = (imm >> 1) & 0xF
    imm11 = (imm >> 11) & 0x1
    inst = (imm12 << 31) | (imm11 << 7) | (imm10_5 << 25) | (rs2 << 20) | (rs1 << 15) | (func3 << 12) | (imm4_1 << 8) | opcode
    return inst
@cocotb.test()
async def short_program(dut):
    """Test a short program that loads a value from memory, adds an immediate, and stores the result back."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Reset DUT
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await Timer(1, unit="ps")

    # Preload data memory at address 0x00 with value 0x00000005
    dut.data_memory_inst.mem[0].value = 0x00000005

    # Load program into instruction memory
    # Address 0x00: lw x1, 0(x0)      ; Load word from address 0 into x1
    # Address 0x04: addi x2, x1, 10   ; Add immediate 10 to x1 and store in x2
    # Address 0x08: sw x2, 4(x0)      ; Store word from x2 into address 4
    
    dut.instruction_memory_inst.mem[0].value = compileLW(1, 0, 0)      # lw x1, 0(x0)
    dut.instruction_memory_inst.mem[1].value = compileADDI(2, 1, 10)   # addi x2, x1, 10
    dut.instruction_memory_inst.mem[2].value = compileSW(2, 0, 4)      # sw x2, 4(x0)

    # Run for 3 cycles to complete the program (single-cycle execution per instruction)
    for _ in range(3):
        await RisingEdge(dut.clk)
    await ReadOnly()
    # Check that memory at address 4 now contains 15 (5 + 10)
    result = dut.data_memory_inst.mem[1].value.to_unsigned()  # Address 4 is memory index 1
    assert result == 15, f"Expected memory at address 4 to be 15, got {result}"
@cocotb.test()
async def add_untill_over_100_store_iterations(dut):
    """Test a program that adds numbers until the sum exceeds 100, then stores the iteration count."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Reset DUT
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await Timer(1, unit="ps")

    # Preload data memory
    dut.data_memory_inst.mem[0].value = 0x00000064  # 100 in decimal
    dut.data_memory_inst.mem[1].value = 0x00000032  # 50 in decimal

    # Load program into instruction memory
    # Address 0x00: lw x1, 0(x0)      ; Load 100 into x1
    # Address 0x04: lw x2, 4(x0)      ; Load 50 into x2
    # Address 0x08: bgt x1, x2, 8     ; If x1 > x2, branch forward by 8 bytes (skip next instruction)
    # Address 0x0C: addi x3, x0, 0    ; x3 = 0 (executed if branch NOT taken)
    # Address 0x10: addi x3, x0, 1    ; x3 = 1 (executed if branch taken)
    # Address 0x14: sw x3, 8(x0)      ; Store result in memory at address 8

    dut.instruction_memory_inst.mem[0].value = compileLW(1, 0, 0)        # lw x1, 0(x0)
    dut.instruction_memory_inst.mem[1].value = compileLW(2, 0, 4)        # lw x2, 4(x0)
    dut.instruction_memory_inst.mem[2].value = compileBGT(1, 2, 8)       # bgt x1, x2, 8
    dut.instruction_memory_inst.mem[3].value = compileADDI(3, 0, 0)      # addi x3, x0, 0
    
    dut.instruction_memory_inst.mem[4].value = compileADDI(3, 0, 1)      # addi x3, x0, 1 
    dut.instruction_memory_inst.mem[5].value = compileSW(3, 0, 8)        # sw x3, 8(x0)

    # Run for enough cycles to complete the program
    for _ in range(6):
        await RisingEdge(dut.clk)
    await ReadOnly()
    
    # Check that x3 was set to 1 (branch was taken because 100 >)
    result = dut.data_memory_inst.mem[2].value.to_unsigned()  # Address 8 is memory index 2

    for _ in range(20):  # Run enough cycles to complete the loop
        await RisingEdge(dut.clk)
    await ReadOnly()
    # Print the amount of iterations stored at memory address 4
    result = dut.data_memory_inst.mem[1].value.to_unsigned()  # Address 4 is memory index 1
    print(f"Iterations until sum exceeded 100: {result}")