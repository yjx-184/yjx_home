module Timing(
  input  [3:0] io_in,
  output [7:0] io_seg
);
  wire [7:0] _GEN_0 = io_in == 4'hf ? 8'h71 : 8'hff; // @[Timing.scala 28:{36,45} 29:25]
  wire [7:0] _GEN_1 = io_in == 4'he ? 8'h61 : _GEN_0; // @[Timing.scala 27:{36,45}]
  wire [7:0] _GEN_2 = io_in == 4'hd ? 8'h85 : _GEN_1; // @[Timing.scala 26:{36,45}]
  wire [7:0] _GEN_3 = io_in == 4'hc ? 8'h63 : _GEN_2; // @[Timing.scala 25:{36,45}]
  wire [7:0] _GEN_4 = io_in == 4'hb ? 8'hc1 : _GEN_3; // @[Timing.scala 24:{36,45}]
  wire [7:0] _GEN_5 = io_in == 4'ha ? 8'h11 : _GEN_4; // @[Timing.scala 23:{36,45}]
  wire [7:0] _GEN_6 = io_in == 4'h9 ? 8'h9 : _GEN_5; // @[Timing.scala 22:{36,45}]
  wire [7:0] _GEN_7 = io_in == 4'h8 ? 8'h1 : _GEN_6; // @[Timing.scala 21:{36,45}]
  wire [7:0] _GEN_8 = io_in == 4'h7 ? 8'h1f : _GEN_7; // @[Timing.scala 20:{36,45}]
  wire [7:0] _GEN_9 = io_in == 4'h6 ? 8'h41 : _GEN_8; // @[Timing.scala 19:{36,45}]
  wire [7:0] _GEN_10 = io_in == 4'h5 ? 8'h49 : _GEN_9; // @[Timing.scala 18:{36,45}]
  wire [7:0] _GEN_11 = io_in == 4'h4 ? 8'h99 : _GEN_10; // @[Timing.scala 17:{36,45}]
  wire [7:0] _GEN_12 = io_in == 4'h3 ? 8'hd : _GEN_11; // @[Timing.scala 16:{36,45}]
  wire [7:0] _GEN_13 = io_in == 4'h2 ? 8'h25 : _GEN_12; // @[Timing.scala 15:{36,45}]
  wire [7:0] _GEN_14 = io_in == 4'h1 ? 8'h9f : _GEN_13; // @[Timing.scala 14:{36,45}]
  assign io_seg = io_in == 4'h0 ? 8'h3 : _GEN_14; // @[Timing.scala 13:{29,38}]
endmodule
module Top(
  input        clock,
  input        reset,
  output [7:0] io_seg
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire [3:0] timing_io_in; // @[Timing.scala 62:22]
  wire [7:0] timing_io_seg; // @[Timing.scala 62:22]
  reg [3:0] counter4; // @[Timing.scala 39:25]
  reg [26:0] secCounter; // @[Timing.scala 44:27]
  wire [25:0] _T_1 = 26'h2faf080 - 26'h1; // @[Timing.scala 49:34]
  wire [26:0] _GEN_3 = {{1'd0}, _T_1}; // @[Timing.scala 49:19]
  wire  tick = secCounter == _GEN_3; // @[Timing.scala 49:19]
  wire [26:0] _secCounter_T_1 = secCounter + 27'h1; // @[Timing.scala 53:30]
  wire [3:0] _counter4_T_1 = counter4 + 4'h1; // @[Timing.scala 58:26]
  Timing timing ( // @[Timing.scala 62:22]
    .io_in(timing_io_in),
    .io_seg(timing_io_seg)
  );
  assign io_seg = timing_io_seg; // @[Timing.scala 64:10]
  assign timing_io_in = counter4; // @[Timing.scala 63:16]
  always @(posedge clock) begin
    if (reset) begin // @[Timing.scala 39:25]
      counter4 <= 4'h0; // @[Timing.scala 39:25]
    end else if (tick) begin // @[Timing.scala 57:14]
      counter4 <= _counter4_T_1; // @[Timing.scala 58:14]
    end
    if (reset) begin // @[Timing.scala 44:27]
      secCounter <= 27'h0; // @[Timing.scala 44:27]
    end else if (tick) begin // @[Timing.scala 49:41]
      secCounter <= 27'h0; // @[Timing.scala 50:16]
    end else begin
      secCounter <= _secCounter_T_1; // @[Timing.scala 53:16]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  counter4 = _RAND_0[3:0];
  _RAND_1 = {1{`RANDOM}};
  secCounter = _RAND_1[26:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
