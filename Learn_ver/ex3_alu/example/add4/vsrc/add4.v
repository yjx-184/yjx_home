module add4(a,b,ci,sum,co);
    input [3:0] a;
    input [3:0] b;
    input ci;
    output [3:0] sum;
    output co;
    wire [3:0] count;

    //实例化加法器
    add1 u0(a[0], b[0], ci, sum[0], count[0]);
    add1 u1(a[1], b[1], count[0], sum[1], count[1]);
    add1 u2(a[2], b[2], count[1], sum[2], count[2]);
    add1 u3(a[3], b[3], count[2], sum[3], count[3]);
    assign co = count[3];

endmodule

module add1(a, b, ci, sum, co);
    input a;
    input b;
    input ci;
    output sum;
    output co;

    //和
    assign sum = (a ^ b) ^ ci;

    //c_i+1进位运算
    assign co = ((a ^ b)&ci) | (a & b);

endmodule