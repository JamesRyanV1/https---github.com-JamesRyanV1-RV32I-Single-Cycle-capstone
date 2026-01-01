module alu_logic (
    input logic  [31:0] a,
    input logic  [31:0] b,
    input logic  [3:0]  cntrl,
    output logic [31:0] logic_output
);
    always_comb begin
        case (cntrl)
            4'b0100: logic_output = a & b; // AND
            4'b0101: logic_output = a | b; // OR
            4'b0110: logic_output = a ^ b; // XOR
            default : logic_output = 32'b0; // DEFAULT
        endcase
    end
endmodule