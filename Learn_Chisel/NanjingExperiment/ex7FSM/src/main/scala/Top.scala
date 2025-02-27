import chisel3._
import chisel3.util._

// Top级模块，负责整合各个子模块
class Top extends Module {
    val io = IO(new Bundle {
        val clrn      = Input(Bool())  // 清零信号
        val ps2_clk   = Input(Bool())  // PS/2时钟信号
        val ps2_data  = Input(Bool())  // PS/2数据线
        val seg_out_0 = Output(UInt(8.W))  // 低两位：扫描码
        val seg_out_1 = Output(UInt(8.W))
        val seg_out_2 = Output(UInt(8.W))  // 中两位：ASCII码
        val seg_out_3 = Output(UInt(8.W))
        val seg_out_4 = Output(UInt(8.W))  // 高两位：按键计数
        val seg_out_5 = Output(UInt(8.W))
    })

    // 实例化ps2_keyboard模块
    val keyboard = Module(new PS2Keyboard)
    keyboard.io.clrn     := io.clrn
    keyboard.io.ps2_clk  := io.ps2_clk
    keyboard.io.ps2_data := io.ps2_data

    // nextda_n信号：ready_p1有效时置0，否则为1
    val nextdata_n = RegInit(true.B)
    keyboard.io.nextdata_n := nextdata_n

    // 产生ready信号的上升沿检测信号，用于检测数据是否准备好
    val ready_delay = RegNext(keyboard.io.ready, false.B)
    val ready_p1 = keyboard.io.ready && !ready_delay

    // 存储从ps2Keyboard模块读取的数据
    val data_d1 = RegInit(0.U(8.W))
    when(ready_p1) {
      data_d1 := keyboard.io.data // 当数据准备好时，存储数据
    }

    // 实例化ps2_decoder模块
    val decoder = Module(new Ps2_decoder)
    decoder.io.keycode   := data_d1
    decoder.io.clrn      := io.clrn

    // 实例化7段数码管显示模块
    val seg0 = Module(new Seg)
    val seg1 = Module(new Seg)
    val seg2 = Module(new Seg)
    val seg3 = Module(new Seg)
    val seg4 = Module(new Seg)
    val seg5 = Module(new Seg)

    // 实例化Keycount模块
    val counter = Module(new Keycount)
    counter.io.key_press := ready_p1 && !decoder.io.released  // 当按键按下时增加计数
    counter.io.key_release := decoder.io.released             // 按键松开时重置计数标记
    counter.io.clrn := io.clrn

    // nextdata_n逻辑，确保正确触发数据读取
    when(ready_p1) {
        nextdata_n := false.B   // 当数据准备好时，允许读取数据
    } .otherwise {
        nextdata_n := true.B    // 否则禁止读取数据
    }

    // 用寄存器保存显示数据和显示使能信号
    val key_scan_display_reg  = RegInit(0.U(8.W)) // 存储扫描码
    val key_ascii_display_reg = RegInit(0.U(8.W)) // 存储ASCII码
    val display_en = RegInit(false.B)             // 显示使能

    when(!io.clrn) {
      key_scan_display_reg  := 0.U
      key_ascii_display_reg := 0.U
      display_en := false.B
    } .otherwise {
      // 按下事件：更新显示数据，并使能显示
      when(ready_p1) {
        key_scan_display_reg  := keyboard.io.data // 更新扫描码
        key_ascii_display_reg := decoder.io.ascii // 更新ASCII码
        display_en := true.B                      // 使能显示
      } .elsewhen(decoder.io.released) {
        display_en := false.B                     // 当按键松开时，禁用显示
      }
    }

    // 根据 display_en 决定低四位（扫描码、ASCII）的显示内容
    val seg0_in = WireDefault(0.U(4.W))
    val seg1_in = WireDefault(0.U(4.W))
    val seg2_in = WireDefault(0.U(4.W))
    val seg3_in = WireDefault(0.U(4.W))

    when(display_en) {
      // 低两位显示扫描码
      seg0_in := key_scan_display_reg(3, 0)
      seg1_in := key_scan_display_reg(7, 4)
      // 中两位显示 ASCII 码
      seg2_in := key_ascii_display_reg(3, 0)
      seg3_in := key_ascii_display_reg(7, 4)
    } .otherwise {
      seg0_in := 0.U
      seg1_in := 0.U
      seg2_in := 0.U
      seg3_in := 0.U
    }

    seg0.io.in := seg0_in
    seg1.io.in := seg1_in
    seg2.io.in := seg2_in
    seg3.io.in := seg3_in

    seg0.io.en := display_en
    seg1.io.en := display_en
    seg2.io.en := display_en
    seg3.io.en := display_en

    // 高两位：按键计数
    seg4.io.en := true.B
    seg5.io.en := true.B
    seg4.io.in := counter.io.ones
    seg5.io.in := counter.io.tens

    // 输出连接
    io.seg_out_0 := seg0.io.seg
    io.seg_out_1 := seg1.io.seg
    io.seg_out_2 := seg2.io.seg
    io.seg_out_3 := seg3.io.seg
    io.seg_out_4 := seg4.io.seg
    io.seg_out_5 := seg5.io.seg
}

