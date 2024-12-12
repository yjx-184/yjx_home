module Imm_Gen(
    input [31:0] instr,       // 输入：instr
    input [2:0] ExtOp,        // 扩展操作：用于区分立即数类型
    output reg [31:0] imm     // 输出：生成的32位立即数
);

    always @(*) begin
        case (ExtOp)
            3'b000: // I-Type：立即数操作指令 
                // 最高位为符号位，对其进行扩展。
                imm = {{20{instr[31]}}, instr[31:20]};

            3'b001: // U-Type: 长立即数指令
                imm = {instr[31:12], 12'b0};

            3'b010: // S-Type: 存储器写指令
                imm = {{20{instr[31]}}, instr[31:25], instr[11:7]};

            3'b011: // B-Type: 跳转指令 13位立即数，末尾始终为0
                imm = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};

            3'b100: // J-Type: 长跳转指令
                imm = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};
            default: // 默认输出 0
                imm = 32'b0;
        endcase
    end

endmodule
