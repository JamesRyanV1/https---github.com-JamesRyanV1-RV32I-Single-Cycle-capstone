# source .venv/bin/activate


import Instructions as i
import HelperPrograms as hp
import time
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer
# import pygame
# from pygame.locals import *
# import sys
# import select

# IMPORTANT THINGS
# x31 is the input register,
# x30 will be the output register,
# x0 is the zero register,
# x8-12 are reserved for snake board handling in the snake game
# x1 is the stack pointer
# x2 is the return adress
# x3 is the global pointer if needed, not for snake game
# x4 is the current val

# ANOTHER IMPORTANT THING
# I need to inject directly into the simulation. This means that nothing can freeze the creation of the simulation or its running outside of the testbench.
# All pygame can do is update the single input variable, and read the output variable.

# def key_pressed():
#     if sys.platform.startswith("win"):
#         import msvcrt
#         if not msvcrt.kbhit():
#             return None
#         key = msvcrt.getch()
#         if key in (b"\x00", b"\xe0"):
#             key = msvcrt.getch()
#         return key[0]
#     if not hasattr(sys.stdin, "fileno") or not sys.stdin.isatty():
#         return None
#     ready = select.select([sys.stdin], [], [], 0) == ([sys.stdin], [], [])
#     if not ready:
#         return None
#     return ord(sys.stdin.read(1))

# # Global variable to store the last pressed key for pygame
# _last_key = None

# def init_pygame_input():
#     """Initialize a small pygame window for key input capture."""
#     pygame.init()
#     screen = pygame.display.set_mode((300, 100))
#     pygame.display.set_caption("Snake Input (Keep Focused)")
#     return screen

# def get_pygame_key():
#     """Poll pygame events and return the last key pressed (or None)."""
#     global _last_key
#     for event in pygame.event.get():
#         if event.type == pygame.QUIT:
#             pygame.quit()
#             return None
#         elif event.type == pygame.KEYDOWN:
#             # Convert pygame key to ASCII-like value
#             if event.key < 256:
#                 _last_key = event.key
#             elif event.key == pygame.K_UP:
#                 _last_key = ord('w')  # Map arrow keys to WASD
#             elif event.key == pygame.K_DOWN:
#                 _last_key = ord('s')
#             elif event.key == pygame.K_LEFT:
#                 _last_key = ord('a')
#             elif event.key == pygame.K_RIGHT:
#                 _last_key = ord('d')
    
#     key_to_return = _last_key
#     _last_key = None  # Clear after reading
#     return key_to_return

# def printLedArr():
#     ROWS, COLS = 16, 16
#     CELL_SIZE = 30
#     WIDTH, HEIGHT = COLS * CELL_SIZE, ROWS * CELL_SIZE

#     # Initialize Pygame
#     pygame.init()
#     screen = pygame.display.set_mode((WIDTH, HEIGHT))
#     pygame.display.set_caption("grid")
#     leds = [[(0, 0, 0) for _ in range(COLS)] for _ in range(ROWS)]
#     leds[5][5] = (255, 0, 0)  # Turn one LED red
#     leds[10][10] = (0, 255, 0) # Turn one LED green
#     # Main loop
#     running = True
    
#     while running:
#         if __name__ == "__main__": 
#             key_value = key_pressed()
#             if key_value is not None:
#                 print(f"Key pressed: {key_value}")
#             else:
#                 pass
#         for event in pygame.event.get():
#             if event.type == pygame.QUIT:
#                 running = False
#         screen.fill((0, 0, 0))
#         for row in range(ROWS):
#             for col in range(COLS):
#                 pygame.draw.rect(
#                     screen,
#                     leds[row][col],
#                     (col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE - 2, CELL_SIZE - 2)
#                 )

#         pygame.display.flip()

#     pygame.quit()
# printLedArr() # remove if running the actual testbench

# # remove if running the actual testbench
# if __name__ == "__main__": 
#     while True:
#         key_value = key_pressed()
#         if key_value is not None:
#             print(f"Key pressed: {key_value}")
#         else:
#             pass
# arr = hp.iterate_arr_type(hp.load_snake_array, 0xfff, 16, 16) # input instructions here in i.instruction(), i.instruction, format
# arr = (hp.z + [0,0,0,0])# premade list in hp

