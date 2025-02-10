circuit Combinational :
  module Combinational :
    input clock : Clock
    input reset : UInt<1>
    input io_in : UInt<4>
    output io_seg : UInt<8>

    node _T = eq(io_in, UInt<1>("h0")) @[Combinational.scala 13:14]
    node _T_1 = eq(io_in, UInt<1>("h1")) @[Combinational.scala 14:21]
    node _T_2 = eq(io_in, UInt<2>("h2")) @[Combinational.scala 15:21]
    node _T_3 = eq(io_in, UInt<2>("h3")) @[Combinational.scala 16:21]
    node _T_4 = eq(io_in, UInt<3>("h4")) @[Combinational.scala 17:21]
    node _T_5 = eq(io_in, UInt<3>("h5")) @[Combinational.scala 18:21]
    node _T_6 = eq(io_in, UInt<3>("h6")) @[Combinational.scala 19:21]
    node _T_7 = eq(io_in, UInt<3>("h7")) @[Combinational.scala 20:21]
    node _T_8 = eq(io_in, UInt<4>("h8")) @[Combinational.scala 21:21]
    node _T_9 = eq(io_in, UInt<4>("h9")) @[Combinational.scala 22:21]
    node _GEN_0 = mux(_T_9, UInt<4>("h9"), UInt<8>("hff")) @[Combinational.scala 22:{36,45} 23:25]
    node _GEN_1 = mux(_T_8, UInt<1>("h1"), _GEN_0) @[Combinational.scala 21:{36,45}]
    node _GEN_2 = mux(_T_7, UInt<5>("h1f"), _GEN_1) @[Combinational.scala 20:{36,45}]
    node _GEN_3 = mux(_T_6, UInt<7>("h41"), _GEN_2) @[Combinational.scala 19:{36,45}]
    node _GEN_4 = mux(_T_5, UInt<7>("h49"), _GEN_3) @[Combinational.scala 18:{36,45}]
    node _GEN_5 = mux(_T_4, UInt<8>("h99"), _GEN_4) @[Combinational.scala 17:{36,45}]
    node _GEN_6 = mux(_T_3, UInt<4>("hd"), _GEN_5) @[Combinational.scala 16:{36,45}]
    node _GEN_7 = mux(_T_2, UInt<6>("h25"), _GEN_6) @[Combinational.scala 15:{36,45}]
    node _GEN_8 = mux(_T_1, UInt<8>("h9f"), _GEN_7) @[Combinational.scala 14:{36,45}]
    node _GEN_9 = mux(_T, UInt<2>("h3"), _GEN_8) @[Combinational.scala 13:{29,38}]
    io_seg <= _GEN_9
