
//使用算术赋值语句和向量来实现4位加法器

module add4b(a,b,sum,co);
    input [3:0] a;
    input [3:0] b;
    output [3:0] sum;
    output co;

    assign {co,sum} = a + b;

endmodule
