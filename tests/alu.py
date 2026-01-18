import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly
import random as rd

@cocotb.test()
async def alu_test(dut):
    # start a cocotb-driven clock (10 ns period)
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    dut.rst.value = 1
    dut.alu_source.value = 0  # use rs2
    dut.d1.value = 0
    dut.immediate.value = 0
    dut.rs2.value = 0
    dut.cntrl.value = 0

    # turns off reset
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # loop to test random alu operations a couple hundred times
    for i in range(200):
        await RisingEdge(dut.clk)
        # generate two random 32 bit numbers
        x = rd.randint(0, 0xFFFFFFFF)
        y = rd.randint(0, 0xFFFFFFFF)

        # randomly choose an operation: 0 for add, 1-6 for other ops
        operation = rd.choice([0, 1, 2, 3, 4, 5, 6])
        
        # Set inputs
        dut.d1.value = x
        dut.rs2.value = y
        dut.alu_source.value = 0  # use rs2 (not immediate)
        dut.cntrl.value = operation

        # Wait for combinational logic to settle
        await RisingEdge(dut.clk)
        await ReadOnly()

        # Check output based on operation
        got = int(dut.alu_output.value)
        
        if operation == 0:  # Addition
            expected_value = (x + y) & 0xFFFFFFFF
            assert got == expected_value, f"ALU add failed for {x:#010x} + {y:#010x}: got {got:#010x}, expected {expected_value:#010x}"
        elif operation == 1:  # SLL (logical left shift)
            shift_amt = y & 0x1F  # use lower 5 bits
            expected_value = (x << shift_amt) & 0xFFFFFFFF
            assert got == expected_value, f"ALU sll failed for {x:#010x} << {shift_amt}: got {got:#010x}, expected {expected_value:#010x}"
        elif operation == 2:  # SRL (logical right shift)
            shift_amt = y & 0x1F
            expected_value = x >> shift_amt
            assert got == expected_value, f"ALU srl failed for {x:#010x} >> {shift_amt}: got {got:#010x}, expected {expected_value:#010x}"
        elif operation == 3:  # SRA (arithmetic right shift)
            shift_amt = y & 0x1F
            if x & 0x80000000:  # negative
                expected_value = ((x >> shift_amt) | (0xFFFFFFFF << (32 - shift_amt))) & 0xFFFFFFFF
            else:
                expected_value = x >> shift_amt
            assert got == expected_value, f"ALU sra failed for {x:#010x} >>> {shift_amt}: got {got:#010x}, expected {expected_value:#010x}"
        elif operation == 4:  # AND
            expected_value = x & y
            assert got == expected_value, f"ALU and failed for {x:#010x} & {y:#010x}: got {got:#010x}, expected {expected_value:#010x}"
        elif operation == 5:  # OR
            expected_value = x | y
            assert got == expected_value, f"ALU or failed for {x:#010x} | {y:#010x}: got {got:#010x}, expected {expected_value:#010x}"
        elif operation == 6:  # XOR
            expected_value = x ^ y
            assert got == expected_value, f"ALU xor failed for {x:#010x} ^ {y:#010x}: got {got:#010x}, expected {expected_value:#010x}"