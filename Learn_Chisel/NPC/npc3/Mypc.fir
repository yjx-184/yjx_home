circuit Mypc :
  module Mypc :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip nextpc : UInt<32>, flip wrclk : Clock, pc : UInt<32>}

    reg pcReg : UInt<32>, clock with :
      reset => (reset, UInt<32>("h80000000")) @[Mypc.scala 12:24]
    wire clk_neg_edge : UInt<1> @[Mypc.scala 15:28]
    node _clk_neg_edge_T = asUInt(io.wrclk) @[Mypc.scala 16:39]
    node _clk_neg_edge_T_1 = bits(_clk_neg_edge_T, 0, 0) @[Mypc.scala 16:39]
    reg clk_neg_edge_REG : UInt<1>, clock with :
      reset => (UInt<1>("h0"), clk_neg_edge_REG) @[Mypc.scala 16:29]
    clk_neg_edge_REG <= _clk_neg_edge_T_1 @[Mypc.scala 16:29]
    node _clk_neg_edge_T_2 = eq(clk_neg_edge_REG, UInt<1>("h0")) @[Mypc.scala 16:21]
    node _clk_neg_edge_T_3 = asUInt(io.wrclk) @[Mypc.scala 16:59]
    node _clk_neg_edge_T_4 = bits(_clk_neg_edge_T_3, 0, 0) @[Mypc.scala 16:59]
    node _clk_neg_edge_T_5 = and(_clk_neg_edge_T_2, _clk_neg_edge_T_4) @[Mypc.scala 16:47]
    clk_neg_edge <= _clk_neg_edge_T_5 @[Mypc.scala 16:18]
    when clk_neg_edge : @[Mypc.scala 19:24]
      pcReg <= io.nextpc @[Mypc.scala 20:15]
    io.pc <= pcReg @[Mypc.scala 22:11]

