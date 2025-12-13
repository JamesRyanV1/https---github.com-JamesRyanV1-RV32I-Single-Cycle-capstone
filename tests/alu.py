# import cocotb
# from cocotb import clock                  (i think this is a thing)
# import random


# @cocotb(test)

# x, y = some 32 bit number under 31'b1 (no handling for overflow right now, handled later)

# Instantly 
    # Set d1 to x and d2 to y
    # Set control to be 4'b0


# on clock

    # nothing

# after clock

    # check output port to make sure its the sum of the two 32 bit numbers


# @cocotb(test)

# x, y = some 32 bit numbers, doesnt matter
# instantly
    # set d1 and d2 to x, y
    # set control to 4'b1 (not in the alu)

# on clock
    #wait
# on low edge clock
    # check to make sure alu output is 0
        # ERROR POSSIBLE HERE IF IT NEEDS TO BE 32'B0 INSTEAD OF JUST 0