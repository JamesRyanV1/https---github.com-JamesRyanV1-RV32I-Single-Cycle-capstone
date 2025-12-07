module control (
    input logic [6:0] op,
    input logic [3:0] func3,
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
);

always_comb begin

    case (op)
        6'b000011 : begin // type for lw
            reg_write = 1'b1,
            imm_source = 3'b000,
            mem_write = 1'b0, // no writing for this
            mem_read = 1'b1 // Read enabled bc it has to be
            alu_source = 1'b1 // imm

        end

    endcase
end

endmodule