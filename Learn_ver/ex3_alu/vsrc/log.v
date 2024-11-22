//取反
module log_not(i_a, o_result);
    input [3:0] i_a;
    output [3:0] o_result;

    assign o_result = ~i_a;

endmodule

//与
module log_and(i_a, i_b, o_result);
    input [3:0] i_a;
    input [3:0] i_b;
    output [3:0] o_result;

    assign o_result = i_a & i_b;

endmodule

//或
module log_or(i_a, i_b, o_result);
    input [3:0] i_a;
    input [3:0] i_b;
    output [3:0] o_result;

    assign o_result = i_a | i_b;

endmodule

//异或
module log_xor(i_a, i_b, o_result);
    input [3:0] i_a;
    input [3:0] i_b;
    output [3:0] o_result;

    assign o_result = i_a ^ i_b;
endmodule

//比较大小
module log_max(i_a, i_b, o_max, o_result);
    input [3:0] i_a;
    input [3:0] i_b;
    output o_max;
    output [3:0] o_result;

    assign o_max = (i_a > i_b)?1'b1:1'b0;
    assign o_result = (i_a > i_b)?i_a:i_b;

endmodule

//相等
module log_equ(i_a, i_b, o_equ, o_result);
    input [3:0] i_a;
    input [3:0] i_b;
    output o_equ;
    output [3:0] o_result;

    assign o_equ = (i_a == i_b)?1'b1:1'b0;
    assign o_result = i_a;

endmodule