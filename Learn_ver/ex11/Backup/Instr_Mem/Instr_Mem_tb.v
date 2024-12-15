`timescale 1ns / 1ps

module Instr_Mem_tb;

    // 测试平台信号定义
    reg Rdclk;               // 读取时钟
    reg [31:0] Rdaddr;       // 读取地址
    wire [31:0] Instr;       // 输出指令

    // 实例化Instr_Mem模块
    Instr_Mem uut (
        .Rdclk(Rdclk),
        .Rdaddr(Rdaddr),
        .Instr(Instr)
    );

    // 生成时钟信号
    always begin
        Rdclk = ~Rdclk;  // 时钟周期翻转
        #5;              // 每5ns切换一次，时钟频率为100MHz
    end

    // 初始化信号
    initial begin
        // 初始化
        Rdclk = 0;
        Rdaddr = 0;

        // 输出到文件中显示
        $monitor("At time %t, Rdaddr = %d, Instr = %h", $time, Rdaddr, Instr);

        // 仿真开始
        #10;
        Rdaddr = 32'h00000000; // 设置读取地址，指向存储器的唯一位置

        #10;
        Rdaddr = 32'h00000000; // 修改地址（注意：MEM_DEPTH=1，所有地址都会指向同一位置）

        #10;
        Rdaddr = 32'h00000000; // 修改地址（同样会指向存储器的唯一位置）

        #10;
        $finish;  // 结束仿真
    end

    // 加载初始化文件（假设instr_mem.hex文件存在）
    initial begin
        $readmemh("instr_mem.hex", uut.mem_array);
    end

endmodule
