circuit Top :
  module Shiftreg :
    input clock : Clock
    input reset : UInt<1>
    input io_clk : UInt<1>
    input io_reset : UInt<1>
    output io_random_out : UInt<8>

    reg shiftreg : UInt<8>, clock with :
      reset => (UInt<1>("h0"), shiftreg) @[Top.scala 35:26]
    node _lfsr_T = bits(shiftreg, 4, 4) @[Top.scala 38:22]
    node _lfsr_T_1 = bits(shiftreg, 3, 3) @[Top.scala 38:36]
    node _lfsr_T_2 = xor(_lfsr_T, _lfsr_T_1) @[Top.scala 38:26]
    node _lfsr_T_3 = bits(shiftreg, 2, 2) @[Top.scala 38:50]
    node _lfsr_T_4 = xor(_lfsr_T_2, _lfsr_T_3) @[Top.scala 38:40]
    node _lfsr_T_5 = bits(shiftreg, 0, 0) @[Top.scala 38:64]
    node lfsr = xor(_lfsr_T_4, _lfsr_T_5) @[Top.scala 38:54]
    node _shiftreg_T = bits(shiftreg, 7, 1) @[Top.scala 44:35]
    node _shiftreg_T_1 = cat(lfsr, _shiftreg_T) @[Cat.scala 31:58]
    node _GEN_0 = mux(io_clk, _shiftreg_T_1, shiftreg) @[Top.scala 43:23 44:14 35:26]
    node _GEN_1 = mux(io_reset, UInt<8>("hff"), _GEN_0) @[Top.scala 41:18 42:14]
    io_random_out <= shiftreg @[Top.scala 48:17]
    shiftreg <= mux(reset, UInt<8>("hff"), _GEN_1) @[Top.scala 35:{26,26}]

  module Seg :
    input clock : Clock
    input reset : UInt<1>
    input io_in : UInt<8>
    output io_seg : UInt<8>

    node _T = eq(UInt<1>("h0"), io_in) @[Top.scala 78:17]
    node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 79:25]
    node _T_1 = eq(UInt<1>("h1"), io_in) @[Top.scala 78:17]
    node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 80:25]
    node _T_2 = eq(UInt<2>("h2"), io_in) @[Top.scala 78:17]
    node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 81:25]
    node _T_3 = eq(UInt<2>("h3"), io_in) @[Top.scala 78:17]
    node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 82:25]
    node _T_4 = eq(UInt<3>("h4"), io_in) @[Top.scala 78:17]
    node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 83:25]
    node _T_5 = eq(UInt<3>("h5"), io_in) @[Top.scala 78:17]
    node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 84:25]
    node _T_6 = eq(UInt<3>("h6"), io_in) @[Top.scala 78:17]
    node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 85:25]
    node _T_7 = eq(UInt<3>("h7"), io_in) @[Top.scala 78:17]
    node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 86:25]
    node _T_8 = eq(UInt<4>("h8"), io_in) @[Top.scala 78:17]
    node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 87:25]
    node _T_9 = eq(UInt<4>("h9"), io_in) @[Top.scala 78:17]
    node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 88:25]
    node _T_10 = eq(UInt<4>("ha"), io_in) @[Top.scala 78:17]
    node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 89:26]
    node _T_11 = eq(UInt<4>("hb"), io_in) @[Top.scala 78:17]
    node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 90:26]
    node _T_12 = eq(UInt<4>("hc"), io_in) @[Top.scala 78:17]
    node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 91:26]
    node _T_13 = eq(UInt<4>("hd"), io_in) @[Top.scala 78:17]
    node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 92:26]
    node _T_14 = eq(UInt<4>("he"), io_in) @[Top.scala 78:17]
    node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 93:26]
    node _T_15 = eq(UInt<4>("hf"), io_in) @[Top.scala 78:17]
    node _io_seg_T_15 = not(UInt<8>("h8e")) @[Top.scala 94:26]
    node _GEN_0 = mux(_T_15, _io_seg_T_15, UInt<1>("h0")) @[Top.scala 76:10 78:17 94:23]
    node _GEN_1 = mux(_T_14, _io_seg_T_14, _GEN_0) @[Top.scala 78:17 93:23]
    node _GEN_2 = mux(_T_13, _io_seg_T_13, _GEN_1) @[Top.scala 78:17 92:23]
    node _GEN_3 = mux(_T_12, _io_seg_T_12, _GEN_2) @[Top.scala 78:17 91:23]
    node _GEN_4 = mux(_T_11, _io_seg_T_11, _GEN_3) @[Top.scala 78:17 90:23]
    node _GEN_5 = mux(_T_10, _io_seg_T_10, _GEN_4) @[Top.scala 78:17 89:23]
    node _GEN_6 = mux(_T_9, _io_seg_T_9, _GEN_5) @[Top.scala 78:17 88:22]
    node _GEN_7 = mux(_T_8, _io_seg_T_8, _GEN_6) @[Top.scala 78:17 87:22]
    node _GEN_8 = mux(_T_7, _io_seg_T_7, _GEN_7) @[Top.scala 78:17 86:22]
    node _GEN_9 = mux(_T_6, _io_seg_T_6, _GEN_8) @[Top.scala 78:17 85:22]
    node _GEN_10 = mux(_T_5, _io_seg_T_5, _GEN_9) @[Top.scala 78:17 84:22]
    node _GEN_11 = mux(_T_4, _io_seg_T_4, _GEN_10) @[Top.scala 78:17 83:22]
    node _GEN_12 = mux(_T_3, _io_seg_T_3, _GEN_11) @[Top.scala 78:17 82:22]
    node _GEN_13 = mux(_T_2, _io_seg_T_2, _GEN_12) @[Top.scala 78:17 81:22]
    node _GEN_14 = mux(_T_1, _io_seg_T_1, _GEN_13) @[Top.scala 78:17 80:22]
    node _GEN_15 = mux(_T, _io_seg_T, _GEN_14) @[Top.scala 78:17 79:22]
    io_seg <= _GEN_15

  module Top :
    input clock : Clock
    input reset : UInt<1>
    input io_clk : UInt<1>
    input io_reset : UInt<1>
    output io_seg_out : UInt<8>

    inst shiftreg of Shiftreg @[Top.scala 11:24]
    inst seg of Seg @[Top.scala 13:19]
    node _seg_io_in_T = bits(shiftreg.io_random_out, 3, 0) @[Top.scala 16:38]
    io_seg_out <= seg.io_seg @[Top.scala 24:14]
    shiftreg.clock <= clock
    shiftreg.reset <= reset
    shiftreg.io_clk <= io_clk @[Top.scala 20:19]
    shiftreg.io_reset <= io_reset @[Top.scala 21:21]
    seg.clock <= clock
    seg.reset <= reset
    seg.io_in <= pad(_seg_io_in_T, 8) @[Top.scala 16:13]
