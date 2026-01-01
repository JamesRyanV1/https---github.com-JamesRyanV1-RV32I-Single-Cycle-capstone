module alu (
    input logic clk,
    input logic rst,
    input logic alu_source,
    input logic [3:0] cntrl,
    input logic [31:0] d1,
    input logic [31:0] immediate,
    input logic [31:0] rs2

    output logic [31:0] alu_output,
    output logic zero,
    output logic last_bit
);

    // internal d2 wire, selects between rs2 and immediate based on alu_source from control
    logic [31:0] d2;
    case alu_source
        1'b0: d2 = rs2;        // use register data
        1'b1: d2 = immediate;  // use immediate data
        default: d2 = 32'b0;
    endcase

    // internal wires for submodules
    logic [31:0] add_result;
    logic [31:0] shift_result;
    logic [1:0]  shift_type;
    logic [31:0] logic_result;

    // instantiate submodules
    alu_adder adder_inst (
        .a(d1),
        .b(d2),
        .sum(add_result)
    );
    alu_shifter shifter_inst (
        .a(d1),
        .shamt(d2[4:0]), // last 5 bits of d2 ONLY IN CASES WHERE D2 IS IMMEDIATE
        .shift_type(shift_type),
        .shift_result(shift_result)
    );
    alu_logic logic_inst (
        .a(d1),
        .b(d2),
        .cntrl(cntrl),
        .logic_output(logic_result)
    );

    always_comb begin
        case (cntrl)
            // ALL IMMEDIATE INSTRUCTIONS HAVE THE SAME CONTROL, D2 IS IMMEDIATE VALUE CHANGED FROM THE CONTROL UNIT
            4'b0000: alu_output = add_result; // ADD, handles add, sub, addi, no subi instruction
            4'b0001: begin // SHIFT LEFT LOGICAL
                shift_type = 2'b00;
                alu_output = shift_result;
            end
            4'b0010: begin // SHIFT RIGHT LOGICAL
                shift_type = 2'b01;
                alu_output = shift_result;
            end
            4'b0011: begin // SHIFT RIGHT ARITHMETIC
                shift_type = 2'b10;
                alu_output = shift_result;
            end
            4'b0100: alu_output = logic_result; // AND
            4'b0101: alu_output = logic_result; // OR
            4'b0110: alu_output = logic_result; // XOR

            default: alu_output = 32'b0; // zeros on default
            
        endcase

        zero     = (alu_output == 32'b0);
        last_bit = alu_output[0];
    end
endmodule