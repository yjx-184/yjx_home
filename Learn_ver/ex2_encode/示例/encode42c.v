module encode42c(in_code, en, out_code);
    input [3:0] in_code;
    input en;
    output reg [1:0] out_code;

    always @(in_code or en) begin
        if(en) begin
            casez(in_code)
                4'b0001: out_code = 2'b00;
                4'b001z: out_code = 2'b01;
                4'b01zz: out_code = 2'b10;
                4'b1???: out_code = 2'b11;
                default: out_code = 2'b00;
            endcase    
        end else
            out_code = 2'b00;
    end


endmodule