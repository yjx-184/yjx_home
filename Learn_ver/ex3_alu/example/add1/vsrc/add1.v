module add1(a_i, b_i, c_i, s_i, c_o);
    input a_i;      //待加位a
    input b_i;      //待加位b
    input c_i;      //待加进位ci
    output s_i;     //结果和s
    output c_o;     //下一位进位c_i+1

    //si = （a异或b）异或ci
    assign s_i = (a_i ^ b_i) ^ c_i;

    //c_i+1进位运算
    assign c_o = ((a_i ^ b_i)&c_i) | (a_i & b_i);

endmodule