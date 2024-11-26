module reg_top(clk, reset, btn, seg_u, seg_t);
    input clk;          //全局时钟
    input reset;        //复位信号
    input btn;          //按钮输入
    output [7:0] seg_u; //数码管显示低位
    output [7:0] seg_t; //数码管显示高位

    //中间信号定义
    wire btn_clk;
    wire [7:0] lfsr_out;

    //实例化
    //按钮生成伪时钟信号
    button_clk u_btn_clk(
        .clk(clk),
        .reset(reset),
        .btn(btn),
        .btn_clk(btn_clk)
    );
    
    //lfsr随机数生成
    lfsr u_lfsr(
        .clk(btn_clk),
        .reset(reset),
        .lfsr_out(lfsr_out)
    );

    //数码管显示低位
    seg_h u_seg_u(
        .seg_in(lfsr_out[3:0]),
        .seg_out(seg_u)
    );

    //数码管显示高位
    seg_h u_seg_t(
        .seg_in(lfsr_out[7:4]),
        .seg_out(seg_t)
    );

    
endmodule