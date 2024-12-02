`timescale 1ns / 1ps
module ps2_keyboard_model(
    output reg ps2_clk,         //ps/2时钟信号，作为输出模拟键盘的时钟行为
    output reg ps2_data         //ps/2数据信号，作为输出模拟键盘发送的数据
    );
parameter [31:0] kbd_clk_period = 60;   //表示ps/2时钟周期为60
initial ps2_clk = 1'b1;                 //初始化时钟信号为高电平

task kbd_sendcode;
    input [7:0] code; //扫描码，表示需要发送的键盘数据
    integer i;

    reg[10:0] send_buffer;  //定义了一个11位的寄存器，用于存储完整的数据
    begin
        send_buffer[0]   = 1'b0;  // 起始位，固定为低电平0
        send_buffer[8:1] = code;  // 发送的扫描码
        send_buffer[9]   = ~(^code); // 奇校验
        send_buffer[10]  = 1'b1;  // 停止位固定为高电平1
        i = 0;
        while( i < 11) begin
            // set kbd_data
            ps2_data = send_buffer[i];
            #(kbd_clk_period/2) ps2_clk = 1'b0;
            #(kbd_clk_period/2) ps2_clk = 1'b1;
            i = i + 1;
        end
    end
endtask

endmodule