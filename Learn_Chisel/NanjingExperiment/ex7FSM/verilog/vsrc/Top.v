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
  reg [9:0] buffer; // @[Top.scala 128:28]
  reg [7:0] fifo_0; // @[Top.scala 129:28]
  reg [7:0] fifo_1; // @[Top.scala 129:28]
  reg [7:0] fifo_2; // @[Top.scala 129:28]
  reg [7:0] fifo_3; // @[Top.scala 129:28]
  reg [7:0] fifo_4; // @[Top.scala 129:28]
  reg [7:0] fifo_5; // @[Top.scala 129:28]
  reg [7:0] fifo_6; // @[Top.scala 129:28]
  reg [7:0] fifo_7; // @[Top.scala 129:28]
  reg [2:0] w_ptr; // @[Top.scala 130:28]
  reg [2:0] r_ptr; // @[Top.scala 131:28]
  reg [3:0] count; // @[Top.scala 132:28]
  reg  ready; // @[Top.scala 134:28]
  reg [2:0] ps2_clk_sync; // @[Top.scala 135:28]
  wire [2:0] _ps2_clk_sync_T_1 = {ps2_clk_sync[1:0],io_ps2_clk}; // @[Cat.scala 31:58]
  wire  sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1]; // @[Top.scala 139:34]
  wire [2:0] _r_ptr_T_1 = r_ptr + 3'h1; // @[Top.scala 155:22]
  wire  _GEN_1 = ready & ~io_nextdata_n ? ~(w_ptr == _r_ptr_T_1) : ready; // @[Top.scala 154:36 156:13 134:28]
  wire  _valid_T_3 = ~buffer[0] & io_ps2_data; // @[Top.scala 164:39]
  wire  _valid_T_5 = ^buffer[9:1]; // @[Top.scala 166:38]
  wire  valid = _valid_T_3 & _valid_T_5; // @[Top.scala 165:40]
  wire [7:0] _GEN_2 = 3'h0 == w_ptr ? buffer[8:1] : fifo_0; // @[Top.scala 169:{23,23} 129:28]
  wire [7:0] _GEN_3 = 3'h1 == w_ptr ? buffer[8:1] : fifo_1; // @[Top.scala 169:{23,23} 129:28]
  wire [7:0] _GEN_4 = 3'h2 == w_ptr ? buffer[8:1] : fifo_2; // @[Top.scala 169:{23,23} 129:28]
  wire [7:0] _GEN_5 = 3'h3 == w_ptr ? buffer[8:1] : fifo_3; // @[Top.scala 169:{23,23} 129:28]
  wire [7:0] _GEN_6 = 3'h4 == w_ptr ? buffer[8:1] : fifo_4; // @[Top.scala 169:{23,23} 129:28]
  wire [7:0] _GEN_7 = 3'h5 == w_ptr ? buffer[8:1] : fifo_5; // @[Top.scala 169:{23,23} 129:28]
  wire [7:0] _GEN_8 = 3'h6 == w_ptr ? buffer[8:1] : fifo_6; // @[Top.scala 169:{23,23} 129:28]
  wire [7:0] _GEN_9 = 3'h7 == w_ptr ? buffer[8:1] : fifo_7; // @[Top.scala 169:{23,23} 129:28]
  wire [2:0] _w_ptr_T_1 = w_ptr + 3'h1; // @[Top.scala 170:26]
  wire [7:0] _GEN_10 = valid ? _GEN_2 : fifo_0; // @[Top.scala 168:22 129:28]
  wire [7:0] _GEN_11 = valid ? _GEN_3 : fifo_1; // @[Top.scala 168:22 129:28]
  wire [7:0] _GEN_12 = valid ? _GEN_4 : fifo_2; // @[Top.scala 168:22 129:28]
  wire [7:0] _GEN_13 = valid ? _GEN_5 : fifo_3; // @[Top.scala 168:22 129:28]
  wire [7:0] _GEN_14 = valid ? _GEN_6 : fifo_4; // @[Top.scala 168:22 129:28]
  wire [7:0] _GEN_15 = valid ? _GEN_7 : fifo_5; // @[Top.scala 168:22 129:28]
  wire [7:0] _GEN_16 = valid ? _GEN_8 : fifo_6; // @[Top.scala 168:22 129:28]
  wire [7:0] _GEN_17 = valid ? _GEN_9 : fifo_7; // @[Top.scala 168:22 129:28]
  wire [2:0] _GEN_18 = valid ? _w_ptr_T_1 : w_ptr; // @[Top.scala 168:22 170:17 130:28]
  wire  _GEN_19 = valid | _GEN_1; // @[Top.scala 168:22 171:17]
  wire  bufferVec_0 = 4'h0 == count ? io_ps2_data : buffer[0]; // @[Top.scala 178:{26,26} 177:32]
  wire  bufferVec_1 = 4'h1 == count ? io_ps2_data : buffer[1]; // @[Top.scala 178:{26,26} 177:32]
  wire  bufferVec_2 = 4'h2 == count ? io_ps2_data : buffer[2]; // @[Top.scala 178:{26,26} 177:32]
  wire  bufferVec_3 = 4'h3 == count ? io_ps2_data : buffer[3]; // @[Top.scala 178:{26,26} 177:32]
  wire  bufferVec_4 = 4'h4 == count ? io_ps2_data : buffer[4]; // @[Top.scala 178:{26,26} 177:32]
  wire  bufferVec_5 = 4'h5 == count ? io_ps2_data : buffer[5]; // @[Top.scala 178:{26,26} 177:32]
  wire  bufferVec_6 = 4'h6 == count ? io_ps2_data : buffer[6]; // @[Top.scala 178:{26,26} 177:32]
  wire  bufferVec_7 = 4'h7 == count ? io_ps2_data : buffer[7]; // @[Top.scala 178:{26,26} 177:32]
  wire  bufferVec_8 = 4'h8 == count ? io_ps2_data : buffer[8]; // @[Top.scala 178:{26,26} 177:32]
  wire  bufferVec_9 = 4'h9 == count ? io_ps2_data : buffer[9]; // @[Top.scala 178:{26,26} 177:32]
  wire [9:0] _buffer_T = {bufferVec_9,bufferVec_8,bufferVec_7,bufferVec_6,bufferVec_5,bufferVec_4,bufferVec_3,
    bufferVec_2,bufferVec_1,bufferVec_0}; // @[Top.scala 179:29]
  wire [3:0] _count_T_1 = count + 4'h1; // @[Top.scala 180:24]
  wire [7:0] _GEN_72 = 3'h1 == r_ptr ? fifo_1 : fifo_0; // @[Top.scala 185:{15,15}]
  wire [7:0] _GEN_73 = 3'h2 == r_ptr ? fifo_2 : _GEN_72; // @[Top.scala 185:{15,15}]
  wire [7:0] _GEN_74 = 3'h3 == r_ptr ? fifo_3 : _GEN_73; // @[Top.scala 185:{15,15}]
  wire [7:0] _GEN_75 = 3'h4 == r_ptr ? fifo_4 : _GEN_74; // @[Top.scala 185:{15,15}]
  wire [7:0] _GEN_76 = 3'h5 == r_ptr ? fifo_5 : _GEN_75; // @[Top.scala 185:{15,15}]
  wire [7:0] _GEN_77 = 3'h6 == r_ptr ? fifo_6 : _GEN_76; // @[Top.scala 185:{15,15}]
  assign io_data = 3'h7 == r_ptr ? fifo_7 : _GEN_77; // @[Top.scala 185:{15,15}]
  assign io_ready = ready; // @[Top.scala 186:15]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 128:28]
      buffer <= 10'h0; // @[Top.scala 128:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      buffer <= 10'h0; // @[Top.scala 144:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (!(count == 4'ha)) begin // @[Top.scala 162:29]
        buffer <= _buffer_T; // @[Top.scala 179:16]
      end
    end
    if (reset) begin // @[Top.scala 129:28]
      fifo_0 <= 8'h0; // @[Top.scala 129:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      fifo_0 <= 8'h0; // @[Top.scala 145:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (count == 4'ha) begin // @[Top.scala 162:29]
        fifo_0 <= _GEN_10;
      end
    end
    if (reset) begin // @[Top.scala 129:28]
      fifo_1 <= 8'h0; // @[Top.scala 129:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      fifo_1 <= 8'h0; // @[Top.scala 145:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (count == 4'ha) begin // @[Top.scala 162:29]
        fifo_1 <= _GEN_11;
      end
    end
    if (reset) begin // @[Top.scala 129:28]
      fifo_2 <= 8'h0; // @[Top.scala 129:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      fifo_2 <= 8'h0; // @[Top.scala 145:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (count == 4'ha) begin // @[Top.scala 162:29]
        fifo_2 <= _GEN_12;
      end
    end
    if (reset) begin // @[Top.scala 129:28]
      fifo_3 <= 8'h0; // @[Top.scala 129:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      fifo_3 <= 8'h0; // @[Top.scala 145:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (count == 4'ha) begin // @[Top.scala 162:29]
        fifo_3 <= _GEN_13;
      end
    end
    if (reset) begin // @[Top.scala 129:28]
      fifo_4 <= 8'h0; // @[Top.scala 129:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      fifo_4 <= 8'h0; // @[Top.scala 145:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (count == 4'ha) begin // @[Top.scala 162:29]
        fifo_4 <= _GEN_14;
      end
    end
    if (reset) begin // @[Top.scala 129:28]
      fifo_5 <= 8'h0; // @[Top.scala 129:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      fifo_5 <= 8'h0; // @[Top.scala 145:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (count == 4'ha) begin // @[Top.scala 162:29]
        fifo_5 <= _GEN_15;
      end
    end
    if (reset) begin // @[Top.scala 129:28]
      fifo_6 <= 8'h0; // @[Top.scala 129:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      fifo_6 <= 8'h0; // @[Top.scala 145:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (count == 4'ha) begin // @[Top.scala 162:29]
        fifo_6 <= _GEN_16;
      end
    end
    if (reset) begin // @[Top.scala 129:28]
      fifo_7 <= 8'h0; // @[Top.scala 129:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      fifo_7 <= 8'h0; // @[Top.scala 145:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (count == 4'ha) begin // @[Top.scala 162:29]
        fifo_7 <= _GEN_17;
      end
    end
    if (reset) begin // @[Top.scala 130:28]
      w_ptr <= 3'h0; // @[Top.scala 130:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      w_ptr <= 3'h0; // @[Top.scala 146:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (count == 4'ha) begin // @[Top.scala 162:29]
        w_ptr <= _GEN_18;
      end
    end
    if (reset) begin // @[Top.scala 131:28]
      r_ptr <= 3'h0; // @[Top.scala 131:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      r_ptr <= 3'h0; // @[Top.scala 147:15]
    end else if (ready & ~io_nextdata_n) begin // @[Top.scala 154:36]
      r_ptr <= _r_ptr_T_1; // @[Top.scala 155:13]
    end
    if (reset) begin // @[Top.scala 132:28]
      count <= 4'h0; // @[Top.scala 132:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      count <= 4'h0; // @[Top.scala 148:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (count == 4'ha) begin // @[Top.scala 162:29]
        count <= 4'h0; // @[Top.scala 174:15]
      end else begin
        count <= _count_T_1; // @[Top.scala 180:15]
      end
    end
    if (reset) begin // @[Top.scala 134:28]
      ready <= 1'h0; // @[Top.scala 134:28]
    end else if (~io_clrn) begin // @[Top.scala 142:19]
      ready <= 1'h0; // @[Top.scala 149:15]
    end else if (sampling) begin // @[Top.scala 161:21]
      if (count == 4'ha) begin // @[Top.scala 162:29]
        ready <= _GEN_19;
      end else begin
        ready <= _GEN_1;
      end
    end else begin
      ready <= _GEN_1;
    end
    if (reset) begin // @[Top.scala 135:28]
      ps2_clk_sync <= 3'h0; // @[Top.scala 135:28]
    end else begin
      ps2_clk_sync <= _ps2_clk_sync_T_1; // @[Top.scala 138:16]
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
  reg  isBreakCode; // @[Top.scala 199:30]
  wire [6:0] _GEN_0 = 8'h14 == io_keycode ? 7'h5a : 7'h0; // @[Top.scala 215:26 218:36 255:43]
  wire [6:0] _GEN_1 = 8'h22 == io_keycode ? 7'h59 : _GEN_0; // @[Top.scala 218:36 254:43]
  wire [6:0] _GEN_2 = 8'h1a == io_keycode ? 7'h58 : _GEN_1; // @[Top.scala 218:36 253:43]
  wire [6:0] _GEN_3 = 8'h1d == io_keycode ? 7'h57 : _GEN_2; // @[Top.scala 218:36 252:43]
  wire [6:0] _GEN_4 = 8'h2a == io_keycode ? 7'h56 : _GEN_3; // @[Top.scala 218:36 251:43]
  wire [6:0] _GEN_5 = 8'h3c == io_keycode ? 7'h55 : _GEN_4; // @[Top.scala 218:36 250:43]
  wire [6:0] _GEN_6 = 8'h2c == io_keycode ? 7'h54 : _GEN_5; // @[Top.scala 218:36 249:43]
  wire [6:0] _GEN_7 = 8'h1b == io_keycode ? 7'h53 : _GEN_6; // @[Top.scala 218:36 248:43]
  wire [6:0] _GEN_8 = 8'h2d == io_keycode ? 7'h52 : _GEN_7; // @[Top.scala 218:36 247:43]
  wire [6:0] _GEN_9 = 8'h15 == io_keycode ? 7'h51 : _GEN_8; // @[Top.scala 218:36 246:43]
  wire [6:0] _GEN_10 = 8'h4d == io_keycode ? 7'h50 : _GEN_9; // @[Top.scala 218:36 245:43]
  wire [6:0] _GEN_11 = 8'h44 == io_keycode ? 7'h4f : _GEN_10; // @[Top.scala 218:36 244:43]
  wire [6:0] _GEN_12 = 8'h31 == io_keycode ? 7'h4e : _GEN_11; // @[Top.scala 218:36 243:43]
  wire [6:0] _GEN_13 = 8'h3a == io_keycode ? 7'h4d : _GEN_12; // @[Top.scala 218:36 242:43]
  wire [6:0] _GEN_14 = 8'h4b == io_keycode ? 7'h4c : _GEN_13; // @[Top.scala 218:36 241:43]
  wire [6:0] _GEN_15 = 8'h42 == io_keycode ? 7'h4b : _GEN_14; // @[Top.scala 218:36 240:43]
  wire [6:0] _GEN_16 = 8'h3b == io_keycode ? 7'h4a : _GEN_15; // @[Top.scala 218:36 239:43]
  wire [6:0] _GEN_17 = 8'h43 == io_keycode ? 7'h49 : _GEN_16; // @[Top.scala 218:36 238:43]
  wire [6:0] _GEN_18 = 8'h33 == io_keycode ? 7'h48 : _GEN_17; // @[Top.scala 218:36 237:43]
  wire [6:0] _GEN_19 = 8'h34 == io_keycode ? 7'h47 : _GEN_18; // @[Top.scala 218:36 236:43]
  wire [6:0] _GEN_20 = 8'h2b == io_keycode ? 7'h46 : _GEN_19; // @[Top.scala 218:36 235:43]
  wire [6:0] _GEN_21 = 8'h24 == io_keycode ? 7'h45 : _GEN_20; // @[Top.scala 218:36 234:43]
  wire [6:0] _GEN_22 = 8'h23 == io_keycode ? 7'h44 : _GEN_21; // @[Top.scala 218:36 233:43]
  wire [6:0] _GEN_23 = 8'h21 == io_keycode ? 7'h43 : _GEN_22; // @[Top.scala 218:36 232:43]
  wire [6:0] _GEN_24 = 8'h32 == io_keycode ? 7'h42 : _GEN_23; // @[Top.scala 218:36 231:43]
  wire [6:0] _GEN_25 = 8'h1c == io_keycode ? 7'h41 : _GEN_24; // @[Top.scala 218:36 230:43]
  wire [6:0] _GEN_26 = 8'h46 == io_keycode ? 7'h39 : _GEN_25; // @[Top.scala 218:36 228:43]
  wire [6:0] _GEN_27 = 8'h3e == io_keycode ? 7'h38 : _GEN_26; // @[Top.scala 218:36 227:43]
  wire [6:0] _GEN_28 = 8'h3d == io_keycode ? 7'h37 : _GEN_27; // @[Top.scala 218:36 226:43]
  wire [6:0] _GEN_29 = 8'h36 == io_keycode ? 7'h36 : _GEN_28; // @[Top.scala 218:36 225:43]
  wire [6:0] _GEN_30 = 8'h2e == io_keycode ? 7'h35 : _GEN_29; // @[Top.scala 218:36 224:43]
  wire [6:0] _GEN_31 = 8'h25 == io_keycode ? 7'h34 : _GEN_30; // @[Top.scala 218:36 223:43]
  wire [6:0] _GEN_32 = 8'h26 == io_keycode ? 7'h33 : _GEN_31; // @[Top.scala 218:36 222:43]
  wire [6:0] _GEN_33 = 8'h1e == io_keycode ? 7'h32 : _GEN_32; // @[Top.scala 218:36 221:43]
  wire [6:0] _GEN_34 = 8'h16 == io_keycode ? 7'h31 : _GEN_33; // @[Top.scala 218:36 220:43]
  wire [6:0] _GEN_35 = 8'h45 == io_keycode ? 7'h30 : _GEN_34; // @[Top.scala 218:36 219:43]
  wire  _GEN_36 = isBreakCode ? 1'h0 : isBreakCode; // @[Top.scala 211:31 212:29 199:30]
  wire [6:0] _GEN_38 = isBreakCode ? 7'h0 : _GEN_35; // @[Top.scala 202:14 211:31]
  wire  _GEN_39 = io_keycode == 8'hf0 | _GEN_36; // @[Top.scala 208:37 209:25]
  wire  _GEN_40 = io_keycode == 8'hf0 ? 1'h0 : isBreakCode; // @[Top.scala 201:17 208:37]
  wire [6:0] _GEN_41 = io_keycode == 8'hf0 ? 7'h0 : _GEN_38; // @[Top.scala 202:14 208:37]
  wire [6:0] _GEN_44 = ~io_clrn ? 7'h0 : _GEN_41; // @[Top.scala 202:14 204:20]
  assign io_ascii = {{1'd0}, _GEN_44};
  assign io_released = ~io_clrn ? 1'h0 : _GEN_40; // @[Top.scala 204:20 206:21]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 199:30]
      isBreakCode <= 1'h0; // @[Top.scala 199:30]
    end else if (~io_clrn) begin // @[Top.scala 204:20]
      isBreakCode <= 1'h0; // @[Top.scala 205:21]
    end else begin
      isBreakCode <= _GEN_39;
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
  input        io_en,
  output [7:0] io_seg
);
  wire [7:0] _GEN_0 = 4'hf == io_in ? 8'h71 : 8'hff; // @[Top.scala 288:10 294:19 310:25]
  wire [7:0] _GEN_1 = 4'he == io_in ? 8'h61 : _GEN_0; // @[Top.scala 294:19 309:25]
  wire [7:0] _GEN_2 = 4'hd == io_in ? 8'h85 : _GEN_1; // @[Top.scala 294:19 308:25]
  wire [7:0] _GEN_3 = 4'hc == io_in ? 8'h63 : _GEN_2; // @[Top.scala 294:19 307:25]
  wire [7:0] _GEN_4 = 4'hb == io_in ? 8'hc1 : _GEN_3; // @[Top.scala 294:19 306:25]
  wire [7:0] _GEN_5 = 4'ha == io_in ? 8'h11 : _GEN_4; // @[Top.scala 294:19 305:25]
  wire [7:0] _GEN_6 = 4'h9 == io_in ? 8'h9 : _GEN_5; // @[Top.scala 294:19 304:24]
  wire [7:0] _GEN_7 = 4'h8 == io_in ? 8'h1 : _GEN_6; // @[Top.scala 294:19 303:24]
  wire [7:0] _GEN_8 = 4'h7 == io_in ? 8'h1f : _GEN_7; // @[Top.scala 294:19 302:24]
  wire [7:0] _GEN_9 = 4'h6 == io_in ? 8'h41 : _GEN_8; // @[Top.scala 294:19 301:24]
  wire [7:0] _GEN_10 = 4'h5 == io_in ? 8'h49 : _GEN_9; // @[Top.scala 294:19 300:24]
  wire [7:0] _GEN_11 = 4'h4 == io_in ? 8'h99 : _GEN_10; // @[Top.scala 294:19 299:24]
  wire [7:0] _GEN_12 = 4'h3 == io_in ? 8'hd : _GEN_11; // @[Top.scala 294:19 298:24]
  wire [7:0] _GEN_13 = 4'h2 == io_in ? 8'h25 : _GEN_12; // @[Top.scala 294:19 297:24]
  wire [7:0] _GEN_14 = 4'h1 == io_in ? 8'h9f : _GEN_13; // @[Top.scala 294:19 296:24]
  wire [7:0] _GEN_15 = 4'h0 == io_in ? 8'h3 : _GEN_14; // @[Top.scala 294:19 295:24]
  assign io_seg = ~io_en ? 8'hff : _GEN_15; // @[Top.scala 291:16 292:12]
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
  reg [3:0] ones; // @[Top.scala 326:23]
  reg [3:0] tens; // @[Top.scala 327:23]
  reg  counted; // @[Top.scala 328:26]
  wire [3:0] _tens_T_2 = tens + 4'h1; // @[Top.scala 341:47]
  wire [3:0] _tens_T_3 = tens == 4'h9 ? 4'h0 : _tens_T_2; // @[Top.scala 341:22]
  wire [3:0] _ones_T_1 = ones + 4'h1; // @[Top.scala 343:24]
  wire  _GEN_2 = io_key_press & ~counted | counted; // @[Top.scala 336:38 337:17 328:26]
  assign io_ones = ones; // @[Top.scala 351:13]
  assign io_tens = tens; // @[Top.scala 352:13]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 326:23]
      ones <= 4'h0; // @[Top.scala 326:23]
    end else if (~io_clrn) begin // @[Top.scala 330:20]
      ones <= 4'h0; // @[Top.scala 331:12]
    end else if (io_key_press & ~counted) begin // @[Top.scala 336:38]
      if (ones == 4'h9) begin // @[Top.scala 339:28]
        ones <= 4'h0; // @[Top.scala 340:16]
      end else begin
        ones <= _ones_T_1; // @[Top.scala 343:16]
      end
    end
    if (reset) begin // @[Top.scala 327:23]
      tens <= 4'h0; // @[Top.scala 327:23]
    end else if (~io_clrn) begin // @[Top.scala 330:20]
      tens <= 4'h0; // @[Top.scala 332:12]
    end else if (io_key_press & ~counted) begin // @[Top.scala 336:38]
      if (ones == 4'h9) begin // @[Top.scala 339:28]
        tens <= _tens_T_3; // @[Top.scala 341:16]
      end
    end
    if (reset) begin // @[Top.scala 328:26]
      counted <= 1'h0; // @[Top.scala 328:26]
    end else if (~io_clrn) begin // @[Top.scala 330:20]
      counted <= 1'h0; // @[Top.scala 333:15]
    end else if (io_key_release) begin // @[Top.scala 347:28]
      counted <= 1'h0; // @[Top.scala 348:17]
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
`endif // RANDOMIZE_REG_INIT
  wire  keyboard_clock; // @[Top.scala 19:26]
  wire  keyboard_reset; // @[Top.scala 19:26]
  wire  keyboard_io_clrn; // @[Top.scala 19:26]
  wire  keyboard_io_ps2_clk; // @[Top.scala 19:26]
  wire  keyboard_io_ps2_data; // @[Top.scala 19:26]
  wire  keyboard_io_nextdata_n; // @[Top.scala 19:26]
  wire [7:0] keyboard_io_data; // @[Top.scala 19:26]
  wire  keyboard_io_ready; // @[Top.scala 19:26]
  wire  decoder_clock; // @[Top.scala 46:25]
  wire  decoder_reset; // @[Top.scala 46:25]
  wire [7:0] decoder_io_keycode; // @[Top.scala 46:25]
  wire  decoder_io_clrn; // @[Top.scala 46:25]
  wire [7:0] decoder_io_ascii; // @[Top.scala 46:25]
  wire  decoder_io_released; // @[Top.scala 46:25]
  wire [3:0] seg0_io_in; // @[Top.scala 51:22]
  wire  seg0_io_en; // @[Top.scala 51:22]
  wire [7:0] seg0_io_seg; // @[Top.scala 51:22]
  wire [3:0] seg1_io_in; // @[Top.scala 52:22]
  wire  seg1_io_en; // @[Top.scala 52:22]
  wire [7:0] seg1_io_seg; // @[Top.scala 52:22]
  wire [3:0] seg2_io_in; // @[Top.scala 53:22]
  wire  seg2_io_en; // @[Top.scala 53:22]
  wire [7:0] seg2_io_seg; // @[Top.scala 53:22]
  wire [3:0] seg3_io_in; // @[Top.scala 54:22]
  wire  seg3_io_en; // @[Top.scala 54:22]
  wire [7:0] seg3_io_seg; // @[Top.scala 54:22]
  wire [3:0] seg4_io_in; // @[Top.scala 55:22]
  wire  seg4_io_en; // @[Top.scala 55:22]
  wire [7:0] seg4_io_seg; // @[Top.scala 55:22]
  wire [3:0] seg5_io_in; // @[Top.scala 56:22]
  wire  seg5_io_en; // @[Top.scala 56:22]
  wire [7:0] seg5_io_seg; // @[Top.scala 56:22]
  wire  counter_clock; // @[Top.scala 59:25]
  wire  counter_reset; // @[Top.scala 59:25]
  wire  counter_io_key_press; // @[Top.scala 59:25]
  wire  counter_io_key_release; // @[Top.scala 59:25]
  wire  counter_io_clrn; // @[Top.scala 59:25]
  wire [3:0] counter_io_ones; // @[Top.scala 59:25]
  wire [3:0] counter_io_tens; // @[Top.scala 59:25]
  reg  readySync; // @[Top.scala 25:28]
  wire  ready_p1 = keyboard_io_ready & ~readySync; // @[Top.scala 26:38]
  reg  nextdata_n; // @[Top.scala 29:29]
  wire  _GEN_0 = ready_p1 ? 1'h0 : 1'h1; // @[Top.scala 33:20 34:20 36:20]
  reg [7:0] data_d1; // @[Top.scala 40:26]
  reg [7:0] key_ascii_display_reg; // @[Top.scala 65:40]
  reg  display_en; // @[Top.scala 66:29]
  wire  _GEN_2 = decoder_io_released ? 1'h0 : display_en; // @[Top.scala 77:40 78:20 66:29]
  wire  _GEN_5 = ready_p1 | _GEN_2; // @[Top.scala 73:22 76:20]
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
  Ps2_decoder decoder ( // @[Top.scala 46:25]
    .clock(decoder_clock),
    .reset(decoder_reset),
    .io_keycode(decoder_io_keycode),
    .io_clrn(decoder_io_clrn),
    .io_ascii(decoder_io_ascii),
    .io_released(decoder_io_released)
  );
  Seg seg0 ( // @[Top.scala 51:22]
    .io_in(seg0_io_in),
    .io_en(seg0_io_en),
    .io_seg(seg0_io_seg)
  );
  Seg seg1 ( // @[Top.scala 52:22]
    .io_in(seg1_io_in),
    .io_en(seg1_io_en),
    .io_seg(seg1_io_seg)
  );
  Seg seg2 ( // @[Top.scala 53:22]
    .io_in(seg2_io_in),
    .io_en(seg2_io_en),
    .io_seg(seg2_io_seg)
  );
  Seg seg3 ( // @[Top.scala 54:22]
    .io_in(seg3_io_in),
    .io_en(seg3_io_en),
    .io_seg(seg3_io_seg)
  );
  Seg seg4 ( // @[Top.scala 55:22]
    .io_in(seg4_io_in),
    .io_en(seg4_io_en),
    .io_seg(seg4_io_seg)
  );
  Seg seg5 ( // @[Top.scala 56:22]
    .io_in(seg5_io_in),
    .io_en(seg5_io_en),
    .io_seg(seg5_io_seg)
  );
  Keycount counter ( // @[Top.scala 59:25]
    .clock(counter_clock),
    .reset(counter_reset),
    .io_key_press(counter_io_key_press),
    .io_key_release(counter_io_key_release),
    .io_clrn(counter_io_clrn),
    .io_ones(counter_io_ones),
    .io_tens(counter_io_tens)
  );
  assign io_seg_out_0 = seg0_io_seg; // @[Top.scala 108:18]
  assign io_seg_out_1 = seg1_io_seg; // @[Top.scala 109:18]
  assign io_seg_out_2 = seg2_io_seg; // @[Top.scala 110:18]
  assign io_seg_out_3 = seg3_io_seg; // @[Top.scala 111:18]
  assign io_seg_out_4 = seg4_io_seg; // @[Top.scala 112:18]
  assign io_seg_out_5 = seg5_io_seg; // @[Top.scala 113:18]
  assign keyboard_clock = clock;
  assign keyboard_reset = reset;
  assign keyboard_io_clrn = io_clrn; // @[Top.scala 20:26]
  assign keyboard_io_ps2_clk = io_ps2_clk; // @[Top.scala 21:26]
  assign keyboard_io_ps2_data = io_ps2_data; // @[Top.scala 22:26]
  assign keyboard_io_nextdata_n = nextdata_n; // @[Top.scala 30:28]
  assign decoder_clock = clock;
  assign decoder_reset = reset;
  assign decoder_io_keycode = data_d1; // @[Top.scala 47:26]
  assign decoder_io_clrn = io_clrn; // @[Top.scala 48:26]
  assign seg0_io_in = display_en ? data_d1[3:0] : 4'h0; // @[Top.scala 82:22 84:18 90:18]
  assign seg0_io_en = display_en; // @[Top.scala 96:16]
  assign seg1_io_in = display_en ? data_d1[7:4] : 4'h0; // @[Top.scala 82:22 85:18 91:18]
  assign seg1_io_en = display_en; // @[Top.scala 97:16]
  assign seg2_io_in = display_en ? key_ascii_display_reg[3:0] : 4'h0; // @[Top.scala 82:22 87:18 92:18]
  assign seg2_io_en = display_en; // @[Top.scala 98:16]
  assign seg3_io_in = display_en ? key_ascii_display_reg[7:4] : 4'h0; // @[Top.scala 82:22 88:18 93:18]
  assign seg3_io_en = display_en; // @[Top.scala 99:16]
  assign seg4_io_in = counter_io_ones; // @[Top.scala 104:16]
  assign seg4_io_en = 1'h1; // @[Top.scala 102:16]
  assign seg5_io_in = counter_io_tens; // @[Top.scala 105:16]
  assign seg5_io_en = 1'h1; // @[Top.scala 103:16]
  assign counter_clock = clock;
  assign counter_reset = reset;
  assign counter_io_key_press = ready_p1 & ~decoder_io_released; // @[Top.scala 60:38]
  assign counter_io_key_release = decoder_io_released; // @[Top.scala 61:28]
  assign counter_io_clrn = io_clrn; // @[Top.scala 62:21]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 25:28]
      readySync <= 1'h0; // @[Top.scala 25:28]
    end else begin
      readySync <= keyboard_io_ready; // @[Top.scala 25:28]
    end
    nextdata_n <= reset | _GEN_0; // @[Top.scala 29:{29,29}]
    if (reset) begin // @[Top.scala 40:26]
      data_d1 <= 8'h0; // @[Top.scala 40:26]
    end else if (~io_clrn) begin // @[Top.scala 67:20]
      data_d1 <= 8'h0; // @[Top.scala 68:15]
    end else if (ready_p1) begin // @[Top.scala 73:22]
      data_d1 <= keyboard_io_data; // @[Top.scala 74:17]
    end else if (ready_p1) begin // @[Top.scala 41:20]
      data_d1 <= keyboard_io_data; // @[Top.scala 42:15]
    end
    if (reset) begin // @[Top.scala 65:40]
      key_ascii_display_reg <= 8'h0; // @[Top.scala 65:40]
    end else if (~io_clrn) begin // @[Top.scala 67:20]
      key_ascii_display_reg <= 8'h0; // @[Top.scala 69:29]
    end else if (ready_p1) begin // @[Top.scala 73:22]
      key_ascii_display_reg <= decoder_io_ascii; // @[Top.scala 75:31]
    end
    if (reset) begin // @[Top.scala 66:29]
      display_en <= 1'h0; // @[Top.scala 66:29]
    end else if (~io_clrn) begin // @[Top.scala 67:20]
      display_en <= 1'h0; // @[Top.scala 70:18]
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
  readySync = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  nextdata_n = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  data_d1 = _RAND_2[7:0];
  _RAND_3 = {1{`RANDOM}};
  key_ascii_display_reg = _RAND_3[7:0];
  _RAND_4 = {1{`RANDOM}};
  display_en = _RAND_4[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
