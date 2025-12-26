module cpu (
    input wire clk,
    input wire rst,

    output logic [31:0] readd // JUST FOR TESTING
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
logic [31:0] regData; // out from reg file (for verification thjat it is stored, used in later instructions)
logic [31:0] dData; // out from data memory, in to reg file
logic [3:0] alu_op; // add for lw, more later
logic [31:0] data_adress; // data adress to be read (wire will go between the alu out and the data memory)
logic reg_write; // 1 bit wire from control to registers
logic[3:0] inst_type;
logic[2:0] imm_type; // used only by the sign extender, if not usefull later will make the same signal as inst_type
logic [31:0] regData1;
logic memRead;

// WIRES DIRECTLY FROM INSTRUCTION
logic [31:0] instruction;
logic [4:0] rs1;
logic [31:0] immediate;
logic [6:0] opcode;
logic [2:0] funct3;
logic [6:0] funct7;
logic [4:0] rd;
logic [4:0] reg_destination;
// NEW BUS DLC COMING SOON*tm*




// initiats the program counter as a single register, then counts up (ignore this for the time being, I cant count a program if I cant add generally, this is a placeholder anyway)
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







// memory #(
//     .mem_init("") // file path to ADD ONCE I HAVE A FILE  ignore this for now :)
// ) instruction_memory (
//     // Memory inputs
//     .clk(clk), // Connects clk of each module to higher level speficied port (weird module hierarchy thing)
//     .address(pc),
//     .write_data(32'b0), // when nothing to connect to, im defining them as wires of the correct width
//     .write_enable(1'b0),
//     .rst_n(1'b1),

//     // Memory outputs
//     .read_data(instruction)
// );

// Register File
registerFile (      // WORKS FOR NOW
    .clk(clk)
    .rst(rst)
    .rs1(rs1) // not data,, output port instead
//    .rs2(rs2)
    .rd(reg_destination)               // LOCATION COMES FROM DECODER NOT CONTROL. CREATE CONTROL PORT FOR THIS LATER
    .wd(dData)
    .enableWrite(reg_write)

    // read data, not destination register (bad naming mb)
    .rd1(readd)                        // ill add this later 
    //.rd2

)

// Data Memory
dataMemory (          // WORKS FOR NOW
    .clk(clk)
    .address(data_adress)
    .write_data()
    .write_enabled(memRead)
    .rst_data(rst)

    .read_data(dData)
)

// ALU for data memory adress calculation
alu (               // WORKS FOR NOW
    .clk(clk)
    .rst(rst)
    .cntrl(alu_op) // from control module, control must be modified further to support different functions per inst type
    .d1(regData1)
    .d2(immediate)                      // MAKE THIS THE SIGN EXTENDED IMMEDIATE

    .alu_output(data_adress) // to data memory
    .zero                               // useless ports, I already know what zero is im sure the machine can do the same
    .last_bit
)

// Control unit
control (               // NEEDS TEST
    .op(opcode) 
    .func3(func3)
    .func7(func7)
    .alu_zero // n/a
    .alu_last_bit // I sure wonder where this binds to

    .alu_control 
    .imm_source // I realy need this but I realy dont need this (1 or 0)
    .mem_read(memRead) // ignore
//    .mem_write // ignore
    .reg_write(reg_write) // goes to register file
    .alu_source                         // IF 1'b1 IS IMMEDIATE, ELSE SOURCE IS REGISTER? alo does not supoort this yet for lw
//    .pc_source
    .alu_op(alu_op)
)

// Sign extender
signExtender (              // WORKS FOR NOW
    .clk(clk)
    .rst(rst)
    .inst(instruction)
    .imm_type (imm_type) // from decoder

    .ext_imm(immediate)
)

// Decoder  
decoder (               // WORKS FOR NOW
    .clk(clk)
    .rst(rst)
    .instruction(instruction)

    .inst_type(inst_type) // to extender
    .rd(reg_destination)
    .rs1(rs1)                    
    .alu_op(alu_op)                    // js edition for now
    .func3(func3)
    .funct7(func7)
    .imm_type(imm_type)
    .opcode(opcode)

)
endmodule