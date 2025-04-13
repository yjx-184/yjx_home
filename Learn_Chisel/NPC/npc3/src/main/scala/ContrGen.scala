import chisel3._
import chisel3.util._

class ContrGen extends Module {
    val io = IO(new Bundle {
        val opcode = Input(UInt(7.W))
        val func3  = Input(UInt(3.W))
        val func7  = Input(UInt(7.W))
        val immop  = Output(UInt(3.W))  // 立即数类型
        val regwr  = Output(UInt(1.W))  // 控制是否对寄存器rd进行写回，为1时写回寄存器。
        val alua   = Output(UInt(1.W))  // 选择ALU输入端A的来源。为0时选择rs1，为1时选择PC。
        val alub   = Output(UInt(2.W))  // 选择ALU输入端B的来源。00时rs2,01时imm，10时常数4
        val aluctr = Output(UInt(4.W))  // 选择ALU执行的操作
        val branch = Output(UInt(3.W))  // 说明分支和跳转的种类，用于生成最终的分支控制信号
        val memreg = Output(UInt(1.W))  // 选择寄存器rd写回数据来源。0时选择ALU输出。1时选择数据存储器输出。
        val memwr  = Output(UInt(1.W))  // 控制是否对数据存储器进行写入，为1时写回存储器
        val memop  = Output(UInt(3.W))  // 控制数据存储器读写格式
                                        // 为010时为4字节读写，为001时为2字节读写带符号扩展，
                                        // 为000时为1字节读写带符号扩展，为101时为2字节读写无符号扩展，
                                        // 为100时为1字节读写无符号扩展。

        val rdmemop = Output(UInt(3.W))
    })

    // 立即数类型
    io.immop := MuxLookup(io.opcode, 0.U, Seq(
        "b0010011".U -> 0.U,    // I 型（addi)
        "b0000011".U -> 0.U,    // I 型（lw）
        "b1100111".U -> 0.U,    // I 型（jalr）

        "b0100011".U -> 1.U,    // S 型（sw）

        "b1100011".U -> 2.U,    // B 型（beq、bne）

        "b0110111".U -> 3.U,    // U 型（lui）
        "b0010111".U -> 3.U,    // U 型（auipc）

        "b1101111".U -> 4.U,    // J 型（jal）
    ))
    
    // 控制是否对寄存器rd进行写回，为1时写回寄存器
    io.regwr := MuxLookup(io.opcode, "b1".U, Seq(
        "b1100011".U -> "b0".U,     // beq, bne, blt, bge, bltu, bgeu
        "b0100011".U -> "b0".U      // sb, sh, sw
    ))

    // 选择ALU输入端A的来源。为0时选择rs1，为1时选择PC
    io.alua := MuxCase("b0".U, Seq(
        (io.opcode === "b0010111".U) -> "b1".U,     // auipc
        (io.opcode === "b1101111".U) -> "b1".U,     // jal
        (io.opcode === "b1100111".U && io.func3 === "b000".U) -> "b1".U   // jalr
    ))

    // 选择ALU输入端B的来源。00时rs2,01时imm，10时常数4
    io.alub := MuxLookup(io.opcode, "b00".U, Seq(
        "b0110111".U -> "b01".U,    // U 型（lui）
        "b0010111".U -> "b01".U,    // U 型（auipc）
        "b0010011".U -> "b01".U,    // addi
        "b0000011".U -> "b01".U,    // I 型（lw）
        "b0100011".U -> "b01".U,    // S 型（sw）
        "b1101111".U -> "b10".U,    // J 型（jal）
        "b1100111".U -> "b10".U,    // I 型（jalr）
    ))

