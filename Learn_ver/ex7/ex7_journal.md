

# 实验七 状态机及键盘输入
## 状态机
### 简单状态机设计
**要求：** 设计一个区别两种特定时序的有限状态机FSM：该有限状态机有一个输入w和一个输出z。当w是4个连续的0或4个连续的1时，输出z=1，否则z=0，时序允许重叠。即：若w是连续的5个1时，则在第4个和第5个时钟之后，z均为1。用SW0作为FSM低电平有效同步复位端，用SW1作为输入w，用KEY0作为手动的时钟输入，用LEDR0作为输出z，用LEDR4-LEDR7显示4个触发器的状态。
#### fsm.v
根据前面学习，我们了解到，一个有限状态机包含有一个起始状态、一个输入列表（列表中包含了所有可能的输入信号序列）、一个状态转移函数和一个输出端。因此我们将A = 4'b0000定为初始状态。输入列表则以当前状态sta为判断的依据，且明确得知有9种状态。同时要求使用手动时钟输入，这里我使用了前一节内容所使用的按钮输入来代替时钟输入。

```
module fsm(clk, w, z, reset, y, btn);
    input clk;      //时钟信号
    input w;        //输入信号
    input reset;    //复位信号
    input btn;      //按钮输入
    output reg z;   //输出信号
    output reg [3:0] y; //显示4个触发器状态

    //状态寄存器
    reg [3:0] sta, sta_next;        //当前状态和下一状态

    //按钮代替时钟信号的中间信号定义
    wire btn_clk;

    //状态编码
    parameter A = 4'b0000; // 初始状态
    parameter B = 4'b0001; 
    parameter C = 4'b0010; 
    parameter D = 4'b0011; 
    parameter E = 4'b0100; 
    parameter F = 4'b0101; 
    parameter G = 4'b0110; 
    parameter H = 4'b0111; 
    parameter I = 4'b1000;

    //输入信号寄存
    always @(posedge btn_clk or negedge reset) begin
        if(!reset) sta <= A;           //初始状态
        else sta <= sta_next;          //正常更新状态
    end

    //状态转移
    always @(*) begin
        //默认值
        sta_next = sta;    //默认保持当前状态
        z = 0;              //默认输出为0；

        case(sta)
            A: begin
                if(w) sta_next = B;     //输入为1,进入状态B
                else sta_next = E;      //输入为0,进入状态E
            end
            B: begin
                if(w) sta_next = C;     //连续输入2个1,进入状态C 
                else sta_next = A;      //输入为0，进入状态A
            end
            C: begin
                if(w) sta_next = D;     //连续输入3个1,进入状态D
                else sta_next = A;      //输入为0，进入状态A
            end
            D: begin
                if(w) begin
                    sta_next = I;        //连续输入4个1,进入状态I
                    z = 1'b1;            // 满足条件，输出1
                end else
                    sta_next = A;        //输入为0,进入状态A   
            end
            E: begin
                if(!w) sta_next = F;    //连续输入1个0,进入状态F
                else sta_next = A;      //输入为1,进入状态A
            end
            F: begin
                if(!w) sta_next = G;    //连续输入2个0,进入状态F
                else sta_next = A;      //输入为1,进入状态A
            end
            G: begin
                if(!w) sta_next = H;    //连续输入3个0,进入状态H
                else sta_next = A;      //输入为1,进入状态A
            end
            H: begin
                if(!w) begin
                    sta_next = I;       //连续输入4个0,进入状态I
                    z = 1'b1;           // 满足条件，输出1
                end else
                    sta_next = A;       //输入为1,进入状态A
            end
            I: begin
                if(w) sta_next = B;     //重叠检测：下一个周期为1
                else sta_next = E;      //重叠检测：下一个周期为0
                z = 1'b1;               // 在状态I，输出保持为1
            end
            default: sta_next = A;
        endcase
    end


    //按钮生成伪时钟信号
    button_clk u_btn_clk(
        .clk(clk),
        .btn(btn),
        .btn_clk(btn_clk)
    );

    //显示状态
    assign y = sta;
endmodule
```
#### button_clk.v:
```
module button_clk(clk,btn, btn_clk);
    input clk;                  //全局时钟信号，
    input btn;                  //按钮输入信号
    output reg btn_clk;         //按钮生成的伪时钟信号

    reg btn_sta1, btn_sta2; //同步寄存器
    reg btn_last;           //上一个状态

    //将按钮的输入信号btn同步到全局时钟clk的时钟域中，防止由于信号跨时钟域而引发亚稳态问题。
    always @(posedge clk) begin
            btn_sta1 <= btn;        //将按钮输入信号btn同步到寄存器btn_sta1
            btn_sta2 <= btn_sta1;   //将btn_sta1中的数据同步到btn_sta2中
    end

    //检测按钮的上升沿并生成单周期脉冲信号
    always @(posedge clk) begin
            //如果当btn_sta2为高电平且上一个状态btn_last为低电平则表示检测到按钮按下
            if(btn_sta2 && !btn_last) begin
                btn_clk <= 1;       //生成一个脉冲信号
            end else begin
                btn_clk <= 0;       //保证脉冲信号只有一个时钟周期
            end
            btn_last <= btn_sta2;   //更新按钮的上一个状态
        end
endmodule
```
### Listing 21 给的摩尔型状态机设计实例
#### 寄存器模板 SimReg.v
```
module SimReg #(
    parameter WIDTH = 4,        // 数据位宽
    parameter RESET_VALUE = 0   // 复位初始值
) (
    input clk,                  // 时钟信号
    input reset,                // 复位信号
    input [WIDTH-1:0] din,      // 数据输入
    output reg [WIDTH-1:0] dout, // 数据输出
    input wen                   // 写使能
);
    // 寄存器逻辑：在时钟上升沿或复位时操作
    always @(posedge clk or negedge reset) begin
        if (!reset)              // 低电平复位
            dout <= RESET_VALUE; // 复位时输出为初始值
        else if (wen) 
            dout <= din;         // 写使能为高时更新寄存器值
    end
endmodule

```
#### 有限状态机 fsm_bin.v
这个部分我添加了注释，方便我自己阅读，同时也能捋清楚各个部分代码的含义。  
```
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
```
#### 顶层模块 top.v
```
module top(
    input clk,
    input reset,
    input in,
    input btn,
    output reg out,
    output reg [3:0] sta
);
    //按钮代替时钟信号的中间信号定义
    wire btn_clk;

    //按钮生成伪时钟信号
    button_clk u_btn_clk(
        .clk(clk),
        .btn(btn),
        .btn_clk(btn_clk)
    );

    //实例化fsm_bin
    fsm_bin u_fsm_bin(
        .clk(btn_clk),
        .reset(reset),
        .in(in),
        .out(out),
        .sta(sta)
    );


endmodule
```
### 摩尔型与米里型的区别
Moore（摩尔）型有限状态机和Mealy（米里）型有限状态机。Moore 型有限状态机的输出信号只与有限状态机的当前状态有关，与输入信号的当前值无关，输入信号的当前值只会影响到状态机的次态，不会影响状态机当前的输出。即Moore 型有限状态机的输出信号是直接由状态寄存器译码得到。 Moore型有限状态机在时钟CLK信号有效后经过一段时间的延迟，输出达到稳定值。即使在这个时钟周期内输入信号发生变化，输出也会在这个完整的时钟周期内保持稳定值而不变。输入对输出的影响要到下一个时钟周期才能反映出来。Moore有限状态机最重要的特点就是将输入与输出信号隔离开来。Mealy 状态机与Moore有限状态机不同，Mealy有限状态机的输出不仅仅与状态机的当前状态有关，而且与输入信号的当前值也有关。Mealy有限状态机的输出直接受输入信号的当前值影响，而输入信号可能在一个时钟周期内任意时刻变化，这使得Mealy有限状态机对输入的响应发生在当前时钟周期，比Moore有限状态机对输入信号的响应要早一个周期。因此，输入信号的噪声可能影响到输出的信号。  
**摩尔型更适合：** 时序逻辑同步要求高的系统，输入变化较频繁，输出需要稳定的系统。  
**米里型更适合：** 响应速度要求高的系统。输出需要快速对输入变化作出反应的场景。  

### 根据之前实验要求，尝试写一个米里型状态机
#### fsm_mealy.v
```
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
```
#### 实验现象描述
当我复位信号reset为1时，无论当前状态如何，输入如何，状态机都被复位到了初始状态S0。
当reset为0时，我的输出out与我的输入in的变化有即时响应。这里就体验了米里型与之前摩尔型的不同之处。
