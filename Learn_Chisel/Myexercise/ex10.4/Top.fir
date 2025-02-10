FIRRTL version 1.2.0
circuit Top :
  module Top :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip minorcar : UInt<1>, flip timestate : UInt<1>, minorLight : UInt<2>, mainLight : UInt<2>} @[src/main/scala/Top.scala 6:14]

    reg stateReg : UInt<3>, clock with :
      reset => (reset, UInt<1>("h0")) @[src/main/scala/Top.scala 18:25]
    io.mainLight <= UInt<1>("h0") @[src/main/scala/Top.scala 21:16]
    io.minorLight <= UInt<1>("h0") @[src/main/scala/Top.scala 22:17]
    node _T = asUInt(UInt<1>("h0")) @[src/main/scala/Top.scala 25:21]
    node _T_1 = asUInt(stateReg) @[src/main/scala/Top.scala 25:21]
    node _T_2 = eq(_T, _T_1) @[src/main/scala/Top.scala 25:21]
    when _T_2 : @[src/main/scala/Top.scala 25:21]
      io.mainLight <= UInt<2>("h2") @[src/main/scala/Top.scala 27:20]
      io.minorLight <= UInt<1>("h0") @[src/main/scala/Top.scala 28:21]
      node _T_3 = eq(io.minorcar, UInt<1>("h1")) @[src/main/scala/Top.scala 29:24]
      when _T_3 : @[src/main/scala/Top.scala 29:36]
        stateReg <= UInt<1>("h1") @[src/main/scala/Top.scala 30:18]
    else :
      node _T_4 = asUInt(UInt<1>("h1")) @[src/main/scala/Top.scala 25:21]
      node _T_5 = asUInt(stateReg) @[src/main/scala/Top.scala 25:21]
      node _T_6 = eq(_T_4, _T_5) @[src/main/scala/Top.scala 25:21]
      when _T_6 : @[src/main/scala/Top.scala 25:21]
        io.mainLight <= UInt<1>("h1") @[src/main/scala/Top.scala 34:20]
        io.minorLight <= UInt<1>("h0") @[src/main/scala/Top.scala 35:21]
        when io.timestate : @[src/main/scala/Top.scala 36:26]
          stateReg <= UInt<2>("h2") @[src/main/scala/Top.scala 37:18]
      else :
        node _T_7 = asUInt(UInt<2>("h2")) @[src/main/scala/Top.scala 25:21]
        node _T_8 = asUInt(stateReg) @[src/main/scala/Top.scala 25:21]
        node _T_9 = eq(_T_7, _T_8) @[src/main/scala/Top.scala 25:21]
        when _T_9 : @[src/main/scala/Top.scala 25:21]
          io.mainLight <= UInt<1>("h0") @[src/main/scala/Top.scala 41:20]
          io.minorLight <= UInt<1>("h0") @[src/main/scala/Top.scala 42:21]
          when io.timestate : @[src/main/scala/Top.scala 43:26]
            stateReg <= UInt<2>("h3") @[src/main/scala/Top.scala 44:18]
        else :
          node _T_10 = asUInt(UInt<2>("h3")) @[src/main/scala/Top.scala 25:21]
          node _T_11 = asUInt(stateReg) @[src/main/scala/Top.scala 25:21]
          node _T_12 = eq(_T_10, _T_11) @[src/main/scala/Top.scala 25:21]
          when _T_12 : @[src/main/scala/Top.scala 25:21]
            io.mainLight <= UInt<1>("h0") @[src/main/scala/Top.scala 48:20]
            io.minorLight <= UInt<2>("h2") @[src/main/scala/Top.scala 49:21]
            node _T_13 = eq(io.minorcar, UInt<1>("h0")) @[src/main/scala/Top.scala 50:40]
            node _T_14 = and(io.timestate, _T_13) @[src/main/scala/Top.scala 50:25]
            when _T_14 : @[src/main/scala/Top.scala 50:54]
              stateReg <= UInt<3>("h4") @[src/main/scala/Top.scala 51:18]
          else :
            node _T_15 = asUInt(UInt<3>("h4")) @[src/main/scala/Top.scala 25:21]
            node _T_16 = asUInt(stateReg) @[src/main/scala/Top.scala 25:21]
            node _T_17 = eq(_T_15, _T_16) @[src/main/scala/Top.scala 25:21]
            when _T_17 : @[src/main/scala/Top.scala 25:21]
              io.mainLight <= UInt<1>("h0") @[src/main/scala/Top.scala 55:20]
              io.minorLight <= UInt<1>("h1") @[src/main/scala/Top.scala 56:21]
              when io.timestate : @[src/main/scala/Top.scala 57:26]
                stateReg <= UInt<1>("h0") @[src/main/scala/Top.scala 58:18]


