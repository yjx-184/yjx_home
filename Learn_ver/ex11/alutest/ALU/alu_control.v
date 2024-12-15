module alu_control(
    input [3:0] ALUctr,
    output  reg [2:0] actr,
    output  reg a_l,
    output  reg l_r,
    output  reg u_s,
    output  reg Cin
);
    always @(*) begin
        //默认值
        actr = 3'b000;
        a_l = 1'b0;
        l_r = 1'b0;
        u_s = 1'b0;
        Cin = 1'b0;

        case(ALUctr)
            //选择加法器输出，做加法
            4'b0000:begin
                        actr = 3'b000;
                        Cin = 1'b0;
                    end
            //选择加法器输出，做减法
            4'b1000:begin
                        actr = 3'b000;
                        Cin = 1'b1;
                    end


            //选择移位器输出，左移
            4'b0001:begin
                        actr = 3'b001;
                        l_r = 1'b0;
                    end
            //选择移位器输出，左移
            4'b1001:begin
                        actr = 3'b001;
                        l_r = 1'b0;
                    end


            //做减法，选择带符号小于置位结果输出, Less按带符号结果设置
            4'b0010:begin
                        actr = 3'b010;
                        u_s = 1'b0;
                    end
            //做减法，选择无符号小于置位结果输出, Less按无符号结果设置
            4'b1010:begin
                        actr = 3'b010;
                        u_s = 1'b1;
                    end


            //选择ALU输入B的结果直接输出
            4'b0011:begin
                        actr = 3'b011;
                    end
            //选择ALU输入B的结果直接输出
            4'b1011:begin
                        actr = 3'b011;
                    end


            //选择异或输出
            4'b0100:begin
                        actr = 3'b100;
                    end
            //选择异或输出
            4'b1100:begin
                        actr = 3'b100;
                    end


            //选择移位器输出，逻辑右移
            4'b0101:begin
                        actr = 3'b101;
                        a_l = 1'b0;
                    end
            //选择移位器输出，算术右移
            4'b1101:begin
                        actr = 3'b101;
                        a_l = 1'b1;
                    end


            //选择逻辑或输出
            4'b0110:begin
                        actr = 3'b110;
                    end
            //选择逻辑或输出
            4'b1110:begin
                        actr = 3'b110;
                    end

            //选择逻辑与输出
            4'b0111:begin
                        actr = 3'b111;
                    end
            //选择逻辑与输出
            4'b1111:begin
                        actr = 3'b111;
                    end


            default: begin
                // 默认操作，防止出现无效操作
                actr = 3'b000;   // 默认为加法
                Cin = 1'b0;      // 无进位输入
            end

        endcase
    end
endmodule