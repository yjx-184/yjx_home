module Branch_Cond(
    input [2:0] Branch,
    input Less,
    input Zero,
    output reg PCAsrc,
    output reg PCBsrc
);

    always @(*) begin
        //默认情况下, PC + 4
        PCAsrc = 0;  //默认设置为PC + 4
        PCBsrc = 0;  //默认设置为PC + 4
        
        case(Branch)
            3'b000: begin       //非跳转指令
                //PC + 4
                PCAsrc = 0;
                PCBsrc = 0;
            end

            3'b001: begin       //无条件跳转PC目标
                //PC + imm
                PCAsrc = 1;
                PCBsrc = 0;
            end

            3'b010: begin       //无条件跳转寄存器目标
                //rs1 + imm
                PCAsrc = 1;
                PCBsrc = 1;
            end

            3'b100: begin       //条件分支，等于
                case(Zero)
                    1'b0: begin //PC + 4
                        PCAsrc = 0;
                        PCBsrc = 0;
                    end

                    1'b1: begin //PC + imm
                        PCAsrc = 1;
                        PCBsrc = 0;
                    end
                endcase
            end

            3'b101: begin       //条件分支，不等于
                case(Zero)
                    1'b0: begin //PC + imm
                        PCAsrc = 1;
                        PCBsrc = 0;
                    end

                    1'b1: begin //PC + 4
                        PCAsrc = 0;
                        PCBsrc = 0;
                    end
                endcase
            end

            3'b110: begin       //条件分支，小于
                case(Less)
                    1'b0: begin //PC + 4
                        PCAsrc = 0;
                        PCBsrc = 0;
                    end

                    1'b1: begin //PC + imm
                        PCAsrc = 1;
                        PCBsrc = 0;
                    end
                endcase
            end

            3'b111: begin       //条件分支，大于等于
                case(Less)
                    1'b0: begin //PC + imm
                        PCAsrc = 1;
                        PCBsrc = 0;
                    end

                    1'b1: begin //PC + 4
                        PCAsrc = 0;
                        PCBsrc = 0;
                    end

                endcase
            end


        endcase

    end



endmodule