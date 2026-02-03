


module cpu (
    input  wire        clk,
    input  wire        rst,
    // input  logic [31:0] instruction_in, // direct instruction feed for testing

    // any outputs for testing go here if needed.
    output logic [31:0] cpu_out
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
logic [3:0]  inst_type;      // used only by the decoder
logic [2:0]  imm_type;       // used only by the sign extender
logic [31:0] regData1;    // data from register 1
logic [31:0] regData2;    // data from register 2
logic        memRead;  
logic        memWrite;
logic        alu_zero;
logic        alu_last_bit;
logic        alu_source;
logic [31:0] alu_result;      // output from ALU to data memory address input and destination register
logic [31:0] instruction;   // instruction from instruction memory to decoder, sign extender, etc.
logic [4:0]  rs1;           // location of rs1 from instruction
logic [4:0]  rs2;           // location of rs2 from instruction
logic [31:0] immediate;     // sign-extended immediate from sign extender
logic [6:0]  opcode;        // opcode from instruction
logic [2:0]  func3;         // func3 from instruction
logic [6:0]  func7;         // func7 from instruction
logic [4:0]  rd;            // destination register from instruction
logic [31:0] rd_data ;      // data to be written to destination register, = to data from rd
logic       take_branch;   // branch decision from branch unit
logic [2:0]  pc_source;     // branch control from control unit
logic [4:0]  reg_destination;   // destination register for register file
// NEW BUS DLC COMING SOON*tm*
logic [31:0] pc_next;        // output from pc to instruction memory mostly, or ALUIPC, (might not even use aluipc)
logic [1:0]  register_source; // from control to register file
logic        override;       // override signal for jalr to pc












// instruction memory
dataMemory instruction_memory_inst (
    .clk(clk),
    .address(pc_next), // pc output goes here later
    .write_data(32'b0), // no writing to instruction memory in this sub sub module
    .write_enable(1'b0), // no writing to instruction memory in this sub sub module
    .rst_data(rst),
    .read_data(instruction)
);
// branch unit
branch_unit branch_unit_inst (
    .clk(clk),
    .rst(rst),
    .d1(regData1),
    .d2(regData2),
    .cntrl(pc_source), // branch control from control unit, not implemented yet

    .take_branch(take_branch)
);
// Program Counter
pc pc_inst (
    .clk(clk),
    .rst(rst),
    .branch(take_branch), // branch control signal from control unit, not implemented yet
    .offset(immediate), // for branch instructions, comes from sign extender 
    .override(override), // override for jalr instruction
    .pc_out(pc_next)
);
// Register File
registerFile register_file_inst (
    .clk(clk),
    .rst(rst),
    .rs1(rs1),
    .rs2(rs2),
    .rd(reg_destination),
    .register_source(register_source),
    .alu_result(alu_result),
    .pc_plus_4(pc_next + 32'd4),
    .wd(dData),
    .enableWrite(reg_write),
    .rd1(regData1),
    .rd2(regData2)
);

// Data Memory
dataMemory data_memory_inst (
    .clk(clk),
    .address(alu_result),
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
//assign alu_result = alu_output; // expose alu output for testing
// Control unit
control control_inst (
    .op(opcode),
    .func3(func3),
    .func7(func7),
    .alu_zero(alu_zero),
    .alu_last_bit(alu_last_bit),
    .register_source(register_source),
    .alu_control(), // USELESS
    .imm_source(),  // USELESS
    .mem_read(memRead),
    .mem_write(memWrite),
    .reg_write(reg_write),
    .alu_source(alu_source),
    .pc_source(pc_source),
    .alu_op(alu_ctrl),
    .jalr_override(override)
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
    .inst_type(inst_type), // USELESS
    .rd(reg_destination),
    .rs1(rs1),
    .rs2(rs2),
    .func3(func3),
    .func7(func7),
    .imm_type(imm_type),
    .opcode(opcode),
    .immediate()
);

// direct instruction drive
// assign instruction = instruction_in;

// expose loaded data for testing

endmodule