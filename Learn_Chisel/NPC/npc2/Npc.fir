circuit Npc :
  extmodule EbreakDetector :
    input inst : UInt<32>
    input pc : UInt<32>
    output exit : UInt<1>
    defname = EbreakDetector

  module Npc :
    input clock : Clock
    input reset : UInt<1>
    output io : { pc : UInt<32>, inst : UInt<32>, exit : UInt<1>}

    wire instMem : UInt<32>[5] @[Npc.scala 19:24]
    instMem[0] <= UInt<32>("h200093") @[Npc.scala 19:24]
    instMem[1] <= UInt<32>("h300113") @[Npc.scala 19:24]
    instMem[2] <= UInt<32>("h408193") @[Npc.scala 19:24]
    instMem[3] <= UInt<32>("h510213") @[Npc.scala 19:24]
    instMem[4] <= UInt<32>("h100073") @[Npc.scala 19:24]
    reg pc : UInt<32>, clock with :
      reset => (reset, UInt<32>("h0")) @[Npc.scala 27:19]
    reg inst : UInt<32>, clock with :
      reset => (reset, UInt<32>("h0")) @[Npc.scala 28:21]
    io.pc <= pc @[Npc.scala 29:9]
    io.inst <= inst @[Npc.scala 30:11]
    inst ebreakDetector of EbreakDetector @[Npc.scala 33:30]
    ebreakDetector.exit is invalid
    ebreakDetector.pc is invalid
    ebreakDetector.inst is invalid
    ebreakDetector.inst <= inst @[Npc.scala 34:26]
    ebreakDetector.pc <= pc @[Npc.scala 35:24]
    io.exit <= ebreakDetector.exit @[Npc.scala 38:11]
    node _T = eq(io.exit, UInt<1>("h0")) @[Npc.scala 41:8]
    when _T : @[Npc.scala 41:18]
      node _pc_T = add(pc, UInt<3>("h4")) @[Npc.scala 42:14]
      node _pc_T_1 = tail(_pc_T, 1) @[Npc.scala 42:14]
      pc <= _pc_T_1 @[Npc.scala 42:8]
      node _inst_T = sub(pc, UInt<32>("h80000000")) @[Npc.scala 43:25]
      node _inst_T_1 = tail(_inst_T, 1) @[Npc.scala 43:25]
      node _inst_T_2 = shr(_inst_T_1, 2) @[Npc.scala 43:42]
      node _inst_T_3 = bits(_inst_T_2, 2, 0)
      inst <= instMem[_inst_T_3] @[Npc.scala 43:10]

