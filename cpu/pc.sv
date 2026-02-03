// program counter module

module pc (
    input  logic        clk,
    input  logic        rst,
    input  logic        branch, // control signal to indicate branch taken 
    input  logic [31:0] offset, // 32 bit offset for branch instructions or jal
    input logic         override, // override resets pc to offset + 4 for jalr
    input  logic [31:0] rs1, // source register value for JALR
    input  logic [31:0] jalr_imm, // immediate for JALR
    output logic [31:0] pc_out
);

    reg [31:0] pc;

    // Compute JALR target address combinationally
    logic [31:0] jalr_target;
    assign jalr_target = (rs1 + jalr_imm) & 32'hfffffffe; // JALR clears bit 0

    // initiats the program counter as a single register, then counts up
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 32'b0; 
        end else if (override) begin
            pc <= jalr_target; // JALR: use computed rs1 + imm
        end else  if (branch) begin
            pc <= pc + offset + 32'd4;
        end else if (~branch) begin // if not branch 
            pc <= pc + 4; 
        end
    end

    assign pc_out = pc;
endmodule

// BRANCH UNIT SETUP FOR 3'110 JAL
// ADDED OVERRIDE TO PC.SV FOR JALR INSTRUCTION
// ADDED JALR CASE TO CONTROL.SV AND JAL OVERRIDE CONTROL SIGNAL
// 
// NEEDS NEW SIGNAL IN CONTROL UNIT FOR JALR OVERRIDE // done
// NEEDS JALR CASE IN THE DECODER // maybe done, jalr should load from rd
// NEEDS OVERRIDE WIRE IN PC MODULE // done
