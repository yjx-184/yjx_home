`timescale 1ns / 1ps

module tb_Contr_Gen;
    //接口信号
    reg [6:0] op;
    reg [2:0] func3;
    reg [6:0] func7;
    wire [2:0] ExtOp;
    wire RegWr;
    wire ALUAsrc;
    wire [1:0] ALUBsrc;
    wire [3:0] ALUctr;
    wire [2:0] Branch;
    wire MemtoReg;
    wire MemWr;
    wire [2:0] MemOp;

    //实例化被测试模块
    Contr_Gen uut(
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


    //测试逻辑
    initial begin
        // 初始化
        op = 7'b0;
        func3 = 3'b0;
        func7 = 7'b0;

        // 打印开始测试信息
        $display("开始测试");

        //测试lui
        op = 7'b0110111; func3 = 3'b000; func7 = 7'b0000000;
        #10; 
        $display("test lui:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //测试auipc
        op = 7'b0010111; func3 = 3'b000; func7 = 7'b0000000;
        #10;
        $display("test auipc:   ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        #10;
        $display("......");

        //测试addi
        op = 7'b0010011; func3 = 3'b000; func7 = 7'b0000000;
        #10;
        $display("test addi:    ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //测试slti
        op = 7'b0010011; func3 = 3'b010; func7 = 7'b0000000;
        #10;
        $display("test slti:    ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr); 

        //测试sltiu
        op = 7'b0010011; func3 = 3'b011; func7 = 7'b0000000;
        #10;
        $display("test sltiu:   ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr); 

        //测试xori
        op = 7'b0010011; func3 = 3'b100; func7 = 7'b0000000;
        #10;
        $display("test xori:    ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //测试ori
        op = 7'b0010011; func3 = 3'b110; func7 = 7'b0000000;
        #10;
        $display("test ori:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //测试andi
        op = 7'b0010011; func3 = 3'b111; func7 = 7'b0000000;
        #10;
        $display("test andi:    ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //测试slli
        op = 7'b0010011; func3 = 3'b001; func7 = 7'b0000000;
        #10;
        $display("test slli:    ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //测试srli
        op = 7'b0010011; func3 = 3'b101; func7 = 7'b0000000;
        #10;
        $display("test srli:    ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //测试srai
        op = 7'b0010011; func3 = 3'b101; func7 = 7'b1111111;
        #10;
        $display("test srai:    ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);
        #10;
        $display(".......");

        //add
        op = 7'b0110011; func3 = 3'b000; func7 = 7'b0000000;
        #10;
        $display("test add:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //sub
        op = 7'b0110011; func3 = 3'b000; func7 = 7'b1111111;
        #10;
        $display("test sub:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //sll
        op = 7'b0110011; func3 = 3'b001; func7 = 7'b0000000;
        #10;
        $display("test sll:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //slt
        op = 7'b0110011; func3 = 3'b010; func7 = 7'b0000000;
        #10;
        $display("test slt:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //sltu
        op = 7'b0110011; func3 = 3'b011; func7 = 7'b0000000;
        #10;
        $display("test sltu:    ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //xor
        op = 7'b0110011; func3 = 3'b100; func7 = 7'b0000000;
        #10;
        $display("test xor:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //srl
        op = 7'b0110011; func3 = 3'b101; func7 = 7'b0000000;
        #10;
        $display("test srl:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //sra
        op = 7'b0110011; func3 = 3'b101; func7 = 7'b1111111;
        #10;
        $display("test sra:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //or
        op = 7'b0110011; func3 = 3'b110; func7 = 7'b0000000;
        #10;
        $display("test or:      ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //and
        op = 7'b0110011; func3 = 3'b111; func7 = 7'b0000000;
        #10;
        $display("test and:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        #10;
        $display("......");

        //jal
        op = 7'b1101111;
        #10;
        $display("test jal:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //jalr
        op = 7'b1100111; func3 = 3'b000;
        #10;
        $display("test jalr:    ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //beq
        op = 7'b1100011; func3 = 3'b000;
        #10;
        $display("test beq:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //bne
        op = 7'b1100011; func3 = 3'b001;
        #10;
        $display("test bne:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //blt
        op = 7'b1100011; func3 = 3'b100;
        #10;
        $display("test blt:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //bge
        op = 7'b1100011; func3 = 3'b101;
        #10;
        $display("test bge:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //bltu
        op = 7'b1100011; func3 = 3'b110;
        #10;
        $display("test bltu:    ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //bgeu
        op = 7'b1100011; func3 = 3'b111;
        #10;
        $display("test bgeu:    ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        #10;
        $display("......");

        //lb
        op = 7'b0000011; func3 = 3'b000;
        #10;
        $display("test bl:      ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //lh
        op = 7'b0000011; func3 = 3'b001;
        #10;
        $display("test lh:      ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //lw
        op = 7'b0000011; func3 = 3'b010;
        #10;
        $display("test lw:      ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //lbu
        op = 7'b0000011; func3 = 3'b100;
        #10;
        $display("test lbu:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //lhu
        op = 7'b0000011; func3 = 3'b101;
        #10;
        $display("test lhu:     ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //sb
        op = 7'b0100011; func3 = 3'b000;
        #10;
        $display("test sb:      ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //sh
        op = 7'b0100011; func3 = 3'b001;
        #10;
        $display("test sh:      ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        //sw
        op = 7'b0100011; func3 = 3'b010;
        #10;
        $display("test sw:      ExtOp = %b, RegWr = %b, Branch = %b, MemtoReg = %b, MemWr = %b, MemOp = %b, ALUAsrc = %b, ALUBsrc = %b, ALUctr = %b",
                    ExtOp, RegWr, Branch, MemtoReg, MemWr, MemOp, ALUAsrc, ALUBsrc, ALUctr);

        #50;

        $display("测试结束");
        $finish;
    end


endmodule