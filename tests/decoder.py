import cocotb # this wont work anywhere yikes

# @cocotb(test) (); to start test or something see docs

# Create a random 12 bit number

# Clock on, clock off

# At posedge clock, run following
    # Set input port to be the instruction containing the 12 bit number 
# Wait for clock next clock cycle
    # Check if output port is the expected 32 bit number, sign extended from the 12 bit number


from cocotb.clock import Clock # very nice trigger
from cocotb.triggers import RisingEdge, ReadOnly, Timer, ReadWrite # cocotb stuff
import logging # learn how to use this
import random as rd

@cocotb.test()
async def decoder_test(dut):
    pass