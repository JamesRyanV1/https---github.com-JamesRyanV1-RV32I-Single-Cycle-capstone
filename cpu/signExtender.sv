module signExtender (
    input logic [31:0] inst,
    input logic [2:0] imm_type,
    output logic [31:0] ext_imm
);
    
    case (imm_type)
        // turns the immediate into a 32 bit value, usefull
        3'b000: ext_imm = {{20{inst[31]}}, inst[31:20]}; // I type
    endcase
endmodule