# arr = hp.fillRandomArray + [0,0,0,0] # xor shift and 
arr = hp.x33 + [0,0,0,0] # full snake game, change this to run different programs, make sure to end with 4 0s to signify end of program for now, eventually change this to an actual estop instruction when i add that
@cocotb.test()
async def run_instructions(dut):
    # Initialize pygame window for input capture
    # screen = init_pygame_input()
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    
    # Hold reset for one cycle to clear state
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    
    # Deassert reset before loading memories so reset doesn't clear them
    dut.rst.value = 0
    
    # loads instruction memory with the given program
    for i in range(len(arr)):
        # Instructions can be either binary strings or integers, so handle both (ooops)
        if isinstance(arr[i], str):
            dut.instruction_memory_inst.mem[i].value = int(arr[i], 2)
        else:
            dut.instruction_memory_inst.mem[i].value = arr[i]

    # Memory needs to be preloaded with data for the program. 
    # load 16 into 16, both rows and columns will be 16
    # load 2**8 with the base adress of the array

    # MEMORY PRELOADS
    dut.data_memory_inst.mem[1].value = 5120  # Base address in bytes (word index 1280)
    dut.data_memory_inst.mem[2].value = 16   # Number of rows
    dut.data_memory_inst.mem[3].value = 16   # Number of columns
    seed = int(time.time_ns()) & 0xFFFFFFFF
    dut.register_file_inst.regs[30].value = seed  # Initial seed for xorshift state in x30
    dut.register_file_inst.regs[31].value = seed  # Mirror seed for visibility

    # Start execution on next clock edge
    await RisingEdge(dut.clk)
    
    # Run the instructions ASSUMES THERE IS AN ESTOP OR SMTN THAT STOPS IT, I HAVNT IMPLIMENTED THIS YET BUT IT JS WORKS IN TB
    dut.pc_inst.pc.value = 0  # Ensure PC starts at 0
    cycle_count = 0
    max_cycles = 30004
    last_mem_write_addr = None
    last_mem_write_val = None
    base_addr = 5120
    base_idx = base_addr >> 2
    end_addr = base_addr + (256 * 4)
    arrays_printed = 0
    dumped_this_pass = False
    written_indices = set()
    prev_mem = [int(dut.data_memory_inst.mem[base_idx + i].value) for i in range(256)]
    
    while arr[int(dut.pc_inst.pc_out.value) // 4] != 0:
        # print(arr[int(dut.pc_inst.pc_out.value) // 4])
        # print(dut.pc_inst.pc_out.value, int(dut.pc_inst.pc_out.value) // 4)
        
        # Debug: print key registers every 100 cycles
        if cycle_count % 100 == 0:
            print(f"\n[Cycle {cycle_count}] PC={int(dut.pc_inst.pc_out.value)}, "
                  f"x4={int(dut.register_file_inst.regs[4].value)}, "
                  f"x8={int(dut.register_file_inst.regs[8].value)}, "
                  f"x31={int(dut.register_file_inst.regs[31].value)}")
        
        val = 0
        key_value = 47  # Poll pygame for key input
        dut.input_data.value = 3
        temp = dut.register_file_inst.regs[30].value
        await RisingEdge(dut.clk)
        temp = int(dut.register_file_inst.regs[30].value)
        await Timer(1, units="ns")
        
        # # Check if a store happened
        # current_x31 = int(dut.register_file_inst.regs[31].value)
        # if int(dut.data_memory_inst.write_enable.value) == 1:
        #     write_addr = int(dut.data_memory_inst.address.value)
        #     if write_addr != 0 and write_addr != last_mem_write_addr:
        #         # Track stores into the array region (including zero values)
        #         if base_addr <= write_addr < end_addr:
        #             idx = (write_addr >> 2) - base_idx
        #             if 0 <= idx < 256:
        #                 written_indices.add(idx)
        #                 mem_val = int(dut.data_memory_inst.mem[base_idx + idx].value)
        #                 print(f"[Cycle {cycle_count}] STORE DETECTED: mem[{base_idx + idx}] = {mem_val}, x31={current_x31}")
        #         last_mem_write_addr = write_addr

        # # Fallback: detect writes by scanning for changes in the 16x16 region
        # for offset in range(256):
        #     current_val = int(dut.data_memory_inst.mem[base_idx + offset].value)
        #     if current_val != prev_mem[offset]:
        #         written_indices.add(offset)
        #         prev_mem[offset] = current_val
        
        # cycle_count += 1
        # if cycle_count >= max_cycles:  # Stop after max_cycles for debugging
        #     print(f"\nStopped after {cycle_count} cycles (max_cycles={max_cycles})")
        #     break
        
        # print(temp, val)
        # # Dump after a full array is written: either wrap to base or reach end address
        # if not dumped_this_pass and len(written_indices) >= 256:
        #     arrays_printed += 1
        #     print("\n\nMemory dump at addresses 1280-1304 (first few expected locations):")
        #     print(dut.register_file_inst.regs[4].value)
        #     for i in range(25):
        #         val = int(dut.data_memory_inst.mem[base_idx + i].value)
        #         print(f"mem[{base_idx + i}] = {val}")
            
        #     print("\n\nFormatted 16x16 array from memory:")
        #     for i in range(256):ma
        #         break
        #     dumped_this_pass = True
        #     written_indices.clear()
    if not dumped_this_pass:
        print("\n\nUnconditional memory dump (array may be partially filled):")
        for i in range(256):
            val = int(dut.data_memory_inst.mem[base_idx + i].value)
            print(f"{val:3}", end=" ")
            if (i + 1) % 16 == 0:
                print()
    assert True
    # # pygame.quit()  # kill pygame when done
    # change this assertion to something usefull depending on the program (last expected value for traceable programs, otherwise idk)