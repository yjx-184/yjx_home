module Alu(
  input        clock,
  input        reset,
  input  [2:0] io_op,
  input  [3:0] io_a,
  input  [3:0] io_b,
  output       io_carry,
  output       io_zero,
  output       io_overflow,
  output [3:0] io_result
);
  wire [4:0] sum = $signed(io_a) + $signed(io_b); // @[Alu.scala 37:22]
  wire [3:0] _result_T_1 = sum[3:0]; // @[Alu.scala 38:27]
  wire [4:0] diff = $signed(io_a) - $signed(io_b); // @[Alu.scala 45:23]
  wire [3:0] _result_T_3 = diff[3:0]; // @[Alu.scala 46:28]
  wire [3:0] _result_T_5 = ~io_a; // @[Alu.scala 53:17]
  wire [3:0] _result_T_7 = $signed(io_a) & $signed(io_b); // @[Alu.scala 56:22]
  wire [3:0] _result_T_9 = $signed(io_a) | $signed(io_b); // @[Alu.scala 59:22]
  wire [3:0] _result_T_11 = $signed(io_a) ^ $signed(io_b); // @[Alu.scala 62:22]
  wire [1:0] _result_T_13 = $signed(io_a) < $signed(io_b) ? $signed(2'sh1) : $signed(2'sh0); // @[Alu.scala 65:20]
  wire [1:0] _result_T_15 = $signed(io_a) == $signed(io_b) ? $signed(2'sh1) : $signed(2'sh0); // @[Alu.scala 68:20]
  wire [1:0] _GEN_0 = 3'h7 == io_op ? $signed(_result_T_15) : $signed(2'sh0); // @[Alu.scala 21:10 35:17 68:14]
  wire [1:0] _GEN_1 = 3'h6 == io_op ? $signed(_result_T_13) : $signed(_GEN_0); // @[Alu.scala 35:17 65:14]
  wire [3:0] _GEN_2 = 3'h5 == io_op ? $signed(_result_T_11) : $signed({{2{_GEN_1[1]}},_GEN_1}); // @[Alu.scala 35:17 62:14]
  wire [3:0] _GEN_3 = 3'h4 == io_op ? $signed(_result_T_9) : $signed(_GEN_2); // @[Alu.scala 35:17 59:14]
  wire [3:0] _GEN_4 = 3'h3 == io_op ? $signed(_result_T_7) : $signed(_GEN_3); // @[Alu.scala 35:17 56:14]
  wire [3:0] _GEN_5 = 3'h2 == io_op ? $signed(_result_T_5) : $signed(_GEN_4); // @[Alu.scala 35:17 53:14]
  wire [3:0] _GEN_6 = 3'h1 == io_op ? $signed(_result_T_3) : $signed(_GEN_5); // @[Alu.scala 35:17 46:14]
  wire [3:0] result = 3'h0 == io_op ? $signed(_result_T_1) : $signed(_GEN_6); // @[Alu.scala 35:17 38:14]
  wire  _overflow_T_5 = io_a[3] != result[3]; // @[Alu.scala 42:53]
  wire  _GEN_7 = 3'h1 == io_op & diff[4]; // @[Alu.scala 35:17 47:13 22:9]
  wire  _GEN_8 = 3'h1 == io_op & (io_a[3] != io_b[3] & _overflow_T_5); // @[Alu.scala 23:12 35:17 50:16]
  assign io_carry = 3'h0 == io_op ? sum[4] : _GEN_7; // @[Alu.scala 35:17 39:13]
  assign io_zero = $signed(result) == 4'sh0; // @[Alu.scala 75:22]
  assign io_overflow = 3'h0 == io_op ? io_a[3] == io_b[3] & io_a[3] != result[3] : _GEN_8; // @[Alu.scala 35:17 42:16]
  assign io_result = 3'h0 == io_op ? $signed(_result_T_1) : $signed(_GEN_6); // @[Alu.scala 35:17 38:14]
endmodule
