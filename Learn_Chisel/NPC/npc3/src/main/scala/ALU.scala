import chisel3._
import chisel3.util._

class ALU extends Module {
    val io = IO(new Bundle {
        val rs1    = Input(UInt(32.W))
        val rs2    = Input(UInt(32.W))
        val imm    = Input(SInt(32.W))
        val pc     = Input(UInt(32.W))
        val alua   = Input(UInt(1.W))
        val alub   = Input(UInt(2.W))
        val aluctr = Input(UInt(4.W))
        val less   = Output(UInt(1.W))
        val zero   = Output(UInt(1.W))
        val result = Output(UInt(32.W))

        // val issub = Output(Bool())
        // val aluaout = Output(UInt(32.W))
        // val alubout = Output(UInt(32.W))
    })


    // 选择A 端输入
    val aluA = Mux(io.alua === "b1".U, io.pc, io.rs1)

    // 选择B 端输入
    val aluB = MuxLookup(io.alub, io.rs2, Seq(
        "b01".U -> io.imm.asUInt,   // 立即数
        "b10".U -> 4.U              // 常数 4
    ))

    // 共用加减法
    // 判断是否是需要减法
    val isSub = io.aluctr === "b1000".U || io.aluctr === "b0010".U // || io.aluctr === "b1010".U
    val operandB = Mux(isSub, ~aluB, aluB)
    val carryIn = Mux(isSub, 1.U, 0.U)
    val sum = aluA + operandB + carryIn
    // 溢出检测，用于slt
    val overflow = (aluA(31) =/= aluB(31)) && (sum(31) =/= aluA(31))

    // ALU 计算
    val slt = sum(31) ^ overflow                 // 有符号比较
    val sltu = aluA < aluB                       // 无符号比较
    val sll = aluA << aluB(4, 0)                 // 逻辑左移
    val srl = aluA >> aluB(4, 0)                 // 逻辑右移
    val sra = (aluA.asSInt >> aluB(4, 0)).asUInt // 算术右移
    val xor = aluA ^ aluB                        // 按位异或
    val or  = aluA | aluB                        // 按位或
    val and = aluA & aluB                        // 按位与

    val eq  = aluA === aluB


    // 选择 ALU 计算结果
    io.result := MuxLookup(io.aluctr, 0.U, Seq(
        "b0000".U -> sum,   // add, addi, jal, jalr, auipc
        "b1000".U -> sum,   // sub
        "b0010".U -> slt,   // slt, slti, beq, bne, blt, bge
        "b1010".U -> sltu,  // sltu, sltiu, bltu, bgeu
        "b0001".U -> sll,   // sll, slli
        "b0101".U -> srl,   // srl, srli
        "b1101".U -> sra,   // sra, srai
        "b0100".U -> xor,   // xor, xori
        "b0110".U -> or,    // or, ori
        "b0111".U -> and,   // and, andi
        "b0011".U -> aluB   // lui 
    ))



    // 计算 zero 和 less 信号
    io.zero := eq.asUInt
    io.less := MuxLookup(io.aluctr, 0.U, Seq(
        "b0010".U -> slt.asUInt,
        "b1010".U -> sltu.asUInt
    ))
     

    // io.issub := isSub
    // io.aluaout := aluA
    // io.alubout := aluB
}

