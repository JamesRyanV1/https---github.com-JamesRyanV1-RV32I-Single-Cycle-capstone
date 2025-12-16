import cocotb
from cocotb.clock import Clock # very nice trigger
from cocotb.triggers import RisingEdge, ReadOnly, Timer, ReadWrite # cocotb stuff
import logging # learn how to use this
import random as rd
from util import random_binary # random binary function from my utils
                # RANDOM BINARY MAY NOT WORK WITH THIS
                # I HAVE BEEN WARNED (BY ME(THANKS ME))

# @cocotb(test)
@cocotb.test()
async def alu_test(dut):
    # start a  cocotb-driven clock (10 ns period)
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    dut.rst.value = 1
    dut.d1.value = 0
    dut.d2.value = 0
    dut.control.value = 0

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

        # Instantly set inputs
        dut.d1.value = x
        dut.d2.value = y
        dut.control.value = operation

        # Wait for clock next clock cycle
        await RisingEdge(dut.clk)

        # Check output based on operation
        # TESTBENCH DOES NOT HANDLE OVERFLOWS
        if operation == 0:  # Addition
            expected_value = (x + y) & 0xFFFFFFFF  # Ensure it stays within 32 bits
            assert dut.alu_out.value == expected_value, f"ALU addition failed for {x:#010x} + {y:#010x}: got {dut.alu_out.value:#010x}, expected {expected_value:#010x}"
        elif operation == 1:  # NOP
            expected_value = 0
            assert dut.alu_out.value == expected_value, f"ALU NOP failed: got {dut.alu_out.value:#010x}, expected {expected_value:#010x}"
# x, y = some 32 bit number under 31'b1 (no handling for overflow right now, handled later)

# Instantly 
    # Set d1 to x and d2 to y
    # Set control to be 4'b0


# on clock

    # nothing

# after clock

    # check output port to make sure its the sum of the two 32 bit numbers


# @cocotb(test)

# x, y = some 32 bit numbers, doesnt matter
# instantly
    # set d1 and d2 to x, y
    # set control to 4'b1 (not in the alu)

# on clock
    #wait
# on low edge clock
    # check to make sure alu output is 0
        # ERROR POSSIBLE HERE IF IT NEEDS TO BE 32'B0 INSTEAD OF JUST 0