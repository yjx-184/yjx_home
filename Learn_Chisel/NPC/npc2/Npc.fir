circuit Npc :
  extmodule InstFetch :
    input clk : Clock
    input pc : UInt<32>
    output inst : UInt<32>
    defname = InstFetch

  extmodule DataMem :
    input clk : Clock
    input valid : UInt<1>
    input wen : UInt<1>
    input raddr : UInt<32>
    input waddr : UInt<32>
    input wdata : UInt<32>
    input wmask : UInt<3>
    output rdata : UInt<32>
    defname = DataMem

  extmodule EbreakDetector :
    input inst : UInt<32>
    input pc : UInt<32>
    output exit : UInt<1>
    defname = EbreakDetector

  module Npc :
    input clock : Clock
    input reset : UInt<1>
    output io : { pc : UInt<32>, inst : UInt<32>, exit : UInt<1>, regs : UInt<32>[16], nextPC : UInt<32>}

    inst instfetch of InstFetch @[Npc.scala 49:25]
    instfetch.inst is invalid
    instfetch.pc is invalid
    instfetch.clk is invalid
    instfetch.clk <= clock @[Npc.scala 50:21]
    reg pc : UInt<32>, clock with :
      reset => (reset, UInt<32>("h80000000")) @[Npc.scala 53:19]
    wire _regs_WIRE : UInt<32>[16] @[Npc.scala 54:29]
    _regs_WIRE[0] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[1] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[2] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[3] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[4] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[5] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[6] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[7] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[8] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[9] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[10] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[11] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[12] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[13] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[14] <= UInt<32>("h0") @[Npc.scala 54:29]
    _regs_WIRE[15] <= UInt<32>("h0") @[Npc.scala 54:29]
    reg regs : UInt<32>[16], clock with :
      reset => (reset, _regs_WIRE) @[Npc.scala 54:21]
    regs[0] <= UInt<1>("h0") @[Npc.scala 55:11]
    reg instReg : UInt<32>, clock with :
      reset => (UInt<1>("h0"), instReg) @[Npc.scala 59:20]
    instReg <= instfetch.inst @[Npc.scala 60:11]
    io.inst <= instReg @[Npc.scala 61:11]
    node opcode = bits(instReg, 6, 0) @[Npc.scala 74:23]
    node opcode_1 = bits(instReg, 6, 0) @[Npc.scala 77:22]
    wire rd : UInt<4> @[Npc.scala 78:18]
    wire rs1 : UInt<4> @[Npc.scala 79:19]
    wire rs2 : UInt<4> @[Npc.scala 80:19]
    wire funct3 : UInt<3> @[Npc.scala 81:22]
    wire funct7 : UInt<7> @[Npc.scala 82:22]
    wire imm : SInt<32> @[Npc.scala 83:19]
    wire wmask : UInt<3> @[Npc.scala 84:21]
    rd <= UInt<1>("h0") @[Npc.scala 86:8]
    rs1 <= UInt<1>("h0") @[Npc.scala 87:9]
    rs2 <= UInt<1>("h0") @[Npc.scala 88:9]
    imm <= asSInt(UInt<1>("h0")) @[Npc.scala 89:9]
    funct3 <= UInt<1>("h0") @[Npc.scala 90:12]
    funct7 <= UInt<1>("h0") @[Npc.scala 91:12]
    wmask <= UInt<3>("h7") @[Npc.scala 92:11]
    node _T = eq(UInt<6>("h37"), opcode_1) @[Npc.scala 94:20]
    when _T : @[Npc.scala 94:20]
      node _rd_T = bits(instReg, 11, 8) @[Npc.scala 96:19]
      rd <= _rd_T @[Npc.scala 96:12]
      node _imm_T = bits(instReg, 31, 12) @[Npc.scala 68:34]
      node _imm_T_1 = cat(_imm_T, UInt<12>("h0")) @[Cat.scala 31:58]
      node _imm_T_2 = asSInt(_imm_T_1) @[Npc.scala 68:55]
      imm <= _imm_T_2 @[Npc.scala 97:13]
    else :
      node _T_1 = eq(UInt<5>("h17"), opcode_1) @[Npc.scala 94:20]
      when _T_1 : @[Npc.scala 94:20]
        node _rd_T_1 = bits(instReg, 11, 8) @[Npc.scala 100:19]
        rd <= _rd_T_1 @[Npc.scala 100:12]
        node _imm_T_3 = bits(instReg, 31, 12) @[Npc.scala 68:34]
        node _imm_T_4 = cat(_imm_T_3, UInt<12>("h0")) @[Cat.scala 31:58]
        node _imm_T_5 = asSInt(_imm_T_4) @[Npc.scala 68:55]
        imm <= _imm_T_5 @[Npc.scala 101:13]
      else :
        node _T_2 = eq(UInt<5>("h13"), opcode_1) @[Npc.scala 94:20]
        when _T_2 : @[Npc.scala 94:20]
          node _rd_T_2 = bits(instReg, 11, 8) @[Npc.scala 105:19]
          rd <= _rd_T_2 @[Npc.scala 105:12]
          node _rs1_T = bits(instReg, 19, 15) @[Npc.scala 106:20]
          rs1 <= _rs1_T @[Npc.scala 106:13]
          node _imm_T_6 = bits(instReg, 31, 31) @[Npc.scala 65:43]
          node _imm_T_7 = bits(_imm_T_6, 0, 0) @[Bitwise.scala 74:15]
          node _imm_T_8 = mux(_imm_T_7, UInt<20>("hfffff"), UInt<20>("h0")) @[Bitwise.scala 74:12]
          node _imm_T_9 = bits(instReg, 31, 20) @[Npc.scala 65:54]
          node _imm_T_10 = cat(_imm_T_8, _imm_T_9) @[Cat.scala 31:58]
          node _imm_T_11 = asSInt(_imm_T_10) @[Npc.scala 65:64]
          imm <= _imm_T_11 @[Npc.scala 107:13]
          node _funct3_T = bits(instReg, 14, 12) @[Npc.scala 108:23]
          funct3 <= _funct3_T @[Npc.scala 108:16]
        else :
          node _T_3 = eq(UInt<7>("h67"), opcode_1) @[Npc.scala 94:20]
          when _T_3 : @[Npc.scala 94:20]
            node _rd_T_3 = bits(instReg, 11, 8) @[Npc.scala 117:19]
            rd <= _rd_T_3 @[Npc.scala 117:12]
            node _rs1_T_1 = bits(instReg, 19, 16) @[Npc.scala 118:20]
            rs1 <= _rs1_T_1 @[Npc.scala 118:13]
            node _imm_T_12 = bits(instReg, 31, 31) @[Npc.scala 65:43]
            node _imm_T_13 = bits(_imm_T_12, 0, 0) @[Bitwise.scala 74:15]
            node _imm_T_14 = mux(_imm_T_13, UInt<20>("hfffff"), UInt<20>("h0")) @[Bitwise.scala 74:12]
            node _imm_T_15 = bits(instReg, 31, 20) @[Npc.scala 65:54]
            node _imm_T_16 = cat(_imm_T_14, _imm_T_15) @[Cat.scala 31:58]
            node _imm_T_17 = asSInt(_imm_T_16) @[Npc.scala 65:64]
            imm <= _imm_T_17 @[Npc.scala 119:13]
            node _funct3_T_1 = bits(instReg, 14, 12) @[Npc.scala 120:23]
            funct3 <= _funct3_T_1 @[Npc.scala 120:16]
          else :
            node _T_4 = eq(UInt<6>("h23"), opcode_1) @[Npc.scala 94:20]
            when _T_4 : @[Npc.scala 94:20]
              node _rs1_T_2 = bits(instReg, 19, 16) @[Npc.scala 123:20]
              rs1 <= _rs1_T_2 @[Npc.scala 123:13]
              node _rs2_T = bits(instReg, 24, 21) @[Npc.scala 124:20]
              rs2 <= _rs2_T @[Npc.scala 124:13]
              node _imm_T_18 = bits(instReg, 31, 31) @[Npc.scala 66:43]
              node _imm_T_19 = bits(_imm_T_18, 0, 0) @[Bitwise.scala 74:15]
              node _imm_T_20 = mux(_imm_T_19, UInt<20>("hfffff"), UInt<20>("h0")) @[Bitwise.scala 74:12]
              node _imm_T_21 = bits(instReg, 31, 25) @[Npc.scala 66:54]
              node _imm_T_22 = bits(instReg, 11, 7) @[Npc.scala 66:68]
              node imm_hi = cat(_imm_T_20, _imm_T_21) @[Cat.scala 31:58]
              node _imm_T_23 = cat(imm_hi, _imm_T_22) @[Cat.scala 31:58]
              node _imm_T_24 = asSInt(_imm_T_23) @[Npc.scala 66:77]
              imm <= _imm_T_24 @[Npc.scala 125:13]
              node _funct3_T_2 = bits(instReg, 14, 12) @[Npc.scala 126:23]
              funct3 <= _funct3_T_2 @[Npc.scala 126:16]
              node _T_5 = eq(UInt<2>("h2"), funct3) @[Npc.scala 128:24]
              when _T_5 : @[Npc.scala 128:24]
                wmask <= UInt<4>("hf") @[Npc.scala 130:19]
              else :
                node _T_6 = eq(UInt<1>("h1"), funct3) @[Npc.scala 128:24]
                when _T_6 : @[Npc.scala 128:24]
                  wmask <= UInt<2>("h3") @[Npc.scala 133:19]
                else :
                  node _T_7 = eq(UInt<1>("h0"), funct3) @[Npc.scala 128:24]
                  when _T_7 : @[Npc.scala 128:24]
                    wmask <= UInt<1>("h1") @[Npc.scala 136:19]
            else :
              node _T_8 = eq(UInt<7>("h6f"), opcode_1) @[Npc.scala 94:20]
              when _T_8 : @[Npc.scala 94:20]
                node _rd_T_4 = bits(instReg, 11, 8) @[Npc.scala 141:19]
                rd <= _rd_T_4 @[Npc.scala 141:12]
                node _imm_T_25 = bits(instReg, 31, 31) @[Npc.scala 69:43]
                node _imm_T_26 = bits(_imm_T_25, 0, 0) @[Bitwise.scala 74:15]
                node _imm_T_27 = mux(_imm_T_26, UInt<11>("h7ff"), UInt<11>("h0")) @[Bitwise.scala 74:12]
                node _imm_T_28 = bits(instReg, 31, 31) @[Npc.scala 69:54]
                node _imm_T_29 = bits(instReg, 19, 12) @[Npc.scala 69:64]
                node _imm_T_30 = bits(instReg, 20, 20) @[Npc.scala 69:78]
                node _imm_T_31 = bits(instReg, 30, 21) @[Npc.scala 69:88]
                node imm_lo_hi = cat(_imm_T_30, _imm_T_31) @[Cat.scala 31:58]
                node imm_lo = cat(imm_lo_hi, UInt<1>("h0")) @[Cat.scala 31:58]
                node imm_hi_hi = cat(_imm_T_27, _imm_T_28) @[Cat.scala 31:58]
                node imm_hi_1 = cat(imm_hi_hi, _imm_T_29) @[Cat.scala 31:58]
                node _imm_T_32 = cat(imm_hi_1, imm_lo) @[Cat.scala 31:58]
                node _imm_T_33 = asSInt(_imm_T_32) @[Npc.scala 69:108]
                imm <= _imm_T_33 @[Npc.scala 142:13]
    node is_store = eq(opcode, UInt<6>("h23")) @[Npc.scala 167:25]
    node _store_addr_T = asSInt(regs[rs1]) @[Npc.scala 168:31]
    node _store_addr_T_1 = add(_store_addr_T, imm) @[Npc.scala 168:38]
    node _store_addr_T_2 = tail(_store_addr_T_1, 1) @[Npc.scala 168:38]
    node _store_addr_T_3 = asSInt(_store_addr_T_2) @[Npc.scala 168:38]
    node store_addr = asUInt(_store_addr_T_3) @[Npc.scala 168:52]
    inst mem of DataMem @[Npc.scala 173:19]
    mem.rdata is invalid
    mem.wmask is invalid
    mem.wdata is invalid
    mem.waddr is invalid
    mem.raddr is invalid
    mem.wen is invalid
    mem.valid is invalid
    mem.clk is invalid
    mem.clk <= clock @[Npc.scala 174:14]
    mem.valid <= is_store @[Npc.scala 175:16]
    mem.wen <= is_store @[Npc.scala 176:14]
    mem.raddr <= regs[rs1] @[Npc.scala 177:16]
    mem.waddr <= store_addr @[Npc.scala 178:16]
    mem.wdata <= regs[rs2] @[Npc.scala 179:16]
    mem.wmask <= wmask @[Npc.scala 180:16]
    node _regWriteData_T = asUInt(imm) @[Npc.scala 185:31]
    node _regWriteData_T_1 = add(pc, _regWriteData_T) @[Npc.scala 185:25]
    node _regWriteData_T_2 = tail(_regWriteData_T_1, 1) @[Npc.scala 185:25]
    node _regWriteData_T_3 = asUInt(imm) @[Npc.scala 186:26]
    node _regWriteData_T_4 = asSInt(regs[rs1]) @[Npc.scala 187:32]
    node _regWriteData_T_5 = add(_regWriteData_T_4, imm) @[Npc.scala 187:39]
    node _regWriteData_T_6 = tail(_regWriteData_T_5, 1) @[Npc.scala 187:39]
    node _regWriteData_T_7 = asSInt(_regWriteData_T_6) @[Npc.scala 187:39]
    node _regWriteData_T_8 = asUInt(_regWriteData_T_7) @[Npc.scala 187:46]
    node _regWriteData_T_9 = add(pc, UInt<3>("h4")) @[Npc.scala 188:25]
    node _regWriteData_T_10 = tail(_regWriteData_T_9, 1) @[Npc.scala 188:25]
    node _regWriteData_T_11 = add(pc, UInt<3>("h4")) @[Npc.scala 189:25]
    node _regWriteData_T_12 = tail(_regWriteData_T_11, 1) @[Npc.scala 189:25]
    node _regWriteData_T_13 = eq(UInt<5>("h17"), opcode) @[Mux.scala 81:61]
    node _regWriteData_T_14 = mux(_regWriteData_T_13, _regWriteData_T_2, UInt<1>("h0")) @[Mux.scala 81:58]
    node _regWriteData_T_15 = eq(UInt<6>("h37"), opcode) @[Mux.scala 81:61]
    node _regWriteData_T_16 = mux(_regWriteData_T_15, _regWriteData_T_3, _regWriteData_T_14) @[Mux.scala 81:58]
    node _regWriteData_T_17 = eq(UInt<5>("h13"), opcode) @[Mux.scala 81:61]
    node _regWriteData_T_18 = mux(_regWriteData_T_17, _regWriteData_T_8, _regWriteData_T_16) @[Mux.scala 81:58]
    node _regWriteData_T_19 = eq(UInt<7>("h67"), opcode) @[Mux.scala 81:61]
    node _regWriteData_T_20 = mux(_regWriteData_T_19, _regWriteData_T_10, _regWriteData_T_18) @[Mux.scala 81:58]
    node _regWriteData_T_21 = eq(UInt<7>("h6f"), opcode) @[Mux.scala 81:61]
    node regWriteData = mux(_regWriteData_T_21, _regWriteData_T_12, _regWriteData_T_20) @[Mux.scala 81:58]
    node _T_9 = neq(rd, UInt<1>("h0")) @[Npc.scala 192:11]
    node _T_10 = lt(rd, UInt<5>("h10")) @[Npc.scala 192:25]
    node _T_11 = and(_T_9, _T_10) @[Npc.scala 192:19]
    when _T_11 : @[Npc.scala 192:33]
      regs[rd] <= regWriteData @[Npc.scala 192:44]
    wire nextPC : UInt<32> @[Npc.scala 196:20]
    node _nextPC_T = add(pc, UInt<3>("h4")) @[Npc.scala 197:34]
    node _nextPC_T_1 = tail(_nextPC_T, 1) @[Npc.scala 197:34]
    node _nextPC_T_2 = asSInt(regs[rs1]) @[Npc.scala 198:34]
    node _nextPC_T_3 = add(_nextPC_T_2, imm) @[Npc.scala 198:41]
    node _nextPC_T_4 = tail(_nextPC_T_3, 1) @[Npc.scala 198:41]
    node _nextPC_T_5 = asSInt(_nextPC_T_4) @[Npc.scala 198:41]
    node _nextPC_T_6 = asUInt(_nextPC_T_5) @[Npc.scala 198:48]
    node _nextPC_T_7 = not(UInt<1>("h1")) @[Npc.scala 198:57]
    node _nextPC_T_8 = and(_nextPC_T_6, _nextPC_T_7) @[Npc.scala 198:55]
    node _nextPC_T_9 = asUInt(imm) @[Npc.scala 199:31]
    node _nextPC_T_10 = add(pc, _nextPC_T_9) @[Npc.scala 199:25]
    node _nextPC_T_11 = tail(_nextPC_T_10, 1) @[Npc.scala 199:25]
    node _nextPC_T_12 = eq(UInt<7>("h67"), opcode) @[Mux.scala 81:61]
    node _nextPC_T_13 = mux(_nextPC_T_12, _nextPC_T_8, _nextPC_T_1) @[Mux.scala 81:58]
    node _nextPC_T_14 = eq(UInt<7>("h6f"), opcode) @[Mux.scala 81:61]
    node _nextPC_T_15 = mux(_nextPC_T_14, _nextPC_T_11, _nextPC_T_13) @[Mux.scala 81:58]
    nextPC <= _nextPC_T_15 @[Npc.scala 197:10]
    reg reset_stable : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Npc.scala 203:31]
    node _T_12 = bits(reset, 0, 0) @[Npc.scala 204:22]
    when _T_12 : @[Npc.scala 204:26]
      reset_stable <= UInt<1>("h0") @[Npc.scala 205:20]
    else :
      node _T_13 = bits(reset, 0, 0) @[Npc.scala 206:30]
      node _T_14 = eq(_T_13, UInt<1>("h0")) @[Npc.scala 206:17]
      when _T_14 : @[Npc.scala 206:34]
        reset_stable <= UInt<1>("h1") @[Npc.scala 207:20]
    node _T_15 = bits(reset, 0, 0) @[Npc.scala 212:22]
    when _T_15 : @[Npc.scala 212:26]
      pc <= UInt<32>("h80000000") @[Npc.scala 214:10]
    else :
      when reset_stable : @[Npc.scala 215:31]
        pc <= nextPC @[Npc.scala 217:10]
    io.nextPC <= nextPC @[Npc.scala 221:13]
    io.pc <= pc @[Npc.scala 222:9]
    io.regs <= regs @[Npc.scala 223:11]
    inst ebreakDetector of EbreakDetector @[Npc.scala 226:30]
    ebreakDetector.exit is invalid
    ebreakDetector.pc is invalid
    ebreakDetector.inst is invalid
    ebreakDetector.inst <= instReg @[Npc.scala 227:26]
    ebreakDetector.pc <= pc @[Npc.scala 229:24]
    io.exit <= ebreakDetector.exit @[Npc.scala 230:11]
    instfetch.pc <= pc @[Npc.scala 233:20]

