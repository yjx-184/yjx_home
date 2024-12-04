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