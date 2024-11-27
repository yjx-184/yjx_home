module fsm_mealy(clk, in, reset, out, sta, btn);
    input clk;
    input in;
    input reset;
    input btn;
    output reg out;
    output reg [3:0] sta;

    //按钮代替时钟信号的中间信号定义
    wire btn_clk;

    //状态定义：9个状态S0到S8,用来描述有限状态机的状态集合
    parameter [3:0] S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4,
                    S5 = 5, S6 = 6, S7 = 7, S8 = 8;

    //状态寄存器和相关信号
    reg [3:0] state, next_state;    //当前状态，下一个状态

    //状态寄存器更新
    always @(posedge btn_clk or posedge reset) begin
        if(reset)                  //复位信号，低电平有效
            state <= S0;
        else
            state <= next_state;   //状态更新为下一个状态
    end

    //状态转移
    always @(*) begin
        case(state)
            S0: next_state = in ? S5 : S1;
            S1: next_state = in ? S5 : S2;
            S2: next_state = in ? S5 : S3;
            S3: next_state = in ? S5 : S4;
            S4: next_state = in ? S5 : S4;
            S5: next_state = in ? S6 : S1;
            S6: next_state = in ? S7 : S1;
            S7: next_state = in ? S8 : S1;
            S8: next_state = in ? S8 : S1;
            default: next_state = S0;
        endcase
    end

    //输出，不仅依赖于当前状态state，还依赖于输入信号in
    always @(*) begin
        case(state)
            S0: out = in ? 1'b1 : 1'b0;
            S1: out = in ? 1'b1 : 1'b0;
            S2: out = in ? 1'b0 : 1'b0;
            S3: out = in ? 1'b0 : 1'b0;
            S4: out = in ? 1'b1 : 1'b0;
            S5: out = in ? 1'b1 : 1'b0;
            S6: out = in ? 1'b1 : 1'b0;
            S7: out = in ? 1'b1 : 1'b0;
            S8: out = in ? 1'b0 : 1'b0;
            default: out = 1'b0;
        endcase
    end 

    //按钮生成伪时钟信号
    button_clk u_btn_clk(
        .clk(clk),
        .btn(btn),
        .btn_clk(btn_clk)
    );

    //显示当前状态
    assign sta = state;

endmodule