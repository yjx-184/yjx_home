module PC(
    input [31:0] NextPC,
    input CLK,
    input clrn,
    output reg [31:0] Pc
);
    always @(negedge CLK or negedge clrn) begin
        if(clrn == 1'b0)
            Pc <= 32'b0;
        else
            Pc <= NextPC;
    end
endmodule