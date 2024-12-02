module ps2_keyboard(clk, clrn, ps2_clk, ps2_data, data, ready, nextdata_n, overflow);
    input clk, clrn;            //时钟信号，复位信号(低电平有效)
    input ps2_clk, ps2_data;    //ps2时钟信号，ps2数据线信号
    input nextdata_n;           //控制信号，表示是否需要读取下一个数据
    output [7:0] data;          //从fifo中读取8位数据，表示键盘扫描码
    output reg ready;           //指示fifo种有新数据可供读取的标志位
    output reg overflow;        //fifo溢出标志

    //内部信号
    reg [9:0] buffer;           //存储ps2数据位，包括起始位，数据位，奇偶校验位和停止位
    reg [7:0] fifo[7:0];        //8位fifo，缓存ps2键盘接受到的数据
    reg [2:0] w_ptr, r_ptr;     //fifo的写指针和读指针
    reg [3:0] count;            //计数器
    reg [2:0] ps2_clk_sync;     //同步ps2时钟信号，避免时序问题

    //检测ps/2时钟信号的下降沿
    always @(posedge clk) begin
        //将ps/2时钟信号同步到系统时钟clk，避免由于时序不匹配产生错误。
        ps2_clk_sync <= {ps2_clk_sync[1:0],ps2_clk};
    end

    //sampling表示ps/2时钟信号的下降沿，用于触发数据采样。
    //ps2_clk_sync[2]和ps2_clk_sync[1]表示当前和上一时钟周期的ps/2时钟信号，有变化说明出现下降沿。
    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    always @(posedge clk) begin
        if (clrn == 0) begin    //复位信号
            count <= 0;
            w_ptr <= 0;
            r_ptr <= 0;
            overflow <= 0;
            ready <= 0;
        end else begin          //fifo数据读取和控制
            if(ready) begin     //如果fifo中有数据，则准备读取
                if(nextdata_n == 1'b0) begin    //需要读取下一个数据
                    r_ptr <= r_ptr + 3'b1;      //读指针自增
                    if(w_ptr == (r_ptr + 1'b1)) //如果fifo为空（w_ptr+1'b1 == r_ptr则表示为满）
                        ready <= 1'b0;          //ready为0表示无数据可读
                end
            end
            //数据采样和处理
            if(sampling) begin                  //检测到ps/2时钟信号下降沿，开始采样
                if(count == 4'd10) begin        //接收到了一组完整的数据
                    if((buffer[0] == 0) &&      //校验起始位为0
                        (ps2_data)      &&      //校验停止位位1
                        (^buffer[9:1])) begin   //校验奇偶，为奇数
                            fifo[w_ptr] <= buffer[8:1]; //存储有效数据到fifo
                            w_ptr <= w_ptr + 3'b1;      //更新写指针，自增
                            ready <= 1'b1;              //ready为1表示可读
                            //检测fifo是否溢出
                            overflow <= overflow | (r_ptr == (w_ptr +3'b1));
                        end
                        count <= 0; //重置计数器，准备接收下一组数据
                end else begin
                    buffer[count] <= ps2_data;  //存储当前采样的数据位
                    count <= count + 3'b1;      //计数器自增
                end
            end
        end
    end

    assign data = fifo[r_ptr];  //将fifo读取的数据赋值给data输出

endmodule