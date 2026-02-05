module control (
    input logic [6:0] op,
    input logic [2:0] func3,
    input logic [6:0] func7,
    input logic alu_zero,
    input logic alu_last_bit,

    output logic [1:0] register_source,
    output logic [3:0] alu_control,
    output logic [2:0] imm_source,
    output logic mem_read,
    output logic mem_write,
    output logic reg_write,
    output logic alu_source,
    output logic [2:0] pc_source,
    output logic [3:0] alu_op,
    output logic       jalr_override
);

always_comb begin
    // Default all outputs to 0
    register_source = 2'b0;
    alu_control = 4'b0000;
    imm_source = 3'b000;
    mem_read = 1'b0;
    mem_write = 1'b0;
    reg_write = 1'b0;
    alu_source = 1'b0;
    pc_source = 3'b000;
    alu_op = 4'b0000;
    jalr_override = 1'b0;

    case (op)
    // memory store instruction
        7'b0100011: begin  // SW
            mem_write = 1'b1;
            mem_read = 1'b0;
            reg_write = 1'b0;
            alu_source = 1'b1;      // use immediate
            imm_source = 3'b001;    // S-type
            alu_op = 4'b0000;       // add
        end
        // memory load instruction
        7'b0000011: begin  // LW
            register_source = 2'b00; // from data memory
            mem_write = 1'b0;
            mem_read = 1'b1;
            reg_write = 1'b1;
            alu_source = 1'b1;      // use immediate
            imm_source = 3'b000;    // I-type for memory loading
            alu_op = 4'b0000;       // add
        end
        // R-type instructions (register to register arithmetic)
        7'b0110011: begin
            register_source = 2'b01; // from alu result
            mem_write = 1'b0;
            mem_read = 1'b0;
            reg_write = 1'b1;
            alu_source = 1'b0;      // use register
            imm_source = 3'b000;    // not used
            case ({func7, func3})
                10'b0000000000: alu_op = 4'b0000; // ADD
                10'b0100000000: alu_op = 4'b0000; // SUB
                10'b0000000111: alu_op = 4'b0100; // AND
                10'b0000000110: alu_op = 4'b0101; // OR
                10'b0000000100: alu_op = 4'b0110; // XOR
                10'b0000000001: alu_op = 4'b0001; // SLL
                10'b0000000101: alu_op = 4'b0010; // SRL
                10'b0100000101: alu_op = 4'b0011; // SRA
                default: alu_op = 4'b0000; // default to ADD
            endcase
        end
        // I-type instructions (immediate to register arithmetic)
        7'b0010011: begin
            register_source = 2'b01; // from alu result
            mem_write = 1'b0;
            mem_read = 1'b0;
            reg_write = 1'b1;
            alu_source = 1'b1;      // use immediate
            imm_source = 3'b000;    // I-type
            case (func3)
                3'b000: alu_op = 4'b0000; // ADDI
                3'b111: alu_op = 4'b0100; // ANDI
                3'b110: alu_op = 4'b0101; // ORI
                3'b100: alu_op = 4'b0110; // XORI
                3'b001: alu_op = 4'b0001; // SLLI
                3'b101: begin
                    if (func7 == 7'b0000000)
                        alu_op = 4'b0010; // SRLI
                    else if (func7 == 7'b0100000)
                        alu_op = 4'b0011; // SRAI
                    else
                        alu_op = 4'b0000; // default to ADDI
                end
                default: alu_op = 4'b0000; // default to ADDI
            endcase
        end
        // branch instructions
        7'b1100011: begin
            mem_write = 1'b0;
            mem_read = 1'b0;
            reg_write = 1'b0;
            alu_source = 1'b0;      // use register
            imm_source = 3'b011;    // B-type
            alu_op = 4'b1000;       // branch operation (handled in branch unit)
            case (func3) // works with branch unit, should rename pc_source to be accurate
                3'b000: pc_source = 3'b001;          // BEQ
                3'b001: pc_source = 3'b010;          // BNE
                3'b100: pc_source = 3'b011;          // BLT
                3'b101: pc_source = 3'b100;          // BGE
                default: pc_source = 3'b000;           // default no branch
            endcase
        end
        7'b1101111 : begin  // JAL
            register_source = 2'b10; // from pc + 4
            mem_write = 1'b0;
            mem_read = 1'b0;
            reg_write = 1'b1;
            alu_source = 1'b0;      // not used
            imm_source = 3'b100;    // J-type
            pc_source = 3'b101;     // jump to target
        end
        7'b1100111: begin // JALR
            register_source = 2'b10; // from pc + 4
            mem_write = 1'b0;
            mem_read = 1'b0;
            reg_write = 1'b1;       // if its end of programmed stack, instead of link set rd to x0
            alu_source = 1'b1;      // use immediate
            imm_source = 3'b000;    // I-type
            pc_source = 3'b110;     // jump to target
            jalr_override = 1'b1;   // signal to override pc for jalr
        end
        
        default: ;
    endcase
end

endmodule