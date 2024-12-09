module seg(i_signbit, seg_in, seg_out);
    input i_signbit;            // 控制是否输出符号位
    input [3:0] seg_in;         // 4位的输入
    output reg [7:0] seg_out;   // 8位输出，对数码管的控制信号

    // 参数定义：数码管显示编码
    parameter seg0 = 8'b11111101; // 数字 0
    parameter seg1 = 8'b01100000; // 数字 1
    parameter seg2 = 8'b11011010; // 数字 2
    parameter seg3 = 8'b11110010; // 数字 3
    parameter seg4 = 8'b01100110; // 数字 4
    parameter seg5 = 8'b10110110; // 数字 5
    parameter seg6 = 8'b10111110; // 数字 6
    parameter seg7 = 8'b11100000; // 数字 7
    parameter seg8 = 8'b11111111; // 数字 8

    always @(*) begin
        // 当收到i_signbit = 0,无符号数显示 (0 到 7)
        if (~i_signbit) begin
            case (seg_in)
                4'd0:  seg_out = ~seg0;
                4'd1:  seg_out = ~seg1;
                4'd2:  seg_out = ~seg2;
                4'd3:  seg_out = ~seg3;
                4'd4:  seg_out = ~seg4;
                4'd5:  seg_out = ~seg5;
                4'd6:  seg_out = ~seg6;
                4'd7:  seg_out = ~seg7;
                4'd8:  seg_out = ~seg8;
                default: seg_out = 8'b00000000; // 默认熄灭
            endcase
        end
        // 有符号数显示 (-1 到 -8)
        else begin
            case (seg_in)
                4'd1:  seg_out = ~seg1; // 显示 -1
                4'd2:  seg_out = ~seg2; // 显示 -2
                4'd3:  seg_out = ~seg3; // 显示 -3
                4'd4:  seg_out = ~seg4; // 显示 -4
                4'd5:  seg_out = ~seg5; // 显示 -5
                4'd6:  seg_out = ~seg6; // 显示 -6
                4'd7:  seg_out = ~seg7; // 显示 -7
                4'd8:  seg_out = ~seg8; // 显示 -8
                default: seg_out = 8'b00000000; // 默认熄灭
            endcase
        end
    end
endmodule
