module Shiftreg(
  input        clock,
  input        reset,
  input        io_clk,
  input        io_reset,
  output [7:0] io_random_out
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] shiftreg; // @[Top.scala 34:26]
  wire  lfsr = shiftreg[4] ^ shiftreg[3] ^ shiftreg[2] ^ shiftreg[0]; // @[Top.scala 37:54]
  wire [7:0] _shiftreg_T_1 = {lfsr,shiftreg[7:1]}; // @[Cat.scala 31:58]
  assign io_random_out = shiftreg; // @[Top.scala 47:17]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 34:26]
      shiftreg <= 8'hff; // @[Top.scala 34:26]
    end else if (io_reset) begin // @[Top.scala 40:18]
      shiftreg <= 8'hff; // @[Top.scala 41:14]
    end else if (io_clk) begin // @[Top.scala 42:23]
      shiftreg <= _shiftreg_T_1; // @[Top.scala 43:14]
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
  shiftreg = _RAND_0[7:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Seg(
  input  [7:0] io_in,
  output [7:0] io_seg
);
  wire [7:0] _GEN_0 = 8'hf == io_in ? 8'h71 : 8'h0; // @[Top.scala 75:10 77:17 93:23]
  wire [7:0] _GEN_1 = 8'he == io_in ? 8'h61 : _GEN_0; // @[Top.scala 77:17 92:23]
  wire [7:0] _GEN_2 = 8'hd == io_in ? 8'h85 : _GEN_1; // @[Top.scala 77:17 91:23]
  wire [7:0] _GEN_3 = 8'hc == io_in ? 8'h63 : _GEN_2; // @[Top.scala 77:17 90:23]
  wire [7:0] _GEN_4 = 8'hb == io_in ? 8'hc1 : _GEN_3; // @[Top.scala 77:17 89:23]
  wire [7:0] _GEN_5 = 8'ha == io_in ? 8'h11 : _GEN_4; // @[Top.scala 77:17 88:23]
  wire [7:0] _GEN_6 = 8'h9 == io_in ? 8'h9 : _GEN_5; // @[Top.scala 77:17 87:22]
  wire [7:0] _GEN_7 = 8'h8 == io_in ? 8'h1 : _GEN_6; // @[Top.scala 77:17 86:22]
  wire [7:0] _GEN_8 = 8'h7 == io_in ? 8'h1f : _GEN_7; // @[Top.scala 77:17 85:22]
  wire [7:0] _GEN_9 = 8'h6 == io_in ? 8'h41 : _GEN_8; // @[Top.scala 77:17 84:22]
  wire [7:0] _GEN_10 = 8'h5 == io_in ? 8'h49 : _GEN_9; // @[Top.scala 77:17 83:22]
  wire [7:0] _GEN_11 = 8'h4 == io_in ? 8'h99 : _GEN_10; // @[Top.scala 77:17 82:22]
  wire [7:0] _GEN_12 = 8'h3 == io_in ? 8'hd : _GEN_11; // @[Top.scala 77:17 81:22]
  wire [7:0] _GEN_13 = 8'h2 == io_in ? 8'h25 : _GEN_12; // @[Top.scala 77:17 80:22]
  wire [7:0] _GEN_14 = 8'h1 == io_in ? 8'h9f : _GEN_13; // @[Top.scala 77:17 79:22]
  assign io_seg = 8'h0 == io_in ? 8'h3 : _GEN_14; // @[Top.scala 77:17 78:22]
endmodule
module Top(
  input        clock,
  input        reset,
  input        io_clk,
  input        io_reset,
  output [7:0] io_seg_out
);
  wire  shiftreg_clock; // @[Top.scala 11:24]
  wire  shiftreg_reset; // @[Top.scala 11:24]
  wire  shiftreg_io_clk; // @[Top.scala 11:24]
  wire  shiftreg_io_reset; // @[Top.scala 11:24]
  wire [7:0] shiftreg_io_random_out; // @[Top.scala 11:24]
  wire [7:0] seg_io_in; // @[Top.scala 13:19]
  wire [7:0] seg_io_seg; // @[Top.scala 13:19]
  Shiftreg shiftreg ( // @[Top.scala 11:24]
    .clock(shiftreg_clock),
    .reset(shiftreg_reset),
    .io_clk(shiftreg_io_clk),
    .io_reset(shiftreg_io_reset),
    .io_random_out(shiftreg_io_random_out)
  );
  Seg seg ( // @[Top.scala 13:19]
    .io_in(seg_io_in),
    .io_seg(seg_io_seg)
  );
  assign io_seg_out = seg_io_seg; // @[Top.scala 23:14]
  assign shiftreg_clock = clock;
  assign shiftreg_reset = reset;
  assign shiftreg_io_clk = io_clk; // @[Top.scala 19:19]
  assign shiftreg_io_reset = io_reset; // @[Top.scala 20:21]
  assign seg_io_in = {{4'd0}, shiftreg_io_random_out[3:0]}; // @[Top.scala 16:13]
endmodule
