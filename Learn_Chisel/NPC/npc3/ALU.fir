circuit ALU :
  module ALU :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip rs1 : UInt<32>, flip rs2 : UInt<32>, flip imm : SInt<32>, flip pc : UInt<32>, flip alua : UInt<1>, flip alub : UInt<2>, flip aluctr : UInt<4>, less : UInt<1>, zero : UInt<1>, result : UInt<32>}

    node _aluA_T = eq(io.alua, UInt<1>("h1")) @[ALU.scala 19:28]
    node aluA = mux(_aluA_T, io.pc, io.rs1) @[ALU.scala 19:19]
    node _aluB_T = asUInt(io.imm) @[ALU.scala 23:27]
    node _aluB_T_1 = eq(UInt<1>("h1"), io.alub) @[Mux.scala 81:61]
    node _aluB_T_2 = mux(_aluB_T_1, _aluB_T, io.rs2) @[Mux.scala 81:58]
    node _aluB_T_3 = eq(UInt<2>("h2"), io.alub) @[Mux.scala 81:61]
    node aluB = mux(_aluB_T_3, UInt<3>("h4"), _aluB_T_2) @[Mux.scala 81:58]
    node _sum_T = add(aluA, aluB) @[ALU.scala 28:20]
    node sum = tail(_sum_T, 1) @[ALU.scala 28:20]
    node _sub_T = sub(aluA, aluB) @[ALU.scala 29:20]
    node sub = tail(_sub_T, 1) @[ALU.scala 29:20]
    node _slt_T = asSInt(sub) @[ALU.scala 30:19]
    node slt = lt(_slt_T, asSInt(UInt<1>("h0"))) @[ALU.scala 30:26]
    node sltu = lt(aluA, aluB) @[ALU.scala 31:21]
    node _sll_T = bits(aluB, 4, 0) @[ALU.scala 32:27]
    node sll = dshl(aluA, _sll_T) @[ALU.scala 32:20]
    node _srl_T = bits(aluB, 4, 0) @[ALU.scala 33:27]
    node srl = dshr(aluA, _srl_T) @[ALU.scala 33:20]
    node _sra_T = asSInt(aluA) @[ALU.scala 34:21]
    node _sra_T_1 = bits(aluB, 4, 0) @[ALU.scala 34:35]
    node _sra_T_2 = dshr(_sra_T, _sra_T_1) @[ALU.scala 34:28]
    node sra = asUInt(_sra_T_2) @[ALU.scala 34:43]
    node xor = xor(aluA, aluB) @[ALU.scala 35:20]
    node or = or(aluA, aluB) @[ALU.scala 36:20]
    node and = and(aluA, aluB) @[ALU.scala 37:20]
    reg resultReg : UInt<32>, clock with :
      reset => (reset, UInt<32>("h0")) @[ALU.scala 40:28]
    reg lessReg : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[ALU.scala 41:26]
    reg zeroReg : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[ALU.scala 42:26]
    node _resultReg_T = eq(UInt<1>("h0"), io.aluctr) @[Mux.scala 81:61]
    node _resultReg_T_1 = mux(_resultReg_T, sum, UInt<1>("h0")) @[Mux.scala 81:58]
    node _resultReg_T_2 = eq(UInt<4>("h8"), io.aluctr) @[Mux.scala 81:61]
    node _resultReg_T_3 = mux(_resultReg_T_2, sub, _resultReg_T_1) @[Mux.scala 81:58]
    node _resultReg_T_4 = eq(UInt<2>("h2"), io.aluctr) @[Mux.scala 81:61]
    node _resultReg_T_5 = mux(_resultReg_T_4, slt, _resultReg_T_3) @[Mux.scala 81:58]
    node _resultReg_T_6 = eq(UInt<4>("ha"), io.aluctr) @[Mux.scala 81:61]
    node _resultReg_T_7 = mux(_resultReg_T_6, sltu, _resultReg_T_5) @[Mux.scala 81:58]
    node _resultReg_T_8 = eq(UInt<1>("h1"), io.aluctr) @[Mux.scala 81:61]
    node _resultReg_T_9 = mux(_resultReg_T_8, sll, _resultReg_T_7) @[Mux.scala 81:58]
    node _resultReg_T_10 = eq(UInt<3>("h5"), io.aluctr) @[Mux.scala 81:61]
    node _resultReg_T_11 = mux(_resultReg_T_10, srl, _resultReg_T_9) @[Mux.scala 81:58]
    node _resultReg_T_12 = eq(UInt<4>("hd"), io.aluctr) @[Mux.scala 81:61]
    node _resultReg_T_13 = mux(_resultReg_T_12, sra, _resultReg_T_11) @[Mux.scala 81:58]
    node _resultReg_T_14 = eq(UInt<3>("h4"), io.aluctr) @[Mux.scala 81:61]
    node _resultReg_T_15 = mux(_resultReg_T_14, xor, _resultReg_T_13) @[Mux.scala 81:58]
    node _resultReg_T_16 = eq(UInt<3>("h6"), io.aluctr) @[Mux.scala 81:61]
    node _resultReg_T_17 = mux(_resultReg_T_16, or, _resultReg_T_15) @[Mux.scala 81:58]
    node _resultReg_T_18 = eq(UInt<3>("h7"), io.aluctr) @[Mux.scala 81:61]
    node _resultReg_T_19 = mux(_resultReg_T_18, and, _resultReg_T_17) @[Mux.scala 81:58]
    resultReg <= _resultReg_T_19 @[ALU.scala 62:15]
    node _zeroReg_T = eq(sub, UInt<1>("h0")) @[ALU.scala 76:21]
    zeroReg <= _zeroReg_T @[ALU.scala 76:13]
    lessReg <= slt @[ALU.scala 77:13]
    io.result <= resultReg @[ALU.scala 80:15]
    io.zero <= zeroReg @[ALU.scala 81:13]
    io.less <= lessReg @[ALU.scala 82:13]

