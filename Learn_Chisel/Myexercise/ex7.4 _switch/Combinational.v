module Combinational(
  input        clock,
  input        reset,
  input  [3:0] io_in,
  output [7:0] io_seg
);
  wire [7:0] _GEN_0 = 4'h9 == io_in ? 8'h9 : 8'hff; // @[Combinational.scala 11:10 14:17 24:28]
  wire [7:0] _GEN_1 = 4'h8 == io_in ? 8'h1 : _GEN_0; // @[Combinational.scala 14:17 23:28]
  wire [7:0] _GEN_2 = 4'h7 == io_in ? 8'h1f : _GEN_1; // @[Combinational.scala 14:17 22:28]
  wire [7:0] _GEN_3 = 4'h6 == io_in ? 8'h41 : _GEN_2; // @[Combinational.scala 14:17 21:28]
  wire [7:0] _GEN_4 = 4'h5 == io_in ? 8'h49 : _GEN_3; // @[Combinational.scala 14:17 20:28]
  wire [7:0] _GEN_5 = 4'h4 == io_in ? 8'h99 : _GEN_4; // @[Combinational.scala 14:17 19:28]
  wire [7:0] _GEN_6 = 4'h3 == io_in ? 8'hd : _GEN_5; // @[Combinational.scala 14:17 18:28]
  wire [7:0] _GEN_7 = 4'h2 == io_in ? 8'h25 : _GEN_6; // @[Combinational.scala 14:17 17:28]
  wire [7:0] _GEN_8 = 4'h1 == io_in ? 8'h9f : _GEN_7; // @[Combinational.scala 14:17 16:28]
  assign io_seg = 4'h0 == io_in ? 8'h3 : _GEN_8; // @[Combinational.scala 14:17 15:28]
endmodule
