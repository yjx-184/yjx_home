circuit Top :
  module Timing :
    input clock : Clock
    input reset : UInt<1>
    input io_in : UInt<4>
    output io_seg : UInt<8>

    node _T = eq(io_in, UInt<1>("h0")) @[Top.scala 13:14]
    node _T_1 = eq(io_in, UInt<1>("h1")) @[Top.scala 14:21]
    node _T_2 = eq(io_in, UInt<2>("h2")) @[Top.scala 15:21]
    node _T_3 = eq(io_in, UInt<2>("h3")) @[Top.scala 16:21]
    node _T_4 = eq(io_in, UInt<3>("h4")) @[Top.scala 17:21]
    node _T_5 = eq(io_in, UInt<3>("h5")) @[Top.scala 18:21]
    node _T_6 = eq(io_in, UInt<3>("h6")) @[Top.scala 19:21]
    node _T_7 = eq(io_in, UInt<3>("h7")) @[Top.scala 20:21]
    node _T_8 = eq(io_in, UInt<4>("h8")) @[Top.scala 21:21]
    node _T_9 = eq(io_in, UInt<4>("h9")) @[Top.scala 22:21]
    node _T_10 = eq(io_in, UInt<4>("ha")) @[Top.scala 23:21]
    node _T_11 = eq(io_in, UInt<4>("hb")) @[Top.scala 24:21]
    node _T_12 = eq(io_in, UInt<4>("hc")) @[Top.scala 25:21]
    node _T_13 = eq(io_in, UInt<4>("hd")) @[Top.scala 26:21]
    node _T_14 = eq(io_in, UInt<4>("he")) @[Top.scala 27:21]
    node _T_15 = eq(io_in, UInt<4>("hf")) @[Top.scala 28:21]
    node _GEN_0 = mux(_T_15, UInt<7>("h71"), UInt<8>("hff")) @[Top.scala 28:{36,45} 29:25]
    node _GEN_1 = mux(_T_14, UInt<7>("h61"), _GEN_0) @[Top.scala 27:{36,45}]
    node _GEN_2 = mux(_T_13, UInt<8>("h85"), _GEN_1) @[Top.scala 26:{36,45}]
    node _GEN_3 = mux(_T_12, UInt<7>("h63"), _GEN_2) @[Top.scala 25:{36,45}]
    node _GEN_4 = mux(_T_11, UInt<8>("hc1"), _GEN_3) @[Top.scala 24:{36,45}]
    node _GEN_5 = mux(_T_10, UInt<5>("h11"), _GEN_4) @[Top.scala 23:{36,45}]
    node _GEN_6 = mux(_T_9, UInt<4>("h9"), _GEN_5) @[Top.scala 22:{36,45}]
    node _GEN_7 = mux(_T_8, UInt<1>("h1"), _GEN_6) @[Top.scala 21:{36,45}]
    node _GEN_8 = mux(_T_7, UInt<5>("h1f"), _GEN_7) @[Top.scala 20:{36,45}]
    node _GEN_9 = mux(_T_6, UInt<7>("h41"), _GEN_8) @[Top.scala 19:{36,45}]
    node _GEN_10 = mux(_T_5, UInt<7>("h49"), _GEN_9) @[Top.scala 18:{36,45}]
    node _GEN_11 = mux(_T_4, UInt<8>("h99"), _GEN_10) @[Top.scala 17:{36,45}]
    node _GEN_12 = mux(_T_3, UInt<4>("hd"), _GEN_11) @[Top.scala 16:{36,45}]
    node _GEN_13 = mux(_T_2, UInt<6>("h25"), _GEN_12) @[Top.scala 15:{36,45}]
    node _GEN_14 = mux(_T_1, UInt<8>("h9f"), _GEN_13) @[Top.scala 14:{36,45}]
    node _GEN_15 = mux(_T, UInt<2>("h3"), _GEN_14) @[Top.scala 13:{29,38}]
    io_seg <= _GEN_15

  module Top :
    input clock : Clock
    input reset : UInt<1>
    output io_seg : UInt<8>

    inst timing of Timing @[Top.scala 62:22]
    reg counter4 : UInt<4>, clock with :
      reset => (UInt<1>("h0"), counter4) @[Top.scala 39:25]
    reg secCounter : UInt<27>, clock with :
      reset => (UInt<1>("h0"), secCounter) @[Top.scala 44:27]
    node _T = sub(UInt<26>("h2faf080"), UInt<1>("h1")) @[Top.scala 49:34]
    node _T_1 = tail(_T, 1) @[Top.scala 49:34]
    node _T_2 = eq(secCounter, _T_1) @[Top.scala 49:19]
    node _secCounter_T = add(secCounter, UInt<1>("h1")) @[Top.scala 53:30]
    node _secCounter_T_1 = tail(_secCounter_T, 1) @[Top.scala 53:30]
    node _GEN_0 = mux(_T_2, UInt<1>("h0"), _secCounter_T_1) @[Top.scala 49:41 50:16 53:16]
    node _GEN_1 = mux(_T_2, UInt<1>("h1"), UInt<1>("h0")) @[Top.scala 49:41 51:10 47:8]
    node _counter4_T = add(counter4, UInt<1>("h1")) @[Top.scala 58:26]
    node _counter4_T_1 = tail(_counter4_T, 1) @[Top.scala 58:26]
    node tick = _GEN_1 @[Top.scala 46:18]
    node _GEN_2 = mux(tick, _counter4_T_1, counter4) @[Top.scala 57:14 58:14 39:25]
    io_seg <= timing.io_seg @[Top.scala 64:10]
    counter4 <= mux(reset, UInt<4>("h0"), _GEN_2) @[Top.scala 39:{25,25}]
    secCounter <= mux(reset, UInt<27>("h0"), _GEN_0) @[Top.scala 44:{27,27}]
    timing.clock <= clock
    timing.reset <= reset
    timing.io_in <= counter4 @[Top.scala 63:16]
