module ALU(
    input [31:0] A,             //输入数A
    input [31:0] B,             //输入数B
    input [3:0] ALUctr,         //输入ALUctr
    output Less,            //输出符号标志
    output Zero,            //零标志
    output reg [31:0] ALUout    //输出ALUout
);

    //内部信号
    wire [2:0] actr;            //最后8选1的控制信号

    //A/L控制移位器进行算术移位还是逻辑移位，L/R控制是左移还是右移
    //U/S控制比较大小是带符号比较还是无符号比较，S/A控制是加法还是减法。
    wire a_l, l_r, u_s, Cin;
    
    //进位，溢出位
    wire carry, overflow;
    wire [31:0] result;            //加法结果

    //移位结果，逻辑运算结果，带（无）符号小于置位结果输出
    wire [31:0] shift, i_XOR, i_AND, i_OR, sit;


    //实例化
    alu_control u_a_control(
        .ALUctr(ALUctr),
        .actr(actr),
        .a_l(a_l),
        .l_r(l_r),
        .u_s(u_s),
        .Cin(Cin)
    );

    adder u_adder(
        .A1(A),
        .B1(B),
        .Cin(Cin),
        .Carry(carry),
        .Overflow(overflow),
        .Result(result),
        .Zero(Zero)
    );

    adder_less u_al(
        .Carry(carry),
        .Overflow(overflow),
        .Cin(Cin),
        .i_Result(result),
        .u_s(u_s),
        .o_Result(sit),
        .Less(Less)
    );

    barrel_shifter u_bs(
        .Din(A),
        .B1(B),
        .l_r(l_r),
        .a_l(a_l),
        .shift(shift)
    );

    log_and u_l_and(
        .i_a(A),
        .i_b(B),
        .o_result(i_AND)
    );

    log_or u_l_or(
        .i_a(A),
        .i_b(B),
        .o_result(i_OR)
    );

    log_xor u_l_xor(
        .i_a(A),
        .i_b(B),
        .o_result(i_XOR)
    );


    //8选1,输出
    always @(*) begin
        case (actr)
            3'b000: ALUout = result;        // 选择加法结果
            3'b001: ALUout = shift;         // 选择左移结果
            3'b010: ALUout = sit;           // 选择带符号/无符号小于结果
            3'b011: ALUout = B;             // 直接输出B
            3'b100: ALUout = i_XOR;         // 选择异或输出
            3'b101: ALUout = shift;         // 选择右移结果
            3'b110: ALUout = i_OR;          // 选择逻辑或输出
            3'b111: ALUout = i_AND;         // 选择逻辑与输出
            default: ALUout = 32'b0;        // 默认输出0
        endcase
    end

endmodule