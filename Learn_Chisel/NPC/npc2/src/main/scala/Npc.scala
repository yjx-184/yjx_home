import chisel3._
import chisel3.util._

// ========================== 黑盒模块定义 ============================================
// EbreakDetector: 用于检测是否触发EBreak指令
class EbreakDetector extends BlackBox {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val pc = Input(UInt(32.W))
    val exit = Output(Bool())  
  })
}

// InstFetch: 用于获取指令
class InstFetch extends  BlackBox {
  val io = IO(new Bundle {
    val clk = Input(Clock())
    val pc = Input(UInt(32.W))
    val inst = Output(UInt(32.W))
    // val gpr = Input(Vec(16, UInt(32.W)))
  })
}

// DataMem: 访存模块，支持读写操作
class DataMem extends BlackBox {
  val io = IO(new Bundle {
    val clk = Input(Clock())
    val valid = Input(Bool())          // 访存有效信号
    val wen = Input(Bool())            // 写使能信号
    val raddr = Input(UInt(32.W))      // 读地址
    val waddr = Input(UInt(32.W))      // 写地址
    val wdata = Input(UInt(32.W))      // 写入数据
    val wmask = Input(UInt(3.W))       // 写掩码
    val rdata = Output(UInt(32.W))     // 读数据输出
  })
}

// ==========================  Npc模块定义  ==========================
class Npc extends Module {
  val io = IO(new Bundle {
    val pc = Output(UInt(32.W))            // 当前PC值
    val inst = Output(UInt(32.W))          // 当前指令
    val exit = Output(Bool())              // 是否退出信号
    val regs = Output(Vec(16, UInt(32.W))) // 寄存器值
    val nextPC = Output(UInt(32.W))        // 下一条指令的PC值
  })

  // 获取指令模块实例
  val instfetch = Module(new InstFetch)
   instfetch.io.clk := clock

  // ==========================  寄存器定义  ==========================
  val pc = RegInit(0x80000000L.U(32.W))                 // 程序计数器
  val regs = RegInit(VecInit(Seq.fill(16)(0.U(32.W))))  // 16个通用寄存器
  regs(0) := 0.U // 强制x0始终为0


  // ==========================  指令寄存器  ==========================
  val instReg = Reg(UInt(32.W))
  instReg :=  instfetch.io.inst
  io.inst := instReg


