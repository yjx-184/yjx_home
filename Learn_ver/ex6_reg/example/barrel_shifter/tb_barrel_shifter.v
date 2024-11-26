module tb_barrel_shifter;

    reg [7:0] din;
    reg [2:0] shamt;
    reg LR;
    reg AL;
    wire [7:0] dout;

    // 实例化桶形移位器
    barrel_shifter uut (
        .din(din),
        .shamt(shamt),
        .LR(LR),
        .AL(AL),
        .dout(dout)
    );

    // 生成波形文件
    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, tb_barrel_shifter);
        $display("Dumping waveforms to dump.vcd...");
    end

    // 测试激励
    initial begin
        // 初始化输入
        din = 8'b10101010; // 输入数据
        shamt = 3'b010;    // 移位2位
        LR = 1;            // 左移
        AL = 0;            // 逻辑移位
        #10;

        // 测试逻辑右移
        LR = 0;            // 右移
        AL = 0;            // 逻辑移位
        #10;

        // 测试算术右移
        AL = 1;            // 算术移位
        #10;

        // 测试边界条件
        shamt = 3'b000;    // 不移位
        #10;
        shamt = 3'b111;    // 最大移位
        #10;

        // 结束仿真
        $finish;
    end

    // 显示仿真日志
    initial begin
        $monitor("Time = %0t | din = %b | shamt = %d | L_R = %b | A_L = %b | dout = %b",
                 $time, din, shamt, LR, AL, dout);
    end
endmodule
