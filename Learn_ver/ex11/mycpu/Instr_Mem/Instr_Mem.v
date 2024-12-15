module Instr_Mem(
    input Rdclk,            //读取时钟
    input [31:0] Rdaddr,    //读取地址
    output reg [31:0] Instr     //输出指令
);

    //参数定义
    parameter MEM_DEPTH = 1; //指令存储器的深度
    parameter MEM_WIDTH = 32;  //每条指令的宽度

    //指令存储器阵列
    reg [MEM_WIDTH-1:0] mem_array [0:MEM_DEPTH-1];

    //初始化存储器，从外部文件加载指令数据
    // initial begin
    //     $readmemh("instr_mem.hex", mem_array);  //从文件中加载指令
    // end

     initial begin
        mem_array[0] = 32'h00230293;
    end


    always @(negedge Rdclk) begin
        Instr <= mem_array[Rdaddr[31:2]];
    end

endmodule