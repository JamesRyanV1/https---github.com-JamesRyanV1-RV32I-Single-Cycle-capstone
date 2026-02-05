module dataMemory #(
    parameter WORDS = (1 << 24) // 2^31 words, change shift if I want more
    // THE SIM COULD NOT HANDLE 2^31 WORDS, KEEP IT HERE for testing
) (
    input logic clk,
    input logic [31:0] address,
    input logic [31:0] write_data,
    input logic write_enable,
    input logic rst_data,

    output logic [31:0] read_data
);

    reg [31:0] mem [0:WORDS-1];  // 32-bit words

    // Write / reset
    always_ff @(posedge clk) begin
        if (rst_data) begin
            for (int i = 0; i < WORDS; i++) begin
                mem[i] <= 32'b0;
            end
        end else if (write_enable) begin
            int unsigned idx;
            idx = address >> 2;       // word index, 32-bit wide
            if (address != 0 && idx < WORDS) begin
                mem[idx] <= write_data;
            end
        end
    end

    // Read
    always_comb begin
        int unsigned idx;
        idx = address >> 2;           // word index, 32-bit wide
        if (idx < WORDS)
            read_data = mem[idx];
        else
            read_data = 32'b0;
    end

endmodule