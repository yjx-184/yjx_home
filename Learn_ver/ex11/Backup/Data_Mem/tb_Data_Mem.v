`timescale 1ns / 1ps

module tb_Data_Mem;
    //接口信号
    reg [31:0] Addr;
    reg [2:0] MemOp;
    reg [31:0] DataIn;
    reg WrEn;
    reg CLK;
    wire [31:0] DataOut;

    //派生时钟信号
    wire RdClk;
    wire WrClk;

    //实例化被测试模块
    Data_Mem uut(
        .Addr(Addr),
        .MemOp(MemOp),
        .DataIn(DataIn),
        .WrEn(WrEn),
        .RdClk(RdClk),
        .WrClk(WrClk),
        .DataOut(DataOut)
    );

    //时钟生成
    initial begin
        CLK = 0;
        forever #10 CLK = ~CLK;
    end

    //测试逻辑
    initial begin
        //初始化
        Addr = 32'b0;
        MemOp = 3'b0;
        DataIn = 32'b0;
        WrEn = 1'b0;

        #50;

        //测试1： 写入一个字（MemOp = 3'b000）, 地址0x4,数据为32'hDEADEBEEF
        Addr = 32'h4;
        DataIn = 32'hDEADBEEF;
        MemOp = 3'b000; // 写字
        WrEn = 1'b1;
        #20; // 等待一个完整时钟周期
        WrEn = 1'b0;

        //测试 2: 读取一个字（MemOp=3'b000），地址为 0x4
        #20; // 等待一个完整时钟周期
        MemOp = 3'b000; // 读字
        #20; // 等待数据稳定
        if (DataOut != 32'hDEADBEEF)
            $display("Test 1 失败! 预期: 32'hDEADBEEF, 得到: %h", DataOut);
        else
            $display("Test 1 测试通过!");

        //测试 3: 写入一个字节（MemOp=3'b100），地址为 0x8，数据为 0xAB
        Addr = 32'h8;
        DataIn = 32'hAB;
        MemOp = 3'b100; // 写字节
        WrEn = 1'b1;
        #20; // 等待一个完整时钟周期
        WrEn = 1'b0;

        //测试 4: 读取一个字节（MemOp=3'b100），地址为 0x8
        #20; // 等待一个完整时钟周期
        MemOp = 3'b100; // 读字节
        #20; // 等待数据稳定
        if (DataOut != 32'hAB)
            $display("Test 2 失败! 预期: 32'hAB, 得到: %h", DataOut);
        else
            $display("Test 2 测试通过!");

        //测试 5: 写入一个半字（MemOp=3'b001），地址为 0xC，数据为 0x1234
        Addr = 32'hC;
        DataIn = 32'h1234;
        MemOp = 3'b001; // 写半字
        WrEn = 1'b1;
        #20; // 等待一个完整时钟周期
        WrEn = 1'b0;

        //测试 6: 读取一个半字（MemOp=3'b001），地址为 0xC
        #20; // 等待一个完整时钟周期
        MemOp = 3'b001; // 读半字
        #20; // 等待数据稳定
        if (DataOut != 32'h1234)
            $display("Test 3 失败! 预期: 32'h1234, 得到: %h", DataOut);
        else
            $display("Test 3 测试通过!");

        
        #50;
        $stop;
    end

endmodule