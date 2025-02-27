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
  reg [9:0] buffer; // @[Top.scala 140:28]
  reg [7:0] fifo_0; // @[Top.scala 141:28]
  reg [7:0] fifo_1; // @[Top.scala 141:28]
  reg [7:0] fifo_2; // @[Top.scala 141:28]
  reg [7:0] fifo_3; // @[Top.scala 141:28]
  reg [7:0] fifo_4; // @[Top.scala 141:28]
  reg [7:0] fifo_5; // @[Top.scala 141:28]
  reg [7:0] fifo_6; // @[Top.scala 141:28]
  reg [7:0] fifo_7; // @[Top.scala 141:28]
  reg [2:0] w_ptr; // @[Top.scala 142:28]
  reg [2:0] r_ptr; // @[Top.scala 143:28]
  reg [3:0] count; // @[Top.scala 144:28]
  reg  ready; // @[Top.scala 146:28]
  reg [2:0] ps2_clk_sync; // @[Top.scala 147:28]
  wire [2:0] _ps2_clk_sync_T_1 = {ps2_clk_sync[1:0],io_ps2_clk}; // @[Cat.scala 31:58]
  wire  sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1]; // @[Top.scala 151:34]
  wire [2:0] _r_ptr_T_1 = r_ptr + 3'h1; // @[Top.scala 167:22]
  wire  _GEN_1 = ready & ~io_nextdata_n ? ~(w_ptr == _r_ptr_T_1) : ready; // @[Top.scala 166:36 168:13 146:28]
  wire  _valid_T_3 = ~buffer[0] & io_ps2_data; // @[Top.scala 176:39]
  wire  _valid_T_5 = ^buffer[9:1]; // @[Top.scala 178:38]
  wire  valid = _valid_T_3 & _valid_T_5; // @[Top.scala 177:40]
  wire [7:0] _GEN_2 = 3'h0 == w_ptr ? buffer[8:1] : fifo_0; // @[Top.scala 181:{23,23} 141:28]
  wire [7:0] _GEN_3 = 3'h1 == w_ptr ? buffer[8:1] : fifo_1; // @[Top.scala 181:{23,23} 141:28]
  wire [7:0] _GEN_4 = 3'h2 == w_ptr ? buffer[8:1] : fifo_2; // @[Top.scala 181:{23,23} 141:28]
  wire [7:0] _GEN_5 = 3'h3 == w_ptr ? buffer[8:1] : fifo_3; // @[Top.scala 181:{23,23} 141:28]
  wire [7:0] _GEN_6 = 3'h4 == w_ptr ? buffer[8:1] : fifo_4; // @[Top.scala 181:{23,23} 141:28]
  wire [7:0] _GEN_7 = 3'h5 == w_ptr ? buffer[8:1] : fifo_5; // @[Top.scala 181:{23,23} 141:28]
  wire [7:0] _GEN_8 = 3'h6 == w_ptr ? buffer[8:1] : fifo_6; // @[Top.scala 181:{23,23} 141:28]
  wire [7:0] _GEN_9 = 3'h7 == w_ptr ? buffer[8:1] : fifo_7; // @[Top.scala 181:{23,23} 141:28]
  wire [2:0] _w_ptr_T_1 = w_ptr + 3'h1; // @[Top.scala 182:26]
  wire [7:0] _GEN_10 = valid ? _GEN_2 : fifo_0; // @[Top.scala 180:22 141:28]
  wire [7:0] _GEN_11 = valid ? _GEN_3 : fifo_1; // @[Top.scala 180:22 141:28]
  wire [7:0] _GEN_12 = valid ? _GEN_4 : fifo_2; // @[Top.scala 180:22 141:28]
  wire [7:0] _GEN_13 = valid ? _GEN_5 : fifo_3; // @[Top.scala 180:22 141:28]
  wire [7:0] _GEN_14 = valid ? _GEN_6 : fifo_4; // @[Top.scala 180:22 141:28]
  wire [7:0] _GEN_15 = valid ? _GEN_7 : fifo_5; // @[Top.scala 180:22 141:28]
  wire [7:0] _GEN_16 = valid ? _GEN_8 : fifo_6; // @[Top.scala 180:22 141:28]
  wire [7:0] _GEN_17 = valid ? _GEN_9 : fifo_7; // @[Top.scala 180:22 141:28]
  wire [2:0] _GEN_18 = valid ? _w_ptr_T_1 : w_ptr; // @[Top.scala 180:22 182:17 142:28]
  wire  _GEN_19 = valid | _GEN_1; // @[Top.scala 180:22 183:17]
  wire  bufferVec_0 = 4'h0 == count ? io_ps2_data : buffer[0]; // @[Top.scala 190:{26,26} 189:32]
  wire  bufferVec_1 = 4'h1 == count ? io_ps2_data : buffer[1]; // @[Top.scala 190:{26,26} 189:32]
  wire  bufferVec_2 = 4'h2 == count ? io_ps2_data : buffer[2]; // @[Top.scala 190:{26,26} 189:32]
  wire  bufferVec_3 = 4'h3 == count ? io_ps2_data : buffer[3]; // @[Top.scala 190:{26,26} 189:32]
  wire  bufferVec_4 = 4'h4 == count ? io_ps2_data : buffer[4]; // @[Top.scala 190:{26,26} 189:32]
  wire  bufferVec_5 = 4'h5 == count ? io_ps2_data : buffer[5]; // @[Top.scala 190:{26,26} 189:32]
  wire  bufferVec_6 = 4'h6 == count ? io_ps2_data : buffer[6]; // @[Top.scala 190:{26,26} 189:32]
  wire  bufferVec_7 = 4'h7 == count ? io_ps2_data : buffer[7]; // @[Top.scala 190:{26,26} 189:32]
  wire  bufferVec_8 = 4'h8 == count ? io_ps2_data : buffer[8]; // @[Top.scala 190:{26,26} 189:32]
  wire  bufferVec_9 = 4'h9 == count ? io_ps2_data : buffer[9]; // @[Top.scala 190:{26,26} 189:32]
  wire [9:0] _buffer_T = {bufferVec_9,bufferVec_8,bufferVec_7,bufferVec_6,bufferVec_5,bufferVec_4,bufferVec_3,
    bufferVec_2,bufferVec_1,bufferVec_0}; // @[Top.scala 191:29]
  wire [3:0] _count_T_1 = count + 4'h1; // @[Top.scala 192:24]
  wire [7:0] _GEN_72 = 3'h1 == r_ptr ? fifo_1 : fifo_0; // @[Top.scala 197:{15,15}]
  wire [7:0] _GEN_73 = 3'h2 == r_ptr ? fifo_2 : _GEN_72; // @[Top.scala 197:{15,15}]
  wire [7:0] _GEN_74 = 3'h3 == r_ptr ? fifo_3 : _GEN_73; // @[Top.scala 197:{15,15}]
  wire [7:0] _GEN_75 = 3'h4 == r_ptr ? fifo_4 : _GEN_74; // @[Top.scala 197:{15,15}]
  wire [7:0] _GEN_76 = 3'h5 == r_ptr ? fifo_5 : _GEN_75; // @[Top.scala 197:{15,15}]
  wire [7:0] _GEN_77 = 3'h6 == r_ptr ? fifo_6 : _GEN_76; // @[Top.scala 197:{15,15}]
  assign io_data = 3'h7 == r_ptr ? fifo_7 : _GEN_77; // @[Top.scala 197:{15,15}]
  assign io_ready = ready; // @[Top.scala 198:15]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 140:28]
      buffer <= 10'h0; // @[Top.scala 140:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      buffer <= 10'h0; // @[Top.scala 156:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (!(count == 4'ha)) begin // @[Top.scala 174:29]
        buffer <= _buffer_T; // @[Top.scala 191:16]
      end
    end
    if (reset) begin // @[Top.scala 141:28]
      fifo_0 <= 8'h0; // @[Top.scala 141:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      fifo_0 <= 8'h0; // @[Top.scala 157:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (count == 4'ha) begin // @[Top.scala 174:29]
        fifo_0 <= _GEN_10;
      end
    end
    if (reset) begin // @[Top.scala 141:28]
      fifo_1 <= 8'h0; // @[Top.scala 141:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      fifo_1 <= 8'h0; // @[Top.scala 157:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (count == 4'ha) begin // @[Top.scala 174:29]
        fifo_1 <= _GEN_11;
      end
    end
    if (reset) begin // @[Top.scala 141:28]
      fifo_2 <= 8'h0; // @[Top.scala 141:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      fifo_2 <= 8'h0; // @[Top.scala 157:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (count == 4'ha) begin // @[Top.scala 174:29]
        fifo_2 <= _GEN_12;
      end
    end
    if (reset) begin // @[Top.scala 141:28]
      fifo_3 <= 8'h0; // @[Top.scala 141:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      fifo_3 <= 8'h0; // @[Top.scala 157:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (count == 4'ha) begin // @[Top.scala 174:29]
        fifo_3 <= _GEN_13;
      end
    end
    if (reset) begin // @[Top.scala 141:28]
      fifo_4 <= 8'h0; // @[Top.scala 141:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      fifo_4 <= 8'h0; // @[Top.scala 157:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (count == 4'ha) begin // @[Top.scala 174:29]
        fifo_4 <= _GEN_14;
      end
    end
    if (reset) begin // @[Top.scala 141:28]
      fifo_5 <= 8'h0; // @[Top.scala 141:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      fifo_5 <= 8'h0; // @[Top.scala 157:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (count == 4'ha) begin // @[Top.scala 174:29]
        fifo_5 <= _GEN_15;
      end
    end
    if (reset) begin // @[Top.scala 141:28]
      fifo_6 <= 8'h0; // @[Top.scala 141:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      fifo_6 <= 8'h0; // @[Top.scala 157:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (count == 4'ha) begin // @[Top.scala 174:29]
        fifo_6 <= _GEN_16;
      end
    end
    if (reset) begin // @[Top.scala 141:28]
      fifo_7 <= 8'h0; // @[Top.scala 141:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      fifo_7 <= 8'h0; // @[Top.scala 157:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (count == 4'ha) begin // @[Top.scala 174:29]
        fifo_7 <= _GEN_17;
      end
    end
    if (reset) begin // @[Top.scala 142:28]
      w_ptr <= 3'h0; // @[Top.scala 142:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      w_ptr <= 3'h0; // @[Top.scala 158:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (count == 4'ha) begin // @[Top.scala 174:29]
        w_ptr <= _GEN_18;
      end
    end
    if (reset) begin // @[Top.scala 143:28]
      r_ptr <= 3'h0; // @[Top.scala 143:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      r_ptr <= 3'h0; // @[Top.scala 159:15]
    end else if (ready & ~io_nextdata_n) begin // @[Top.scala 166:36]
      r_ptr <= _r_ptr_T_1; // @[Top.scala 167:13]
    end
    if (reset) begin // @[Top.scala 144:28]
      count <= 4'h0; // @[Top.scala 144:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      count <= 4'h0; // @[Top.scala 160:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (count == 4'ha) begin // @[Top.scala 174:29]
        count <= 4'h0; // @[Top.scala 186:15]
      end else begin
        count <= _count_T_1; // @[Top.scala 192:15]
      end
    end
    if (reset) begin // @[Top.scala 146:28]
      ready <= 1'h0; // @[Top.scala 146:28]
    end else if (~io_clrn) begin // @[Top.scala 154:19]
      ready <= 1'h0; // @[Top.scala 161:15]
    end else if (sampling) begin // @[Top.scala 173:21]
      if (count == 4'ha) begin // @[Top.scala 174:29]
        ready <= _GEN_19;
      end else begin
        ready <= _GEN_1;
      end
    end else begin
      ready <= _GEN_1;
    end
    if (reset) begin // @[Top.scala 147:28]
      ps2_clk_sync <= 3'h0; // @[Top.scala 147:28]
    end else begin
      ps2_clk_sync <= _ps2_clk_sync_T_1; // @[Top.scala 150:16]
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
  output       io_released
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg  isBreakCode; // @[Top.scala 211:30]
  wire [6:0] _GEN_0 = 8'h14 == io_keycode ? 7'h5a : 7'h0; // @[Top.scala 229:26 232:36 269:43]
  wire [6:0] _GEN_1 = 8'h22 == io_keycode ? 7'h59 : _GEN_0; // @[Top.scala 232:36 268:43]
  wire [6:0] _GEN_2 = 8'h1a == io_keycode ? 7'h58 : _GEN_1; // @[Top.scala 232:36 267:43]
  wire [6:0] _GEN_3 = 8'h1d == io_keycode ? 7'h57 : _GEN_2; // @[Top.scala 232:36 266:43]
  wire [6:0] _GEN_4 = 8'h2a == io_keycode ? 7'h56 : _GEN_3; // @[Top.scala 232:36 265:43]
  wire [6:0] _GEN_5 = 8'h3c == io_keycode ? 7'h55 : _GEN_4; // @[Top.scala 232:36 264:43]
  wire [6:0] _GEN_6 = 8'h2c == io_keycode ? 7'h54 : _GEN_5; // @[Top.scala 232:36 263:43]
  wire [6:0] _GEN_7 = 8'h1b == io_keycode ? 7'h53 : _GEN_6; // @[Top.scala 232:36 262:43]
  wire [6:0] _GEN_8 = 8'h2d == io_keycode ? 7'h52 : _GEN_7; // @[Top.scala 232:36 261:43]
  wire [6:0] _GEN_9 = 8'h15 == io_keycode ? 7'h51 : _GEN_8; // @[Top.scala 232:36 260:43]
  wire [6:0] _GEN_10 = 8'h4d == io_keycode ? 7'h50 : _GEN_9; // @[Top.scala 232:36 259:43]
  wire [6:0] _GEN_11 = 8'h44 == io_keycode ? 7'h4f : _GEN_10; // @[Top.scala 232:36 258:43]
  wire [6:0] _GEN_12 = 8'h31 == io_keycode ? 7'h4e : _GEN_11; // @[Top.scala 232:36 257:43]
  wire [6:0] _GEN_13 = 8'h3a == io_keycode ? 7'h4d : _GEN_12; // @[Top.scala 232:36 256:43]
  wire [6:0] _GEN_14 = 8'h4b == io_keycode ? 7'h4c : _GEN_13; // @[Top.scala 232:36 255:43]
  wire [6:0] _GEN_15 = 8'h42 == io_keycode ? 7'h4b : _GEN_14; // @[Top.scala 232:36 254:43]
  wire [6:0] _GEN_16 = 8'h3b == io_keycode ? 7'h4a : _GEN_15; // @[Top.scala 232:36 253:43]
  wire [6:0] _GEN_17 = 8'h43 == io_keycode ? 7'h49 : _GEN_16; // @[Top.scala 232:36 252:43]
  wire [6:0] _GEN_18 = 8'h33 == io_keycode ? 7'h48 : _GEN_17; // @[Top.scala 232:36 251:43]
  wire [6:0] _GEN_19 = 8'h34 == io_keycode ? 7'h47 : _GEN_18; // @[Top.scala 232:36 250:43]
  wire [6:0] _GEN_20 = 8'h2b == io_keycode ? 7'h46 : _GEN_19; // @[Top.scala 232:36 249:43]
  wire [6:0] _GEN_21 = 8'h24 == io_keycode ? 7'h45 : _GEN_20; // @[Top.scala 232:36 248:43]
  wire [6:0] _GEN_22 = 8'h23 == io_keycode ? 7'h44 : _GEN_21; // @[Top.scala 232:36 247:43]
  wire [6:0] _GEN_23 = 8'h21 == io_keycode ? 7'h43 : _GEN_22; // @[Top.scala 232:36 246:43]
  wire [6:0] _GEN_24 = 8'h32 == io_keycode ? 7'h42 : _GEN_23; // @[Top.scala 232:36 245:43]
  wire [6:0] _GEN_25 = 8'h1c == io_keycode ? 7'h41 : _GEN_24; // @[Top.scala 232:36 244:43]
  wire [6:0] _GEN_26 = 8'h46 == io_keycode ? 7'h39 : _GEN_25; // @[Top.scala 232:36 242:43]
  wire [6:0] _GEN_27 = 8'h3e == io_keycode ? 7'h38 : _GEN_26; // @[Top.scala 232:36 241:43]
  wire [6:0] _GEN_28 = 8'h3d == io_keycode ? 7'h37 : _GEN_27; // @[Top.scala 232:36 240:43]
  wire [6:0] _GEN_29 = 8'h36 == io_keycode ? 7'h36 : _GEN_28; // @[Top.scala 232:36 239:43]
  wire [6:0] _GEN_30 = 8'h2e == io_keycode ? 7'h35 : _GEN_29; // @[Top.scala 232:36 238:43]
  wire [6:0] _GEN_31 = 8'h25 == io_keycode ? 7'h34 : _GEN_30; // @[Top.scala 232:36 237:43]
  wire [6:0] _GEN_32 = 8'h26 == io_keycode ? 7'h33 : _GEN_31; // @[Top.scala 232:36 236:43]
  wire [6:0] _GEN_33 = 8'h1e == io_keycode ? 7'h32 : _GEN_32; // @[Top.scala 232:36 235:43]
  wire [6:0] _GEN_34 = 8'h16 == io_keycode ? 7'h31 : _GEN_33; // @[Top.scala 232:36 234:43]
  wire [6:0] _GEN_35 = 8'h45 == io_keycode ? 7'h30 : _GEN_34; // @[Top.scala 232:36 233:43]
  wire  _GEN_36 = isBreakCode ? 1'h0 : isBreakCode; // @[Top.scala 224:31 225:29 211:30]
  wire [6:0] _GEN_39 = isBreakCode ? 7'h0 : _GEN_35; // @[Top.scala 215:14 224:31]
  wire  _GEN_40 = io_keycode == 8'hf0 | _GEN_36; // @[Top.scala 221:37 222:25]
  wire  _GEN_41 = io_keycode == 8'hf0 ? 1'h0 : isBreakCode; // @[Top.scala 214:17 221:37]
  wire [6:0] _GEN_43 = io_keycode == 8'hf0 ? 7'h0 : _GEN_39; // @[Top.scala 215:14 221:37]
  wire [6:0] _GEN_47 = ~io_clrn ? 7'h0 : _GEN_43; // @[Top.scala 215:14 217:20]
  assign io_ascii = {{1'd0}, _GEN_47};
  assign io_released = ~io_clrn ? 1'h0 : _GEN_41; // @[Top.scala 217:20 219:21]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 211:30]
      isBreakCode <= 1'h0; // @[Top.scala 211:30]
    end else if (~io_clrn) begin // @[Top.scala 217:20]
      isBreakCode <= 1'h0; // @[Top.scala 218:21]
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
  input  [4:0] io_in,
  input        io_en,
  output [7:0] io_seg
);
  wire [7:0] _GEN_0 = 5'hf == io_in ? 8'h71 : 8'hff; // @[Top.scala 302:10 308:19 324:25]
  wire [7:0] _GEN_1 = 5'he == io_in ? 8'h61 : _GEN_0; // @[Top.scala 308:19 323:25]
  wire [7:0] _GEN_2 = 5'hd == io_in ? 8'h85 : _GEN_1; // @[Top.scala 308:19 322:25]
  wire [7:0] _GEN_3 = 5'hc == io_in ? 8'h63 : _GEN_2; // @[Top.scala 308:19 321:25]
  wire [7:0] _GEN_4 = 5'hb == io_in ? 8'hc1 : _GEN_3; // @[Top.scala 308:19 320:25]
  wire [7:0] _GEN_5 = 5'ha == io_in ? 8'h11 : _GEN_4; // @[Top.scala 308:19 319:25]
  wire [7:0] _GEN_6 = 5'h9 == io_in ? 8'h9 : _GEN_5; // @[Top.scala 308:19 318:24]
  wire [7:0] _GEN_7 = 5'h8 == io_in ? 8'h1 : _GEN_6; // @[Top.scala 308:19 317:24]
  wire [7:0] _GEN_8 = 5'h7 == io_in ? 8'h1f : _GEN_7; // @[Top.scala 308:19 316:24]
  wire [7:0] _GEN_9 = 5'h6 == io_in ? 8'h41 : _GEN_8; // @[Top.scala 308:19 315:24]
  wire [7:0] _GEN_10 = 5'h5 == io_in ? 8'h49 : _GEN_9; // @[Top.scala 308:19 314:24]
  wire [7:0] _GEN_11 = 5'h4 == io_in ? 8'h99 : _GEN_10; // @[Top.scala 308:19 313:24]
  wire [7:0] _GEN_12 = 5'h3 == io_in ? 8'hd : _GEN_11; // @[Top.scala 308:19 312:24]
  wire [7:0] _GEN_13 = 5'h2 == io_in ? 8'h25 : _GEN_12; // @[Top.scala 308:19 311:24]
  wire [7:0] _GEN_14 = 5'h1 == io_in ? 8'h9f : _GEN_13; // @[Top.scala 308:19 310:24]
  wire [7:0] _GEN_15 = 5'h0 == io_in ? 8'h3 : _GEN_14; // @[Top.scala 308:19 309:24]
  assign io_seg = ~io_en ? 8'hff : _GEN_15; // @[Top.scala 305:16 306:12]
endmodule
module Keycount(
  input        clock,
  input        reset,
  input        io_key_press,
  input        io_key_release,
  input        io_clrn,
  output [3:0] io_ones,
  output [3:0] io_tens
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
`endif // RANDOMIZE_REG_INIT
  reg [3:0] ones; // @[Top.scala 340:23]
  reg [3:0] tens; // @[Top.scala 341:23]
  reg  counted; // @[Top.scala 342:26]
  wire [3:0] _tens_T_2 = tens + 4'h1; // @[Top.scala 355:47]
  wire [3:0] _tens_T_3 = tens == 4'h9 ? 4'h0 : _tens_T_2; // @[Top.scala 355:22]
  wire [3:0] _ones_T_1 = ones + 4'h1; // @[Top.scala 357:24]
  wire  _GEN_2 = io_key_press & ~counted | counted; // @[Top.scala 350:38 351:17 342:26]
  assign io_ones = ones; // @[Top.scala 367:13]
  assign io_tens = tens; // @[Top.scala 368:13]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 340:23]
      ones <= 4'h0; // @[Top.scala 340:23]
    end else if (~io_clrn) begin // @[Top.scala 344:20]
      ones <= 4'h0; // @[Top.scala 345:12]
    end else if (io_key_press & ~counted) begin // @[Top.scala 350:38]
      if (ones == 4'h9) begin // @[Top.scala 353:28]
        ones <= 4'h0; // @[Top.scala 354:16]
      end else begin
        ones <= _ones_T_1; // @[Top.scala 357:16]
      end
    end
    if (reset) begin // @[Top.scala 341:23]
      tens <= 4'h0; // @[Top.scala 341:23]
    end else if (~io_clrn) begin // @[Top.scala 344:20]
      tens <= 4'h0; // @[Top.scala 346:12]
    end else if (io_key_press & ~counted) begin // @[Top.scala 350:38]
      if (ones == 4'h9) begin // @[Top.scala 353:28]
        tens <= _tens_T_3; // @[Top.scala 355:16]
      end
    end
    if (reset) begin // @[Top.scala 342:26]
      counted <= 1'h0; // @[Top.scala 342:26]
    end else if (~io_clrn) begin // @[Top.scala 344:20]
      counted <= 1'h0; // @[Top.scala 347:15]
    end else if (io_key_release) begin // @[Top.scala 362:28]
      counted <= 1'h0; // @[Top.scala 363:17]
    end else begin
      counted <= _GEN_2;
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
  ones = _RAND_0[3:0];
  _RAND_1 = {1{`RANDOM}};
  tens = _RAND_1[3:0];
  _RAND_2 = {1{`RANDOM}};
  counted = _RAND_2[0:0];
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
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
`endif // RANDOMIZE_REG_INIT
  wire  keyboard_clock; // @[Top.scala 19:26]
  wire  keyboard_reset; // @[Top.scala 19:26]
  wire  keyboard_io_clrn; // @[Top.scala 19:26]
  wire  keyboard_io_ps2_clk; // @[Top.scala 19:26]
  wire  keyboard_io_ps2_data; // @[Top.scala 19:26]
  wire  keyboard_io_nextdata_n; // @[Top.scala 19:26]
  wire [7:0] keyboard_io_data; // @[Top.scala 19:26]
  wire  keyboard_io_ready; // @[Top.scala 19:26]
  wire  decoder_clock; // @[Top.scala 38:25]
  wire  decoder_reset; // @[Top.scala 38:25]
  wire [7:0] decoder_io_keycode; // @[Top.scala 38:25]
  wire  decoder_io_clrn; // @[Top.scala 38:25]
  wire [7:0] decoder_io_ascii; // @[Top.scala 38:25]
  wire  decoder_io_released; // @[Top.scala 38:25]
  wire [4:0] seg0_io_in; // @[Top.scala 43:22]
  wire  seg0_io_en; // @[Top.scala 43:22]
  wire [7:0] seg0_io_seg; // @[Top.scala 43:22]
  wire [4:0] seg1_io_in; // @[Top.scala 44:22]
  wire  seg1_io_en; // @[Top.scala 44:22]
  wire [7:0] seg1_io_seg; // @[Top.scala 44:22]
  wire [4:0] seg2_io_in; // @[Top.scala 45:22]
  wire  seg2_io_en; // @[Top.scala 45:22]
  wire [7:0] seg2_io_seg; // @[Top.scala 45:22]
  wire [4:0] seg3_io_in; // @[Top.scala 46:22]
  wire  seg3_io_en; // @[Top.scala 46:22]
  wire [7:0] seg3_io_seg; // @[Top.scala 46:22]
  wire [4:0] seg4_io_in; // @[Top.scala 47:22]
  wire  seg4_io_en; // @[Top.scala 47:22]
  wire [7:0] seg4_io_seg; // @[Top.scala 47:22]
  wire [4:0] seg5_io_in; // @[Top.scala 48:22]
  wire  seg5_io_en; // @[Top.scala 48:22]
  wire [7:0] seg5_io_seg; // @[Top.scala 48:22]
  wire  counter_clock; // @[Top.scala 51:25]
  wire  counter_reset; // @[Top.scala 51:25]
  wire  counter_io_key_press; // @[Top.scala 51:25]
  wire  counter_io_key_release; // @[Top.scala 51:25]
  wire  counter_io_clrn; // @[Top.scala 51:25]
  wire [3:0] counter_io_ones; // @[Top.scala 51:25]
  wire [3:0] counter_io_tens; // @[Top.scala 51:25]
  reg  nextdata_n; // @[Top.scala 25:29]
  reg  ready_delay; // @[Top.scala 29:30]
  wire  ready_p1 = keyboard_io_ready & ~ready_delay; // @[Top.scala 30:38]
  reg [7:0] data_d1; // @[Top.scala 32:26]
  wire  _GEN_1 = ready_p1 ? 1'h0 : 1'h1; // @[Top.scala 57:20 58:20 60:20]
  reg [7:0] key_scan_display_reg; // @[Top.scala 64:40]
  reg [7:0] key_ascii_display_reg; // @[Top.scala 65:40]
  reg  display_en; // @[Top.scala 66:29]
  wire  _GEN_2 = decoder_io_released ? 1'h0 : display_en; // @[Top.scala 78:40 79:20 66:29]
  wire  _GEN_5 = ready_p1 | _GEN_2; // @[Top.scala 74:22 77:20]
  wire [3:0] seg0_in = display_en ? key_scan_display_reg[3:0] : 4'h0; // @[Top.scala 89:22 91:15 97:15]
  wire [3:0] seg1_in = display_en ? key_scan_display_reg[7:4] : 4'h0; // @[Top.scala 89:22 92:15 98:15]
  wire [3:0] seg2_in = display_en ? key_ascii_display_reg[3:0] : 4'h0; // @[Top.scala 89:22 94:15 99:15]
  wire [3:0] seg3_in = display_en ? key_ascii_display_reg[7:4] : 4'h0; // @[Top.scala 100:15 89:22 95:15]
  PS2Keyboard keyboard ( // @[Top.scala 19:26]
    .clock(keyboard_clock),
    .reset(keyboard_reset),
    .io_clrn(keyboard_io_clrn),
    .io_ps2_clk(keyboard_io_ps2_clk),
    .io_ps2_data(keyboard_io_ps2_data),
    .io_nextdata_n(keyboard_io_nextdata_n),
    .io_data(keyboard_io_data),
    .io_ready(keyboard_io_ready)
  );
  Ps2_decoder decoder ( // @[Top.scala 38:25]
    .clock(decoder_clock),
    .reset(decoder_reset),
    .io_keycode(decoder_io_keycode),
    .io_clrn(decoder_io_clrn),
    .io_ascii(decoder_io_ascii),
    .io_released(decoder_io_released)
  );
  Seg seg0 ( // @[Top.scala 43:22]
    .io_in(seg0_io_in),
    .io_en(seg0_io_en),
    .io_seg(seg0_io_seg)
  );
  Seg seg1 ( // @[Top.scala 44:22]
    .io_in(seg1_io_in),
    .io_en(seg1_io_en),
    .io_seg(seg1_io_seg)
  );
  Seg seg2 ( // @[Top.scala 45:22]
    .io_in(seg2_io_in),
    .io_en(seg2_io_en),
    .io_seg(seg2_io_seg)
  );
  Seg seg3 ( // @[Top.scala 46:22]
    .io_in(seg3_io_in),
    .io_en(seg3_io_en),
    .io_seg(seg3_io_seg)
  );
  Seg seg4 ( // @[Top.scala 47:22]
    .io_in(seg4_io_in),
    .io_en(seg4_io_en),
    .io_seg(seg4_io_seg)
  );
  Seg seg5 ( // @[Top.scala 48:22]
    .io_in(seg5_io_in),
    .io_en(seg5_io_en),
    .io_seg(seg5_io_seg)
  );
  Keycount counter ( // @[Top.scala 51:25]
    .clock(counter_clock),
    .reset(counter_reset),
    .io_key_press(counter_io_key_press),
    .io_key_release(counter_io_key_release),
    .io_clrn(counter_io_clrn),
    .io_ones(counter_io_ones),
    .io_tens(counter_io_tens)
  );
  assign io_seg_out_0 = seg0_io_seg; // @[Top.scala 120:18]
  assign io_seg_out_1 = seg1_io_seg; // @[Top.scala 121:18]
  assign io_seg_out_2 = seg2_io_seg; // @[Top.scala 122:18]
  assign io_seg_out_3 = seg3_io_seg; // @[Top.scala 123:18]
  assign io_seg_out_4 = seg4_io_seg; // @[Top.scala 124:18]
  assign io_seg_out_5 = seg5_io_seg; // @[Top.scala 125:18]
  assign keyboard_clock = clock;
  assign keyboard_reset = reset;
  assign keyboard_io_clrn = io_clrn; // @[Top.scala 20:26]
  assign keyboard_io_ps2_clk = io_ps2_clk; // @[Top.scala 21:26]
  assign keyboard_io_ps2_data = io_ps2_data; // @[Top.scala 22:26]
  assign keyboard_io_nextdata_n = nextdata_n; // @[Top.scala 26:28]
  assign decoder_clock = clock;
  assign decoder_reset = reset;
  assign decoder_io_keycode = data_d1; // @[Top.scala 39:26]
  assign decoder_io_clrn = io_clrn; // @[Top.scala 40:26]
  assign seg0_io_in = {{1'd0}, seg0_in}; // @[Top.scala 103:16]
  assign seg0_io_en = display_en; // @[Top.scala 108:16]
  assign seg1_io_in = {{1'd0}, seg1_in}; // @[Top.scala 104:16]
  assign seg1_io_en = display_en; // @[Top.scala 109:16]
  assign seg2_io_in = {{1'd0}, seg2_in}; // @[Top.scala 105:16]
  assign seg2_io_en = display_en; // @[Top.scala 110:16]
  assign seg3_io_in = {{1'd0}, seg3_in}; // @[Top.scala 106:16]
  assign seg3_io_en = display_en; // @[Top.scala 111:16]
  assign seg4_io_in = {{1'd0}, counter_io_ones}; // @[Top.scala 116:16]
  assign seg4_io_en = 1'h1; // @[Top.scala 114:16]
  assign seg5_io_in = {{1'd0}, counter_io_tens}; // @[Top.scala 117:16]
  assign seg5_io_en = 1'h1; // @[Top.scala 115:16]
  assign counter_clock = clock;
  assign counter_reset = reset;
  assign counter_io_key_press = ready_p1 & ~decoder_io_released; // @[Top.scala 52:38]
  assign counter_io_key_release = decoder_io_released; // @[Top.scala 53:28]
  assign counter_io_clrn = io_clrn; // @[Top.scala 54:21]
  always @(posedge clock) begin
    nextdata_n <= reset | _GEN_1; // @[Top.scala 25:{29,29}]
    if (reset) begin // @[Top.scala 29:30]
      ready_delay <= 1'h0; // @[Top.scala 29:30]
    end else begin
      ready_delay <= keyboard_io_ready; // @[Top.scala 29:30]
    end
    if (reset) begin // @[Top.scala 32:26]
      data_d1 <= 8'h0; // @[Top.scala 32:26]
    end else if (ready_p1) begin // @[Top.scala 33:20]
      data_d1 <= keyboard_io_data; // @[Top.scala 34:15]
    end
    if (reset) begin // @[Top.scala 64:40]
      key_scan_display_reg <= 8'h0; // @[Top.scala 64:40]
    end else if (~io_clrn) begin // @[Top.scala 68:20]
      key_scan_display_reg <= 8'h0; // @[Top.scala 69:29]
    end else if (ready_p1) begin // @[Top.scala 74:22]
      key_scan_display_reg <= keyboard_io_data; // @[Top.scala 75:31]
    end
    if (reset) begin // @[Top.scala 65:40]
      key_ascii_display_reg <= 8'h0; // @[Top.scala 65:40]
    end else if (~io_clrn) begin // @[Top.scala 68:20]
      key_ascii_display_reg <= 8'h0; // @[Top.scala 70:29]
    end else if (ready_p1) begin // @[Top.scala 74:22]
      key_ascii_display_reg <= decoder_io_ascii; // @[Top.scala 76:31]
    end
    if (reset) begin // @[Top.scala 66:29]
      display_en <= 1'h0; // @[Top.scala 66:29]
    end else if (~io_clrn) begin // @[Top.scala 68:20]
      display_en <= 1'h0; // @[Top.scala 71:18]
    end else begin
      display_en <= _GEN_5;
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
  _RAND_2 = {1{`RANDOM}};
  data_d1 = _RAND_2[7:0];
  _RAND_3 = {1{`RANDOM}};
  key_scan_display_reg = _RAND_3[7:0];
  _RAND_4 = {1{`RANDOM}};
  key_ascii_display_reg = _RAND_4[7:0];
  _RAND_5 = {1{`RANDOM}};
  display_en = _RAND_5[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
