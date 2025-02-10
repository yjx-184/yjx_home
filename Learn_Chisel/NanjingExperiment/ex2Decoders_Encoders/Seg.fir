circuit Seg :
  module Seg :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip in : UInt<8>, flip sel : UInt<1>, out : UInt<3>, seg : UInt<7>, valid : UInt<1>}

    wire encodedOut : UInt<3> @[Seg.scala 14:26]
    node _T = bits(io.in, 7, 7) @[Seg.scala 16:15]
    when _T : @[Seg.scala 16:20]
      encodedOut <= UInt<3>("h7") @[Seg.scala 17:20]
    else :
      node _T_1 = bits(io.in, 6, 6) @[Seg.scala 18:22]
      when _T_1 : @[Seg.scala 18:27]
        encodedOut <= UInt<3>("h6") @[Seg.scala 19:20]
      else :
        node _T_2 = bits(io.in, 5, 5) @[Seg.scala 20:22]
        when _T_2 : @[Seg.scala 20:27]
          encodedOut <= UInt<3>("h5") @[Seg.scala 21:20]
        else :
          node _T_3 = bits(io.in, 4, 4) @[Seg.scala 22:22]
          when _T_3 : @[Seg.scala 22:27]
            encodedOut <= UInt<3>("h4") @[Seg.scala 23:20]
          else :
            node _T_4 = bits(io.in, 3, 3) @[Seg.scala 24:22]
            when _T_4 : @[Seg.scala 24:27]
              encodedOut <= UInt<2>("h3") @[Seg.scala 25:20]
            else :
              node _T_5 = bits(io.in, 2, 2) @[Seg.scala 26:22]
              when _T_5 : @[Seg.scala 26:27]
                encodedOut <= UInt<2>("h2") @[Seg.scala 27:20]
              else :
                node _T_6 = bits(io.in, 1, 1) @[Seg.scala 28:22]
                when _T_6 : @[Seg.scala 28:27]
                  encodedOut <= UInt<1>("h1") @[Seg.scala 29:20]
                else :
                  encodedOut <= UInt<1>("h0") @[Seg.scala 31:20]
    io.out <= encodedOut @[Seg.scala 34:12]
    node _io_valid_T = orr(io.in) @[Seg.scala 37:23]
    io.valid <= _io_valid_T @[Seg.scala 37:14]
    io.seg <= UInt<7>("h0") @[Seg.scala 40:12]
    when io.sel : @[Seg.scala 42:18]
      node _T_7 = eq(UInt<1>("h0"), io.out) @[Seg.scala 43:24]
      when _T_7 : @[Seg.scala 43:24]
        io.seg <= UInt<7>("h1") @[Seg.scala 44:30]
      else :
        node _T_8 = eq(UInt<1>("h1"), io.out) @[Seg.scala 43:24]
        when _T_8 : @[Seg.scala 43:24]
          io.seg <= UInt<7>("h4f") @[Seg.scala 45:30]
        else :
          node _T_9 = eq(UInt<2>("h2"), io.out) @[Seg.scala 43:24]
          when _T_9 : @[Seg.scala 43:24]
            io.seg <= UInt<7>("h12") @[Seg.scala 46:30]
          else :
            node _T_10 = eq(UInt<2>("h3"), io.out) @[Seg.scala 43:24]
            when _T_10 : @[Seg.scala 43:24]
              io.seg <= UInt<7>("h6") @[Seg.scala 47:30]
            else :
              node _T_11 = eq(UInt<3>("h4"), io.out) @[Seg.scala 43:24]
              when _T_11 : @[Seg.scala 43:24]
                io.seg <= UInt<7>("h4c") @[Seg.scala 48:30]
              else :
                node _T_12 = eq(UInt<3>("h5"), io.out) @[Seg.scala 43:24]
                when _T_12 : @[Seg.scala 43:24]
                  io.seg <= UInt<7>("h24") @[Seg.scala 49:30]
                else :
                  node _T_13 = eq(UInt<3>("h6"), io.out) @[Seg.scala 43:24]
                  when _T_13 : @[Seg.scala 43:24]
                    io.seg <= UInt<7>("h20") @[Seg.scala 50:30]
                  else :
                    node _T_14 = eq(UInt<3>("h7"), io.out) @[Seg.scala 43:24]
                    when _T_14 : @[Seg.scala 43:24]
                      io.seg <= UInt<7>("hf") @[Seg.scala 51:30]

