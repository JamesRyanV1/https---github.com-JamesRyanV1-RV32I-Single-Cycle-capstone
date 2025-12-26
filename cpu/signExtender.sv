module signExtender (
    input logic clk,
    input logic rst,
    input  logic [31:0] inst,
    input  logic [2:0]  imm_type, // outputted by control, redundant needs removing

    output logic [31:0] ext_imm

);
    always_comb begin
        ext_imm = 32'b0; // default
        case (imm_type)
            3'b000: ext_imm = {{20{inst[31]}}, inst[31:20]}; // I-type
            // add other imm types here
            default: ext_imm = 32'b0;
        endcase
    end
endmodule
