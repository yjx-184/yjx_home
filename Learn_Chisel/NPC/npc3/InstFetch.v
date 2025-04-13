module InstFetch (
    input logic [31:0] pc,
    input clk,
    // input logic [31:0] gpr_0, gpr_1, gpr_2, gpr_3, gpr_4, gpr_5, gpr_6, gpr_7,
    // input logic [31:0] gpr_8, gpr_9, gpr_10, gpr_11, gpr_12, gpr_13, gpr_14, gpr_15,
    output logic [31:0] inst
);

    import "DPI-C" function int paddr_read(input int raddr, input int len);

    // import "DPI-C" function void set_inst(input int inst);

    // import "DPI-C" function void get_gpr_values(input [31:0] gpr[16]);

    // // 发送寄存器值
    // logic [31:0] gpr[16];
    // task send_gpr_values;
    //         // input [31:0] gpr[16];
    //         begin

    //         gpr[0] = gpr_0;
    //         gpr[1] = gpr_1;
    //         gpr[2] = gpr_2;
    //         gpr[3] = gpr_3;
    //         gpr[4] = gpr_4;
    //         gpr[5] = gpr_5;
    //         gpr[6] = gpr_6;
    //         gpr[7] = gpr_7;
    //         gpr[8] = gpr_8;
    //         gpr[9] = gpr_9;
    //         gpr[10] = gpr_10;
    //         gpr[11] = gpr_11;
    //         gpr[12] = gpr_12;
    //         gpr[13] = gpr_13;
    //         gpr[14] = gpr_14;
    //         gpr[15] = gpr_15;
            

    //         get_gpr_values(gpr);
    //         end
    //     endtask
    always @(negedge clk) begin

        inst <= paddr_read(pc,4);
        // set_inst(inst);  // 每个周期传递指令到 C 端

        // send_gpr_values();
    end


endmodule