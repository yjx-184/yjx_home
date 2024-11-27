module top(
    input clk,
    input reset,
    input in,
    input btn,
    output reg out,
    output reg [3:0] sta
);
    //按钮代替时钟信号的中间信号定义
    wire btn_clk;

    //按钮生成伪时钟信号
    button_clk u_btn_clk(
        .clk(clk),
        .btn(btn),
        .btn_clk(btn_clk)
    );

    //实例化fsm_bin
    fsm_bin u_fsm_bin(
        .clk(btn_clk),
        .reset(reset),
        .in(in),
        .out(out),
        .sta(sta)
    );


endmodule