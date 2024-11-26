module reg_control(clk, reset, control, s_in, d_in, reg_out);
    input clk;                  //时钟信号
    input reset;                //复位信号
    input [2:0] control;        //控制信号，选择模式
    input s_in;                 //串行输入
    input [7:0] d_in;           //并行输入
    output reg [7:0] reg_out;   //并行输出

    always @(posedge clk or negedge reset) begin
        if(reset) begin
            reg_out <= 8'b0;
        end else begin
            case(control)
                3'b000: reg_out <= 8'b0;    //清零
                3'b001: reg_out <= d_in;    //置数
                3'b010: reg_out <= reg_out >> 1;    //逻辑右移
                3'b011: reg_out <= reg_out << 1;    //逻辑左移
                3'b100: reg_out <= {reg_out[7], reg_out[7:1]};  //算术右移
                3'b101: reg_out <= {reg_out[6:0], s_in};    //左端串行输入，右移
                3'b110: reg_out <= {reg_out[0], reg_out[7:1]};//循环右移
                3'b111: reg_out <= {reg_out[6:0], reg_out[7]};//循环左移
                default: reg_out <= reg_out;    //默认保持不变
            endcase
        end
    end
endmodule