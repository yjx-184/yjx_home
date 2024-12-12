`timescale 1ns / 1ps

module tb_PCMux;
    //接口信号
    reg [31:0] imm;
    reg [31:0] rs1;
    reg [31:0] Pc;
    reg PCAsrc;
    reg PCBsrc;
    wire [31:0] NextPC;

    //实例化被测试模块
    PCMux uut(
        .imm(imm),
        .rs1(rs1),
        .Pc(Pc),
        .PCAsrc(PCAsrc),
        .PCBsrc(PCBsrc),
        .NextPC(NextPC)
    );

    //测试逻辑
    initial begin
        //初始化
        imm = 32'b0;
        rs1 = 32'b0;
        Pc = 32'h0000_0000;
        PCAsrc = 0;
        PCBsrc = 0;

        #10 Pc = 32'h0000_0004; imm = 32'h0000_0008; rs1 = 32'h0000_0010; PCAsrc = 0; PCBsrc = 0; // NextPC = Pc + 4
        #10 Pc = 32'h0000_0004; imm = 32'h0000_0008; rs1 = 32'h0000_0010; PCAsrc = 1; PCBsrc = 0; // NextPC = Pc + imm
        #10 Pc = 32'h0000_0004; imm = 32'h0000_0008; rs1 = 32'h0000_0010; PCAsrc = 1; PCBsrc = 1; // NextPC = rs1 + imm
        #10 Pc = 32'h0000_0010; imm = 32'h0000_0010; rs1 = 32'h0000_0020; PCAsrc = 0; PCBsrc = 1; // NextPC = rs1 + imm
        #10 Pc = 32'h0000_0020; imm = 32'h0000_0004; rs1 = 32'h0000_0030; PCAsrc = 1; PCBsrc = 1; // NextPC = rs1 + imm

        // 测试结束
        #10 $finish;

    end
    initial begin
        $monitor("time %t, Pc = %h, imm = %h, rs1 = %h, PCAsrc = %b, PCBsrc = %b, NextPC = %h", $time, Pc, imm, rs1, PCAsrc, PCBsrc, NextPC);
    end



endmodule