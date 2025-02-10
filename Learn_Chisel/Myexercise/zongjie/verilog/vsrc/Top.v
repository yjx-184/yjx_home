//模块定义
module Top(
  input        clock,
  input        reset,
  input        io_minorcar, // @[src/main/scala/Top.scala 6:14]
  input        io_timestate, // @[src/main/scala/Top.scala 6:14]
  output [1:0] io_minorLight, // @[src/main/scala/Top.scala 6:14]
  output [1:0] io_mainLight // @[src/main/scala/Top.scala 6:14]
);

//随机化寄存器初始化
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0; //随机数寄存器
`endif // RANDOMIZE_REG_INIT

  //状态寄存器定义（存储当前状态）
  reg [2:0] stateReg; // @[src/main/scala/Top.scala 18:25]

  //状态转移逻辑的中间信号
  //时间状态触发，转移到状态3（AllRed）），否则保持当前状态
  wire [2:0] _GEN_2 = io_timestate ? 3'h3 : stateReg; // @[src/main/scala/Top.scala 43:26 44:18 18:25]
  //时间状态触发且车辆未离开，转移到状态4（MinorGreen），否则保持当前状态
  wire [2:0] _GEN_3 = io_timestate & ~io_minorcar ? 3'h4 : stateReg; // @[src/main/scala/Top.scala 50:54 51:18 18:25]
  //时间状态触发，则转移到状态0（MainGreen），否则保持当前状态
  wire [2:0] _GEN_4 = io_timestate ? 3'h0 : stateReg; // @[src/main/scala/Top.scala 57:26 58:18 18:25]
  
  //如果当前状态是4（MinorOrange），则根据时间状态转移到状态0或保持
  wire [2:0] _GEN_7 = 3'h4 == stateReg ? _GEN_4 : stateReg; // @[src/main/scala/Top.scala 25:21 18:25]
  //当前状态是3（AllRed），则副干道信号灯为2（绿灯），否则根据状态4判断
  wire [1:0] _GEN_9 = 3'h3 == stateReg ? 2'h2 : {{1'd0}, 3'h4 == stateReg}; // @[src/main/scala/Top.scala 25:21 49:21]
  //当前状态是3（AllRed），则根据时间状态转移到状态4或保持
  wire [2:0] _GEN_10 = 3'h3 == stateReg ? _GEN_3 : _GEN_7; // @[src/main/scala/Top.scala 25:21]
  //当前状态是2（MainOrange），则副干道信号灯为0（红灯），否则根据状态3判断
  wire [1:0] _GEN_12 = 3'h2 == stateReg ? 2'h0 : _GEN_9; // @[src/main/scala/Top.scala 25:21 42:21]
  //当前状态是1（MainGreen），则副干道信号灯为0（红灯），否则根据状态2判断
  wire [1:0] _GEN_15 = 3'h1 == stateReg ? 2'h0 : _GEN_12; // @[src/main/scala/Top.scala 25:21 35:21]
  
  //副干道输出逻辑，状态是0（MainGreen），则副干道信号灯为0（红灯），否则根据状态1判断
  assign io_minorLight = 3'h0 == stateReg ? 2'h0 : _GEN_15; // @[src/main/scala/Top.scala 25:21 28:21]
  //主干道信号灯输出逻辑，当前状态是0（MainGreen），则主干道信号灯为2（绿灯），否则根据状态1判断
  assign io_mainLight = 3'h0 == stateReg ? 2'h2 : {{1'd0}, 3'h1 == stateReg}; // @[src/main/scala/Top.scala 25:21 27:20]
  
  //时序逻辑
  always @(posedge clock) begin
    if (reset) begin // @[src/main/scala/Top.scala 18:25]
      stateReg <= 3'h0; // @[src/main/scala/Top.scala 18:25]

        //如果是状态0（默认MainGreen）
    end else if (3'h0 == stateReg) begin // @[src/main/scala/Top.scala 25:21]
      //检测到副干道来车
      if (io_minorcar) begin // @[src/main/scala/Top.scala 29:36]
        //状态寄存器存储状态1（MainOrange）
        stateReg <= 3'h1; // @[src/main/scala/Top.scala 30:18]
      end
        //如果是状态1（MainOrange）
    end else if (3'h1 == stateReg) begin // @[src/main/scala/Top.scala 25:21]
      //时间触发
      if (io_timestate) begin // @[src/main/scala/Top.scala 36:26]
        //进入状态2（AllRed）
        stateReg <= 3'h2; // @[src/main/scala/Top.scala 37:18]
      end
        //如果是状态2
    end else if (3'h2 == stateReg) begin // @[src/main/scala/Top.scala 25:21]
      //进入条件判断（根据时间触发）
      stateReg <= _GEN_2;
    end else begin
      //否则
      stateReg <= _GEN_10;
    end
  end

//寄存器和存储器初始化（用于仿真时随机初始化）
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  stateReg = _RAND_0[2:0];  //随机初始化状态寄存器
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
