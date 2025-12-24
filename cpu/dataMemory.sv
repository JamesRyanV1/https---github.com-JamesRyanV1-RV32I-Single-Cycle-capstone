module dataMemory #(
    parameter WORDS = 64 // Supports bigger if needed
) (
    input logic clk,
    input logic [31:0] address,
    input logic [31:0] write_data,
    input logic write_enable,
    input logic rst_data,

    output logic [31:0] read_data
);


reg [31:0] mem [0:WORDS-1];  // 32 32 bit words

always @(posedge clk) begin
    // Same reset as registers basically
    if (rst_data) begin
        for (int i = 0; i < WORDS; i++) begin // Words can change later on if more memory size is needed without extra work
            mem[i] <= 32'b0;  
        end
    end
    else if (write_enable) begin
        // Make sure address is aligned to a word boundary or ignore write

        if (address != 0) begin 
            // Here, address[31:2] is the word index
            int index = address[31:2];
            // If the index works, write
            if (index < WORDS) begin
                mem[index] <= write_data;
            end
        end
    end
end

// Read logic
always_comb begin
    static index = address[31:2];    // No 0 indexing here (hopefully)
    if (index < WORDS)
        read_data = mem[index];
    // Ff index would be out of bounds, read off all 0s for saftey, will be visable in debugging later
    else
        read_data = 32'b0;
end

endmodule