`timescale 1ns/1ps  // 修正后的 timescale

module tb_mux21b;
  reg a, b, s;
  wire y;

  mux21b uut (.a(a), .b(b), .s(s), .y(y));

  initial begin
    // 仿真输入设置
    a = 0; b = 0; s = 0; #10;
    a = 0; b = 1; s = 0; #10;
    a = 1; b = 0; s = 0; #10;
    a = 1; b = 1; s = 0; #10;
    a = 0; b = 0; s = 1; #10;
    a = 0; b = 1; s = 1; #10;
    a = 1; b = 0; s = 1; #10;
    a = 1; b = 1; s = 1; #10;
    
    // 停止仿真
    $finish;
  end
endmodule