// PS/2键盘模块，负责从PS/2接口接收数据
class PS2Keyboard extends Module {
  val io = IO(new Bundle {
    val clrn       = Input(Bool())   // 清零信号
    val ps2_clk    = Input(Bool())   // PS/2时钟信号
    val ps2_data   = Input(Bool())   // PS/2数据线
    val nextdata_n = Input(Bool())   // 数据读取触发信号
    val data       = Output(UInt(8.W))   // 读取的数据
    val ready      = Output(Bool())   // 数据准备好
    val overflow   = Output(Bool())   // 数据溢出
  })
  // ============ 内部寄存器 =================
  val buffer      = RegInit(0.U(10.W))   // 数据缓存
  val fifo        = RegInit(VecInit(Seq.fill(8)(0.U(8.W))))  // FIFO队列
  val w_ptr       = RegInit(0.U(3.W))    // 写指针
  val r_ptr       = RegInit(0.U(3.W))    // 读指针
  val count       = RegInit(0.U(4.W))    // 数据位计数
  val overflow    = RegInit(false.B)     // 数据溢出标志
  val ready       = RegInit(false.B)     // 数据准备好标志
  val ps2_clk_sync= RegInit(0.U(3.W))    // PS/2时钟同步信号

  // ============ PS/2 时钟同步 =================
  ps2_clk_sync := Cat(ps2_clk_sync(1, 0), io.ps2_clk)
  val sampling = ps2_clk_sync(2) && !ps2_clk_sync(1)   // 采样时机

  // ============ 复位逻辑 =================
  when (!io.clrn) {
    // 清零逻辑
    buffer    := 0.U
    fifo      := VecInit(Seq.fill(8)(0.U))
    w_ptr     := 0.U
    r_ptr     := 0.U
    count     := 0.U
    ready     := false.B
    overflow  := false.B
  } .otherwise {
    // ========== 处理 FIFO 读取 ==========
    // 数据读取触发
    when (ready && !io.nextdata_n) {
      r_ptr := r_ptr + 1.U // 读指针前移
      ready := !(w_ptr === r_ptr + 1.U)// 检测 FIFO 是否为空
    }

    // ========== 处理 PS/2 数据接收 ==========
    // 采样阶段
    when (sampling) {         // 仅在 PS/2 时钟下降沿时处理数据
      when (count === 10.U) {
        // 校验数据有效性
        val valid = buffer(0) === 0.B && 
                   io.ps2_data === 1.B && 
                   (buffer(9, 1).xorR() === 1.B)

        when (valid) {
          fifo(w_ptr) := buffer(8, 1)
          w_ptr := w_ptr + 1.U
          ready := true.B
          overflow := (r_ptr === Mux(w_ptr === 7.U, 0.U, w_ptr + 1.U))
        }
        count := 0.U
      } .otherwise {
        // 数据存储到缓冲区
        val bufferVec = VecInit(buffer.asBools)
        bufferVec(count) := io.ps2_data
        buffer := bufferVec.asUInt
        count := count + 1.U
      }
    }
  }

  io.data     := fifo(r_ptr)
  io.ready    := ready
  io.overflow := overflow
}

// PS/2解码器模块，将扫描码转为ASCII码
class Ps2_decoder extends Module {
    val io = IO(new Bundle {
        val keycode = Input(UInt(8.W))   // 扫描码输入
        val clrn    = Input(Bool())      // 清零信号
        val ascii   = Output(UInt(8.W))  // ASCII码输出
        val released = Output(Bool())    // 标记松开事件
    })

    val isBreakCode = RegInit(false.B)  // 断码检测标志
    val lastKeycode = RegInit(0.U(8.W)) // 上一个按键的扫描码

    io.released := false.B
    io.ascii := 0.U

