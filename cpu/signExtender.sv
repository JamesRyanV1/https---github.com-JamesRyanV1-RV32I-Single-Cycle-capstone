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
            3'b000: ext_imm = {{20{inst[31]}}, inst[31:20]}; // I-type immediate (Load, ALU I-type)
            3'b001: ext_imm = {{20{inst[31]}}, inst[31:25], inst[11:7]}; // S-type immediate (Store)
            3'b010: ext_imm = 32'b0; // R-type (no immediate needed)
            // b type immediate (Branch)
            3'b011: ext_imm = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
            3'b100: ext_imm = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0}; // J-type immediate (JAL)
            default: ext_imm = 32'b0;
        endcase
    end
endmodule
