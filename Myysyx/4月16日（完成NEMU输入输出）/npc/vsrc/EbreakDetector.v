module EbreakDetector(
    input [31:0] inst,
    input [31:0] pc,
    output exit
);

    // 检测是否为 ebreak 指令
    assign exit = (inst == 32'h00100073); // ebreak指令的操作码
endmodule
