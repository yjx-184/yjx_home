`timescale 1ns / 1ps

module tb_ram_mem;
    //接口信号
    reg [31:0] rs1;
    reg [31:0] rs2;
    reg [31:0] imm12;
    reg [3:0] MemOP;
    reg [31:0] memory_data_in;
    wire [31:0] result;
    wire [31:0] memory_data_out;
    wire memory_write;
    wire [3:0] byte_we;

    // 被测试模块实例化
    ram_mem uut (
        .rs1(rs1),
        .rs2(rs2),
        .imm12(imm12),
        .MemOP(MemOP),
        .memory_data_in(memory_data_in),
        .result(result),
        .memory_data_out(memory_data_out),
        .memory_write(memory_write),
        .byte_we(byte_we)
    );

    // 模拟测试逻辑
    initial begin
        // 初始化信号
        rs1 = 32'h1000;
        rs2 = 32'h0;
        imm12 = 32'h0;
        MemOP = 4'b0;
        memory_data_in = 32'h0;
        #10;

        // 测试 1: 存储字节 (sb)
        imm12 = 32'h4;
        MemOP = 4'b0000; // sb
        memory_data_in = 32'hAABBCCDD;
        #10;
        $display("测试1 (sb): memory_write = %b, byte_we = %b", memory_write, byte_we);

        // 测试 2: 存储半字 (sh)
        MemOP = 4'b0001; // sh
        memory_data_in = 32'hAABBCCDD;
        #10;
        $display("测试2 (sh): memory_write = %b, byte_we = %b", memory_write, byte_we);

        // 测试 3: 存储字 (sw)
        MemOP = 4'b0010; // sw
        memory_data_in = 32'hAABBCCDD;
        #10;
        $display("测试3 (sw): memory_write = %b, byte_we = %b", memory_write, byte_we);

        // 测试 4: 加载字节 (lb)
        MemOP = 4'b0100; // lb
        memory_data_in = 32'hFF123456; // 数据从内存读取
        #10;
        $display("测试4 (lb): result = %h", result);

        // 测试 5: 加载半字 (lh)
        MemOP = 4'b0101; // lh
        memory_data_in = 32'hFFFF1234; // 数据从内存读取
        #10;
        $display("测试5 (lh): result = %h", result);

        // 测试 6: 加载字 (lw)
        MemOP = 4'b0110; // lw
        memory_data_in = 32'h12345678; // 数据从内存读取
        #10;
        $display("测试6 (lw): result = %h", result);

        // 测试 7: 加载字节无符号 (lbu)
        MemOP = 4'b0111; // lbu
        memory_data_in = 32'hFF123456; // 数据从内存读取
        #10;
        $display("测试7 (lbu): result = %h", result);

        // 测试 8: 加载半字无符号 (lhu)
        MemOP = 4'b1000; // lhu
        memory_data_in = 32'hFFFF1234; // 数据从内存读取
        #10;
        $display("测试8 (lhu): result = %h", result);

        // 结束测试
        $finish;
    end
endmodule
