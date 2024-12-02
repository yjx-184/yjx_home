`timescale 1ns / 1ps
module keyboard_sim;

/* 参数定义 */
parameter [31:0] clock_period = 10; //定义时钟周期为10单位

/* ps2_keyboard 接口信号 */
reg clk,clrn;               //时钟信号和复位信号
wire [7:0] data;            //键盘数据线
wire ready,overflow;        //键盘准备标志，溢出标志
wire kbd_clk, kbd_data;     //ps2时钟线和数据线
reg nextdata_n;             //控制可读数据的信号

//实例化ps/2键盘模型，用于模拟键盘行为
ps2_keyboard_model model(
    .ps2_clk(kbd_clk),
    .ps2_data(kbd_data)
);

//实例化ps/2键盘接口模块，连接各信号
ps2_keyboard inst(
    .clk(clk),
    .clrn(clrn),
    .ps2_clk(kbd_clk),
    .ps2_data(kbd_data),
    .data(data),
    .ready(ready),
    .nextdata_n(nextdata_n),
    .overflow(overflow)
);

//时钟生成器
initial begin
    clk = 0;
    forever
        #(clock_period/2) clk = ~clk;
end

//仿真过程
initial begin
    clrn = 1'b0;  #20;  //复位信号低，持续20ns
    clrn = 1'b1;  #20;  //复位信号高，持续20ns
    model.kbd_sendcode(8'h1C); // 按下 'A'
    #20 nextdata_n =1'b0; #20 nextdata_n =1'b1;//请求读取数据
    model.kbd_sendcode(8'hF0); // 发送断开码，表示A被时方
    #20 nextdata_n =1'b0; #20 nextdata_n =1'b1; //请求读取数据
    model.kbd_sendcode(8'h1C); // 发送 'A'的释放码
    #20 nextdata_n =1'b0; #20 nextdata_n =1'b1; //请求读取数据
    model.kbd_sendcode(8'h1B); // 按下 'S'
    #20 model.kbd_sendcode(8'h1B); // 保持按下 'S'
    #20 model.kbd_sendcode(8'h1B); // 保持按下 'S'
    model.kbd_sendcode(8'hF0); // 发送断开码，表示s被释放
    model.kbd_sendcode(8'h1B); // 发送 'S'的释放码
    #20;
    $stop;
end

endmodule