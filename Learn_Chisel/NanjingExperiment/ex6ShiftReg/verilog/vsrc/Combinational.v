module Combinational(
  input        clock,
  input        reset,
  input  [3:0] io_in,
  output [7:0] io_seg
);
  wire [7:0] _GEN_0 = io_in == 4'h9 ? 8'h9 : 8'hff; // @[Combinational.scala 22:{36,45} 23:25]
  wire [7:0] _GEN_1 = io_in == 4'h8 ? 8'h1 : _GEN_0; // @[Combinational.scala 21:{36,45}]
  wire [7:0] _GEN_2 = io_in == 4'h7 ? 8'h1f : _GEN_1; // @[Combinational.scala 20:{36,45}]
  wire [7:0] _GEN_3 = io_in == 4'h6 ? 8'h41 : _GEN_2; // @[Combinational.scala 19:{36,45}]
  wire [7:0] _GEN_4 = io_in == 4'h5 ? 8'h49 : _GEN_3; // @[Combinational.scala 18:{36,45}]
  wire [7:0] _GEN_5 = io_in == 4'h4 ? 8'h99 : _GEN_4; // @[Combinational.scala 17:{36,45}]
  wire [7:0] _GEN_6 = io_in == 4'h3 ? 8'hd : _GEN_5; // @[Combinational.scala 16:{36,45}]
  wire [7:0] _GEN_7 = io_in == 4'h2 ? 8'h25 : _GEN_6; // @[Combinational.scala 15:{36,45}]
  wire [7:0] _GEN_8 = io_in == 4'h1 ? 8'h9f : _GEN_7; // @[Combinational.scala 14:{36,45}]
  assign io_seg = io_in == 4'h0 ? 8'h3 : _GEN_8; // @[Combinational.scala 13:{29,38}]
endmodule
