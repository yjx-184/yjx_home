module tb_shifter32;

    reg [31:0] din;
    reg [4:0] shamt;
    reg LR;
    reg AL;
    wire [31:0] dout;

    // 实例化桶形移位器
    shifter32 uut (
        .din(din),
        .shamt(shamt),
        .LR(LR),
        .AL(AL),
        .dout(dout)
    );

    // 生成波形文件
    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, tb_shifter32);
        $display("Dumping waveforms to dump.vcd...");
    end

    //测试激励
    initial begin
    // 初始化输入
        din = 32'b10101010101010101010101010101010; // 测试数据
        shamt = 5'd2;  // 移位 2 位
        LR = 1;            // 左移
        AL = 0;            // 逻辑移位
        #10;

        // 测试逻辑左移
        din = 32'b10101010101010101010101010101010;
        shamt = 5'd2;
        LR = 1;
        AL = 0;  // 逻辑左移
        #10;

        // 测试逻辑右移
        din = 32'b10101010101010101010101010101010;
        shamt = 5'd2;
        LR = 0;
        AL = 0;  // 逻辑右移
        #10;

        // 测试算术右移
        din = 32'b11111111111111111111111111111010; // 负数
        shamt = 5'd2;
        LR = 0;
        AL = 1;  // 算术右移
        #10;

        // 结束仿真
        $finish;
    end

    // 显示仿真日志
    initial begin
        $monitor("Time = %0t | din = %b | shamt = %d | LR = %b | AL = %b | dout = %b",
                 $time, din, shamt, LR, AL, dout);
    end


endmodule