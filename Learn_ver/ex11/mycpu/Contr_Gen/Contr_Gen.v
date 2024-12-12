module Contr_Gen(
    input [6:0] op,         //操作码
    input [2:0] func3,      //功能码3
    input [6:0] func7,      //功能码7
    output reg [2:0] ExtOp,     //宽度为3bit，选择立即数产生器的输出类型
    output reg RegWr,           //宽度为1bit，控制是否对寄存器rd进行写回，为1时写回寄存器
    output reg ALUAsrc,         //宽度为1bit，选择ALU输入端A的来源。为0时选择rs1，为1时选择PC
    output reg [1:0] ALUBsrc,   //宽度为2bit，选择ALU输入端B的来源。
    output reg [3:0] ALUctr,    //宽度为4bit，选择ALU执行的操作
    output reg [2:0] Branch,    //宽度为3bit，说明分支和跳转的种类，用于生成最终的分支控制信号
    output reg MemtoReg,        //宽度为1bit，选择寄存器rd写回数据来源，为0时选择ALU输出，为1时选择数据存储器输出
    output reg MemWr,           //宽度为1bit，控制是否对数据存储器进行写入，为1时写回存储器
    output reg [2:0] MemOp      //宽度为3bit，控制数据存储器读写格式
);
    

    always @(*) begin
        //默认值
        RegWr = 0;
        ALUAsrc = 0;
        ALUBsrc = 2'b00;
        ALUctr = 4'b0000;
        Branch = 3'b000;
        MemtoReg = 0;
        MemWr = 0;
        MemOp = 3'b000;
        ExtOp = 3'b000;

        case(op[6:2])
            7'b01101: begin         //lui
                ExtOp = 3'b001;
                RegWr = 1;
                ALUBsrc = 2'b01;
                ALUctr = 4'b0011;
            end 

            7'b00101: begin         //auipc
                ExtOp = 3'b001;
                RegWr = 1;
                Branch = 3'b000;
                ALUAsrc = 1;
                ALUBsrc = 2'b01;
            end

            7'b00100: begin
                case(func3)
                    3'b000: begin   //addi
                        RegWr = 1;
                        ALUBsrc = 2'b01;
                    end

                    3'b010: begin   //slti
                        RegWr = 1;
                        ALUBsrc = 2'b01;
                        ALUctr = 4'b0010;
                    end

                    3'b011: begin   //sltiu
                        RegWr = 1;
                        ALUBsrc = 2'b01;
                        ALUctr = 4'b1010;
                    end

                    3'b100: begin   //xori
                        RegWr = 1;
                        ALUBsrc = 2'b01;
                        ALUctr = 4'b0100;
                    end

                    3'b110: begin   //ori
                        RegWr = 1;
                        ALUBsrc = 2'b01;
                        ALUctr = 4'b0110;
                    end

                    3'b111: begin   //andi
                        RegWr = 1;
                        ALUBsrc = 2'b01;
                        ALUctr = 4'b0111;
                    end

                    3'b001: begin   //slli
                        if(func7[5] == 1'b0) begin
                            ExtOp = 3'b001;
                            RegWr = 1;
                            ALUBsrc = 2'b01;
                            ALUctr = 4'b0001;
                        end
                    end

                    3'b101: begin   
                        case(func7[5]) 
                            1'b0: begin      //srli
                                ExtOp = 3'b001;
                                RegWr = 1;
                                Branch = 3'b000;
                                MemtoReg = 0;
                                MemWr = 0;
                                ALUAsrc = 0;
                                ALUBsrc = 2'b01;
                                ALUctr = 4'b0101;
                            end

                            1'b1: begin  //srai
                                ExtOp = 3'b001;
                                RegWr = 1;
                                Branch = 3'b000;
                                MemtoReg = 0;
                                MemWr = 0;
                                ALUAsrc = 0;
                                ALUBsrc = 2'b01;
                                ALUctr = 4'b1101;
                            end 

                            default: begin
                                // 默认行为
                                RegWr = 0;
                                ALUBsrc = 2'b00;
                                ALUctr = 4'b0000;
                            end
                            
                        endcase
                    end
                    default: begin
                        ALUBsrc = 2'b00;  // 设置默认值
                    end
                endcase
            end

            7'b01100: begin
                case(func3)
                    3'b000: begin   
                        case(func7[5]) 
                            1'b0: begin     //add
                                RegWr = 1;
                            end 

                            1'b1: begin     //sub
                                RegWr = 1;
                                ALUctr = 4'b1000;
                            end

                            default: begin
                                // 默认行为
                                RegWr = 0;
                                ALUBsrc = 2'b00;
                                ALUctr = 4'b0000;
                            end
                        endcase
                    end

                    3'b001: begin           //sll
                        if(!func7[5]) begin
                            RegWr = 1;
                            ALUctr = 4'b0001;
                        end
                    end

                    3'b010: begin           //slt
                        if(!func7[5]) begin
                            RegWr = 1;
                            ALUctr = 4'b0010;
                        end
                    end

                    3'b011: begin           //sltu
                        if(!func7[5]) begin
                            RegWr = 1;
                            ALUctr = 4'b1010;
                        end
                    end

                    3'b100: begin           //xor
                        if(!func7[5]) begin
                            RegWr = 1;
                            ALUctr = 4'b0100;
                        end
                    end

                    3'b101: begin           //srl
                        case(func7[5]) 
                        1'b0:begin
                            RegWr = 1;
                            ALUctr = 4'b0101;
                        end 
                        1'b1: begin         //sra
                            RegWr = 1;
                            ALUctr = 4'b1101;
                        end
                    endcase
                    end

                    3'b110: begin           //or
                        if(!func7[5]) begin
                            RegWr = 1;
                            ALUctr = 4'b0110;
                        end
                    end

                    3'b111: begin           //and
                        if(!func7[5]) begin
                            RegWr = 1;
                            ALUctr = 4'b0111;
                        end
                    end
                endcase
            end

            7'b11011: begin                 //jal
                ExtOp = 3'b100;
                RegWr = 1;
                Branch = 3'b001;
                ALUAsrc = 1;
                ALUBsrc = 2'b10;
            end

            7'b11001: begin                 //jalr
                case(func3)
                    3'b000: begin
                        RegWr = 1;
                        Branch = 3'b010;
                        ALUAsrc = 1;
                        ALUBsrc = 2'b10;
                    end
                    default: begin
                        // 未定义的func3，做出默认处理
                        RegWr = 0;
                        Branch = 3'b000;
                        ALUAsrc = 0;
                        ALUBsrc = 2'b00;
                    end
                endcase
            end

            7'b11000: begin
                case(func3)
                    3'b000: begin           //beq
                        ExtOp = 3'b011;
                        Branch = 3'b100;
                        ALUctr = 4'b0010;
                    end

                    3'b001: begin           //bne
                        ExtOp = 3'b011;
                        Branch = 3'b101;
                        ALUctr = 4'b0010;
                    end

                    3'b100: begin           //blt
                        ExtOp = 3'b011;
                        Branch = 3'b110;
                        ALUctr = 4'b0010;
                    end

                    3'b101: begin           //bge
                        ExtOp = 3'b011;
                        Branch = 3'b111;
                        ALUctr = 4'b0010;
                    end

                    3'b110: begin           //bltu
                        ExtOp = 3'b011;
                        Branch = 3'b110;
                        ALUctr = 4'b1010;
                    end

                    3'b111: begin           //bgeu
                        ExtOp = 3'b011;
                        Branch = 3'b111;
                        ALUctr = 4'b1010;
                    end
                endcase
            end

            7'b00000: begin
                case(func3)
                    3'b000: begin           //lb
                        RegWr = 1;
                        MemtoReg = 1;
                        ALUBsrc = 2'b01;
                    end

                    3'b001: begin           //lh
                        RegWr = 1;
                        MemtoReg = 1;
                        MemOp = 3'b001;
                        ALUBsrc = 2'b01;
                    end

                    3'b010: begin           //lw
                        RegWr = 1;
                        MemtoReg = 1;
                        MemOp = 3'b010;
                        ALUBsrc = 2'b01;
                    end

                    3'b100: begin           //lbu
                        RegWr = 1;
                        MemtoReg = 1;
                        MemOp = 3'b100;
                        ALUBsrc = 2'b01;
                    end

                    3'b101: begin           //lhu
                        RegWr = 1;
                        MemtoReg = 1;
                        MemOp = 3'b101;
                        ALUBsrc = 2'b01;
                    end
                endcase
            end

            7'b01000: begin
                case(func3)
                    3'b000: begin           //sb
                        ExtOp = 3'b010;
                        MemWr = 1;
                        MemOp = 3'b000;
                        ALUBsrc = 2'b01;
                    end

                    3'b001: begin           //sh
                        ExtOp = 3'b010;
                        MemWr = 1;
                        MemOp = 3'b001;
                        ALUBsrc = 2'b01;
                    end

                    3'b010: begin           //sw
                        ExtOp = 3'b010;
                        MemWr = 1;
                        MemOp = 3'b010;
                        ALUBsrc = 2'b01;
                    end
                endcase
            end

        default: begin
            // 未知的操作码，做出默认处理
            RegWr = 0;
            ALUAsrc = 0;
            ALUBsrc = 2'b00;
            ALUctr = 4'b0000;
            Branch = 3'b000;
            MemtoReg = 0;
            MemWr = 0;
            MemOp = 3'b000;
            ExtOp = 3'b000;
        end
        endcase
    end
endmodule