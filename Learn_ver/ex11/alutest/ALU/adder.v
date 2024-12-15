module adder(A1, B1,Cin,Carry,Overflow,Result,Zero);
    input [31:0] A1;          //操作数a
    input [31:0] B1;          //操作数b
    input Cin;                //控制加减法，sub为1,add为0
    output Carry;           //进位
    output Overflow;        //溢出
    output [31:0] Result;    //结果
    output Zero;            //零判断位

    wire [31:0] t_add_cin;   //中间变量，用于存储经过cin控制的b的处理结果


    //功能实现，通过控制cin来实现加法和减法逻辑
    assign t_add_cin = (Cin) ? ~B1 + 1'b1 : B1; // 当Cin=1时，B1取反+1（减法），否则不变（加法）
    assign {Carry, Result} = A1 + t_add_cin;    // 加法操作
    assign Overflow = (A1[31] == t_add_cin[31]) && (Result[31] != A1[31]);

    assign Zero = ~(| Result);
    
endmodule