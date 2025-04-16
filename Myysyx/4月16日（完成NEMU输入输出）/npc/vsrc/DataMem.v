module DataMem (
    // input clk,
    input valid,
    input wen,
    input [31:0] raddr,
    input [31:0] waddr,
    input [31:0] wdata,
    input [2:0] wmask,
    output reg [31:0] rdata
);

    // 引用DPI-C接口的声明
    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(
        input int waddr, input byte wmask, input int wdata
    );


    // 处理读写操作
    always @(*) begin
        byte actual_mask = 8'b00001111;
        if (valid) begin
            rdata = pmem_read(raddr);
            if (wen) begin
                case (wmask)
                    3'b000: actual_mask = 8'b00000001; // 1字节 (最低字节)
                    3'b001: actual_mask = 8'b00000011; // 2字节
                    3'b010: actual_mask = 8'b00001111; // 4字节  
                    // 3'b100: actual_mask = 8'b00000001; // 1字节 (无符号)
                    // 3'b101: actual_mask = 8'b00000011; // 2字节 (无符号)
                    default: actual_mask = 8'b00001111; // 默认4字节
                endcase
                pmem_write(waddr, actual_mask, wdata);
            end
        end else begin
            rdata = 0;
        end
    end
endmodule