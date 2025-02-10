circuit Seg :
  module Seg :
    input clock : Clock
    input reset : UInt<1>
    input io_in : UInt<8>
    input io_sel : UInt<1>
    output io_out : UInt<3>
    output io_seg : UInt<7>
    output io_valid : UInt<1>

    node _T = bits(io_in, 7, 7) @[Seg.scala 16:15]
    node _T_1 = bits(io_in, 6, 6) @[Seg.scala 18:22]
    node _T_2 = bits(io_in, 5, 5) @[Seg.scala 20:22]
    node _T_3 = bits(io_in, 4, 4) @[Seg.scala 22:22]
    node _T_4 = bits(io_in, 3, 3) @[Seg.scala 24:22]
    node _T_5 = bits(io_in, 2, 2) @[Seg.scala 26:22]
    node _T_6 = bits(io_in, 1, 1) @[Seg.scala 28:22]
    node _GEN_0 = mux(_T_6, UInt<1>("h1"), UInt<1>("h0")) @[Seg.scala 28:27 29:20 31:20]
    node _GEN_1 = mux(_T_5, UInt<2>("h2"), _GEN_0) @[Seg.scala 26:27 27:20]
    node _GEN_2 = mux(_T_4, UInt<2>("h3"), _GEN_1) @[Seg.scala 24:27 25:20]
    node _GEN_3 = mux(_T_3, UInt<3>("h4"), _GEN_2) @[Seg.scala 22:27 23:20]
    node _GEN_4 = mux(_T_2, UInt<3>("h5"), _GEN_3) @[Seg.scala 20:27 21:20]
    node _GEN_5 = mux(_T_1, UInt<3>("h6"), _GEN_4) @[Seg.scala 18:27 19:20]
    node _GEN_6 = mux(_T, UInt<3>("h7"), _GEN_5) @[Seg.scala 16:20 17:20]
    node _io_valid_T = orr(io_in) @[Seg.scala 37:23]
    node _T_7 = eq(UInt<1>("h0"), io_out) @[Seg.scala 43:24]
    node _T_8 = eq(UInt<1>("h1"), io_out) @[Seg.scala 43:24]
    node _T_9 = eq(UInt<2>("h2"), io_out) @[Seg.scala 43:24]
    node _T_10 = eq(UInt<2>("h3"), io_out) @[Seg.scala 43:24]
    node _T_11 = eq(UInt<3>("h4"), io_out) @[Seg.scala 43:24]
    node _T_12 = eq(UInt<3>("h5"), io_out) @[Seg.scala 43:24]
    node _T_13 = eq(UInt<3>("h6"), io_out) @[Seg.scala 43:24]
    node _T_14 = eq(UInt<3>("h7"), io_out) @[Seg.scala 43:24]
    node _GEN_7 = mux(_T_14, UInt<7>("hf"), UInt<7>("h0")) @[Seg.scala 40:12 43:24 51:30]
    node _GEN_8 = mux(_T_13, UInt<7>("h20"), _GEN_7) @[Seg.scala 43:24 50:30]
    node _GEN_9 = mux(_T_12, UInt<7>("h24"), _GEN_8) @[Seg.scala 43:24 49:30]
    node _GEN_10 = mux(_T_11, UInt<7>("h4c"), _GEN_9) @[Seg.scala 43:24 48:30]
    node _GEN_11 = mux(_T_10, UInt<7>("h6"), _GEN_10) @[Seg.scala 43:24 47:30]
    node _GEN_12 = mux(_T_9, UInt<7>("h12"), _GEN_11) @[Seg.scala 43:24 46:30]
    node _GEN_13 = mux(_T_8, UInt<7>("h4f"), _GEN_12) @[Seg.scala 43:24 45:30]
    node _GEN_14 = mux(_T_7, UInt<7>("h1"), _GEN_13) @[Seg.scala 43:24 44:30]
    node _GEN_15 = mux(io_sel, _GEN_14, UInt<7>("h0")) @[Seg.scala 40:12 42:18]
    node encodedOut = _GEN_6 @[Seg.scala 14:26]
    io_out <= encodedOut @[Seg.scala 34:12]
    io_seg <= _GEN_15
    io_valid <= _io_valid_T @[Seg.scala 37:14]
