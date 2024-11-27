module button_clk(clk,btn, btn_clk);
    input clk;                  //全局时钟信号，
    input btn;                  //按钮输入信号
    output reg btn_clk;         //按钮生成的伪时钟信号

    reg btn_sta1, btn_sta2; //同步寄存器
    reg btn_last;           //上一个状态

    //将按钮的输入信号btn同步到全局时钟clk的时钟域中，防止由于信号跨时钟域而引发亚稳态问题。
    always @(posedge clk) begin
            btn_sta1 <= btn;        //将按钮输入信号btn同步到寄存器btn_sta1
            btn_sta2 <= btn_sta1;   //将btn_sta1中的数据同步到btn_sta2中
    end

    //检测按钮的上升沿并生成单周期脉冲信号
    always @(posedge clk) begin
            //如果当btn_sta2为高电平且上一个状态btn_last为低电平则表示检测到按钮按下
            if(btn_sta2 && !btn_last) begin
                btn_clk <= 1;       //生成一个脉冲信号
            end else begin
                btn_clk <= 0;       //保证脉冲信号只有一个时钟周期
            end
            btn_last <= btn_sta2;   //更新按钮的上一个状态
        end
endmodule