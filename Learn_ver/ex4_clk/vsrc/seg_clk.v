module seg_clk(seg_in, seg_out);
    input [3:0] seg_in;
    output reg [7:0] seg_out;

    //定义参数
    parameter seg0 = 8'b11111101; // 数字 0
    parameter seg1 = 8'b01100000; // 数字 1
    parameter seg2 = 8'b11011010; // 数字 2
    parameter seg3 = 8'b11110010; // 数字 3
    parameter seg4 = 8'b01100110; // 数字 4
    parameter seg5 = 8'b10110110; // 数字 5
    parameter seg6 = 8'b10111110; // 数字 6
    parameter seg7 = 8'b11100000; // 数字 7
    parameter seg8 = 8'b11111111; // 数字 8
    parameter seg9 = 8'b11110111; // 数字 9

    always @(seg_in)begin
        case (seg_in)
            4'd0: seg_out = ~seg0;
            4'd1: seg_out = ~seg1;
            4'd2: seg_out = ~seg2;
            4'd3: seg_out = ~seg3;
            4'd4: seg_out = ~seg4;
            4'd5: seg_out = ~seg5;
            4'd6: seg_out = ~seg6;
            4'd7: seg_out = ~seg7;
            4'd8: seg_out = ~seg8;
            4'd9: seg_out = ~seg9;
            default: seg_out = 8'b00000000;
        endcase
    end
endmodule