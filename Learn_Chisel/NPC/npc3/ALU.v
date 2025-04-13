module ALU(
  input         clock,
  input         reset,
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
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
`endif // RANDOMIZE_REG_INIT
  wire [31:0] aluA = io_alua ? io_pc : io_rs1; // @[ALU.scala 19:19]
  wire [31:0] _aluB_T_2 = 2'h1 == io_alub ? io_imm : io_rs2; // @[Mux.scala 81:58]
  wire [31:0] aluB = 2'h2 == io_alub ? 32'h4 : _aluB_T_2; // @[Mux.scala 81:58]
  wire [31:0] sum = aluA + aluB; // @[ALU.scala 28:20]
  wire [31:0] sub = aluA - aluB; // @[ALU.scala 29:20]
  wire [31:0] _slt_T = aluA - aluB; // @[ALU.scala 30:19]
  wire  slt = $signed(_slt_T) < 32'sh0; // @[ALU.scala 30:26]
  wire  sltu = aluA < aluB; // @[ALU.scala 31:21]
  wire [62:0] _GEN_1 = {{31'd0}, aluA}; // @[ALU.scala 32:20]
  wire [62:0] sll = _GEN_1 << aluB[4:0]; // @[ALU.scala 32:20]
  wire [31:0] srl = aluA >> aluB[4:0]; // @[ALU.scala 33:20]
  wire [31:0] _sra_T = io_alua ? io_pc : io_rs1; // @[ALU.scala 34:21]
  wire [31:0] sra = $signed(_sra_T) >>> aluB[4:0]; // @[ALU.scala 34:43]
  wire [31:0] xor_ = aluA ^ aluB; // @[ALU.scala 35:20]
  wire [31:0] or_ = aluA | aluB; // @[ALU.scala 36:20]
  wire [31:0] and_ = aluA & aluB; // @[ALU.scala 37:20]
  reg [31:0] resultReg; // @[ALU.scala 40:28]
  reg  lessReg; // @[ALU.scala 41:26]
  reg  zeroReg; // @[ALU.scala 42:26]
  wire [31:0] _resultReg_T_1 = 4'h0 == io_aluctr ? sum : 32'h0; // @[Mux.scala 81:58]
  wire [31:0] _resultReg_T_3 = 4'h8 == io_aluctr ? sub : _resultReg_T_1; // @[Mux.scala 81:58]
  wire [31:0] _resultReg_T_5 = 4'h2 == io_aluctr ? {{31'd0}, slt} : _resultReg_T_3; // @[Mux.scala 81:58]
  wire [31:0] _resultReg_T_7 = 4'ha == io_aluctr ? {{31'd0}, sltu} : _resultReg_T_5; // @[Mux.scala 81:58]
  wire [62:0] _resultReg_T_9 = 4'h1 == io_aluctr ? sll : {{31'd0}, _resultReg_T_7}; // @[Mux.scala 81:58]
  wire [62:0] _resultReg_T_11 = 4'h5 == io_aluctr ? {{31'd0}, srl} : _resultReg_T_9; // @[Mux.scala 81:58]
  wire [62:0] _resultReg_T_13 = 4'hd == io_aluctr ? {{31'd0}, sra} : _resultReg_T_11; // @[Mux.scala 81:58]
  wire [62:0] _resultReg_T_15 = 4'h4 == io_aluctr ? {{31'd0}, xor_} : _resultReg_T_13; // @[Mux.scala 81:58]
  wire [62:0] _resultReg_T_17 = 4'h6 == io_aluctr ? {{31'd0}, or_} : _resultReg_T_15; // @[Mux.scala 81:58]
  wire [62:0] _resultReg_T_19 = 4'h7 == io_aluctr ? {{31'd0}, and_} : _resultReg_T_17; // @[Mux.scala 81:58]
  wire [62:0] _GEN_0 = reset ? 63'h0 : _resultReg_T_19; // @[ALU.scala 40:{28,28} 62:15]
  assign io_less = lessReg; // @[ALU.scala 82:13]
  assign io_zero = zeroReg; // @[ALU.scala 81:13]
  assign io_result = resultReg; // @[ALU.scala 80:15]
  always @(posedge clock) begin
    resultReg <= _GEN_0[31:0]; // @[ALU.scala 40:{28,28} 62:15]
    if (reset) begin // @[ALU.scala 41:26]
      lessReg <= 1'h0; // @[ALU.scala 41:26]
    end else begin
      lessReg <= slt; // @[ALU.scala 77:13]
    end
    if (reset) begin // @[ALU.scala 42:26]
      zeroReg <= 1'h0; // @[ALU.scala 42:26]
    end else begin
      zeroReg <= sub == 32'h0; // @[ALU.scala 76:13]
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
  resultReg = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  lessReg = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  zeroReg = _RAND_2[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
