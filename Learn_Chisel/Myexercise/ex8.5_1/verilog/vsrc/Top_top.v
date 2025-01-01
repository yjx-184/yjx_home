/* Minimal top level for the Chisel Hello World.
  Wire reset to 0. */

module Top_top(
  input clk, 
  input res,
  output [7:0] seg);

  Top uut(
    .clock(clk), 
    .reset(res),
    .io_seg(seg));
endmodule
