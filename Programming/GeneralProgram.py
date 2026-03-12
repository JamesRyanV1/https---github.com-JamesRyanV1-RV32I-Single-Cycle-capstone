import Instructions as i
class GeneralizedProgram:
    """
    A class to make programs that more easily can be modified and supports loops and nested loops
    """
    def __init__(self, instructions):
        self.instructions = instructions
        self.vars = {} # dict of variable name to register number, for my use in writing programss
    def get_instructions(self):
        return self.instructions
    def print_instructions(self):        
        for i in self.instructions:
            y = int(i, 2) if isinstance(i, str) else int(i)
            print(format(y & 0xFFFFFFFF, '032b'))
    def addLoop(self, loopInstructions, times, timesReg, countReg): # THE LOOP CAN BE A PROGRAM ITSELF: Loops within loops 
        """
        Adds a loop that will run the given string of instructions a constant number of times.
        Loop will be added at the end of loopInstructions, and will jump back to the start of loopInstructions in pc untill times is passed. times will have a set register
        Takes: 1d array of instructions made by instructions.py
        Takes: Int number of times to loop, the countReg, and the timesReg (regs 22-29 will be free to allow for a loop depth of 4)
        Adds loop to self.instructions
        """
        loopInit = i.makeList(
            i.addi(timesReg,0,times), # set timesReg to times
            i.addi(countReg,0,0) # set countReg to 0
        )
        self.instructions += loopInit
        loopStartAdress = len(self.instructions) # loop will be added at the end of current instructions
        self.instructions += loopInstructions
        # Branch immediates are PC-relative byte offsets.
        # In this CPU, taken branch updates PC as: pc <= pc + offset + 4.
        # Subtract 4 bytes so target lands exactly on loopStartAdress.
        bneIndex = len(self.instructions) + 1
        loopOffsetBytes = ((loopStartAdress - bneIndex) * 4) - 4
        self.instructions += i.makeList(
            i.addi(countReg,countReg,1), # increment loop counter
            i.bne(countReg,timesReg,loopOffsetBytes) # if loop counter != times, jump back to start of loop
        )

# testProgram = GeneralizedProgram(
#     i.makeList(
#         i.addi(1,0,5) # random instruction
#     )
# )
# testProgram.addLoop(
#     i.makeList(
#         i.addi(2,0,10) # random instruction to loop
#     ),
#     times=3,
#     timesReg=22,
#     countReg=23
# )
# testProgram.print_instructions()
testNestedLoop = GeneralizedProgram(i.makeList())
testNestedLoop.addLoop(
    i.makeList(
        i.addi(1,0,5) # random instruction to loop),
    ),
    times=3,
    timesReg=22,
    countReg=23
)
loopToNest = GeneralizedProgram(i.makeList())
loopToNest.addLoop(
    i.makeList(
        i.addi(2,0,10) # random instruction to loop),
    ),
    times=4,
    timesReg=26,
    countReg=27
)
# loopToNest.print_instructions()
testNestedLoop.addLoop(
    loopToNest.get_instructions()[:], # copy of the prorgram to nest.
    times=2,
    timesReg=24,
    countReg=25
)
# testNestedLoop.print_instructions()