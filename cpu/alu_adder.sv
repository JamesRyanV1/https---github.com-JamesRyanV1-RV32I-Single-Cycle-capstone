module alu_adder (
    input logic [31:0] a, // operand a
    input logic [31:0] b, // the second operand
    output logic [31:0] sum // result of addition (and negative addition)
);
    assign sum = a + b;
endmodule

