`timescale 1ns / 1ps

module tb_Imm_Gen;
    //接口信号
    reg [31:0] instr;
    reg [2:0] ExtOp;
    wire [31:0] imm;

    //实例化被测试模块
    Imm_Gen uut(
        .instr(instr),
        .ExtOp(ExtOp),
        .imm(imm)
    );

    //测试逻辑
    initial begin
        // 测试 1: I-Type (立即数操作指令)
        instr = 32'b10000000000000000000000010010011;
        ExtOp = 3'b000;
        #10;
        $display("test 1: imm = %b", imm);

        #10;

        // 测试 2: U-Type (长立即数指令)
        instr = 32'b11111111111100000000000000000000; 
        ExtOp = 3'b001;
        #10;
        $display("test 2: imm = %b", imm);

        #10;

        // 测试 3: S-Type (存储器写指令)
        instr = 32'b11111110000000000000111110000011; 
        ExtOp = 3'b010;
        #10;
        $display("test 3: imm = %b", imm);

        #10;

        // 测试 4: B-Type (条件跳转指令)
        instr = 32'b11111110000000001000000001100011;
        ExtOp = 3'b011;
        #10;
        $display("test 4: imm = %b", imm);

        #10;

        // 测试 5: J-Type (长跳转指令)
        instr = 32'b11111110000000000000010011101111; 
        ExtOp = 3'b100;
        #10;
        $display("test 5: imm = %b", imm);

        // 结束测试
        #50;
        $stop;
    end




endmodule