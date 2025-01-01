circuit Top :
  module Timing :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Timing.scala 11:10]
    node _T = eq(io.in, UInt<1>("h0")) @[Timing.scala 13:14]
    when _T : @[Timing.scala 13:29]
      io.seg <= UInt<2>("h3") @[Timing.scala 13:38]
    else :
      node _T_1 = eq(io.in, UInt<1>("h1")) @[Timing.scala 14:21]
      when _T_1 : @[Timing.scala 14:36]
        io.seg <= UInt<8>("h9f") @[Timing.scala 14:45]
      else :
        node _T_2 = eq(io.in, UInt<2>("h2")) @[Timing.scala 15:21]
        when _T_2 : @[Timing.scala 15:36]
          io.seg <= UInt<6>("h25") @[Timing.scala 15:45]
        else :
          node _T_3 = eq(io.in, UInt<2>("h3")) @[Timing.scala 16:21]
          when _T_3 : @[Timing.scala 16:36]
            io.seg <= UInt<4>("hd") @[Timing.scala 16:45]
          else :
            node _T_4 = eq(io.in, UInt<3>("h4")) @[Timing.scala 17:21]
            when _T_4 : @[Timing.scala 17:36]
              io.seg <= UInt<8>("h99") @[Timing.scala 17:45]
            else :
              node _T_5 = eq(io.in, UInt<3>("h5")) @[Timing.scala 18:21]
              when _T_5 : @[Timing.scala 18:36]
                io.seg <= UInt<7>("h49") @[Timing.scala 18:45]
              else :
                node _T_6 = eq(io.in, UInt<3>("h6")) @[Timing.scala 19:21]
                when _T_6 : @[Timing.scala 19:36]
                  io.seg <= UInt<7>("h41") @[Timing.scala 19:45]
                else :
                  node _T_7 = eq(io.in, UInt<3>("h7")) @[Timing.scala 20:21]
                  when _T_7 : @[Timing.scala 20:36]
                    io.seg <= UInt<5>("h1f") @[Timing.scala 20:45]
                  else :
                    node _T_8 = eq(io.in, UInt<4>("h8")) @[Timing.scala 21:21]
                    when _T_8 : @[Timing.scala 21:36]
                      io.seg <= UInt<1>("h1") @[Timing.scala 21:45]
                    else :
                      node _T_9 = eq(io.in, UInt<4>("h9")) @[Timing.scala 22:21]
                      when _T_9 : @[Timing.scala 22:36]
                        io.seg <= UInt<4>("h9") @[Timing.scala 22:45]
                      else :
                        node _T_10 = eq(io.in, UInt<4>("ha")) @[Timing.scala 23:21]
                        when _T_10 : @[Timing.scala 23:36]
                          io.seg <= UInt<5>("h11") @[Timing.scala 23:45]
                        else :
                          node _T_11 = eq(io.in, UInt<4>("hb")) @[Timing.scala 24:21]
                          when _T_11 : @[Timing.scala 24:36]
                            io.seg <= UInt<8>("hc1") @[Timing.scala 24:45]
                          else :
                            node _T_12 = eq(io.in, UInt<4>("hc")) @[Timing.scala 25:21]
                            when _T_12 : @[Timing.scala 25:36]
                              io.seg <= UInt<7>("h63") @[Timing.scala 25:45]
                            else :
                              node _T_13 = eq(io.in, UInt<4>("hd")) @[Timing.scala 26:21]
                              when _T_13 : @[Timing.scala 26:36]
                                io.seg <= UInt<8>("h85") @[Timing.scala 26:45]
                              else :
                                node _T_14 = eq(io.in, UInt<4>("he")) @[Timing.scala 27:21]
                                when _T_14 : @[Timing.scala 27:36]
                                  io.seg <= UInt<7>("h61") @[Timing.scala 27:45]
                                else :
                                  node _T_15 = eq(io.in, UInt<4>("hf")) @[Timing.scala 28:21]
                                  when _T_15 : @[Timing.scala 28:36]
                                    io.seg <= UInt<7>("h71") @[Timing.scala 28:45]
                                  else :
                                    io.seg <= UInt<8>("hff") @[Timing.scala 29:25]

  module Top :
    input clock : Clock
    input reset : UInt<1>
    output io : { seg : UInt<8>}

    reg counter4 : UInt<4>, clock with :
      reset => (reset, UInt<4>("h0")) @[Timing.scala 39:25]
    reg secCounter : UInt<27>, clock with :
      reset => (reset, UInt<27>("h0")) @[Timing.scala 44:27]
    wire tick : UInt<1> @[Timing.scala 46:18]
    tick <= UInt<1>("h0") @[Timing.scala 47:8]
    node _T = sub(UInt<26>("h2faf080"), UInt<1>("h1")) @[Timing.scala 49:34]
    node _T_1 = tail(_T, 1) @[Timing.scala 49:34]
    node _T_2 = eq(secCounter, _T_1) @[Timing.scala 49:19]
    when _T_2 : @[Timing.scala 49:41]
      secCounter <= UInt<1>("h0") @[Timing.scala 50:16]
      tick <= UInt<1>("h1") @[Timing.scala 51:10]
    else :
      node _secCounter_T = add(secCounter, UInt<1>("h1")) @[Timing.scala 53:30]
      node _secCounter_T_1 = tail(_secCounter_T, 1) @[Timing.scala 53:30]
      secCounter <= _secCounter_T_1 @[Timing.scala 53:16]
    when tick : @[Timing.scala 57:14]
      node _counter4_T = add(counter4, UInt<1>("h1")) @[Timing.scala 58:26]
      node _counter4_T_1 = tail(_counter4_T, 1) @[Timing.scala 58:26]
      counter4 <= _counter4_T_1 @[Timing.scala 58:14]
    inst timing of Timing @[Timing.scala 62:22]
    timing.clock <= clock
    timing.reset <= reset
    timing.io.in <= counter4 @[Timing.scala 63:16]
    io.seg <= timing.io.seg @[Timing.scala 64:10]

