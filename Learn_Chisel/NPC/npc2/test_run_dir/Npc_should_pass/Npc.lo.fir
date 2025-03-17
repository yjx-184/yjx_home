circuit Npc :
  module Npc :
    input clock : Clock
    input reset : UInt<1>
    output io_exit : UInt<1>
    output io_pc : UInt<32>
    output io_regFileOut_0 : UInt<32>
    output io_regFileOut_1 : UInt<32>
    output io_regFileOut_2 : UInt<32>
    output io_regFileOut_3 : UInt<32>
    output io_regFileOut_4 : UInt<32>
    output io_regFileOut_5 : UInt<32>
    output io_regFileOut_6 : UInt<32>
    output io_regFileOut_7 : UInt<32>
    output io_regFileOut_8 : UInt<32>
    output io_regFileOut_9 : UInt<32>
    output io_regFileOut_10 : UInt<32>
    output io_regFileOut_11 : UInt<32>
    output io_regFileOut_12 : UInt<32>
    output io_regFileOut_13 : UInt<32>
    output io_regFileOut_14 : UInt<32>
    output io_regFileOut_15 : UInt<32>
    output io_regFileOut_16 : UInt<32>
    output io_regFileOut_17 : UInt<32>
    output io_regFileOut_18 : UInt<32>
    output io_regFileOut_19 : UInt<32>
    output io_regFileOut_20 : UInt<32>
    output io_regFileOut_21 : UInt<32>
    output io_regFileOut_22 : UInt<32>
    output io_regFileOut_23 : UInt<32>
    output io_regFileOut_24 : UInt<32>
    output io_regFileOut_25 : UInt<32>
    output io_regFileOut_26 : UInt<32>
    output io_regFileOut_27 : UInt<32>
    output io_regFileOut_28 : UInt<32>
    output io_regFileOut_29 : UInt<32>
    output io_regFileOut_30 : UInt<32>
    output io_regFileOut_31 : UInt<32>

    reg regFile_0 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_0) @[Npc.scala 16:24]
    reg regFile_1 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_1) @[Npc.scala 16:24]
    reg regFile_2 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_2) @[Npc.scala 16:24]
    reg regFile_3 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_3) @[Npc.scala 16:24]
    reg regFile_4 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_4) @[Npc.scala 16:24]
    reg regFile_5 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_5) @[Npc.scala 16:24]
    reg regFile_6 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_6) @[Npc.scala 16:24]
    reg regFile_7 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_7) @[Npc.scala 16:24]
    reg regFile_8 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_8) @[Npc.scala 16:24]
    reg regFile_9 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_9) @[Npc.scala 16:24]
    reg regFile_10 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_10) @[Npc.scala 16:24]
    reg regFile_11 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_11) @[Npc.scala 16:24]
    reg regFile_12 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_12) @[Npc.scala 16:24]
    reg regFile_13 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_13) @[Npc.scala 16:24]
    reg regFile_14 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_14) @[Npc.scala 16:24]
    reg regFile_15 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_15) @[Npc.scala 16:24]
    reg regFile_16 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_16) @[Npc.scala 16:24]
    reg regFile_17 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_17) @[Npc.scala 16:24]
    reg regFile_18 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_18) @[Npc.scala 16:24]
    reg regFile_19 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_19) @[Npc.scala 16:24]
    reg regFile_20 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_20) @[Npc.scala 16:24]
    reg regFile_21 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_21) @[Npc.scala 16:24]
    reg regFile_22 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_22) @[Npc.scala 16:24]
    reg regFile_23 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_23) @[Npc.scala 16:24]
    reg regFile_24 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_24) @[Npc.scala 16:24]
    reg regFile_25 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_25) @[Npc.scala 16:24]
    reg regFile_26 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_26) @[Npc.scala 16:24]
    reg regFile_27 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_27) @[Npc.scala 16:24]
    reg regFile_28 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_28) @[Npc.scala 16:24]
    reg regFile_29 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_29) @[Npc.scala 16:24]
    reg regFile_30 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_30) @[Npc.scala 16:24]
    reg regFile_31 : UInt<32>, clock with :
      reset => (UInt<1>("h0"), regFile_31) @[Npc.scala 16:24]
    reg pc : UInt<32>, clock with :
      reset => (UInt<1>("h0"), pc) @[Npc.scala 19:19]
    node _inst_T = sub(pc, UInt<32>("h80000000")) @[Npc.scala 31:26]
    node _inst_T_1 = tail(_inst_T, 1) @[Npc.scala 31:26]
    node _inst_T_2 = shr(_inst_T_1, 2) @[Npc.scala 31:38]
    node _inst_T_3 = bits(_inst_T_2, 2, 0)
    node instMem_0 = UInt<32>("h200093") @[Npc.scala 22:{24,24}]
    node _GEN_0 = validif(eq(UInt<1>("h0"), _inst_T_3), instMem_0) @[Npc.scala 34:{16,16}]
    node instMem_1 = UInt<32>("h300113") @[Npc.scala 22:{24,24}]
    node _GEN_1 = mux(eq(UInt<1>("h1"), _inst_T_3), instMem_1, _GEN_0) @[Npc.scala 34:{16,16}]
    node instMem_2 = UInt<32>("h408193") @[Npc.scala 22:{24,24}]
    node _GEN_2 = mux(eq(UInt<2>("h2"), _inst_T_3), instMem_2, _GEN_1) @[Npc.scala 34:{16,16}]
    node instMem_3 = UInt<32>("h510213") @[Npc.scala 22:{24,24}]
    node _GEN_3 = mux(eq(UInt<2>("h3"), _inst_T_3), instMem_3, _GEN_2) @[Npc.scala 34:{16,16}]
    node instMem_4 = UInt<32>("h100073") @[Npc.scala 22:{24,24}]
    node _GEN_4 = mux(eq(UInt<3>("h4"), _inst_T_3), instMem_4, _GEN_3) @[Npc.scala 34:{16,16}]
    node _instMem_inst_T_3 = _GEN_4 @[Npc.scala 34:16]
    node op = bits(_instMem_inst_T_3, 6, 0) @[Npc.scala 34:16]
    node _instMem_inst_T_3_0 = _GEN_4 @[Npc.scala 35:16]
    node rd = bits(_instMem_inst_T_3_0, 11, 7) @[Npc.scala 35:16]
    node _instMem_inst_T_3_1 = _GEN_4 @[Npc.scala 36:17]
    node rs1 = bits(_instMem_inst_T_3_1, 19, 15) @[Npc.scala 36:17]
    node _instMem_inst_T_3_2 = _GEN_4 @[Npc.scala 37:17]
    node imm = bits(_instMem_inst_T_3_2, 31, 20) @[Npc.scala 37:17]
    node _imm_sext_T = bits(imm, 11, 11) @[Npc.scala 40:34]
    node _imm_sext_T_1 = bits(_imm_sext_T, 0, 0) @[Bitwise.scala 74:15]
    node _imm_sext_T_2 = mux(_imm_sext_T_1, UInt<20>("hfffff"), UInt<20>("h0")) @[Bitwise.scala 74:12]
    node imm_sext = cat(_imm_sext_T_2, imm) @[Cat.scala 31:58]
    node _GEN_5 = validif(eq(UInt<1>("h0"), rs1), regFile_0) @[Npc.scala 44:{26,26}]
    node _GEN_6 = mux(eq(UInt<1>("h1"), rs1), regFile_1, _GEN_5) @[Npc.scala 44:{26,26}]
    node _GEN_7 = mux(eq(UInt<2>("h2"), rs1), regFile_2, _GEN_6) @[Npc.scala 44:{26,26}]
    node _GEN_8 = mux(eq(UInt<2>("h3"), rs1), regFile_3, _GEN_7) @[Npc.scala 44:{26,26}]
    node _GEN_9 = mux(eq(UInt<3>("h4"), rs1), regFile_4, _GEN_8) @[Npc.scala 44:{26,26}]
    node _GEN_10 = mux(eq(UInt<3>("h5"), rs1), regFile_5, _GEN_9) @[Npc.scala 44:{26,26}]
    node _GEN_11 = mux(eq(UInt<3>("h6"), rs1), regFile_6, _GEN_10) @[Npc.scala 44:{26,26}]
    node _GEN_12 = mux(eq(UInt<3>("h7"), rs1), regFile_7, _GEN_11) @[Npc.scala 44:{26,26}]
    node _GEN_13 = mux(eq(UInt<4>("h8"), rs1), regFile_8, _GEN_12) @[Npc.scala 44:{26,26}]
    node _GEN_14 = mux(eq(UInt<4>("h9"), rs1), regFile_9, _GEN_13) @[Npc.scala 44:{26,26}]
    node _GEN_15 = mux(eq(UInt<4>("ha"), rs1), regFile_10, _GEN_14) @[Npc.scala 44:{26,26}]
    node _GEN_16 = mux(eq(UInt<4>("hb"), rs1), regFile_11, _GEN_15) @[Npc.scala 44:{26,26}]
    node _GEN_17 = mux(eq(UInt<4>("hc"), rs1), regFile_12, _GEN_16) @[Npc.scala 44:{26,26}]
    node _GEN_18 = mux(eq(UInt<4>("hd"), rs1), regFile_13, _GEN_17) @[Npc.scala 44:{26,26}]
    node _GEN_19 = mux(eq(UInt<4>("he"), rs1), regFile_14, _GEN_18) @[Npc.scala 44:{26,26}]
    node _GEN_20 = mux(eq(UInt<4>("hf"), rs1), regFile_15, _GEN_19) @[Npc.scala 44:{26,26}]
    node _GEN_21 = mux(eq(UInt<5>("h10"), rs1), regFile_16, _GEN_20) @[Npc.scala 44:{26,26}]
    node _GEN_22 = mux(eq(UInt<5>("h11"), rs1), regFile_17, _GEN_21) @[Npc.scala 44:{26,26}]
    node _GEN_23 = mux(eq(UInt<5>("h12"), rs1), regFile_18, _GEN_22) @[Npc.scala 44:{26,26}]
    node _GEN_24 = mux(eq(UInt<5>("h13"), rs1), regFile_19, _GEN_23) @[Npc.scala 44:{26,26}]
    node _GEN_25 = mux(eq(UInt<5>("h14"), rs1), regFile_20, _GEN_24) @[Npc.scala 44:{26,26}]
    node _GEN_26 = mux(eq(UInt<5>("h15"), rs1), regFile_21, _GEN_25) @[Npc.scala 44:{26,26}]
    node _GEN_27 = mux(eq(UInt<5>("h16"), rs1), regFile_22, _GEN_26) @[Npc.scala 44:{26,26}]
    node _GEN_28 = mux(eq(UInt<5>("h17"), rs1), regFile_23, _GEN_27) @[Npc.scala 44:{26,26}]
    node _GEN_29 = mux(eq(UInt<5>("h18"), rs1), regFile_24, _GEN_28) @[Npc.scala 44:{26,26}]
    node _GEN_30 = mux(eq(UInt<5>("h19"), rs1), regFile_25, _GEN_29) @[Npc.scala 44:{26,26}]
    node _GEN_31 = mux(eq(UInt<5>("h1a"), rs1), regFile_26, _GEN_30) @[Npc.scala 44:{26,26}]
    node _GEN_32 = mux(eq(UInt<5>("h1b"), rs1), regFile_27, _GEN_31) @[Npc.scala 44:{26,26}]
    node _GEN_33 = mux(eq(UInt<5>("h1c"), rs1), regFile_28, _GEN_32) @[Npc.scala 44:{26,26}]
    node _GEN_34 = mux(eq(UInt<5>("h1d"), rs1), regFile_29, _GEN_33) @[Npc.scala 44:{26,26}]
    node _GEN_35 = mux(eq(UInt<5>("h1e"), rs1), regFile_30, _GEN_34) @[Npc.scala 44:{26,26}]
    node _GEN_36 = mux(eq(UInt<5>("h1f"), rs1), regFile_31, _GEN_35) @[Npc.scala 44:{26,26}]
    node _regFile_rs1 = _GEN_36 @[Npc.scala 44:26]
    node _aluOut_T = add(_regFile_rs1, imm_sext) @[Npc.scala 44:26]
    node _aluOut_T_1 = tail(_aluOut_T, 1) @[Npc.scala 44:26]
    node _T = eq(op, UInt<5>("h13")) @[Npc.scala 47:11]
    node _T_1 = neq(rd, UInt<1>("h0")) @[Npc.scala 48:13]
    node aluOut = _aluOut_T_1
    node _regFile_rd = aluOut @[Npc.scala 49:{19,19}]
    node _GEN_37 = mux(eq(UInt<1>("h0"), rd), _regFile_rd, regFile_0) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_38 = mux(eq(UInt<1>("h1"), rd), _regFile_rd, regFile_1) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_39 = mux(eq(UInt<2>("h2"), rd), _regFile_rd, regFile_2) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_40 = mux(eq(UInt<2>("h3"), rd), _regFile_rd, regFile_3) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_41 = mux(eq(UInt<3>("h4"), rd), _regFile_rd, regFile_4) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_42 = mux(eq(UInt<3>("h5"), rd), _regFile_rd, regFile_5) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_43 = mux(eq(UInt<3>("h6"), rd), _regFile_rd, regFile_6) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_44 = mux(eq(UInt<3>("h7"), rd), _regFile_rd, regFile_7) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_45 = mux(eq(UInt<4>("h8"), rd), _regFile_rd, regFile_8) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_46 = mux(eq(UInt<4>("h9"), rd), _regFile_rd, regFile_9) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_47 = mux(eq(UInt<4>("ha"), rd), _regFile_rd, regFile_10) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_48 = mux(eq(UInt<4>("hb"), rd), _regFile_rd, regFile_11) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_49 = mux(eq(UInt<4>("hc"), rd), _regFile_rd, regFile_12) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_50 = mux(eq(UInt<4>("hd"), rd), _regFile_rd, regFile_13) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_51 = mux(eq(UInt<4>("he"), rd), _regFile_rd, regFile_14) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_52 = mux(eq(UInt<4>("hf"), rd), _regFile_rd, regFile_15) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_53 = mux(eq(UInt<5>("h10"), rd), _regFile_rd, regFile_16) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_54 = mux(eq(UInt<5>("h11"), rd), _regFile_rd, regFile_17) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_55 = mux(eq(UInt<5>("h12"), rd), _regFile_rd, regFile_18) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_56 = mux(eq(UInt<5>("h13"), rd), _regFile_rd, regFile_19) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_57 = mux(eq(UInt<5>("h14"), rd), _regFile_rd, regFile_20) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_58 = mux(eq(UInt<5>("h15"), rd), _regFile_rd, regFile_21) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_59 = mux(eq(UInt<5>("h16"), rd), _regFile_rd, regFile_22) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_60 = mux(eq(UInt<5>("h17"), rd), _regFile_rd, regFile_23) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_61 = mux(eq(UInt<5>("h18"), rd), _regFile_rd, regFile_24) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_62 = mux(eq(UInt<5>("h19"), rd), _regFile_rd, regFile_25) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_63 = mux(eq(UInt<5>("h1a"), rd), _regFile_rd, regFile_26) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_64 = mux(eq(UInt<5>("h1b"), rd), _regFile_rd, regFile_27) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_65 = mux(eq(UInt<5>("h1c"), rd), _regFile_rd, regFile_28) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_66 = mux(eq(UInt<5>("h1d"), rd), _regFile_rd, regFile_29) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_67 = mux(eq(UInt<5>("h1e"), rd), _regFile_rd, regFile_30) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_68 = mux(eq(UInt<5>("h1f"), rd), _regFile_rd, regFile_31) @[Npc.scala 49:{19,19} 16:24]
    node _GEN_69 = mux(_T_1, _GEN_37, regFile_0) @[Npc.scala 48:22 16:24]
    node _GEN_70 = mux(_T_1, _GEN_38, regFile_1) @[Npc.scala 48:22 16:24]
    node _GEN_71 = mux(_T_1, _GEN_39, regFile_2) @[Npc.scala 48:22 16:24]
    node _GEN_72 = mux(_T_1, _GEN_40, regFile_3) @[Npc.scala 48:22 16:24]
    node _GEN_73 = mux(_T_1, _GEN_41, regFile_4) @[Npc.scala 48:22 16:24]
    node _GEN_74 = mux(_T_1, _GEN_42, regFile_5) @[Npc.scala 48:22 16:24]
    node _GEN_75 = mux(_T_1, _GEN_43, regFile_6) @[Npc.scala 48:22 16:24]
    node _GEN_76 = mux(_T_1, _GEN_44, regFile_7) @[Npc.scala 48:22 16:24]
    node _GEN_77 = mux(_T_1, _GEN_45, regFile_8) @[Npc.scala 48:22 16:24]
    node _GEN_78 = mux(_T_1, _GEN_46, regFile_9) @[Npc.scala 48:22 16:24]
    node _GEN_79 = mux(_T_1, _GEN_47, regFile_10) @[Npc.scala 48:22 16:24]
    node _GEN_80 = mux(_T_1, _GEN_48, regFile_11) @[Npc.scala 48:22 16:24]
    node _GEN_81 = mux(_T_1, _GEN_49, regFile_12) @[Npc.scala 48:22 16:24]
    node _GEN_82 = mux(_T_1, _GEN_50, regFile_13) @[Npc.scala 48:22 16:24]
    node _GEN_83 = mux(_T_1, _GEN_51, regFile_14) @[Npc.scala 48:22 16:24]
    node _GEN_84 = mux(_T_1, _GEN_52, regFile_15) @[Npc.scala 48:22 16:24]
    node _GEN_85 = mux(_T_1, _GEN_53, regFile_16) @[Npc.scala 48:22 16:24]
    node _GEN_86 = mux(_T_1, _GEN_54, regFile_17) @[Npc.scala 48:22 16:24]
    node _GEN_87 = mux(_T_1, _GEN_55, regFile_18) @[Npc.scala 48:22 16:24]
    node _GEN_88 = mux(_T_1, _GEN_56, regFile_19) @[Npc.scala 48:22 16:24]
    node _GEN_89 = mux(_T_1, _GEN_57, regFile_20) @[Npc.scala 48:22 16:24]
    node _GEN_90 = mux(_T_1, _GEN_58, regFile_21) @[Npc.scala 48:22 16:24]
    node _GEN_91 = mux(_T_1, _GEN_59, regFile_22) @[Npc.scala 48:22 16:24]
    node _GEN_92 = mux(_T_1, _GEN_60, regFile_23) @[Npc.scala 48:22 16:24]
    node _GEN_93 = mux(_T_1, _GEN_61, regFile_24) @[Npc.scala 48:22 16:24]
    node _GEN_94 = mux(_T_1, _GEN_62, regFile_25) @[Npc.scala 48:22 16:24]
    node _GEN_95 = mux(_T_1, _GEN_63, regFile_26) @[Npc.scala 48:22 16:24]
    node _GEN_96 = mux(_T_1, _GEN_64, regFile_27) @[Npc.scala 48:22 16:24]
    node _GEN_97 = mux(_T_1, _GEN_65, regFile_28) @[Npc.scala 48:22 16:24]
    node _GEN_98 = mux(_T_1, _GEN_66, regFile_29) @[Npc.scala 48:22 16:24]
    node _GEN_99 = mux(_T_1, _GEN_67, regFile_30) @[Npc.scala 48:22 16:24]
    node _GEN_100 = mux(_T_1, _GEN_68, regFile_31) @[Npc.scala 48:22 16:24]
    node _GEN_101 = mux(_T, _GEN_69, regFile_0) @[Npc.scala 16:24 47:29]
    node _GEN_102 = mux(_T, _GEN_70, regFile_1) @[Npc.scala 16:24 47:29]
    node _GEN_103 = mux(_T, _GEN_71, regFile_2) @[Npc.scala 16:24 47:29]
    node _GEN_104 = mux(_T, _GEN_72, regFile_3) @[Npc.scala 16:24 47:29]
    node _GEN_105 = mux(_T, _GEN_73, regFile_4) @[Npc.scala 16:24 47:29]
    node _GEN_106 = mux(_T, _GEN_74, regFile_5) @[Npc.scala 16:24 47:29]
    node _GEN_107 = mux(_T, _GEN_75, regFile_6) @[Npc.scala 16:24 47:29]
    node _GEN_108 = mux(_T, _GEN_76, regFile_7) @[Npc.scala 16:24 47:29]
    node _GEN_109 = mux(_T, _GEN_77, regFile_8) @[Npc.scala 16:24 47:29]
    node _GEN_110 = mux(_T, _GEN_78, regFile_9) @[Npc.scala 16:24 47:29]
    node _GEN_111 = mux(_T, _GEN_79, regFile_10) @[Npc.scala 16:24 47:29]
    node _GEN_112 = mux(_T, _GEN_80, regFile_11) @[Npc.scala 16:24 47:29]
    node _GEN_113 = mux(_T, _GEN_81, regFile_12) @[Npc.scala 16:24 47:29]
    node _GEN_114 = mux(_T, _GEN_82, regFile_13) @[Npc.scala 16:24 47:29]
    node _GEN_115 = mux(_T, _GEN_83, regFile_14) @[Npc.scala 16:24 47:29]
    node _GEN_116 = mux(_T, _GEN_84, regFile_15) @[Npc.scala 16:24 47:29]
    node _GEN_117 = mux(_T, _GEN_85, regFile_16) @[Npc.scala 16:24 47:29]
    node _GEN_118 = mux(_T, _GEN_86, regFile_17) @[Npc.scala 16:24 47:29]
    node _GEN_119 = mux(_T, _GEN_87, regFile_18) @[Npc.scala 16:24 47:29]
    node _GEN_120 = mux(_T, _GEN_88, regFile_19) @[Npc.scala 16:24 47:29]
    node _GEN_121 = mux(_T, _GEN_89, regFile_20) @[Npc.scala 16:24 47:29]
    node _GEN_122 = mux(_T, _GEN_90, regFile_21) @[Npc.scala 16:24 47:29]
    node _GEN_123 = mux(_T, _GEN_91, regFile_22) @[Npc.scala 16:24 47:29]
    node _GEN_124 = mux(_T, _GEN_92, regFile_23) @[Npc.scala 16:24 47:29]
    node _GEN_125 = mux(_T, _GEN_93, regFile_24) @[Npc.scala 16:24 47:29]
    node _GEN_126 = mux(_T, _GEN_94, regFile_25) @[Npc.scala 16:24 47:29]
    node _GEN_127 = mux(_T, _GEN_95, regFile_26) @[Npc.scala 16:24 47:29]
    node _GEN_128 = mux(_T, _GEN_96, regFile_27) @[Npc.scala 16:24 47:29]
    node _GEN_129 = mux(_T, _GEN_97, regFile_28) @[Npc.scala 16:24 47:29]
    node _GEN_130 = mux(_T, _GEN_98, regFile_29) @[Npc.scala 16:24 47:29]
    node _GEN_131 = mux(_T, _GEN_99, regFile_30) @[Npc.scala 16:24 47:29]
    node _GEN_132 = mux(_T, _GEN_100, regFile_31) @[Npc.scala 16:24 47:29]
    node _pc_T = add(pc, UInt<3>("h4")) @[Npc.scala 54:12]
    node _pc_T_1 = tail(_pc_T, 1) @[Npc.scala 54:12]
    node _instMem_inst_T_3_3 = _GEN_4 @[Npc.scala 61:20]
    node _io_exit_T = eq(_instMem_inst_T_3_3, UInt<21>("h100073")) @[Npc.scala 61:20]
    node _regFile_WIRE_0 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_1 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_2 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_3 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_4 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_5 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_6 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_7 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_8 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_9 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_10 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_11 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_12 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_13 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_14 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_15 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_16 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_17 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_18 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_19 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_20 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_21 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_22 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_23 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_24 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_25 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_26 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_27 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_28 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_29 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_30 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    node _regFile_WIRE_31 = UInt<32>("h0") @[Npc.scala 16:{32,32}]
    io_exit <= _io_exit_T @[Npc.scala 61:11]
    io_pc <= pc @[Npc.scala 55:9]
    io_regFileOut_0 <= regFile_0 @[Npc.scala 58:17]
    io_regFileOut_1 <= regFile_1 @[Npc.scala 58:17]
    io_regFileOut_2 <= regFile_2 @[Npc.scala 58:17]
    io_regFileOut_3 <= regFile_3 @[Npc.scala 58:17]
    io_regFileOut_4 <= regFile_4 @[Npc.scala 58:17]
    io_regFileOut_5 <= regFile_5 @[Npc.scala 58:17]
    io_regFileOut_6 <= regFile_6 @[Npc.scala 58:17]
    io_regFileOut_7 <= regFile_7 @[Npc.scala 58:17]
    io_regFileOut_8 <= regFile_8 @[Npc.scala 58:17]
    io_regFileOut_9 <= regFile_9 @[Npc.scala 58:17]
    io_regFileOut_10 <= regFile_10 @[Npc.scala 58:17]
    io_regFileOut_11 <= regFile_11 @[Npc.scala 58:17]
    io_regFileOut_12 <= regFile_12 @[Npc.scala 58:17]
    io_regFileOut_13 <= regFile_13 @[Npc.scala 58:17]
    io_regFileOut_14 <= regFile_14 @[Npc.scala 58:17]
    io_regFileOut_15 <= regFile_15 @[Npc.scala 58:17]
    io_regFileOut_16 <= regFile_16 @[Npc.scala 58:17]
    io_regFileOut_17 <= regFile_17 @[Npc.scala 58:17]
    io_regFileOut_18 <= regFile_18 @[Npc.scala 58:17]
    io_regFileOut_19 <= regFile_19 @[Npc.scala 58:17]
    io_regFileOut_20 <= regFile_20 @[Npc.scala 58:17]
    io_regFileOut_21 <= regFile_21 @[Npc.scala 58:17]
    io_regFileOut_22 <= regFile_22 @[Npc.scala 58:17]
    io_regFileOut_23 <= regFile_23 @[Npc.scala 58:17]
    io_regFileOut_24 <= regFile_24 @[Npc.scala 58:17]
    io_regFileOut_25 <= regFile_25 @[Npc.scala 58:17]
    io_regFileOut_26 <= regFile_26 @[Npc.scala 58:17]
    io_regFileOut_27 <= regFile_27 @[Npc.scala 58:17]
    io_regFileOut_28 <= regFile_28 @[Npc.scala 58:17]
    io_regFileOut_29 <= regFile_29 @[Npc.scala 58:17]
    io_regFileOut_30 <= regFile_30 @[Npc.scala 58:17]
    io_regFileOut_31 <= regFile_31 @[Npc.scala 58:17]
    regFile_0 <= mux(reset, _regFile_WIRE_0, _GEN_101) @[Npc.scala 16:{24,24}]
    regFile_1 <= mux(reset, _regFile_WIRE_1, _GEN_102) @[Npc.scala 16:{24,24}]
    regFile_2 <= mux(reset, _regFile_WIRE_2, _GEN_103) @[Npc.scala 16:{24,24}]
    regFile_3 <= mux(reset, _regFile_WIRE_3, _GEN_104) @[Npc.scala 16:{24,24}]
    regFile_4 <= mux(reset, _regFile_WIRE_4, _GEN_105) @[Npc.scala 16:{24,24}]
    regFile_5 <= mux(reset, _regFile_WIRE_5, _GEN_106) @[Npc.scala 16:{24,24}]
    regFile_6 <= mux(reset, _regFile_WIRE_6, _GEN_107) @[Npc.scala 16:{24,24}]
    regFile_7 <= mux(reset, _regFile_WIRE_7, _GEN_108) @[Npc.scala 16:{24,24}]
    regFile_8 <= mux(reset, _regFile_WIRE_8, _GEN_109) @[Npc.scala 16:{24,24}]
    regFile_9 <= mux(reset, _regFile_WIRE_9, _GEN_110) @[Npc.scala 16:{24,24}]
    regFile_10 <= mux(reset, _regFile_WIRE_10, _GEN_111) @[Npc.scala 16:{24,24}]
    regFile_11 <= mux(reset, _regFile_WIRE_11, _GEN_112) @[Npc.scala 16:{24,24}]
    regFile_12 <= mux(reset, _regFile_WIRE_12, _GEN_113) @[Npc.scala 16:{24,24}]
    regFile_13 <= mux(reset, _regFile_WIRE_13, _GEN_114) @[Npc.scala 16:{24,24}]
    regFile_14 <= mux(reset, _regFile_WIRE_14, _GEN_115) @[Npc.scala 16:{24,24}]
    regFile_15 <= mux(reset, _regFile_WIRE_15, _GEN_116) @[Npc.scala 16:{24,24}]
    regFile_16 <= mux(reset, _regFile_WIRE_16, _GEN_117) @[Npc.scala 16:{24,24}]
    regFile_17 <= mux(reset, _regFile_WIRE_17, _GEN_118) @[Npc.scala 16:{24,24}]
    regFile_18 <= mux(reset, _regFile_WIRE_18, _GEN_119) @[Npc.scala 16:{24,24}]
    regFile_19 <= mux(reset, _regFile_WIRE_19, _GEN_120) @[Npc.scala 16:{24,24}]
    regFile_20 <= mux(reset, _regFile_WIRE_20, _GEN_121) @[Npc.scala 16:{24,24}]
    regFile_21 <= mux(reset, _regFile_WIRE_21, _GEN_122) @[Npc.scala 16:{24,24}]
    regFile_22 <= mux(reset, _regFile_WIRE_22, _GEN_123) @[Npc.scala 16:{24,24}]
    regFile_23 <= mux(reset, _regFile_WIRE_23, _GEN_124) @[Npc.scala 16:{24,24}]
    regFile_24 <= mux(reset, _regFile_WIRE_24, _GEN_125) @[Npc.scala 16:{24,24}]
    regFile_25 <= mux(reset, _regFile_WIRE_25, _GEN_126) @[Npc.scala 16:{24,24}]
    regFile_26 <= mux(reset, _regFile_WIRE_26, _GEN_127) @[Npc.scala 16:{24,24}]
    regFile_27 <= mux(reset, _regFile_WIRE_27, _GEN_128) @[Npc.scala 16:{24,24}]
    regFile_28 <= mux(reset, _regFile_WIRE_28, _GEN_129) @[Npc.scala 16:{24,24}]
    regFile_29 <= mux(reset, _regFile_WIRE_29, _GEN_130) @[Npc.scala 16:{24,24}]
    regFile_30 <= mux(reset, _regFile_WIRE_30, _GEN_131) @[Npc.scala 16:{24,24}]
    regFile_31 <= mux(reset, _regFile_WIRE_31, _GEN_132) @[Npc.scala 16:{24,24}]
    pc <= mux(reset, UInt<32>("h80000000"), _pc_T_1) @[Npc.scala 19:{19,19} 54:6]
