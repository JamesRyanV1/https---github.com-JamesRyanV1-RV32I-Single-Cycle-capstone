module registerFile (
    /*
    Writes should be on clock, with reads being combinational
    allows for reading early in the next cycle with writing late in the cycle, so recent data is read 
    */
    input logic clk,
    input logic rst,

    // source registerss
    input logic [4:0] rs1,
    input logic [4:0] rs2,

    // destination register
    input logic [4:0] rd,

    // write data and enable write
    input logic [1:0] register_source, // 00 is data memory, 01 is alu result, 10 is pc + 4, 11 is imm (for auipc only if implimented later)
    input logic [31:0] alu_result, // from alu
    input logic [31:0] pc_plus_4, // from pc
    input logic [31:0] wd, // write data from data memory
    input logic enableWrite,

    // two read data ports, for adding two data
    output logic [31:0] rd1,
    output logic [31:0] rd2
);
    // reg
    logic [31:0] regs [31:0];

    integer i; // I dont know if i need this but im scared to find out otherwise
    // always on posedge, non blocking
    always_ff @(posedge clk) begin

        // resets each register to 32'b0
        if (rst) begin
            for (i = 0; i <32; i++) begin
                // asignments are non blocking in a ff block (<=)
                regs[i] <= 32'b0;
            end
        end
        // if writing is allowed (and regs[0] cannot be written to anyways so its included)
        else if (enableWrite && rd != 0) begin
            // sets the destination register to the write data
            case (register_source)
                2'b00: regs[rd] <= wd;               // from data memory
                2'b01: regs[rd] <= alu_result;      // from alu
                2'b10: regs[rd] <= pc_plus_4;      // from pc + 4
                default: regs[rd] <= wd;            // default to data memory just in case
            endcase
            //
        end
    end

    // reads whenever anything changes always combinalationally, blocking
    assign rd1 = (rs1 == 0) ? 32'b0 : regs[rs1];
    // the read data knows where it is by knowing where it isnt
    assign rd2 = (rs2 == 0) ? 32'b0 : regs[rs2];

// freedom
endmodule