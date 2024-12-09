`timescale 1ns / 1ps

module tb_char_display;
    //接口信号
    //输入信号
    reg clk;
    reg clrn;
    reg [7:0] ascii;
    reg [9:0] x;
    reg [9:0] y;

    //输出信号
    wire [23:0] vga_data;

    //实例化被测试模块
    char_display uut(
        .clk(clk),
        .clrn(clrn),
        .ascii(ascii),
        .x(x),
        .y(y),
        .vga_data(vga_data)
    );

    //生成时钟信号
    always begin
        #5 clk = ~clk;
    end

    //初始化信号
    initial begin
        //初始化信号
        clk = 0;
        clrn = 0;
        ascii = 8'h00;
        x = 0;
        y = 0;

        //等待一段时间后释放复位
        #20 clrn = 1;

        //测试字符A
        #10 ascii = 8'h41;
        #10 x = 0; y = 0;
        #10 x = 1; y = 0;
        #10 x = 2; y = 0;
        #10 x = 3; y = 0;
        #10 x = 4; y = 0;
        #10 x = 5; y = 0;
        #10 x = 6; y = 0;

        //测试字符B
        #20 ascii = 8'h42;
        #10 x = 0; y = 0;
        #10 x = 1; y = 0;
        #10 x = 2; y = 0;

        //测试字符C
        #20 ascii = 8'h43;
        #10 x = 0; y = 0;
        #10 x = 1; y = 0;

        //测试字符D
        #20 ascii = 8'h44;
        #10 x = 0; y = 0;
        #10 x = 1; y = 0;

        //结束仿真
        #100 $finish;
    end

    initial begin
        $monitor("Time: %t | ASCII: %h | x: %d , y: %d | VGA Data: %h",
                    $time, ascii , x, y, vga_data);
    end     

    initial begin
    $dumpfile("char_display.vcd");
    $dumpvars(0, tb_char_display);
end

endmodule