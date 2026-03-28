import GeneralProgram as gp
import Instructions as i

class Array:
    """
    A class to make, manipulate, and print 2nd dimensional arrays in memory.
    """
    def __init__(self, base_address, x_size, y_size, x_reg, y_reg, base_address_reg):
        """
        base_address: int, the base address of the array in memory, must be word-aligned
        x_size: int, the size of the array in the x dimension
        y_size: int, the size of the array in the y dimension
        x_reg: str, the register to use for the x index
        y_reg: str, the register to use for the y index
        base_address_reg: str, the register to use for the base address
        """
        self.base_address = base_address
        self.x_size = x_size
        self.y_size = y_size
        self.x_reg = x_reg
        self.y_reg = y_reg
        self.base_address_reg = base_address_reg
        self.program = gp.GeneralizedProgram([])
        self.program.instructions += i.makeList(
            i.addi(x_reg, 0, 0), # initialize x index register
            i.addi(y_reg, 0, 0), # initialize y index register
            i.addi(base_address_reg, 0, base_address) # load base address into base_address_reg
        )
    def game_loop(self, programs):
        """
        programs: list of GeneralizedProgram objects, each containing instructions to run for each (x,y) pair in the array.
        Each program will run fully, then the next program will run
        Uses register 20 for x_size and register 30 as an always-true loop condition.
        """
        inLoop = gp.GeneralizedProgram([])
        x_size_reg = 20
        always_true_reg = 30
        # Capture one-time setup done before the infinite game loop is appended.
        # This includes Array __init__ register setup and any caller-added preloop init instructions.
        self.setup_instructions = self.program.get_instructions()[:]
        programs = [program.get_instructions() for program in programs]
        looping_programs = []
        for p, program_instructions in enumerate(programs):
            loop_program = gp.GeneralizedProgram([])
            loop_program.instructions += i.makeList(
                i.addi(self.x_reg, 0, 0), # reset x index for this program pass
                i.addi(self.y_reg, 0, 0), # reset y index for this program pass
                i.addi(self.base_address_reg, 0, self.base_address), # reset address to start of array
                i.addi(x_size_reg, 0, self.x_size) # load x dimension for row wrapping
            )
            loop_program.addLoop(
                program_instructions + i.makeList(
                    i.addi(self.base_address_reg, self.base_address_reg, 4), # advance to next element address
                    i.addi(self.x_reg, self.x_reg, 1), # advance x index
                    i.bne(self.x_reg, x_size_reg, 8), # if still in current row, skip index reset
                    i.addi(self.x_reg, 0, 0), # wrap x index to start of row
                    i.addi(self.y_reg, self.y_reg, 1) # advance y index when row wraps
                ),
                times=self.x_size * self.y_size,
                timesReg=22+2*p,
                countReg=23+2*p
            ) # use regs 22-29 for loop counters and limits, so we can have up to 6 nested loops (probably will never need that many)
            looping_programs.append(loop_program)
        self.single_tic_instructions = [instr for program in looping_programs for instr in program.get_instructions()]
        inLoop.instructions += i.makeList(
            i.addi(always_true_reg, 0, 1) # keep condition register non-zero so while loop is always true
        )
        inLoop.whileLoop(
            self.single_tic_instructions, # flatten program passes over the array
            conditionReg=always_true_reg # loop forever (while true)
        )
        # update self.program to include the game loop
        self.program.instructions += inLoop.get_instructions()

    def get_single_tic(self):
        """Returns instructions for one full pass over the array (no outer while loop), for use by Game."""
        return self.single_tic_instructions

    def get_setup_instructions(self):
        """Returns one-time setup instructions to run before the Game outer loop starts."""
        return self.setup_instructions

    def get_program(self):
        return self.program.get_instructions()

class Game():
    """
    Takes an array that already has a game loop set up with.
    Adds stuff to be run once per tic, not once per (x,y) pair to the start
    Runs this in a loop forever, so it will run the instructions, then the array game_loop will run, repeat.
    """
    def __init__(self, array, tic_program):
        self.array = array
        self.tic_program = tic_program
        self.program = gp.GeneralizedProgram([])

        # Run array/setup initialization once before entering the forever game loop.
        self.program.instructions += array.get_setup_instructions()

        # make loop
        always_true_reg = 15  # reg 15 is unused by all programs; reg 30 is clobbered by xorshift
        self.program.instructions += i.makeList(
            i.addi(always_true_reg, 0, 1) # keep condition register non-zero so while loop is always true
        )
        self.program.whileLoop(
            tic_program.get_instructions() + array.get_single_tic(),
            conditionReg=always_true_reg # loop forever (while true)
        )
    def get_program(self):
        return self.program.get_instructions()
