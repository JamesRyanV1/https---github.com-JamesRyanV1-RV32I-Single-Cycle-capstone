import Instructions as i
import HelperPrograms as hp
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly
import pygame
from pygame.locals import *
import sys
import select
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

def key_pressed():
    if sys.platform.startswith("win"):
        import msvcrt
        if not msvcrt.kbhit():
            return None
        key = msvcrt.getch()
        if key in (b"\x00", b"\xe0"):
            key = msvcrt.getch()
        return key[0]
    if not hasattr(sys.stdin, "fileno") or not sys.stdin.isatty():
        return None
    ready = select.select([sys.stdin], [], [], 0) == ([sys.stdin], [], [])
    if not ready:
        return None
    return ord(sys.stdin.read(1))

# Global variable to store the last pressed key for pygame
_last_key = None

def init_pygame_input():
    """Initialize a small pygame window for key input capture."""
    pygame.init()
    screen = pygame.display.set_mode((300, 100))
    pygame.display.set_caption("Snake Input (Keep Focused)")
    return screen

def get_pygame_key():
    """Poll pygame events and return the last key pressed (or None)."""
    global _last_key
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            return None
        elif event.type == pygame.KEYDOWN:
            # Convert pygame key to ASCII-like value
            if event.key < 256:
                _last_key = event.key
            elif event.key == pygame.K_UP:
                _last_key = ord('w')  # Map arrow keys to WASD
            elif event.key == pygame.K_DOWN:
                _last_key = ord('s')
            elif event.key == pygame.K_LEFT:
                _last_key = ord('a')
            elif event.key == pygame.K_RIGHT:
                _last_key = ord('d')
    
    key_to_return = _last_key
    _last_key = None  # Clear after reading
    return key_to_return

def printLedArr():
    ROWS, COLS = 16, 16
    CELL_SIZE = 30
    WIDTH, HEIGHT = COLS * CELL_SIZE, ROWS * CELL_SIZE

    # Initialize Pygame
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("grid")
    leds = [[(0, 0, 0) for _ in range(COLS)] for _ in range(ROWS)]
    leds[5][5] = (255, 0, 0)  # Turn one LED red
    leds[10][10] = (0, 255, 0) # Turn one LED green
    # Main loop
    running = True
    
    while running:
        if __name__ == "__main__": 
            key_value = key_pressed()
            if key_value is not None:
                print(f"Key pressed: {key_value}")
            else:
                pass
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        screen.fill((0, 0, 0))
        for row in range(ROWS):
            for col in range(COLS):
                pygame.draw.rect(
                    screen,
                    leds[row][col],
                    (col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE - 2, CELL_SIZE - 2)
                )

        pygame.display.flip()

    pygame.quit()
printLedArr() # remove if running the actual testbench

# remove if running the actual testbench
if __name__ == "__main__": 
    while True:
        key_value = key_pressed()
        if key_value is not None:
            print(f"Key pressed: {key_value}")
        else:
            pass
arr = i.makeList() # input instructions here in i.instruction(), i.instruction, format
@cocotb.test()
async def run_instructions(dut):
    # Initialize pygame window for input capture
    screen = init_pygame_input()
    
    @cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    async def reset_dut():
        dut.rst.value = 1
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)
        dut.rst.value = 0
        
    await reset_dut()

    # loads instruction memory with the given program
    # make arr, run snake

    for i in range(len(arr)):
        dut.instruction_memory_inst.memory[i*4].value = arr[i]  # Load instruction into instruction memory
    # ALSO PRELOAD REGISTERS AND NEEDED MEMORY DURING THIS CLOCK CYCLE 
    
    # Run the instructions ASSUMES THERE IS AN ESTOP OR SMTN THAT STOPS IT, I HAVNT IMPLIMENTED THIS YET BUT IT JS WORKS IN TB
    while arr[dut.pc.value // 4] != 0:
        key_value = get_pygame_key()  # Poll pygame for key input
        dut.input_data.value = key_value if key_value is not None else 0
        await RisingEdge(dut.clk)
        #print(f"PC: {dut.pc.value}, x30 (output): {dut.register_file_inst.registers[30].value}, x31 (input): {dut.register_file_inst.registers[31].value}")
    
    pygame.quit()  # Clean up pygame when done
    assert True # change this assertion to something usefull depending on the program (last expected value for traceable programs, otherwise idk)