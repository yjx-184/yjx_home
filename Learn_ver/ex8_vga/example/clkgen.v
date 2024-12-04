//通用时钟生成代码
module clkgen(clkin, rst, clken, clkout);
    input clkin;                //输入时钟信号
    input rst;                  //复位信号
    input clken;                //启用信号
    output reg clkout;          //输出时钟信号

    parameter clk_freq = 1000;  //时钟频率参数

    // countlimit 表示每多少个输入时钟周期输出一个高低跳变
    parameter countlimit = 50000000/2/clk_freq; //自动计算计数次数

    reg [31:0] clkcount;        //32位计数器，用于计算输入时钟周期

    always @(posedge clkin)
        if(rst) begin
            //复位时，清零计数器并将输出时钟设置为低电平
            clkcount = 0;       
            clkout = 1'b0;
        end else begin
            if(clken) begin
                clkount = clkcount + 1;

                //当计数器达到预设的上限时，切换输出时钟的状态（高/低）
                if(clkcount >= countlimit) begin
                    clkcount = 31'd0;       //计数去重置
                    clkout = ~clkout;       //反转输出时钟
                end else 
                        clkout = clkout;    //保持当前输出
            end else begin
                //如果禁用时钟，保持当前计数器值和输出时钟状态
                clkcount = clkcount;
                clkout = clkout;
            end
        end
endmodule