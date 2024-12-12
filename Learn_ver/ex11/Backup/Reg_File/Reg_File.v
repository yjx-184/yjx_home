module Reg_File(
    input [4:0] Ra,             //读地址，对应risc-v rs1
    input [4:0] Rb,             //读地址，对应risc-v rs2
    input [4:0] Rw,             //写地址，对应rd
    input [31:0] busW,          //写入的数据
    input RegWr,                //写入有效控制，高电平有效
    input WrClk,                //控制写入的时钟信号
    output reg [31:0] busA,     //输出A
    output reg [31:0] busB      //输出B
);

    //寄存器堆
    reg [31:0] regfile [0:31];

    //处理x0寄存器
    initial begin
        regfile[0] = 32'b0;     //x0寄存器总是为0
    end

    //读取操作（异步）
    always @(*) begin
        if(Ra == 5'b0) begin
            busA = 32'b0;       //如果是x0地址，则返回0
        end else begin
            busA = regfile[Ra];
        end

        if(Rb == 5'b0) begin
            busB = 32'b0;       //如果是x0地址，则返回0
        end  else begin
            busB = regfile[Rb];
        end
    end

    //写操作
    always @(negedge WrClk) begin
            if(RegWr && Rw != 5'b0) begin
            regfile[Rw] <= busW;    //写数据到指定寄存器
        end
    end
endmodule