    // 选择ALU执行的操作
    io.aluctr := MuxCase("b0000".U, Seq(
        (io.opcode === "b0110111".U) -> "b0011".U,    // U 型（lui）

        (io.opcode === "b0010011".U && io.func3 === "b010".U) -> "b0010".U, // slti
        (io.opcode === "b0010011".U && io.func3 === "b011".U) -> "b1010".U, // sltiu
        (io.opcode === "b0010011".U && io.func3 === "b100".U) -> "b0100".U, // xori
        (io.opcode === "b0010011".U && io.func3 === "b110".U) -> "b0110".U, // ori
        (io.opcode === "b0010011".U && io.func3 === "b111".U) -> "b0111".U, // andi
        (io.opcode === "b0010011".U && io.func3 === "b001".U && io.func7 === "b0000000".U) -> "b0001".U, // slli
        (io.opcode === "b0010011".U && io.func3 === "b101".U && io.func7 === "b0000000".U) -> "b0101".U, // srli
        (io.opcode === "b0010011".U && io.func3 === "b101".U && io.func7 === "b0100000".U) -> "b1101".U, // srai

        (io.opcode === "b0110011".U && io.func3 === "b000".U && io.func7 === "b0100000".U) -> "b1000".U, // sub
        (io.opcode === "b0110011".U && io.func3 === "b001".U && io.func7 === "b0000000".U) -> "b0001".U, // sll
        (io.opcode === "b0110011".U && io.func3 === "b010".U && io.func7 === "b0000000".U) -> "b0010".U, // slt
        (io.opcode === "b0110011".U && io.func3 === "b011".U && io.func7 === "b0000000".U) -> "b1010".U, // sltu
        (io.opcode === "b0110011".U && io.func3 === "b100".U && io.func7 === "b0000000".U) -> "b0100".U, // xor
        (io.opcode === "b0110011".U && io.func3 === "b101".U && io.func7 === "b0000000".U) -> "b0101".U, // srl
        (io.opcode === "b0110011".U && io.func3 === "b101".U && io.func7 === "b0100000".U) -> "b1101".U, // sra
        (io.opcode === "b0110011".U && io.func3 === "b110".U && io.func7 === "b0000000".U) -> "b0110".U, // or
        (io.opcode === "b0110011".U && io.func3 === "b111".U && io.func7 === "b0000000".U) -> "b0111".U, // and

        (io.opcode === "b1100011".U && io.func3 === "b000".U) -> "b0010".U, // beq
        (io.opcode === "b1100011".U && io.func3 === "b001".U) -> "b0010".U, // bne
        (io.opcode === "b1100011".U && io.func3 === "b100".U) -> "b0010".U, // blt
        (io.opcode === "b1100011".U && io.func3 === "b101".U) -> "b0010".U, // bge
        (io.opcode === "b1100011".U && io.func3 === "b110".U) -> "b1010".U, // bltu
        (io.opcode === "b1100011".U && io.func3 === "b111".U) -> "b1010".U  // bgeu
    ))

    // 说明分支和跳转的种类，用于生成最终的分支控制信号
    io.branch := MuxCase("b000".U, Seq(
        (io.opcode === "b1101111".U) -> "b001".U, // jal
        (io.opcode === "b1100111".U) -> "b010".U, // jalr

        (io.opcode === "b1100011".U && io.func3 === "b000".U) -> "b100".U, // beq
        (io.opcode === "b1100011".U && io.func3 === "b001".U) -> "b101".U, // bne
        (io.opcode === "b1100011".U && io.func3 === "b100".U) -> "b110".U, // blt
        (io.opcode === "b1100011".U && io.func3 === "b101".U) -> "b111".U, // bge
        (io.opcode === "b1100011".U && io.func3 === "b110".U) -> "b110".U, // bltu
        (io.opcode === "b1100011".U && io.func3 === "b111".U) -> "b111".U  // bgeu
    ))

    // 选择寄存器rd写回数据来源。0时选择ALU输出。1时选择数据存储器输出
    io.memreg := MuxLookup(io.opcode, "b0".U, Seq(
        "b0000011".U -> "b1".U // I 型（lw）
    ))

    // 控制是否对数据存储器进行写入，为1时写回存储器
    io.memwr := MuxLookup(io.opcode, "b0".U, Seq(
        "b0100011".U -> "b1".U // S 型（sw）
    ))

    // 控制数据存储器读写格式
    io.memop := MuxCase("b000".U, Seq(  //sb 为000时为1字节读写带符号扩展
        (io.opcode === "b0100011".U && io.func3 === "b001".U) -> "b001".U, // sh,为001时为2字节读写带符号扩展
        (io.opcode === "b0100011".U && io.func3 === "b010".U) -> "b010".U  // sw,为010时为4字节读写
    ))

    io.rdmemop := MuxCase("b000".U, Seq(    // lb 
        (io.opcode === "b0000011".U && io.func3 === "b001".U) -> "b001".U, // lh,为001时为2字节读写带符号扩展
        (io.opcode === "b0000011".U && io.func3 === "b010".U) -> "b010".U, // lw,为010时为4字节读写
        (io.opcode === "b0000011".U && io.func3 === "b100".U) -> "b100".U, // lbu,为100时为1字节读写无符号扩展
        (io.opcode === "b0000011".U && io.func3 === "b101".U) -> "b101".U, // lhu,为101时为2字节读写无符号扩展
    ))
}

