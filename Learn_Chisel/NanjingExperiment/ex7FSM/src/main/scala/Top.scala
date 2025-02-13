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

    // 实例化ps2_decoder模块
    val decoder = Module(new Ps2_decoder)
    decoder.io.keycode   := keyboard.io.data
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
    counter.io.key_press := decoder.io.pressed
    counter.io.clrn := io.clrn

    // nextdata_n逻辑，确保正确触发数据读取
    val nextdata_n = RegInit(true.B)
    keyboard.io.nextdata_n := nextdata_n

    val ready_delay = RegNext(keyboard.io.ready, false.B)
    when(keyboard.io.ready && !ready_delay) {
        nextdata_n := false.B
    } .otherwise {
        nextdata_n := true.B
    }

    // 按键松开时低四位全灭
    when(!decoder.io.pressed) {
        seg0.io.in := 15.U
        seg1.io.in := 15.U
        seg2.io.in := 15.U
        seg3.io.in := 15.U
    } .otherwise {
        // 低两位：扫描码
        seg0.io.in := keyboard.io.data(3, 0)
        seg1.io.in := keyboard.io.data(7, 4)

        // 中间两位：ASCII码
        seg2.io.in := decoder.io.ascii(3, 0)
        seg3.io.in := decoder.io.ascii(7, 4)
    }

    // 高两位：按键计数
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

  val buffer      = RegInit(0.U(10.W))   // 数据缓存
  val fifo        = RegInit(VecInit(Seq.fill(8)(0.U(8.W))))  // FIFO队列
  val w_ptr       = RegInit(0.U(3.W))    // 写指针
  val r_ptr       = RegInit(0.U(3.W))    // 读指针
  val count       = RegInit(0.U(4.W))    // 数据位计数
  val overflow    = RegInit(false.B)     // 数据溢出标志
  val ready       = RegInit(false.B)     // 数据准备好标志
  val ps2_clk_sync= RegInit(0.U(3.W))    // PS/2时钟同步信号

  ps2_clk_sync := Cat(ps2_clk_sync(1, 0), io.ps2_clk)
  val sampling = ps2_clk_sync(2) && !ps2_clk_sync(1)   // 采样时机

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
    // 数据读取触发
    when (ready && !io.nextdata_n) {
      r_ptr := Mux(r_ptr === 7.U, 0.U, r_ptr + 1.U)
      ready := !(w_ptr === Mux(r_ptr === 7.U, 0.U, r_ptr + 1.U))
    }

    // 采样阶段
    when (sampling) {
      when (count === 10.U) {
        // 校验数据有效性
        val valid = buffer(0) === 0.B && 
                   io.ps2_data === 1.B && 
                   (buffer(9, 1).xorR() === 1.B)

        when (valid) {
          fifo(w_ptr) := buffer(8, 1)
          w_ptr := Mux(w_ptr === 7.U, 0.U, w_ptr + 1.U)
          ready := true.B

          when (r_ptr === Mux(w_ptr === 7.U, 0.U, w_ptr + 1.U)) {
            overflow := true.B
          }
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
        val pressed = Output(Bool())     // 按键是否按下
    })

    val isBreakCode = RegInit(false.B)  // 断码检测标志
    val lastKeycode = RegInit(0.U(8.W)) // 上一个按键的扫描码

    io.pressed := false.B
    io.ascii := 0.U

    when(!io.clrn) {
        isBreakCode := false.B
        lastKeycode := 0.U
        io.ascii := 0.U
        io.pressed := false.B
    } .otherwise {
        when(io.keycode === 0xF0.U) {
            isBreakCode := true.B
        } .otherwise {
            when(isBreakCode) {
                isBreakCode := false.B
                io.pressed := false.B
            } .otherwise {
                lastKeycode := io.keycode
                io.pressed := true.B

                // 根据扫描码转为ASCII码
                switch(io.keycode) {
                    is(0x45.U) { io.ascii := 0x30.U }  // 0
                    is(0x16.U) { io.ascii := 0x31.U }  // 1
                    // 其他按键的ASCII码转换...
                    is(0x14.U) { io.ascii := 0x5A.U }  // Z
                }
            }
        }
    }
}

// 7段数码管模块，用于显示4位数字
class Seg extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(4.W))    // 输入的4位数字
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

  io.seg := "b11111111".U // 默认显示关闭状态

  // 根据输入的4位数字选择显示的7段数码管编码
  switch(io.in) {
    is(0.U) { io.seg := seg0 }
    is(1.U) { io.seg := seg1 }
    is(2.U) { io.seg := seg2 }
    is(3.U) { io.seg := seg3 }
    is(4.U) { io.seg := seg4 }
    is(5.U) { io.seg := seg5 }
    is(6.U) { io.seg := seg6 }
    is(7.U) { io.seg := seg7 }
    is(8.U) { io.seg := seg8 }
    is(9.U) { io.seg := seg9 }
    is(10.U) { io.seg := segA }
    is(11.U) { io.seg := segB }
    is(12.U) { io.seg := segC }
    is(13.U) { io.seg := segD }
    is(14.U) { io.seg := segE }
    is(15.U) { io.seg := segF }
  }
}

// 按键计数模块
class Keycount extends Module {
  val io = IO(new Bundle {
    val key_press = Input(Bool())  // 按键是否按下
    val clrn      = Input(Bool())  // 清零信号
    val ones      = Output(UInt(4.W))  // 个位数
    val tens      = Output(UInt(4.W))  // 十位数
  })

  val count = RegInit(0.U(8.W))  // 按键计数器

  when (!io.clrn) {
    // 清零逻辑
    count := 0.U
  } .elsewhen(io.key_press) {
    // 按键按下时，计数加1
    count := count + 1.U
  }

  // 输出个位数和十位数
  io.ones := count(3, 0)
  io.tens := count(7, 4)
}



object Top extends App {
    (new chisel3.stage.ChiselStage).emitVerilog(new Top)
}