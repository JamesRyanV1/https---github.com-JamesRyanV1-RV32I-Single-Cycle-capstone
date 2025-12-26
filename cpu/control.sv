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

    case (op)
    // zeros on default
    default : begin
            reg_write   = 1'b0;
            imm_source  = 3'b000;
            mem_write   = 1'b0;
            mem_read    = 1'b0;
            alu_source  = 1'b0;
            alu_op      = 4'b0000;
            alu_control = alu_op;
        end
    7'b0000011 : begin // type for lw (just for lw rn, nested case needed later for more func3s per inst type)
            reg_write   = 1'b1;
            imm_source  = 3'b000;
            mem_write   = 1'b0; // no writing for this
            mem_read    = 1'b1; // Read enabled bc it has to be
            alu_source  = 1'b1; // imm
            alu_op      = 4'b0000; // (add)
            alu_control = alu_op;

        end

    endcase
end

endmodule