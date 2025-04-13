circuit BranchCond :
  module BranchCond :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip less : UInt<1>, flip zero : UInt<1>, flip branch : UInt<3>, pcasrc : UInt<1>, pcbsrc : UInt<1>}

    node _io_pcasrc_T = eq(io.branch, UInt<1>("h0")) @[BranchCond.scala 14:20]
    node _io_pcasrc_T_1 = eq(io.branch, UInt<3>("h4")) @[BranchCond.scala 15:20]
    node _io_pcasrc_T_2 = eq(io.zero, UInt<1>("h0")) @[BranchCond.scala 15:44]
    node _io_pcasrc_T_3 = and(_io_pcasrc_T_1, _io_pcasrc_T_2) @[BranchCond.scala 15:33]
    node _io_pcasrc_T_4 = eq(io.branch, UInt<3>("h5")) @[BranchCond.scala 16:20]
    node _io_pcasrc_T_5 = eq(io.zero, UInt<1>("h1")) @[BranchCond.scala 16:44]
    node _io_pcasrc_T_6 = and(_io_pcasrc_T_4, _io_pcasrc_T_5) @[BranchCond.scala 16:33]
    node _io_pcasrc_T_7 = eq(io.branch, UInt<3>("h6")) @[BranchCond.scala 17:20]
    node _io_pcasrc_T_8 = eq(io.less, UInt<1>("h0")) @[BranchCond.scala 17:44]
    node _io_pcasrc_T_9 = and(_io_pcasrc_T_7, _io_pcasrc_T_8) @[BranchCond.scala 17:33]
    node _io_pcasrc_T_10 = eq(io.branch, UInt<3>("h7")) @[BranchCond.scala 18:20]
    node _io_pcasrc_T_11 = eq(io.less, UInt<1>("h1")) @[BranchCond.scala 18:44]
    node _io_pcasrc_T_12 = and(_io_pcasrc_T_10, _io_pcasrc_T_11) @[BranchCond.scala 18:33]
    node _io_pcasrc_T_13 = mux(_io_pcasrc_T_12, UInt<1>("h0"), UInt<1>("h1")) @[Mux.scala 101:16]
    node _io_pcasrc_T_14 = mux(_io_pcasrc_T_9, UInt<1>("h0"), _io_pcasrc_T_13) @[Mux.scala 101:16]
    node _io_pcasrc_T_15 = mux(_io_pcasrc_T_6, UInt<1>("h0"), _io_pcasrc_T_14) @[Mux.scala 101:16]
    node _io_pcasrc_T_16 = mux(_io_pcasrc_T_3, UInt<1>("h0"), _io_pcasrc_T_15) @[Mux.scala 101:16]
    node _io_pcasrc_T_17 = mux(_io_pcasrc_T, UInt<1>("h0"), _io_pcasrc_T_16) @[Mux.scala 101:16]
    io.pcasrc <= _io_pcasrc_T_17 @[BranchCond.scala 13:15]
    node _io_pcbsrc_T = eq(io.branch, UInt<2>("h2")) @[BranchCond.scala 22:20]
    node _io_pcbsrc_T_1 = mux(_io_pcbsrc_T, UInt<1>("h1"), UInt<1>("h0")) @[Mux.scala 101:16]
    io.pcbsrc <= _io_pcbsrc_T_1 @[BranchCond.scala 21:15]

