module ps2_display(clk, clrn, ascii, display_data);
    input clk;
    input clrn;
    input ascii;
    output reg [7:0] display_data;

    always @(posedge clk or negedge clrn) begin
        if(clrn == 1'b0) begin
            display_data <= 8'h00;
        end else display_data <= ascii;
        end
endmodule