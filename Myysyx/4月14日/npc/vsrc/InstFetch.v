module InstFetch (
    input logic [31:0] pc,
    input clk,
    input logic rst,
    output logic [31:0] inst
);
    // 内部寄存器用于存储pc值，初始化为0x80000000
    reg [31:0] pc_reg = 32'h80000000;

    import "DPI-C" function int pmem_read(input int raddr);

    always @(negedge clk or posedge rst) begin
        if (rst) begin
            // 复位时，pc_reg 初始化为 0x80000000
            pc_reg <= 32'h80000000;
        end else begin
            pc_reg <= pc;
        end
    end

    always @(posedge clk) begin

        inst <= pmem_read(pc_reg);

    end


endmodule