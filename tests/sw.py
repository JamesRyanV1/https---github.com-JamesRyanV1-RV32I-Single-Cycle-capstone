import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge


OPCODE_SW = 0b0100011
FUNCT3_SW = 0b010


def encode_sw(rs2: int, rs1: int, imm: int) -> int:
	"""Assemble an RV32I sw instruction (positive imm only for this test)."""
	imm_masked = imm & 0xFFF
	imm_hi = (imm_masked >> 5) & 0x7F
	imm_lo = imm_masked & 0x1F
	return (imm_hi << 25) | (rs2 << 20) | (rs1 << 15) | (FUNCT3_SW << 12) | (imm_lo << 7) | OPCODE_SW


@cocotb.test()
async def test_sw_basic(dut):
	"""Store word writes rs2 into data memory at rs1+imm."""

	clock = Clock(dut.clk, 10, units="ns")
	cocotb.start_soon(clock.start())

	# Reset
	dut.rst.value = 1
	dut.instruction_in.value = 0
	await RisingEdge(dut.clk)
	await RisingEdge(dut.clk)
	dut.rst.value = 0

	# Test parameters
	base_reg = 3
	src_reg = 4
	imm = 8  # byte offset
	base_addr = 16
	store_data = 0xCAFEBABE

	# Preload register file values hierarchically
	dut.register_file_inst.regs[base_reg].value = base_addr
	dut.register_file_inst.regs[src_reg].value = store_data

	# Drive sw instruction
	dut.instruction_in.value = encode_sw(src_reg, base_reg, imm)

	# Memory write should occur on this rising edge
	await RisingEdge(dut.clk)

	word_index = (base_addr + imm) >> 2
	assert dut.data_memory_inst.mem[word_index].value.integer == store_data, "Data memory should capture store data at computed address"
