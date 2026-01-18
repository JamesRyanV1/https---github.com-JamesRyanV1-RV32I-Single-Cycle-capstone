import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly


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
	await RisingEdge(dut.clk)

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

	# Execute: wait for combinational path to settle
	await RisingEdge(dut.clk)   # instruction executes
	await RisingEdge(dut.clk)   # memory read data available on readd

	await ReadOnly()

	# Debug: check memory contents and address
	mem_addr = int(dut.data_memory_inst.address.value)
	mem_word_idx = mem_addr >> 2
	mem_contents = int(dut.data_memory_inst.mem[mem_word_idx].value)
	readd_val = int(dut.readd.value)

	print(f"DEBUG: mem_addr = {mem_addr:08x}, word_idx = {mem_word_idx}")
	print(f"DEBUG: mem[{mem_word_idx}] = {mem_contents:08x}")
	print(f"DEBUG: readd (output) = {readd_val:08x}")

	# Now assert after debug output
	assert readd_val == mem_data, f"Data memory read should match expected value: got {readd_val:08x}, expected {mem_data:08x}"

	await RisingEdge(dut.clk)  # writeback into dest_reg
	assert int(dut.register_file_inst.regs[dest_reg].value) == mem_data, "Destination register should capture loaded word"

	await RisingEdge(dut.clk)
	await RisingEdge(dut.clk)

	await ReadOnly()

	# Debug: check memory contents and address
	mem_addr = int(dut.data_memory_inst.address.value)
	mem_word_idx = mem_addr >> 2
	mem_contents = int(dut.data_memory_inst.mem[mem_word_idx].value)
	readd_val = int(dut.readd.value)

	print(f"DEBUG: mem_addr = {mem_addr:08x}, word_idx = {mem_word_idx}")
	print(f"DEBUG: mem[{mem_word_idx}] = {mem_contents:08x}")
	print(f"DEBUG: readd (output) = {readd_val:08x}")

	assert mem_contents == mem_data, f"Memory contents at [{mem_word_idx}] should be {mem_data:08x}, got {mem_contents:08x}"
	assert readd_val == mem_data, f"readd should be {mem_data:08x}, got {readd_val:08x}"



