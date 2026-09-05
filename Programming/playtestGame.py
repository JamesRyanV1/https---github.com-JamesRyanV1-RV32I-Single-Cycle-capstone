from snakeHelpers import test_game, real_game # game to be tested
import cocotb
from cocotb.triggers import Timer
from cocotb.clock import Clock
from cocotb.clock import RisingEdge

try:
    import pygame
except Exception:
    pygame = None


RIGHT = 37
UP = 38
LEFT = 39
DOWN = 40

OPPOSITE = {
    RIGHT: LEFT,
    LEFT: RIGHT,
    UP: DOWN,
    DOWN: UP,
}


class PygameGridRenderer:
    def __init__(self, rows=16, cols=16, cell_size=28, initial_input=RIGHT):
        self.rows = rows
        self.cols = cols
        self.cell_size = cell_size
        self.screen = None
        self.clock = None
        self.current_input = initial_input
        self.keep_running = True

    def _handle_events(self):
        if self.screen is None:
            return

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.keep_running = False
            elif event.type == pygame.KEYDOWN:
                new_input = None
                if event.key == pygame.K_RIGHT:
                    new_input = RIGHT
                elif event.key == pygame.K_UP:
                    new_input = UP
                elif event.key == pygame.K_LEFT:
                    new_input = LEFT
                elif event.key == pygame.K_DOWN:
                    new_input = DOWN

                if new_input is not None and new_input != OPPOSITE.get(self.current_input):
                    self.current_input = new_input

    def start(self):
        if pygame is None:
            return False
        pygame.init()
        width = self.cols * self.cell_size
        height = self.rows * self.cell_size
        self.screen = pygame.display.set_mode((width, height))
        pygame.display.set_caption("interpreted output")
        self.clock = pygame.time.Clock()
        return True

    def draw_frame(self, signed_cells):
        if self.screen is None:
            return True

        self._handle_events()
        if not self.keep_running:
            return False

        self.screen.fill((18, 18, 18))
        for idx, cell in enumerate(signed_cells):
            r = idx // self.cols
            c = idx % self.cols
            x = c * self.cell_size
            y = r * self.cell_size

            if cell == -255:
                color = (220, 60, 60)   # apple
            elif cell > 0:
                color = (70, 220, 110)   # snake
            else:
                color = (35, 35, 35)     # empty

            pygame.draw.rect(self.screen, color, (x + 1, y + 1, self.cell_size - 2, self.cell_size - 2))

        pygame.display.flip()
        self.clock.tick(30)
        return True

    def get_input(self):
        return self.current_input

    def close(self):
        if pygame is not None and self.screen is not None:
            pygame.quit()

@cocotb.test()
async def playtest_game_loop(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Player-driven input (x5): updated by arrow keys in pygame window.
    input_reg_value = RIGHT

    async def reset():
        dut.rst.value = 1
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)
        dut.rst.value = 0
        await Timer(1, unit="ps")
    await reset()
    dut.input_data.value = input_reg_value
    dut.register_file_inst.regs[5].value = input_reg_value
    # load program
    # loads instruction memory with the given program
    instructions = real_game.get_program()
    instructions_int = [int(instr, 2) if isinstance(instr, str) else int(instr) for instr in instructions]
    # print(instructions)
    capture_active = False
    prev_out_reg = 0
    prev_pc_idx = None
    frame_count = 0
    frame = []
    max_frames = 5000
    captured_frames = 0
    renderer = PygameGridRenderer(rows=16, cols=16, cell_size=28, initial_input=input_reg_value)
    renderer_active = renderer.start()
    if not renderer_active:
        raise RuntimeError("pygame is required for player controls. Install pygame and run on Debian with a display.")
    for i in range(len(instructions_int)):
        # Instructions can be either binary strings or integers, so handle both (ooops)
        dut.instruction_memory_inst.mem[i].value = instructions_int[i]

    def is_output_lw(instr_word: int) -> bool:
        opcode = instr_word & 0x7F
        rd = (instr_word >> 7) & 0x1F
        funct3 = (instr_word >> 12) & 0x7
        rs1 = (instr_word >> 15) & 0x1F
        imm12 = (instr_word >> 20) & 0xFFF
        return opcode == 0x03 and funct3 == 0x2 and rd == 6 and rs1 == 3 and imm12 == 0

    def to_signed32(v: int) -> int:
        return v if v < 0x80000000 else v - 0x100000000

    while int(dut.pc_inst.pc_out.value) // 4 < len(instructions_int):
        # Drive input directly into x5 each cycle.
        dut.input_data.value = input_reg_value
        dut.register_file_inst.regs[5].value = input_reg_value
        await RisingEdge(dut.clk)
        curr_out_reg = int(dut.register_file_inst.regs[6].value)
        pc_idx = int(dut.pc_inst.pc_out.value) // 4
        just_executed_output_lw = (
            prev_pc_idx is not None
            and 0 <= prev_pc_idx < len(instructions_int)
            and is_output_lw(instructions_int[prev_pc_idx])
        )
        # detect rising edge of 0xFF (new occurrence, not continuation)
        rising_edge = (curr_out_reg == 0xFF and prev_out_reg != 0xFF)
        if rising_edge and not capture_active:
            capture_active = True
            frame = []
            frame_count = 0
        prev_out_reg = curr_out_reg

        if capture_active and frame_count < 256 and just_executed_output_lw:
            frame_count += 1
            frame.append(curr_out_reg)
        prev_pc_idx = pc_idx
        if frame_count >= 256:
            captured_frames += 1
            print(f"frame {captured_frames}")
            signed_frame = [to_signed32(v) for v in frame]
            for row in range(16):
                row_vals = frame[row * 16:(row + 1) * 16]
                print([to_signed32(v) for v in row_vals])

            if renderer_active:
                keep_running = renderer.draw_frame(signed_frame)
                if not keep_running:
                    break

            input_reg_value = renderer.get_input()
            print(f"input -> {input_reg_value}")

            frame = []
            frame_count = 0
            capture_active = False
            if captured_frames >= max_frames:
                break

    renderer.close()