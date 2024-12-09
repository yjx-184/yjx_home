module ram_mem(
    input [31:0] rs1,                   //rs1寄存器，用于地址计算
    input [31:0] rs2,                   //rs2寄存器，用于存储操作
    input [31:0] imm12,                 //立即数
    input [3:0] MemOP,                  //内存操作类型
    input [31:0] memory_data_in,        //存储器写入数据
    output reg [31:0] result,           //存储操作的结果或加载操作的结果
    output reg [31:0] memory_data_out,  //内存读取数据
    output reg memory_write,            //内存写使能信号
    output reg [3:0] byte_we            //内存字节写使能信号（用于存储）
    );

    wire [31:0] address;                //计算出来的内存地址
    reg [7:0] byte_data;                //用于字节操作
    reg [15:0] halfword_data;           //用于半字操作
    reg [31:0] word_data;               //用于字操作


    //计算内存地址
    assign address = rs1 + imm12;

    //根据MemOP执行不同的内存访问操作
    always @(*) begin
        memory_write = 0;
        byte_we = 4'b0000;

        case(MemOP)
            4'b0000: begin     //sb
                memory_write = 1;       //启用内存写
                byte_we = 4'b0001;      //仅写入最低8位
                result = 32'b0;         //无需输出结果
            end
            
            4'b0001: begin      //sh
                memory_write = 1;       //启用内存写
                byte_we = 4'b0011;      //仅写入低16位
                result = 32'b0;         //无需输出结果
            end

            4'b0010: begin      //sw
                memory_write = 1;       //启用内存写
                byte_we = 4'b1111;      //写入整个字
                result = 32'b0;         //无需输出结果
            end

            4'b0100: begin      //lb
                memory_write = 0;
                byte_data = memory_data_in[7:0]; // 提取最低 8 位
                result = {{24{byte_data[7]}}, byte_data}; // 符号扩展
                memory_data_out = result;
            end 

            4'b0101: begin      //lh
                memory_write = 0;              //禁用内存写
                halfword_data = memory_data_in[15:0];   //从内存中读取半字数据
                result = {{16{halfword_data[15]}}, halfword_data};  //符号扩展
                memory_data_out = result;      //输出结果
            end

            4'b0110: begin      //lw
                memory_write = 0;              //禁用内存写
                word_data = memory_data_in;    //从内存中读取字数据
                result = word_data;            //无符号扩展
                memory_data_out = result;      // 出结果
            end

            4'b0111: begin      //bu
                memory_write = 0;                   //禁用内存写
                byte_data = memory_data_in[7:0];    //从内存中读取字节数据
                result = {24'b0, byte_data};        //无符号扩展
                memory_data_out = result;           //输出结果
            end

            4'b1000: begin      //lhu
                memory_write = 0;                       //禁用内存写
                halfword_data = memory_data_in[15:0];   //从内存中读取半字数据
                result = {16'b0, halfword_data};        //无符号扩展
                memory_data_out = result;               //输出结果
            end

            default: begin
                memory_write = 0;
                byte_we = 4'b0000;
                result = 32'b0;
                memory_data_out = 32'b0;
            end

        endcase
    end

endmodule