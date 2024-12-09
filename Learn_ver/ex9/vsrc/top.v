module top (
    input clk,                // 时钟信号
    input clrn,              // 复位信号
    input ps2_clk,            // PS/2 时钟
    input ps2_data,           // PS/2 数据
    output hsync,             // VGA 水平同步信号
    output vsync,             // VGA 垂直同步信号
    output [7:0] vga_r,      // VGA 红色信号
    output [7:0] vga_g,      // VGA 绿色信号
    output [7:0] vga_b       // VGA 蓝色信号
);

    wire [7:0] ascii_data;          // ASCII字符数据
    wire [7:0] ascii_distinguish;   // PS/2 键盘扫描码转换后的 ASCII 字符数据
    wire key_release;               // 按键松开标志
    wire [23:0] vga_data;           // VGA输出数据
    wire ready;                     // 按键数据准备好标志
    wire overflow_signal;

    // PS/2 键盘模块，用于获取按键的扫描码
    ps2_keyboard ps2_kb (
        .clk(clk),
        .clrn(clrn),
        .ps2_clk(ps2_clk),
        .ps2_data(ps2_data),
        .data(ascii_data),
        .ready(ready),
        .overflow(overflow_signal),
        .nextdata_n()
    );

    // PS/2 键盘扫描码转换为 ASCII 字符
    ps2_distinguish ps2_dist (
        .clk(clk),
        .clrn(clrn),
        .i_data(ascii_data),
        .ascii(ascii_distinguish),
        .key_release(key_release)
    );

    // VGA 控制模块，负责生成 VGA 信号
    vga_ctrl u_vga_ctrl (
        .pclk(clk),
        .reset(clrn),
        .vga_data(vga_data),  // 从显示模块获取字符数据
        .h_addr(),
        .v_addr(),
        .hsync(hsync),
        .vsync(vsync),
        .valid(),
        .vga_r(vga_r),
        .vga_g(vga_g),
        .vga_b(vga_b)
    );

    // 字符显示
    char_display char_display_inst (
        .clk(clk),
        .clrn(clrn),
        .ascii(ascii_distinguish),
        .x(x),        // 字符横坐标
        .y(y),        // 字符纵坐标
        .vga_data(vga_data)
    );

    // 输入缓冲与显示逻辑
    reg [7:0] input_buffer [0:15]; // 输入字符缓冲区，最多支持16个字符
    reg [3:0] char_count = 0;      // 当前输入字符计数器
    reg [9:0] x;                   // 字符横坐标
    reg [9:0] y;                   // 字符纵坐标

    always @(posedge clk or negedge clrn) begin
        if (~clrn) begin
            char_count <= 0;
            x <= 0;
            y <= 0;
        end else if (ready && !key_release) begin
            if (ascii_data == 8'h0D) begin // 回车键
                char_count <= 0;  // 换行
                x <= 0;
                y <= y + 8; // 换行，纵坐标加 8
            end else begin
                input_buffer[char_count] <= ascii_data;
                // 计算横坐标和纵坐标
                x <= (char_count[9:0] % 80) * 8;
                y <= (char_count[9:0] / 80) * 8;
                char_count <= char_count + 1;
            end
        end
    end

endmodule

