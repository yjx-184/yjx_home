circuit Top :
  module ButtonDebounce :
    input clock : Clock
    input reset : UInt<1>
    input io_clk : UInt<1>
    input io_reset : UInt<1>
    input io_btn : UInt<1>
    output io_btn_clk : UInt<1>

    reg btnDebReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), btnDebReg) @[Top.scala 44:26]
    reg btnLast : UInt<1>, clock with :
      reset => (UInt<1>("h0"), btnLast) @[Top.scala 45:24]
    node _T = eq(io_reset, UInt<1>("h0")) @[Top.scala 48:17]
    node _T_1 = eq(io_btn, UInt<1>("h1")) @[Top.scala 53:17]
    node _T_2 = eq(btnLast, UInt<1>("h0")) @[Top.scala 53:39]
    node _T_3 = and(_T_1, _T_2) @[Top.scala 53:28]
    node _GEN_0 = mux(_T_3, UInt<1>("h1"), UInt<1>("h0")) @[Top.scala 53:52 54:17 56:17]
    node _GEN_1 = mux(_T, UInt<1>("h0"), _GEN_0) @[Top.scala 48:30 49:15]
    node _GEN_2 = mux(_T, UInt<1>("h0"), io_btn) @[Top.scala 48:30 50:13 59:13]
    io_btn_clk <= btnDebReg @[Top.scala 63:14]
    btnDebReg <= mux(reset, UInt<1>("h0"), _GEN_1) @[Top.scala 44:{26,26}]
    btnLast <= mux(reset, UInt<1>("h0"), _GEN_2) @[Top.scala 45:{24,24}]

  module Shiftreg :
    input clock : Clock
    input reset : UInt<1>
    input io_clk : UInt<1>
    input io_reset : UInt<1>
    output io_random_out : UInt<8>

    reg shiftreg : UInt<8>, clock with :
      reset => (UInt<1>("h0"), shiftreg) @[Top.scala 74:26]
    node _lfsr_T = bits(shiftreg, 4, 4) @[Top.scala 77:22]
    node _lfsr_T_1 = bits(shiftreg, 3, 3) @[Top.scala 77:36]
    node _lfsr_T_2 = xor(_lfsr_T, _lfsr_T_1) @[Top.scala 77:26]
    node _lfsr_T_3 = bits(shiftreg, 2, 2) @[Top.scala 77:50]
    node _lfsr_T_4 = xor(_lfsr_T_2, _lfsr_T_3) @[Top.scala 77:40]
    node _lfsr_T_5 = bits(shiftreg, 0, 0) @[Top.scala 77:64]
    node lfsr = xor(_lfsr_T_4, _lfsr_T_5) @[Top.scala 77:54]
    node _T = eq(io_reset, UInt<1>("h0")) @[Top.scala 80:17]
    node _shiftreg_T = bits(shiftreg, 7, 1) @[Top.scala 83:35]
    node _shiftreg_T_1 = cat(lfsr, _shiftreg_T) @[Cat.scala 31:58]
    node _GEN_0 = mux(io_clk, _shiftreg_T_1, shiftreg) @[Top.scala 82:23 83:14 74:26]
    node _GEN_1 = mux(_T, UInt<8>("hff"), _GEN_0) @[Top.scala 80:30 81:14]
    io_random_out <= shiftreg @[Top.scala 87:17]
    shiftreg <= mux(reset, UInt<8>("hff"), _GEN_1) @[Top.scala 74:{26,26}]

  module Seg :
    input clock : Clock
    input reset : UInt<1>
    input io_in : UInt<8>
    output io_seg : UInt<8>

    node _T = eq(UInt<1>("h0"), io_in) @[Top.scala 117:17]
    node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 118:25]
    node _T_1 = eq(UInt<1>("h1"), io_in) @[Top.scala 117:17]
    node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 119:25]
    node _T_2 = eq(UInt<2>("h2"), io_in) @[Top.scala 117:17]
    node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 120:25]
    node _T_3 = eq(UInt<2>("h3"), io_in) @[Top.scala 117:17]
    node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 121:25]
    node _T_4 = eq(UInt<3>("h4"), io_in) @[Top.scala 117:17]
    node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 122:25]
    node _T_5 = eq(UInt<3>("h5"), io_in) @[Top.scala 117:17]
    node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 123:25]
    node _T_6 = eq(UInt<3>("h6"), io_in) @[Top.scala 117:17]
    node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 124:25]
    node _T_7 = eq(UInt<3>("h7"), io_in) @[Top.scala 117:17]
    node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 125:25]
    node _T_8 = eq(UInt<4>("h8"), io_in) @[Top.scala 117:17]
    node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 126:25]
    node _T_9 = eq(UInt<4>("h9"), io_in) @[Top.scala 117:17]
    node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 127:25]
    node _T_10 = eq(UInt<4>("ha"), io_in) @[Top.scala 117:17]
    node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 128:26]
    node _T_11 = eq(UInt<4>("hb"), io_in) @[Top.scala 117:17]
    node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 129:26]
    node _T_12 = eq(UInt<4>("hc"), io_in) @[Top.scala 117:17]
    node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 130:26]
    node _T_13 = eq(UInt<4>("hd"), io_in) @[Top.scala 117:17]
    node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 131:26]
    node _T_14 = eq(UInt<4>("he"), io_in) @[Top.scala 117:17]
    node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 132:26]
    node _T_15 = eq(UInt<4>("hf"), io_in) @[Top.scala 117:17]
    node _io_seg_T_15 = not(UInt<8>("h8e")) @[Top.scala 133:26]
    node _GEN_0 = mux(_T_15, _io_seg_T_15, UInt<1>("h0")) @[Top.scala 115:10 117:17 133:23]
    node _GEN_1 = mux(_T_14, _io_seg_T_14, _GEN_0) @[Top.scala 117:17 132:23]
    node _GEN_2 = mux(_T_13, _io_seg_T_13, _GEN_1) @[Top.scala 117:17 131:23]
    node _GEN_3 = mux(_T_12, _io_seg_T_12, _GEN_2) @[Top.scala 117:17 130:23]
    node _GEN_4 = mux(_T_11, _io_seg_T_11, _GEN_3) @[Top.scala 117:17 129:23]
    node _GEN_5 = mux(_T_10, _io_seg_T_10, _GEN_4) @[Top.scala 117:17 128:23]
    node _GEN_6 = mux(_T_9, _io_seg_T_9, _GEN_5) @[Top.scala 117:17 127:22]
    node _GEN_7 = mux(_T_8, _io_seg_T_8, _GEN_6) @[Top.scala 117:17 126:22]
    node _GEN_8 = mux(_T_7, _io_seg_T_7, _GEN_7) @[Top.scala 117:17 125:22]
    node _GEN_9 = mux(_T_6, _io_seg_T_6, _GEN_8) @[Top.scala 117:17 124:22]
    node _GEN_10 = mux(_T_5, _io_seg_T_5, _GEN_9) @[Top.scala 117:17 123:22]
    node _GEN_11 = mux(_T_4, _io_seg_T_4, _GEN_10) @[Top.scala 117:17 122:22]
    node _GEN_12 = mux(_T_3, _io_seg_T_3, _GEN_11) @[Top.scala 117:17 121:22]
    node _GEN_13 = mux(_T_2, _io_seg_T_2, _GEN_12) @[Top.scala 117:17 120:22]
    node _GEN_14 = mux(_T_1, _io_seg_T_1, _GEN_13) @[Top.scala 117:17 119:22]
    node _GEN_15 = mux(_T, _io_seg_T, _GEN_14) @[Top.scala 117:17 118:22]
    io_seg <= _GEN_15

  module Top :
    input clock : Clock
    input reset : UInt<1>
    input io_clk : UInt<1>
    input io_reset : UInt<1>
    input io_btn : UInt<1>
    output io_seg_out : UInt<8>

    inst buttonDebounce of ButtonDebounce @[Top.scala 13:30]
    inst shiftreg of Shiftreg @[Top.scala 15:24]
    inst seg of Seg @[Top.scala 17:19]
    node _seg_io_in_T = bits(shiftreg.io_random_out, 3, 0) @[Top.scala 25:38]
    io_seg_out <= seg.io_seg @[Top.scala 33:14]
    buttonDebounce.clock <= clock
    buttonDebounce.reset <= reset
    buttonDebounce.io_clk <= io_clk @[Top.scala 20:25]
    buttonDebounce.io_reset <= io_reset @[Top.scala 21:27]
    buttonDebounce.io_btn <= io_btn @[Top.scala 22:25]
    shiftreg.clock <= clock
    shiftreg.reset <= reset
    shiftreg.io_clk <= buttonDebounce.io_btn_clk @[Top.scala 29:19]
    shiftreg.io_reset <= io_reset @[Top.scala 30:21]
    seg.clock <= clock
    seg.reset <= reset
    seg.io_in <= pad(_seg_io_in_T, 8) @[Top.scala 25:13]
