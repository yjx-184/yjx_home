module subadd(a,b,cin,carry,overflow,result,zero);
    input [3:0] a;          //操作数a
    input [3:0] b;          //操作数b
    input cin;              //控制加减法，sub为1,add为0
    output carry;           //进位
    output overflow;         //溢出
    output [3:0] result;    //结果
    output zero;            //零判断位

    wire [3:0] t_add_cin;   //中间变量，用于存储经过cin控制的b的处理结果

    //功能实现，通过控制cin来实现加法和减法逻辑
    assign t_add_cin = ({4{cin}}^b) + cin;
    assign {carry, result} = a + t_add_cin;
    assign overflow = (a[3] == t_add_cin[3]) && (result[3] != a[3]);

    assign zero = ~(| result);
    
endmodule