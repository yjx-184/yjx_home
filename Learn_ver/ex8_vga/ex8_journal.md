

# 实验八：VGA接口控制器实验
## 验收实验
先前有阅读过nvboard的代码，就直接使用了提供的图片picture.hex
```
module vga_top(
    input clk,           // 时钟信号
    input rst,           // 复位信号
    output hsync,        // 行同步信号
    output vsync,        // 列同步信号
    output valid,
    output [7:0] vga_r,
    output [7:0] vga_g,
    output [7:0] vga_b
);

    // 信号定义
    wire [9:0] h_addr;    // 水平地址
    wire [9:0] v_addr;    // 垂直地址
    wire [23:0] vga_data; // 当前像素的24位RGB数据

    // VGA 控制模块实例
    vga_ctrl u_vga_ctrl (
        .pclk(clk),      // 使用时钟生成器输出的时钟
        .reset(rst),        // 复位信号
        .vga_data(vga_data), // VGA 数据
        .h_addr(h_addr),    // 水平地址输出
        .v_addr(v_addr),    // 垂直地址输出
        .hsync(hsync),      // 行同步信号
        .vsync(vsync),      // 列同步信号
        .valid(valid),      // 有效像素信号
        .vga_r(vga_r),      // VGA 红色通道
        .vga_g(vga_g),      // VGA 绿色通道
        .vga_b(vga_b)       // VGA 蓝色通道
    );
    

    //视频显示模块
    vmem my_vmem(
        .h_addr(h_addr),
        .v_addr(v_addr[8:0]),
        .vga_data(vga_data)
    );

endmodule

module vmem(
    input [9:0] h_addr,
    input [8:0] v_addr,
    output [23:0] vga_data
);

reg [23:0] vga_mem [524287:0];//524288个24位像素数据（640x512 = 327680）

initial begin
    $readmemh("vsrc/picture.hex", vga_mem);
end

//将水平方向和垂直方向的地址拼接成一个19位的地址
assign vga_data = vga_mem[{h_addr, v_addr}];

endmodule

```
