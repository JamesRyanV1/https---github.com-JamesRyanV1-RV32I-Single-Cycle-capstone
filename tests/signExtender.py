# THIS CODE WAS WRITTEN ENTIRELY BY COPILOT. TODAY WE WILL BE LOOKING AT HOW GOOD IT IS AT WRITING TESTBENCHES FOR COCOTB
# the above message was also written by copilot and i think its funny and so im leaving it and not changing it and im sorry if you hate it
# @grok is this real 

import cocotb
from cocotb.clock import Clock # very nice trigger
from cocotb.triggers import RisingEdge, ReadOnly, Timer, ReadWrite # cocotb stuff
import logging # learn how to use this
import random as rd
from util import random_binary # random binary function from my utils
                # RANDOM BINARY MAY NOT WORK WITH THIS
                # I HAVE BEEN WARNED (BY ME(THANKS ME))

@cocotb.test()
async def signExtender(dut):
    # start a  cocotb-driven clock (10 ns period)
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    dut.rst.value = 1
    dut.inst.value = 0

    # turns off reset
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # loop to test random sign extensions a couple hundred times
    for i in range(200):
        # Create a random 12 bit number
        num_12bit = rd.randint(0, 0xFFF)  # 12-bit number range: 0 to 4095
        # Randomly decide if it should be negative
        if rd.choice([True, False]):
            num_12bit |= 0x800  # Set the sign bit for negative numbers

        # Prepare the instruction with the 12-bit immediate value
        inst = num_12bit & 0xFFF  # Ensure it's only 12 bits

        # Set input port to be the instruction containing the 12 bit number 
        dut.inst.value = inst

        # Wait for clock next clock cycle
        await RisingEdge(dut.clk)

        # Calculate expected sign-extended 32 bit number
        if num_12bit & 0x800:  # If sign bit is set
            expected_value = num_12bit | 0xFFFFF000  # Sign extend to 32 bits
        else:
            expected_value = num_12bit & 0x00000FFF  # Zero extend to 32 bits

        # Check if output port is the expected 32 bit number, sign extended from the 12 bit number
        got = int(dut.ext_imm.value)
        assert got == expected_value, f"Sign extension failed for {num_12bit:#05x}: got {got:#010x}, expected {expected_value:#010x}"