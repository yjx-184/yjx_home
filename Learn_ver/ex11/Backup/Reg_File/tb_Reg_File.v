`timescale 1ns / 1ps

module tb_Reg_File;

    reg [31:0] instr;
    reg [31:0] busW;
    reg RegWr;
    reg CLK;
    reg clrn;
    wire [31:0] busA;
    wire [31:0] busB;

    wire [4:0] Ra, Rb, Rw;

    assign Ra = instr[19:15];
    assign Rb = instr[24:20];
    assign Rw = instr[11:7];

    //实例化被测试模块
    Reg_File uut(
        .Ra(Ra),
        .Rb(Rb),
        .Rw(Rw),
        .busW(busW),
        .RegWr(RegWr),
        .WrClk(CLK),
        .clrn(clrn),
        .busA(busA),
        .busB(busB)
    );

    //时钟
    always begin
        #5 CLK = ~CLK;  // 每5ns翻转一次时钟
    end

    //激励过程
    initial begin
        CLK = 0;
        clrn = 1;         // 先不复位
        RegWr = 0;        // 初始不写使能
        instr = 32'h00230293;    // 初始指令值
        busW = 32'b0;     // 初始写数据值

        #10;
        $display("instr = %b", instr);
        $display("instr(16) = %h", instr);
        $display("Ra = %b, Rb = %b, Rw = %b, busA = %b, busB = %b", Ra, Rb, Rw, busA, busB);
    
        
        // 结束仿真
        #10;
        $finish;
    end

endmodule