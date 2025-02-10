module Seg(
  input        clock,
  input        reset,
  input  [7:0] io_in,
  input        io_sel,
  output [2:0] io_out,
  output [6:0] io_seg,
  output       io_valid
);
  wire [1:0] _GEN_1 = io_in[2] ? 2'h2 : {{1'd0}, io_in[1]}; // @[Seg.scala 26:27 27:20]
  wire [1:0] _GEN_2 = io_in[3] ? 2'h3 : _GEN_1; // @[Seg.scala 24:27 25:20]
  wire [2:0] _GEN_3 = io_in[4] ? 3'h4 : {{1'd0}, _GEN_2}; // @[Seg.scala 22:27 23:20]
  wire [2:0] _GEN_4 = io_in[5] ? 3'h5 : _GEN_3; // @[Seg.scala 20:27 21:20]
  wire [2:0] _GEN_5 = io_in[6] ? 3'h6 : _GEN_4; // @[Seg.scala 18:27 19:20]
  wire [6:0] _GEN_7 = 3'h7 == io_out ? 7'hf : 7'h0; // @[Seg.scala 40:12 43:24 51:30]
  wire [6:0] _GEN_8 = 3'h6 == io_out ? 7'h20 : _GEN_7; // @[Seg.scala 43:24 50:30]
  wire [6:0] _GEN_9 = 3'h5 == io_out ? 7'h24 : _GEN_8; // @[Seg.scala 43:24 49:30]
  wire [6:0] _GEN_10 = 3'h4 == io_out ? 7'h4c : _GEN_9; // @[Seg.scala 43:24 48:30]
  wire [6:0] _GEN_11 = 3'h3 == io_out ? 7'h6 : _GEN_10; // @[Seg.scala 43:24 47:30]
  wire [6:0] _GEN_12 = 3'h2 == io_out ? 7'h12 : _GEN_11; // @[Seg.scala 43:24 46:30]
  wire [6:0] _GEN_13 = 3'h1 == io_out ? 7'h4f : _GEN_12; // @[Seg.scala 43:24 45:30]
  wire [6:0] _GEN_14 = 3'h0 == io_out ? 7'h1 : _GEN_13; // @[Seg.scala 43:24 44:30]
  assign io_out = io_in[7] ? 3'h7 : _GEN_5; // @[Seg.scala 16:20 17:20]
  assign io_seg = io_sel ? _GEN_14 : 7'h0; // @[Seg.scala 40:12 42:18]
  assign io_valid = |io_in; // @[Seg.scala 37:23]
endmodule
