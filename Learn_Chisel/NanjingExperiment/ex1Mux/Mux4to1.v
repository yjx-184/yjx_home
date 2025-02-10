module Mux4to1(
  input        clock,
  input        reset,
  input  [1:0] io_X0,
  input  [1:0] io_X1,
  input  [1:0] io_X2,
  input  [1:0] io_X3,
  input  [1:0] io_Y,
  output [1:0] io_F
);
  wire  _io_F_T = io_Y == 2'h0; // @[Mux4to1.scala 16:11]
  wire  _io_F_T_1 = io_Y == 2'h1; // @[Mux4to1.scala 17:11]
  wire  _io_F_T_2 = io_Y == 2'h2; // @[Mux4to1.scala 18:11]
  wire  _io_F_T_3 = io_Y == 2'h3; // @[Mux4to1.scala 19:11]
  wire [1:0] _io_F_T_4 = _io_F_T_3 ? io_X3 : 2'h0; // @[Mux.scala 101:16]
  wire [1:0] _io_F_T_5 = _io_F_T_2 ? io_X2 : _io_F_T_4; // @[Mux.scala 101:16]
  wire [1:0] _io_F_T_6 = _io_F_T_1 ? io_X1 : _io_F_T_5; // @[Mux.scala 101:16]
  assign io_F = _io_F_T ? io_X0 : _io_F_T_6; // @[Mux.scala 101:16]
endmodule
