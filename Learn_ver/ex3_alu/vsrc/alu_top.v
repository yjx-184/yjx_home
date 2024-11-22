module alu_top(i_a, i_b, i_op, o_result, o_cin, o_carry, o_overflow, o_max, o_equ, o_zero, o_signbit, o_seg);
    input [3:0] i_a;        //4位输入数a
    input [3:0] i_b;        //4位输入数b
    input [2:0] i_op;       //3位操作码，选择alu的操作
    output [3:0] o_result;  //4位运算结果
    output o_cin;           //输出1位加减法的控制标志
    output o_carry;         //输出1位进位标志
    output o_overflow;      //输出1位溢出标志
    output o_max;           //输出1位最大值标志
    output o_equ;           //输出1位相等标志
    output o_zero;          //输出零位标志
    output [7:0] o_signbit; //符号位标志
    output [7:0] o_seg;     //7段数码管控制信号

    //中间信号
    //加法与减法的控制码
    wire cin_0, cin_1;
    //不同运算结果
    wire [3:0] result_0, result_1, result_2, result_3, result_4, result_5, result_6, result_7, o_result_0;
    //加法和减法的进位信号
    wire carry_0, carry_1;
    //加法和减法的溢出信号
    wire overflow_0, overflow_1;
    //零位
    wire zero_0, zero_1;
    //比较运算
    wire max_0, equ_0;


    //控制信号
    assign cin_0 = 1'b0;  // 初始化加法的控制信号，固定为0
    assign cin_1 = 1'b1;  // 初始化减法的控制信号，固定为1
    assign o_max = (i_op == 3'b110)?max_0:1'b0;     //当操作码到110,o_max输出比较结果
    assign o_equ = (i_op == 3'b111)?equ_0:1'b0;     //当操作码到111,o_equ输出是否相等
    assign o_result = o_overflow?4'b0:o_result_0;   //如果发生溢出，o_result输出全0,否则输出o_led_0


    //符号位控制,当最高位为1时点亮-号，否则熄灭
    assign o_signbit = o_result[3]?8'b11111101:8'b11111111;

    //绝对值处理
    wire [3:0] abs_result;
    assign abs_result = o_result[3] ? (~o_result + 1) : o_result; // 若为负数，取补码

    //实例化
    //加法模块
    adder u0_adder(
        .i_a(i_a),
        .i_b(i_b),
        .cin(cin_0),
        .o_carry(carry_0),
        .o_overflow(overflow_0),
        .o_result(result_0),
        .zero(zero_0)
    );

    //减法模块
    adder u1_adder(
        .i_a(i_a),
        .i_b(i_b),
        .cin(cin_1),
        .o_carry(carry_1),
        .o_overflow(overflow_1),
        .o_result(result_1),
        .zero(zero_1)
    );

    //逻辑运算
    //取反
    log_not u0_log_not(
        .i_a(i_a), 
        .o_result(result_2)
    );

    //与
    log_and u0_log_and(
        .i_a(i_a), 
        .i_b(i_b), 
        .o_result(result_3)
    );

    //或
    log_or u0_log_or(
        .i_a(i_a), 
        .i_b(i_b), 
        .o_result(result_4)
    );

    //异或
    log_xor u0_log_xor(
        .i_a(i_a), 
        .i_b(i_b), 
        .o_result(result_5)
    );

    //比较大小
    log_max u0_log_max(
        .i_a(i_a),
        .i_b(i_b),
        .o_max(max_0),
        .o_result(result_6)
    );
    
    //判断相等
    log_equ u0_log_equ(
        .i_a(i_a),
        .i_b(i_b),
        .o_equ(equ_0),
        .o_result(result_7)
    );

    //数码管模块
    seg u0_seg(
        .i_signbit(o_result[3]),
        .seg_in(abs_result),
        .seg_out(o_seg)
    );

    //加减法标志选择
    MuxKey #(2,3,1) i0(o_cin, i_op, {
    3'b000, cin_0,  // 加法的标志
    3'b001, cin_1   // 减法的标志
    });

    //进位标志选择
    MuxKey #(2,3,1) i1(o_carry, i_op, { 
        3'b000, carry_0, // 加法的进位
        3'b001, carry_1  // 减法的进位
    });

    //溢出标志选择
    MuxKey #(2,3,1) i2(o_overflow, i_op, { 
        3'b000, overflow_0, // 加法的溢出
        3'b001, overflow_1  // 减法的溢出
    });

    //结果输出选择
    MuxKey #(8,3,4) i3(o_result_0, i_op, { 
        3'b000, result_0,   // 加法
        3'b001, result_1,   // 减法
        3'b010, result_2,   // 取反
        3'b011, result_3,   // 与
        3'b100, result_4,   // 或
        3'b101, result_5,   // 异或
        3'b110, result_6,   // 较大值
        3'b111, result_7    // 判断相等
    });

endmodule

