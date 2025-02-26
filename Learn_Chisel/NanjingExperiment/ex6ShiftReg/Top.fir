circuit Top :
  module ButtonDebounce :
    input clock : Clock
    input reset : Reset
    output io : { flip clk : UInt<1>, flip reset : UInt<1>, flip btn : UInt<1>, btn_clk : UInt<1>}

    reg btnDebReg : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 45:26]
    reg btnLast : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 46:24]
    node _T = eq(io.reset, UInt<1>("h0")) @[Top.scala 49:17]
    when _T : @[Top.scala 49:30]
      btnDebReg <= UInt<1>("h0") @[Top.scala 50:15]
      btnLast <= UInt<1>("h0") @[Top.scala 51:13]
    else :
      node _T_1 = eq(io.btn, UInt<1>("h1")) @[Top.scala 54:17]
      node _T_2 = eq(btnLast, UInt<1>("h0")) @[Top.scala 54:39]
      node _T_3 = and(_T_1, _T_2) @[Top.scala 54:28]
      when _T_3 : @[Top.scala 54:52]
        btnDebReg <= UInt<1>("h1") @[Top.scala 55:17]
      else :
        btnDebReg <= UInt<1>("h0") @[Top.scala 57:17]
      btnLast <= io.btn @[Top.scala 60:13]
    io.btn_clk <= btnDebReg @[Top.scala 64:14]

  module Shiftreg :
    input clock : Clock
    input reset : Reset
    output io : { flip clk : UInt<1>, flip reset : UInt<1>, random_out : UInt<8>}

    reg shiftreg : UInt<8>, clock with :
      reset => (reset, UInt<8>("hff")) @[Top.scala 75:26]
    node _lfsr_T = bits(shiftreg, 4, 4) @[Top.scala 78:22]
    node _lfsr_T_1 = bits(shiftreg, 3, 3) @[Top.scala 78:36]
    node _lfsr_T_2 = xor(_lfsr_T, _lfsr_T_1) @[Top.scala 78:26]
    node _lfsr_T_3 = bits(shiftreg, 2, 2) @[Top.scala 78:50]
    node _lfsr_T_4 = xor(_lfsr_T_2, _lfsr_T_3) @[Top.scala 78:40]
    node _lfsr_T_5 = bits(shiftreg, 0, 0) @[Top.scala 78:64]
    node lfsr = xor(_lfsr_T_4, _lfsr_T_5) @[Top.scala 78:54]
    node _T = eq(io.reset, UInt<1>("h0")) @[Top.scala 81:17]
    when _T : @[Top.scala 81:30]
      shiftreg <= UInt<8>("hff") @[Top.scala 82:14]
    else :
      when io.clk : @[Top.scala 83:23]
        node _shiftreg_T = bits(shiftreg, 7, 1) @[Top.scala 84:35]
        node _shiftreg_T_1 = cat(lfsr, _shiftreg_T) @[Cat.scala 31:58]
        shiftreg <= _shiftreg_T_1 @[Top.scala 84:14]
    io.random_out <= shiftreg @[Top.scala 88:17]

  module Seg :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<8>, flip reset : UInt<1>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 117:10]
    node _T = eq(io.reset, UInt<1>("h0")) @[Top.scala 119:17]
    when _T : @[Top.scala 119:30]
      io.seg <= UInt<8>("hff") @[Top.scala 120:12]
    else :
      node _T_1 = eq(UInt<1>("h0"), io.in) @[Top.scala 123:19]
      when _T_1 : @[Top.scala 123:19]
        node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 124:27]
        io.seg <= _io_seg_T @[Top.scala 124:24]
      else :
        node _T_2 = eq(UInt<1>("h1"), io.in) @[Top.scala 123:19]
        when _T_2 : @[Top.scala 123:19]
          node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 125:27]
          io.seg <= _io_seg_T_1 @[Top.scala 125:24]
        else :
          node _T_3 = eq(UInt<2>("h2"), io.in) @[Top.scala 123:19]
          when _T_3 : @[Top.scala 123:19]
            node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 126:27]
            io.seg <= _io_seg_T_2 @[Top.scala 126:24]
          else :
            node _T_4 = eq(UInt<2>("h3"), io.in) @[Top.scala 123:19]
            when _T_4 : @[Top.scala 123:19]
              node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 127:27]
              io.seg <= _io_seg_T_3 @[Top.scala 127:24]
            else :
              node _T_5 = eq(UInt<3>("h4"), io.in) @[Top.scala 123:19]
              when _T_5 : @[Top.scala 123:19]
                node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 128:27]
                io.seg <= _io_seg_T_4 @[Top.scala 128:24]
              else :
                node _T_6 = eq(UInt<3>("h5"), io.in) @[Top.scala 123:19]
                when _T_6 : @[Top.scala 123:19]
                  node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 129:27]
                  io.seg <= _io_seg_T_5 @[Top.scala 129:24]
                else :
                  node _T_7 = eq(UInt<3>("h6"), io.in) @[Top.scala 123:19]
                  when _T_7 : @[Top.scala 123:19]
                    node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 130:27]
                    io.seg <= _io_seg_T_6 @[Top.scala 130:24]
                  else :
                    node _T_8 = eq(UInt<3>("h7"), io.in) @[Top.scala 123:19]
                    when _T_8 : @[Top.scala 123:19]
                      node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 131:27]
                      io.seg <= _io_seg_T_7 @[Top.scala 131:24]
                    else :
                      node _T_9 = eq(UInt<4>("h8"), io.in) @[Top.scala 123:19]
                      when _T_9 : @[Top.scala 123:19]
                        node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 132:27]
                        io.seg <= _io_seg_T_8 @[Top.scala 132:24]
                      else :
                        node _T_10 = eq(UInt<4>("h9"), io.in) @[Top.scala 123:19]
                        when _T_10 : @[Top.scala 123:19]
                          node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 133:27]
                          io.seg <= _io_seg_T_9 @[Top.scala 133:24]
                        else :
                          node _T_11 = eq(UInt<4>("ha"), io.in) @[Top.scala 123:19]
                          when _T_11 : @[Top.scala 123:19]
                            node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 134:28]
                            io.seg <= _io_seg_T_10 @[Top.scala 134:25]
                          else :
                            node _T_12 = eq(UInt<4>("hb"), io.in) @[Top.scala 123:19]
                            when _T_12 : @[Top.scala 123:19]
                              node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 135:28]
                              io.seg <= _io_seg_T_11 @[Top.scala 135:25]
                            else :
                              node _T_13 = eq(UInt<4>("hc"), io.in) @[Top.scala 123:19]
                              when _T_13 : @[Top.scala 123:19]
                                node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 136:28]
                                io.seg <= _io_seg_T_12 @[Top.scala 136:25]
                              else :
                                node _T_14 = eq(UInt<4>("hd"), io.in) @[Top.scala 123:19]
                                when _T_14 : @[Top.scala 123:19]
                                  node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 137:28]
                                  io.seg <= _io_seg_T_13 @[Top.scala 137:25]
                                else :
                                  node _T_15 = eq(UInt<4>("he"), io.in) @[Top.scala 123:19]
                                  when _T_15 : @[Top.scala 123:19]
                                    node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 138:28]
                                    io.seg <= _io_seg_T_14 @[Top.scala 138:25]
                                  else :
                                    node _T_16 = eq(UInt<4>("hf"), io.in) @[Top.scala 123:19]
                                    when _T_16 : @[Top.scala 123:19]
                                      node _io_seg_T_15 = not(UInt<8>("h8e")) @[Top.scala 139:28]
                                      io.seg <= _io_seg_T_15 @[Top.scala 139:25]

  module Top :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip clk : UInt<1>, flip reset : UInt<1>, flip btn : UInt<1>, seg_out : UInt<8>}

    inst buttonDebounce of ButtonDebounce @[Top.scala 13:30]
    buttonDebounce.clock <= clock
    buttonDebounce.reset <= reset
    inst shiftreg of Shiftreg @[Top.scala 15:24]
    shiftreg.clock <= clock
    shiftreg.reset <= reset
    inst seg of Seg @[Top.scala 17:19]
    seg.clock <= clock
    seg.reset <= reset
    buttonDebounce.io.clk <= io.clk @[Top.scala 20:25]
    buttonDebounce.io.reset <= io.reset @[Top.scala 21:27]
    buttonDebounce.io.btn <= io.btn @[Top.scala 22:25]
    node _seg_io_in_T = bits(shiftreg.io.random_out, 3, 0) @[Top.scala 25:38]
    seg.io.in <= _seg_io_in_T @[Top.scala 25:13]
    shiftreg.io.clk <= buttonDebounce.io.btn_clk @[Top.scala 29:19]
    shiftreg.io.reset <= io.reset @[Top.scala 30:21]
    seg.io.reset <= io.reset @[Top.scala 31:16]
    io.seg_out <= seg.io.seg @[Top.scala 34:14]

