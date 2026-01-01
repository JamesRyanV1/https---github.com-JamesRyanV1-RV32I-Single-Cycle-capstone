module cpu (
    input  wire        clk,
    input  wire        rst,
    input  logic [31:0] instruction_in, // direct instruction feed for testing

    output logic [31:0] readd // observation signal for testing
    output logic [31:0] alu_output // expose ALU output for testing
);


/*
my thoughts but wires for lw instruction

GETTING DATA MEMORY
read_data from data                     -> write_data for registers
    alu_add(rs1+sign extended immediate)    -> read_data_adress (data_memory in port)
    read_data                               -> data_memory (adress in port([31:0]) write_data out port([31:0]))

WRITING TO REGISTERS
destination_register(control out port)  -> register_adress (regfile in port)
reg_write (control out port)            -> enabled ()

decoder -> control


*/


// WIRES BETWEEN COMPONENTS NOT FROM INSTRUCTIONS
logic [31:0] regData;        // unused placeholder for future instructions
logic [31:0] dData;          // out from data memory, in to reg file
logic [3:0]  alu_ctrl;       // control into ALU
logic [31:0] data_address;   // data address to be read (wire between the ALU out and the data memory)
logic        reg_write;      // 1 bit wire from control to registers
logic [3:0]  inst_type;
logic [2:0]  imm_type;       // used only by the sign extender
logic [31:0] regData1;
logic [31:0] regData2;
logic        memRead;
logic        memWrite;
logic        alu_zero;
logic        alu_last_bit;
logic        alu_source;
logic [31:0] alu_result; //USED LATER :)
// WIRES DIRECTLY FROM INSTRUCTION
logic [31:0] instruction;
logic [4:0]  rs1;
logic [4:0]  rs2;
logic [31:0] immediate;
logic [6:0]  opcode;
logic [2:0]  func3;
logic [6:0]  func7;
logic [4:0]  rd;
logic [4:0]  reg_destination;
// NEW BUS DLC COMING SOON*tm*




// initiats the program counter as a single register, then counts up (ignore this for the time being, I cant count a program if I cant add generally, this is a placeholder anyway, nvm?)
                    // reg [31:0] pc;
                    // logic [31:0] next_pc;

                    // always_comb begin : pcSelect
                    //     next_pc = pc + 4; // forward 4 bits
                    // end

                    // // zeros the program counter when done 
                    // always @(posedge clk) begin
                    //     if (rst = 0)
                    //         pc = 32'b0; 
                    // end







// ADD INSTRUCTION MEMORY SOMHOW


// Register File
registerFile register_file_inst (
    .clk(clk),
    .rst(rst),
    .rs1(rs1),
    .rs2(rs2),
    .rd(reg_destination),
    .wd(dData),
    .enableWrite(reg_write),
    .rd1(regData1),
    .rd2(regData2)
);

// Data Memory
dataMemory data_memory_inst (
    .clk(clk),
    .address(alu_result), // SET ALU TO MATCH ONCE TESTING IS OVER
    .write_data(regData2),
    .write_enable(memWrite),
    .rst_data(rst),
    .read_data(dData)
);

// ALU for data memory address calculation
alu alu_inst (
    .clk(clk),
    .rst(rst),
    .alu_source(alu_source),
    .cntrl(alu_ctrl),
    .d1(regData1),
    .immediate(immediate), // THIS WILL BE EITHER REGDATA2 OR IMMEDIATE BASED ON ALU SOURCE FROM CONTROL UNIT
    .rs2(regData2),
    .alu_output(alu_result), // THIS NEEDS TO GO SOMEWHERE, WAS DATA ADRESS FOR LW/SW, NOW IS ALU_OUTPUT PORT FOR TESTING
    .zero(alu_zero),
    .last_bit(alu_last_bit)
);
// JUST FOR TESTING REMOVE LATER
assign alu_result = alu_output; // expose alu output for testing
// Control unit
control control_inst (
    .op(opcode),
    .func3(func3),
    .func7(func7),
    .alu_zero(alu_zero),
    .alu_last_bit(alu_last_bit),
    .alu_control(),
    .imm_source(),
    .mem_read(memRead),
    .mem_write(memWrite),
    .reg_write(reg_write),
    .alu_source(alu_source),
    .pc_source(),
    .alu_op(alu_ctrl)
);

// Sign extender
signExtender sign_extender_inst (
    .clk(clk),
    .rst(rst),
    .inst(instruction),
    .imm_type(imm_type),
    .ext_imm(immediate)
);

// Decoder
decoder decoder_inst (
    .clk(clk),
    .rst(rst),
    .instruction(instruction),
    .inst_type(inst_type),
    .rd(reg_destination),
    .rs1(rs1),
    .rs2(rs2),
    .func3(func3),
    .func7(func7),
    .imm_type(imm_type),
    .opcode(opcode),
    .immediate()
);

// direct instruction drive for this testbench-style hookup
assign instruction = instruction_in;

// expose loaded data for visibility
assign readd = dData;

endmodule