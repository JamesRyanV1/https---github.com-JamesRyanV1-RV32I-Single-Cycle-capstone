// program counter module

module pc (
    input  logic        clk,
    input  logic        rst,
    input  logic        branch, // control signal to indicate branch taken 
    input  logic [31:0] offset, // 32 bit offset for branch instructions, tragically sign-extended
    output logic [31:0] pc_out
);

    reg [31:0] pc;

    // initiats the program counter as a single register, then counts up
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 32'b0; 
        end else  if (branch) begin
            pc <= pc + offset + 32'd4;
        end else if (~branch) begin // if not branch 
            pc <= pc + 4; 
        end
    end

    assign pc_out = pc;
endmodule