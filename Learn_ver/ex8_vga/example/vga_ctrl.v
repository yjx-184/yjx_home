module vga_ctrl(
    input pclk,             //25MHz时钟
    input reset,            //复位信号
    input [23:0] vga_data,  //上层模块提供的VGA颜色数据
    output [9:0] h_addr,    //提供给上层模块的当前扫描像素坐标
    output [9:0] v_addr,
    output hsync,           //行同步和列同步信号
    output vsync,
    output valid,           //消隐信号
    output [7:0] vga_r,
    output [7:0] vga_g,
    output [7:0] vga_b
);

    //640x480分辨率下的VGA参数设置
    parameter h_frontporch = 96;            //行前沿
    parameter h_active = 144;               //行有效区域起始位置
    parameter h_backporch = 784;            //行后沿
    parameter h_total = 800;                //行总周期

    parameter v_frontporch = 2;             //列前沿
    parameter v_active = 35;                //列有效区域起始位置
    parameter v_backporch = 515;            //列后沿
    parameter v_total = 525;                //列总周期

    //像素计算
    reg [9:0] x_cnt;
    reg [9:0] y_cnt;
    wire h_valid;
    wire v_valid;

    //行像素计数
    always @(posedge pclk or posedge reset) 
        if(reset == 1'b1)
            x_cnt <= 1;
        else begin
            if(x_cnt == h_total)            //当计数达到总行周期时重新计数
                x_cnt <= 1;
            else
                x_cnt <= x_cnt + 10'd1;     //否则正常加
        end 

    //列像素计数
    always @(posedge pclk)
        if(reset == 1'b1)               
            y_cnt <= 1;
        else begin
            if(y_cnt == v_total & x_cnt == h_total) //行列都满时换行
                y_cnt <= 1;
            else if(x_cnt == h_total)       //每当行计数满时，列计数加一
                y_cnt <= y_cnt + 10'd1;
        end

        //生成同步信号
        assign hsync = (x_cnt > h_frontporch);
        assign vsync = (y_cnt > v_frontporch);

        //生成消隐信号
        assign h_valid = (x_cnt > h_active) & (x_cnt <= h_backporch);
        assign v_valid = (y_cnt > v_active) & (y_cnt <= v_backporch);
        assign valid = h_valid & v_valid;

        //计算当前有效像素坐标
        assign h_addr = h_valid ? (x_cnt - 10'd145) : {10{1'b0}};
        assign v_addr = v_valid ? (y_cnt - 10'd36) : {10{1'b0}};

        //设置输出的颜色值
        assign vga_r = vga_data[23:16];
        assign vga_g = vga_data[15:8];
        assign vga_b = vga_data[7:0];

endmodule