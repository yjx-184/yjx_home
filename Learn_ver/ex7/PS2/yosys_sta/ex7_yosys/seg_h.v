module seg_h(seg_in,seg_out, en);
    input [3:0] seg_in;
    input en;
    output reg [7:0] seg_out;

    // 定义16进制字符
    parameter seg0  = 8'b11111100; // 显示 0
    parameter seg1  = 8'b01100000; // 显示 1
    parameter seg2  = 8'b11011010; // 显示 2
    parameter seg3  = 8'b11110010; // 显示 3
    parameter seg4  = 8'b01100110; // 显示 4
    parameter seg5  = 8'b10110110; // 显示 5
    parameter seg6  = 8'b10111110; // 显示 6
    parameter seg7  = 8'b11100000; // 显示 7
    parameter seg8  = 8'b11111110; // 显示 8
    parameter seg9  = 8'b11110110; // 显示 9
    parameter segA  = 8'b11101110; // 显示 A
    parameter segB  = 8'b00111110; // 显示 B
    parameter segC  = 8'b10011100; // 显示 C
    parameter segD  = 8'b01111010; // 显示 D
    parameter segE  = 8'b10011110; // 显示 E
    parameter segF  = 8'b10001110; // 显示 F

    always @(seg_in or en) begin
        if(en == 1'b0) begin
            seg_out = 8'b11111111; // 全灭
        end else begin
            case(seg_in)
                4'd0:  seg_out = ~seg0;
                4'd1:  seg_out = ~seg1;
                4'd2:  seg_out = ~seg2;
                4'd3:  seg_out = ~seg3;
                4'd4:  seg_out = ~seg4;
                4'd5:  seg_out = ~seg5;
                4'd6:  seg_out = ~seg6;
                4'd7:  seg_out = ~seg7;
                4'd8:  seg_out = ~seg8;
                4'd9:  seg_out = ~seg9;
                4'd10: seg_out = ~segA;  // A
                4'd11: seg_out = ~segB;  // B
                4'd12: seg_out = ~segC;  // C
                4'd13: seg_out = ~segD;  // D
                4'd14: seg_out = ~segE;  // E
                4'd15: seg_out = ~segF;  // F
                default: seg_out = 8'b11111111; // 全灭
            endcase
        end
    end

endmodule