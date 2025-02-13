circuit Top :
  module PS2Keyboard :
    input clock : Clock
    input reset : Reset
    output io : { flip clrn : UInt<1>, flip ps2_clk : UInt<1>, flip ps2_data : UInt<1>, flip nextdata_n : UInt<1>, data : UInt<8>, ready : UInt<1>, overflow : UInt<1>}

    reg buffer : UInt<10>, clock with :
      reset => (reset, UInt<10>("h0")) @[Top.scala 92:28]
    wire _fifo_WIRE : UInt<8>[8] @[Top.scala 93:36]
    _fifo_WIRE[0] <= UInt<8>("h0") @[Top.scala 93:36]
    _fifo_WIRE[1] <= UInt<8>("h0") @[Top.scala 93:36]
    _fifo_WIRE[2] <= UInt<8>("h0") @[Top.scala 93:36]
    _fifo_WIRE[3] <= UInt<8>("h0") @[Top.scala 93:36]
    _fifo_WIRE[4] <= UInt<8>("h0") @[Top.scala 93:36]
    _fifo_WIRE[5] <= UInt<8>("h0") @[Top.scala 93:36]
    _fifo_WIRE[6] <= UInt<8>("h0") @[Top.scala 93:36]
    _fifo_WIRE[7] <= UInt<8>("h0") @[Top.scala 93:36]
    reg fifo : UInt<8>[8], clock with :
      reset => (reset, _fifo_WIRE) @[Top.scala 93:28]
    reg w_ptr : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Top.scala 94:28]
    reg r_ptr : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Top.scala 95:28]
    reg count : UInt<4>, clock with :
      reset => (reset, UInt<4>("h0")) @[Top.scala 96:28]
    reg overflow : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 97:28]
    reg ready : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 98:28]
    reg ps2_clk_sync : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Top.scala 99:28]
    node _ps2_clk_sync_T = bits(ps2_clk_sync, 1, 0) @[Top.scala 101:35]
    node _ps2_clk_sync_T_1 = cat(_ps2_clk_sync_T, io.ps2_clk) @[Cat.scala 31:58]
    ps2_clk_sync <= _ps2_clk_sync_T_1 @[Top.scala 101:16]
    node _sampling_T = bits(ps2_clk_sync, 2, 2) @[Top.scala 102:30]
    node _sampling_T_1 = bits(ps2_clk_sync, 1, 1) @[Top.scala 102:50]
    node _sampling_T_2 = eq(_sampling_T_1, UInt<1>("h0")) @[Top.scala 102:37]
    node sampling = and(_sampling_T, _sampling_T_2) @[Top.scala 102:34]
    node _T = eq(io.clrn, UInt<1>("h0")) @[Top.scala 104:9]
    when _T : @[Top.scala 104:19]
      buffer <= UInt<1>("h0") @[Top.scala 105:15]
      wire _WIRE : UInt<1>[8] @[Top.scala 106:25]
      _WIRE[0] <= UInt<1>("h0") @[Top.scala 106:25]
      _WIRE[1] <= UInt<1>("h0") @[Top.scala 106:25]
      _WIRE[2] <= UInt<1>("h0") @[Top.scala 106:25]
      _WIRE[3] <= UInt<1>("h0") @[Top.scala 106:25]
      _WIRE[4] <= UInt<1>("h0") @[Top.scala 106:25]
      _WIRE[5] <= UInt<1>("h0") @[Top.scala 106:25]
      _WIRE[6] <= UInt<1>("h0") @[Top.scala 106:25]
      _WIRE[7] <= UInt<1>("h0") @[Top.scala 106:25]
      fifo <= _WIRE @[Top.scala 106:15]
      w_ptr <= UInt<1>("h0") @[Top.scala 107:15]
      r_ptr <= UInt<1>("h0") @[Top.scala 108:15]
      count <= UInt<1>("h0") @[Top.scala 109:15]
      ready <= UInt<1>("h0") @[Top.scala 110:15]
      overflow <= UInt<1>("h0") @[Top.scala 111:15]
    else :
      node _T_1 = eq(io.nextdata_n, UInt<1>("h0")) @[Top.scala 113:20]
      node _T_2 = and(ready, _T_1) @[Top.scala 113:17]
      when _T_2 : @[Top.scala 113:36]
        node _r_ptr_T = eq(r_ptr, UInt<3>("h7")) @[Top.scala 114:26]
        node _r_ptr_T_1 = add(r_ptr, UInt<1>("h1")) @[Top.scala 114:46]
        node _r_ptr_T_2 = tail(_r_ptr_T_1, 1) @[Top.scala 114:46]
        node _r_ptr_T_3 = mux(_r_ptr_T, UInt<1>("h0"), _r_ptr_T_2) @[Top.scala 114:19]
        r_ptr <= _r_ptr_T_3 @[Top.scala 114:13]
        node _ready_T = eq(r_ptr, UInt<3>("h7")) @[Top.scala 115:38]
        node _ready_T_1 = add(r_ptr, UInt<1>("h1")) @[Top.scala 115:58]
        node _ready_T_2 = tail(_ready_T_1, 1) @[Top.scala 115:58]
        node _ready_T_3 = mux(_ready_T, UInt<1>("h0"), _ready_T_2) @[Top.scala 115:31]
        node _ready_T_4 = eq(w_ptr, _ready_T_3) @[Top.scala 115:24]
        node _ready_T_5 = eq(_ready_T_4, UInt<1>("h0")) @[Top.scala 115:16]
        ready <= _ready_T_5 @[Top.scala 115:13]
      when sampling : @[Top.scala 118:21]
        node _T_3 = eq(count, UInt<4>("ha")) @[Top.scala 119:19]
        when _T_3 : @[Top.scala 119:29]
          node _valid_T = bits(buffer, 0, 0) @[Top.scala 120:27]
          node _valid_T_1 = eq(_valid_T, UInt<1>("h0")) @[Top.scala 120:31]
          node _valid_T_2 = eq(io.ps2_data, UInt<1>("h1")) @[Top.scala 121:32]
          node _valid_T_3 = and(_valid_T_1, _valid_T_2) @[Top.scala 120:39]
          node _valid_T_4 = bits(buffer, 9, 1) @[Top.scala 122:27]
          node _valid_T_5 = xorr(_valid_T_4) @[Top.scala 122:38]
          node _valid_T_6 = eq(_valid_T_5, UInt<1>("h1")) @[Top.scala 122:41]
          node valid = and(_valid_T_3, _valid_T_6) @[Top.scala 121:40]
          when valid : @[Top.scala 124:22]
            node _fifo_T = bits(buffer, 8, 1) @[Top.scala 125:32]
            fifo[w_ptr] <= _fifo_T @[Top.scala 125:23]
            node _w_ptr_T = eq(w_ptr, UInt<3>("h7")) @[Top.scala 126:30]
            node _w_ptr_T_1 = add(w_ptr, UInt<1>("h1")) @[Top.scala 126:50]
            node _w_ptr_T_2 = tail(_w_ptr_T_1, 1) @[Top.scala 126:50]
            node _w_ptr_T_3 = mux(_w_ptr_T, UInt<1>("h0"), _w_ptr_T_2) @[Top.scala 126:23]
            w_ptr <= _w_ptr_T_3 @[Top.scala 126:17]
            ready <= UInt<1>("h1") @[Top.scala 127:17]
            node _T_4 = eq(w_ptr, UInt<3>("h7")) @[Top.scala 129:37]
            node _T_5 = add(w_ptr, UInt<1>("h1")) @[Top.scala 129:57]
            node _T_6 = tail(_T_5, 1) @[Top.scala 129:57]
            node _T_7 = mux(_T_4, UInt<1>("h0"), _T_6) @[Top.scala 129:30]
            node _T_8 = eq(r_ptr, _T_7) @[Top.scala 129:23]
            when _T_8 : @[Top.scala 129:65]
              overflow <= UInt<1>("h1") @[Top.scala 130:22]
          count <= UInt<1>("h0") @[Top.scala 133:15]
        else :
          node _bufferVec_T = bits(buffer, 0, 0) @[Top.scala 135:40]
          node _bufferVec_T_1 = bits(buffer, 1, 1) @[Top.scala 135:40]
          node _bufferVec_T_2 = bits(buffer, 2, 2) @[Top.scala 135:40]
          node _bufferVec_T_3 = bits(buffer, 3, 3) @[Top.scala 135:40]
          node _bufferVec_T_4 = bits(buffer, 4, 4) @[Top.scala 135:40]
          node _bufferVec_T_5 = bits(buffer, 5, 5) @[Top.scala 135:40]
          node _bufferVec_T_6 = bits(buffer, 6, 6) @[Top.scala 135:40]
          node _bufferVec_T_7 = bits(buffer, 7, 7) @[Top.scala 135:40]
          node _bufferVec_T_8 = bits(buffer, 8, 8) @[Top.scala 135:40]
          node _bufferVec_T_9 = bits(buffer, 9, 9) @[Top.scala 135:40]
          wire bufferVec : UInt<1>[10] @[Top.scala 135:32]
          bufferVec[0] <= _bufferVec_T @[Top.scala 135:32]
          bufferVec[1] <= _bufferVec_T_1 @[Top.scala 135:32]
          bufferVec[2] <= _bufferVec_T_2 @[Top.scala 135:32]
          bufferVec[3] <= _bufferVec_T_3 @[Top.scala 135:32]
          bufferVec[4] <= _bufferVec_T_4 @[Top.scala 135:32]
          bufferVec[5] <= _bufferVec_T_5 @[Top.scala 135:32]
          bufferVec[6] <= _bufferVec_T_6 @[Top.scala 135:32]
          bufferVec[7] <= _bufferVec_T_7 @[Top.scala 135:32]
          bufferVec[8] <= _bufferVec_T_8 @[Top.scala 135:32]
          bufferVec[9] <= _bufferVec_T_9 @[Top.scala 135:32]
          bufferVec[count] <= io.ps2_data @[Top.scala 136:26]
          node buffer_lo_lo = cat(bufferVec[1], bufferVec[0]) @[Top.scala 137:29]
          node buffer_lo_hi_hi = cat(bufferVec[4], bufferVec[3]) @[Top.scala 137:29]
          node buffer_lo_hi = cat(buffer_lo_hi_hi, bufferVec[2]) @[Top.scala 137:29]
          node buffer_lo = cat(buffer_lo_hi, buffer_lo_lo) @[Top.scala 137:29]
          node buffer_hi_lo = cat(bufferVec[6], bufferVec[5]) @[Top.scala 137:29]
          node buffer_hi_hi_hi = cat(bufferVec[9], bufferVec[8]) @[Top.scala 137:29]
          node buffer_hi_hi = cat(buffer_hi_hi_hi, bufferVec[7]) @[Top.scala 137:29]
          node buffer_hi = cat(buffer_hi_hi, buffer_hi_lo) @[Top.scala 137:29]
          node _buffer_T = cat(buffer_hi, buffer_lo) @[Top.scala 137:29]
          buffer <= _buffer_T @[Top.scala 137:16]
          node _count_T = add(count, UInt<1>("h1")) @[Top.scala 138:24]
          node _count_T_1 = tail(_count_T, 1) @[Top.scala 138:24]
          count <= _count_T_1 @[Top.scala 138:15]
    io.data <= fifo[r_ptr] @[Top.scala 143:15]
    io.ready <= ready @[Top.scala 144:15]
    io.overflow <= overflow @[Top.scala 145:15]

  module Ps2_decoder :
    input clock : Clock
    input reset : Reset
    output io : { flip keycode : UInt<8>, flip clrn : UInt<1>, ascii : UInt<8>, pressed : UInt<1>}

    reg isBreakCode : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 156:30]
    reg lastKeycode : UInt<8>, clock with :
      reset => (reset, UInt<8>("h0")) @[Top.scala 157:30]
    io.pressed <= UInt<1>("h0") @[Top.scala 159:16]
    io.ascii <= UInt<1>("h0") @[Top.scala 160:14]
    node _T = eq(io.clrn, UInt<1>("h0")) @[Top.scala 162:10]
    when _T : @[Top.scala 162:20]
      isBreakCode <= UInt<1>("h0") @[Top.scala 163:21]
      lastKeycode <= UInt<1>("h0") @[Top.scala 164:21]
      io.ascii <= UInt<1>("h0") @[Top.scala 165:18]
      io.pressed <= UInt<1>("h0") @[Top.scala 166:20]
    else :
      node _T_1 = eq(io.keycode, UInt<8>("hf0")) @[Top.scala 168:25]
      when _T_1 : @[Top.scala 168:37]
        isBreakCode <= UInt<1>("h1") @[Top.scala 169:25]
      else :
        when isBreakCode : @[Top.scala 171:31]
          isBreakCode <= UInt<1>("h0") @[Top.scala 172:29]
          io.pressed <= UInt<1>("h0") @[Top.scala 173:28]
        else :
          lastKeycode <= io.keycode @[Top.scala 175:29]
          io.pressed <= UInt<1>("h1") @[Top.scala 176:28]
          node _T_2 = eq(UInt<7>("h45"), io.keycode) @[Top.scala 178:36]
          when _T_2 : @[Top.scala 178:36]
            io.ascii <= UInt<6>("h30") @[Top.scala 179:43]
          else :
            node _T_3 = eq(UInt<5>("h16"), io.keycode) @[Top.scala 178:36]
            when _T_3 : @[Top.scala 178:36]
              io.ascii <= UInt<6>("h31") @[Top.scala 180:43]
            else :
              node _T_4 = eq(UInt<5>("h1e"), io.keycode) @[Top.scala 178:36]
              when _T_4 : @[Top.scala 178:36]
                io.ascii <= UInt<6>("h32") @[Top.scala 181:43]
              else :
                node _T_5 = eq(UInt<6>("h26"), io.keycode) @[Top.scala 178:36]
                when _T_5 : @[Top.scala 178:36]
                  io.ascii <= UInt<6>("h33") @[Top.scala 182:43]
                else :
                  node _T_6 = eq(UInt<6>("h25"), io.keycode) @[Top.scala 178:36]
                  when _T_6 : @[Top.scala 178:36]
                    io.ascii <= UInt<6>("h34") @[Top.scala 183:43]
                  else :
                    node _T_7 = eq(UInt<6>("h2e"), io.keycode) @[Top.scala 178:36]
                    when _T_7 : @[Top.scala 178:36]
                      io.ascii <= UInt<6>("h35") @[Top.scala 184:43]
                    else :
                      node _T_8 = eq(UInt<6>("h36"), io.keycode) @[Top.scala 178:36]
                      when _T_8 : @[Top.scala 178:36]
                        io.ascii <= UInt<6>("h36") @[Top.scala 185:43]
                      else :
                        node _T_9 = eq(UInt<6>("h3d"), io.keycode) @[Top.scala 178:36]
                        when _T_9 : @[Top.scala 178:36]
                          io.ascii <= UInt<6>("h37") @[Top.scala 186:43]
                        else :
                          node _T_10 = eq(UInt<6>("h3e"), io.keycode) @[Top.scala 178:36]
                          when _T_10 : @[Top.scala 178:36]
                            io.ascii <= UInt<6>("h38") @[Top.scala 187:43]
                          else :
                            node _T_11 = eq(UInt<7>("h46"), io.keycode) @[Top.scala 178:36]
                            when _T_11 : @[Top.scala 178:36]
                              io.ascii <= UInt<6>("h39") @[Top.scala 188:43]
                            else :
                              node _T_12 = eq(UInt<5>("h1c"), io.keycode) @[Top.scala 178:36]
                              when _T_12 : @[Top.scala 178:36]
                                io.ascii <= UInt<7>("h41") @[Top.scala 190:43]
                              else :
                                node _T_13 = eq(UInt<6>("h32"), io.keycode) @[Top.scala 178:36]
                                when _T_13 : @[Top.scala 178:36]
                                  io.ascii <= UInt<7>("h42") @[Top.scala 191:43]
                                else :
                                  node _T_14 = eq(UInt<6>("h21"), io.keycode) @[Top.scala 178:36]
                                  when _T_14 : @[Top.scala 178:36]
                                    io.ascii <= UInt<7>("h43") @[Top.scala 192:43]
                                  else :
                                    node _T_15 = eq(UInt<6>("h23"), io.keycode) @[Top.scala 178:36]
                                    when _T_15 : @[Top.scala 178:36]
                                      io.ascii <= UInt<7>("h44") @[Top.scala 193:43]
                                    else :
                                      node _T_16 = eq(UInt<6>("h24"), io.keycode) @[Top.scala 178:36]
                                      when _T_16 : @[Top.scala 178:36]
                                        io.ascii <= UInt<7>("h45") @[Top.scala 194:43]
                                      else :
                                        node _T_17 = eq(UInt<6>("h2b"), io.keycode) @[Top.scala 178:36]
                                        when _T_17 : @[Top.scala 178:36]
                                          io.ascii <= UInt<7>("h46") @[Top.scala 195:43]
                                        else :
                                          node _T_18 = eq(UInt<6>("h34"), io.keycode) @[Top.scala 178:36]
                                          when _T_18 : @[Top.scala 178:36]
                                            io.ascii <= UInt<7>("h47") @[Top.scala 196:43]
                                          else :
                                            node _T_19 = eq(UInt<6>("h33"), io.keycode) @[Top.scala 178:36]
                                            when _T_19 : @[Top.scala 178:36]
                                              io.ascii <= UInt<7>("h48") @[Top.scala 197:43]
                                            else :
                                              node _T_20 = eq(UInt<7>("h43"), io.keycode) @[Top.scala 178:36]
                                              when _T_20 : @[Top.scala 178:36]
                                                io.ascii <= UInt<7>("h49") @[Top.scala 198:43]
                                              else :
                                                node _T_21 = eq(UInt<6>("h3b"), io.keycode) @[Top.scala 178:36]
                                                when _T_21 : @[Top.scala 178:36]
                                                  io.ascii <= UInt<7>("h4a") @[Top.scala 199:43]
                                                else :
                                                  node _T_22 = eq(UInt<7>("h42"), io.keycode) @[Top.scala 178:36]
                                                  when _T_22 : @[Top.scala 178:36]
                                                    io.ascii <= UInt<7>("h4b") @[Top.scala 200:43]
                                                  else :
                                                    node _T_23 = eq(UInt<7>("h4b"), io.keycode) @[Top.scala 178:36]
                                                    when _T_23 : @[Top.scala 178:36]
                                                      io.ascii <= UInt<7>("h4c") @[Top.scala 201:43]
                                                    else :
                                                      node _T_24 = eq(UInt<6>("h3a"), io.keycode) @[Top.scala 178:36]
                                                      when _T_24 : @[Top.scala 178:36]
                                                        io.ascii <= UInt<7>("h4d") @[Top.scala 202:43]
                                                      else :
                                                        node _T_25 = eq(UInt<6>("h31"), io.keycode) @[Top.scala 178:36]
                                                        when _T_25 : @[Top.scala 178:36]
                                                          io.ascii <= UInt<7>("h4e") @[Top.scala 203:43]
                                                        else :
                                                          node _T_26 = eq(UInt<7>("h44"), io.keycode) @[Top.scala 178:36]
                                                          when _T_26 : @[Top.scala 178:36]
                                                            io.ascii <= UInt<7>("h4f") @[Top.scala 204:43]
                                                          else :
                                                            node _T_27 = eq(UInt<7>("h4d"), io.keycode) @[Top.scala 178:36]
                                                            when _T_27 : @[Top.scala 178:36]
                                                              io.ascii <= UInt<7>("h50") @[Top.scala 205:43]
                                                            else :
                                                              node _T_28 = eq(UInt<5>("h15"), io.keycode) @[Top.scala 178:36]
                                                              when _T_28 : @[Top.scala 178:36]
                                                                io.ascii <= UInt<7>("h51") @[Top.scala 206:43]
                                                              else :
                                                                node _T_29 = eq(UInt<6>("h2d"), io.keycode) @[Top.scala 178:36]
                                                                when _T_29 : @[Top.scala 178:36]
                                                                  io.ascii <= UInt<7>("h52") @[Top.scala 207:43]
                                                                else :
                                                                  node _T_30 = eq(UInt<5>("h1b"), io.keycode) @[Top.scala 178:36]
                                                                  when _T_30 : @[Top.scala 178:36]
                                                                    io.ascii <= UInt<7>("h53") @[Top.scala 208:43]
                                                                  else :
                                                                    node _T_31 = eq(UInt<6>("h2c"), io.keycode) @[Top.scala 178:36]
                                                                    when _T_31 : @[Top.scala 178:36]
                                                                      io.ascii <= UInt<7>("h54") @[Top.scala 209:43]
                                                                    else :
                                                                      node _T_32 = eq(UInt<6>("h3c"), io.keycode) @[Top.scala 178:36]
                                                                      when _T_32 : @[Top.scala 178:36]
                                                                        io.ascii <= UInt<7>("h55") @[Top.scala 210:43]
                                                                      else :
                                                                        node _T_33 = eq(UInt<6>("h2a"), io.keycode) @[Top.scala 178:36]
                                                                        when _T_33 : @[Top.scala 178:36]
                                                                          io.ascii <= UInt<7>("h56") @[Top.scala 211:43]
                                                                        else :
                                                                          node _T_34 = eq(UInt<5>("h1d"), io.keycode) @[Top.scala 178:36]
                                                                          when _T_34 : @[Top.scala 178:36]
                                                                            io.ascii <= UInt<7>("h57") @[Top.scala 212:43]
                                                                          else :
                                                                            node _T_35 = eq(UInt<5>("h1a"), io.keycode) @[Top.scala 178:36]
                                                                            when _T_35 : @[Top.scala 178:36]
                                                                              io.ascii <= UInt<7>("h58") @[Top.scala 213:43]
                                                                            else :
                                                                              node _T_36 = eq(UInt<6>("h22"), io.keycode) @[Top.scala 178:36]
                                                                              when _T_36 : @[Top.scala 178:36]
                                                                                io.ascii <= UInt<7>("h59") @[Top.scala 214:43]
                                                                              else :
                                                                                node _T_37 = eq(UInt<5>("h14"), io.keycode) @[Top.scala 178:36]
                                                                                when _T_37 : @[Top.scala 178:36]
                                                                                  io.ascii <= UInt<7>("h5a") @[Top.scala 215:43]

  module Seg :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 245:10]
    node _T = eq(UInt<1>("h0"), io.in) @[Top.scala 247:17]
    when _T : @[Top.scala 247:17]
      node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 248:26]
      io.seg <= _io_seg_T @[Top.scala 248:23]
    else :
      node _T_1 = eq(UInt<1>("h1"), io.in) @[Top.scala 247:17]
      when _T_1 : @[Top.scala 247:17]
        node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 249:26]
        io.seg <= _io_seg_T_1 @[Top.scala 249:23]
      else :
        node _T_2 = eq(UInt<2>("h2"), io.in) @[Top.scala 247:17]
        when _T_2 : @[Top.scala 247:17]
          node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 250:26]
          io.seg <= _io_seg_T_2 @[Top.scala 250:23]
        else :
          node _T_3 = eq(UInt<2>("h3"), io.in) @[Top.scala 247:17]
          when _T_3 : @[Top.scala 247:17]
            node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 251:26]
            io.seg <= _io_seg_T_3 @[Top.scala 251:23]
          else :
            node _T_4 = eq(UInt<3>("h4"), io.in) @[Top.scala 247:17]
            when _T_4 : @[Top.scala 247:17]
              node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 252:26]
              io.seg <= _io_seg_T_4 @[Top.scala 252:23]
            else :
              node _T_5 = eq(UInt<3>("h5"), io.in) @[Top.scala 247:17]
              when _T_5 : @[Top.scala 247:17]
                node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 253:26]
                io.seg <= _io_seg_T_5 @[Top.scala 253:23]
              else :
                node _T_6 = eq(UInt<3>("h6"), io.in) @[Top.scala 247:17]
                when _T_6 : @[Top.scala 247:17]
                  node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 254:26]
                  io.seg <= _io_seg_T_6 @[Top.scala 254:23]
                else :
                  node _T_7 = eq(UInt<3>("h7"), io.in) @[Top.scala 247:17]
                  when _T_7 : @[Top.scala 247:17]
                    node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 255:26]
                    io.seg <= _io_seg_T_7 @[Top.scala 255:23]
                  else :
                    node _T_8 = eq(UInt<4>("h8"), io.in) @[Top.scala 247:17]
                    when _T_8 : @[Top.scala 247:17]
                      node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 256:26]
                      io.seg <= _io_seg_T_8 @[Top.scala 256:23]
                    else :
                      node _T_9 = eq(UInt<4>("h9"), io.in) @[Top.scala 247:17]
                      when _T_9 : @[Top.scala 247:17]
                        node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 257:26]
                        io.seg <= _io_seg_T_9 @[Top.scala 257:23]
                      else :
                        node _T_10 = eq(UInt<4>("ha"), io.in) @[Top.scala 247:17]
                        when _T_10 : @[Top.scala 247:17]
                          node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 258:26]
                          io.seg <= _io_seg_T_10 @[Top.scala 258:23]
                        else :
                          node _T_11 = eq(UInt<4>("hb"), io.in) @[Top.scala 247:17]
                          when _T_11 : @[Top.scala 247:17]
                            node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 259:26]
                            io.seg <= _io_seg_T_11 @[Top.scala 259:23]
                          else :
                            node _T_12 = eq(UInt<4>("hc"), io.in) @[Top.scala 247:17]
                            when _T_12 : @[Top.scala 247:17]
                              node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 260:26]
                              io.seg <= _io_seg_T_12 @[Top.scala 260:23]
                            else :
                              node _T_13 = eq(UInt<4>("hd"), io.in) @[Top.scala 247:17]
                              when _T_13 : @[Top.scala 247:17]
                                node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 261:26]
                                io.seg <= _io_seg_T_13 @[Top.scala 261:23]
                              else :
                                node _T_14 = eq(UInt<4>("he"), io.in) @[Top.scala 247:17]
                                when _T_14 : @[Top.scala 247:17]
                                  node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 262:26]
                                  io.seg <= _io_seg_T_14 @[Top.scala 262:23]
                                else :
                                  node _T_15 = eq(UInt<4>("hf"), io.in) @[Top.scala 247:17]
                                  when _T_15 : @[Top.scala 247:17]
                                    io.seg <= UInt<8>("hff") @[Top.scala 263:23]

  module Seg_1 :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 245:10]
    node _T = eq(UInt<1>("h0"), io.in) @[Top.scala 247:17]
    when _T : @[Top.scala 247:17]
      node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 248:26]
      io.seg <= _io_seg_T @[Top.scala 248:23]
    else :
      node _T_1 = eq(UInt<1>("h1"), io.in) @[Top.scala 247:17]
      when _T_1 : @[Top.scala 247:17]
        node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 249:26]
        io.seg <= _io_seg_T_1 @[Top.scala 249:23]
      else :
        node _T_2 = eq(UInt<2>("h2"), io.in) @[Top.scala 247:17]
        when _T_2 : @[Top.scala 247:17]
          node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 250:26]
          io.seg <= _io_seg_T_2 @[Top.scala 250:23]
        else :
          node _T_3 = eq(UInt<2>("h3"), io.in) @[Top.scala 247:17]
          when _T_3 : @[Top.scala 247:17]
            node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 251:26]
            io.seg <= _io_seg_T_3 @[Top.scala 251:23]
          else :
            node _T_4 = eq(UInt<3>("h4"), io.in) @[Top.scala 247:17]
            when _T_4 : @[Top.scala 247:17]
              node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 252:26]
              io.seg <= _io_seg_T_4 @[Top.scala 252:23]
            else :
              node _T_5 = eq(UInt<3>("h5"), io.in) @[Top.scala 247:17]
              when _T_5 : @[Top.scala 247:17]
                node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 253:26]
                io.seg <= _io_seg_T_5 @[Top.scala 253:23]
              else :
                node _T_6 = eq(UInt<3>("h6"), io.in) @[Top.scala 247:17]
                when _T_6 : @[Top.scala 247:17]
                  node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 254:26]
                  io.seg <= _io_seg_T_6 @[Top.scala 254:23]
                else :
                  node _T_7 = eq(UInt<3>("h7"), io.in) @[Top.scala 247:17]
                  when _T_7 : @[Top.scala 247:17]
                    node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 255:26]
                    io.seg <= _io_seg_T_7 @[Top.scala 255:23]
                  else :
                    node _T_8 = eq(UInt<4>("h8"), io.in) @[Top.scala 247:17]
                    when _T_8 : @[Top.scala 247:17]
                      node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 256:26]
                      io.seg <= _io_seg_T_8 @[Top.scala 256:23]
                    else :
                      node _T_9 = eq(UInt<4>("h9"), io.in) @[Top.scala 247:17]
                      when _T_9 : @[Top.scala 247:17]
                        node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 257:26]
                        io.seg <= _io_seg_T_9 @[Top.scala 257:23]
                      else :
                        node _T_10 = eq(UInt<4>("ha"), io.in) @[Top.scala 247:17]
                        when _T_10 : @[Top.scala 247:17]
                          node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 258:26]
                          io.seg <= _io_seg_T_10 @[Top.scala 258:23]
                        else :
                          node _T_11 = eq(UInt<4>("hb"), io.in) @[Top.scala 247:17]
                          when _T_11 : @[Top.scala 247:17]
                            node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 259:26]
                            io.seg <= _io_seg_T_11 @[Top.scala 259:23]
                          else :
                            node _T_12 = eq(UInt<4>("hc"), io.in) @[Top.scala 247:17]
                            when _T_12 : @[Top.scala 247:17]
                              node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 260:26]
                              io.seg <= _io_seg_T_12 @[Top.scala 260:23]
                            else :
                              node _T_13 = eq(UInt<4>("hd"), io.in) @[Top.scala 247:17]
                              when _T_13 : @[Top.scala 247:17]
                                node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 261:26]
                                io.seg <= _io_seg_T_13 @[Top.scala 261:23]
                              else :
                                node _T_14 = eq(UInt<4>("he"), io.in) @[Top.scala 247:17]
                                when _T_14 : @[Top.scala 247:17]
                                  node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 262:26]
                                  io.seg <= _io_seg_T_14 @[Top.scala 262:23]
                                else :
                                  node _T_15 = eq(UInt<4>("hf"), io.in) @[Top.scala 247:17]
                                  when _T_15 : @[Top.scala 247:17]
                                    io.seg <= UInt<8>("hff") @[Top.scala 263:23]

  module Seg_2 :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 245:10]
    node _T = eq(UInt<1>("h0"), io.in) @[Top.scala 247:17]
    when _T : @[Top.scala 247:17]
      node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 248:26]
      io.seg <= _io_seg_T @[Top.scala 248:23]
    else :
      node _T_1 = eq(UInt<1>("h1"), io.in) @[Top.scala 247:17]
      when _T_1 : @[Top.scala 247:17]
        node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 249:26]
        io.seg <= _io_seg_T_1 @[Top.scala 249:23]
      else :
        node _T_2 = eq(UInt<2>("h2"), io.in) @[Top.scala 247:17]
        when _T_2 : @[Top.scala 247:17]
          node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 250:26]
          io.seg <= _io_seg_T_2 @[Top.scala 250:23]
        else :
          node _T_3 = eq(UInt<2>("h3"), io.in) @[Top.scala 247:17]
          when _T_3 : @[Top.scala 247:17]
            node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 251:26]
            io.seg <= _io_seg_T_3 @[Top.scala 251:23]
          else :
            node _T_4 = eq(UInt<3>("h4"), io.in) @[Top.scala 247:17]
            when _T_4 : @[Top.scala 247:17]
              node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 252:26]
              io.seg <= _io_seg_T_4 @[Top.scala 252:23]
            else :
              node _T_5 = eq(UInt<3>("h5"), io.in) @[Top.scala 247:17]
              when _T_5 : @[Top.scala 247:17]
                node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 253:26]
                io.seg <= _io_seg_T_5 @[Top.scala 253:23]
              else :
                node _T_6 = eq(UInt<3>("h6"), io.in) @[Top.scala 247:17]
                when _T_6 : @[Top.scala 247:17]
                  node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 254:26]
                  io.seg <= _io_seg_T_6 @[Top.scala 254:23]
                else :
                  node _T_7 = eq(UInt<3>("h7"), io.in) @[Top.scala 247:17]
                  when _T_7 : @[Top.scala 247:17]
                    node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 255:26]
                    io.seg <= _io_seg_T_7 @[Top.scala 255:23]
                  else :
                    node _T_8 = eq(UInt<4>("h8"), io.in) @[Top.scala 247:17]
                    when _T_8 : @[Top.scala 247:17]
                      node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 256:26]
                      io.seg <= _io_seg_T_8 @[Top.scala 256:23]
                    else :
                      node _T_9 = eq(UInt<4>("h9"), io.in) @[Top.scala 247:17]
                      when _T_9 : @[Top.scala 247:17]
                        node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 257:26]
                        io.seg <= _io_seg_T_9 @[Top.scala 257:23]
                      else :
                        node _T_10 = eq(UInt<4>("ha"), io.in) @[Top.scala 247:17]
                        when _T_10 : @[Top.scala 247:17]
                          node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 258:26]
                          io.seg <= _io_seg_T_10 @[Top.scala 258:23]
                        else :
                          node _T_11 = eq(UInt<4>("hb"), io.in) @[Top.scala 247:17]
                          when _T_11 : @[Top.scala 247:17]
                            node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 259:26]
                            io.seg <= _io_seg_T_11 @[Top.scala 259:23]
                          else :
                            node _T_12 = eq(UInt<4>("hc"), io.in) @[Top.scala 247:17]
                            when _T_12 : @[Top.scala 247:17]
                              node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 260:26]
                              io.seg <= _io_seg_T_12 @[Top.scala 260:23]
                            else :
                              node _T_13 = eq(UInt<4>("hd"), io.in) @[Top.scala 247:17]
                              when _T_13 : @[Top.scala 247:17]
                                node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 261:26]
                                io.seg <= _io_seg_T_13 @[Top.scala 261:23]
                              else :
                                node _T_14 = eq(UInt<4>("he"), io.in) @[Top.scala 247:17]
                                when _T_14 : @[Top.scala 247:17]
                                  node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 262:26]
                                  io.seg <= _io_seg_T_14 @[Top.scala 262:23]
                                else :
                                  node _T_15 = eq(UInt<4>("hf"), io.in) @[Top.scala 247:17]
                                  when _T_15 : @[Top.scala 247:17]
                                    io.seg <= UInt<8>("hff") @[Top.scala 263:23]

  module Seg_3 :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 245:10]
    node _T = eq(UInt<1>("h0"), io.in) @[Top.scala 247:17]
    when _T : @[Top.scala 247:17]
      node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 248:26]
      io.seg <= _io_seg_T @[Top.scala 248:23]
    else :
      node _T_1 = eq(UInt<1>("h1"), io.in) @[Top.scala 247:17]
      when _T_1 : @[Top.scala 247:17]
        node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 249:26]
        io.seg <= _io_seg_T_1 @[Top.scala 249:23]
      else :
        node _T_2 = eq(UInt<2>("h2"), io.in) @[Top.scala 247:17]
        when _T_2 : @[Top.scala 247:17]
          node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 250:26]
          io.seg <= _io_seg_T_2 @[Top.scala 250:23]
        else :
          node _T_3 = eq(UInt<2>("h3"), io.in) @[Top.scala 247:17]
          when _T_3 : @[Top.scala 247:17]
            node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 251:26]
            io.seg <= _io_seg_T_3 @[Top.scala 251:23]
          else :
            node _T_4 = eq(UInt<3>("h4"), io.in) @[Top.scala 247:17]
            when _T_4 : @[Top.scala 247:17]
              node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 252:26]
              io.seg <= _io_seg_T_4 @[Top.scala 252:23]
            else :
              node _T_5 = eq(UInt<3>("h5"), io.in) @[Top.scala 247:17]
              when _T_5 : @[Top.scala 247:17]
                node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 253:26]
                io.seg <= _io_seg_T_5 @[Top.scala 253:23]
              else :
                node _T_6 = eq(UInt<3>("h6"), io.in) @[Top.scala 247:17]
                when _T_6 : @[Top.scala 247:17]
                  node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 254:26]
                  io.seg <= _io_seg_T_6 @[Top.scala 254:23]
                else :
                  node _T_7 = eq(UInt<3>("h7"), io.in) @[Top.scala 247:17]
                  when _T_7 : @[Top.scala 247:17]
                    node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 255:26]
                    io.seg <= _io_seg_T_7 @[Top.scala 255:23]
                  else :
                    node _T_8 = eq(UInt<4>("h8"), io.in) @[Top.scala 247:17]
                    when _T_8 : @[Top.scala 247:17]
                      node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 256:26]
                      io.seg <= _io_seg_T_8 @[Top.scala 256:23]
                    else :
                      node _T_9 = eq(UInt<4>("h9"), io.in) @[Top.scala 247:17]
                      when _T_9 : @[Top.scala 247:17]
                        node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 257:26]
                        io.seg <= _io_seg_T_9 @[Top.scala 257:23]
                      else :
                        node _T_10 = eq(UInt<4>("ha"), io.in) @[Top.scala 247:17]
                        when _T_10 : @[Top.scala 247:17]
                          node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 258:26]
                          io.seg <= _io_seg_T_10 @[Top.scala 258:23]
                        else :
                          node _T_11 = eq(UInt<4>("hb"), io.in) @[Top.scala 247:17]
                          when _T_11 : @[Top.scala 247:17]
                            node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 259:26]
                            io.seg <= _io_seg_T_11 @[Top.scala 259:23]
                          else :
                            node _T_12 = eq(UInt<4>("hc"), io.in) @[Top.scala 247:17]
                            when _T_12 : @[Top.scala 247:17]
                              node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 260:26]
                              io.seg <= _io_seg_T_12 @[Top.scala 260:23]
                            else :
                              node _T_13 = eq(UInt<4>("hd"), io.in) @[Top.scala 247:17]
                              when _T_13 : @[Top.scala 247:17]
                                node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 261:26]
                                io.seg <= _io_seg_T_13 @[Top.scala 261:23]
                              else :
                                node _T_14 = eq(UInt<4>("he"), io.in) @[Top.scala 247:17]
                                when _T_14 : @[Top.scala 247:17]
                                  node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 262:26]
                                  io.seg <= _io_seg_T_14 @[Top.scala 262:23]
                                else :
                                  node _T_15 = eq(UInt<4>("hf"), io.in) @[Top.scala 247:17]
                                  when _T_15 : @[Top.scala 247:17]
                                    io.seg <= UInt<8>("hff") @[Top.scala 263:23]

  module Seg_4 :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 245:10]
    node _T = eq(UInt<1>("h0"), io.in) @[Top.scala 247:17]
    when _T : @[Top.scala 247:17]
      node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 248:26]
      io.seg <= _io_seg_T @[Top.scala 248:23]
    else :
      node _T_1 = eq(UInt<1>("h1"), io.in) @[Top.scala 247:17]
      when _T_1 : @[Top.scala 247:17]
        node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 249:26]
        io.seg <= _io_seg_T_1 @[Top.scala 249:23]
      else :
        node _T_2 = eq(UInt<2>("h2"), io.in) @[Top.scala 247:17]
        when _T_2 : @[Top.scala 247:17]
          node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 250:26]
          io.seg <= _io_seg_T_2 @[Top.scala 250:23]
        else :
          node _T_3 = eq(UInt<2>("h3"), io.in) @[Top.scala 247:17]
          when _T_3 : @[Top.scala 247:17]
            node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 251:26]
            io.seg <= _io_seg_T_3 @[Top.scala 251:23]
          else :
            node _T_4 = eq(UInt<3>("h4"), io.in) @[Top.scala 247:17]
            when _T_4 : @[Top.scala 247:17]
              node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 252:26]
              io.seg <= _io_seg_T_4 @[Top.scala 252:23]
            else :
              node _T_5 = eq(UInt<3>("h5"), io.in) @[Top.scala 247:17]
              when _T_5 : @[Top.scala 247:17]
                node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 253:26]
                io.seg <= _io_seg_T_5 @[Top.scala 253:23]
              else :
                node _T_6 = eq(UInt<3>("h6"), io.in) @[Top.scala 247:17]
                when _T_6 : @[Top.scala 247:17]
                  node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 254:26]
                  io.seg <= _io_seg_T_6 @[Top.scala 254:23]
                else :
                  node _T_7 = eq(UInt<3>("h7"), io.in) @[Top.scala 247:17]
                  when _T_7 : @[Top.scala 247:17]
                    node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 255:26]
                    io.seg <= _io_seg_T_7 @[Top.scala 255:23]
                  else :
                    node _T_8 = eq(UInt<4>("h8"), io.in) @[Top.scala 247:17]
                    when _T_8 : @[Top.scala 247:17]
                      node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 256:26]
                      io.seg <= _io_seg_T_8 @[Top.scala 256:23]
                    else :
                      node _T_9 = eq(UInt<4>("h9"), io.in) @[Top.scala 247:17]
                      when _T_9 : @[Top.scala 247:17]
                        node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 257:26]
                        io.seg <= _io_seg_T_9 @[Top.scala 257:23]
                      else :
                        node _T_10 = eq(UInt<4>("ha"), io.in) @[Top.scala 247:17]
                        when _T_10 : @[Top.scala 247:17]
                          node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 258:26]
                          io.seg <= _io_seg_T_10 @[Top.scala 258:23]
                        else :
                          node _T_11 = eq(UInt<4>("hb"), io.in) @[Top.scala 247:17]
                          when _T_11 : @[Top.scala 247:17]
                            node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 259:26]
                            io.seg <= _io_seg_T_11 @[Top.scala 259:23]
                          else :
                            node _T_12 = eq(UInt<4>("hc"), io.in) @[Top.scala 247:17]
                            when _T_12 : @[Top.scala 247:17]
                              node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 260:26]
                              io.seg <= _io_seg_T_12 @[Top.scala 260:23]
                            else :
                              node _T_13 = eq(UInt<4>("hd"), io.in) @[Top.scala 247:17]
                              when _T_13 : @[Top.scala 247:17]
                                node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 261:26]
                                io.seg <= _io_seg_T_13 @[Top.scala 261:23]
                              else :
                                node _T_14 = eq(UInt<4>("he"), io.in) @[Top.scala 247:17]
                                when _T_14 : @[Top.scala 247:17]
                                  node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 262:26]
                                  io.seg <= _io_seg_T_14 @[Top.scala 262:23]
                                else :
                                  node _T_15 = eq(UInt<4>("hf"), io.in) @[Top.scala 247:17]
                                  when _T_15 : @[Top.scala 247:17]
                                    io.seg <= UInt<8>("hff") @[Top.scala 263:23]

  module Seg_5 :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 245:10]
    node _T = eq(UInt<1>("h0"), io.in) @[Top.scala 247:17]
    when _T : @[Top.scala 247:17]
      node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 248:26]
      io.seg <= _io_seg_T @[Top.scala 248:23]
    else :
      node _T_1 = eq(UInt<1>("h1"), io.in) @[Top.scala 247:17]
      when _T_1 : @[Top.scala 247:17]
        node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 249:26]
        io.seg <= _io_seg_T_1 @[Top.scala 249:23]
      else :
        node _T_2 = eq(UInt<2>("h2"), io.in) @[Top.scala 247:17]
        when _T_2 : @[Top.scala 247:17]
          node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 250:26]
          io.seg <= _io_seg_T_2 @[Top.scala 250:23]
        else :
          node _T_3 = eq(UInt<2>("h3"), io.in) @[Top.scala 247:17]
          when _T_3 : @[Top.scala 247:17]
            node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 251:26]
            io.seg <= _io_seg_T_3 @[Top.scala 251:23]
          else :
            node _T_4 = eq(UInt<3>("h4"), io.in) @[Top.scala 247:17]
            when _T_4 : @[Top.scala 247:17]
              node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 252:26]
              io.seg <= _io_seg_T_4 @[Top.scala 252:23]
            else :
              node _T_5 = eq(UInt<3>("h5"), io.in) @[Top.scala 247:17]
              when _T_5 : @[Top.scala 247:17]
                node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 253:26]
                io.seg <= _io_seg_T_5 @[Top.scala 253:23]
              else :
                node _T_6 = eq(UInt<3>("h6"), io.in) @[Top.scala 247:17]
                when _T_6 : @[Top.scala 247:17]
                  node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 254:26]
                  io.seg <= _io_seg_T_6 @[Top.scala 254:23]
                else :
                  node _T_7 = eq(UInt<3>("h7"), io.in) @[Top.scala 247:17]
                  when _T_7 : @[Top.scala 247:17]
                    node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 255:26]
                    io.seg <= _io_seg_T_7 @[Top.scala 255:23]
                  else :
                    node _T_8 = eq(UInt<4>("h8"), io.in) @[Top.scala 247:17]
                    when _T_8 : @[Top.scala 247:17]
                      node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 256:26]
                      io.seg <= _io_seg_T_8 @[Top.scala 256:23]
                    else :
                      node _T_9 = eq(UInt<4>("h9"), io.in) @[Top.scala 247:17]
                      when _T_9 : @[Top.scala 247:17]
                        node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 257:26]
                        io.seg <= _io_seg_T_9 @[Top.scala 257:23]
                      else :
                        node _T_10 = eq(UInt<4>("ha"), io.in) @[Top.scala 247:17]
                        when _T_10 : @[Top.scala 247:17]
                          node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 258:26]
                          io.seg <= _io_seg_T_10 @[Top.scala 258:23]
                        else :
                          node _T_11 = eq(UInt<4>("hb"), io.in) @[Top.scala 247:17]
                          when _T_11 : @[Top.scala 247:17]
                            node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 259:26]
                            io.seg <= _io_seg_T_11 @[Top.scala 259:23]
                          else :
                            node _T_12 = eq(UInt<4>("hc"), io.in) @[Top.scala 247:17]
                            when _T_12 : @[Top.scala 247:17]
                              node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 260:26]
                              io.seg <= _io_seg_T_12 @[Top.scala 260:23]
                            else :
                              node _T_13 = eq(UInt<4>("hd"), io.in) @[Top.scala 247:17]
                              when _T_13 : @[Top.scala 247:17]
                                node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 261:26]
                                io.seg <= _io_seg_T_13 @[Top.scala 261:23]
                              else :
                                node _T_14 = eq(UInt<4>("he"), io.in) @[Top.scala 247:17]
                                when _T_14 : @[Top.scala 247:17]
                                  node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 262:26]
                                  io.seg <= _io_seg_T_14 @[Top.scala 262:23]
                                else :
                                  node _T_15 = eq(UInt<4>("hf"), io.in) @[Top.scala 247:17]
                                  when _T_15 : @[Top.scala 247:17]
                                    io.seg <= UInt<8>("hff") @[Top.scala 263:23]

  module Keycount :
    input clock : Clock
    input reset : Reset
    output io : { flip key_press : UInt<1>, flip clrn : UInt<1>, ones : UInt<4>, tens : UInt<4>}

    reg ones : UInt<4>, clock with :
      reset => (reset, UInt<4>("h0")) @[Top.scala 275:23]
    reg tens : UInt<4>, clock with :
      reset => (reset, UInt<4>("h0")) @[Top.scala 276:23]
    reg prev_key : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 278:27]
    prev_key <= io.key_press @[Top.scala 278:27]
    node _key_rise_T = eq(prev_key, UInt<1>("h0")) @[Top.scala 279:36]
    node key_rise = and(io.key_press, _key_rise_T) @[Top.scala 279:33]
    reg debounce_count : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Top.scala 282:33]
    reg stable_key_press : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 283:35]
    node _T = eq(io.key_press, stable_key_press) @[Top.scala 286:23]
    when _T : @[Top.scala 286:45]
      debounce_count <= UInt<1>("h0") @[Top.scala 287:24]
    else :
      node _debounce_count_T = add(debounce_count, UInt<1>("h1")) @[Top.scala 289:42]
      node _debounce_count_T_1 = tail(_debounce_count_T, 1) @[Top.scala 289:42]
      debounce_count <= _debounce_count_T_1 @[Top.scala 289:24]
    node _T_1 = eq(debounce_count, UInt<3>("h7")) @[Top.scala 293:25]
    when _T_1 : @[Top.scala 293:34]
      stable_key_press <= io.key_press @[Top.scala 294:26]
    reg stable_key_rise_REG : UInt<1>, clock with :
      reset => (UInt<1>("h0"), stable_key_rise_REG) @[Top.scala 298:55]
    stable_key_rise_REG <= stable_key_press @[Top.scala 298:55]
    node _stable_key_rise_T = eq(stable_key_rise_REG, UInt<1>("h0")) @[Top.scala 298:47]
    node stable_key_rise = and(stable_key_press, _stable_key_rise_T) @[Top.scala 298:44]
    node _T_2 = eq(io.clrn, UInt<1>("h0")) @[Top.scala 300:10]
    when _T_2 : @[Top.scala 300:20]
      ones <= UInt<1>("h0") @[Top.scala 301:14]
      tens <= UInt<1>("h0") @[Top.scala 302:14]
    else :
      when stable_key_rise : @[Top.scala 303:34]
        node _T_3 = eq(ones, UInt<4>("h9")) @[Top.scala 305:19]
        when _T_3 : @[Top.scala 305:28]
          ones <= UInt<1>("h0") @[Top.scala 306:18]
          node _tens_T = eq(tens, UInt<4>("h9")) @[Top.scala 307:30]
          node _tens_T_1 = add(tens, UInt<1>("h1")) @[Top.scala 307:49]
          node _tens_T_2 = tail(_tens_T_1, 1) @[Top.scala 307:49]
          node _tens_T_3 = mux(_tens_T, UInt<1>("h0"), _tens_T_2) @[Top.scala 307:24]
          tens <= _tens_T_3 @[Top.scala 307:18]
        else :
          node _ones_T = add(ones, UInt<1>("h1")) @[Top.scala 309:26]
          node _ones_T_1 = tail(_ones_T, 1) @[Top.scala 309:26]
          ones <= _ones_T_1 @[Top.scala 309:18]
    io.ones <= ones @[Top.scala 313:13]
    io.tens <= tens @[Top.scala 314:13]

  module Top :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip clrn : UInt<1>, flip ps2_clk : UInt<1>, flip ps2_data : UInt<1>, seg_out_0 : UInt<8>, seg_out_1 : UInt<8>, seg_out_2 : UInt<8>, seg_out_3 : UInt<8>, seg_out_4 : UInt<8>, seg_out_5 : UInt<8>}

    inst keyboard of PS2Keyboard @[Top.scala 18:26]
    keyboard.clock <= clock
    keyboard.reset <= reset
    keyboard.io.clrn <= io.clrn @[Top.scala 19:26]
    keyboard.io.ps2_clk <= io.ps2_clk @[Top.scala 20:26]
    keyboard.io.ps2_data <= io.ps2_data @[Top.scala 21:26]
    inst decoder of Ps2_decoder @[Top.scala 24:25]
    decoder.clock <= clock
    decoder.reset <= reset
    decoder.io.keycode <= keyboard.io.data @[Top.scala 25:26]
    decoder.io.clrn <= io.clrn @[Top.scala 26:26]
    inst seg0 of Seg @[Top.scala 29:22]
    seg0.clock <= clock
    seg0.reset <= reset
    inst seg1 of Seg_1 @[Top.scala 30:22]
    seg1.clock <= clock
    seg1.reset <= reset
    inst seg2 of Seg_2 @[Top.scala 31:22]
    seg2.clock <= clock
    seg2.reset <= reset
    inst seg3 of Seg_3 @[Top.scala 32:22]
    seg3.clock <= clock
    seg3.reset <= reset
    inst seg4 of Seg_4 @[Top.scala 33:22]
    seg4.clock <= clock
    seg4.reset <= reset
    inst seg5 of Seg_5 @[Top.scala 34:22]
    seg5.clock <= clock
    seg5.reset <= reset
    inst counter of Keycount @[Top.scala 37:25]
    counter.clock <= clock
    counter.reset <= reset
    counter.io.key_press <= decoder.io.pressed @[Top.scala 38:26]
    counter.io.clrn <= io.clrn @[Top.scala 39:21]
    reg nextdata_n : UInt<1>, clock with :
      reset => (reset, UInt<1>("h1")) @[Top.scala 42:29]
    keyboard.io.nextdata_n <= nextdata_n @[Top.scala 43:28]
    reg ready_delay : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 45:30]
    ready_delay <= keyboard.io.ready @[Top.scala 45:30]
    node _T = eq(ready_delay, UInt<1>("h0")) @[Top.scala 46:31]
    node _T_1 = and(keyboard.io.ready, _T) @[Top.scala 46:28]
    when _T_1 : @[Top.scala 46:45]
      nextdata_n <= UInt<1>("h0") @[Top.scala 47:20]
    else :
      nextdata_n <= UInt<1>("h1") @[Top.scala 49:20]
    node _T_2 = eq(decoder.io.pressed, UInt<1>("h0")) @[Top.scala 53:10]
    when _T_2 : @[Top.scala 53:31]
      seg0.io.in <= UInt<4>("hf") @[Top.scala 54:20]
      seg1.io.in <= UInt<4>("hf") @[Top.scala 55:20]
      seg2.io.in <= UInt<4>("hf") @[Top.scala 56:20]
      seg3.io.in <= UInt<4>("hf") @[Top.scala 57:20]
    else :
      node _seg0_io_in_T = bits(keyboard.io.data, 3, 0) @[Top.scala 60:39]
      seg0.io.in <= _seg0_io_in_T @[Top.scala 60:20]
      node _seg1_io_in_T = bits(keyboard.io.data, 7, 4) @[Top.scala 61:39]
      seg1.io.in <= _seg1_io_in_T @[Top.scala 61:20]
      node _seg2_io_in_T = bits(decoder.io.ascii, 3, 0) @[Top.scala 64:39]
      seg2.io.in <= _seg2_io_in_T @[Top.scala 64:20]
      node _seg3_io_in_T = bits(decoder.io.ascii, 7, 4) @[Top.scala 65:39]
      seg3.io.in <= _seg3_io_in_T @[Top.scala 65:20]
    seg4.io.in <= counter.io.ones @[Top.scala 69:16]
    seg5.io.in <= counter.io.tens @[Top.scala 70:16]
    io.seg_out_0 <= seg0.io.seg @[Top.scala 73:18]
    io.seg_out_1 <= seg1.io.seg @[Top.scala 74:18]
    io.seg_out_2 <= seg2.io.seg @[Top.scala 75:18]
    io.seg_out_3 <= seg3.io.seg @[Top.scala 76:18]
    io.seg_out_4 <= seg4.io.seg @[Top.scala 77:18]
    io.seg_out_5 <= seg5.io.seg @[Top.scala 78:18]

