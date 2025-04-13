module DataMem (
    input clk,
    input wen,
    input [31:0] raddr,
    input [31:0] waddr,
    input [31:0] wdata,
    input [2:0] wmask,
    output reg [31:0] rdata
);

    // 引用DPI-C接口的声明
    import "DPI-C" function int pmem_read(input int raddr, input int len);
    import "DPI-C" function void pmem_write(
        input int waddr, input byte wmask, input int wdata
    );

    // 处理读操作（时钟上升沿）
    always @(posedge clk) begin
        rdata <= pmem_read(raddr, 4);
    end

    // 处理写操作（时钟上升沿，但用寄存器延迟一个周期，模拟下降沿写）
    reg wen_d;  // 记录 wen 的上一个周期状态
    always @(posedge clk) begin
        wen_d <= wen; // 延迟wen信号
        if (wen_d) begin // 在时钟上升沿的下一个周期执行写入，相当于下降沿时写
            pmem_write(waddr, {5'b0, wmask}, wdata);
        end
    end
endmodule