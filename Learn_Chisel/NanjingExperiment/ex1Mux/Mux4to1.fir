circuit Mux4to1 :
  module Mux4to1 :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip X0 : UInt<2>, flip X1 : UInt<2>, flip X2 : UInt<2>, flip X3 : UInt<2>, flip Y : UInt<2>, F : UInt<2>}

    node _io_F_T = eq(io.Y, UInt<1>("h0")) @[Mux4to1.scala 16:11]
    node _io_F_T_1 = eq(io.Y, UInt<1>("h1")) @[Mux4to1.scala 17:11]
    node _io_F_T_2 = eq(io.Y, UInt<2>("h2")) @[Mux4to1.scala 18:11]
    node _io_F_T_3 = eq(io.Y, UInt<2>("h3")) @[Mux4to1.scala 19:11]
    node _io_F_T_4 = mux(_io_F_T_3, io.X3, UInt<1>("h0")) @[Mux.scala 101:16]
    node _io_F_T_5 = mux(_io_F_T_2, io.X2, _io_F_T_4) @[Mux.scala 101:16]
    node _io_F_T_6 = mux(_io_F_T_1, io.X1, _io_F_T_5) @[Mux.scala 101:16]
    node _io_F_T_7 = mux(_io_F_T, io.X0, _io_F_T_6) @[Mux.scala 101:16]
    io.F <= _io_F_T_7 @[Mux4to1.scala 15:8]

