module ButtonDebounce(
  input   clock,
  input   reset,
  input   io_reset,
  input   io_btn,
  output  io_btn_clk
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg  btnDebReg; // @[Top.scala 45:26]
  reg  btnLast; // @[Top.scala 46:24]
  wire  _T_3 = io_btn & ~btnLast; // @[Top.scala 54:28]
  assign io_btn_clk = btnDebReg; // @[Top.scala 64:14]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 45:26]
      btnDebReg <= 1'h0; // @[Top.scala 45:26]
    end else if (~io_reset) begin // @[Top.scala 49:30]
      btnDebReg <= 1'h0; // @[Top.scala 50:15]
    end else begin
      btnDebReg <= _T_3;
    end
    if (reset) begin // @[Top.scala 46:24]
      btnLast <= 1'h0; // @[Top.scala 46:24]
    end else if (~io_reset) begin // @[Top.scala 49:30]
      btnLast <= 1'h0; // @[Top.scala 51:13]
    end else begin
      btnLast <= io_btn; // @[Top.scala 60:13]
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
  btnDebReg = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  btnLast = _RAND_1[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
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
  reg [7:0] shiftreg; // @[Top.scala 75:26]
  wire  lfsr = shiftreg[4] ^ shiftreg[3] ^ shiftreg[2] ^ shiftreg[0]; // @[Top.scala 78:54]
  wire [7:0] _shiftreg_T_1 = {lfsr,shiftreg[7:1]}; // @[Cat.scala 31:58]
  assign io_random_out = shiftreg; // @[Top.scala 88:17]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 75:26]
      shiftreg <= 8'hff; // @[Top.scala 75:26]
    end else if (~io_reset) begin // @[Top.scala 81:30]
      shiftreg <= 8'hff; // @[Top.scala 82:14]
    end else if (io_clk) begin // @[Top.scala 83:23]
      shiftreg <= _shiftreg_T_1; // @[Top.scala 84:14]
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
  input        io_reset,
  output [7:0] io_seg
);
  wire [7:0] _GEN_0 = 8'hf == io_in ? 8'h71 : 8'hff; // @[Top.scala 117:10 123:19 139:25]
  wire [7:0] _GEN_1 = 8'he == io_in ? 8'h61 : _GEN_0; // @[Top.scala 123:19 138:25]
  wire [7:0] _GEN_2 = 8'hd == io_in ? 8'h85 : _GEN_1; // @[Top.scala 123:19 137:25]
  wire [7:0] _GEN_3 = 8'hc == io_in ? 8'h63 : _GEN_2; // @[Top.scala 123:19 136:25]
  wire [7:0] _GEN_4 = 8'hb == io_in ? 8'hc1 : _GEN_3; // @[Top.scala 123:19 135:25]
  wire [7:0] _GEN_5 = 8'ha == io_in ? 8'h11 : _GEN_4; // @[Top.scala 123:19 134:25]
  wire [7:0] _GEN_6 = 8'h9 == io_in ? 8'h9 : _GEN_5; // @[Top.scala 123:19 133:24]
  wire [7:0] _GEN_7 = 8'h8 == io_in ? 8'h1 : _GEN_6; // @[Top.scala 123:19 132:24]
  wire [7:0] _GEN_8 = 8'h7 == io_in ? 8'h1f : _GEN_7; // @[Top.scala 123:19 131:24]
  wire [7:0] _GEN_9 = 8'h6 == io_in ? 8'h41 : _GEN_8; // @[Top.scala 123:19 130:24]
  wire [7:0] _GEN_10 = 8'h5 == io_in ? 8'h49 : _GEN_9; // @[Top.scala 123:19 129:24]
  wire [7:0] _GEN_11 = 8'h4 == io_in ? 8'h99 : _GEN_10; // @[Top.scala 123:19 128:24]
  wire [7:0] _GEN_12 = 8'h3 == io_in ? 8'hd : _GEN_11; // @[Top.scala 123:19 127:24]
  wire [7:0] _GEN_13 = 8'h2 == io_in ? 8'h25 : _GEN_12; // @[Top.scala 123:19 126:24]
  wire [7:0] _GEN_14 = 8'h1 == io_in ? 8'h9f : _GEN_13; // @[Top.scala 123:19 125:24]
  wire [7:0] _GEN_15 = 8'h0 == io_in ? 8'h3 : _GEN_14; // @[Top.scala 123:19 124:24]
  assign io_seg = ~io_reset ? 8'hff : _GEN_15; // @[Top.scala 119:30 120:12]
endmodule
module Top(
  input        clock,
  input        reset,
  input        io_clk,
  input        io_reset,
  input        io_btn,
  output [7:0] io_seg_out
);
  wire  buttonDebounce_clock; // @[Top.scala 13:30]
  wire  buttonDebounce_reset; // @[Top.scala 13:30]
  wire  buttonDebounce_io_reset; // @[Top.scala 13:30]
  wire  buttonDebounce_io_btn; // @[Top.scala 13:30]
  wire  buttonDebounce_io_btn_clk; // @[Top.scala 13:30]
  wire  shiftreg_clock; // @[Top.scala 15:24]
  wire  shiftreg_reset; // @[Top.scala 15:24]
  wire  shiftreg_io_clk; // @[Top.scala 15:24]
  wire  shiftreg_io_reset; // @[Top.scala 15:24]
  wire [7:0] shiftreg_io_random_out; // @[Top.scala 15:24]
  wire [7:0] seg_io_in; // @[Top.scala 17:19]
  wire  seg_io_reset; // @[Top.scala 17:19]
  wire [7:0] seg_io_seg; // @[Top.scala 17:19]
  ButtonDebounce buttonDebounce ( // @[Top.scala 13:30]
    .clock(buttonDebounce_clock),
    .reset(buttonDebounce_reset),
    .io_reset(buttonDebounce_io_reset),
    .io_btn(buttonDebounce_io_btn),
    .io_btn_clk(buttonDebounce_io_btn_clk)
  );
  Shiftreg shiftreg ( // @[Top.scala 15:24]
    .clock(shiftreg_clock),
    .reset(shiftreg_reset),
    .io_clk(shiftreg_io_clk),
    .io_reset(shiftreg_io_reset),
    .io_random_out(shiftreg_io_random_out)
  );
  Seg seg ( // @[Top.scala 17:19]
    .io_in(seg_io_in),
    .io_reset(seg_io_reset),
    .io_seg(seg_io_seg)
  );
  assign io_seg_out = seg_io_seg; // @[Top.scala 34:14]
  assign buttonDebounce_clock = clock;
  assign buttonDebounce_reset = reset;
  assign buttonDebounce_io_reset = io_reset; // @[Top.scala 21:27]
  assign buttonDebounce_io_btn = io_btn; // @[Top.scala 22:25]
  assign shiftreg_clock = clock;
  assign shiftreg_reset = reset;
  assign shiftreg_io_clk = buttonDebounce_io_btn_clk; // @[Top.scala 29:19]
  assign shiftreg_io_reset = io_reset; // @[Top.scala 30:21]
  assign seg_io_in = {{4'd0}, shiftreg_io_random_out[3:0]}; // @[Top.scala 25:13]
  assign seg_io_reset = io_reset; // @[Top.scala 31:16]
endmodule
