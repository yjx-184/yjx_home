module seg7(seg_in, seg_out);
    input [2:0] seg_in;
    output reg [7:0] seg_out;

    parameter seg0 = 8'b11111101;
    parameter seg1 = 8'b01100000;
    parameter seg2 = 8'b11011010;
    parameter seg3 = 8'b11110010;
    parameter seg4 = 8'b01100110;
    parameter seg5 = 8'b10110110;
    parameter seg6 = 8'b10111110;
    parameter seg7 = 8'b11100000;

    always @(seg_in) begin
        case(seg_in)
            3'd0: seg_out = ~seg0;
            3'd1: seg_out = ~seg1;
            3'd2: seg_out = ~seg2;
            3'd3: seg_out = ~seg3;
            3'd4: seg_out = ~seg4;
            3'd5: seg_out = ~seg5;
            3'd6: seg_out = ~seg6;
            3'd7: seg_out = ~seg7;
        endcase
    end
endmodule