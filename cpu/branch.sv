// branch unit module, specialized alu for branch comparisons

module branch_unit (
    input logic clk,
    input logic rst,
    input logic [31:0] d1,
    input logic [31:0] d2,
    input logic [2:0] cntrl, // branch control from control unit

    output logic take_branch
);

    always_comb begin
        take_branch = 1'b0; // default to no branch taken
        if(rst) begin
            take_branch = 1'b0;
        end else begin
            case (cntrl)
                3'b000: begin // NOP, no branch
                    take_branch = 1'b0;
                end
                3'b001: begin // BEQ
                    if (d1 == d2) begin
                        take_branch = 1'b1;
                    end
                    else begin
                        take_branch = 1'b0;
                    end
                end
                3'b010: begin // BNE
                    if (d1 != d2) begin
                        take_branch = 1'b1;
                    end
                    else begin
                        take_branch = 1'b0;
                    end
                end
                3'b011: begin // BLT
                    if ($signed(d1) < $signed(d2)) begin
                        take_branch = 1'b1;
                    end
                    else begin
                        take_branch = 1'b0;
                    end

                end
                3'b100: begin // BGE
                    if ($signed(d1) >= $signed(d2)) begin
                        take_branch = 1'b1;
                    end
                    else begin
                        take_branch = 1'b0;
                    end
                end
            
                default: take_branch = 1'b0; // default case, no branch
                3'b101: take_branch = 1'b1; // JAL handled in pc and register file
                3'b110: take_branch = 1'b0; // JALR not handled here
            endcase
        end
        end
endmodule