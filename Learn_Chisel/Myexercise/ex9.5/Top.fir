circuit Top :
  module Top :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip btn : UInt<1>, led : UInt<8>}

    reg btnsync_REG : UInt<1>, clock with :
      reset => (UInt<1>("h0"), btnsync_REG) @[Top.scala 13:38]
    btnsync_REG <= io.btn @[Top.scala 13:38]
    reg btnsync : UInt<1>, clock with :
      reset => (UInt<1>("h0"), btnsync) @[Top.scala 13:30]
    btnsync <= btnsync_REG @[Top.scala 13:30]
    reg tick_reg : UInt<14>, clock with :
      reset => (reset, UInt<14>("h0")) @[Top.scala 18:22]
    node tick = eq(tick_reg, UInt<14>("h270f")) @[Top.scala 19:20]
    node _tick_reg_T = add(tick_reg, UInt<1>("h1")) @[Top.scala 20:31]
    node _tick_reg_T_1 = tail(_tick_reg_T, 1) @[Top.scala 20:31]
    node _tick_reg_T_2 = mux(tick, UInt<1>("h0"), _tick_reg_T_1) @[Top.scala 20:15]
    tick_reg <= _tick_reg_T_2 @[Top.scala 20:9]
    reg btnDeb : UInt<1>, clock with :
      reset => (UInt<1>("h0"), btnDeb) @[Top.scala 25:19]
    when tick : @[Top.scala 26:14]
      btnDeb <= btnsync @[Top.scala 27:12]
    reg btnClean_reg : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Top.scala 32:22]
    when tick : @[Top.scala 33:13]
      node _btnClean_reg_T = bits(btnClean_reg, 1, 0) @[Top.scala 34:21]
      node _btnClean_reg_T_1 = cat(_btnClean_reg_T, btnDeb) @[Cat.scala 31:58]
      btnClean_reg <= _btnClean_reg_T_1 @[Top.scala 34:11]
    node _btnClean_T = bits(btnClean_reg, 2, 2) @[Top.scala 36:9]
    node _btnClean_T_1 = bits(btnClean_reg, 0, 0) @[Top.scala 36:18]
    node _btnClean_T_2 = and(_btnClean_T, _btnClean_T_1) @[Top.scala 36:13]
    node _btnClean_T_3 = bits(btnClean_reg, 2, 2) @[Top.scala 36:29]
    node _btnClean_T_4 = bits(btnClean_reg, 1, 1) @[Top.scala 36:38]
    node _btnClean_T_5 = and(_btnClean_T_3, _btnClean_T_4) @[Top.scala 36:33]
    node _btnClean_T_6 = or(_btnClean_T_2, _btnClean_T_5) @[Top.scala 36:23]
    node _btnClean_T_7 = bits(btnClean_reg, 1, 1) @[Top.scala 36:49]
    node _btnClean_T_8 = bits(btnClean_reg, 0, 0) @[Top.scala 36:58]
    node _btnClean_T_9 = and(_btnClean_T_7, _btnClean_T_8) @[Top.scala 36:53]
    node btnClean = or(_btnClean_T_6, _btnClean_T_9) @[Top.scala 36:43]
    reg risingEdge_REG : UInt<1>, clock with :
      reset => (UInt<1>("h0"), risingEdge_REG) @[Top.scala 41:43]
    risingEdge_REG <= btnClean @[Top.scala 41:43]
    node _risingEdge_T = eq(risingEdge_REG, UInt<1>("h0")) @[Top.scala 41:35]
    node risingEdge = and(btnClean, _risingEdge_T) @[Top.scala 41:33]
    reg counter : UInt<8>, clock with :
      reset => (reset, UInt<8>("h0")) @[Top.scala 45:24]
    when risingEdge : @[Top.scala 46:20]
      node _counter_T = add(counter, UInt<1>("h1")) @[Top.scala 47:24]
      node _counter_T_1 = tail(_counter_T, 1) @[Top.scala 47:24]
      counter <= _counter_T_1 @[Top.scala 47:13]
    io.led <= counter @[Top.scala 51:10]

