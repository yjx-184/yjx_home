module SimReg #(
    parameter WIDTH = 4,        // 数据位宽
    parameter RESET_VALUE = 0   // 复位初始值
) (
    input clk,                  // 时钟信号
    input reset,                // 复位信号
    input [WIDTH-1:0] din,      // 数据输入
    output reg [WIDTH-1:0] dout, // 数据输出
    input wen                   // 写使能
);
    // 寄存器逻辑：在时钟上升沿或复位时操作
    always @(posedge clk or negedge reset) begin
        if (!reset)              // 低电平复位
            dout <= RESET_VALUE; // 复位时输出为初始值
        else if (wen) 
            dout <= din;         // 写使能为高时更新寄存器值
    end
endmodule
