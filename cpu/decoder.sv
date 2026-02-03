module decoder (
    input logic clk,
    input logic rst,
    input logic [31:0] instruction,
    
    output logic [3:0] inst_type,
    output logic [4:0] rd,
    output logic [4:0] rs1,
    output logic [4:0] rs2,
    output logic [2:0] func3,
    output logic [6:0] func7,
    output logic [2:0] imm_type, // used by the sign extender
    output logic [6:0] opcode,
    output logic [19:0] immediate
     
    // Mem read and write are handled by the control, not important here.
);

    assign opcode = instruction[6:0];

    always_comb begin
        // Default values, because latch errors are not it
        inst_type = 4'b0000;
        imm_type = 3'b111;
        immediate = 20'b0;
        rs1 = 5'b0;
        rs2 = 5'b0;
        rd = 5'b0;
        func3 = 3'b0;
        func7 = 7'b0;
        // alu_op removed; control drives ALU directly

        case (opcode)
            7'b0110011: begin
                inst_type = 4'b0011; // R-type instruction (register-register ALU)
                imm_type = 3'b010;
                
                // R-type format: [func7(7)][rs2(5)][rs1(5)][func3(3)][rd(5)][opcode(7)]
                rs1 = instruction[19:15];
                rs2 = instruction[24:20];
                rd = instruction[11:7];
                func3 = instruction[14:12];
                func7 = instruction[31:25];
            end
            7'b0010011: begin
                inst_type = 4'b0100; // I-type instruction (register-immediate ALU)
                imm_type = 3'b000;
                
                // I-type format: [imm[11:0](12)][rs1(5)][func3(3)][rd(5)][opcode(7)]
                immediate = {8'b0, instruction[31:20]};
                rs1 = instruction[19:15];
                rd = instruction[11:7];
                func3 = instruction[14:12];
                func7 = instruction[31:25]; // for shift immediates, func7 is in imm[11:5]
            end
            7'b0000011: begin
                inst_type = 4'b0001; // I type instruction (Load)
                imm_type = 3'b000;
                
                // I-type format
                immediate = {8'b0, instruction[31:20]};
                rs1 = instruction[19:15];
                rd = instruction[11:7];
                func3 = instruction[14:12];
                func7 = 7'b0;
            end
            7'b0100011: begin
                inst_type = 4'b0010; // S type instruction (Store)
                imm_type  = 3'b001;
                
                // S-type format
                immediate = {8'b0, instruction[31:25], instruction[11:7]};
                rs1       = instruction[19:15];
                rs2       = instruction[24:20];  // add rs2 decode here
                rd        = 5'b0; // no rd in store
                func3     = instruction[14:12];
                func7     = 7'b0;
            end
            
            // B type
            7'b1100011: begin
                inst_type = 4'b0101; // B type 
                imm_type  = 3'b011; // also
                
                // B-type format
                immediate = {8'b0, instruction[31], instruction[7], instruction[30:25], instruction[11:8]};
                rs1       = instruction[19:15];
                rs2       = instruction[24:20];
                rd        = 5'b0; // no rd in branch
                func3     = instruction[14:12];
                func7     = 7'b0;
            end
            7'b1101111: begin
                inst_type = 4'b0110; // J type instruction (JAL)
                imm_type  = 3'b100;
                // J-type format
                immediate = {instruction[31], instruction[19:12], instruction[20], instruction[30:21]};
                rd        = instruction[11:7];
                rs1       = 5'b0; // only 1 j type
                rs2       = 5'b0;
                func3     = 3'b0;
                func7     = 7'b0;
            end
            7'b1100111: begin // JALR
                inst_type = 4'b0111; // I type instruction (JALR)
                imm_type = 3'b000; // sign extends like I type, because it is I type with weird opcode
                immediate = {8'b0, instruction[31:20]}; // 12 bit immediate padded to 20 bits
                rd = instruction[11:7]; // destination register
                rs1 = instruction[19:15]; // source register (base address)
                rs2 = 5'b0;
                func3 = 3'b0;
                func7 = 7'b0;
            end
            default: begin
                // Keeps default values
            end
        endcase
    end
    
endmodule