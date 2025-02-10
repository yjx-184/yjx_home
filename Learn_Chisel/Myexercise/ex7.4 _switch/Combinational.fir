circuit Combinational :
  module Combinational :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip in : UInt<4>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Combinational.scala 11:10]
    node _T = eq(UInt<1>("h0"), io.in) @[Combinational.scala 14:17]
    when _T : @[Combinational.scala 14:17]
      io.seg <= UInt<2>("h3") @[Combinational.scala 15:28]
    else :
      node _T_1 = eq(UInt<1>("h1"), io.in) @[Combinational.scala 14:17]
      when _T_1 : @[Combinational.scala 14:17]
        io.seg <= UInt<8>("h9f") @[Combinational.scala 16:28]
      else :
        node _T_2 = eq(UInt<2>("h2"), io.in) @[Combinational.scala 14:17]
        when _T_2 : @[Combinational.scala 14:17]
          io.seg <= UInt<6>("h25") @[Combinational.scala 17:28]
        else :
          node _T_3 = eq(UInt<2>("h3"), io.in) @[Combinational.scala 14:17]
          when _T_3 : @[Combinational.scala 14:17]
            io.seg <= UInt<4>("hd") @[Combinational.scala 18:28]
          else :
            node _T_4 = eq(UInt<3>("h4"), io.in) @[Combinational.scala 14:17]
            when _T_4 : @[Combinational.scala 14:17]
              io.seg <= UInt<8>("h99") @[Combinational.scala 19:28]
            else :
              node _T_5 = eq(UInt<3>("h5"), io.in) @[Combinational.scala 14:17]
              when _T_5 : @[Combinational.scala 14:17]
                io.seg <= UInt<7>("h49") @[Combinational.scala 20:28]
              else :
                node _T_6 = eq(UInt<3>("h6"), io.in) @[Combinational.scala 14:17]
                when _T_6 : @[Combinational.scala 14:17]
                  io.seg <= UInt<7>("h41") @[Combinational.scala 21:28]
                else :
                  node _T_7 = eq(UInt<3>("h7"), io.in) @[Combinational.scala 14:17]
                  when _T_7 : @[Combinational.scala 14:17]
                    io.seg <= UInt<5>("h1f") @[Combinational.scala 22:28]
                  else :
                    node _T_8 = eq(UInt<4>("h8"), io.in) @[Combinational.scala 14:17]
                    when _T_8 : @[Combinational.scala 14:17]
                      io.seg <= UInt<1>("h1") @[Combinational.scala 23:28]
                    else :
                      node _T_9 = eq(UInt<4>("h9"), io.in) @[Combinational.scala 14:17]
                      when _T_9 : @[Combinational.scala 14:17]
                        io.seg <= UInt<4>("h9") @[Combinational.scala 24:28]

