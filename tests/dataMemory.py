import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer
import logging
import random as rd


@cocotb.test()
async def dataMemory(dut):
    """Basic testbench for the `dataMemory` module.

    Tests:
    - Reset clears all words to 0
    - Writes update the targeted word on rising clock edge
    - Writes to address 0 are ignored
    - Out-of-bounds writes/reads return/keep 0
    - Randomized write/read stress test
    """

    log = logging.getLogger("cocotb.test")

    # Attempt to read WORDS parameter from DUT; fall back to 64
    try:
        WORDS = int(dut.WORDS.value)
    except Exception:
        WORDS = 64

    # Start clock
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Helper to pulse reset (rst_data synchronous to posedge)
    async def reset_pulse():
        dut.rst_data.value = 1
        # wait a couple cycles
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)
        dut.rst_data.value = 0
        await RisingEdge(dut.clk)

    # Ensure initial signals
    dut.write_enable.value = 0
    dut.address.value = 0
    dut.write_data.value = 0

    # Reset memory and verify cleared
    await reset_pulse()

    # Software model of memory contents
    model = {i: 0 for i in range(WORDS)}

    for idx in range(WORDS):
        dut.address.value = idx * 4
        await ReadOnly()
        rd_val = int(dut.read_data.value)
        assert rd_val == 0, f"Memory not zero at index {idx}, got {rd_val}"
        await RisingEdge(dut.clk)

    log.info("Reset cleared all %d words", WORDS)

    # Test write to a normal address (address != 0)
    test_addr = 4  # index 1
    test_val = 0xDEADBEEF
    dut.address.value = test_addr
    dut.write_data.value = test_val
    dut.write_enable.value = 1
    await RisingEdge(dut.clk)  # write happens on posedge
    dut.write_enable.value = 0

    # Read back
    dut.address.value = test_addr
    await ReadOnly()
    rd_val = int(dut.read_data.value)
    assert rd_val == test_val, f"Write/read mismatch at {test_addr}: expected {hex(test_val)}, got {hex(rd_val)}"
    model[1] = test_val  # keep model in sync
    log.info("Write/read OK at address %d: %s", test_addr, hex(rd_val))

    # Test write ignored at address 0
    await RisingEdge(dut.clk)  # ensure clean edge (needed because this is now the readonly stage of the simulation)
    dut.address.value = 0
    dut.write_data.value = 0x12345678
    dut.write_enable.value = 1
    await RisingEdge(dut.clk)
    dut.write_enable.value = 0
    dut.address.value = 0
    await ReadOnly()
    rd_val = int(dut.read_data.value)
    assert rd_val == 0, f"Write to address 0 should be ignored, but read {hex(rd_val)}"
    log.info("Write to address 0 correctly ignored")

    # Test out-of-bounds write/read (index == WORDS)
    await RisingEdge(dut.clk)  # ensure clean edge (im not taking any changes istg)
    oob_addr = WORDS * 4
    dut.address.value = oob_addr
    dut.write_data.value = 0xCAFEBABE
    dut.write_enable.value = 1
    await RisingEdge(dut.clk)
    dut.write_enable.value = 0
    dut.address.value = oob_addr
    await RisingEdge(dut.clk)  # just making sure
    await ReadOnly()
    rd_val = int(dut.read_data.value)
    assert rd_val == 0, f"Out-of-bounds read should be 0, got {hex(rd_val)}"
    log.info("Out-of-bounds write/read ignored as expected")
    await RisingEdge(dut.clk)  # just making sure
    # Randomized stress test: perform random writes and maintain a software model
    operations = 2000000
    # model already initialized and contains any prior writes

    for _ in range(operations):
        await RisingEdge(dut.clk)  # advance time each op

        # Bias toward valid, nonzero addresses; occasional OOB and zero
        choice = rd.random()
        if choice < 0.7:
            addr_word = rd.randrange(1, WORDS)    # valid, nonzero
        elif choice < 0.85:
            addr_word = 0                         # zero address (ignored writes)
        else:
            addr_word = WORDS + rd.randrange(0, 3)  # out-of-bounds

        addr = addr_word * 4
        value = rd.getrandbits(32)

        if rd.choice([True, False]):
            # write
            dut.address.value = addr
            dut.write_data.value = value
            dut.write_enable.value = 1
            await RisingEdge(dut.clk)      # write on posedge
            dut.write_enable.value = 0
            if addr != 0 and addr_word < WORDS:
                model[addr_word] = value
        else:
            # read: drive, let comb settle, then sample
            dut.write_enable.value = 0
            dut.address.value = addr
            await Timer(1, unit="ps")
            await ReadOnly()
            rd_val = int(dut.read_data.value)
            expected = model.get(addr_word, 0)
            assert rd_val == expected, (
                f"Random read mismatch at {addr} (word {addr_word}): "
                f"expected {hex(expected)}, got {hex(rd_val)}"
            )

