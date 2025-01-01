/* Minimal top level for the Chisel Hello World.
  Wire reset to 0. */

module Combinational_top(
  input clk, 
  input res,
  input [3:0] in,
  output [7:0] seg);

  Combinational uut(
    .clock(clk), 
    .reset(res),
    .io_in(in),
    .io_seg(seg));
endmodule
