module alu (
    input logic clk,
    input logic rst,
    input logic [3:0] cntrl,
    input logic [31:0] d1,
    input logic [31:0] d2,

    output logic [31:0] alu_output,
    output logic zero;
    output logic last_bit;

 
);

case (cntrl) // the "cpu_" is needed to avoid naming issues
    4'b0000: alu_output = d1 + d2



    default : alu_output = 0; 
endcase
endmodule