/* Minimal top level for the Chisel Hello World.
  Wire reset to 0. */

module hello_top(input clk, input [1:0] sw,output led);

  wire h_io_led;
  wire res;

  assign led = h_io_led;
  assign res = 1'h0;
  Hello h(.clock(clk), 
          .reset(res),
          .io_sw(sw),
          .io_led( h_io_led ));
endmodule
