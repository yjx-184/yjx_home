module Npc(
  input         clock,
  input         reset,
  output [31:0] io_pc,
  output [31:0] io_inst,
  output        io_exit
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire [31:0] ebreakDetector_inst; // @[Npc.scala 33:30]
  wire [31:0] ebreakDetector_pc; // @[Npc.scala 33:30]
  wire  ebreakDetector_exit; // @[Npc.scala 33:30]
  reg [31:0] pc; // @[Npc.scala 27:19]
  reg [31:0] inst; // @[Npc.scala 28:21]
  wire [31:0] _pc_T_1 = pc + 32'h4; // @[Npc.scala 42:14]
  wire [31:0] _inst_T_1 = pc - 32'h80000000; // @[Npc.scala 43:25]
  wire [31:0] _GEN_1 = 3'h1 == _inst_T_1[4:2] ? 32'h300113 : 32'h200093; // @[Npc.scala 43:{10,10}]
  wire [31:0] _GEN_2 = 3'h2 == _inst_T_1[4:2] ? 32'h408193 : _GEN_1; // @[Npc.scala 43:{10,10}]
  EbreakDetector ebreakDetector ( // @[Npc.scala 33:30]
    .inst(ebreakDetector_inst),
    .pc(ebreakDetector_pc),
    .exit(ebreakDetector_exit)
  );
  assign io_pc = pc; // @[Npc.scala 29:9]
  assign io_inst = inst; // @[Npc.scala 30:11]
  assign io_exit = ebreakDetector_exit; // @[Npc.scala 38:11]
  assign ebreakDetector_inst = inst; // @[Npc.scala 34:26]
  assign ebreakDetector_pc = pc; // @[Npc.scala 35:24]
  always @(posedge clock) begin
    if (reset) begin // @[Npc.scala 27:19]
      pc <= 32'h0; // @[Npc.scala 27:19]
    end else if (~io_exit) begin // @[Npc.scala 41:18]
      pc <= _pc_T_1; // @[Npc.scala 42:8]
    end
    if (reset) begin // @[Npc.scala 28:21]
      inst <= 32'h0; // @[Npc.scala 28:21]
    end else if (~io_exit) begin // @[Npc.scala 41:18]
      if (3'h4 == _inst_T_1[4:2]) begin // @[Npc.scala 43:10]
        inst <= 32'h100073; // @[Npc.scala 43:10]
      end else if (3'h3 == _inst_T_1[4:2]) begin // @[Npc.scala 43:10]
        inst <= 32'h510213; // @[Npc.scala 43:10]
      end else begin
        inst <= _GEN_2;
      end
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
  pc = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  inst = _RAND_1[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
