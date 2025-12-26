module alu (
    input logic clk,
    input logic rst,
    input logic [3:0] cntrl,
    input logic [31:0] d1,
    input logic [31:0] d2,

    output logic [31:0] alu_output,
    output logic zero,
    output logic last_bit
);

    always_comb begin
        case (cntrl)
            4'b0000: alu_output = d1 + d2;
            default : alu_output = 32'b0;
        endcase

        zero     = (alu_output == 32'b0);
        last_bit = alu_output[0];
    end
endmodule