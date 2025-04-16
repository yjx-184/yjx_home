module ImmGen(
  input  [31:0] io_instin,
  input  [2:0]  io_immop,
  output [31:0] io_immout
);
  wire [19:0] _immI_T_2 = io_instin[31] ? 20'hfffff : 20'h0; // @[Bitwise.scala 74:12]
  wire [31:0] immI = {_immI_T_2,io_instin[31:20]}; // @[ImmGen.scala 12:64]
  wire [30:0] immS = {_immI_T_2,io_instin[30:25],io_instin[11:7]}; // @[ImmGen.scala 13:82]
  wire [31:0] immB = {_immI_T_2,io_instin[7],io_instin[30:25],io_instin[11:8],1'h0}; // @[ImmGen.scala 14:106]
  wire [31:0] immU = {io_instin[31:12],12'h0}; // @[ImmGen.scala 15:57]
  wire [11:0] _immJ_T_2 = io_instin[31] ? 12'hfff : 12'h0; // @[Bitwise.scala 74:12]
  wire [31:0] immJ = {_immJ_T_2,io_instin[19:12],io_instin[20],io_instin[30:21],1'h0}; // @[ImmGen.scala 16:108]
  wire [31:0] _io_immout_T_1 = 3'h0 == io_immop ? $signed(immI) : $signed(32'sh0); // @[Mux.scala 81:58]
  wire [31:0] _io_immout_T_3 = 3'h1 == io_immop ? $signed({{1{immS[30]}},immS}) : $signed(_io_immout_T_1); // @[Mux.scala 81:58]
  wire [31:0] _io_immout_T_5 = 3'h2 == io_immop ? $signed(immB) : $signed(_io_immout_T_3); // @[Mux.scala 81:58]
  wire [31:0] _io_immout_T_7 = 3'h3 == io_immop ? $signed(immU) : $signed(_io_immout_T_5); // @[Mux.scala 81:58]
  assign io_immout = 3'h4 == io_immop ? $signed(immJ) : $signed(_io_immout_T_7); // @[Mux.scala 81:58]
endmodule
module RegFile(
  input         clock,
  input         reset,
  input  [3:0]  io_ra,
  input  [3:0]  io_rb,
  input  [3:0]  io_rw,
  input  [31:0] io_busw,
  input         io_regwr,
  output [31:0] io_busa,
  output [31:0] io_busb,
  output [31:0] io_regsout_0,
  output [31:0] io_regsout_1,
  output [31:0] io_regsout_2,
  output [31:0] io_regsout_3,
  output [31:0] io_regsout_4,
  output [31:0] io_regsout_5,
  output [31:0] io_regsout_6,
  output [31:0] io_regsout_7,
  output [31:0] io_regsout_8,
  output [31:0] io_regsout_9,
  output [31:0] io_regsout_10,
  output [31:0] io_regsout_11,
  output [31:0] io_regsout_12,
  output [31:0] io_regsout_13,
  output [31:0] io_regsout_14,
  output [31:0] io_regsout_15
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] regs_0; // @[RegFile.scala 20:23]
  reg [31:0] regs_1; // @[RegFile.scala 20:23]
  reg [31:0] regs_2; // @[RegFile.scala 20:23]
  reg [31:0] regs_3; // @[RegFile.scala 20:23]
  reg [31:0] regs_4; // @[RegFile.scala 20:23]
  reg [31:0] regs_5; // @[RegFile.scala 20:23]
  reg [31:0] regs_6; // @[RegFile.scala 20:23]
  reg [31:0] regs_7; // @[RegFile.scala 20:23]
  reg [31:0] regs_8; // @[RegFile.scala 20:23]
  reg [31:0] regs_9; // @[RegFile.scala 20:23]
  reg [31:0] regs_10; // @[RegFile.scala 20:23]
  reg [31:0] regs_11; // @[RegFile.scala 20:23]
  reg [31:0] regs_12; // @[RegFile.scala 20:23]
  reg [31:0] regs_13; // @[RegFile.scala 20:23]
  reg [31:0] regs_14; // @[RegFile.scala 20:23]
  reg [31:0] regs_15; // @[RegFile.scala 20:23]
  wire [31:0] _GEN_1 = 4'h1 == io_ra ? regs_1 : regs_0; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_2 = 4'h2 == io_ra ? regs_2 : _GEN_1; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_3 = 4'h3 == io_ra ? regs_3 : _GEN_2; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_4 = 4'h4 == io_ra ? regs_4 : _GEN_3; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_5 = 4'h5 == io_ra ? regs_5 : _GEN_4; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_6 = 4'h6 == io_ra ? regs_6 : _GEN_5; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_7 = 4'h7 == io_ra ? regs_7 : _GEN_6; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_8 = 4'h8 == io_ra ? regs_8 : _GEN_7; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_9 = 4'h9 == io_ra ? regs_9 : _GEN_8; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_10 = 4'ha == io_ra ? regs_10 : _GEN_9; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_11 = 4'hb == io_ra ? regs_11 : _GEN_10; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_12 = 4'hc == io_ra ? regs_12 : _GEN_11; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_13 = 4'hd == io_ra ? regs_13 : _GEN_12; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_14 = 4'he == io_ra ? regs_14 : _GEN_13; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_15 = 4'hf == io_ra ? regs_15 : _GEN_14; // @[RegFile.scala 23:{19,19}]
  wire [31:0] _GEN_17 = 4'h1 == io_rb ? regs_1 : regs_0; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_18 = 4'h2 == io_rb ? regs_2 : _GEN_17; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_19 = 4'h3 == io_rb ? regs_3 : _GEN_18; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_20 = 4'h4 == io_rb ? regs_4 : _GEN_19; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_21 = 4'h5 == io_rb ? regs_5 : _GEN_20; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_22 = 4'h6 == io_rb ? regs_6 : _GEN_21; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_23 = 4'h7 == io_rb ? regs_7 : _GEN_22; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_24 = 4'h8 == io_rb ? regs_8 : _GEN_23; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_25 = 4'h9 == io_rb ? regs_9 : _GEN_24; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_26 = 4'ha == io_rb ? regs_10 : _GEN_25; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_27 = 4'hb == io_rb ? regs_11 : _GEN_26; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_28 = 4'hc == io_rb ? regs_12 : _GEN_27; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_29 = 4'hd == io_rb ? regs_13 : _GEN_28; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_30 = 4'he == io_rb ? regs_14 : _GEN_29; // @[RegFile.scala 24:{19,19}]
  wire [31:0] _GEN_31 = 4'hf == io_rb ? regs_15 : _GEN_30; // @[RegFile.scala 24:{19,19}]
  assign io_busa = io_ra == 4'h0 ? 32'h0 : _GEN_15; // @[RegFile.scala 23:19]
  assign io_busb = io_rb == 4'h0 ? 32'h0 : _GEN_31; // @[RegFile.scala 24:19]
  assign io_regsout_0 = regs_0; // @[RegFile.scala 31:16]
  assign io_regsout_1 = regs_1; // @[RegFile.scala 31:16]
  assign io_regsout_2 = regs_2; // @[RegFile.scala 31:16]
  assign io_regsout_3 = regs_3; // @[RegFile.scala 31:16]
  assign io_regsout_4 = regs_4; // @[RegFile.scala 31:16]
  assign io_regsout_5 = regs_5; // @[RegFile.scala 31:16]
  assign io_regsout_6 = regs_6; // @[RegFile.scala 31:16]
  assign io_regsout_7 = regs_7; // @[RegFile.scala 31:16]
  assign io_regsout_8 = regs_8; // @[RegFile.scala 31:16]
  assign io_regsout_9 = regs_9; // @[RegFile.scala 31:16]
  assign io_regsout_10 = regs_10; // @[RegFile.scala 31:16]
  assign io_regsout_11 = regs_11; // @[RegFile.scala 31:16]
  assign io_regsout_12 = regs_12; // @[RegFile.scala 31:16]
  assign io_regsout_13 = regs_13; // @[RegFile.scala 31:16]
  assign io_regsout_14 = regs_14; // @[RegFile.scala 31:16]
  assign io_regsout_15 = regs_15; // @[RegFile.scala 31:16]
  always @(posedge clock) begin
    if (reset) begin // @[RegFile.scala 20:23]
      regs_0 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'h0 == io_rw) begin // @[RegFile.scala 28:19]
        regs_0 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_1 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'h1 == io_rw) begin // @[RegFile.scala 28:19]
        regs_1 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_2 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'h2 == io_rw) begin // @[RegFile.scala 28:19]
        regs_2 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_3 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'h3 == io_rw) begin // @[RegFile.scala 28:19]
        regs_3 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_4 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'h4 == io_rw) begin // @[RegFile.scala 28:19]
        regs_4 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_5 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'h5 == io_rw) begin // @[RegFile.scala 28:19]
        regs_5 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_6 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'h6 == io_rw) begin // @[RegFile.scala 28:19]
        regs_6 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_7 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'h7 == io_rw) begin // @[RegFile.scala 28:19]
        regs_7 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_8 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'h8 == io_rw) begin // @[RegFile.scala 28:19]
        regs_8 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_9 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'h9 == io_rw) begin // @[RegFile.scala 28:19]
        regs_9 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_10 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'ha == io_rw) begin // @[RegFile.scala 28:19]
        regs_10 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_11 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'hb == io_rw) begin // @[RegFile.scala 28:19]
        regs_11 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_12 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'hc == io_rw) begin // @[RegFile.scala 28:19]
        regs_12 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_13 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'hd == io_rw) begin // @[RegFile.scala 28:19]
        regs_13 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_14 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'he == io_rw) begin // @[RegFile.scala 28:19]
        regs_14 <= io_busw; // @[RegFile.scala 28:19]
      end
    end
    if (reset) begin // @[RegFile.scala 20:23]
      regs_15 <= 32'h0; // @[RegFile.scala 20:23]
    end else if (io_regwr & io_rw != 4'h0) begin // @[RegFile.scala 27:44]
      if (4'hf == io_rw) begin // @[RegFile.scala 28:19]
        regs_15 <= io_busw; // @[RegFile.scala 28:19]
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
  regs_0 = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  regs_1 = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  regs_2 = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  regs_3 = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  regs_4 = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  regs_5 = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  regs_6 = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  regs_7 = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  regs_8 = _RAND_8[31:0];
  _RAND_9 = {1{`RANDOM}};
  regs_9 = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  regs_10 = _RAND_10[31:0];
  _RAND_11 = {1{`RANDOM}};
  regs_11 = _RAND_11[31:0];
  _RAND_12 = {1{`RANDOM}};
  regs_12 = _RAND_12[31:0];
  _RAND_13 = {1{`RANDOM}};
  regs_13 = _RAND_13[31:0];
  _RAND_14 = {1{`RANDOM}};
  regs_14 = _RAND_14[31:0];
  _RAND_15 = {1{`RANDOM}};
  regs_15 = _RAND_15[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module ALU(
  input  [31:0] io_rs1,
  input  [31:0] io_rs2,
  input  [31:0] io_imm,
  input  [31:0] io_pc,
  input         io_alua,
  input  [1:0]  io_alub,
  input  [3:0]  io_aluctr,
  output        io_less,
  output        io_zero,
  output [31:0] io_result
);
  wire [31:0] aluA = io_alua ? io_pc : io_rs1; // @[ALU.scala 24:19]
  wire [31:0] _aluB_T_2 = 2'h1 == io_alub ? io_imm : io_rs2; // @[Mux.scala 81:58]
  wire [31:0] aluB = 2'h2 == io_alub ? 32'h4 : _aluB_T_2; // @[Mux.scala 81:58]
  wire  isSub = io_aluctr == 4'h8 | io_aluctr == 4'h2; // @[ALU.scala 34:41]
  wire [31:0] _operandB_T = ~aluB; // @[ALU.scala 35:31]
  wire [31:0] operandB = isSub ? _operandB_T : aluB; // @[ALU.scala 35:23]
  wire [31:0] _sum_T_1 = aluA + operandB; // @[ALU.scala 37:20]
  wire [31:0] _GEN_0 = {{31'd0}, isSub}; // @[ALU.scala 37:31]
  wire [31:0] sum = _sum_T_1 + _GEN_0; // @[ALU.scala 37:31]
  wire  overflow = aluA[31] != aluB[31] & sum[31] != aluA[31]; // @[ALU.scala 39:44]
  wire  slt = sum[31] ^ overflow; // @[ALU.scala 42:23]
  wire  sltu = aluA < aluB; // @[ALU.scala 43:21]
  wire [62:0] _GEN_1 = {{31'd0}, aluA}; // @[ALU.scala 44:20]
  wire [62:0] sll = _GEN_1 << aluB[4:0]; // @[ALU.scala 44:20]
  wire [31:0] srl = aluA >> aluB[4:0]; // @[ALU.scala 45:20]
  wire [31:0] _sra_T = io_alua ? io_pc : io_rs1; // @[ALU.scala 46:21]
  wire [31:0] sra = $signed(_sra_T) >>> aluB[4:0]; // @[ALU.scala 46:43]
  wire [31:0] xor_ = aluA ^ aluB; // @[ALU.scala 47:20]
  wire [31:0] or_ = aluA | aluB; // @[ALU.scala 48:20]
  wire [31:0] and_ = aluA & aluB; // @[ALU.scala 49:20]
  wire [31:0] _io_result_T_1 = 4'h0 == io_aluctr ? sum : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_3 = 4'h8 == io_aluctr ? sum : _io_result_T_1; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_5 = 4'h2 == io_aluctr ? {{31'd0}, slt} : _io_result_T_3; // @[Mux.scala 81:58]
  wire [31:0] _io_result_T_7 = 4'ha == io_aluctr ? {{31'd0}, sltu} : _io_result_T_5; // @[Mux.scala 81:58]
  wire [62:0] _io_result_T_9 = 4'h1 == io_aluctr ? sll : {{31'd0}, _io_result_T_7}; // @[Mux.scala 81:58]
  wire [62:0] _io_result_T_11 = 4'h5 == io_aluctr ? {{31'd0}, srl} : _io_result_T_9; // @[Mux.scala 81:58]
  wire [62:0] _io_result_T_13 = 4'hd == io_aluctr ? {{31'd0}, sra} : _io_result_T_11; // @[Mux.scala 81:58]
  wire [62:0] _io_result_T_15 = 4'h4 == io_aluctr ? {{31'd0}, xor_} : _io_result_T_13; // @[Mux.scala 81:58]
  wire [62:0] _io_result_T_17 = 4'h6 == io_aluctr ? {{31'd0}, or_} : _io_result_T_15; // @[Mux.scala 81:58]
  wire [62:0] _io_result_T_19 = 4'h7 == io_aluctr ? {{31'd0}, and_} : _io_result_T_17; // @[Mux.scala 81:58]
  wire [62:0] _io_result_T_21 = 4'h3 == io_aluctr ? {{31'd0}, aluB} : _io_result_T_19; // @[Mux.scala 81:58]
  assign io_less = 4'ha == io_aluctr ? sltu : 4'h2 == io_aluctr & slt; // @[Mux.scala 81:58]
  assign io_zero = aluA == aluB; // @[ALU.scala 51:20]
  assign io_result = _io_result_T_21[31:0]; // @[ALU.scala 55:15]
