circuit Hello :
  module Hello :
    input clock : Clock
    input reset : UInt<1>
    output io : { led : UInt<1>}

    reg cntReg : UInt<32>, clock with :
      reset => (reset, UInt<32>("h0")) @[Hello.scala 11:23]
    reg blkReg : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Hello.scala 12:23]
    node _cntReg_T = add(cntReg, UInt<1>("h1")) @[Hello.scala 14:20]
    node _cntReg_T_1 = tail(_cntReg_T, 1) @[Hello.scala 14:20]
    cntReg <= _cntReg_T_1 @[Hello.scala 14:10]
    node _T = eq(cntReg, UInt<25>("h17d783f")) @[Hello.scala 15:15]
    when _T : @[Hello.scala 15:28]
      cntReg <= UInt<1>("h0") @[Hello.scala 16:12]
      node _blkReg_T = not(blkReg) @[Hello.scala 17:15]
      blkReg <= _blkReg_T @[Hello.scala 17:12]
    io.led <= blkReg @[Hello.scala 19:10]

