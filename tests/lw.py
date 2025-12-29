import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge


OPCODE_LW = 0b0000011
FUNCT3_LW = 0b010


def encode_lw(rd: int, rs1: int, imm: int) -> int:
	"""Assemble an RV32I lw instruction (positive imm only for this test)."""
	imm_masked = imm & 0xFFF
	return (imm_masked << 20) | (rs1 << 15) | (FUNCT3_LW << 12) | (rd << 7) | OPCODE_LW


@cocotb.test()
async def test_lw_basic(dut):
	"""Load word writes data memory contents into destination register."""

	clock = Clock(dut.clk, 10, unit="ns")
	cocotb.start_soon(clock.start())

	# Reset
	dut.rst.value = 1
	dut.instruction_in.value = 0
	await RisingEdge(dut.clk)
	await RisingEdge(dut.clk)
	dut.rst.value = 0

	# Test parameters
	base_reg = 3
	dest_reg = 5
	imm = 8  # byte offset
	base_addr = 16
	mem_data = 0xDEADBEEF

	# Preload register file base and data memory contents hierarchically
	dut.register_file_inst.regs[base_reg].value = base_addr
	word_index = (base_addr + imm) >> 2
	dut.data_memory_inst.mem[word_index].value = mem_data

	# Drive lw instruction
	dut.instruction_in.value = encode_lw(dest_reg, base_reg, imm)
    # Allow combinational path to settle then capture on rising edge
	await RisingEdge(dut.clk)   # execute/load
	await RisingEdge(dut.clk)   # writeback
	# The load data should appear on readd and be written into dest_reg on this edge
	assert int(dut.readd.value) == mem_data, "Data memory read should match expected value"
	assert int(dut.register_file_inst.regs[dest_reg].value) == mem_data, "Destination register should capture loaded word"

    

    