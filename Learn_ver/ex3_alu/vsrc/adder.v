module adder(i_a, i_b,cin,o_carry,o_overflow,o_result,zero);
    input [3:0] i_a;          //操作数a
    input [3:0] i_b;          //操作数b
    input cin;                //控制加减法，sub为1,add为0
    output o_carry;           //进位
    output o_overflow;        //溢出
    output [3:0] o_result;    //结果
    output zero;            //零判断位

    wire [3:0] t_add_cin;   //中间变量，用于存储经过cin控制的b的处理结果


    //功能实现，通过控制cin来实现加法和减法逻辑
    assign t_add_cin = ({4{cin}}^i_b) + {3'b0,cin};
    assign {o_carry, o_result} = i_a + t_add_cin;
    assign o_overflow = (i_a[3] == t_add_cin[3]) && (o_result[3] != i_a[3]);

    assign zero = ~(| o_result);
    
endmodule