module control (
    input logic [6:0] op,
    input logic [2:0] func3,
    input logic [6:0] func7, // for use later
    input logic alu_zero,
    input logic alu_last_bit,

    output logic [3:0] alu_control,
    output logic [2:0] imm_source,
    output logic mem_read,
    output logic mem_write,
    output logic reg_write,
    output logic alu_source,
    output logic pc_source,
    output logic [3:0] alu_op
);

always_comb begin
    // Default all outputs to 0
    alu_control = 4'b0000;
    imm_source = 3'b000;
    mem_read = 1'b0;
    mem_write = 1'b0;
    reg_write = 1'b0;
    alu_source = 1'b0;
    pc_source = 1'b0;
    alu_op = 4'b0000;

    case (op)
        7'b0100011: begin  // SW
            mem_write = 1'b1;
            mem_read = 1'b0;
            reg_write = 1'b0;
            alu_source = 1'b1;      // use immediate
            imm_source = 3'b001;    // S-type
            alu_op = 4'b0000;       // add
        end
        7'b0000011: begin  // LW
            mem_write = 1'b0;
            mem_read = 1'b1;
            reg_write = 1'b1;
            alu_source = 1'b1;      // use immediate
            imm_source = 3'b000;    // I-type
            alu_op = 4'b0000;       // add
        end
        default: ;
    endcase
end

endmodule