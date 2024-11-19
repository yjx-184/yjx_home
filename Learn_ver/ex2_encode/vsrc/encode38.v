module encode38(x, en, y, seg_out, x_mark);
    input [7:0] x;          //8位二进制输入
    input en;               //使能信号
    output reg [2:0] y;     //3位二进制输出
    output [7:0] seg_out;   //7段数码管的输出
    output reg x_mark;          //输入指示位，判断是否有输入
    integer i;

    always @(x or en) begin
        if(en) begin
            y = 0;
            x_mark = 1'b1;
            for(i = 0; i <= 7; i = i+1)
                if(x[i] == 1) y = i[2:0];    
        end
        else begin
            y = 0;
            x_mark = 1'b0;
        end
    end

    seg7 seg7_encode38(
        .seg_in(y),
        .seg_out(seg_out)
    );
endmodule