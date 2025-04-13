circuit Mynextpc :
  module Mynextpc :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip imm : SInt<32>, flip rs1 : UInt<32>, flip pc : UInt<32>, flip pcasrc : UInt<1>, flip pcbsrc : UInt<1>, nextpc : UInt<32>}

    node _pca_T = eq(io.pcasrc, UInt<1>("h1")) @[Mynextpc.scala 14:29]
    node _pca_T_1 = asUInt(io.imm) @[Mynextpc.scala 14:48]
    node pca = mux(_pca_T, _pca_T_1, UInt<3>("h4")) @[Mynextpc.scala 14:18]
    node _pcb_T = eq(io.pcbsrc, UInt<1>("h1")) @[Mynextpc.scala 15:29]
    node pcb = mux(_pcb_T, io.rs1, io.pc) @[Mynextpc.scala 15:18]
    node _io_nextpc_T = add(pca, pcb) @[Mynextpc.scala 16:22]
    node _io_nextpc_T_1 = tail(_io_nextpc_T, 1) @[Mynextpc.scala 16:22]
    io.nextpc <= _io_nextpc_T_1 @[Mynextpc.scala 16:15]

