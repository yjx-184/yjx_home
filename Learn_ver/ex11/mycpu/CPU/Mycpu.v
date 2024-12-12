module Mycpu(
    input CLK   //系统时钟
);

    //内部信号声明
    wire [31:0] Pc, NextPC, Instr, ALU_Result, DataOut, Imm, busA, busB, busW, ALU_A, ALU_B;
    wire [31:0] Addr, DataIn;
    wire [4:0] Ra, Rb, Rw;
    wire [3:0] ALUctr;
    wire [2:0] Branch, MemOp, ExtOp;
    wire [1:0] ALUBsrc;
    wire Zero, Less, RegWr, WrEn, MemtoReg, PCAsrc, PCBsrc, ALUAsrc, MemWr;

    //实例化

    // ------ 程序计数器 ------
    PCMux my_PCMux(
        .imm(Imm),
        .rs1(busA),
        .Pc(Pc),
        .PCAsrc(PCAsrc),
        .PCBsrc(PCBsrc),
        .NextPC(NextPC)
    );
    PC my_PC(
        .NextPC(NextPC),
        .CLK(CLK),
        .Pc(Pc)
    );

    // ------ 指令存储器 ------
    Instr_Mem my_IM(
        .Rdclk(CLK),
        .Rdaddr(NextPC),
        .Instr(Instr)
    );

    // ------ 指令译码及立即数生成 ------
    wire [6:0] op;
    wire [2:0] func3;
    wire [6:0] func7;

    assign  op  = Instr[6:0];
    assign  Ra = Instr[19:15];
    assign  Rb = Instr[24:20];
    assign  Rd  = Instr[11:7];
    assign  func3  = Instr[14:12];
    assign  func7  = Instr[31:25];

    Reg_File my_RF(
        .Ra(Ra),
        .Rb(Rb),
        .Rw(Rw),
        .busW(busW),
        .RegWr(RegWr),
        .WrClk(CLK),
        .busA(busA),
        .busB(busB)
    );

    Imm_Gen my_IG(
        .instr(Instr),
        .ExtOp(ExtOp),
        .imm(Imm)
    );

    Contr_Gen my_CG(
        .op(op),
        .func3(func3),
        .func7(func7),
        .ExtOp(ExtOp),
        .RegWr(RegWr),
        .ALUAsrc(ALUAsrc),
        .ALUBsrc(ALUBsrc),
        .ALUctr(ALUctr),
        .Branch(Branch),
        .MemtoReg(MemtoReg),
        .MemWr(MemWr),
        .MemOp(MemOp)
    );

    // ------ ALU ------
    ALU my_ALU(
        .rs1(busA),
        .rs2(busB),
        .ALUctr(ALUctr),
        .pc(Pc),
        .imm(Imm),
        .ALUAsrc(ALUAsrc),
        .ALUBsrc(ALUBsrc),
        .Less(Less),
        .Zero(Zero),
        .ALUout(ALU_Result)
    );

    // ------ 分支控制 ------
    Branch_Cond my_BC(
        .Branch(Branch),
        .Less(Less),
        .Zero(Zero),
        .PCAsrc(PCAsrc),
        .PCBsrc(PCBsrc)
    );

    // ------ 数据存储器 ------
    Data_Mem my_DM(
        .Addr(Addr),
        .MemOp(MemOp),
        .DataIn(DataIn),
        .WrEn(WrEn),
        .RdClk(CLK),
        .WrClk(CLK),
        .DataOut(DataOut)
    );

    Data_Mux my_DMux(
        .DataOut_in(DataOut),
        .ALU_Result(ALU_Result),
        .MemtoReg(MemtoReg),
        .busW(busW)
    );


endmodule