module PCMux(
    input [31:0] imm,
    input [31:0] rs1,
    input [31:0] Pc,
    input PCAsrc,
    input PCBsrc,
    output reg [31:0] NextPC
);

    always @(*) begin
        if(PCAsrc == 0) begin
            //PC + 4
            NextPC = Pc + 4;
        end else begin
            if(PCBsrc == 0) begin
                //PC + imm
                NextPC = Pc + imm;
            end else begin
                //rs1 + imm
                NextPC = rs1 + imm;
            end
        end
    end
endmodule