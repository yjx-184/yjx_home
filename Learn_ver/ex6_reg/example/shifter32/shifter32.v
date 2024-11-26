module shifter32(din, shamt, LR, AL, dout);
    input [31:0] din;        //32位数据输入
    input [4:0] shamt;      //移位位数
    input LR;               //选择1左移还是0右移
    input AL;               //算术逻辑选择，1算术移位，0逻辑移位
    output reg [31:0] dout;  //8位数据输出

    always @(*) begin
        if (LR) begin    // LR 为 1 时左移
            dout = din << shamt;  // 左移
        end else begin      // LR 为 0 时右移
            if (AL) begin    // AL 为 1 时算术右移
                dout = $signed(din) >>> shamt;  // 算术右移
            end else begin   // AL 为 0 时逻辑右移
                dout = din >> shamt;  // 逻辑右移
            end
        end
    end
endmodule