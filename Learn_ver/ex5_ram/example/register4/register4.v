module register4(load, clk, clr, d, q);
    input load, clr, clk;
    input [3:0] d;
    output reg [3:0] q;

    always @(posedge clk)
        if(clr == 1)
            q <= 0;
        else if(load ==1)
            q <= d;
endmodule