    when(!io.clrn) {
        isBreakCode := false.B
        io.released := false.B
    } .otherwise {
        when(io.keycode === 0xF0.U) {
            isBreakCode := true.B
        } .otherwise {
            when(isBreakCode) {
                isBreakCode := false.B
                io.released := true.B // 发生按键松开事件
            } .otherwise {
                lastKeycode := io.keycode
                io.ascii := 0x00.U

                // 根据扫描码转为ASCII码
                switch(io.keycode) {
                    is(0x45.U) { io.ascii := 0x30.U }  // 0
                    is(0x16.U) { io.ascii := 0x31.U }  // 1
                    is(0x1E.U) { io.ascii := 0x32.U }  // 2
                    is(0x26.U) { io.ascii := 0x33.U }  // 3
                    is(0x25.U) { io.ascii := 0x34.U }  // 4
                    is(0x2E.U) { io.ascii := 0x35.U }  // 5
                    is(0x36.U) { io.ascii := 0x36.U }  // 6
                    is(0x3D.U) { io.ascii := 0x37.U }  // 7
                    is(0x3E.U) { io.ascii := 0x38.U }  // 8
                    is(0x46.U) { io.ascii := 0x39.U }  // 9

                    is(0x1C.U) { io.ascii := 0x41.U }  // A
                    is(0x32.U) { io.ascii := 0x42.U }  // B
                    is(0x21.U) { io.ascii := 0x43.U }  // C
                    is(0x23.U) { io.ascii := 0x44.U }  // D
                    is(0x24.U) { io.ascii := 0x45.U }  // E
                    is(0x2B.U) { io.ascii := 0x46.U }  // F
                    is(0x34.U) { io.ascii := 0x47.U }  // G
                    is(0x33.U) { io.ascii := 0x48.U }  // H
                    is(0x43.U) { io.ascii := 0x49.U }  // I
                    is(0x3B.U) { io.ascii := 0x4A.U }  // J
                    is(0x42.U) { io.ascii := 0x4B.U }  // K
                    is(0x4B.U) { io.ascii := 0x4C.U }  // L
                    is(0x3A.U) { io.ascii := 0x4D.U }  // M
                    is(0x31.U) { io.ascii := 0x4E.U }  // N
                    is(0x44.U) { io.ascii := 0x4F.U }  // O
                    is(0x4D.U) { io.ascii := 0x50.U }  // P
                    is(0x15.U) { io.ascii := 0x51.U }  // Q
                    is(0x2D.U) { io.ascii := 0x52.U }  // R
                    is(0x1B.U) { io.ascii := 0x53.U }  // S
                    is(0x2C.U) { io.ascii := 0x54.U }  // T
                    is(0x3C.U) { io.ascii := 0x55.U }  // U
                    is(0x2A.U) { io.ascii := 0x56.U }  // V
                    is(0x1D.U) { io.ascii := 0x57.U }  // W
                    is(0x1A.U) { io.ascii := 0x58.U }  // X
                    is(0x22.U) { io.ascii := 0x59.U }  // Y
                    is(0x14.U) { io.ascii := 0x5A.U }  // Z
                }
            }
        }
    }
}

// 7段数码管模块，用于显示4位数字
class Seg extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(5.W))    // 输入的4位数字
    val en = Input(Bool())       // 使能信号
    val seg = Output(UInt(8.W))  // 7段数码管的显示信号
  })

  // 定义7段数码管显示的各个数字（0-9和A-F）
  val seg0  = "b11111100".U(8.W)
  val seg1  = "b01100000".U(8.W)
  val seg2  = "b11011010".U(8.W)
  val seg3  = "b11110010".U(8.W)
  val seg4  = "b01100110".U(8.W)
  val seg5  = "b10110110".U(8.W)
  val seg6  = "b10111110".U(8.W)
  val seg7  = "b11100000".U(8.W)
  val seg8  = "b11111110".U(8.W)
  val seg9  = "b11110110".U(8.W)
  val segA  = "b11101110".U(8.W)
  val segB  = "b00111110".U(8.W)
  val segC  = "b10011100".U(8.W)
  val segD  = "b01111010".U(8.W)
  val segE  = "b10011110".U(8.W)
  val segF  = "b10001110".U(8.W)

  io.seg := 0xff.U // 默认显示关闭状态

  // 根据输入的4位数字选择显示的7段数码管编码
  when(!io.en) {
    io.seg := 0xff.U
  } .otherwise {
    switch(io.in) {
      is(0.U) { io.seg := ~seg0 }
      is(1.U) { io.seg := ~seg1 }
      is(2.U) { io.seg := ~seg2 }
      is(3.U) { io.seg := ~seg3 }
      is(4.U) { io.seg := ~seg4 }
      is(5.U) { io.seg := ~seg5 }
      is(6.U) { io.seg := ~seg6 }
      is(7.U) { io.seg := ~seg7 }
      is(8.U) { io.seg := ~seg8 }
      is(9.U) { io.seg := ~seg9 }
      is(10.U) { io.seg := ~segA }
      is(11.U) { io.seg := ~segB }
      is(12.U) { io.seg := ~segC }
      is(13.U) { io.seg := ~segD }
      is(14.U) { io.seg := ~segE }
      is(15.U) { io.seg := ~segF }
    }
  }
  
}

// 按键计数模块
class Keycount extends Module {
  val io = IO(new Bundle {
    val key_press = Input(Bool())  // 按下标记
    val key_release = Input(Bool())// 松开标记
    val clrn      = Input(Bool())  // 清零信号
    val ones      = Output(UInt(4.W))  // 个位数
    val tens      = Output(UInt(4.W))  // 十位数
  })

    val ones = RegInit(0.U(4.W))
    val tens = RegInit(0.U(4.W))
    val counted = RegInit(false.B) // 记录是否已经被计数

    when(!io.clrn) {
      ones := 0.U
      tens := 0.U
      counted := false.B
    } .otherwise {
      // 按下事件：增加计数
      when(io.key_press && !counted) {
        counted := true.B 

        when(ones === 9.U) {
          ones := 0.U
          tens := Mux(tens === 9.U, 0.U, tens + 1.U)
        } .otherwise {
          ones := ones + 1.U
        }
      }

      // 松开事件：重置 counted 标志
      when(io.key_release) { 
        counted := false.B
      }
    }

    io.ones := ones
    io.tens := tens
}




object Top extends App {
    (new chisel3.stage.ChiselStage).emitVerilog(new Top)
}