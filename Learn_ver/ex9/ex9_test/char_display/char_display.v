module char_display(
    input clk,                  // 时钟信号
    input clrn,                 // 复位信号
    input [7:0] ascii,          // 输入的ascii码，选择需要显示的字符
    input [9:0] x,              // 显示字符的横坐标
    input [9:0] y,              // 显示字符的纵坐标
    output reg [23:0] vga_data  // vga输出数据，rgb的颜色值
);

    // 字符点阵（暂时只支持 ABCD 四个字符）
    // 每个字符由7x7的点阵表示
    reg [6:0] font_A [0:6];
    reg [6:0] font_B [0:6];
    reg [6:0] font_C [0:6];
    reg [6:0] font_D [0:6];

    // 当前的字符点阵，大小为7x7
    reg [6:0] current_font [0:6];

    // 使用initial块初始化字符点阵
    initial begin
        font_A[0] = 7'b0001110; 
        font_A[1] = 7'b0010001; 
        font_A[2] = 7'b0011111;
        font_A[3] = 7'b0010001; 
        font_A[4] = 7'b0010001; 
        font_A[5] = 7'b0000000;
        font_A[6] = 7'b0000000;

        font_B[0] = 7'b0011110; 
        font_B[1] = 7'b0010001; 
        font_B[2] = 7'b0011110;
        font_B[3] = 7'b0010001; 
        font_B[4] = 7'b0011110; 
        font_B[5] = 7'b0000000;
        font_B[6] = 7'b0000000;

        font_C[0] = 7'b0001111; 
        font_C[1] = 7'b0010000; 
        font_C[2] = 7'b0010000;
        font_C[3] = 7'b0010000; 
        font_C[4] = 7'b0001111; 
        font_C[5] = 7'b0000000;
        font_C[6] = 7'b0000000;

        font_D[0] = 7'b0011110; 
        font_D[1] = 7'b0010001; 
        font_D[2] = 7'b0010001;
        font_D[3] = 7'b0010001; 
        font_D[4] = 7'b0011110; 
        font_D[5] = 7'b0000000;
        font_D[6] = 7'b0000000;
    end

    // 根据输入的ascii码，选择相应的点阵
    always @(*) begin
        case (ascii)
            8'h41: begin
                current_font[0] = font_A[0];
                current_font[1] = font_A[1];
                current_font[2] = font_A[2];
                current_font[3] = font_A[3];
                current_font[4] = font_A[4];
                current_font[5] = font_A[5];
                current_font[6] = font_A[6];
            end
            8'h42: begin
                current_font[0] = font_B[0];
                current_font[1] = font_B[1];
                current_font[2] = font_B[2];
                current_font[3] = font_B[3];
                current_font[4] = font_B[4];
                current_font[5] = font_B[5];
                current_font[6] = font_B[6];
            end
            8'h43: begin
                current_font[0] = font_C[0];
                current_font[1] = font_C[1];
                current_font[2] = font_C[2];
                current_font[3] = font_C[3];
                current_font[4] = font_C[4];
                current_font[5] = font_C[5];
                current_font[6] = font_C[6];
            end
            8'h44: begin
                current_font[0] = font_D[0];
                current_font[1] = font_D[1];
                current_font[2] = font_D[2];
                current_font[3] = font_D[3];
                current_font[4] = font_D[4];
                current_font[5] = font_D[5];
                current_font[6] = font_D[6];
            end
            default: begin
                current_font[0] = 7'b0000000;
                current_font[1] = 7'b0000000;
                current_font[2] = 7'b0000000;
                current_font[3] = 7'b0000000;
                current_font[4] = 7'b0000000;
                current_font[5] = 7'b0000000;
                current_font[6] = 7'b0000000;
            end
        endcase
    end

    // 根据坐标和点阵值，生成vga输出数据
    always @(*) begin
        // 如果y小于7且当前点阵中该位置为1，则点亮该位置
        if (x < 7 && y < 7 && current_font[y][x]) 
            vga_data = 24'hFFFFFF;  // 点亮该位置（白色）
        else
            vga_data = 24'h000000;  // 否则黑色
    end

endmodule
