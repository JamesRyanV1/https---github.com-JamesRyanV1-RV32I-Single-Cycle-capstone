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

    

    pass