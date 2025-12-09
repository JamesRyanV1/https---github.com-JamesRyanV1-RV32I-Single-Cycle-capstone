module decoder (
    input logic [31:0] instruction,
    
    output logic [3:0] inst_type,
    output logic [4:0] rd,
    output logic [4:0] rs1,
    output logic alu_op,
    output logic [2:0] func3,
    output logic [6:0] func7,
    output logic [2:0] imm_type, // used by the sign extender
    output logic [6:0] opcode
     
    // Mem read and write are handled by the control, not important here.
);

    assign opcode = instruction[6:0];



    // Asigns the instruction type from the opcode

    always @(*) begin // always @(*) is for whenever a signal inside changes, it runs, not clock dependant
                      // change to always_comb() begin later if issues
        case (opcode)

            7'b0000001: begin
                inst_type = 4'b0001; // I type instruction
                imm_type = 3'b000; // I type imm_type used so the sign extender can make it useable on a 32 bit bus
                end
            // note for later U type needs 31 bit for sign extension ig

        endcase
    end
    /*
        A case is being added for each instruction type.
        Each type will follow a different path, included under each case
        and each case will include the entire algorithm(is it an algorithm) to be run for each instruction
    */
    always_comb begin 
        case (inst_type)

            4'b0001: begin 

                // Splitting up instruction acording to I type format 
                assign immediate = instruction [31:20];

                assign rs1 = instruction [19:15];

                assign rd = instruction[11:7];
                
                // func3 is the function, only allows for 2^3 instructions per type which is enough for me at the moment.
                // I can edit the instruction format later if needed and shrink the opcode if needed
                logic [2:0] func3;
                assign func3 = instruction [14:12];
            end

        endcase
    end

    
endmodule