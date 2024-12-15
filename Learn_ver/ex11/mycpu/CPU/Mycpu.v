module Mycpu(
    input CLK,   //系统时钟
    input clrn,
    input [31:0] Instr,
    output [31:0] ALU_Result,
    output [31:0] busB,
    output [31:0] NextPC
);

    //内部信号声明
    wire [31:0] Pc, DataOut, Imm, busA, busW, ALU_A, ALU_B;
    wire [31:0] Addr, DataIn;
    wire [3:0] ALUctr;
    wire [2:0] Branch, MemOp, ExtOp;
    wire [1:0] ALUBsrc;
    wire Zero, Less, RegWr, WrEn, MemtoReg, PCAsrc, PCBsrc, ALUAsrc;

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
        .clrn(clrn),
        .Pc(Pc)
    );


    // ------ 指令译码及立即数生成 ------

    Reg_File my_RF(
        .Ra(Instr[19:15]),
        .Rb(Instr[24:20]),
        .Rw(Instr[11:7]),
        .busW(busW),
        .RegWr(RegWr),
        .WrClk(CLK),
        .clrn(clrn),
        .busA(busA),
        .busB(busB)
    );

    Imm_Gen my_IG(
        .instr(Instr),
        .ExtOp(ExtOp),
        .imm(Imm)
    );

    Contr_Gen my_CG(
        .op(Instr[6:0]),
        .func3(Instr[14:12]),
        .func7(Instr[31:25]),
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

endmodule