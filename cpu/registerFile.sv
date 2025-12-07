module registerFile (
    input logic clk,
    input logic rst,

    // source registerss
    input logic [4:0] rs1,
    input logic [4:0] rs2,

    // destination register
    input logic [4:0] rd,

    // write data and enable write
    input logic [31:0] wd,
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
            regs[rd] <= wd;
        end
    end

    // reads whenever anything happens, will explain more later once I know more and/or replace/fix
    assign rd1 = (rs1 == 0) ? 32'b0 : regs[rs1];
    // the read data knows where it is by knowing where it isnt
    assign rd2 = (rs2 == 0) ? 32'b0 : regs[rs2];

// freedom
endmodule