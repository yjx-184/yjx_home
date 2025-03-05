circuit Top :
  module PS2Keyboard :
    input clock : Clock
    input reset : Reset
    output io : { flip clrn : UInt<1>, flip ps2_clk : UInt<1>, flip ps2_data : UInt<1>, flip nextdata_n : UInt<1>, data : UInt<8>, ready : UInt<1>, overflow : UInt<1>}

    reg buffer : UInt<10>, clock with :
      reset => (reset, UInt<10>("h0")) @[Top.scala 128:28]
    wire _fifo_WIRE : UInt<8>[8] @[Top.scala 129:36]
    _fifo_WIRE[0] <= UInt<8>("h0") @[Top.scala 129:36]
    _fifo_WIRE[1] <= UInt<8>("h0") @[Top.scala 129:36]
    _fifo_WIRE[2] <= UInt<8>("h0") @[Top.scala 129:36]
    _fifo_WIRE[3] <= UInt<8>("h0") @[Top.scala 129:36]
    _fifo_WIRE[4] <= UInt<8>("h0") @[Top.scala 129:36]
    _fifo_WIRE[5] <= UInt<8>("h0") @[Top.scala 129:36]
    _fifo_WIRE[6] <= UInt<8>("h0") @[Top.scala 129:36]
    _fifo_WIRE[7] <= UInt<8>("h0") @[Top.scala 129:36]
    reg fifo : UInt<8>[8], clock with :
      reset => (reset, _fifo_WIRE) @[Top.scala 129:28]
    reg w_ptr : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Top.scala 130:28]
    reg r_ptr : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Top.scala 131:28]
    reg count : UInt<4>, clock with :
      reset => (reset, UInt<4>("h0")) @[Top.scala 132:28]
    reg overflow : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 133:28]
    reg ready : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 134:28]
    reg ps2_clk_sync : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Top.scala 135:28]
    node _ps2_clk_sync_T = bits(ps2_clk_sync, 1, 0) @[Top.scala 138:35]
    node _ps2_clk_sync_T_1 = cat(_ps2_clk_sync_T, io.ps2_clk) @[Cat.scala 31:58]
    ps2_clk_sync <= _ps2_clk_sync_T_1 @[Top.scala 138:16]
    node _sampling_T = bits(ps2_clk_sync, 2, 2) @[Top.scala 139:30]
    node _sampling_T_1 = bits(ps2_clk_sync, 1, 1) @[Top.scala 139:50]
    node _sampling_T_2 = eq(_sampling_T_1, UInt<1>("h0")) @[Top.scala 139:37]
    node sampling = and(_sampling_T, _sampling_T_2) @[Top.scala 139:34]
    node _T = eq(io.clrn, UInt<1>("h0")) @[Top.scala 142:9]
    when _T : @[Top.scala 142:19]
      buffer <= UInt<1>("h0") @[Top.scala 144:15]
      wire _WIRE : UInt<1>[8] @[Top.scala 145:25]
      _WIRE[0] <= UInt<1>("h0") @[Top.scala 145:25]
      _WIRE[1] <= UInt<1>("h0") @[Top.scala 145:25]
      _WIRE[2] <= UInt<1>("h0") @[Top.scala 145:25]
      _WIRE[3] <= UInt<1>("h0") @[Top.scala 145:25]
      _WIRE[4] <= UInt<1>("h0") @[Top.scala 145:25]
      _WIRE[5] <= UInt<1>("h0") @[Top.scala 145:25]
      _WIRE[6] <= UInt<1>("h0") @[Top.scala 145:25]
      _WIRE[7] <= UInt<1>("h0") @[Top.scala 145:25]
      fifo <= _WIRE @[Top.scala 145:15]
      w_ptr <= UInt<1>("h0") @[Top.scala 146:15]
      r_ptr <= UInt<1>("h0") @[Top.scala 147:15]
      count <= UInt<1>("h0") @[Top.scala 148:15]
      ready <= UInt<1>("h0") @[Top.scala 149:15]
      overflow <= UInt<1>("h0") @[Top.scala 150:15]
    else :
      node _T_1 = eq(io.nextdata_n, UInt<1>("h0")) @[Top.scala 154:20]
      node _T_2 = and(ready, _T_1) @[Top.scala 154:17]
      when _T_2 : @[Top.scala 154:36]
        node _r_ptr_T = add(r_ptr, UInt<1>("h1")) @[Top.scala 155:22]
        node _r_ptr_T_1 = tail(_r_ptr_T, 1) @[Top.scala 155:22]
        r_ptr <= _r_ptr_T_1 @[Top.scala 155:13]
        node _ready_T = add(r_ptr, UInt<1>("h1")) @[Top.scala 156:34]
        node _ready_T_1 = tail(_ready_T, 1) @[Top.scala 156:34]
        node _ready_T_2 = eq(w_ptr, _ready_T_1) @[Top.scala 156:24]
        node _ready_T_3 = eq(_ready_T_2, UInt<1>("h0")) @[Top.scala 156:16]
        ready <= _ready_T_3 @[Top.scala 156:13]
      when sampling : @[Top.scala 161:21]
        node _T_3 = eq(count, UInt<4>("ha")) @[Top.scala 162:19]
        when _T_3 : @[Top.scala 162:29]
          node _valid_T = bits(buffer, 0, 0) @[Top.scala 164:27]
          node _valid_T_1 = eq(_valid_T, UInt<1>("h0")) @[Top.scala 164:31]
          node _valid_T_2 = eq(io.ps2_data, UInt<1>("h1")) @[Top.scala 165:32]
          node _valid_T_3 = and(_valid_T_1, _valid_T_2) @[Top.scala 164:39]
          node _valid_T_4 = bits(buffer, 9, 1) @[Top.scala 166:27]
          node _valid_T_5 = xorr(_valid_T_4) @[Top.scala 166:38]
          node _valid_T_6 = eq(_valid_T_5, UInt<1>("h1")) @[Top.scala 166:41]
          node valid = and(_valid_T_3, _valid_T_6) @[Top.scala 165:40]
          when valid : @[Top.scala 168:22]
            node _fifo_T = bits(buffer, 8, 1) @[Top.scala 169:32]
            fifo[w_ptr] <= _fifo_T @[Top.scala 169:23]
            node _w_ptr_T = add(w_ptr, UInt<1>("h1")) @[Top.scala 170:26]
            node _w_ptr_T_1 = tail(_w_ptr_T, 1) @[Top.scala 170:26]
            w_ptr <= _w_ptr_T_1 @[Top.scala 170:17]
            ready <= UInt<1>("h1") @[Top.scala 171:17]
            node _overflow_T = eq(w_ptr, UInt<3>("h7")) @[Top.scala 172:44]
            node _overflow_T_1 = add(w_ptr, UInt<1>("h1")) @[Top.scala 172:64]
            node _overflow_T_2 = tail(_overflow_T_1, 1) @[Top.scala 172:64]
            node _overflow_T_3 = mux(_overflow_T, UInt<1>("h0"), _overflow_T_2) @[Top.scala 172:37]
            node _overflow_T_4 = eq(r_ptr, _overflow_T_3) @[Top.scala 172:30]
            overflow <= _overflow_T_4 @[Top.scala 172:20]
          count <= UInt<1>("h0") @[Top.scala 174:15]
        else :
          node _bufferVec_T = bits(buffer, 0, 0) @[Top.scala 177:40]
          node _bufferVec_T_1 = bits(buffer, 1, 1) @[Top.scala 177:40]
          node _bufferVec_T_2 = bits(buffer, 2, 2) @[Top.scala 177:40]
          node _bufferVec_T_3 = bits(buffer, 3, 3) @[Top.scala 177:40]
          node _bufferVec_T_4 = bits(buffer, 4, 4) @[Top.scala 177:40]
          node _bufferVec_T_5 = bits(buffer, 5, 5) @[Top.scala 177:40]
          node _bufferVec_T_6 = bits(buffer, 6, 6) @[Top.scala 177:40]
          node _bufferVec_T_7 = bits(buffer, 7, 7) @[Top.scala 177:40]
          node _bufferVec_T_8 = bits(buffer, 8, 8) @[Top.scala 177:40]
          node _bufferVec_T_9 = bits(buffer, 9, 9) @[Top.scala 177:40]
          wire bufferVec : UInt<1>[10] @[Top.scala 177:32]
          bufferVec[0] <= _bufferVec_T @[Top.scala 177:32]
          bufferVec[1] <= _bufferVec_T_1 @[Top.scala 177:32]
          bufferVec[2] <= _bufferVec_T_2 @[Top.scala 177:32]
          bufferVec[3] <= _bufferVec_T_3 @[Top.scala 177:32]
          bufferVec[4] <= _bufferVec_T_4 @[Top.scala 177:32]
          bufferVec[5] <= _bufferVec_T_5 @[Top.scala 177:32]
          bufferVec[6] <= _bufferVec_T_6 @[Top.scala 177:32]
          bufferVec[7] <= _bufferVec_T_7 @[Top.scala 177:32]
          bufferVec[8] <= _bufferVec_T_8 @[Top.scala 177:32]
          bufferVec[9] <= _bufferVec_T_9 @[Top.scala 177:32]
          bufferVec[count] <= io.ps2_data @[Top.scala 178:26]
          node buffer_lo_lo = cat(bufferVec[1], bufferVec[0]) @[Top.scala 179:29]
          node buffer_lo_hi_hi = cat(bufferVec[4], bufferVec[3]) @[Top.scala 179:29]
          node buffer_lo_hi = cat(buffer_lo_hi_hi, bufferVec[2]) @[Top.scala 179:29]
          node buffer_lo = cat(buffer_lo_hi, buffer_lo_lo) @[Top.scala 179:29]
          node buffer_hi_lo = cat(bufferVec[6], bufferVec[5]) @[Top.scala 179:29]
          node buffer_hi_hi_hi = cat(bufferVec[9], bufferVec[8]) @[Top.scala 179:29]
          node buffer_hi_hi = cat(buffer_hi_hi_hi, bufferVec[7]) @[Top.scala 179:29]
          node buffer_hi = cat(buffer_hi_hi, buffer_hi_lo) @[Top.scala 179:29]
          node _buffer_T = cat(buffer_hi, buffer_lo) @[Top.scala 179:29]
          buffer <= _buffer_T @[Top.scala 179:16]
          node _count_T = add(count, UInt<1>("h1")) @[Top.scala 180:24]
          node _count_T_1 = tail(_count_T, 1) @[Top.scala 180:24]
          count <= _count_T_1 @[Top.scala 180:15]
    io.data <= fifo[r_ptr] @[Top.scala 185:15]
    io.ready <= ready @[Top.scala 186:15]
    io.overflow <= overflow @[Top.scala 187:15]

  module Ps2_decoder :
    input clock : Clock
    input reset : Reset
    output io : { flip keycode : UInt<8>, flip clrn : UInt<1>, ascii : UInt<8>, released : UInt<1>}

    reg isBreakCode : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 199:30]
    io.released <= UInt<1>("h0") @[Top.scala 201:17]
    io.ascii <= UInt<1>("h0") @[Top.scala 202:14]
    node _T = eq(io.clrn, UInt<1>("h0")) @[Top.scala 204:10]
    when _T : @[Top.scala 204:20]
      isBreakCode <= UInt<1>("h0") @[Top.scala 205:21]
      io.released <= UInt<1>("h0") @[Top.scala 206:21]
    else :
      node _T_1 = eq(io.keycode, UInt<8>("hf0")) @[Top.scala 208:25]
      when _T_1 : @[Top.scala 208:37]
        isBreakCode <= UInt<1>("h1") @[Top.scala 209:25]
      else :
        when isBreakCode : @[Top.scala 211:31]
          isBreakCode <= UInt<1>("h0") @[Top.scala 212:29]
          io.released <= UInt<1>("h1") @[Top.scala 213:29]
        else :
          io.ascii <= UInt<1>("h0") @[Top.scala 215:26]
          node _T_2 = eq(UInt<7>("h45"), io.keycode) @[Top.scala 218:36]
          when _T_2 : @[Top.scala 218:36]
            io.ascii <= UInt<6>("h30") @[Top.scala 219:43]
          else :
            node _T_3 = eq(UInt<5>("h16"), io.keycode) @[Top.scala 218:36]
            when _T_3 : @[Top.scala 218:36]
              io.ascii <= UInt<6>("h31") @[Top.scala 220:43]
            else :
              node _T_4 = eq(UInt<5>("h1e"), io.keycode) @[Top.scala 218:36]
              when _T_4 : @[Top.scala 218:36]
                io.ascii <= UInt<6>("h32") @[Top.scala 221:43]
              else :
                node _T_5 = eq(UInt<6>("h26"), io.keycode) @[Top.scala 218:36]
                when _T_5 : @[Top.scala 218:36]
                  io.ascii <= UInt<6>("h33") @[Top.scala 222:43]
                else :
                  node _T_6 = eq(UInt<6>("h25"), io.keycode) @[Top.scala 218:36]
                  when _T_6 : @[Top.scala 218:36]
                    io.ascii <= UInt<6>("h34") @[Top.scala 223:43]
                  else :
                    node _T_7 = eq(UInt<6>("h2e"), io.keycode) @[Top.scala 218:36]
                    when _T_7 : @[Top.scala 218:36]
                      io.ascii <= UInt<6>("h35") @[Top.scala 224:43]
                    else :
                      node _T_8 = eq(UInt<6>("h36"), io.keycode) @[Top.scala 218:36]
                      when _T_8 : @[Top.scala 218:36]
                        io.ascii <= UInt<6>("h36") @[Top.scala 225:43]
                      else :
                        node _T_9 = eq(UInt<6>("h3d"), io.keycode) @[Top.scala 218:36]
                        when _T_9 : @[Top.scala 218:36]
                          io.ascii <= UInt<6>("h37") @[Top.scala 226:43]
                        else :
                          node _T_10 = eq(UInt<6>("h3e"), io.keycode) @[Top.scala 218:36]
                          when _T_10 : @[Top.scala 218:36]
                            io.ascii <= UInt<6>("h38") @[Top.scala 227:43]
                          else :
                            node _T_11 = eq(UInt<7>("h46"), io.keycode) @[Top.scala 218:36]
                            when _T_11 : @[Top.scala 218:36]
                              io.ascii <= UInt<6>("h39") @[Top.scala 228:43]
                            else :
                              node _T_12 = eq(UInt<5>("h1c"), io.keycode) @[Top.scala 218:36]
                              when _T_12 : @[Top.scala 218:36]
                                io.ascii <= UInt<7>("h41") @[Top.scala 230:43]
                              else :
                                node _T_13 = eq(UInt<6>("h32"), io.keycode) @[Top.scala 218:36]
                                when _T_13 : @[Top.scala 218:36]
                                  io.ascii <= UInt<7>("h42") @[Top.scala 231:43]
                                else :
                                  node _T_14 = eq(UInt<6>("h21"), io.keycode) @[Top.scala 218:36]
                                  when _T_14 : @[Top.scala 218:36]
                                    io.ascii <= UInt<7>("h43") @[Top.scala 232:43]
                                  else :
                                    node _T_15 = eq(UInt<6>("h23"), io.keycode) @[Top.scala 218:36]
                                    when _T_15 : @[Top.scala 218:36]
                                      io.ascii <= UInt<7>("h44") @[Top.scala 233:43]
                                    else :
                                      node _T_16 = eq(UInt<6>("h24"), io.keycode) @[Top.scala 218:36]
                                      when _T_16 : @[Top.scala 218:36]
                                        io.ascii <= UInt<7>("h45") @[Top.scala 234:43]
                                      else :
                                        node _T_17 = eq(UInt<6>("h2b"), io.keycode) @[Top.scala 218:36]
                                        when _T_17 : @[Top.scala 218:36]
                                          io.ascii <= UInt<7>("h46") @[Top.scala 235:43]
                                        else :
                                          node _T_18 = eq(UInt<6>("h34"), io.keycode) @[Top.scala 218:36]
                                          when _T_18 : @[Top.scala 218:36]
                                            io.ascii <= UInt<7>("h47") @[Top.scala 236:43]
                                          else :
                                            node _T_19 = eq(UInt<6>("h33"), io.keycode) @[Top.scala 218:36]
                                            when _T_19 : @[Top.scala 218:36]
                                              io.ascii <= UInt<7>("h48") @[Top.scala 237:43]
                                            else :
                                              node _T_20 = eq(UInt<7>("h43"), io.keycode) @[Top.scala 218:36]
                                              when _T_20 : @[Top.scala 218:36]
                                                io.ascii <= UInt<7>("h49") @[Top.scala 238:43]
                                              else :
                                                node _T_21 = eq(UInt<6>("h3b"), io.keycode) @[Top.scala 218:36]
                                                when _T_21 : @[Top.scala 218:36]
                                                  io.ascii <= UInt<7>("h4a") @[Top.scala 239:43]
                                                else :
                                                  node _T_22 = eq(UInt<7>("h42"), io.keycode) @[Top.scala 218:36]
                                                  when _T_22 : @[Top.scala 218:36]
                                                    io.ascii <= UInt<7>("h4b") @[Top.scala 240:43]
                                                  else :
                                                    node _T_23 = eq(UInt<7>("h4b"), io.keycode) @[Top.scala 218:36]
                                                    when _T_23 : @[Top.scala 218:36]
                                                      io.ascii <= UInt<7>("h4c") @[Top.scala 241:43]
                                                    else :
                                                      node _T_24 = eq(UInt<6>("h3a"), io.keycode) @[Top.scala 218:36]
                                                      when _T_24 : @[Top.scala 218:36]
                                                        io.ascii <= UInt<7>("h4d") @[Top.scala 242:43]
                                                      else :
                                                        node _T_25 = eq(UInt<6>("h31"), io.keycode) @[Top.scala 218:36]
                                                        when _T_25 : @[Top.scala 218:36]
                                                          io.ascii <= UInt<7>("h4e") @[Top.scala 243:43]
                                                        else :
                                                          node _T_26 = eq(UInt<7>("h44"), io.keycode) @[Top.scala 218:36]
                                                          when _T_26 : @[Top.scala 218:36]
                                                            io.ascii <= UInt<7>("h4f") @[Top.scala 244:43]
                                                          else :
                                                            node _T_27 = eq(UInt<7>("h4d"), io.keycode) @[Top.scala 218:36]
                                                            when _T_27 : @[Top.scala 218:36]
                                                              io.ascii <= UInt<7>("h50") @[Top.scala 245:43]
                                                            else :
                                                              node _T_28 = eq(UInt<5>("h15"), io.keycode) @[Top.scala 218:36]
                                                              when _T_28 : @[Top.scala 218:36]
                                                                io.ascii <= UInt<7>("h51") @[Top.scala 246:43]
                                                              else :
                                                                node _T_29 = eq(UInt<6>("h2d"), io.keycode) @[Top.scala 218:36]
                                                                when _T_29 : @[Top.scala 218:36]
                                                                  io.ascii <= UInt<7>("h52") @[Top.scala 247:43]
                                                                else :
                                                                  node _T_30 = eq(UInt<5>("h1b"), io.keycode) @[Top.scala 218:36]
                                                                  when _T_30 : @[Top.scala 218:36]
                                                                    io.ascii <= UInt<7>("h53") @[Top.scala 248:43]
                                                                  else :
                                                                    node _T_31 = eq(UInt<6>("h2c"), io.keycode) @[Top.scala 218:36]
                                                                    when _T_31 : @[Top.scala 218:36]
                                                                      io.ascii <= UInt<7>("h54") @[Top.scala 249:43]
                                                                    else :
                                                                      node _T_32 = eq(UInt<6>("h3c"), io.keycode) @[Top.scala 218:36]
                                                                      when _T_32 : @[Top.scala 218:36]
                                                                        io.ascii <= UInt<7>("h55") @[Top.scala 250:43]
                                                                      else :
                                                                        node _T_33 = eq(UInt<6>("h2a"), io.keycode) @[Top.scala 218:36]
                                                                        when _T_33 : @[Top.scala 218:36]
                                                                          io.ascii <= UInt<7>("h56") @[Top.scala 251:43]
                                                                        else :
                                                                          node _T_34 = eq(UInt<5>("h1d"), io.keycode) @[Top.scala 218:36]
                                                                          when _T_34 : @[Top.scala 218:36]
                                                                            io.ascii <= UInt<7>("h57") @[Top.scala 252:43]
                                                                          else :
                                                                            node _T_35 = eq(UInt<5>("h1a"), io.keycode) @[Top.scala 218:36]
                                                                            when _T_35 : @[Top.scala 218:36]
                                                                              io.ascii <= UInt<7>("h58") @[Top.scala 253:43]
                                                                            else :
                                                                              node _T_36 = eq(UInt<6>("h22"), io.keycode) @[Top.scala 218:36]
                                                                              when _T_36 : @[Top.scala 218:36]
                                                                                io.ascii <= UInt<7>("h59") @[Top.scala 254:43]
                                                                              else :
                                                                                node _T_37 = eq(UInt<5>("h14"), io.keycode) @[Top.scala 218:36]
                                                                                when _T_37 : @[Top.scala 218:36]
                                                                                  io.ascii <= UInt<7>("h5a") @[Top.scala 255:43]

  module Seg :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, flip en : UInt<1>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 288:10]
    node _T = eq(io.en, UInt<1>("h0")) @[Top.scala 291:8]
    when _T : @[Top.scala 291:16]
      io.seg <= UInt<8>("hff") @[Top.scala 292:12]
    else :
      node _T_1 = eq(UInt<1>("h0"), io.in) @[Top.scala 294:19]
      when _T_1 : @[Top.scala 294:19]
        node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 295:27]
        io.seg <= _io_seg_T @[Top.scala 295:24]
      else :
        node _T_2 = eq(UInt<1>("h1"), io.in) @[Top.scala 294:19]
        when _T_2 : @[Top.scala 294:19]
          node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 296:27]
          io.seg <= _io_seg_T_1 @[Top.scala 296:24]
        else :
          node _T_3 = eq(UInt<2>("h2"), io.in) @[Top.scala 294:19]
          when _T_3 : @[Top.scala 294:19]
            node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 297:27]
            io.seg <= _io_seg_T_2 @[Top.scala 297:24]
          else :
            node _T_4 = eq(UInt<2>("h3"), io.in) @[Top.scala 294:19]
            when _T_4 : @[Top.scala 294:19]
              node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 298:27]
              io.seg <= _io_seg_T_3 @[Top.scala 298:24]
            else :
              node _T_5 = eq(UInt<3>("h4"), io.in) @[Top.scala 294:19]
              when _T_5 : @[Top.scala 294:19]
                node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 299:27]
                io.seg <= _io_seg_T_4 @[Top.scala 299:24]
              else :
                node _T_6 = eq(UInt<3>("h5"), io.in) @[Top.scala 294:19]
                when _T_6 : @[Top.scala 294:19]
                  node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 300:27]
                  io.seg <= _io_seg_T_5 @[Top.scala 300:24]
                else :
                  node _T_7 = eq(UInt<3>("h6"), io.in) @[Top.scala 294:19]
                  when _T_7 : @[Top.scala 294:19]
                    node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 301:27]
                    io.seg <= _io_seg_T_6 @[Top.scala 301:24]
                  else :
                    node _T_8 = eq(UInt<3>("h7"), io.in) @[Top.scala 294:19]
                    when _T_8 : @[Top.scala 294:19]
                      node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 302:27]
                      io.seg <= _io_seg_T_7 @[Top.scala 302:24]
                    else :
                      node _T_9 = eq(UInt<4>("h8"), io.in) @[Top.scala 294:19]
                      when _T_9 : @[Top.scala 294:19]
                        node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 303:27]
                        io.seg <= _io_seg_T_8 @[Top.scala 303:24]
                      else :
                        node _T_10 = eq(UInt<4>("h9"), io.in) @[Top.scala 294:19]
                        when _T_10 : @[Top.scala 294:19]
                          node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 304:27]
                          io.seg <= _io_seg_T_9 @[Top.scala 304:24]
                        else :
                          node _T_11 = eq(UInt<4>("ha"), io.in) @[Top.scala 294:19]
                          when _T_11 : @[Top.scala 294:19]
                            node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 305:28]
                            io.seg <= _io_seg_T_10 @[Top.scala 305:25]
                          else :
                            node _T_12 = eq(UInt<4>("hb"), io.in) @[Top.scala 294:19]
                            when _T_12 : @[Top.scala 294:19]
                              node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 306:28]
                              io.seg <= _io_seg_T_11 @[Top.scala 306:25]
                            else :
                              node _T_13 = eq(UInt<4>("hc"), io.in) @[Top.scala 294:19]
                              when _T_13 : @[Top.scala 294:19]
                                node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 307:28]
                                io.seg <= _io_seg_T_12 @[Top.scala 307:25]
                              else :
                                node _T_14 = eq(UInt<4>("hd"), io.in) @[Top.scala 294:19]
                                when _T_14 : @[Top.scala 294:19]
                                  node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 308:28]
                                  io.seg <= _io_seg_T_13 @[Top.scala 308:25]
                                else :
                                  node _T_15 = eq(UInt<4>("he"), io.in) @[Top.scala 294:19]
                                  when _T_15 : @[Top.scala 294:19]
                                    node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 309:28]
                                    io.seg <= _io_seg_T_14 @[Top.scala 309:25]
                                  else :
                                    node _T_16 = eq(UInt<4>("hf"), io.in) @[Top.scala 294:19]
                                    when _T_16 : @[Top.scala 294:19]
                                      node _io_seg_T_15 = not(UInt<8>("h8e")) @[Top.scala 310:28]
                                      io.seg <= _io_seg_T_15 @[Top.scala 310:25]

  module Seg_1 :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, flip en : UInt<1>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 288:10]
    node _T = eq(io.en, UInt<1>("h0")) @[Top.scala 291:8]
    when _T : @[Top.scala 291:16]
      io.seg <= UInt<8>("hff") @[Top.scala 292:12]
    else :
      node _T_1 = eq(UInt<1>("h0"), io.in) @[Top.scala 294:19]
      when _T_1 : @[Top.scala 294:19]
        node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 295:27]
        io.seg <= _io_seg_T @[Top.scala 295:24]
      else :
        node _T_2 = eq(UInt<1>("h1"), io.in) @[Top.scala 294:19]
        when _T_2 : @[Top.scala 294:19]
          node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 296:27]
          io.seg <= _io_seg_T_1 @[Top.scala 296:24]
        else :
          node _T_3 = eq(UInt<2>("h2"), io.in) @[Top.scala 294:19]
          when _T_3 : @[Top.scala 294:19]
            node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 297:27]
            io.seg <= _io_seg_T_2 @[Top.scala 297:24]
          else :
            node _T_4 = eq(UInt<2>("h3"), io.in) @[Top.scala 294:19]
            when _T_4 : @[Top.scala 294:19]
              node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 298:27]
              io.seg <= _io_seg_T_3 @[Top.scala 298:24]
            else :
              node _T_5 = eq(UInt<3>("h4"), io.in) @[Top.scala 294:19]
              when _T_5 : @[Top.scala 294:19]
                node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 299:27]
                io.seg <= _io_seg_T_4 @[Top.scala 299:24]
              else :
                node _T_6 = eq(UInt<3>("h5"), io.in) @[Top.scala 294:19]
                when _T_6 : @[Top.scala 294:19]
                  node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 300:27]
                  io.seg <= _io_seg_T_5 @[Top.scala 300:24]
                else :
                  node _T_7 = eq(UInt<3>("h6"), io.in) @[Top.scala 294:19]
                  when _T_7 : @[Top.scala 294:19]
                    node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 301:27]
                    io.seg <= _io_seg_T_6 @[Top.scala 301:24]
                  else :
                    node _T_8 = eq(UInt<3>("h7"), io.in) @[Top.scala 294:19]
                    when _T_8 : @[Top.scala 294:19]
                      node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 302:27]
                      io.seg <= _io_seg_T_7 @[Top.scala 302:24]
                    else :
                      node _T_9 = eq(UInt<4>("h8"), io.in) @[Top.scala 294:19]
                      when _T_9 : @[Top.scala 294:19]
                        node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 303:27]
                        io.seg <= _io_seg_T_8 @[Top.scala 303:24]
                      else :
                        node _T_10 = eq(UInt<4>("h9"), io.in) @[Top.scala 294:19]
                        when _T_10 : @[Top.scala 294:19]
                          node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 304:27]
                          io.seg <= _io_seg_T_9 @[Top.scala 304:24]
                        else :
                          node _T_11 = eq(UInt<4>("ha"), io.in) @[Top.scala 294:19]
                          when _T_11 : @[Top.scala 294:19]
                            node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 305:28]
                            io.seg <= _io_seg_T_10 @[Top.scala 305:25]
                          else :
                            node _T_12 = eq(UInt<4>("hb"), io.in) @[Top.scala 294:19]
                            when _T_12 : @[Top.scala 294:19]
                              node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 306:28]
                              io.seg <= _io_seg_T_11 @[Top.scala 306:25]
                            else :
                              node _T_13 = eq(UInt<4>("hc"), io.in) @[Top.scala 294:19]
                              when _T_13 : @[Top.scala 294:19]
                                node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 307:28]
                                io.seg <= _io_seg_T_12 @[Top.scala 307:25]
                              else :
                                node _T_14 = eq(UInt<4>("hd"), io.in) @[Top.scala 294:19]
                                when _T_14 : @[Top.scala 294:19]
                                  node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 308:28]
                                  io.seg <= _io_seg_T_13 @[Top.scala 308:25]
                                else :
                                  node _T_15 = eq(UInt<4>("he"), io.in) @[Top.scala 294:19]
                                  when _T_15 : @[Top.scala 294:19]
                                    node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 309:28]
                                    io.seg <= _io_seg_T_14 @[Top.scala 309:25]
                                  else :
                                    node _T_16 = eq(UInt<4>("hf"), io.in) @[Top.scala 294:19]
                                    when _T_16 : @[Top.scala 294:19]
                                      node _io_seg_T_15 = not(UInt<8>("h8e")) @[Top.scala 310:28]
                                      io.seg <= _io_seg_T_15 @[Top.scala 310:25]

  module Seg_2 :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, flip en : UInt<1>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 288:10]
    node _T = eq(io.en, UInt<1>("h0")) @[Top.scala 291:8]
    when _T : @[Top.scala 291:16]
      io.seg <= UInt<8>("hff") @[Top.scala 292:12]
    else :
      node _T_1 = eq(UInt<1>("h0"), io.in) @[Top.scala 294:19]
      when _T_1 : @[Top.scala 294:19]
        node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 295:27]
        io.seg <= _io_seg_T @[Top.scala 295:24]
      else :
        node _T_2 = eq(UInt<1>("h1"), io.in) @[Top.scala 294:19]
        when _T_2 : @[Top.scala 294:19]
          node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 296:27]
          io.seg <= _io_seg_T_1 @[Top.scala 296:24]
        else :
          node _T_3 = eq(UInt<2>("h2"), io.in) @[Top.scala 294:19]
          when _T_3 : @[Top.scala 294:19]
            node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 297:27]
            io.seg <= _io_seg_T_2 @[Top.scala 297:24]
          else :
            node _T_4 = eq(UInt<2>("h3"), io.in) @[Top.scala 294:19]
            when _T_4 : @[Top.scala 294:19]
              node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 298:27]
              io.seg <= _io_seg_T_3 @[Top.scala 298:24]
            else :
              node _T_5 = eq(UInt<3>("h4"), io.in) @[Top.scala 294:19]
              when _T_5 : @[Top.scala 294:19]
                node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 299:27]
                io.seg <= _io_seg_T_4 @[Top.scala 299:24]
              else :
                node _T_6 = eq(UInt<3>("h5"), io.in) @[Top.scala 294:19]
                when _T_6 : @[Top.scala 294:19]
                  node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 300:27]
                  io.seg <= _io_seg_T_5 @[Top.scala 300:24]
                else :
                  node _T_7 = eq(UInt<3>("h6"), io.in) @[Top.scala 294:19]
                  when _T_7 : @[Top.scala 294:19]
                    node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 301:27]
                    io.seg <= _io_seg_T_6 @[Top.scala 301:24]
                  else :
                    node _T_8 = eq(UInt<3>("h7"), io.in) @[Top.scala 294:19]
                    when _T_8 : @[Top.scala 294:19]
                      node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 302:27]
                      io.seg <= _io_seg_T_7 @[Top.scala 302:24]
                    else :
                      node _T_9 = eq(UInt<4>("h8"), io.in) @[Top.scala 294:19]
                      when _T_9 : @[Top.scala 294:19]
                        node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 303:27]
                        io.seg <= _io_seg_T_8 @[Top.scala 303:24]
                      else :
                        node _T_10 = eq(UInt<4>("h9"), io.in) @[Top.scala 294:19]
                        when _T_10 : @[Top.scala 294:19]
                          node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 304:27]
                          io.seg <= _io_seg_T_9 @[Top.scala 304:24]
                        else :
                          node _T_11 = eq(UInt<4>("ha"), io.in) @[Top.scala 294:19]
                          when _T_11 : @[Top.scala 294:19]
                            node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 305:28]
                            io.seg <= _io_seg_T_10 @[Top.scala 305:25]
                          else :
                            node _T_12 = eq(UInt<4>("hb"), io.in) @[Top.scala 294:19]
                            when _T_12 : @[Top.scala 294:19]
                              node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 306:28]
                              io.seg <= _io_seg_T_11 @[Top.scala 306:25]
                            else :
                              node _T_13 = eq(UInt<4>("hc"), io.in) @[Top.scala 294:19]
                              when _T_13 : @[Top.scala 294:19]
                                node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 307:28]
                                io.seg <= _io_seg_T_12 @[Top.scala 307:25]
                              else :
                                node _T_14 = eq(UInt<4>("hd"), io.in) @[Top.scala 294:19]
                                when _T_14 : @[Top.scala 294:19]
                                  node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 308:28]
                                  io.seg <= _io_seg_T_13 @[Top.scala 308:25]
                                else :
                                  node _T_15 = eq(UInt<4>("he"), io.in) @[Top.scala 294:19]
                                  when _T_15 : @[Top.scala 294:19]
                                    node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 309:28]
                                    io.seg <= _io_seg_T_14 @[Top.scala 309:25]
                                  else :
                                    node _T_16 = eq(UInt<4>("hf"), io.in) @[Top.scala 294:19]
                                    when _T_16 : @[Top.scala 294:19]
                                      node _io_seg_T_15 = not(UInt<8>("h8e")) @[Top.scala 310:28]
                                      io.seg <= _io_seg_T_15 @[Top.scala 310:25]

  module Seg_3 :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, flip en : UInt<1>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 288:10]
    node _T = eq(io.en, UInt<1>("h0")) @[Top.scala 291:8]
    when _T : @[Top.scala 291:16]
      io.seg <= UInt<8>("hff") @[Top.scala 292:12]
    else :
      node _T_1 = eq(UInt<1>("h0"), io.in) @[Top.scala 294:19]
      when _T_1 : @[Top.scala 294:19]
        node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 295:27]
        io.seg <= _io_seg_T @[Top.scala 295:24]
      else :
        node _T_2 = eq(UInt<1>("h1"), io.in) @[Top.scala 294:19]
        when _T_2 : @[Top.scala 294:19]
          node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 296:27]
          io.seg <= _io_seg_T_1 @[Top.scala 296:24]
        else :
          node _T_3 = eq(UInt<2>("h2"), io.in) @[Top.scala 294:19]
          when _T_3 : @[Top.scala 294:19]
            node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 297:27]
            io.seg <= _io_seg_T_2 @[Top.scala 297:24]
          else :
            node _T_4 = eq(UInt<2>("h3"), io.in) @[Top.scala 294:19]
            when _T_4 : @[Top.scala 294:19]
              node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 298:27]
              io.seg <= _io_seg_T_3 @[Top.scala 298:24]
            else :
              node _T_5 = eq(UInt<3>("h4"), io.in) @[Top.scala 294:19]
              when _T_5 : @[Top.scala 294:19]
                node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 299:27]
                io.seg <= _io_seg_T_4 @[Top.scala 299:24]
              else :
                node _T_6 = eq(UInt<3>("h5"), io.in) @[Top.scala 294:19]
                when _T_6 : @[Top.scala 294:19]
                  node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 300:27]
                  io.seg <= _io_seg_T_5 @[Top.scala 300:24]
                else :
                  node _T_7 = eq(UInt<3>("h6"), io.in) @[Top.scala 294:19]
                  when _T_7 : @[Top.scala 294:19]
                    node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 301:27]
                    io.seg <= _io_seg_T_6 @[Top.scala 301:24]
                  else :
                    node _T_8 = eq(UInt<3>("h7"), io.in) @[Top.scala 294:19]
                    when _T_8 : @[Top.scala 294:19]
                      node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 302:27]
                      io.seg <= _io_seg_T_7 @[Top.scala 302:24]
                    else :
                      node _T_9 = eq(UInt<4>("h8"), io.in) @[Top.scala 294:19]
                      when _T_9 : @[Top.scala 294:19]
                        node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 303:27]
                        io.seg <= _io_seg_T_8 @[Top.scala 303:24]
                      else :
                        node _T_10 = eq(UInt<4>("h9"), io.in) @[Top.scala 294:19]
                        when _T_10 : @[Top.scala 294:19]
                          node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 304:27]
                          io.seg <= _io_seg_T_9 @[Top.scala 304:24]
                        else :
                          node _T_11 = eq(UInt<4>("ha"), io.in) @[Top.scala 294:19]
                          when _T_11 : @[Top.scala 294:19]
                            node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 305:28]
                            io.seg <= _io_seg_T_10 @[Top.scala 305:25]
                          else :
                            node _T_12 = eq(UInt<4>("hb"), io.in) @[Top.scala 294:19]
                            when _T_12 : @[Top.scala 294:19]
                              node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 306:28]
                              io.seg <= _io_seg_T_11 @[Top.scala 306:25]
                            else :
                              node _T_13 = eq(UInt<4>("hc"), io.in) @[Top.scala 294:19]
                              when _T_13 : @[Top.scala 294:19]
                                node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 307:28]
                                io.seg <= _io_seg_T_12 @[Top.scala 307:25]
                              else :
                                node _T_14 = eq(UInt<4>("hd"), io.in) @[Top.scala 294:19]
                                when _T_14 : @[Top.scala 294:19]
                                  node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 308:28]
                                  io.seg <= _io_seg_T_13 @[Top.scala 308:25]
                                else :
                                  node _T_15 = eq(UInt<4>("he"), io.in) @[Top.scala 294:19]
                                  when _T_15 : @[Top.scala 294:19]
                                    node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 309:28]
                                    io.seg <= _io_seg_T_14 @[Top.scala 309:25]
                                  else :
                                    node _T_16 = eq(UInt<4>("hf"), io.in) @[Top.scala 294:19]
                                    when _T_16 : @[Top.scala 294:19]
                                      node _io_seg_T_15 = not(UInt<8>("h8e")) @[Top.scala 310:28]
                                      io.seg <= _io_seg_T_15 @[Top.scala 310:25]

  module Seg_4 :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, flip en : UInt<1>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 288:10]
    node _T = eq(io.en, UInt<1>("h0")) @[Top.scala 291:8]
    when _T : @[Top.scala 291:16]
      io.seg <= UInt<8>("hff") @[Top.scala 292:12]
    else :
      node _T_1 = eq(UInt<1>("h0"), io.in) @[Top.scala 294:19]
      when _T_1 : @[Top.scala 294:19]
        node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 295:27]
        io.seg <= _io_seg_T @[Top.scala 295:24]
      else :
        node _T_2 = eq(UInt<1>("h1"), io.in) @[Top.scala 294:19]
        when _T_2 : @[Top.scala 294:19]
          node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 296:27]
          io.seg <= _io_seg_T_1 @[Top.scala 296:24]
        else :
          node _T_3 = eq(UInt<2>("h2"), io.in) @[Top.scala 294:19]
          when _T_3 : @[Top.scala 294:19]
            node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 297:27]
            io.seg <= _io_seg_T_2 @[Top.scala 297:24]
          else :
            node _T_4 = eq(UInt<2>("h3"), io.in) @[Top.scala 294:19]
            when _T_4 : @[Top.scala 294:19]
              node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 298:27]
              io.seg <= _io_seg_T_3 @[Top.scala 298:24]
            else :
              node _T_5 = eq(UInt<3>("h4"), io.in) @[Top.scala 294:19]
              when _T_5 : @[Top.scala 294:19]
                node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 299:27]
                io.seg <= _io_seg_T_4 @[Top.scala 299:24]
              else :
                node _T_6 = eq(UInt<3>("h5"), io.in) @[Top.scala 294:19]
                when _T_6 : @[Top.scala 294:19]
                  node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 300:27]
                  io.seg <= _io_seg_T_5 @[Top.scala 300:24]
                else :
                  node _T_7 = eq(UInt<3>("h6"), io.in) @[Top.scala 294:19]
                  when _T_7 : @[Top.scala 294:19]
                    node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 301:27]
                    io.seg <= _io_seg_T_6 @[Top.scala 301:24]
                  else :
                    node _T_8 = eq(UInt<3>("h7"), io.in) @[Top.scala 294:19]
                    when _T_8 : @[Top.scala 294:19]
                      node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 302:27]
                      io.seg <= _io_seg_T_7 @[Top.scala 302:24]
                    else :
                      node _T_9 = eq(UInt<4>("h8"), io.in) @[Top.scala 294:19]
                      when _T_9 : @[Top.scala 294:19]
                        node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 303:27]
                        io.seg <= _io_seg_T_8 @[Top.scala 303:24]
                      else :
                        node _T_10 = eq(UInt<4>("h9"), io.in) @[Top.scala 294:19]
                        when _T_10 : @[Top.scala 294:19]
                          node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 304:27]
                          io.seg <= _io_seg_T_9 @[Top.scala 304:24]
                        else :
                          node _T_11 = eq(UInt<4>("ha"), io.in) @[Top.scala 294:19]
                          when _T_11 : @[Top.scala 294:19]
                            node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 305:28]
                            io.seg <= _io_seg_T_10 @[Top.scala 305:25]
                          else :
                            node _T_12 = eq(UInt<4>("hb"), io.in) @[Top.scala 294:19]
                            when _T_12 : @[Top.scala 294:19]
                              node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 306:28]
                              io.seg <= _io_seg_T_11 @[Top.scala 306:25]
                            else :
                              node _T_13 = eq(UInt<4>("hc"), io.in) @[Top.scala 294:19]
                              when _T_13 : @[Top.scala 294:19]
                                node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 307:28]
                                io.seg <= _io_seg_T_12 @[Top.scala 307:25]
                              else :
                                node _T_14 = eq(UInt<4>("hd"), io.in) @[Top.scala 294:19]
                                when _T_14 : @[Top.scala 294:19]
                                  node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 308:28]
                                  io.seg <= _io_seg_T_13 @[Top.scala 308:25]
                                else :
                                  node _T_15 = eq(UInt<4>("he"), io.in) @[Top.scala 294:19]
                                  when _T_15 : @[Top.scala 294:19]
                                    node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 309:28]
                                    io.seg <= _io_seg_T_14 @[Top.scala 309:25]
                                  else :
                                    node _T_16 = eq(UInt<4>("hf"), io.in) @[Top.scala 294:19]
                                    when _T_16 : @[Top.scala 294:19]
                                      node _io_seg_T_15 = not(UInt<8>("h8e")) @[Top.scala 310:28]
                                      io.seg <= _io_seg_T_15 @[Top.scala 310:25]

  module Seg_5 :
    input clock : Clock
    input reset : Reset
    output io : { flip in : UInt<4>, flip en : UInt<1>, seg : UInt<8>}

    io.seg <= UInt<8>("hff") @[Top.scala 288:10]
    node _T = eq(io.en, UInt<1>("h0")) @[Top.scala 291:8]
    when _T : @[Top.scala 291:16]
      io.seg <= UInt<8>("hff") @[Top.scala 292:12]
    else :
      node _T_1 = eq(UInt<1>("h0"), io.in) @[Top.scala 294:19]
      when _T_1 : @[Top.scala 294:19]
        node _io_seg_T = not(UInt<8>("hfc")) @[Top.scala 295:27]
        io.seg <= _io_seg_T @[Top.scala 295:24]
      else :
        node _T_2 = eq(UInt<1>("h1"), io.in) @[Top.scala 294:19]
        when _T_2 : @[Top.scala 294:19]
          node _io_seg_T_1 = not(UInt<8>("h60")) @[Top.scala 296:27]
          io.seg <= _io_seg_T_1 @[Top.scala 296:24]
        else :
          node _T_3 = eq(UInt<2>("h2"), io.in) @[Top.scala 294:19]
          when _T_3 : @[Top.scala 294:19]
            node _io_seg_T_2 = not(UInt<8>("hda")) @[Top.scala 297:27]
            io.seg <= _io_seg_T_2 @[Top.scala 297:24]
          else :
            node _T_4 = eq(UInt<2>("h3"), io.in) @[Top.scala 294:19]
            when _T_4 : @[Top.scala 294:19]
              node _io_seg_T_3 = not(UInt<8>("hf2")) @[Top.scala 298:27]
              io.seg <= _io_seg_T_3 @[Top.scala 298:24]
            else :
              node _T_5 = eq(UInt<3>("h4"), io.in) @[Top.scala 294:19]
              when _T_5 : @[Top.scala 294:19]
                node _io_seg_T_4 = not(UInt<8>("h66")) @[Top.scala 299:27]
                io.seg <= _io_seg_T_4 @[Top.scala 299:24]
              else :
                node _T_6 = eq(UInt<3>("h5"), io.in) @[Top.scala 294:19]
                when _T_6 : @[Top.scala 294:19]
                  node _io_seg_T_5 = not(UInt<8>("hb6")) @[Top.scala 300:27]
                  io.seg <= _io_seg_T_5 @[Top.scala 300:24]
                else :
                  node _T_7 = eq(UInt<3>("h6"), io.in) @[Top.scala 294:19]
                  when _T_7 : @[Top.scala 294:19]
                    node _io_seg_T_6 = not(UInt<8>("hbe")) @[Top.scala 301:27]
                    io.seg <= _io_seg_T_6 @[Top.scala 301:24]
                  else :
                    node _T_8 = eq(UInt<3>("h7"), io.in) @[Top.scala 294:19]
                    when _T_8 : @[Top.scala 294:19]
                      node _io_seg_T_7 = not(UInt<8>("he0")) @[Top.scala 302:27]
                      io.seg <= _io_seg_T_7 @[Top.scala 302:24]
                    else :
                      node _T_9 = eq(UInt<4>("h8"), io.in) @[Top.scala 294:19]
                      when _T_9 : @[Top.scala 294:19]
                        node _io_seg_T_8 = not(UInt<8>("hfe")) @[Top.scala 303:27]
                        io.seg <= _io_seg_T_8 @[Top.scala 303:24]
                      else :
                        node _T_10 = eq(UInt<4>("h9"), io.in) @[Top.scala 294:19]
                        when _T_10 : @[Top.scala 294:19]
                          node _io_seg_T_9 = not(UInt<8>("hf6")) @[Top.scala 304:27]
                          io.seg <= _io_seg_T_9 @[Top.scala 304:24]
                        else :
                          node _T_11 = eq(UInt<4>("ha"), io.in) @[Top.scala 294:19]
                          when _T_11 : @[Top.scala 294:19]
                            node _io_seg_T_10 = not(UInt<8>("hee")) @[Top.scala 305:28]
                            io.seg <= _io_seg_T_10 @[Top.scala 305:25]
                          else :
                            node _T_12 = eq(UInt<4>("hb"), io.in) @[Top.scala 294:19]
                            when _T_12 : @[Top.scala 294:19]
                              node _io_seg_T_11 = not(UInt<8>("h3e")) @[Top.scala 306:28]
                              io.seg <= _io_seg_T_11 @[Top.scala 306:25]
                            else :
                              node _T_13 = eq(UInt<4>("hc"), io.in) @[Top.scala 294:19]
                              when _T_13 : @[Top.scala 294:19]
                                node _io_seg_T_12 = not(UInt<8>("h9c")) @[Top.scala 307:28]
                                io.seg <= _io_seg_T_12 @[Top.scala 307:25]
                              else :
                                node _T_14 = eq(UInt<4>("hd"), io.in) @[Top.scala 294:19]
                                when _T_14 : @[Top.scala 294:19]
                                  node _io_seg_T_13 = not(UInt<8>("h7a")) @[Top.scala 308:28]
                                  io.seg <= _io_seg_T_13 @[Top.scala 308:25]
                                else :
                                  node _T_15 = eq(UInt<4>("he"), io.in) @[Top.scala 294:19]
                                  when _T_15 : @[Top.scala 294:19]
                                    node _io_seg_T_14 = not(UInt<8>("h9e")) @[Top.scala 309:28]
                                    io.seg <= _io_seg_T_14 @[Top.scala 309:25]
                                  else :
                                    node _T_16 = eq(UInt<4>("hf"), io.in) @[Top.scala 294:19]
                                    when _T_16 : @[Top.scala 294:19]
                                      node _io_seg_T_15 = not(UInt<8>("h8e")) @[Top.scala 310:28]
                                      io.seg <= _io_seg_T_15 @[Top.scala 310:25]

  module Keycount :
    input clock : Clock
    input reset : Reset
    output io : { flip key_press : UInt<1>, flip key_release : UInt<1>, flip clrn : UInt<1>, ones : UInt<4>, tens : UInt<4>}

    reg ones : UInt<4>, clock with :
      reset => (reset, UInt<4>("h0")) @[Top.scala 326:23]
    reg tens : UInt<4>, clock with :
      reset => (reset, UInt<4>("h0")) @[Top.scala 327:23]
    reg counted : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 328:26]
    node _T = eq(io.clrn, UInt<1>("h0")) @[Top.scala 330:10]
    when _T : @[Top.scala 330:20]
      ones <= UInt<1>("h0") @[Top.scala 331:12]
      tens <= UInt<1>("h0") @[Top.scala 332:12]
      counted <= UInt<1>("h0") @[Top.scala 333:15]
    else :
      node _T_1 = eq(counted, UInt<1>("h0")) @[Top.scala 336:28]
      node _T_2 = and(io.key_press, _T_1) @[Top.scala 336:25]
      when _T_2 : @[Top.scala 336:38]
        counted <= UInt<1>("h1") @[Top.scala 337:17]
        node _T_3 = eq(ones, UInt<4>("h9")) @[Top.scala 339:19]
        when _T_3 : @[Top.scala 339:28]
          ones <= UInt<1>("h0") @[Top.scala 340:16]
          node _tens_T = eq(tens, UInt<4>("h9")) @[Top.scala 341:28]
          node _tens_T_1 = add(tens, UInt<1>("h1")) @[Top.scala 341:47]
          node _tens_T_2 = tail(_tens_T_1, 1) @[Top.scala 341:47]
          node _tens_T_3 = mux(_tens_T, UInt<1>("h0"), _tens_T_2) @[Top.scala 341:22]
          tens <= _tens_T_3 @[Top.scala 341:16]
        else :
          node _ones_T = add(ones, UInt<1>("h1")) @[Top.scala 343:24]
          node _ones_T_1 = tail(_ones_T, 1) @[Top.scala 343:24]
          ones <= _ones_T_1 @[Top.scala 343:16]
      when io.key_release : @[Top.scala 347:28]
        counted <= UInt<1>("h0") @[Top.scala 348:17]
    io.ones <= ones @[Top.scala 351:13]
    io.tens <= tens @[Top.scala 352:13]

  module Top :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip clrn : UInt<1>, flip ps2_clk : UInt<1>, flip ps2_data : UInt<1>, seg_out_0 : UInt<8>, seg_out_1 : UInt<8>, seg_out_2 : UInt<8>, seg_out_3 : UInt<8>, seg_out_4 : UInt<8>, seg_out_5 : UInt<8>}

    inst keyboard of PS2Keyboard @[Top.scala 19:26]
    keyboard.clock <= clock
    keyboard.reset <= reset
    keyboard.io.clrn <= io.clrn @[Top.scala 20:26]
    keyboard.io.ps2_clk <= io.ps2_clk @[Top.scala 21:26]
    keyboard.io.ps2_data <= io.ps2_data @[Top.scala 22:26]
    reg readySync : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 25:28]
    readySync <= keyboard.io.ready @[Top.scala 25:28]
    node _ready_p1_T = eq(readySync, UInt<1>("h0")) @[Top.scala 26:41]
    node ready_p1 = and(keyboard.io.ready, _ready_p1_T) @[Top.scala 26:38]
    reg nextdata_n : UInt<1>, clock with :
      reset => (reset, UInt<1>("h1")) @[Top.scala 29:29]
    keyboard.io.nextdata_n <= nextdata_n @[Top.scala 30:28]
    when ready_p1 : @[Top.scala 33:20]
      nextdata_n <= UInt<1>("h0") @[Top.scala 34:20]
    else :
      nextdata_n <= UInt<1>("h1") @[Top.scala 36:20]
    reg data_d1 : UInt<8>, clock with :
      reset => (reset, UInt<8>("h0")) @[Top.scala 40:26]
    when ready_p1 : @[Top.scala 41:20]
      data_d1 <= keyboard.io.data @[Top.scala 42:15]
    inst decoder of Ps2_decoder @[Top.scala 46:25]
    decoder.clock <= clock
    decoder.reset <= reset
    decoder.io.keycode <= data_d1 @[Top.scala 47:26]
    decoder.io.clrn <= io.clrn @[Top.scala 48:26]
    inst seg0 of Seg @[Top.scala 51:22]
    seg0.clock <= clock
    seg0.reset <= reset
    inst seg1 of Seg_1 @[Top.scala 52:22]
    seg1.clock <= clock
    seg1.reset <= reset
    inst seg2 of Seg_2 @[Top.scala 53:22]
    seg2.clock <= clock
    seg2.reset <= reset
    inst seg3 of Seg_3 @[Top.scala 54:22]
    seg3.clock <= clock
    seg3.reset <= reset
    inst seg4 of Seg_4 @[Top.scala 55:22]
    seg4.clock <= clock
    seg4.reset <= reset
    inst seg5 of Seg_5 @[Top.scala 56:22]
    seg5.clock <= clock
    seg5.reset <= reset
    inst counter of Keycount @[Top.scala 59:25]
    counter.clock <= clock
    counter.reset <= reset
    node _counter_io_key_press_T = eq(decoder.io.released, UInt<1>("h0")) @[Top.scala 60:41]
    node _counter_io_key_press_T_1 = and(ready_p1, _counter_io_key_press_T) @[Top.scala 60:38]
    counter.io.key_press <= _counter_io_key_press_T_1 @[Top.scala 60:26]
    counter.io.key_release <= decoder.io.released @[Top.scala 61:28]
    counter.io.clrn <= io.clrn @[Top.scala 62:21]
    reg key_ascii_display_reg : UInt<8>, clock with :
      reset => (reset, UInt<8>("h0")) @[Top.scala 65:40]
    reg display_en : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Top.scala 66:29]
    node _T = eq(io.clrn, UInt<1>("h0")) @[Top.scala 67:10]
    when _T : @[Top.scala 67:20]
      data_d1 <= UInt<1>("h0") @[Top.scala 68:15]
      key_ascii_display_reg <= UInt<1>("h0") @[Top.scala 69:29]
      display_en <= UInt<1>("h0") @[Top.scala 70:18]
    else :
      when ready_p1 : @[Top.scala 73:22]
        data_d1 <= keyboard.io.data @[Top.scala 74:17]
        key_ascii_display_reg <= decoder.io.ascii @[Top.scala 75:31]
        display_en <= UInt<1>("h1") @[Top.scala 76:20]
      else :
        when decoder.io.released : @[Top.scala 77:40]
          display_en <= UInt<1>("h0") @[Top.scala 78:20]
    when display_en : @[Top.scala 82:22]
      node _seg0_io_in_T = bits(data_d1, 3, 0) @[Top.scala 84:28]
      seg0.io.in <= _seg0_io_in_T @[Top.scala 84:18]
      node _seg1_io_in_T = bits(data_d1, 7, 4) @[Top.scala 85:28]
      seg1.io.in <= _seg1_io_in_T @[Top.scala 85:18]
      node _seg2_io_in_T = bits(key_ascii_display_reg, 3, 0) @[Top.scala 87:42]
      seg2.io.in <= _seg2_io_in_T @[Top.scala 87:18]
      node _seg3_io_in_T = bits(key_ascii_display_reg, 7, 4) @[Top.scala 88:42]
      seg3.io.in <= _seg3_io_in_T @[Top.scala 88:18]
    else :
      seg0.io.in <= UInt<1>("h0") @[Top.scala 90:18]
      seg1.io.in <= UInt<1>("h0") @[Top.scala 91:18]
      seg2.io.in <= UInt<1>("h0") @[Top.scala 92:18]
      seg3.io.in <= UInt<1>("h0") @[Top.scala 93:18]
    seg0.io.en <= display_en @[Top.scala 96:16]
    seg1.io.en <= display_en @[Top.scala 97:16]
    seg2.io.en <= display_en @[Top.scala 98:16]
    seg3.io.en <= display_en @[Top.scala 99:16]
    seg4.io.en <= UInt<1>("h1") @[Top.scala 102:16]
    seg5.io.en <= UInt<1>("h1") @[Top.scala 103:16]
    seg4.io.in <= counter.io.ones @[Top.scala 104:16]
    seg5.io.in <= counter.io.tens @[Top.scala 105:16]
    io.seg_out_0 <= seg0.io.seg @[Top.scala 108:18]
    io.seg_out_1 <= seg1.io.seg @[Top.scala 109:18]
    io.seg_out_2 <= seg2.io.seg @[Top.scala 110:18]
    io.seg_out_3 <= seg3.io.seg @[Top.scala 111:18]
    io.seg_out_4 <= seg4.io.seg @[Top.scala 112:18]
    io.seg_out_5 <= seg5.io.seg @[Top.scala 113:18]

