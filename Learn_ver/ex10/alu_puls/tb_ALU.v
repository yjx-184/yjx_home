`timescale 1ns / 1ps

module tb_ALU;

    // 输入信号
    reg [31:0] A, B;
    reg [3:0] ALUctr;

    // 输出信号
    wire Less;
    wire Zero;
    wire [31:0] ALUout;

    // 实例化 ALU 模块
    ALU uut (
        .A(A),
        .B(B),
        .ALUctr(ALUctr),
        .Less(Less),
        .Zero(Zero),
        .ALUout(ALUout)
    );

    // 初始化输入信号
    initial begin
        // 初始化信号
        A = 32'b0;
        B = 32'b0;
        ALUctr = 4'b0000;

        // 打印开始测试信息
        $display("ALU Testbench Started");

        // 测试加法操作 (ALUctr = 4'b0000)
        #10;
        A = 32'd10; B = 32'd5; ALUctr = 4'b0000; // 10 + 5
        $display("A = %d, B = %d, ALUctr = %b, ALUout = %d, Less = %b, Zero = %b", A, B, ALUctr, ALUout, Less, Zero);

        // 测试减法操作 (ALUctr = 4'b1000)
        #10;
        A = 32'd10; B = 32'd5; ALUctr = 4'b1000; // 10 - 5
        $display("A = %d, B = %d, ALUctr = %b, ALUout = %d, Less = %b, Zero = %b", A, B, ALUctr, ALUout, Less, Zero);

        // 测试左移操作 (ALUctr = 4'b0001)
        #10;
        A = 32'd1; B = 32'd2; ALUctr = 4'b0001; // 1 << 2
        $display("A = %d, B = %d, ALUctr = %b, ALUout = %d, Less = %b, Zero = %b", A, B, ALUctr, ALUout, Less, Zero);

        // 测试右移操作 (ALUctr = 4'b0101)
        #10;
        A = 32'd16; B = 32'd2; ALUctr = 4'b0101; // 16 >> 2
        $display("A = %d, B = %d, ALUctr = %b, ALUout = %d, Less = %b, Zero = %b", A, B, ALUctr, ALUout, Less, Zero);

        // 测试异或操作 (ALUctr = 4'b0100)
        #10;
        A = 32'd15; B = 32'd10; ALUctr = 4'b0100; // 15 ^ 10
        $display("A = %d, B = %d, ALUctr = %b, ALUout = %d, Less = %b, Zero = %b", A, B, ALUctr, ALUout, Less, Zero);

        // 测试逻辑与操作 (ALUctr = 4'b0111)
        #10;
        A = 32'd15; B = 32'd10; ALUctr = 4'b0111; // 15 & 10
        $display("A = %d, B = %d, ALUctr = %b, ALUout = %d, Less = %b, Zero = %b", A, B, ALUctr, ALUout, Less, Zero);

        // 测试逻辑或操作 (ALUctr = 4'b0110)
        #10;
        A = 32'd15; B = 32'd10; ALUctr = 4'b0110; // 15 | 10
        $display("A = %d, B = %d, ALUctr = %b, ALUout = %d, Less = %b, Zero = %b", A, B, ALUctr, ALUout, Less, Zero);

        // 测试 Less 标志 (ALUctr = 4'b0010)
        #10;
        A = 32'd10; B = 32'd5; ALUctr = 4'b0010; // 10 - 5, Less = 0
        $display("A = %d, B = %d, ALUctr = %b, ALUout = %d, Less = %b, Zero = %b", A, B, ALUctr, ALUout, Less, Zero);

        // 测试 Zero 标志 (ALUctr = 4'b0000)
        #10;
        A = 32'd0; B = 32'd0; ALUctr = 4'b0000; // 0 + 0
        $display("A = %d, B = %d, ALUctr = %b, ALUout = %d, Less = %b, Zero = %b", A, B, ALUctr, ALUout, Less, Zero);

        // 结束测试
        #10;
        $display("ALU Testbench Completed");
        $finish;
    end

endmodule
