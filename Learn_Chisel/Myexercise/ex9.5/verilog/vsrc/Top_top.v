/* Minimal top level for the Chisel Hello World.
  Wire reset to 0. */

module Top_top(
  input clk, 
  input res,
  input btn,
  output [7:0] led);

  Top uut(
    .clock(clk), 
    .reset(res),
    .io_btn(btn),
    .io_led(led));
endmodule
