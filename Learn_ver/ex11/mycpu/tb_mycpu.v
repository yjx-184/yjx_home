`timescale 1ns / 10ps

module tb_Mycpu;

    // 时钟信号
    reg CLK;

    // 实例化待测试模块
    Mycpu Mycpu_tb (
        .CLK(CLK)
    );

    // 时钟生成器
    initial begin
        CLK = 0;
        forever #50 CLK = ~CLK; // 每50ns翻转一次，时钟周期为100ns
    end

    // 测试过程
    initial begin
        // 初始化
        $display("开始模拟...");
        $dumpfile("my_cpu.vcd");  // 保存波形文件（适用于 GTKWave）
        $dumpvars(0, Mycpu_tb);

        $readmemh("instr_mem.hex", mycpu.Instr_Mem.memory); // 加载指令

        // 等待若干时钟周期，观察CPU行为
        #2000;  // 仿真时间延长

        // 结束仿真
        $display("模拟完成.");
        $finish;
    end
endmodule
