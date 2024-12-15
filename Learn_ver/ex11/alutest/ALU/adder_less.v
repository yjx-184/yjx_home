module adder_less(
    input Carry, 
    input Overflow, 
    input Cin,
    input [31:0] i_Result,
    input u_s,
    output reg [31:0] o_Result,
    output reg Less
);


    reg r0, r1;

    

    always @(*) begin
        r0 = Overflow ^ i_Result[0];  // Overflow与Result_l的最低位进行异或
        r1 = Cin ^ Carry;  // Cin与Carry进行异或

        if (u_s) begin
            //按无符号比较
            Less = (i_Result== 32'b0) ? 1'b1 : 1'b0;  // 无符号比较，符号位是1则Less为1
        end else begin
            //按带符号比较
            Less = (i_Result[31] == 1'b1) ? 1'b1 : 1'b0;  // 带符号比较，符号位是1则Less为1
        end

        //设置o_Result输出
        o_Result = i_Result;
    end

endmodule