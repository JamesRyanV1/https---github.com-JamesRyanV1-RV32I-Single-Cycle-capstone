import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer


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
    src_reg = 4
    imm = 8
    base_addr = 16
    store_data = 0xCAFEBABE

    # Preload register file values AFTER reset
    dut.register_file_inst.regs[base_reg].value = base_addr
    dut.register_file_inst.regs[src_reg].value = store_data

    # Verify preload
    await Timer(1, unit="ps")
    await ReadOnly()
    verify_base = int(dut.register_file_inst.regs[base_reg].value)
    verify_src = int(dut.register_file_inst.regs[src_reg].value)
    assert verify_base == base_addr, f"Register {base_reg} preload failed: expected {base_addr:08x}, got {verify_base:08x}"
    assert verify_src == store_data, f"Register {src_reg} preload failed: expected {store_data:08x}, got {verify_src:08x}"
    print(f"Preload verified: regs[{base_reg}]={verify_base:08x}, regs[{src_reg}]={verify_src:08x}")
    await RisingEdge(dut.clk)
	# Drive sw instruction
    dut.instruction_in.value = encode_sw(src_reg, base_reg, imm)

    await Timer(1, unit="ps")
    await ReadOnly()

    opcode = int(dut.decoder_inst.opcode.value)
    rs1_val = int(dut.decoder_inst.rs1.value)
    rs2_val = int(dut.decoder_inst.rs2.value)
    print(f"DEBUG: instruction = {encode_sw(src_reg, base_reg, imm):032b}")
    print(f"DEBUG: decoder.opcode = {opcode:07b} (expected {OPCODE_SW:07b})")
    print(f"DEBUG: decoder.rs1 = {rs1_val} (expected {base_reg})")
    print(f"DEBUG: decoder.rs2 = {rs2_val} (expected {src_reg})")

    mem_write = int(dut.control_inst.mem_write.value)
    alu_output = int(dut.alu_inst.alu_output.value)
    mem_addr = int(dut.data_memory_inst.address.value)
    write_data = int(dut.data_memory_inst.write_data.value)
    write_enable = int(dut.data_memory_inst.write_enable.value)

    print(f"DEBUG: control.mem_write = {mem_write}")
    print(f"DEBUG: alu_output = {alu_output:08x}")
    print(f"DEBUG: mem_address = {mem_addr:08x}")
    print(f"DEBUG: mem write_data = {write_data:08x}")
    print(f"DEBUG: mem write_enable = {write_enable}")

    assert mem_write == 1, f"control.mem_write should be 1, got {mem_write}"
    assert write_enable == 1, f"data_memory.write_enable should be 1, got {write_enable}"
    assert write_data == store_data, f"write_data should be {store_data:08x}, got {write_data:08x}"
    assert mem_addr == (base_addr + imm), f"address should be {base_addr + imm}, got {mem_addr}"
	# Memory write should occur on this rising edge
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)

    word_index = (base_addr + imm) >> 2
    mem_val = int(dut.data_memory_inst.mem[word_index].value)
    assert mem_val == store_data, f"Data memory should capture store data at computed address, got {mem_val:08x}"
    await Timer(1, unit="ps")
    await ReadOnly()
    