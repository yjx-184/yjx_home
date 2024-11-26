module v_rams_8(clk, we, inaddr, outaddr, din, dout0, dout1, dout2);
    input clk;                          //时钟信号，用于控制RAM的操作
    input we;                           //写使能信号
    input [2:0] inaddr;                 //写地址信号，指定要写入的数据的存储位值
    input [2:0] outaddr;                //读地址信号，指定要读取的数据的
    input [7:0] din;                    //数据输入信号，表示要写入存储器的数据，8位宽
    output reg [7:0] dout0, dout1,dout2;//存储器输出端口

    reg [7:0] ram [7:0];    //定义一个8x8的存储阵列，包含8个8位存储单元

    //初始内容赋值
    initial
    begin
        ram[7] = 8'hf0; ram[6] = 8'h23; ram[5] = 8'h20; ram[4] = 8'h50;
        ram[3] = 8'h03; ram[2] = 8'h21; ram[1] = 8'h82; ram[0] = 8'h0D;
    end

    //同步写，读操作
    always @(posedge clk) begin     //时钟上升沿触发
        if(we)                      //当写使能信号we为高时，执行写操作
            ram[inaddr] <= din;     //将输入数据din写入地址为inaddr的存储单元。
        else                        //当we被低时，执行读操作
            dout0 <= ram[outaddr];  //将地址outaddr的存储单元内容赋值给输出dout0
    end

    //异步读操作
    always @(negedge clk) begin     //时钟下降沿触发
        if(!we)                     //当写使能信号we为低时，执行读操作
            dout1 <= ram[outaddr];  //将地址outaddr的存储单元内容赋值给输出dout1
    end
    assign dout2 <= ram[outaddr];   //组合逻辑输出，实时反映存储单元的内容
endmodule