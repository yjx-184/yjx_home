module Npc(
  input   clock,
  input   reset,
  output  io_exit
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
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [31:0] _RAND_30;
  reg [31:0] _RAND_31;
  reg [31:0] _RAND_32;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] regFile_0; // @[Npc.scala 14:24]
  reg [31:0] regFile_1; // @[Npc.scala 14:24]
  reg [31:0] regFile_2; // @[Npc.scala 14:24]
  reg [31:0] regFile_3; // @[Npc.scala 14:24]
  reg [31:0] regFile_4; // @[Npc.scala 14:24]
  reg [31:0] regFile_5; // @[Npc.scala 14:24]
  reg [31:0] regFile_6; // @[Npc.scala 14:24]
  reg [31:0] regFile_7; // @[Npc.scala 14:24]
  reg [31:0] regFile_8; // @[Npc.scala 14:24]
  reg [31:0] regFile_9; // @[Npc.scala 14:24]
  reg [31:0] regFile_10; // @[Npc.scala 14:24]
  reg [31:0] regFile_11; // @[Npc.scala 14:24]
  reg [31:0] regFile_12; // @[Npc.scala 14:24]
  reg [31:0] regFile_13; // @[Npc.scala 14:24]
  reg [31:0] regFile_14; // @[Npc.scala 14:24]
  reg [31:0] regFile_15; // @[Npc.scala 14:24]
  reg [31:0] regFile_16; // @[Npc.scala 14:24]
  reg [31:0] regFile_17; // @[Npc.scala 14:24]
  reg [31:0] regFile_18; // @[Npc.scala 14:24]
  reg [31:0] regFile_19; // @[Npc.scala 14:24]
  reg [31:0] regFile_20; // @[Npc.scala 14:24]
  reg [31:0] regFile_21; // @[Npc.scala 14:24]
  reg [31:0] regFile_22; // @[Npc.scala 14:24]
  reg [31:0] regFile_23; // @[Npc.scala 14:24]
  reg [31:0] regFile_24; // @[Npc.scala 14:24]
  reg [31:0] regFile_25; // @[Npc.scala 14:24]
  reg [31:0] regFile_26; // @[Npc.scala 14:24]
  reg [31:0] regFile_27; // @[Npc.scala 14:24]
  reg [31:0] regFile_28; // @[Npc.scala 14:24]
  reg [31:0] regFile_29; // @[Npc.scala 14:24]
  reg [31:0] regFile_30; // @[Npc.scala 14:24]
  reg [31:0] regFile_31; // @[Npc.scala 14:24]
  reg [31:0] pc; // @[Npc.scala 17:19]
  wire [31:0] _inst_T_1 = pc - 32'h80000000; // @[Npc.scala 29:26]
  wire [31:0] _GEN_1 = 3'h1 == _inst_T_1[4:2] ? 32'h300113 : 32'h200093; // @[Npc.scala 32:{16,16}]
  wire [31:0] _GEN_2 = 3'h2 == _inst_T_1[4:2] ? 32'h408193 : _GEN_1; // @[Npc.scala 32:{16,16}]
  wire [31:0] _GEN_3 = 3'h3 == _inst_T_1[4:2] ? 32'h510213 : _GEN_2; // @[Npc.scala 32:{16,16}]
  wire [31:0] _GEN_4 = 3'h4 == _inst_T_1[4:2] ? 32'h100073 : _GEN_3; // @[Npc.scala 32:{16,16}]
  wire [6:0] op = _GEN_4[6:0]; // @[Npc.scala 32:16]
  wire [4:0] rd = _GEN_4[11:7]; // @[Npc.scala 33:16]
  wire [4:0] rs1 = _GEN_4[19:15]; // @[Npc.scala 34:17]
  wire [11:0] imm = _GEN_4[31:20]; // @[Npc.scala 35:17]
  wire [19:0] _imm_sext_T_2 = imm[11] ? 20'hfffff : 20'h0; // @[Bitwise.scala 74:12]
  wire [31:0] imm_sext = {_imm_sext_T_2,imm}; // @[Cat.scala 31:58]
  wire [31:0] _GEN_6 = 5'h1 == rs1 ? regFile_1 : regFile_0; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_7 = 5'h2 == rs1 ? regFile_2 : _GEN_6; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_8 = 5'h3 == rs1 ? regFile_3 : _GEN_7; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_9 = 5'h4 == rs1 ? regFile_4 : _GEN_8; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_10 = 5'h5 == rs1 ? regFile_5 : _GEN_9; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_11 = 5'h6 == rs1 ? regFile_6 : _GEN_10; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_12 = 5'h7 == rs1 ? regFile_7 : _GEN_11; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_13 = 5'h8 == rs1 ? regFile_8 : _GEN_12; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_14 = 5'h9 == rs1 ? regFile_9 : _GEN_13; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_15 = 5'ha == rs1 ? regFile_10 : _GEN_14; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_16 = 5'hb == rs1 ? regFile_11 : _GEN_15; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_17 = 5'hc == rs1 ? regFile_12 : _GEN_16; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_18 = 5'hd == rs1 ? regFile_13 : _GEN_17; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_19 = 5'he == rs1 ? regFile_14 : _GEN_18; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_20 = 5'hf == rs1 ? regFile_15 : _GEN_19; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_21 = 5'h10 == rs1 ? regFile_16 : _GEN_20; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_22 = 5'h11 == rs1 ? regFile_17 : _GEN_21; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_23 = 5'h12 == rs1 ? regFile_18 : _GEN_22; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_24 = 5'h13 == rs1 ? regFile_19 : _GEN_23; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_25 = 5'h14 == rs1 ? regFile_20 : _GEN_24; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_26 = 5'h15 == rs1 ? regFile_21 : _GEN_25; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_27 = 5'h16 == rs1 ? regFile_22 : _GEN_26; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_28 = 5'h17 == rs1 ? regFile_23 : _GEN_27; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_29 = 5'h18 == rs1 ? regFile_24 : _GEN_28; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_30 = 5'h19 == rs1 ? regFile_25 : _GEN_29; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_31 = 5'h1a == rs1 ? regFile_26 : _GEN_30; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_32 = 5'h1b == rs1 ? regFile_27 : _GEN_31; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_33 = 5'h1c == rs1 ? regFile_28 : _GEN_32; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_34 = 5'h1d == rs1 ? regFile_29 : _GEN_33; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_35 = 5'h1e == rs1 ? regFile_30 : _GEN_34; // @[Npc.scala 42:{26,26}]
  wire [31:0] _GEN_36 = 5'h1f == rs1 ? regFile_31 : _GEN_35; // @[Npc.scala 42:{26,26}]
  wire [31:0] aluOut = _GEN_36 + imm_sext; // @[Npc.scala 42:26]
  wire [31:0] _pc_T_1 = pc + 32'h4; // @[Npc.scala 52:12]
  wire  _T_3 = ~reset; // @[Npc.scala 58:9]
  assign io_exit = _GEN_4 == 32'h100073; // @[Npc.scala 55:20]
  always @(posedge clock) begin
    if (reset) begin // @[Npc.scala 14:24]
      regFile_0 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h0 == rd) begin // @[Npc.scala 47:19]
          regFile_0 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_1 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h1 == rd) begin // @[Npc.scala 47:19]
          regFile_1 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_2 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h2 == rd) begin // @[Npc.scala 47:19]
          regFile_2 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_3 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h3 == rd) begin // @[Npc.scala 47:19]
          regFile_3 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_4 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h4 == rd) begin // @[Npc.scala 47:19]
          regFile_4 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_5 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h5 == rd) begin // @[Npc.scala 47:19]
          regFile_5 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_6 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h6 == rd) begin // @[Npc.scala 47:19]
          regFile_6 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_7 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h7 == rd) begin // @[Npc.scala 47:19]
          regFile_7 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_8 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h8 == rd) begin // @[Npc.scala 47:19]
          regFile_8 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_9 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h9 == rd) begin // @[Npc.scala 47:19]
          regFile_9 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_10 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'ha == rd) begin // @[Npc.scala 47:19]
          regFile_10 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_11 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'hb == rd) begin // @[Npc.scala 47:19]
          regFile_11 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_12 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'hc == rd) begin // @[Npc.scala 47:19]
          regFile_12 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_13 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'hd == rd) begin // @[Npc.scala 47:19]
          regFile_13 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_14 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'he == rd) begin // @[Npc.scala 47:19]
          regFile_14 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_15 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'hf == rd) begin // @[Npc.scala 47:19]
          regFile_15 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_16 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h10 == rd) begin // @[Npc.scala 47:19]
          regFile_16 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_17 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h11 == rd) begin // @[Npc.scala 47:19]
          regFile_17 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_18 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h12 == rd) begin // @[Npc.scala 47:19]
          regFile_18 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_19 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h13 == rd) begin // @[Npc.scala 47:19]
          regFile_19 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_20 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h14 == rd) begin // @[Npc.scala 47:19]
          regFile_20 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_21 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h15 == rd) begin // @[Npc.scala 47:19]
          regFile_21 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_22 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h16 == rd) begin // @[Npc.scala 47:19]
          regFile_22 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_23 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h17 == rd) begin // @[Npc.scala 47:19]
          regFile_23 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_24 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h18 == rd) begin // @[Npc.scala 47:19]
          regFile_24 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_25 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h19 == rd) begin // @[Npc.scala 47:19]
          regFile_25 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_26 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h1a == rd) begin // @[Npc.scala 47:19]
          regFile_26 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_27 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h1b == rd) begin // @[Npc.scala 47:19]
          regFile_27 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_28 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h1c == rd) begin // @[Npc.scala 47:19]
          regFile_28 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_29 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h1d == rd) begin // @[Npc.scala 47:19]
          regFile_29 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_30 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h1e == rd) begin // @[Npc.scala 47:19]
          regFile_30 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 14:24]
      regFile_31 <= 32'h0; // @[Npc.scala 14:24]
    end else if (op == 7'h13) begin // @[Npc.scala 45:29]
      if (rd != 5'h0) begin // @[Npc.scala 46:22]
        if (5'h1f == rd) begin // @[Npc.scala 47:19]
          regFile_31 <= aluOut; // @[Npc.scala 47:19]
        end
      end
    end
    if (reset) begin // @[Npc.scala 17:19]
      pc <= 32'h80000000; // @[Npc.scala 17:19]
    end else begin
      pc <= _pc_T_1; // @[Npc.scala 52:6]
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (~reset) begin
          $fwrite(32'h80000002,"PC: 0x%x\n",pc); // @[Npc.scala 58:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x0: 0x%x\n",regFile_0); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x1: 0x%x\n",regFile_1); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x2: 0x%x\n",regFile_2); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x3: 0x%x\n",regFile_3); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x4: 0x%x\n",regFile_4); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x5: 0x%x\n",regFile_5); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x6: 0x%x\n",regFile_6); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x7: 0x%x\n",regFile_7); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x8: 0x%x\n",regFile_8); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x9: 0x%x\n",regFile_9); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x10: 0x%x\n",regFile_10); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x11: 0x%x\n",regFile_11); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x12: 0x%x\n",regFile_12); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x13: 0x%x\n",regFile_13); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x14: 0x%x\n",regFile_14); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x15: 0x%x\n",regFile_15); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x16: 0x%x\n",regFile_16); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x17: 0x%x\n",regFile_17); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x18: 0x%x\n",regFile_18); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x19: 0x%x\n",regFile_19); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x20: 0x%x\n",regFile_20); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x21: 0x%x\n",regFile_21); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x22: 0x%x\n",regFile_22); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x23: 0x%x\n",regFile_23); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x24: 0x%x\n",regFile_24); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x25: 0x%x\n",regFile_25); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x26: 0x%x\n",regFile_26); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x27: 0x%x\n",regFile_27); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x28: 0x%x\n",regFile_28); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x29: 0x%x\n",regFile_29); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x30: 0x%x\n",regFile_30); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_3) begin
          $fwrite(32'h80000002,"x31: 0x%x\n",regFile_31); // @[Npc.scala 60:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
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
  regFile_0 = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  regFile_1 = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  regFile_2 = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  regFile_3 = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  regFile_4 = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  regFile_5 = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  regFile_6 = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  regFile_7 = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  regFile_8 = _RAND_8[31:0];
  _RAND_9 = {1{`RANDOM}};
  regFile_9 = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  regFile_10 = _RAND_10[31:0];
  _RAND_11 = {1{`RANDOM}};
  regFile_11 = _RAND_11[31:0];
  _RAND_12 = {1{`RANDOM}};
  regFile_12 = _RAND_12[31:0];
  _RAND_13 = {1{`RANDOM}};
  regFile_13 = _RAND_13[31:0];
  _RAND_14 = {1{`RANDOM}};
  regFile_14 = _RAND_14[31:0];
  _RAND_15 = {1{`RANDOM}};
  regFile_15 = _RAND_15[31:0];
  _RAND_16 = {1{`RANDOM}};
  regFile_16 = _RAND_16[31:0];
  _RAND_17 = {1{`RANDOM}};
  regFile_17 = _RAND_17[31:0];
  _RAND_18 = {1{`RANDOM}};
  regFile_18 = _RAND_18[31:0];
  _RAND_19 = {1{`RANDOM}};
  regFile_19 = _RAND_19[31:0];
  _RAND_20 = {1{`RANDOM}};
  regFile_20 = _RAND_20[31:0];
  _RAND_21 = {1{`RANDOM}};
  regFile_21 = _RAND_21[31:0];
  _RAND_22 = {1{`RANDOM}};
  regFile_22 = _RAND_22[31:0];
  _RAND_23 = {1{`RANDOM}};
  regFile_23 = _RAND_23[31:0];
  _RAND_24 = {1{`RANDOM}};
  regFile_24 = _RAND_24[31:0];
  _RAND_25 = {1{`RANDOM}};
  regFile_25 = _RAND_25[31:0];
  _RAND_26 = {1{`RANDOM}};
  regFile_26 = _RAND_26[31:0];
  _RAND_27 = {1{`RANDOM}};
  regFile_27 = _RAND_27[31:0];
  _RAND_28 = {1{`RANDOM}};
  regFile_28 = _RAND_28[31:0];
  _RAND_29 = {1{`RANDOM}};
  regFile_29 = _RAND_29[31:0];
  _RAND_30 = {1{`RANDOM}};
  regFile_30 = _RAND_30[31:0];
  _RAND_31 = {1{`RANDOM}};
  regFile_31 = _RAND_31[31:0];
  _RAND_32 = {1{`RANDOM}};
  pc = _RAND_32[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
