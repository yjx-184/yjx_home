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