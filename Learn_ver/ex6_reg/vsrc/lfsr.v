module lfsr(clk, reset, lfsr_out);
    input clk;      //时钟信号
    input reset;    //复位信号
    output reg [7:0] lfsr_out;  //当前伪随机输出

    wire feedback;  //存储反馈逻辑的结果

    //反馈逻辑：x8 = x4 ^ x3 ^ x2 ^ x0
    assign feedback = lfsr_out[4] ^ lfsr_out[3] ^ lfsr_out[2] ^ lfsr_out[0];

    always @(posedge clk or negedge reset) begin    //在时钟上升沿或复位信号的下降沿触发
        if(reset) begin            //复位信号
            lfsr_out <= 8'b00000001;    //将lfsr初始化为非零值，避免全零状态，lfsr会卡在全零状态
        end else if(lfsr_out == 8'b00000000) begin  //防止卡死
            lfsr_out <= 8'b00000001;
        end else begin
            lfsr_out <= {feedback, lfsr_out[7:1]};  //将feedback放在最高位，其余依次右移1位，形成新的输出
        end
    end

endmodule