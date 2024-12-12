module ALU_Input_Select(
    input [31:0] pc,
    input [31:0] rs1,
    input [31:0] rs2,
    input [31:0] imm,
    input ALUAsrc,
    input [1:0] ALUBsrc,
    output reg [31:0] ALU_A,
    output reg [31:0] ALU_B
);

    //定义常数4
    localparam FOUR = 32'd4;

    //根据ALUAsrc选择输出ALU_A
    always @(*) begin
        case(ALUAsrc)
            1'b0: ALU_A = rs1;
            1'b1: ALU_A = pc;
            default: ALU_A = 32'b0;
        endcase
    end

    //根据ALUBsrc选择输出ALU_B
    always @(*) begin
        case(ALUBsrc)
            2'b00: ALU_B = rs2;
            2'b01: ALU_B = {27'b0, imm[4:0]};//当是立即数移位指令时，只有低5位有效
            2'b10: ALU_B = FOUR;
            default: ALU_B = 32'b0;
        endcase
    end

endmodule