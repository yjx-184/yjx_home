FIRRTL version 1.2.0
circuit Top :
  module Top :
    input clock : Clock
    input reset : UInt<1>
    input io_minorcar : UInt<1> @[src/main/scala/Top.scala 6:14]
    input io_timestate : UInt<1> @[src/main/scala/Top.scala 6:14]
    output io_minorLight : UInt<2> @[src/main/scala/Top.scala 6:14]
    output io_mainLight : UInt<2> @[src/main/scala/Top.scala 6:14]

    reg stateReg : UInt<3>, clock with :
      reset => (UInt<1>("h0"), stateReg) @[src/main/scala/Top.scala 18:25]
    node _T = asUInt(UInt<1>("h0")) @[src/main/scala/Top.scala 25:21]
    node _T_1 = asUInt(stateReg) @[src/main/scala/Top.scala 25:21]
    node _T_2 = eq(_T, _T_1) @[src/main/scala/Top.scala 25:21]
    node _T_3 = eq(io_minorcar, UInt<1>("h1")) @[src/main/scala/Top.scala 29:24]
    node _GEN_0 = mux(_T_3, UInt<1>("h1"), stateReg) @[src/main/scala/Top.scala 29:36 30:18 18:25]
    node _T_4 = asUInt(UInt<1>("h1")) @[src/main/scala/Top.scala 25:21]
    node _T_5 = asUInt(stateReg) @[src/main/scala/Top.scala 25:21]
    node _T_6 = eq(_T_4, _T_5) @[src/main/scala/Top.scala 25:21]
    node _GEN_1 = mux(io_timestate, UInt<2>("h2"), stateReg) @[src/main/scala/Top.scala 36:26 37:18 18:25]
    node _T_7 = asUInt(UInt<2>("h2")) @[src/main/scala/Top.scala 25:21]
    node _T_8 = asUInt(stateReg) @[src/main/scala/Top.scala 25:21]
    node _T_9 = eq(_T_7, _T_8) @[src/main/scala/Top.scala 25:21]
    node _GEN_2 = mux(io_timestate, UInt<2>("h3"), stateReg) @[src/main/scala/Top.scala 43:26 44:18 18:25]
    node _T_10 = asUInt(UInt<2>("h3")) @[src/main/scala/Top.scala 25:21]
    node _T_11 = asUInt(stateReg) @[src/main/scala/Top.scala 25:21]
    node _T_12 = eq(_T_10, _T_11) @[src/main/scala/Top.scala 25:21]
    node _T_13 = eq(io_minorcar, UInt<1>("h0")) @[src/main/scala/Top.scala 50:40]
    node _T_14 = and(io_timestate, _T_13) @[src/main/scala/Top.scala 50:25]
    node _GEN_3 = mux(_T_14, UInt<3>("h4"), stateReg) @[src/main/scala/Top.scala 50:54 51:18 18:25]
    node _T_15 = asUInt(UInt<3>("h4")) @[src/main/scala/Top.scala 25:21]
    node _T_16 = asUInt(stateReg) @[src/main/scala/Top.scala 25:21]
    node _T_17 = eq(_T_15, _T_16) @[src/main/scala/Top.scala 25:21]
    node _GEN_4 = mux(io_timestate, UInt<1>("h0"), stateReg) @[src/main/scala/Top.scala 57:26 58:18 18:25]
    node _GEN_5 = mux(_T_17, UInt<1>("h0"), UInt<1>("h0")) @[src/main/scala/Top.scala 21:16 25:21 55:20]
    node _GEN_6 = mux(_T_17, UInt<1>("h1"), UInt<1>("h0")) @[src/main/scala/Top.scala 22:17 25:21 56:21]
    node _GEN_7 = mux(_T_17, _GEN_4, stateReg) @[src/main/scala/Top.scala 25:21 18:25]
    node _GEN_8 = mux(_T_12, UInt<1>("h0"), _GEN_5) @[src/main/scala/Top.scala 25:21 48:20]
    node _GEN_9 = mux(_T_12, UInt<2>("h2"), _GEN_6) @[src/main/scala/Top.scala 25:21 49:21]
    node _GEN_10 = mux(_T_12, _GEN_3, _GEN_7) @[src/main/scala/Top.scala 25:21]
    node _GEN_11 = mux(_T_9, UInt<1>("h0"), _GEN_8) @[src/main/scala/Top.scala 25:21 41:20]
    node _GEN_12 = mux(_T_9, UInt<1>("h0"), _GEN_9) @[src/main/scala/Top.scala 25:21 42:21]
    node _GEN_13 = mux(_T_9, _GEN_2, _GEN_10) @[src/main/scala/Top.scala 25:21]
    node _GEN_14 = mux(_T_6, UInt<1>("h1"), _GEN_11) @[src/main/scala/Top.scala 25:21 34:20]
    node _GEN_15 = mux(_T_6, UInt<1>("h0"), _GEN_12) @[src/main/scala/Top.scala 25:21 35:21]
    node _GEN_16 = mux(_T_6, _GEN_1, _GEN_13) @[src/main/scala/Top.scala 25:21]
    node _GEN_17 = mux(_T_2, UInt<2>("h2"), _GEN_14) @[src/main/scala/Top.scala 25:21 27:20]
    node _GEN_18 = mux(_T_2, UInt<1>("h0"), _GEN_15) @[src/main/scala/Top.scala 25:21 28:21]
    node _GEN_19 = mux(_T_2, _GEN_0, _GEN_16) @[src/main/scala/Top.scala 25:21]
    io_minorLight <= _GEN_18
    io_mainLight <= _GEN_17
    stateReg <= mux(reset, UInt<1>("h0"), _GEN_19) @[src/main/scala/Top.scala 18:{25,25}]
