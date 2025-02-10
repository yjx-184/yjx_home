module Top(
  input        clock,
  input        reset,
  input        io_minorcar, // @[src/main/scala/Top.scala 6:14]
  input        io_timestate, // @[src/main/scala/Top.scala 6:14]
  output [1:0] io_minorLight, // @[src/main/scala/Top.scala 6:14]
  output [1:0] io_mainLight // @[src/main/scala/Top.scala 6:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [2:0] stateReg; // @[src/main/scala/Top.scala 18:25]
  wire [2:0] _GEN_2 = io_timestate ? 3'h3 : stateReg; // @[src/main/scala/Top.scala 43:26 44:18 18:25]
  wire [2:0] _GEN_3 = io_timestate & ~io_minorcar ? 3'h4 : stateReg; // @[src/main/scala/Top.scala 50:54 51:18 18:25]
  wire [2:0] _GEN_4 = io_timestate ? 3'h0 : stateReg; // @[src/main/scala/Top.scala 57:26 58:18 18:25]
  wire [2:0] _GEN_7 = 3'h4 == stateReg ? _GEN_4 : stateReg; // @[src/main/scala/Top.scala 25:21 18:25]
  wire [1:0] _GEN_9 = 3'h3 == stateReg ? 2'h2 : {{1'd0}, 3'h4 == stateReg}; // @[src/main/scala/Top.scala 25:21 49:21]
  wire [2:0] _GEN_10 = 3'h3 == stateReg ? _GEN_3 : _GEN_7; // @[src/main/scala/Top.scala 25:21]
  wire [1:0] _GEN_12 = 3'h2 == stateReg ? 2'h0 : _GEN_9; // @[src/main/scala/Top.scala 25:21 42:21]
  wire [1:0] _GEN_15 = 3'h1 == stateReg ? 2'h0 : _GEN_12; // @[src/main/scala/Top.scala 25:21 35:21]
  assign io_minorLight = 3'h0 == stateReg ? 2'h0 : _GEN_15; // @[src/main/scala/Top.scala 25:21 28:21]
  assign io_mainLight = 3'h0 == stateReg ? 2'h2 : {{1'd0}, 3'h1 == stateReg}; // @[src/main/scala/Top.scala 25:21 27:20]
  always @(posedge clock) begin
    if (reset) begin // @[src/main/scala/Top.scala 18:25]
      stateReg <= 3'h0; // @[src/main/scala/Top.scala 18:25]
    end else if (3'h0 == stateReg) begin // @[src/main/scala/Top.scala 25:21]
      if (io_minorcar) begin // @[src/main/scala/Top.scala 29:36]
        stateReg <= 3'h1; // @[src/main/scala/Top.scala 30:18]
      end
    end else if (3'h1 == stateReg) begin // @[src/main/scala/Top.scala 25:21]
      if (io_timestate) begin // @[src/main/scala/Top.scala 36:26]
        stateReg <= 3'h2; // @[src/main/scala/Top.scala 37:18]
      end
    end else if (3'h2 == stateReg) begin // @[src/main/scala/Top.scala 25:21]
      stateReg <= _GEN_2;
    end else begin
      stateReg <= _GEN_10;
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
  stateReg = _RAND_0[2:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
