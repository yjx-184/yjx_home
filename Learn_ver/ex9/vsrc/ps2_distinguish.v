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