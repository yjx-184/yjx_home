module Data_Mux(
    input [31:0] DataOut_in,
    input [31:0] ALU_Result,
    input MemtoReg,
    output reg [31:0] busW
);

    always @(*) begin
        case(MemtoReg)
            1'b0: busW = ALU_Result;
            1'b1: busW = DataOut_in;
            default: busW = 32'b0;
        endcase
    end

endmodule