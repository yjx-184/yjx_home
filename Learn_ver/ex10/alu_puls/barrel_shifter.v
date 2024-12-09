module barrel_shifter(
    input [31:0] Din,                   //输入数据
    input [31:0] B1,                    //接收来自B的输入数据，带有移位量
    input l_r,                          //1右移，0左移
    input a_l,                          //1算术右移，0逻辑右移
    output [31:0] shift                 //输出数据
);

    wire [4:0] Shamt;                   //移位量
    assign Shamt = B1[4:0];             //移位量为B1的低5位

   //根据 l_r 和 a_l 的值选择对应的移位操作
    assign shift = (l_r) ? ( ( a_l ) ? ( $signed( Din ) >>> Shamt ) : ( Din >> Shamt ) ) : ( Din << Shamt );


endmodule