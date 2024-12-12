module PC(
    input [31:0] NextPC,
    input CLK,
    output reg [31:0] Pc
);
    initial begin
        Pc = 32'b0;
    end

    always @(negedge CLK) begin
        Pc <= NextPC;
    end
endmodule