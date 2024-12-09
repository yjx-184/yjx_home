//与
module log_and(i_a, i_b, o_result);
    input [31:0] i_a;
    input [31:0] i_b;
    output [31:0] o_result;

    assign o_result = i_a & i_b;

endmodule