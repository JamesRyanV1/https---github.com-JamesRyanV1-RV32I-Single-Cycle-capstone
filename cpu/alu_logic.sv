module alu_logic (
    input logic  [31:0] a,
    input logic  [31:0] b,
    input logic  [3:0]  cntrl,
    output logic [31:0] logic_output
);
    always_comb begin
        case (cntrl)
            4'b0100: begin // AND
                logic_output = a & b; // System Verilog actualy makes it a pain to do bitwise & in fast time, not sure how a loop would work
            end
            4'b0101: begin // OR
                logic_output = a | b; // ty sv
            end
            4'b0110: begin // XOR
                logic_output = a ^ b; // ty again sv
            end
            default : begin // DEFAULT CASE
                logic_output = 32'b0; 
            end
        endcase
    end
endmodule