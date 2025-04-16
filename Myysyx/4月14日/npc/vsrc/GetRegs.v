module GetRegs(
    input [31:0] regs_0,
    input [31:0] regs_1,
    input [31:0] regs_2,
    input [31:0] regs_3,
    input [31:0] regs_4,
    input [31:0] regs_5,
    input [31:0] regs_6,
    input [31:0] regs_7,
    input [31:0] regs_8,
    input [31:0] regs_9,
    input [31:0] regs_10,
    input [31:0] regs_11,
    input [31:0] regs_12,
    input [31:0] regs_13,
    input [31:0] regs_14,
    input [31:0] regs_15
);
    import "DPI-C" function void get_regs(
        input int regs_0, input int regs_1, input int regs_2, input int regs_3,
        input int regs_4, input int regs_5, input int regs_6, input int regs_7,
        input int regs_8, input int regs_9, input int regs_10, input int regs_11,
        input int regs_12, input int regs_13, input int regs_14, input int regs_15
    );

    always @(*) begin
        get_regs(
            regs_0, 
            regs_1, 
            regs_2, 
            regs_3,
            regs_4, 
            regs_5, 
            regs_6, 
            regs_7,
            regs_8, 
            regs_9, 
            regs_10, 
            regs_11,
            regs_12, 
            regs_13, 
            regs_14, 
            regs_15
        );
    end



endmodule