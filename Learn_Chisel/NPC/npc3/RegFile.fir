circuit RegFile :
  module RegFile :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip wrclk : Clock, flip ra : UInt<4>, flip rb : UInt<4>, flip rw : UInt<4>, flip busw : UInt<32>, flip regwr : UInt<1>, busa : UInt<32>, busb : UInt<32>, regsout : UInt<32>[16]}

    wire _regs_WIRE : UInt<32>[16] @[RegFile.scala 18:31]
    _regs_WIRE[0] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[1] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[2] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[3] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[4] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[5] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[6] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[7] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[8] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[9] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[10] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[11] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[12] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[13] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[14] <= UInt<32>("h0") @[RegFile.scala 18:31]
    _regs_WIRE[15] <= UInt<32>("h0") @[RegFile.scala 18:31]
    reg regs : UInt<32>[16], clock with :
      reset => (reset, _regs_WIRE) @[RegFile.scala 18:23]
    node _io_busa_T = eq(io.ra, UInt<1>("h0")) @[RegFile.scala 21:26]
    node _io_busa_T_1 = mux(_io_busa_T, UInt<1>("h0"), regs[io.ra]) @[RegFile.scala 21:19]
    io.busa <= _io_busa_T_1 @[RegFile.scala 21:13]
    node _io_busb_T = eq(io.rb, UInt<1>("h0")) @[RegFile.scala 22:26]
    node _io_busb_T_1 = mux(_io_busb_T, UInt<1>("h0"), regs[io.rb]) @[RegFile.scala 22:19]
    io.busb <= _io_busb_T_1 @[RegFile.scala 22:13]
    wire clk_neg_edge : UInt<1> @[RegFile.scala 25:28]
    node _clk_neg_edge_T = asUInt(io.wrclk) @[RegFile.scala 26:39]
    node _clk_neg_edge_T_1 = bits(_clk_neg_edge_T, 0, 0) @[RegFile.scala 26:39]
    reg clk_neg_edge_REG : UInt<1>, clock with :
      reset => (UInt<1>("h0"), clk_neg_edge_REG) @[RegFile.scala 26:29]
    clk_neg_edge_REG <= _clk_neg_edge_T_1 @[RegFile.scala 26:29]
    node _clk_neg_edge_T_2 = eq(clk_neg_edge_REG, UInt<1>("h0")) @[RegFile.scala 26:21]
    node _clk_neg_edge_T_3 = asUInt(io.wrclk) @[RegFile.scala 26:59]
    node _clk_neg_edge_T_4 = bits(_clk_neg_edge_T_3, 0, 0) @[RegFile.scala 26:59]
    node _clk_neg_edge_T_5 = and(_clk_neg_edge_T_2, _clk_neg_edge_T_4) @[RegFile.scala 26:47]
    clk_neg_edge <= _clk_neg_edge_T_5 @[RegFile.scala 26:18]
    node _T = bits(io.regwr, 0, 0) @[RegFile.scala 29:35]
    node _T_1 = and(clk_neg_edge, _T) @[RegFile.scala 29:23]
    node _T_2 = neq(io.rw, UInt<1>("h0")) @[RegFile.scala 29:51]
    node _T_3 = and(_T_1, _T_2) @[RegFile.scala 29:42]
    when _T_3 : @[RegFile.scala 29:60]
      regs[io.rw] <= io.busw @[RegFile.scala 30:21]
    io.regsout <= regs @[RegFile.scala 32:16]

