`timescale 1ns / 1ps

module tb_RegisterFile;
    //接口信号
    reg [4:0] Ra;
    reg [4:0] Rb;
    reg [4:0] Rw;
    reg [31:0] busW;
    reg RegWr;
    reg WrClk;
    wire [31:0] busA;
    wire [31:0] busB;

    //实例化被测试模块
    RegisterFile uut(
        .Ra(Ra),
        .Rb(Rb),
        .Rw(Rw),
        .busW(busW),
        .RegWr(RegWr),
        .WrClk(WrClk),
        .busA(busA),
        .busB(busB)
    );

    //生成时钟信号
    always begin
        WrClk = 0;
        forever #5 WrClk = ~WrClk;
    end


    //测试逻辑
    initial begin
        //初始化
        Ra = 5'b0;
        Rb = 5'b0;
        Rw = 5'b0;
        busW = 32'b0;
        RegWr = 1'b0;

        //等待复位
        #10;

        //测试
        Rw = 5'd1;
        busW = 32'hA5A5A5A5;
        RegWr = 1'b1;
        #10;

        //验证写入数据
        RegWr = 1'b0;
        Ra = 5'd1;
        Rb = 5'd0;
        #10;
        $display("busA = %h (预期: A5A5A5A5)", busA);
        $display("busB = %h (预期: 00000000)", busB);

        //测试写入另一个寄存器
        Rw = 5'd2;
        busW = 32'h6B6B6B6B;
        RegWr = 1'b1;
        #10;

        //验证写入和多路读取
        RegWr = 1'b0;
        Ra = 5'd2;
        Rb = 5'd1;
        #10;
        $display("busA = %h (预期: 6B6B6B6B)", busA);
        $display("busB = %h (预期: A5A5A5A5)", busB);

        //测试写入 x0
        Rw = 5'd0;
        busW = 32'hFFFFFFFF;
        RegWr = 1'b1;
        #10;

        //验证x0应该仍为0
        RegWr = 1'b0;
        Ra = 5'd0;
        #10;
        $display("busA = %h (预期: 00000000)", busA);

        $finish;

    end

endmodule