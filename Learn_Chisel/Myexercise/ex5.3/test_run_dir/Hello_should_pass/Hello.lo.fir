circuit Hello :
  module Hello :
    input clock : Clock
    input reset : UInt<1>
    input io_sw : UInt<2>
    output io_led : UInt<1>

    reg cntReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), cntReg) @[Hello.scala 21:23]
    reg blkReg : UInt<1>, clock with :
      reset => (UInt<1>("h0"), blkReg) @[Hello.scala 22:23]
    node _cntReg_T = add(cntReg, UInt<1>("h1")) @[Hello.scala 25:20]
    node _cntReg_T_1 = tail(_cntReg_T, 1) @[Hello.scala 25:20]
    node _T = eq(cntReg, UInt<25>("h17d783f")) @[Hello.scala 26:15]
    node _blkReg_T = not(blkReg) @[Hello.scala 28:15]
    node _GEN_0 = mux(_T, UInt<1>("h0"), _cntReg_T_1) @[Hello.scala 25:10 26:28 27:12]
    node _GEN_1 = mux(_T, _blkReg_T, blkReg) @[Hello.scala 26:28 28:12 22:23]
    node _io_led_T = eq(io_sw, UInt<1>("h0")) @[Hello.scala 31:23]
    node _io_led_T_1 = eq(io_sw, UInt<1>("h1")) @[Hello.scala 32:27]
    node _io_led_T_2 = mux(_io_led_T_1, UInt<1>("h1"), blkReg) @[Hello.scala 32:20]
    node _io_led_T_3 = mux(_io_led_T, UInt<1>("h0"), _io_led_T_2) @[Hello.scala 31:16]
    io_led <= _io_led_T_3 @[Hello.scala 31:10]
    cntReg <= mux(reset, UInt<32>("h0"), _GEN_0) @[Hello.scala 21:{23,23}]
    blkReg <= mux(reset, UInt<1>("h0"), _GEN_1) @[Hello.scala 22:{23,23}]
