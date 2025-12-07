module cpu (
    input clk,
    input rst,
);



// initiats the program counter as a single register, then counts up
reg [31:0] pc;
logic [31:0] next_pc;

always_comb begin : pcSelect
    next_pc = pc + 4; // forward 4 bits
end

// zeros the program counter when done 
always @(posedge clk) begin
    if (rst = 0)
        pc = 32'b0; 
end


// the instruction signal as a wire, to be used shortly
wire [31:0] instruction;

memory #(
    .mem_init("") // file path to ADD ONCE I HAVE A FILE 
) instruction_memory (
    // Memory inputs
    .clk(clk),
    .address(pc),
    .write_data(32'b0),
    .write_enable(1'b0),
    .rst_n(1'b1),

    // Memory outputs
    .read_data(instruction)
);


endmodule