circuit Combinational :
  module Combinational :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip in : UInt<4>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Combinational.scala 10:10]
    node _T = eq(io.in, UInt<1>("h0")) @[Combinational.scala 13:14]
    when _T : @[Combinational.scala 13:29]
      io.seg <= UInt<2>("h3") @[Combinational.scala 13:38]
    else :
      node _T_1 = eq(io.in, UInt<1>("h1")) @[Combinational.scala 14:21]
      when _T_1 : @[Combinational.scala 14:36]
        io.seg <= UInt<8>("h9f") @[Combinational.scala 14:45]
      else :
        node _T_2 = eq(io.in, UInt<2>("h2")) @[Combinational.scala 15:21]
        when _T_2 : @[Combinational.scala 15:36]
          io.seg <= UInt<6>("h25") @[Combinational.scala 15:45]
        else :
          node _T_3 = eq(io.in, UInt<2>("h3")) @[Combinational.scala 16:21]
          when _T_3 : @[Combinational.scala 16:36]
            io.seg <= UInt<4>("hd") @[Combinational.scala 16:45]
          else :
            node _T_4 = eq(io.in, UInt<3>("h4")) @[Combinational.scala 17:21]
            when _T_4 : @[Combinational.scala 17:36]
              io.seg <= UInt<8>("h99") @[Combinational.scala 17:45]
            else :
              node _T_5 = eq(io.in, UInt<3>("h5")) @[Combinational.scala 18:21]
              when _T_5 : @[Combinational.scala 18:36]
                io.seg <= UInt<7>("h49") @[Combinational.scala 18:45]
              else :
                node _T_6 = eq(io.in, UInt<3>("h6")) @[Combinational.scala 19:21]
                when _T_6 : @[Combinational.scala 19:36]
                  io.seg <= UInt<7>("h41") @[Combinational.scala 19:45]
                else :
                  node _T_7 = eq(io.in, UInt<3>("h7")) @[Combinational.scala 20:21]
                  when _T_7 : @[Combinational.scala 20:36]
                    io.seg <= UInt<5>("h1f") @[Combinational.scala 20:45]
                  else :
                    node _T_8 = eq(io.in, UInt<4>("h8")) @[Combinational.scala 21:21]
                    when _T_8 : @[Combinational.scala 21:36]
                      io.seg <= UInt<1>("h1") @[Combinational.scala 21:45]
                    else :
                      node _T_9 = eq(io.in, UInt<4>("h9")) @[Combinational.scala 22:21]
                      when _T_9 : @[Combinational.scala 22:36]
                        io.seg <= UInt<4>("h9") @[Combinational.scala 22:45]
                      else :
                        io.seg <= UInt<8>("hff") @[Combinational.scala 23:25]

