module clk_top(clk, reset, sta, seg_tens, seg_units, led_o);
    input clk;              //时钟信号
    input reset;            //异步复位
    input sta;              //状态：1开始和0停止
    output [7:0] seg_tens;  //数码管十位显示
    output [7:0] seg_units; //数码管个位显示
    output reg led_o;       //led闪烁信号

    //参数定义
    wire clk_1s;
    reg [6:0] count;    //计数器，0-99

    always @(posedge clk_1s or posedge reset) begin
        if(reset) begin
            //复位
            count <= 7'b0;
            led_o <= 1'b0;
        end else if(sta) begin
            if(count == 7'd99) begin
                count <= 7'd0;      //99后重置计数器
                led_o <= 1'b1;      //触发闪烁
            end else begin
                count <= count + 1;
                led_o <= 1'b0;
            end
        end
    end

    //分离十位数和个位数
    wire [6:0] tens_full = count / 10;
    wire [6:0] units_full = count % 10;

    wire [3:0] tens = tens_full[3:0];  // 截断到 4 位
    wire [3:0] units = units_full[3:0]; // 截断到 4 位

    //实例化
    clockdivider clkck_divider(
        .clk(clk),
        .reset(reset),
        .clk_1s(clk_1s)
    );

    seg_clk tens_seg(
        .seg_in(tens),
        .seg_out(seg_tens)
    );

    seg_clk units_seg(
        .seg_in(units),
        .seg_out(seg_units)
    );

endmodule