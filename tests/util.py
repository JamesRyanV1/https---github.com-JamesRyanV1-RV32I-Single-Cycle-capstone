import random
# This file is for little testbench utils

# generates a random binary function of a certian length of bits. Max bits referes to the amount of non 0 bits, none unless speficied
def random_binary(width, max_bits=None,signextend = False):
    numb = ""
    zeros = ""
    if max_bits == None:
        max_bits = width
    for i in range(32-(width - max_bits)):
        numb = numb + f"{random.randint(0,1)}"

    # generates the zeros or ones at the start if signextended
    if max_bits != width:
        if signextend:
            for i in range(32-max_bits):
                zeros = zeros + f"{numb[0]}"
        # if its not sign extended or most signifigant bit is 0, paste zeros instead
        else:
            for i in range (32-max_bits):
                zeros = zeros + "0"  
     
    return (zeros + numb)
        


print(random_binary(32,12,True))

