- [实验七 状态机及键盘输入](#实验七-状态机及键盘输入)
  - [状态机](#状态机)
    - [简单状态机设计](#简单状态机设计)
      - [fsm.v](#fsmv)
      - [button\_clk.v:](#button_clkv)
    - [Listing 21 给的摩尔型状态机设计实例](#listing-21-给的摩尔型状态机设计实例)
      - [寄存器模板 SimReg.v](#寄存器模板-simregv)
      - [有限状态机 fsm\_bin.v](#有限状态机-fsm_binv)
      - [顶层模块 top.v](#顶层模块-topv)
    - [摩尔型与米里型的区别](#摩尔型与米里型的区别)
    - [根据之前实验要求，尝试写一个米里型状态机](#根据之前实验要求尝试写一个米里型状态机)
      - [fsm\_mealy.v](#fsm_mealyv)
      - [实验现象描述](#实验现象描述)
  - [验收实验](#验收实验)
    - [实验步骤1：调用ps2\_keyboard.v模块](#实验步骤1调用ps2_keyboardv模块)
    - [实验步骤2：接收数据后，进行识别是什么按键ps2\_distinguish.v](#实验步骤2接收数据后进行识别是什么按键ps2_distinguishv)
    - [实验步骤3：计数器](#实验步骤3计数器)
    - [复用数码管模块seg\_h.v(添加了使能en，控制是否全灭)](#复用数码管模块seg_hv添加了使能en控制是否全灭)
    - [顶层模块实现 ps2\_top.v](#顶层模块实现-ps2_topv)
    - [实验过程遇到的问题](#实验过程遇到的问题)
      - [计数时，记录按下的同时也把松开记录了](#计数时记录按下的同时也把松开记录了)
      - [实现数码管低4位全灭时，实验结果不是预期的结果](#实现数码管低4位全灭时实验结果不是预期的结果)


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

## 验收实验
### 实验步骤1：调用ps2_keyboard.v模块
如讲义所说，这个部分只负责接收键盘送来的数据。为后续识别做准备。
### 实验步骤2：接收数据后，进行识别是什么按键ps2_distinguish.v
接收来自ps2_keyboard.v的扫描码，根据lut表进行映射。同时处理松开事件,但由于后面添加了“松开时，低四位全灭”，所以现在看不到松开时显示F0。
```
module ps2_distinguish(clk, clrn, i_data, ascii, key_release);
    input clk;              //时钟信号
    input clrn;             //复位信号
    input [7:0] i_data;     //从ps/2传来的扫描码
    output reg [7:0] ascii; //输出对应的ascii字符
    output reg key_release; //标记是否有按键松开时间

    //松开键盘
    parameter KEY_RELEASE_CODE = 8'hF0;

    //查找表LUT：每个键的扫描码对应ASCII码
    //暂时定义26个字母，10个数字
    wire [575:0] lut = {
        //10个数字
        8'h45, 8'h30,  //0
        8'h16, 8'h31,  //1
        8'h1E, 8'h32,  //2
        8'h26, 8'h33,  //3
        8'h25, 8'h34,  //4
        8'h2E, 8'h35,  //5
        8'h36, 8'h36,  //6
        8'h3D, 8'h37,  //7
        8'h3E, 8'h38,  //8
        8'h46, 8'h39,  //9

        //26个字母
        8'h1C, 8'h41,  //A
        8'h32, 8'h42,  //B
        8'h21, 8'h43,  //C
        8'h23, 8'h44,  //D
        8'h24, 8'h45,  //E
        8'h2B, 8'h46,  //F
        8'h34, 8'h47,  //G
        8'h33, 8'h48,  //H
        8'h43, 8'h49,  //I
        8'h3B, 8'h4A,  //J
        8'h42, 8'h4B,  //K
        8'h4B, 8'h4C,  //L
        8'h3A, 8'h4D,  //M
        8'h31, 8'h4E,  //N
        8'h44, 8'h4F,  //O
        8'h4D, 8'h50,  //P
        8'h15, 8'h51,  //Q
        8'h2D, 8'h52,  //R
        8'h1B, 8'h53,  //S
        8'h2C, 8'h54,  //T
        8'h3C, 8'h55,  //U
        8'h2A, 8'h56,  //V
        8'h6B, 8'h57,  //W
        8'h1A, 8'h58,  //X
        8'h22, 8'h59,  //Y
        8'h14, 8'h5A   //Z
    };

    //显示映射结果
    wire [7:0] ascii_result;

    MuxKeyWithDefault #(
        .NR_KEY(36),        // 36个键
        .KEY_LEN(8),        // 键值长度为 8 位（对应扫描码）
        .DATA_LEN(8)        // 输出字符长度为 8 位（ASCII 字符）
    ) key_ascii (
        .out(ascii_result), //映射结果
        .key(i_data),         // 输入扫描码
        .default_out(8'h00),// 默认输出 null
        .lut(lut)           // 查找表（键码到字符的映射）
    );

    // 处理按键松开事件
    always @(posedge clk or negedge clrn) begin
        if (clrn == 0) begin
            ascii <= 8'h00;     //复位
            key_release <= 0;   //清除松开标记
        end else if (i_data == KEY_RELEASE_CODE) begin
            ascii <= 8'h00;  // 如果是松开事件，扫描码为F0，则清除ASCII
            key_release <= 1;
        end else begin
            ascii <= ascii_result; // 更新ASCII字符
            key_release <= 0;  // 标记为按键没有松开
        end
    end

endmodule
```
### 实验步骤3：计数器
将计数器模块化，方便日后复用。同时对实验4的计数器进行了优化。
```
module ps2_counter(
    input clk,                  //时钟信号
    input clrn,                 //复位信号
    input key_press,            //按下标志
    input key_release,          //松开标志
    output reg [3:0] units,     // 个位
    output reg [3:0] tens       // 十位
);

    // 记录是否已经被计数
    reg counted;

    always @(posedge clk or negedge clrn) begin
        if (clrn == 1'b0) begin                 //复位信号
            units <= 4'b0;                      //将个位重置
            tens <= 4'b0;                       //将十位重置
            counted <= 1'b0;                    //将计数标志重置
        end else begin
            if (key_press && !counted) begin    //检查按键按下且未被计数
                counted <= 1'b1;                //标记已经被计数
                if (units == 4'd9) begin        
                    units <= 4'd0;              //当个位到达9重置为0
                    if (tens == 4'd9) begin
                        tens <= 4'd0;           // 超过99次归0
                    end else begin
                        tens <= tens + 1;
                    end
                end else begin
                    units <= units + 1;
                end
            end 
            else if (key_release) begin
                // 按键释放时，标记为未计数
                counted <= 1'b0;
            end
        end
    end

endmodule
```
### 复用数码管模块seg_h.v(添加了使能en，控制是否全灭)
```
module seg_h(seg_in,seg_out, en);
    input [3:0] seg_in;
    input en;
    output reg [7:0] seg_out;

    // 定义16进制字符
    parameter seg0  = 8'b11111100; // 显示 0
    parameter seg1  = 8'b01100000; // 显示 1
    parameter seg2  = 8'b11011010; // 显示 2
    parameter seg3  = 8'b11110010; // 显示 3
    parameter seg4  = 8'b01100110; // 显示 4
    parameter seg5  = 8'b10110110; // 显示 5
    parameter seg6  = 8'b10111110; // 显示 6
    parameter seg7  = 8'b11100000; // 显示 7
    parameter seg8  = 8'b11111110; // 显示 8
    parameter seg9  = 8'b11110110; // 显示 9
    parameter segA  = 8'b11101110; // 显示 A
    parameter segB  = 8'b00111110; // 显示 B
    parameter segC  = 8'b10011100; // 显示 C
    parameter segD  = 8'b01111010; // 显示 D
    parameter segE  = 8'b10011110; // 显示 E
    parameter segF  = 8'b10001110; // 显示 F

    always @(seg_in or en) begin
        if(en == 1'b0) begin
            seg_out = 8'b11111111; // 全灭
        end else begin
            case(seg_in)
                4'd0:  seg_out = ~seg0;
                4'd1:  seg_out = ~seg1;
                4'd2:  seg_out = ~seg2;
                4'd3:  seg_out = ~seg3;
                4'd4:  seg_out = ~seg4;
                4'd5:  seg_out = ~seg5;
                4'd6:  seg_out = ~seg6;
                4'd7:  seg_out = ~seg7;
                4'd8:  seg_out = ~seg8;
                4'd9:  seg_out = ~seg9;
                4'd10: seg_out = ~segA;  // A
                4'd11: seg_out = ~segB;  // B
                4'd12: seg_out = ~segC;  // C
                4'd13: seg_out = ~segD;  // D
                4'd14: seg_out = ~segE;  // E
                4'd15: seg_out = ~segF;  // F
                default: seg_out = 8'b11111111; // 全灭
            endcase
        end
    end

endmodule
```
### 顶层模块实现 ps2_top.v
**延时寄存器的作用：** ready_d1和ready_d2是用来延迟ready信号的寄存器。它们保存了前一个时钟周期的ready状态ready_d1记录了当前周期的ready状态，而ready_d2记录了前一个周期的ready状态。目的是为了避免亚稳态的产生。
```
module ps2_top(
    input clk,                          //时钟信号
    input clrn,                         //复位信号
    input ps2_clk,                      //ps/2的时钟信号
    input ps2_data,                     //ps/2的数据线信号
    output reg [7:0] seg_out_0,         //扫描码的低8位
    output reg [7:0] seg_out_1,         //扫描码的高8位
    output reg [7:0] seg_out_2,         //ascii的低8位
    output reg [7:0] seg_out_3,         //ascii的高8位
    output reg [7:0] seg_out_4,         //按键计数的个位
    output reg [7:0] seg_out_5,         //按键计数的十位
    output overflow                     //fifo溢出标志
);

    //内部信号
    wire [7:0] data;                    //ps/2接收到的数据
    wire ready;                         //数据准备好标志
    reg ready_p1, ready_p2;             //上升沿和下降沿准备信号
    reg ready_d1, ready_d2;             //延迟信号
    reg nextdata_n;                     //控制信号
    reg [7:0] data_d1;                  //数据寄存器
    wire key_press;                     //按钮按下标志
    wire key_release;                   //按钮松开标志
    reg [7:0] ascii;                    //输出ascii
    wire [3:0] high_tens;               //总按键次数的十位
    wire [3:0] high_units;              //总按键次数的个位
    reg [7:0] key_scan_code;            //当前按键扫描码
    reg [7:0] key_scan_display;         //显示的扫描码值
    reg [7:0] key_ascii_display;        //显示的 ASCII 值
    reg en;                             //数码管使能


    //实例化
    //PS2键盘模块，负责接收并处理 PS/2 键盘信号
    ps2_keyboard u0_ps2_kb (
        .clk(clk), 
        .clrn(clrn), 
        .ps2_clk(ps2_clk), 
        .ps2_data(ps2_data), 
        .data(data),                            
        .ready(ready),                         
        .nextdata_n(nextdata_n),                
        .overflow(overflow)                    
    );
    

    //扫描码映射到ascii模块
    ps2_distinguish u1_ps2_dsh(
        .clk(clk),
        .clrn(clrn),
        .i_data(data_d1),                      
        .ascii(ascii),                      
        .key_release(key_release)     
    );

    //计数模块
    ps2_counter u2_ps2_cer(
        .clk(clk),
        .clrn(clrn),
        .key_press(ready_p1 && !key_release),
        .key_release(key_release),
        .units(high_units),
        .tens(high_tens)
    );

    //显示数码管控制模块
    seg_h u3_seg_h_0 (
        .seg_in(key_ascii_display[3:0]),
        .seg_out(seg_out_2),
        .en(en)
    );

    seg_h u4_seg_h_1 (
        .seg_in(key_ascii_display[7:4]),
        .seg_out(seg_out_3),
        .en(en)
    );

    seg_h u5_seg_h_2 (
        .seg_in(key_scan_display[3:0]),
        .seg_out(seg_out_0),
        .en(en)
    );
    
    seg_h u6_seg_h_3 (
        .seg_in(key_scan_display[7:4]),
        .seg_out(seg_out_1),
        .en(en)
    );

    seg_h u7_seg_h_4 (
        .seg_in(high_units),
        .seg_out(seg_out_4),
        .en(1'b1)
    );

    seg_h u8_seg_h_5 (
        .seg_in(high_tens),
        .seg_out(seg_out_5),
        .en(1'b1)
    );

    // 产生准备信号的上升沿和下降沿
    always @(posedge clk or negedge clrn) begin
        if (clrn == 1'b0) begin
            ready_d1 <= 0;          
            ready_d2 <= 0;
        end else begin
            ready_d1 <= ready;
            ready_d2 <= ready_d1;
        end
    end

    assign ready_p1 = ready & ~ready_d1; // 上升沿
    assign ready_p2 = ready_d1 & ~ready_d2; // 下降沿

    // 数据处理逻辑
    always @(posedge clk or negedge clrn) begin
        if (clrn ==  1'b0) begin
            data_d1 <= 0;
            key_scan_display <= 0;
            key_ascii_display <= 0;
            en <= 0;
            nextdata_n <= 1;
        end else begin
            if (ready_p1) begin
                data_d1 <= data;
                key_scan_display <= data;       //显示扫描码
                key_ascii_display <= ascii;     //显示 ASCII
                en <= 1;                        //使能显示
                nextdata_n <= 0;                //读取下一个数据
            end else if (key_release) begin
                en <= 0;                        // 禁用显示
            end else begin
                nextdata_n <= 1;                // 不读取新数据
            end
        end
    end
endmodule
```
### 实验过程遇到的问题
#### 计数时，记录按下的同时也把松开记录了
**解决过程：** 根据实验的结果显示，判断产生错误的地方是在计数器模块，对按下信号进行了加强检测。在对ps2_top.v 61行中 .key_press(ready_p1) 更新为.key_press(ready_p1 && !key_release)后，问题得到了解决。
#### 实现数码管低4位全灭时，实验结果不是预期的结果
**解决过程：** 在seg_h.v模块中添加了使能信号en，并且在ps2_top.v中 数据逻辑处理部分,让使能信号en与上升沿信号相关。