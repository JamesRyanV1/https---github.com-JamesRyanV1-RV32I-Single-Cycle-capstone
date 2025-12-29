import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly
import random as rd

@cocotb.test()
async def alu_test(dut):
    # start a cocotb-driven clock (10 ns period)
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    dut.rst.value = 1
    dut.d1.value = 0
    dut.d2.value = 0
    dut.cntrl.value = 0

    # turns off reset
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # loop to test random alu operations a couple hundred times
    for i in range(200):
        # generate two random 32 bit numbers
        x = rd.randint(0, 0xFFFFFFFF)
        y = rd.randint(0, 0xFFFFFFFF)

        # randomly choose an operation: 0 for add, 1 for nop
        operation = rd.choice([0, 1])
        await RisingEdge(dut.clk)
        # Instantly set inputs
        dut.d1.value = x
        dut.d2.value = y
        dut.cntrl.value = operation

        # Wait for clock next clock cycle
        await RisingEdge(dut.clk)
        await ReadOnly()

        # Check output based on operation
        got = int(dut.alu_output.value)
        
        if operation == 0:  # Addition
            expected_value = (x + y) & 0xFFFFFFFF  # Ensure it stays within 32 bits
            assert got == expected_value, f"ALU addition failed for {x:#010x} + {y:#010x}: got {got:#010x}, expected {expected_value:#010x}"
        elif operation == 1:  # NOP
            expected_value = 0
            assert got == expected_value, f"ALU NOP failed: got {got:#010x}, expected {expected_value:#010x}"