//模块定义
module Top(
  input        clock,
  input        reset,
  input        io_btn,
  output [7:0] io_led
);

//随机化初始化支持，仿真时初始化寄存器的随机值
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
`endif // RANDOMIZE_REG_INIT

  //寄存器定义
  reg  btnsync_REG; // @[Top.scala 13:38] 按钮信号同步
  reg  btnsync; // @[Top.scala 13:30]
  reg [13:0] tick_reg; // @[Top.scala 18:22]  生成定时信号tick
  //组合逻辑信号
  wire  tick = tick_reg == 14'h270f; // @[Top.scala 19:20]
  wire [13:0] _tick_reg_T_1 = tick_reg + 14'h1; // @[Top.scala 20:31] 自增信号

  //寄存器定义
  reg  btnDeb; // @[Top.scala 25:19]  存储同步后的按钮信号
  reg [2:0] btnClean_reg; // @[Top.scala 32:22] 用于滤波按钮信号
  //组合逻辑信号
  wire [2:0] _btnClean_reg_T_1 = {btnClean_reg[1:0],btnDeb}; // @[Cat.scala 31:58]
  wire  btnClean = btnClean_reg[2] & btnClean_reg[0] | btnClean_reg[2] & btnClean_reg[1] | btnClean_reg[1] &
    btnClean_reg[0]; // @[Top.scala 36:43]

  //寄存器定义，检测按钮信号上升沿
  reg  risingEdge_REG; // @[Top.scala 41:43]
  //组合逻辑信号，检测btnClean的上升沿
  wire  risingEdge = btnClean & ~risingEdge_REG; // @[Top.scala 41:33]

  reg [7:0] counter; // @[Top.scala 45:24]
  wire [7:0] _counter_T_1 = counter + 8'h1; // @[Top.scala 47:24]

  //输出信号
  assign io_led = counter; // @[Top.scala 51:10]

  //时序逻辑
  always @(posedge clock) begin
    btnsync_REG <= io_btn; // @[Top.scala 13:38]
    btnsync <= btnsync_REG; // @[Top.scala 13:30]
    if (reset) begin // @[Top.scala 18:22]
      tick_reg <= 14'h0; // @[Top.scala 18:22]
    end else if (tick) begin // @[Top.scala 20:15]
      tick_reg <= 14'h0;
    end else begin
      tick_reg <= _tick_reg_T_1;
    end
    if (tick) begin // @[Top.scala 26:14]
      btnDeb <= btnsync; // @[Top.scala 27:12]
    end
    if (reset) begin // @[Top.scala 32:22]
      btnClean_reg <= 3'h0; // @[Top.scala 32:22]
    end else if (tick) begin // @[Top.scala 33:13]
      btnClean_reg <= _btnClean_reg_T_1; // @[Top.scala 34:11]
    end
    risingEdge_REG <= btnClean_reg[2] & btnClean_reg[0] | btnClean_reg[2] & btnClean_reg[1] | btnClean_reg[1] &
      btnClean_reg[0]; // @[Top.scala 36:43]
    if (reset) begin // @[Top.scala 45:24]
      counter <= 8'h0; // @[Top.scala 45:24]
    end else if (risingEdge) begin // @[Top.scala 46:20]
      counter <= _counter_T_1; // @[Top.scala 47:13]
    end
  end

//随机化初始化
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
  btnsync_REG = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  btnsync = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  tick_reg = _RAND_2[13:0];
  _RAND_3 = {1{`RANDOM}};
  btnDeb = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  btnClean_reg = _RAND_4[2:0];
  _RAND_5 = {1{`RANDOM}};
  risingEdge_REG = _RAND_5[0:0];
  _RAND_6 = {1{`RANDOM}};
  counter = _RAND_6[7:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
