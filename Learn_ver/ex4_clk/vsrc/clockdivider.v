module clockdivider(clk, reset, clk_1s);
    input clk;          //输入时钟信号
    input reset;        //异步复位信号，高电平有效
    output reg clk_1s;  //输出1秒的分频时钟

    //定义计数器
    reg [24:0] count_clk;

    always @(posedge clk or posedge reset) begin
        if(reset) begin
            //复位条件，清零计数器和输出时钟
            count_clk <=25'd0;
            clk_1s <= 1'b0;
        end else begin
            if(count_clk == 25'd24999999) begin
                //当计数器到达目标值时，翻转信号并重置计数器
                count_clk <= 25'd0;
                clk_1s <= ~clk_1s;
            end else begin
                count_clk <= count_clk + 1;
            end
        end
    end
endmodule