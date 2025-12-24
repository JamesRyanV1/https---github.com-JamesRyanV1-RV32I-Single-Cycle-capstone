import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer, ReadWrite
import logging
import random as rd

@cocotb.test()
async def decoder_test(dut):
    """ test for the 32 bit instruction decoder """
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    