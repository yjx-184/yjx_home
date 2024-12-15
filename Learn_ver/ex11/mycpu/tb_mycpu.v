`timescale 1ns / 10ps

module tb_Mycpu;
    //接口信号
    reg CLK, clrn;
    wire MemtoReg, MemWr;
    wire [31:0] Rdaddr, Instr, Addr, DataIn;
    wire [2:0] MemOp;
    wire [31:0] DataOut, busW, ALU_Result, busB;
    reg [31:0] NextPC;




    //实例化被测试模块
    Instr_Mem My_IM(
        .Rdclk(CLK),
        .Rdaddr(NextPC),
        .Instr(Instr)
    );

    Mycpu my_cpu_tb(
        .Instr(Instr),
        .clrn(clrn),
        .CLK(CLK),
        .ALU_Result(ALU_Result),
        .busB(busB)
    );

    Data_Mem my_DM(
        .Addr(ALU_Result),
        .MemOp(MemOp),
        .DataIn(busB),
        .WrEn(MemWr),
        .RdClk(CLK),
        .WrClk(CLK),
        .clrn(clrn),
        .DataOut(DataOut)
    );

    Data_Mux my_DMux(
        .DataOut_in(DataOut),
        .ALU_Result(ALU_Result),
        .MemtoReg(MemtoReg),
        .busW(busW)
    );

    always begin
        CLK = 0;
        #10 CLK = ~CLK;
    end

    initial begin
        //初始化
        clrn = 0;
        NextPC = 32'b0;
        #20 clrn = 1;

        My_IM.mem_array[0] = 32'h00230293;
        $display("获得到的指令: mem_array = 32'h%h", My_IM.mem_array[0]);
        $display("开始时的数据: Instr = %h", Instr);
        $display("Ra(h) = %h, Rb(h) = %h, Rw(h) = %h", my_cpu_tb.my_RF.Ra, my_cpu_tb.my_RF.Rb, my_cpu_tb.my_RF.Rw);
        $display("Ra(b) = %b, Rb(b) = %b, Rw(b) = %b", my_cpu_tb.my_RF.Ra, my_cpu_tb.my_RF.Rb, my_cpu_tb.my_RF.Rw);
        
        #10;
        $display("上升沿数据:ALU_Result = %b",ALU_Result);

        #200;
        $finish;

    end

endmodule