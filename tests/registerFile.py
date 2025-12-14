import cocotb
from cocotb.clock import Clock # very nice trigger
from cocotb.triggers import RisingEdge, ReadOnly, Timer, ReadWrite # cocotb stuff
import logging # learn how to use this
import random as rd
from util import random_binary # random binary function from my utils
                # RANDOM BINARY MAY NOT WORK WITH THIS
                # I HAVE BEEN WARNED (BY ME(THANKS ME))


@cocotb.test()
async def register_file_test(dut):

    # start a  cocotb-driven clock (10 ns period)
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    dut.rst.value = 1
    dut.rs1 = 0
    dut.rs2 = 0
    dut.rd = 0
    dut.wd = 0 
    dut.enableWrite


    # turns off reset
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    # makes all the regs 0 to start
    fake_regs = [0 for i in range(32)]


    # loop to test random reads/writes a couple hundred times
    for i in range(550):
        # random adresses, 1-31
        ad1 = rd.randint(1,31)
        ad2 = rd.randint(1,31)
        ad3 = rd.randint(1,31)
        write_value = random_binary(32)

        #reads
        await Timer(1,units="ns")
        dut.rs1.value = ad1
        dut.rs2.value = ad2
        await Timer(1,units="ns")
        # makes sure the data being read is the same as the data that should be in the regs
        # data that should be there represented by the stand in regs, (im not making a path between this and memory for the testbench)
        assert dut.rd1.value == fake_regs[ad1]
        assert dut.rd2.value == fake_regs[ad2]

        #random writes, stored then read when loops
        dut.ad3.value = ad3
        dut.enableWrite.value = 1 #enables write for this portion
        dut.wd = write_value
        await RisingEdge(dut.clk)
        dut.enableWrite.value = 0
        fake_regs[ad3] = write_value
        await Timer(1,units="ns")
        
    # Try and write to 0, after loop bc would unsettle the zerod fake regs
    await Timer(1, units="ns")
    dut.ad3.value = 0
    dut.enableWrite.value=1
    dut.wd = random_binary(32)
    await RisingEdge(dut.clk)
    dut.wd.value = 0
    fake_regs[ad3] = write_value
    await Timer(1, units="ns")

    # rd1 (if 0) should end up as 0, final assertion after trying to change it
    await Timer(1, units="ns")
    dut.ad1.value = 0
    await Timer(1, units="ns")
    assert int(dut.rd1.value) == 0

    # if random read/writtes work, and 0 cannot be changed from 0, cpu works