`timescale 1ns / 10ps

module tb_ALU;

    // 输入信号
    reg [31:0] rs1, rs2;       // 输入数 rs1 和 rs2
    reg [3:0] ALUctr;          // ALU 控制信号
    reg [31:0] pc, imm;        // pc 和立即数
    reg ALUAsrc;               // ALU 输入 A 选择源
    reg [1:0] ALUBsrc;         // ALU 输入 B 选择源

    // 输出信号
    wire Less;                 // 输出符号标志
    wire Zero;                 // 输出零标志
    wire [31:0] ALUout;        // 输出 ALU 结果

    // 实例化 ALU 模块
    ALU u_ALU (
        .rs1(rs1),
        .rs2(rs2),
        .ALUctr(ALUctr),
        .pc(pc),
        .imm(imm),
        .ALUAsrc(ALUAsrc),
        .ALUBsrc(ALUBsrc),
        .Less(Less),
        .Zero(Zero),
        .ALUout(ALUout)
    );

    // 时钟生成器
    reg CLK;
    initial begin
        CLK = 0;
        forever #10 CLK = ~CLK;  // 时钟周期为20ns
    end

    // 测试过程
    initial begin
        // 初始化
        $display("开始模拟...");
        $dumpfile("alu_test.vcd");  // 保存波形文件（适用于 GTKWave）
        $dumpvars(0, tb_ALU);

        // 测试1: 加法操作
        rs1 = 32'h00000010;  // rs1 = 16
        rs2 = 32'h00000020;  // rs2 = 32
        ALUctr = 4'b0000;    // 加法操作
        ALUAsrc = 0;         // 使用 rs1
        ALUBsrc = 0;         // 使用 rs2
        pc = 32'h00000000;
        imm = 32'h00000000;
        #20;  // 等待一个时钟周期

        // 打印输出
        $display("加法操作: ALUout = %h, Less = %b, Zero = %b", ALUout, Less, Zero);

        // 测试2: 异或操作
        rs1 = 32'h000000FF;  // rs1 = 255
        rs2 = 32'h0000000F;  // rs2 = 15
        ALUctr = 4'b1000;    // 异或操作
        #20;  // 等待一个时钟周期

        // 打印输出
        $display("异或操作: ALUout = %h, Less = %b, Zero = %b", ALUout, Less, Zero);

        // 测试3: 比较操作（带符号小于）
        rs1 = 32'hFFFFFFFF;  // rs1 = -1
        rs2 = 32'h00000001;  // rs2 = 1
        ALUctr = 4'b0010;    // 比较操作（带符号小于）
        #20;  // 等待一个时钟周期

        // 打印输出
        $display("比较操作: ALUout = %h, Less = %b, Zero = %b", ALUout, Less, Zero);

        // 测试4: 逻辑与操作
        rs1 = 32'h000000FF;  // rs1 = 255
        rs2 = 32'h000000F0;  // rs2 = 240
        ALUctr = 4'b0111;    // 逻辑与操作
        #20;  // 等待一个时钟周期

        // 打印输出
        $display("逻辑与操作: ALUout = %h, Less = %b, Zero = %b", ALUout, Less, Zero);

        // 测试结束
        $display("模拟完成.");
        $finish;
    end
endmodule
