module fsm_bin(
    input clk, in, reset,   //输入为时钟信号clk，输入信号in，复位信号reset
    output reg out,         //输出out
    output reg [3:0] sta  //显示4个触发器的状态
);

    //状态定义：9个状态S0到S8,用来描述有限状态机的状态集合
    parameter [3:0] S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4,
                    S5 = 5, S6 = 6, S7 = 7, S8 = 8;

    //状态寄存器和相关信号
    wire [3:0] state_din,   //表示下一个状态的输入信号
               state_dout;  //表示当前状态的输出信号
    wire state_wen;         //写使能信号，控制状态是否更新

    //状态寄存器实例化
    SimReg#(4,0) state(clk, reset, state_din, state_dout, state_wen);

    //状态更新控制信号，直接将state_wen设为1,保证状态寄存器每个时钟周期都能更新。
    assign state_wen = 1;

    //输出逻辑（outMux）
    //#(9, 4, 1)：表示 9 个状态（输入键值），4 位宽的状态值，1 位宽的输出值。
    //state_dout：作为选择键，决定输出。default_out(0)：默认为 0。
    //状态表：S4 和 S8 输出 1，其他状态输出 0。
    MuxKeyWithDefault#(9, 4, 1) outMux(.out(out), .key(state_dout), .default_out(0), .lut({
    S0, 1'b0,
    S1, 1'b0,
    S2, 1'b0,
    S3, 1'b0,
    S4, 1'b1,
    S5, 1'b0,
    S6, 1'b0,
    S7, 1'b0,
    S8, 1'b1
    }));

    //状态转换逻辑(stateMux)
    //#(9, 4, 4)：表示 9 个状态（键值），4 位宽的状态值。
    //state_dout：作为选择键，决定下一个状态。default_out(S0)：默认返回 S0。
    //状态转换表：in 为 1 时，状态跳转至 S5 或其他预定义状态。in 为 0 时，状态按顺序递增或停留在某状态。
    MuxKeyWithDefault#(9, 4, 4) stateMux(.out(state_din), .key(state_dout), .default_out(S0), .lut({
    S0, in ? S5 : S1,
    S1, in ? S5 : S2,
    S2, in ? S5 : S3,
    S3, in ? S5 : S4,
    S4, in ? S5 : S4,
    S5, in ? S6 : S1,
    S6, in ? S7 : S1,
    S7, in ? S8 : S1,
    S8, in ? S8 : S1
    }));

    //显示4个触发器的状态
    assign sta = state_dout;

endmodule