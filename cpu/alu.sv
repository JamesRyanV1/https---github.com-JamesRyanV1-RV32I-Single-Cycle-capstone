module alu (
    input logic clk,
    input logic rst,
    input logic [31:0] cntrl,
    input logic [31:0] d1,
    input logic [31:0] d2,

    output logic [31:0] alu_output,
    output logic zero;
    output logic last_bit;

 
);

case (cntrl) // the "cpu_" is needed to avoid naming issues
    cpu_add : output = d1 + d2;

    cpu_sub : output = d1 - d2; // does not work, will fix later (think binary adder issues with -(d2 > d1))

    cpu_or : output = d1 | d2;

    cpu_and : output = d1 & d2;

    cpu_xor : output = d1 ^ d2;



    default : alu_output = 0; 
endcase
endmodule