  // ==========================  立即数生成函数  ==========================
  def immI(inst: UInt) = Cat(Fill(20, inst(31)), inst(31, 20)).asSInt
  def immS(inst: UInt) = Cat(Fill(20, inst(31)), inst(31, 25), inst(11, 7)).asSInt
  // def immB(inst: UInt) = Cat(Fill(19, inst(31)), inst(31), inst(7), inst(30, 25), inst(11, 8), 0.U(1.W)).asSInt
  def immU(inst: UInt) = Cat(inst(31, 12), 0.U(12.W)).asSInt
  def immJ(inst: UInt) = Cat(Fill(11, inst(31)), inst(31), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W)).asSInt

  

  // ==========================  指令解析函数  ==========================
  val opcode = instReg(6, 0)
  // val opcode = io.inst(6, 0)
  def decodeInst(inst: UInt): (UInt, UInt, UInt, UInt, UInt, SInt, UInt) = {
    val opcode = inst(6, 0)
    val rd = Wire(UInt(4.W))
    val rs1 = Wire(UInt(4.W))
    val rs2 = Wire(UInt(4.W))
    val funct3 = Wire(UInt(3.W))
    val funct7 = Wire(UInt(7.W))
    val imm = Wire(SInt(32.W))
    val wmask = Wire(UInt(3.W))

    rd := 0.U
    rs1 := 0.U
    rs2 := 0.U
    imm := 0.S
    funct3 := 0.U
    funct7 := 0.U
    wmask := "b111".U

    switch(opcode) {
      is("b0110111".U) { // U 型（LUI）
        rd := inst(11, 8)
        imm := immU(inst)
      }
      is("b0010111".U) { // U 型（AUIPC）
        rd := inst(11, 8)
        imm := immU(inst)
      }
      
      is("b0010011".U) { // I 型
        rd := inst(11, 8)
        rs1 := inst(19, 15)
        imm := immI(inst)
        funct3 := inst(14, 12)
      }
      // is("b0000011".U) { // I 型
      //   rd := inst(11, 7)
      //   rs1 := inst(19, 15)
      //   imm := immI(inst)
      //   funct3 := inst(14, 12)
      // }
      is("b1100111".U) { // I 型JALR
        rd := inst(11, 8)
        rs1 := inst(19, 16)
        imm := immI(inst)
        funct3 := inst(14, 12)
      }
      is("b0100011".U) { // S 型
        rs1 := inst(19, 16)
        rs2 := inst(24, 21)
        imm := immS(inst)
        funct3 := inst(14, 12)

        switch(funct3) {
          is("b010".U) {  // SW
            wmask := "b1111".U  // 全字存储
          }
          is("b001".U) { // SH
            wmask := "b0011".U // 半字存储
          }
          is("b000".U) { // SB
            wmask := "b0001".U // 字节存储
          }
        }
      }
      is("b1101111".U) { // J 型（JAL）
        rd := inst(11, 8)
        imm := immJ(inst)
      }
      // is("b0110011".U) { // R 型
      //   rd := inst(11, 7)
      //   rs1 := inst(19, 15)
      //   rs2 := inst(24, 20)
      //   funct3 := inst(14, 12)
      //   funct7 := inst(31, 25)
      // }
      // is("b1100011".U) { // B 型
      //   rs1 := inst(19, 15)
      //   rs2 := inst(24, 20)
      //   imm := immB(inst)
      //   funct3 := inst(14, 12)
      // }
    }

    (rd, rs1, rs2, funct3, funct7, imm, wmask)
  }

  // ==========================  使用指令解析函数  ==========================
  val (rd, rs1, rs2, funct3, funct7, imm, wmask) = decodeInst(instReg)
  // val (rd, rs1, rs2, funct3, funct7, imm, wmask) = decodeInst(io.inst)

  // ==========================  存储处理逻辑  ==========================
  val is_store = opcode === "b0100011".U
  val store_addr = (regs(rs1).asSInt + imm.asSInt).asUInt
  val store_data = regs(rs2)
  

  // 连接到 MemAccess 模块 SW、SH、SB
  val mem = Module(new DataMem)
  mem.io.clk := clock
  mem.io.valid := is_store
  mem.io.wen := is_store
  mem.io.raddr := regs(rs1)
  mem.io.waddr := store_addr
  mem.io.wdata := store_data
  mem.io.wmask := wmask


  // ==========================  寄存器写入  ==========================
  val regWriteData = MuxLookup(opcode, 0.U, Seq(
    "b0010111".U -> (pc + imm.asUInt),               // AUIPC
    "b0110111".U -> (imm.asUInt),                    // LUI
    "b0010011".U -> (regs(rs1).asSInt + imm).asUInt, // ADDI
    "b1100111".U -> (pc + 4.U),                      // JALR
    "b1101111".U -> (pc + 4.U)                       // JAL
    
  ))
  when(rd =/= 0.U && rd < 16.U) { regs(rd) := regWriteData }

  
  // ==========================  计算下一条指令地址  ==========================
  val nextPC = Wire(UInt(32.W))
  nextPC := MuxLookup(opcode, pc + 4.U, Seq(
    "b1100111".U -> (((regs(rs1).asSInt + imm).asUInt & ~1.U)),// JALR
    "b1101111".U -> (pc + imm.asUInt) // JAL
  ))

  // ==========================  复位信号稳定处理  ==========================
    val reset_stable = RegInit(false.B) // 用来标识复位是否已稳定
    when(reset.asBool()) {
      reset_stable := false.B   // 复位时设置为false
    } .elsewhen(!reset.asBool()) {
      reset_stable := true.B    // 复位结束时设置为true
    }
  

  // ==========================  更新PC  ==========================
    when(reset.asBool()) {
      // 复位时直接将PC设置为初始值
      pc := 0x80000000L.U(32.W)  // 这里可以设置你想要的复位值
    } .elsewhen(reset_stable) {
      // 非复位时，基于正常时钟周期更新PC
      pc := nextPC
    }

  // ==========================  连接输出  ==========================
  io.nextPC := nextPC
  io.pc := pc
  io.regs := regs

  // ==========================  Ebreak 检测  ==========================
  val ebreakDetector = Module(new EbreakDetector)
  ebreakDetector.io.inst := instReg
  // ebreakDetector.io.inst := io.inst
  ebreakDetector.io.pc := pc
  io.exit := ebreakDetector.io.exit

  // ==========================   instfetch模块连接  ==========================
   instfetch.io.pc := pc
  //  instfetch.io.gpr := regs

}

// ==========================  生成Verilog  ==========================
object Npc extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Npc)
}
