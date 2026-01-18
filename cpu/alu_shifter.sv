module alu_shifter (
    input logic [31:0] a,
    input logic [4:0]  shamt,
    input logic [1:0]  shift_type, // 00: logical left, 01: logical right, 10: arithmetic right
    output logic [31:0] shift_result
);
    always_comb begin
        case (shift_type)
            2'b00: shift_result = a << shamt; // logical left
            2'b01: shift_result = a >> shamt; // logical right
            2'b10: shift_result = $signed(a) >>> shamt; // arithmetic right
            default: shift_result = 32'b0;
        endcase
    end
endmodule
