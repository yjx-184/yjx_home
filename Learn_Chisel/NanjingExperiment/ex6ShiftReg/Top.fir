circuit Top :
  module Shiftreg :
    input clock : Clock
    input reset : Reset
    output io : { flip clk : UInt<1>, flip reset : UInt<1>, random_out : UInt<8>}

    reg shiftreg : UInt<8>, clock with :
      reset => (reset, UInt<8>("hff")) @[Top.scala 52:26]
    node _lfsr_T = bits(shiftreg, 4, 4) @[Top.scala 55:22]
    node _lfsr_T_1 = bits(shiftreg, 3, 3) @[Top.scala 55:36]
    node _lfsr_T_2 = xor(_lfsr_T, _lfsr_T_1) @[Top.scala 55:26]
    node _lfsr_T_3 = bits(shiftreg, 2, 2) @[Top.scala 55:50]
    node _lfsr_T_4 = xor(_lfsr_T_2, _lfsr_T_3) @[Top.scala 55:40]
    node _lfsr_T_5 = bits(shiftreg, 0, 0) @[Top.scala 55:64]
    node lfsr = xor(_lfsr_T_4, _lfsr_T_5) @[Top.scala 55:54]
    when io.reset : @[Top.scala 58:18]
      shiftreg <= UInt<8>("hff") @[Top.scala 59:14]
    else :
      when io.clk : @[Top.scala 60:23]
        node _shiftreg_T = bits(shiftreg, 7, 1) @[Top.scala 61:35]
        node _shiftreg_T_1 = cat(lfsr, _shiftreg_T) @[Cat.scala 31:58]
        shiftreg <= _shiftreg_T_1 @[Top.scala 61:14]
    io.random_out <= shiftreg @[Top.scala 65:17]

  module Seg :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<8>, seg : UInt<8>}

    io.seg <= UInt<1>("h0") @[Top.scala 93:10]
    node _T = eq(UInt<1>("h0"), io.in) @[Top.scala 95:17]
    when _T : @[Top.scala 95:17]
      node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 96:25]
      io.seg <= _io_seg_T @[Top.scala 96:22]
    else :
      node _T_1 = eq(UInt<1>("h1"), io.in) @[Top.scala 95:17]
      when _T_1 : @[Top.scala 95:17]
        node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 97:25]
        io.seg <= _io_seg_T_1 @[Top.scala 97:22]
      else :
        node _T_2 = eq(UInt<2>("h2"), io.in) @[Top.scala 95:17]
        when _T_2 : @[Top.scala 95:17]
          node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 98:25]
          io.seg <= _io_seg_T_2 @[Top.scala 98:22]
        else :
          node _T_3 = eq(UInt<2>("h3"), io.in) @[Top.scala 95:17]
          when _T_3 : @[Top.scala 95:17]
            node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 99:25]
            io.seg <= _io_seg_T_3 @[Top.scala 99:22]
          else :
            node _T_4 = eq(UInt<3>("h4"), io.in) @[Top.scala 95:17]
            when _T_4 : @[Top.scala 95:17]
              node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 100:25]
              io.seg <= _io_seg_T_4 @[Top.scala 100:22]
            else :
              node _T_5 = eq(UInt<3>("h5"), io.in) @[Top.scala 95:17]
              when _T_5 : @[Top.scala 95:17]
                node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 101:25]
                io.seg <= _io_seg_T_5 @[Top.scala 101:22]
              else :
                node _T_6 = eq(UInt<3>("h6"), io.in) @[Top.scala 95:17]
                when _T_6 : @[Top.scala 95:17]
                  node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 102:25]
                  io.seg <= _io_seg_T_6 @[Top.scala 102:22]
                else :
                  node _T_7 = eq(UInt<3>("h7"), io.in) @[Top.scala 95:17]
                  when _T_7 : @[Top.scala 95:17]
                    node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 103:25]
                    io.seg <= _io_seg_T_7 @[Top.scala 103:22]
                  else :
                    node _T_8 = eq(UInt<4>("h8"), io.in) @[Top.scala 95:17]
                    when _T_8 : @[Top.scala 95:17]
                      node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 104:25]
                      io.seg <= _io_seg_T_8 @[Top.scala 104:22]
                    else :
                      node _T_9 = eq(UInt<4>("h9"), io.in) @[Top.scala 95:17]
                      when _T_9 : @[Top.scala 95:17]
                        node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 105:25]
                        io.seg <= _io_seg_T_9 @[Top.scala 105:22]
                      else :
                        node _T_10 = eq(UInt<4>("ha"), io.in) @[Top.scala 95:17]
                        when _T_10 : @[Top.scala 95:17]
                          node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 106:26]
                          io.seg <= _io_seg_T_10 @[Top.scala 106:23]
                        else :
                          node _T_11 = eq(UInt<4>("hb"), io.in) @[Top.scala 95:17]
                          when _T_11 : @[Top.scala 95:17]
                            node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 107:26]
                            io.seg <= _io_seg_T_11 @[Top.scala 107:23]
                          else :
                            node _T_12 = eq(UInt<4>("hc"), io.in) @[Top.scala 95:17]
                            when _T_12 : @[Top.scala 95:17]
                              node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 108:26]
                              io.seg <= _io_seg_T_12 @[Top.scala 108:23]
                            else :
                              node _T_13 = eq(UInt<4>("hd"), io.in) @[Top.scala 95:17]
                              when _T_13 : @[Top.scala 95:17]
                                node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 109:26]
                                io.seg <= _io_seg_T_13 @[Top.scala 109:23]
                              else :
                                node _T_14 = eq(UInt<4>("he"), io.in) @[Top.scala 95:17]
                                when _T_14 : @[Top.scala 95:17]
                                  node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 110:26]
                                  io.seg <= _io_seg_T_14 @[Top.scala 110:23]
                                else :
                                  node _T_15 = eq(UInt<4>("hf"), io.in) @[Top.scala 95:17]
                                  when _T_15 : @[Top.scala 95:17]
                                    node _io_seg_T_15 = not(UInt<8>("h8e")) @[Top.scala 111:26]
                                    io.seg <= _io_seg_T_15 @[Top.scala 111:23]

  module Top :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip clk : UInt<1>, flip reset : UInt<1>, seg_out : UInt<8>}

    inst shiftreg of Shiftreg @[Top.scala 12:24]
    shiftreg.clock <= clock
    shiftreg.reset <= reset
    inst seg of Seg @[Top.scala 14:19]
    seg.clock <= clock
    seg.reset <= reset
    reg button_last : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 17:28]
    wire button_rise : UInt<1>
    button_rise <= UInt<1>("h0")
    seg.io.in <= UInt<1>("h0") @[Top.scala 21:13]
    node _button_rise_T = eq(button_last, UInt<1>("h0")) @[Top.scala 24:18]
    node _button_rise_T_1 = and(_button_rise_T, io.clk) @[Top.scala 24:31]
    button_rise <= _button_rise_T_1 @[Top.scala 24:15]
    when io.clk : @[Top.scala 27:16]
      button_last <= io.clk @[Top.scala 28:17]
    when button_rise : @[Top.scala 32:21]
      node _seg_io_in_T = bits(shiftreg.io.random_out, 3, 0) @[Top.scala 33:40]
      seg.io.in <= _seg_io_in_T @[Top.scala 33:15]
    shiftreg.io.clk <= io.clk @[Top.scala 37:19]
    shiftreg.io.reset <= io.reset @[Top.scala 38:21]
    io.seg_out <= seg.io.seg @[Top.scala 41:14]

