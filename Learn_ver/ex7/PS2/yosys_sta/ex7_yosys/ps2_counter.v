module ps2_counter(
    input clk,                  //时钟信号
    input clrn,                 //复位信号
    input key_press,            //按下标志
    input key_release,          //松开标志
    output reg [3:0] units,     // 个位
    output reg [3:0] tens       // 十位
);

    // 记录是否已经被计数
    reg counted;

    always @(posedge clk or negedge clrn) begin
        if (clrn == 1'b0) begin                 //复位信号
            units <= 4'b0;                      //将个位重置
            tens <= 4'b0;                       //将十位重置
            counted <= 1'b0;                    //将计数标志重置
        end else begin
            if (key_press && !counted) begin    //检查按键按下且未被计数
                counted <= 1'b1;                //标记已经被计数
                if (units == 4'd9) begin        
                    units <= 4'd0;              //当个位到达9重置为0
                    if (tens == 4'd9) begin
                        tens <= 4'd0;           // 超过99次归0
                    end else begin
                        tens <= tens + 1;
                    end
                end else begin
                    units <= units + 1;
                end
            end 
            else if (key_release) begin
                // 按键释放时，标记为未计数
                counted <= 1'b0;
            end
        end
    end

endmodule