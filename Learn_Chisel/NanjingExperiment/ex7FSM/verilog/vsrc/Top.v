module PS2Keyboard(
  input        clock,
  input        reset,
  input        io_clrn,
  input        io_ps2_clk,
  input        io_ps2_data,
  input        io_nextdata_n,
  output [7:0] io_data,
  output       io_ready
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
`endif // RANDOMIZE_REG_INIT
  reg [9:0] buffer; // @[Top.scala 92:28]
  reg [7:0] fifo_0; // @[Top.scala 93:28]
  reg [7:0] fifo_1; // @[Top.scala 93:28]
  reg [7:0] fifo_2; // @[Top.scala 93:28]
  reg [7:0] fifo_3; // @[Top.scala 93:28]
  reg [7:0] fifo_4; // @[Top.scala 93:28]
  reg [7:0] fifo_5; // @[Top.scala 93:28]
  reg [7:0] fifo_6; // @[Top.scala 93:28]
  reg [7:0] fifo_7; // @[Top.scala 93:28]
  reg [2:0] w_ptr; // @[Top.scala 94:28]
  reg [2:0] r_ptr; // @[Top.scala 95:28]
  reg [3:0] count; // @[Top.scala 96:28]
  reg  ready; // @[Top.scala 98:28]
  reg [2:0] ps2_clk_sync; // @[Top.scala 99:28]
  wire [2:0] _ps2_clk_sync_T_1 = {ps2_clk_sync[1:0],io_ps2_clk}; // @[Cat.scala 31:58]
  wire  sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1]; // @[Top.scala 102:34]
  wire [2:0] _r_ptr_T_2 = r_ptr + 3'h1; // @[Top.scala 114:46]
  wire [2:0] _r_ptr_T_3 = r_ptr == 3'h7 ? 3'h0 : _r_ptr_T_2; // @[Top.scala 114:19]
  wire  _GEN_1 = ready & ~io_nextdata_n ? ~(w_ptr == _r_ptr_T_3) : ready; // @[Top.scala 113:36 115:13 98:28]
  wire  _valid_T_3 = ~buffer[0] & io_ps2_data; // @[Top.scala 120:39]
  wire  _valid_T_5 = ^buffer[9:1]; // @[Top.scala 122:38]
  wire  valid = _valid_T_3 & _valid_T_5; // @[Top.scala 121:40]
  wire [7:0] _GEN_2 = 3'h0 == w_ptr ? buffer[8:1] : fifo_0; // @[Top.scala 125:{23,23} 93:28]
  wire [7:0] _GEN_3 = 3'h1 == w_ptr ? buffer[8:1] : fifo_1; // @[Top.scala 125:{23,23} 93:28]
  wire [7:0] _GEN_4 = 3'h2 == w_ptr ? buffer[8:1] : fifo_2; // @[Top.scala 125:{23,23} 93:28]
  wire [7:0] _GEN_5 = 3'h3 == w_ptr ? buffer[8:1] : fifo_3; // @[Top.scala 125:{23,23} 93:28]
  wire [7:0] _GEN_6 = 3'h4 == w_ptr ? buffer[8:1] : fifo_4; // @[Top.scala 125:{23,23} 93:28]
  wire [7:0] _GEN_7 = 3'h5 == w_ptr ? buffer[8:1] : fifo_5; // @[Top.scala 125:{23,23} 93:28]
  wire [7:0] _GEN_8 = 3'h6 == w_ptr ? buffer[8:1] : fifo_6; // @[Top.scala 125:{23,23} 93:28]
  wire [7:0] _GEN_9 = 3'h7 == w_ptr ? buffer[8:1] : fifo_7; // @[Top.scala 125:{23,23} 93:28]
  wire [2:0] _w_ptr_T_2 = w_ptr + 3'h1; // @[Top.scala 126:50]
  wire [2:0] _w_ptr_T_3 = w_ptr == 3'h7 ? 3'h0 : _w_ptr_T_2; // @[Top.scala 126:23]
  wire [7:0] _GEN_11 = valid ? _GEN_2 : fifo_0; // @[Top.scala 124:22 93:28]
  wire [7:0] _GEN_12 = valid ? _GEN_3 : fifo_1; // @[Top.scala 124:22 93:28]
  wire [7:0] _GEN_13 = valid ? _GEN_4 : fifo_2; // @[Top.scala 124:22 93:28]
  wire [7:0] _GEN_14 = valid ? _GEN_5 : fifo_3; // @[Top.scala 124:22 93:28]
  wire [7:0] _GEN_15 = valid ? _GEN_6 : fifo_4; // @[Top.scala 124:22 93:28]
  wire [7:0] _GEN_16 = valid ? _GEN_7 : fifo_5; // @[Top.scala 124:22 93:28]
  wire [7:0] _GEN_17 = valid ? _GEN_8 : fifo_6; // @[Top.scala 124:22 93:28]
  wire [7:0] _GEN_18 = valid ? _GEN_9 : fifo_7; // @[Top.scala 124:22 93:28]
  wire [2:0] _GEN_19 = valid ? _w_ptr_T_3 : w_ptr; // @[Top.scala 124:22 126:17 94:28]
  wire  _GEN_20 = valid | _GEN_1; // @[Top.scala 124:22 127:17]
  wire  bufferVec_0 = 4'h0 == count ? io_ps2_data : buffer[0]; // @[Top.scala 136:{26,26} 135:32]
  wire  bufferVec_1 = 4'h1 == count ? io_ps2_data : buffer[1]; // @[Top.scala 136:{26,26} 135:32]
  wire  bufferVec_2 = 4'h2 == count ? io_ps2_data : buffer[2]; // @[Top.scala 136:{26,26} 135:32]
  wire  bufferVec_3 = 4'h3 == count ? io_ps2_data : buffer[3]; // @[Top.scala 136:{26,26} 135:32]
  wire  bufferVec_4 = 4'h4 == count ? io_ps2_data : buffer[4]; // @[Top.scala 136:{26,26} 135:32]
  wire  bufferVec_5 = 4'h5 == count ? io_ps2_data : buffer[5]; // @[Top.scala 136:{26,26} 135:32]
  wire  bufferVec_6 = 4'h6 == count ? io_ps2_data : buffer[6]; // @[Top.scala 136:{26,26} 135:32]
  wire  bufferVec_7 = 4'h7 == count ? io_ps2_data : buffer[7]; // @[Top.scala 136:{26,26} 135:32]
  wire  bufferVec_8 = 4'h8 == count ? io_ps2_data : buffer[8]; // @[Top.scala 136:{26,26} 135:32]
  wire  bufferVec_9 = 4'h9 == count ? io_ps2_data : buffer[9]; // @[Top.scala 136:{26,26} 135:32]
  wire [9:0] _buffer_T = {bufferVec_9,bufferVec_8,bufferVec_7,bufferVec_6,bufferVec_5,bufferVec_4,bufferVec_3,
    bufferVec_2,bufferVec_1,bufferVec_0}; // @[Top.scala 137:29]
  wire [3:0] _count_T_1 = count + 4'h1; // @[Top.scala 138:24]
  wire [7:0] _GEN_73 = 3'h1 == r_ptr ? fifo_1 : fifo_0; // @[Top.scala 143:{15,15}]
  wire [7:0] _GEN_74 = 3'h2 == r_ptr ? fifo_2 : _GEN_73; // @[Top.scala 143:{15,15}]
  wire [7:0] _GEN_75 = 3'h3 == r_ptr ? fifo_3 : _GEN_74; // @[Top.scala 143:{15,15}]
  wire [7:0] _GEN_76 = 3'h4 == r_ptr ? fifo_4 : _GEN_75; // @[Top.scala 143:{15,15}]
  wire [7:0] _GEN_77 = 3'h5 == r_ptr ? fifo_5 : _GEN_76; // @[Top.scala 143:{15,15}]
  wire [7:0] _GEN_78 = 3'h6 == r_ptr ? fifo_6 : _GEN_77; // @[Top.scala 143:{15,15}]
  assign io_data = 3'h7 == r_ptr ? fifo_7 : _GEN_78; // @[Top.scala 143:{15,15}]
  assign io_ready = ready; // @[Top.scala 144:15]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 92:28]
      buffer <= 10'h0; // @[Top.scala 92:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      buffer <= 10'h0; // @[Top.scala 105:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (!(count == 4'ha)) begin // @[Top.scala 119:29]
        buffer <= _buffer_T; // @[Top.scala 137:16]
      end
    end
    if (reset) begin // @[Top.scala 93:28]
      fifo_0 <= 8'h0; // @[Top.scala 93:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      fifo_0 <= 8'h0; // @[Top.scala 106:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (count == 4'ha) begin // @[Top.scala 119:29]
        fifo_0 <= _GEN_11;
      end
    end
    if (reset) begin // @[Top.scala 93:28]
      fifo_1 <= 8'h0; // @[Top.scala 93:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      fifo_1 <= 8'h0; // @[Top.scala 106:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (count == 4'ha) begin // @[Top.scala 119:29]
        fifo_1 <= _GEN_12;
      end
    end
    if (reset) begin // @[Top.scala 93:28]
      fifo_2 <= 8'h0; // @[Top.scala 93:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      fifo_2 <= 8'h0; // @[Top.scala 106:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (count == 4'ha) begin // @[Top.scala 119:29]
        fifo_2 <= _GEN_13;
      end
    end
    if (reset) begin // @[Top.scala 93:28]
      fifo_3 <= 8'h0; // @[Top.scala 93:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      fifo_3 <= 8'h0; // @[Top.scala 106:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (count == 4'ha) begin // @[Top.scala 119:29]
        fifo_3 <= _GEN_14;
      end
    end
    if (reset) begin // @[Top.scala 93:28]
      fifo_4 <= 8'h0; // @[Top.scala 93:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      fifo_4 <= 8'h0; // @[Top.scala 106:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (count == 4'ha) begin // @[Top.scala 119:29]
        fifo_4 <= _GEN_15;
      end
    end
    if (reset) begin // @[Top.scala 93:28]
      fifo_5 <= 8'h0; // @[Top.scala 93:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      fifo_5 <= 8'h0; // @[Top.scala 106:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (count == 4'ha) begin // @[Top.scala 119:29]
        fifo_5 <= _GEN_16;
      end
    end
    if (reset) begin // @[Top.scala 93:28]
      fifo_6 <= 8'h0; // @[Top.scala 93:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      fifo_6 <= 8'h0; // @[Top.scala 106:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (count == 4'ha) begin // @[Top.scala 119:29]
        fifo_6 <= _GEN_17;
      end
    end
    if (reset) begin // @[Top.scala 93:28]
      fifo_7 <= 8'h0; // @[Top.scala 93:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      fifo_7 <= 8'h0; // @[Top.scala 106:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (count == 4'ha) begin // @[Top.scala 119:29]
        fifo_7 <= _GEN_18;
      end
    end
    if (reset) begin // @[Top.scala 94:28]
      w_ptr <= 3'h0; // @[Top.scala 94:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      w_ptr <= 3'h0; // @[Top.scala 107:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (count == 4'ha) begin // @[Top.scala 119:29]
        w_ptr <= _GEN_19;
      end
    end
    if (reset) begin // @[Top.scala 95:28]
      r_ptr <= 3'h0; // @[Top.scala 95:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      r_ptr <= 3'h0; // @[Top.scala 108:15]
    end else if (ready & ~io_nextdata_n) begin // @[Top.scala 113:36]
      if (r_ptr == 3'h7) begin // @[Top.scala 114:19]
        r_ptr <= 3'h0;
      end else begin
        r_ptr <= _r_ptr_T_2;
      end
    end
    if (reset) begin // @[Top.scala 96:28]
      count <= 4'h0; // @[Top.scala 96:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      count <= 4'h0; // @[Top.scala 109:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (count == 4'ha) begin // @[Top.scala 119:29]
        count <= 4'h0; // @[Top.scala 133:15]
      end else begin
        count <= _count_T_1; // @[Top.scala 138:15]
      end
    end
    if (reset) begin // @[Top.scala 98:28]
      ready <= 1'h0; // @[Top.scala 98:28]
    end else if (~io_clrn) begin // @[Top.scala 104:19]
      ready <= 1'h0; // @[Top.scala 110:15]
    end else if (sampling) begin // @[Top.scala 118:21]
      if (count == 4'ha) begin // @[Top.scala 119:29]
        ready <= _GEN_20;
      end else begin
        ready <= _GEN_1;
      end
    end else begin
      ready <= _GEN_1;
    end
    if (reset) begin // @[Top.scala 99:28]
      ps2_clk_sync <= 3'h0; // @[Top.scala 99:28]
    end else begin
      ps2_clk_sync <= _ps2_clk_sync_T_1; // @[Top.scala 101:16]
    end
  end
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
  buffer = _RAND_0[9:0];
  _RAND_1 = {1{`RANDOM}};
  fifo_0 = _RAND_1[7:0];
  _RAND_2 = {1{`RANDOM}};
  fifo_1 = _RAND_2[7:0];
  _RAND_3 = {1{`RANDOM}};
  fifo_2 = _RAND_3[7:0];
  _RAND_4 = {1{`RANDOM}};
  fifo_3 = _RAND_4[7:0];
  _RAND_5 = {1{`RANDOM}};
  fifo_4 = _RAND_5[7:0];
  _RAND_6 = {1{`RANDOM}};
  fifo_5 = _RAND_6[7:0];
  _RAND_7 = {1{`RANDOM}};
  fifo_6 = _RAND_7[7:0];
  _RAND_8 = {1{`RANDOM}};
  fifo_7 = _RAND_8[7:0];
  _RAND_9 = {1{`RANDOM}};
  w_ptr = _RAND_9[2:0];
  _RAND_10 = {1{`RANDOM}};
  r_ptr = _RAND_10[2:0];
  _RAND_11 = {1{`RANDOM}};
  count = _RAND_11[3:0];
  _RAND_12 = {1{`RANDOM}};
  ready = _RAND_12[0:0];
  _RAND_13 = {1{`RANDOM}};
  ps2_clk_sync = _RAND_13[2:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Ps2_decoder(
  input        clock,
  input        reset,
  input  [7:0] io_keycode,
  input        io_clrn,
  output [7:0] io_ascii,
  output       io_pressed
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg  isBreakCode; // @[Top.scala 156:30]
  wire [6:0] _GEN_0 = 8'h14 == io_keycode ? 7'h5a : 7'h0; // @[Top.scala 160:14 178:36 215:43]
  wire [6:0] _GEN_1 = 8'h22 == io_keycode ? 7'h59 : _GEN_0; // @[Top.scala 178:36 214:43]
  wire [6:0] _GEN_2 = 8'h1a == io_keycode ? 7'h58 : _GEN_1; // @[Top.scala 178:36 213:43]
  wire [6:0] _GEN_3 = 8'h1d == io_keycode ? 7'h57 : _GEN_2; // @[Top.scala 178:36 212:43]
  wire [6:0] _GEN_4 = 8'h2a == io_keycode ? 7'h56 : _GEN_3; // @[Top.scala 178:36 211:43]
  wire [6:0] _GEN_5 = 8'h3c == io_keycode ? 7'h55 : _GEN_4; // @[Top.scala 178:36 210:43]
  wire [6:0] _GEN_6 = 8'h2c == io_keycode ? 7'h54 : _GEN_5; // @[Top.scala 178:36 209:43]
  wire [6:0] _GEN_7 = 8'h1b == io_keycode ? 7'h53 : _GEN_6; // @[Top.scala 178:36 208:43]
  wire [6:0] _GEN_8 = 8'h2d == io_keycode ? 7'h52 : _GEN_7; // @[Top.scala 178:36 207:43]
  wire [6:0] _GEN_9 = 8'h15 == io_keycode ? 7'h51 : _GEN_8; // @[Top.scala 178:36 206:43]
  wire [6:0] _GEN_10 = 8'h4d == io_keycode ? 7'h50 : _GEN_9; // @[Top.scala 178:36 205:43]
  wire [6:0] _GEN_11 = 8'h44 == io_keycode ? 7'h4f : _GEN_10; // @[Top.scala 178:36 204:43]
  wire [6:0] _GEN_12 = 8'h31 == io_keycode ? 7'h4e : _GEN_11; // @[Top.scala 178:36 203:43]
  wire [6:0] _GEN_13 = 8'h3a == io_keycode ? 7'h4d : _GEN_12; // @[Top.scala 178:36 202:43]
  wire [6:0] _GEN_14 = 8'h4b == io_keycode ? 7'h4c : _GEN_13; // @[Top.scala 178:36 201:43]
  wire [6:0] _GEN_15 = 8'h42 == io_keycode ? 7'h4b : _GEN_14; // @[Top.scala 178:36 200:43]
  wire [6:0] _GEN_16 = 8'h3b == io_keycode ? 7'h4a : _GEN_15; // @[Top.scala 178:36 199:43]
  wire [6:0] _GEN_17 = 8'h43 == io_keycode ? 7'h49 : _GEN_16; // @[Top.scala 178:36 198:43]
  wire [6:0] _GEN_18 = 8'h33 == io_keycode ? 7'h48 : _GEN_17; // @[Top.scala 178:36 197:43]
  wire [6:0] _GEN_19 = 8'h34 == io_keycode ? 7'h47 : _GEN_18; // @[Top.scala 178:36 196:43]
  wire [6:0] _GEN_20 = 8'h2b == io_keycode ? 7'h46 : _GEN_19; // @[Top.scala 178:36 195:43]
  wire [6:0] _GEN_21 = 8'h24 == io_keycode ? 7'h45 : _GEN_20; // @[Top.scala 178:36 194:43]
  wire [6:0] _GEN_22 = 8'h23 == io_keycode ? 7'h44 : _GEN_21; // @[Top.scala 178:36 193:43]
  wire [6:0] _GEN_23 = 8'h21 == io_keycode ? 7'h43 : _GEN_22; // @[Top.scala 178:36 192:43]
  wire [6:0] _GEN_24 = 8'h32 == io_keycode ? 7'h42 : _GEN_23; // @[Top.scala 178:36 191:43]
  wire [6:0] _GEN_25 = 8'h1c == io_keycode ? 7'h41 : _GEN_24; // @[Top.scala 178:36 190:43]
  wire [6:0] _GEN_26 = 8'h46 == io_keycode ? 7'h39 : _GEN_25; // @[Top.scala 178:36 188:43]
  wire [6:0] _GEN_27 = 8'h3e == io_keycode ? 7'h38 : _GEN_26; // @[Top.scala 178:36 187:43]
  wire [6:0] _GEN_28 = 8'h3d == io_keycode ? 7'h37 : _GEN_27; // @[Top.scala 178:36 186:43]
  wire [6:0] _GEN_29 = 8'h36 == io_keycode ? 7'h36 : _GEN_28; // @[Top.scala 178:36 185:43]
  wire [6:0] _GEN_30 = 8'h2e == io_keycode ? 7'h35 : _GEN_29; // @[Top.scala 178:36 184:43]
  wire [6:0] _GEN_31 = 8'h25 == io_keycode ? 7'h34 : _GEN_30; // @[Top.scala 178:36 183:43]
  wire [6:0] _GEN_32 = 8'h26 == io_keycode ? 7'h33 : _GEN_31; // @[Top.scala 178:36 182:43]
  wire [6:0] _GEN_33 = 8'h1e == io_keycode ? 7'h32 : _GEN_32; // @[Top.scala 178:36 181:43]
  wire [6:0] _GEN_34 = 8'h16 == io_keycode ? 7'h31 : _GEN_33; // @[Top.scala 178:36 180:43]
  wire [6:0] _GEN_35 = 8'h45 == io_keycode ? 7'h30 : _GEN_34; // @[Top.scala 178:36 179:43]
  wire  _GEN_36 = isBreakCode ? 1'h0 : isBreakCode; // @[Top.scala 171:31 172:29 156:30]
  wire  _GEN_37 = isBreakCode ? 1'h0 : 1'h1; // @[Top.scala 171:31 173:28 176:28]
  wire [6:0] _GEN_39 = isBreakCode ? 7'h0 : _GEN_35; // @[Top.scala 160:14 171:31]
  wire  _GEN_40 = io_keycode == 8'hf0 | _GEN_36; // @[Top.scala 168:37 169:25]
  wire  _GEN_41 = io_keycode == 8'hf0 ? 1'h0 : _GEN_37; // @[Top.scala 159:16 168:37]
  wire [6:0] _GEN_43 = io_keycode == 8'hf0 ? 7'h0 : _GEN_39; // @[Top.scala 160:14 168:37]
  wire [6:0] _GEN_46 = ~io_clrn ? 7'h0 : _GEN_43; // @[Top.scala 162:20 165:18]
  assign io_ascii = {{1'd0}, _GEN_46};
  assign io_pressed = ~io_clrn ? 1'h0 : _GEN_41; // @[Top.scala 162:20 166:20]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 156:30]
      isBreakCode <= 1'h0; // @[Top.scala 156:30]
    end else if (~io_clrn) begin // @[Top.scala 162:20]
      isBreakCode <= 1'h0; // @[Top.scala 163:21]
    end else begin
      isBreakCode <= _GEN_40;
    end
  end
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
  isBreakCode = _RAND_0[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Seg(
  input  [3:0] io_in,
  output [7:0] io_seg
);
  wire [7:0] _GEN_1 = 4'he == io_in ? 8'h61 : 8'hff; // @[Top.scala 247:17 262:23]
  wire [7:0] _GEN_2 = 4'hd == io_in ? 8'h85 : _GEN_1; // @[Top.scala 247:17 261:23]
  wire [7:0] _GEN_3 = 4'hc == io_in ? 8'h63 : _GEN_2; // @[Top.scala 247:17 260:23]
  wire [7:0] _GEN_4 = 4'hb == io_in ? 8'hc1 : _GEN_3; // @[Top.scala 247:17 259:23]
  wire [7:0] _GEN_5 = 4'ha == io_in ? 8'h11 : _GEN_4; // @[Top.scala 247:17 258:23]
  wire [7:0] _GEN_6 = 4'h9 == io_in ? 8'h9 : _GEN_5; // @[Top.scala 247:17 257:23]
  wire [7:0] _GEN_7 = 4'h8 == io_in ? 8'h1 : _GEN_6; // @[Top.scala 247:17 256:23]
  wire [7:0] _GEN_8 = 4'h7 == io_in ? 8'h1f : _GEN_7; // @[Top.scala 247:17 255:23]
  wire [7:0] _GEN_9 = 4'h6 == io_in ? 8'h41 : _GEN_8; // @[Top.scala 247:17 254:23]
  wire [7:0] _GEN_10 = 4'h5 == io_in ? 8'h49 : _GEN_9; // @[Top.scala 247:17 253:23]
  wire [7:0] _GEN_11 = 4'h4 == io_in ? 8'h99 : _GEN_10; // @[Top.scala 247:17 252:23]
  wire [7:0] _GEN_12 = 4'h3 == io_in ? 8'hd : _GEN_11; // @[Top.scala 247:17 251:23]
  wire [7:0] _GEN_13 = 4'h2 == io_in ? 8'h25 : _GEN_12; // @[Top.scala 247:17 250:23]
  wire [7:0] _GEN_14 = 4'h1 == io_in ? 8'h9f : _GEN_13; // @[Top.scala 247:17 249:23]
  assign io_seg = 4'h0 == io_in ? 8'h3 : _GEN_14; // @[Top.scala 247:17 248:23]
endmodule
module Keycount(
  input        clock,
  input        reset,
  input        io_key_press,
  input        io_clrn,
  output [3:0] io_ones,
  output [3:0] io_tens
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  reg [3:0] ones; // @[Top.scala 275:23]
  reg [3:0] tens; // @[Top.scala 276:23]
  reg [2:0] debounce_count; // @[Top.scala 282:33]
  reg  stable_key_press; // @[Top.scala 283:35]
  wire [2:0] _debounce_count_T_1 = debounce_count + 3'h1; // @[Top.scala 289:42]
  reg  stable_key_rise_REG; // @[Top.scala 298:55]
  wire  stable_key_rise = stable_key_press & ~stable_key_rise_REG; // @[Top.scala 298:44]
  wire [3:0] _tens_T_2 = tens + 4'h1; // @[Top.scala 307:49]
  wire [3:0] _tens_T_3 = tens == 4'h9 ? 4'h0 : _tens_T_2; // @[Top.scala 307:24]
  wire [3:0] _ones_T_1 = ones + 4'h1; // @[Top.scala 309:26]
  assign io_ones = ones; // @[Top.scala 313:13]
  assign io_tens = tens; // @[Top.scala 314:13]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 275:23]
      ones <= 4'h0; // @[Top.scala 275:23]
    end else if (~io_clrn) begin // @[Top.scala 300:20]
      ones <= 4'h0; // @[Top.scala 301:14]
    end else if (stable_key_rise) begin // @[Top.scala 303:34]
      if (ones == 4'h9) begin // @[Top.scala 305:28]
        ones <= 4'h0; // @[Top.scala 306:18]
      end else begin
        ones <= _ones_T_1; // @[Top.scala 309:18]
      end
    end
    if (reset) begin // @[Top.scala 276:23]
      tens <= 4'h0; // @[Top.scala 276:23]
    end else if (~io_clrn) begin // @[Top.scala 300:20]
      tens <= 4'h0; // @[Top.scala 302:14]
    end else if (stable_key_rise) begin // @[Top.scala 303:34]
      if (ones == 4'h9) begin // @[Top.scala 305:28]
        tens <= _tens_T_3; // @[Top.scala 307:18]
      end
    end
    if (reset) begin // @[Top.scala 282:33]
      debounce_count <= 3'h0; // @[Top.scala 282:33]
    end else if (io_key_press == stable_key_press) begin // @[Top.scala 286:45]
      debounce_count <= 3'h0; // @[Top.scala 287:24]
    end else begin
      debounce_count <= _debounce_count_T_1; // @[Top.scala 289:24]
    end
    if (reset) begin // @[Top.scala 283:35]
      stable_key_press <= 1'h0; // @[Top.scala 283:35]
    end else if (debounce_count == 3'h7) begin // @[Top.scala 293:34]
      stable_key_press <= io_key_press; // @[Top.scala 294:26]
    end
    stable_key_rise_REG <= stable_key_press; // @[Top.scala 298:55]
  end
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
  ones = _RAND_0[3:0];
  _RAND_1 = {1{`RANDOM}};
  tens = _RAND_1[3:0];
  _RAND_2 = {1{`RANDOM}};
  debounce_count = _RAND_2[2:0];
  _RAND_3 = {1{`RANDOM}};
  stable_key_press = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  stable_key_rise_REG = _RAND_4[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Top(
  input        clock,
  input        reset,
  input        io_clrn,
  input        io_ps2_clk,
  input        io_ps2_data,
  output [7:0] io_seg_out_0,
  output [7:0] io_seg_out_1,
  output [7:0] io_seg_out_2,
  output [7:0] io_seg_out_3,
  output [7:0] io_seg_out_4,
  output [7:0] io_seg_out_5
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire  keyboard_clock; // @[Top.scala 18:26]
  wire  keyboard_reset; // @[Top.scala 18:26]
  wire  keyboard_io_clrn; // @[Top.scala 18:26]
  wire  keyboard_io_ps2_clk; // @[Top.scala 18:26]
  wire  keyboard_io_ps2_data; // @[Top.scala 18:26]
  wire  keyboard_io_nextdata_n; // @[Top.scala 18:26]
  wire [7:0] keyboard_io_data; // @[Top.scala 18:26]
  wire  keyboard_io_ready; // @[Top.scala 18:26]
  wire  decoder_clock; // @[Top.scala 24:25]
  wire  decoder_reset; // @[Top.scala 24:25]
  wire [7:0] decoder_io_keycode; // @[Top.scala 24:25]
  wire  decoder_io_clrn; // @[Top.scala 24:25]
  wire [7:0] decoder_io_ascii; // @[Top.scala 24:25]
  wire  decoder_io_pressed; // @[Top.scala 24:25]
  wire [3:0] seg0_io_in; // @[Top.scala 29:22]
  wire [7:0] seg0_io_seg; // @[Top.scala 29:22]
  wire [3:0] seg1_io_in; // @[Top.scala 30:22]
  wire [7:0] seg1_io_seg; // @[Top.scala 30:22]
  wire [3:0] seg2_io_in; // @[Top.scala 31:22]
  wire [7:0] seg2_io_seg; // @[Top.scala 31:22]
  wire [3:0] seg3_io_in; // @[Top.scala 32:22]
  wire [7:0] seg3_io_seg; // @[Top.scala 32:22]
  wire [3:0] seg4_io_in; // @[Top.scala 33:22]
  wire [7:0] seg4_io_seg; // @[Top.scala 33:22]
  wire [3:0] seg5_io_in; // @[Top.scala 34:22]
  wire [7:0] seg5_io_seg; // @[Top.scala 34:22]
  wire  counter_clock; // @[Top.scala 37:25]
  wire  counter_reset; // @[Top.scala 37:25]
  wire  counter_io_key_press; // @[Top.scala 37:25]
  wire  counter_io_clrn; // @[Top.scala 37:25]
  wire [3:0] counter_io_ones; // @[Top.scala 37:25]
  wire [3:0] counter_io_tens; // @[Top.scala 37:25]
  reg  nextdata_n; // @[Top.scala 42:29]
  reg  ready_delay; // @[Top.scala 45:30]
  wire  _GEN_0 = keyboard_io_ready & ~ready_delay ? 1'h0 : 1'h1; // @[Top.scala 46:45 47:20 49:20]
  PS2Keyboard keyboard ( // @[Top.scala 18:26]
    .clock(keyboard_clock),
    .reset(keyboard_reset),
    .io_clrn(keyboard_io_clrn),
    .io_ps2_clk(keyboard_io_ps2_clk),
    .io_ps2_data(keyboard_io_ps2_data),
    .io_nextdata_n(keyboard_io_nextdata_n),
    .io_data(keyboard_io_data),
    .io_ready(keyboard_io_ready)
  );
  Ps2_decoder decoder ( // @[Top.scala 24:25]
    .clock(decoder_clock),
    .reset(decoder_reset),
    .io_keycode(decoder_io_keycode),
    .io_clrn(decoder_io_clrn),
    .io_ascii(decoder_io_ascii),
    .io_pressed(decoder_io_pressed)
  );
  Seg seg0 ( // @[Top.scala 29:22]
    .io_in(seg0_io_in),
    .io_seg(seg0_io_seg)
  );
  Seg seg1 ( // @[Top.scala 30:22]
    .io_in(seg1_io_in),
    .io_seg(seg1_io_seg)
  );
  Seg seg2 ( // @[Top.scala 31:22]
    .io_in(seg2_io_in),
    .io_seg(seg2_io_seg)
  );
  Seg seg3 ( // @[Top.scala 32:22]
    .io_in(seg3_io_in),
    .io_seg(seg3_io_seg)
  );
  Seg seg4 ( // @[Top.scala 33:22]
    .io_in(seg4_io_in),
    .io_seg(seg4_io_seg)
  );
  Seg seg5 ( // @[Top.scala 34:22]
    .io_in(seg5_io_in),
    .io_seg(seg5_io_seg)
  );
  Keycount counter ( // @[Top.scala 37:25]
    .clock(counter_clock),
    .reset(counter_reset),
    .io_key_press(counter_io_key_press),
    .io_clrn(counter_io_clrn),
    .io_ones(counter_io_ones),
    .io_tens(counter_io_tens)
  );
  assign io_seg_out_0 = seg0_io_seg; // @[Top.scala 73:18]
  assign io_seg_out_1 = seg1_io_seg; // @[Top.scala 74:18]
  assign io_seg_out_2 = seg2_io_seg; // @[Top.scala 75:18]
  assign io_seg_out_3 = seg3_io_seg; // @[Top.scala 76:18]
  assign io_seg_out_4 = seg4_io_seg; // @[Top.scala 77:18]
  assign io_seg_out_5 = seg5_io_seg; // @[Top.scala 78:18]
  assign keyboard_clock = clock;
  assign keyboard_reset = reset;
  assign keyboard_io_clrn = io_clrn; // @[Top.scala 19:26]
  assign keyboard_io_ps2_clk = io_ps2_clk; // @[Top.scala 20:26]
  assign keyboard_io_ps2_data = io_ps2_data; // @[Top.scala 21:26]
  assign keyboard_io_nextdata_n = nextdata_n; // @[Top.scala 43:28]
  assign decoder_clock = clock;
  assign decoder_reset = reset;
  assign decoder_io_keycode = keyboard_io_data; // @[Top.scala 25:26]
  assign decoder_io_clrn = io_clrn; // @[Top.scala 26:26]
  assign seg0_io_in = ~decoder_io_pressed ? 4'hf : keyboard_io_data[3:0]; // @[Top.scala 53:31 54:20 60:20]
  assign seg1_io_in = ~decoder_io_pressed ? 4'hf : keyboard_io_data[7:4]; // @[Top.scala 53:31 55:20 61:20]
  assign seg2_io_in = ~decoder_io_pressed ? 4'hf : decoder_io_ascii[3:0]; // @[Top.scala 53:31 56:20 64:20]
  assign seg3_io_in = ~decoder_io_pressed ? 4'hf : decoder_io_ascii[7:4]; // @[Top.scala 53:31 57:20 65:20]
  assign seg4_io_in = counter_io_ones; // @[Top.scala 69:16]
  assign seg5_io_in = counter_io_tens; // @[Top.scala 70:16]
  assign counter_clock = clock;
  assign counter_reset = reset;
  assign counter_io_key_press = decoder_io_pressed; // @[Top.scala 38:26]
  assign counter_io_clrn = io_clrn; // @[Top.scala 39:21]
  always @(posedge clock) begin
    nextdata_n <= reset | _GEN_0; // @[Top.scala 42:{29,29}]
    if (reset) begin // @[Top.scala 45:30]
      ready_delay <= 1'h0; // @[Top.scala 45:30]
    end else begin
      ready_delay <= keyboard_io_ready; // @[Top.scala 45:30]
    end
  end
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
  nextdata_n = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  ready_delay = _RAND_1[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
