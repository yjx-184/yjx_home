module tb_seg;
    //接口
    reg i_signbit;
    reg [3:0] seg_in;
    wire [7:0] seg_out;


    //实例化被测模块
    seg uut(
        .i_signbit(i_signbit),
        .seg_in(seg_in),
        .seg_out(seg_out)
    );

    //时钟信号生成
    // initial begin
    //     clk = 0;
    //     forever #5 clk = ~clk;
    // end

    //激励信号
    initial begin
        //生成VCD波形文件
        $dumpfile("tb_seg.vcd");
        $dumpvars(0, tb_seg);

        
        i_signbit = 0;
        seg_in = 4'd0;
        #10 seg_in = 4'd1;
        #10 seg_in = 4'd2;
        #10 seg_in = 4'd3;
        #10 seg_in = 4'd4;
        #10 seg_in = 4'd5;
        #10 seg_in = 4'd6;
        #10 seg_in = 4'd7;
        #10 seg_in = 4'd8;

        //切换到有符号
        i_signbit = 1;
        #10 seg_in = 4'd1;
        #10 seg_in = 4'd2;
        #10 seg_in = 4'd3;
        #10 seg_in = 4'd4;
        #10 seg_in = 4'd5;
        #10 seg_in = 4'd6;
        #10 seg_in = 4'd7;
        #10 seg_in = 4'd8;

        //结束仿真
        #10 $finish;
    end
        //输出监视
        initial begin
            $monitor("时间%t: i_signbit = %b, seg_in = %d, seg_out = %b",
                        $time, i_signbit, seg_in, seg_out);
        end


    

endmodule