endmodule
module ContrGen(
  input  [6:0] io_opcode,
  input  [2:0] io_func3,
  input  [6:0] io_func7,
  output [2:0] io_immop,
  output       io_regwr,
  output       io_alua,
  output [1:0] io_alub,
  output [3:0] io_aluctr,
  output [2:0] io_branch,
  output       io_memreg,
  output       io_memwr,
  output [2:0] io_memop,
  output [2:0] io_rdmemop
);
  wire [1:0] _io_immop_T_9 = 7'h63 == io_opcode ? 2'h2 : {{1'd0}, 7'h23 == io_opcode}; // @[Mux.scala 81:58]
  wire [1:0] _io_immop_T_11 = 7'h37 == io_opcode ? 2'h3 : _io_immop_T_9; // @[Mux.scala 81:58]
  wire [1:0] _io_immop_T_13 = 7'h17 == io_opcode ? 2'h3 : _io_immop_T_11; // @[Mux.scala 81:58]
  wire  _io_regwr_T_1 = 7'h63 == io_opcode ? 1'h0 : 1'h1; // @[Mux.scala 81:58]
  wire  _io_alua_T = io_opcode == 7'h17; // @[ContrGen.scala 49:20]
  wire  _io_alua_T_1 = io_opcode == 7'h6f; // @[ContrGen.scala 50:20]
  wire  _io_alua_T_2 = io_opcode == 7'h67; // @[ContrGen.scala 51:20]
  wire  _io_alua_T_3 = io_func3 == 3'h0; // @[ContrGen.scala 51:49]
  wire  _io_alua_T_4 = io_opcode == 7'h67 & io_func3 == 3'h0; // @[ContrGen.scala 51:37]
  wire  _io_alub_T_9 = 7'h23 == io_opcode | (7'h3 == io_opcode | (7'h13 == io_opcode | (7'h17 == io_opcode | 7'h37 ==
    io_opcode))); // @[Mux.scala 81:58]
  wire [1:0] _io_alub_T_11 = 7'h6f == io_opcode ? 2'h2 : {{1'd0}, _io_alub_T_9}; // @[Mux.scala 81:58]
  wire  _io_aluctr_T = io_opcode == 7'h37; // @[ContrGen.scala 67:20]
  wire  _io_aluctr_T_1 = io_opcode == 7'h13; // @[ContrGen.scala 69:20]
  wire  _io_aluctr_T_2 = io_func3 == 3'h2; // @[ContrGen.scala 69:49]
  wire  _io_aluctr_T_3 = io_opcode == 7'h13 & io_func3 == 3'h2; // @[ContrGen.scala 69:37]
  wire  _io_aluctr_T_5 = io_func3 == 3'h3; // @[ContrGen.scala 70:49]
  wire  _io_aluctr_T_6 = _io_aluctr_T_1 & io_func3 == 3'h3; // @[ContrGen.scala 70:37]
  wire  _io_aluctr_T_8 = io_func3 == 3'h4; // @[ContrGen.scala 71:49]
  wire  _io_aluctr_T_9 = _io_aluctr_T_1 & io_func3 == 3'h4; // @[ContrGen.scala 71:37]
  wire  _io_aluctr_T_11 = io_func3 == 3'h6; // @[ContrGen.scala 72:49]
  wire  _io_aluctr_T_12 = _io_aluctr_T_1 & io_func3 == 3'h6; // @[ContrGen.scala 72:37]
  wire  _io_aluctr_T_14 = io_func3 == 3'h7; // @[ContrGen.scala 73:49]
  wire  _io_aluctr_T_15 = _io_aluctr_T_1 & io_func3 == 3'h7; // @[ContrGen.scala 73:37]
  wire  _io_aluctr_T_17 = io_func3 == 3'h1; // @[ContrGen.scala 74:49]
  wire  _io_aluctr_T_19 = io_func7 == 7'h0; // @[ContrGen.scala 74:74]
  wire  _io_aluctr_T_20 = _io_aluctr_T_1 & io_func3 == 3'h1 & io_func7 == 7'h0; // @[ContrGen.scala 74:62]
  wire  _io_aluctr_T_22 = io_func3 == 3'h5; // @[ContrGen.scala 75:49]
  wire  _io_aluctr_T_23 = _io_aluctr_T_1 & io_func3 == 3'h5; // @[ContrGen.scala 75:37]
  wire  _io_aluctr_T_25 = _io_aluctr_T_1 & io_func3 == 3'h5 & _io_aluctr_T_19; // @[ContrGen.scala 75:62]
  wire  _io_aluctr_T_29 = io_func7 == 7'h20; // @[ContrGen.scala 76:74]
  wire  _io_aluctr_T_30 = _io_aluctr_T_23 & io_func7 == 7'h20; // @[ContrGen.scala 76:62]
  wire  _io_aluctr_T_31 = io_opcode == 7'h33; // @[ContrGen.scala 78:20]
  wire  _io_aluctr_T_35 = io_opcode == 7'h33 & _io_alua_T_3 & _io_aluctr_T_29; // @[ContrGen.scala 78:62]
  wire  _io_aluctr_T_40 = _io_aluctr_T_31 & _io_aluctr_T_17 & _io_aluctr_T_19; // @[ContrGen.scala 79:62]
  wire  _io_aluctr_T_45 = _io_aluctr_T_31 & _io_aluctr_T_2 & _io_aluctr_T_19; // @[ContrGen.scala 80:62]
  wire  _io_aluctr_T_50 = _io_aluctr_T_31 & _io_aluctr_T_5 & _io_aluctr_T_19; // @[ContrGen.scala 81:62]
  wire  _io_aluctr_T_55 = _io_aluctr_T_31 & _io_aluctr_T_8 & _io_aluctr_T_19; // @[ContrGen.scala 82:62]
  wire  _io_aluctr_T_58 = _io_aluctr_T_31 & _io_aluctr_T_22; // @[ContrGen.scala 83:37]
  wire  _io_aluctr_T_60 = _io_aluctr_T_31 & _io_aluctr_T_22 & _io_aluctr_T_19; // @[ContrGen.scala 83:62]
  wire  _io_aluctr_T_65 = _io_aluctr_T_58 & _io_aluctr_T_29; // @[ContrGen.scala 84:62]
  wire  _io_aluctr_T_70 = _io_aluctr_T_31 & _io_aluctr_T_11 & _io_aluctr_T_19; // @[ContrGen.scala 85:62]
  wire  _io_aluctr_T_75 = _io_aluctr_T_31 & _io_aluctr_T_14 & _io_aluctr_T_19; // @[ContrGen.scala 86:62]
  wire  _io_aluctr_T_76 = io_opcode == 7'h63; // @[ContrGen.scala 88:20]
  wire  _io_aluctr_T_78 = io_opcode == 7'h63 & _io_alua_T_3; // @[ContrGen.scala 88:37]
  wire  _io_aluctr_T_81 = _io_aluctr_T_76 & _io_aluctr_T_17; // @[ContrGen.scala 89:37]
  wire  _io_aluctr_T_84 = _io_aluctr_T_76 & _io_aluctr_T_8; // @[ContrGen.scala 90:37]
  wire  _io_aluctr_T_87 = _io_aluctr_T_76 & _io_aluctr_T_22; // @[ContrGen.scala 91:37]
  wire  _io_aluctr_T_90 = _io_aluctr_T_76 & _io_aluctr_T_11; // @[ContrGen.scala 92:37]
  wire  _io_aluctr_T_93 = _io_aluctr_T_76 & _io_aluctr_T_14; // @[ContrGen.scala 93:37]
  wire [3:0] _io_aluctr_T_94 = _io_aluctr_T_93 ? 4'ha : 4'h0; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_95 = _io_aluctr_T_90 ? 4'ha : _io_aluctr_T_94; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_96 = _io_aluctr_T_87 ? 4'h2 : _io_aluctr_T_95; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_97 = _io_aluctr_T_84 ? 4'h2 : _io_aluctr_T_96; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_98 = _io_aluctr_T_81 ? 4'h2 : _io_aluctr_T_97; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_99 = _io_aluctr_T_78 ? 4'h2 : _io_aluctr_T_98; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_100 = _io_aluctr_T_75 ? 4'h7 : _io_aluctr_T_99; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_101 = _io_aluctr_T_70 ? 4'h6 : _io_aluctr_T_100; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_102 = _io_aluctr_T_65 ? 4'hd : _io_aluctr_T_101; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_103 = _io_aluctr_T_60 ? 4'h5 : _io_aluctr_T_102; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_104 = _io_aluctr_T_55 ? 4'h4 : _io_aluctr_T_103; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_105 = _io_aluctr_T_50 ? 4'ha : _io_aluctr_T_104; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_106 = _io_aluctr_T_45 ? 4'h2 : _io_aluctr_T_105; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_107 = _io_aluctr_T_40 ? 4'h1 : _io_aluctr_T_106; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_108 = _io_aluctr_T_35 ? 4'h8 : _io_aluctr_T_107; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_109 = _io_aluctr_T_30 ? 4'hd : _io_aluctr_T_108; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_110 = _io_aluctr_T_25 ? 4'h5 : _io_aluctr_T_109; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_111 = _io_aluctr_T_20 ? 4'h1 : _io_aluctr_T_110; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_112 = _io_aluctr_T_15 ? 4'h7 : _io_aluctr_T_111; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_113 = _io_aluctr_T_12 ? 4'h6 : _io_aluctr_T_112; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_114 = _io_aluctr_T_9 ? 4'h4 : _io_aluctr_T_113; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_115 = _io_aluctr_T_6 ? 4'ha : _io_aluctr_T_114; // @[Mux.scala 101:16]
  wire [3:0] _io_aluctr_T_116 = _io_aluctr_T_3 ? 4'h2 : _io_aluctr_T_115; // @[Mux.scala 101:16]
  wire [2:0] _io_branch_T_20 = _io_aluctr_T_93 ? 3'h7 : 3'h0; // @[Mux.scala 101:16]
  wire [2:0] _io_branch_T_21 = _io_aluctr_T_90 ? 3'h6 : _io_branch_T_20; // @[Mux.scala 101:16]
  wire [2:0] _io_branch_T_22 = _io_aluctr_T_87 ? 3'h7 : _io_branch_T_21; // @[Mux.scala 101:16]
  wire [2:0] _io_branch_T_23 = _io_aluctr_T_84 ? 3'h6 : _io_branch_T_22; // @[Mux.scala 101:16]
  wire [2:0] _io_branch_T_24 = _io_aluctr_T_81 ? 3'h5 : _io_branch_T_23; // @[Mux.scala 101:16]
  wire [2:0] _io_branch_T_25 = _io_aluctr_T_78 ? 3'h4 : _io_branch_T_24; // @[Mux.scala 101:16]
  wire [2:0] _io_branch_T_26 = _io_alua_T_2 ? 3'h2 : _io_branch_T_25; // @[Mux.scala 101:16]
  wire  _io_memop_T = io_opcode == 7'h23; // @[ContrGen.scala 121:20]
  wire  _io_memop_T_2 = io_opcode == 7'h23 & _io_aluctr_T_17; // @[ContrGen.scala 121:37]
  wire  _io_memop_T_5 = _io_memop_T & _io_aluctr_T_2; // @[ContrGen.scala 122:37]
  wire [1:0] _io_memop_T_6 = _io_memop_T_5 ? 2'h2 : 2'h0; // @[Mux.scala 101:16]
  wire [1:0] _io_memop_T_7 = _io_memop_T_2 ? 2'h1 : _io_memop_T_6; // @[Mux.scala 101:16]
  wire  _io_rdmemop_T = io_opcode == 7'h3; // @[ContrGen.scala 126:20]
  wire  _io_rdmemop_T_2 = io_opcode == 7'h3 & _io_aluctr_T_17; // @[ContrGen.scala 126:37]
  wire  _io_rdmemop_T_5 = _io_rdmemop_T & _io_aluctr_T_2; // @[ContrGen.scala 127:37]
  wire  _io_rdmemop_T_8 = _io_rdmemop_T & _io_aluctr_T_8; // @[ContrGen.scala 128:37]
  wire  _io_rdmemop_T_11 = _io_rdmemop_T & _io_aluctr_T_22; // @[ContrGen.scala 129:37]
  wire [2:0] _io_rdmemop_T_12 = _io_rdmemop_T_11 ? 3'h5 : 3'h0; // @[Mux.scala 101:16]
  wire [2:0] _io_rdmemop_T_13 = _io_rdmemop_T_8 ? 3'h4 : _io_rdmemop_T_12; // @[Mux.scala 101:16]
  wire [2:0] _io_rdmemop_T_14 = _io_rdmemop_T_5 ? 3'h2 : _io_rdmemop_T_13; // @[Mux.scala 101:16]
  assign io_immop = 7'h6f == io_opcode ? 3'h4 : {{1'd0}, _io_immop_T_13}; // @[Mux.scala 81:58]
  assign io_regwr = 7'h23 == io_opcode ? 1'h0 : _io_regwr_T_1; // @[Mux.scala 81:58]
  assign io_alua = _io_alua_T | (_io_alua_T_1 | _io_alua_T_4); // @[Mux.scala 101:16]
  assign io_alub = 7'h67 == io_opcode ? 2'h2 : _io_alub_T_11; // @[Mux.scala 81:58]
  assign io_aluctr = _io_aluctr_T ? 4'h3 : _io_aluctr_T_116; // @[Mux.scala 101:16]
  assign io_branch = _io_alua_T_1 ? 3'h1 : _io_branch_T_26; // @[Mux.scala 101:16]
  assign io_memreg = 7'h3 == io_opcode; // @[Mux.scala 81:61]
  assign io_memwr = 7'h23 == io_opcode; // @[Mux.scala 81:61]
  assign io_memop = {{1'd0}, _io_memop_T_7}; // @[ContrGen.scala 120:14]
  assign io_rdmemop = _io_rdmemop_T_2 ? 3'h1 : _io_rdmemop_T_14; // @[Mux.scala 101:16]
endmodule
module Mypc(
  input         clock,
  input         reset,
  input  [31:0] io_nextpc,
  output [31:0] io_pc
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] pcReg; // @[Mypc.scala 11:24]
  assign io_pc = pcReg; // @[Mypc.scala 15:11]
  always @(posedge clock) begin
    if (reset) begin // @[Mypc.scala 11:24]
      pcReg <= 32'h80000000; // @[Mypc.scala 11:24]
    end else begin
      pcReg <= io_nextpc; // @[Mypc.scala 13:19]
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
  pcReg = _RAND_0[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Mynextpc(
  input  [31:0] io_imm,
  input  [31:0] io_rs1,
  input  [31:0] io_pc,
  input         io_pcasrc,
  input         io_pcbsrc,
  output [31:0] io_nextpc
);
  wire [31:0] pca = io_pcasrc ? io_imm : 32'h4; // @[Mynextpc.scala 14:18]
  wire [31:0] pcb = io_pcbsrc ? io_rs1 : io_pc; // @[Mynextpc.scala 15:18]
  assign io_nextpc = pca + pcb; // @[Mynextpc.scala 16:22]
endmodule
module BranchCond(
  input        io_less,
  input        io_zero,
  input  [2:0] io_branch,
  output       io_pcasrc,
  output       io_pcbsrc
);
  wire  _io_pcasrc_T = io_branch == 3'h0; // @[BranchCond.scala 14:20]
  wire  _io_pcasrc_T_3 = io_branch == 3'h4 & ~io_zero; // @[BranchCond.scala 15:33]
  wire  _io_pcasrc_T_6 = io_branch == 3'h5 & io_zero; // @[BranchCond.scala 16:33]
  wire  _io_pcasrc_T_9 = io_branch == 3'h6 & ~io_less; // @[BranchCond.scala 17:33]
  wire  _io_pcasrc_T_12 = io_branch == 3'h7 & io_less; // @[BranchCond.scala 18:33]
  wire  _io_pcasrc_T_13 = _io_pcasrc_T_12 ? 1'h0 : 1'h1; // @[Mux.scala 101:16]
  wire  _io_pcasrc_T_14 = _io_pcasrc_T_9 ? 1'h0 : _io_pcasrc_T_13; // @[Mux.scala 101:16]
  wire  _io_pcasrc_T_15 = _io_pcasrc_T_6 ? 1'h0 : _io_pcasrc_T_14; // @[Mux.scala 101:16]
  wire  _io_pcasrc_T_16 = _io_pcasrc_T_3 ? 1'h0 : _io_pcasrc_T_15; // @[Mux.scala 101:16]
  assign io_pcasrc = _io_pcasrc_T ? 1'h0 : _io_pcasrc_T_16; // @[Mux.scala 101:16]
  assign io_pcbsrc = io_branch == 3'h2; // @[BranchCond.scala 22:20]
endmodule
module Npc(
  input         clock,
  input         reset,
  output [31:0] io_pc,
  output [31:0] io_inst,
  output        io_exit,
  output [31:0] io_regs_0,
  output [31:0] io_regs_1,
  output [31:0] io_regs_2,
  output [31:0] io_regs_3,
  output [31:0] io_regs_4,
  output [31:0] io_regs_5,
  output [31:0] io_regs_6,
  output [31:0] io_regs_7,
  output [31:0] io_regs_8,
  output [31:0] io_regs_9,
  output [31:0] io_regs_10,
  output [31:0] io_regs_11,
  output [31:0] io_regs_12,
  output [31:0] io_regs_13,
  output [31:0] io_regs_14,
  output [31:0] io_regs_15,
  output [31:0] io_nextPC
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  wire [31:0] immgen_io_instin; // @[Npc.scala 69:30]
  wire [2:0] immgen_io_immop; // @[Npc.scala 69:30]
  wire [31:0] immgen_io_immout; // @[Npc.scala 69:30]
  wire  regfile_clock; // @[Npc.scala 70:30]
  wire  regfile_reset; // @[Npc.scala 70:30]
  wire [3:0] regfile_io_ra; // @[Npc.scala 70:30]
  wire [3:0] regfile_io_rb; // @[Npc.scala 70:30]
  wire [3:0] regfile_io_rw; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_busw; // @[Npc.scala 70:30]
  wire  regfile_io_regwr; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_busa; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_busb; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_0; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_1; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_2; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_3; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_4; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_5; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_6; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_7; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_8; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_9; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_10; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_11; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_12; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_13; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_14; // @[Npc.scala 70:30]
  wire [31:0] regfile_io_regsout_15; // @[Npc.scala 70:30]
  wire [31:0] alu_io_rs1; // @[Npc.scala 71:30]
  wire [31:0] alu_io_rs2; // @[Npc.scala 71:30]
  wire [31:0] alu_io_imm; // @[Npc.scala 71:30]
  wire [31:0] alu_io_pc; // @[Npc.scala 71:30]
  wire  alu_io_alua; // @[Npc.scala 71:30]
  wire [1:0] alu_io_alub; // @[Npc.scala 71:30]
  wire [3:0] alu_io_aluctr; // @[Npc.scala 71:30]
  wire  alu_io_less; // @[Npc.scala 71:30]
  wire  alu_io_zero; // @[Npc.scala 71:30]
  wire [31:0] alu_io_result; // @[Npc.scala 71:30]
  wire [6:0] contrgen_io_opcode; // @[Npc.scala 72:30]
  wire [2:0] contrgen_io_func3; // @[Npc.scala 72:30]
  wire [6:0] contrgen_io_func7; // @[Npc.scala 72:30]
  wire [2:0] contrgen_io_immop; // @[Npc.scala 72:30]
  wire  contrgen_io_regwr; // @[Npc.scala 72:30]
  wire  contrgen_io_alua; // @[Npc.scala 72:30]
  wire [1:0] contrgen_io_alub; // @[Npc.scala 72:30]
  wire [3:0] contrgen_io_aluctr; // @[Npc.scala 72:30]
  wire [2:0] contrgen_io_branch; // @[Npc.scala 72:30]
  wire  contrgen_io_memreg; // @[Npc.scala 72:30]
  wire  contrgen_io_memwr; // @[Npc.scala 72:30]
  wire [2:0] contrgen_io_memop; // @[Npc.scala 72:30]
  wire [2:0] contrgen_io_rdmemop; // @[Npc.scala 72:30]
  wire  mypc_clock; // @[Npc.scala 73:30]
  wire  mypc_reset; // @[Npc.scala 73:30]
  wire [31:0] mypc_io_nextpc; // @[Npc.scala 73:30]
  wire [31:0] mypc_io_pc; // @[Npc.scala 73:30]
  wire [31:0] mynextpc_io_imm; // @[Npc.scala 74:30]
  wire [31:0] mynextpc_io_rs1; // @[Npc.scala 74:30]
  wire [31:0] mynextpc_io_pc; // @[Npc.scala 74:30]
  wire  mynextpc_io_pcasrc; // @[Npc.scala 74:30]
  wire  mynextpc_io_pcbsrc; // @[Npc.scala 74:30]
  wire [31:0] mynextpc_io_nextpc; // @[Npc.scala 74:30]
  wire  branchcond_io_less; // @[Npc.scala 75:30]
  wire  branchcond_io_zero; // @[Npc.scala 75:30]
  wire [2:0] branchcond_io_branch; // @[Npc.scala 75:30]
  wire  branchcond_io_pcasrc; // @[Npc.scala 75:30]
  wire  branchcond_io_pcbsrc; // @[Npc.scala 75:30]
  wire  datamem_valid; // @[Npc.scala 76:30]
  wire  datamem_wen; // @[Npc.scala 76:30]
  wire [31:0] datamem_raddr; // @[Npc.scala 76:30]
  wire [31:0] datamem_waddr; // @[Npc.scala 76:30]
  wire [31:0] datamem_wdata; // @[Npc.scala 76:30]
  wire [2:0] datamem_wmask; // @[Npc.scala 76:30]
  wire [31:0] datamem_rdata; // @[Npc.scala 76:30]
  wire  instfetch_clk; // @[Npc.scala 77:30]
  wire [31:0] instfetch_pc; // @[Npc.scala 77:30]
  wire [31:0] instfetch_inst; // @[Npc.scala 77:30]
  wire  instfetch_rst; // @[Npc.scala 77:30]
  wire [31:0] ebreakdetector_inst; // @[Npc.scala 78:30]
  wire [31:0] ebreakdetector_pc; // @[Npc.scala 78:30]
  wire  ebreakdetector_exit; // @[Npc.scala 78:30]
  wire [31:0] getregs_regs_0; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_1; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_2; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_3; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_4; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_5; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_6; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_7; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_8; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_9; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_10; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_11; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_12; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_13; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_14; // @[Npc.scala 79:30]
  wire [31:0] getregs_regs_15; // @[Npc.scala 79:30]
  wire [23:0] _rdata_T_2 = datamem_rdata[7] ? 24'hffffff : 24'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _rdata_T_4 = {_rdata_T_2,datamem_rdata[7:0]}; // @[Cat.scala 31:58]
  wire [15:0] _rdata_T_7 = datamem_rdata[15] ? 16'hffff : 16'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _rdata_T_9 = {_rdata_T_7,datamem_rdata[15:0]}; // @[Cat.scala 31:58]
  wire [31:0] _rdata_T_12 = {24'h0,datamem_rdata[7:0]}; // @[Cat.scala 31:58]
  wire [31:0] _rdata_T_15 = {16'h0,datamem_rdata[15:0]}; // @[Cat.scala 31:58]
  wire [31:0] _rdata_T_17 = 3'h0 == contrgen_io_rdmemop ? _rdata_T_4 : datamem_rdata; // @[Mux.scala 81:58]
  wire [31:0] _rdata_T_19 = 3'h1 == contrgen_io_rdmemop ? _rdata_T_9 : _rdata_T_17; // @[Mux.scala 81:58]
  wire [31:0] _rdata_T_21 = 3'h4 == contrgen_io_rdmemop ? _rdata_T_12 : _rdata_T_19; // @[Mux.scala 81:58]
  wire [31:0] rdata = 3'h5 == contrgen_io_rdmemop ? _rdata_T_15 : _rdata_T_21; // @[Mux.scala 81:58]
  reg  exitReg; // @[Npc.scala 167:24]
  wire  _GEN_0 = ebreakdetector_exit | exitReg; // @[Npc.scala 171:32 172:13 167:24]
  ImmGen immgen ( // @[Npc.scala 69:30]
    .io_instin(immgen_io_instin),
    .io_immop(immgen_io_immop),
    .io_immout(immgen_io_immout)
  );
  RegFile regfile ( // @[Npc.scala 70:30]
    .clock(regfile_clock),
    .reset(regfile_reset),
    .io_ra(regfile_io_ra),
    .io_rb(regfile_io_rb),
    .io_rw(regfile_io_rw),
    .io_busw(regfile_io_busw),
    .io_regwr(regfile_io_regwr),
    .io_busa(regfile_io_busa),
    .io_busb(regfile_io_busb),
    .io_regsout_0(regfile_io_regsout_0),
    .io_regsout_1(regfile_io_regsout_1),
    .io_regsout_2(regfile_io_regsout_2),
    .io_regsout_3(regfile_io_regsout_3),
    .io_regsout_4(regfile_io_regsout_4),
    .io_regsout_5(regfile_io_regsout_5),
    .io_regsout_6(regfile_io_regsout_6),
    .io_regsout_7(regfile_io_regsout_7),
    .io_regsout_8(regfile_io_regsout_8),
    .io_regsout_9(regfile_io_regsout_9),
    .io_regsout_10(regfile_io_regsout_10),
    .io_regsout_11(regfile_io_regsout_11),
    .io_regsout_12(regfile_io_regsout_12),
    .io_regsout_13(regfile_io_regsout_13),
    .io_regsout_14(regfile_io_regsout_14),
    .io_regsout_15(regfile_io_regsout_15)
  );
  ALU alu ( // @[Npc.scala 71:30]
    .io_rs1(alu_io_rs1),
    .io_rs2(alu_io_rs2),
    .io_imm(alu_io_imm),
    .io_pc(alu_io_pc),
    .io_alua(alu_io_alua),
    .io_alub(alu_io_alub),
    .io_aluctr(alu_io_aluctr),
    .io_less(alu_io_less),
    .io_zero(alu_io_zero),
    .io_result(alu_io_result)
  );
  ContrGen contrgen ( // @[Npc.scala 72:30]
    .io_opcode(contrgen_io_opcode),
    .io_func3(contrgen_io_func3),
    .io_func7(contrgen_io_func7),
    .io_immop(contrgen_io_immop),
    .io_regwr(contrgen_io_regwr),
    .io_alua(contrgen_io_alua),
    .io_alub(contrgen_io_alub),
    .io_aluctr(contrgen_io_aluctr),
    .io_branch(contrgen_io_branch),
    .io_memreg(contrgen_io_memreg),
    .io_memwr(contrgen_io_memwr),
    .io_memop(contrgen_io_memop),
    .io_rdmemop(contrgen_io_rdmemop)
  );
  Mypc mypc ( // @[Npc.scala 73:30]
    .clock(mypc_clock),
    .reset(mypc_reset),
    .io_nextpc(mypc_io_nextpc),
    .io_pc(mypc_io_pc)
  );
  Mynextpc mynextpc ( // @[Npc.scala 74:30]
    .io_imm(mynextpc_io_imm),
    .io_rs1(mynextpc_io_rs1),
    .io_pc(mynextpc_io_pc),
    .io_pcasrc(mynextpc_io_pcasrc),
    .io_pcbsrc(mynextpc_io_pcbsrc),
    .io_nextpc(mynextpc_io_nextpc)
  );
  BranchCond branchcond ( // @[Npc.scala 75:30]
    .io_less(branchcond_io_less),
    .io_zero(branchcond_io_zero),
    .io_branch(branchcond_io_branch),
    .io_pcasrc(branchcond_io_pcasrc),
    .io_pcbsrc(branchcond_io_pcbsrc)
  );
  DataMem datamem ( // @[Npc.scala 76:30]
    .valid(datamem_valid),
    .wen(datamem_wen),
    .raddr(datamem_raddr),
    .waddr(datamem_waddr),
    .wdata(datamem_wdata),
    .wmask(datamem_wmask),
    .rdata(datamem_rdata)
  );
  InstFetch instfetch ( // @[Npc.scala 77:30]
    .clk(instfetch_clk),
    .pc(instfetch_pc),
    .inst(instfetch_inst),
    .rst(instfetch_rst)
  );
  EbreakDetector ebreakdetector ( // @[Npc.scala 78:30]
    .inst(ebreakdetector_inst),
    .pc(ebreakdetector_pc),
    .exit(ebreakdetector_exit)
  );
  GetRegs getregs ( // @[Npc.scala 79:30]
    .regs_0(getregs_regs_0),
    .regs_1(getregs_regs_1),
    .regs_2(getregs_regs_2),
    .regs_3(getregs_regs_3),
    .regs_4(getregs_regs_4),
    .regs_5(getregs_regs_5),
    .regs_6(getregs_regs_6),
    .regs_7(getregs_regs_7),
    .regs_8(getregs_regs_8),
    .regs_9(getregs_regs_9),
    .regs_10(getregs_regs_10),
    .regs_11(getregs_regs_11),
    .regs_12(getregs_regs_12),
    .regs_13(getregs_regs_13),
    .regs_14(getregs_regs_14),
    .regs_15(getregs_regs_15)
  );
  assign io_pc = mypc_io_pc; // @[Npc.scala 161:9]
  assign io_inst = instfetch_inst; // @[Npc.scala 164:11]
  assign io_exit = exitReg; // @[Npc.scala 175:11]
  assign io_regs_0 = regfile_io_regsout_0; // @[Npc.scala 163:11]
  assign io_regs_1 = regfile_io_regsout_1; // @[Npc.scala 163:11]
  assign io_regs_2 = regfile_io_regsout_2; // @[Npc.scala 163:11]
  assign io_regs_3 = regfile_io_regsout_3; // @[Npc.scala 163:11]
  assign io_regs_4 = regfile_io_regsout_4; // @[Npc.scala 163:11]
  assign io_regs_5 = regfile_io_regsout_5; // @[Npc.scala 163:11]
  assign io_regs_6 = regfile_io_regsout_6; // @[Npc.scala 163:11]
  assign io_regs_7 = regfile_io_regsout_7; // @[Npc.scala 163:11]
  assign io_regs_8 = regfile_io_regsout_8; // @[Npc.scala 163:11]
  assign io_regs_9 = regfile_io_regsout_9; // @[Npc.scala 163:11]
  assign io_regs_10 = regfile_io_regsout_10; // @[Npc.scala 163:11]
  assign io_regs_11 = regfile_io_regsout_11; // @[Npc.scala 163:11]
  assign io_regs_12 = regfile_io_regsout_12; // @[Npc.scala 163:11]
  assign io_regs_13 = regfile_io_regsout_13; // @[Npc.scala 163:11]
  assign io_regs_14 = regfile_io_regsout_14; // @[Npc.scala 163:11]
  assign io_regs_15 = regfile_io_regsout_15; // @[Npc.scala 163:11]
  assign io_nextPC = mynextpc_io_nextpc; // @[Npc.scala 162:13]
  assign immgen_io_instin = instfetch_inst; // @[Npc.scala 105:20]
  assign immgen_io_immop = contrgen_io_immop; // @[Npc.scala 95:22]
  assign regfile_clock = clock;
  assign regfile_reset = reset;
  assign regfile_io_ra = instfetch_inst[18:15]; // @[Npc.scala 121:34]
  assign regfile_io_rb = instfetch_inst[23:20]; // @[Npc.scala 122:34]
  assign regfile_io_rw = instfetch_inst[10:7]; // @[Npc.scala 123:33]
  assign regfile_io_busw = ~contrgen_io_memreg ? alu_io_result : rdata; // @[Npc.scala 124:25]
  assign regfile_io_regwr = contrgen_io_regwr; // @[Npc.scala 94:22]
  assign alu_io_rs1 = regfile_io_busa; // @[Npc.scala 128:14]
  assign alu_io_rs2 = regfile_io_busb; // @[Npc.scala 130:14]
  assign alu_io_imm = immgen_io_immout; // @[Npc.scala 131:14]
  assign alu_io_pc = mypc_io_pc; // @[Npc.scala 129:14]
  assign alu_io_alua = contrgen_io_alua; // @[Npc.scala 96:22]
  assign alu_io_alub = contrgen_io_alub; // @[Npc.scala 97:22]
  assign alu_io_aluctr = contrgen_io_aluctr; // @[Npc.scala 93:22]
  assign contrgen_io_opcode = instfetch_inst[6:0]; // @[Npc.scala 90:32]
  assign contrgen_io_func3 = instfetch_inst[14:12]; // @[Npc.scala 91:31]
  assign contrgen_io_func7 = instfetch_inst[31:25]; // @[Npc.scala 92:31]
  assign mypc_clock = clock;
  assign mypc_reset = reset;
  assign mypc_io_nextpc = mynextpc_io_nextpc; // @[Npc.scala 141:19]
  assign mynextpc_io_imm = immgen_io_immout; // @[Npc.scala 134:19]
  assign mynextpc_io_rs1 = regfile_io_busa; // @[Npc.scala 135:19]
  assign mynextpc_io_pc = mypc_io_pc; // @[Npc.scala 136:19]
  assign mynextpc_io_pcasrc = branchcond_io_pcasrc; // @[Npc.scala 137:22]
  assign mynextpc_io_pcbsrc = branchcond_io_pcbsrc; // @[Npc.scala 138:22]
  assign branchcond_io_less = alu_io_less; // @[Npc.scala 145:22]
  assign branchcond_io_zero = alu_io_zero; // @[Npc.scala 146:22]
  assign branchcond_io_branch = contrgen_io_branch; // @[Npc.scala 100:24]
  assign datamem_valid = contrgen_io_memwr | contrgen_io_memreg; // @[Npc.scala 153:48]
  assign datamem_wen = contrgen_io_memwr; // @[Npc.scala 99:22]
  assign datamem_raddr = alu_io_result; // @[Npc.scala 150:20]
  assign datamem_waddr = alu_io_result; // @[Npc.scala 151:20]
  assign datamem_wdata = regfile_io_busb; // @[Npc.scala 152:20]
  assign datamem_wmask = contrgen_io_memop; // @[Npc.scala 98:22]
  assign instfetch_clk = clock; // @[Npc.scala 86:20]
  assign instfetch_pc = mynextpc_io_nextpc; // @[Npc.scala 87:20]
  assign instfetch_rst = reset; // @[Npc.scala 85:20]
  assign ebreakdetector_inst = instfetch_inst; // @[Npc.scala 168:26]
  assign ebreakdetector_pc = mypc_io_pc; // @[Npc.scala 169:24]
  assign getregs_regs_0 = regfile_io_regsout_0; // @[Npc.scala 157:19]
  assign getregs_regs_1 = regfile_io_regsout_1; // @[Npc.scala 157:19]
  assign getregs_regs_2 = regfile_io_regsout_2; // @[Npc.scala 157:19]
  assign getregs_regs_3 = regfile_io_regsout_3; // @[Npc.scala 157:19]
  assign getregs_regs_4 = regfile_io_regsout_4; // @[Npc.scala 157:19]
  assign getregs_regs_5 = regfile_io_regsout_5; // @[Npc.scala 157:19]
  assign getregs_regs_6 = regfile_io_regsout_6; // @[Npc.scala 157:19]
  assign getregs_regs_7 = regfile_io_regsout_7; // @[Npc.scala 157:19]
  assign getregs_regs_8 = regfile_io_regsout_8; // @[Npc.scala 157:19]
  assign getregs_regs_9 = regfile_io_regsout_9; // @[Npc.scala 157:19]
  assign getregs_regs_10 = regfile_io_regsout_10; // @[Npc.scala 157:19]
  assign getregs_regs_11 = regfile_io_regsout_11; // @[Npc.scala 157:19]
  assign getregs_regs_12 = regfile_io_regsout_12; // @[Npc.scala 157:19]
  assign getregs_regs_13 = regfile_io_regsout_13; // @[Npc.scala 157:19]
  assign getregs_regs_14 = regfile_io_regsout_14; // @[Npc.scala 157:19]
  assign getregs_regs_15 = regfile_io_regsout_15; // @[Npc.scala 157:19]
  always @(posedge clock) begin
    if (reset) begin // @[Npc.scala 167:24]
      exitReg <= 1'h0; // @[Npc.scala 167:24]
    end else begin
      exitReg <= _GEN_0;
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
  exitReg = _RAND_0[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
