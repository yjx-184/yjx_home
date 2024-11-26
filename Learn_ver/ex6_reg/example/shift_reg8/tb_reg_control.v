module tb_reg_control;

    reg clk;
    reg reset;
    reg [2:0] control;
    reg s_in;
    reg [7:0] d_in;
    wire [7:0] reg_out;

    //实例化
    reg_control uut(
        .clk(clk),
        .reset(reset),
        .control(control),
        .s_in(s_in),
        .d_in(d_in),
        .reg_out(reg_out)
    );

    // 波形生成
    initial begin
        $dumpfile("dump.vcd");  // 指定波形输出文件名
        $dumpvars(0, tb_reg_control);
    $display("Dumping waveforms to dump.vcd...");
    #1000; // 运行仿真指定时间后自动停止波形记录（可根据需要调整）
    $finish; // 结束仿真
    end

    //时钟信号生成
    initial begin
        clk = 0;
        forever #5 clk = ~clk;      //10ns 时钟周期
    end

    //测试逻辑
    initial begin
        //初始化
        reset = 0;
        control = 3'b000;
        s_in = 0;
        d_in = 8'b0;
        #15;

        //释放复位，测试清零
        reset = 1;
        #10 control = 3'b000;

        //测试置数
        #10 control = 3'b001; d_in = 8'b10101010;

        //测试逻辑右移
        control = 3'b010;
        #10;

        //测试逻辑左移
        control = 3'b011;
        #10;

        //测试算术右移
        control = 3'b100;
        #10;

        //测试左端串行输入并右移
        control = 3'b101; s_in = 1;
        #10 s_in = 0;
        #10;

        //测试循环右移
        control = 3'b110;
        #10;

        //测试循环左移
        control = 3'b111;
        #10;

        $finish;//结束仿真
    end
endmodule