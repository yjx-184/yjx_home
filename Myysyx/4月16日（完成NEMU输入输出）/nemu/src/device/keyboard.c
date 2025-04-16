/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <device/map.h>
#include <utils.h>

// 键盘按键按下掩码，最高位为1表示按键按下
#define KEYDOWN_MASK 0x8000

// 如果不是在AM(Abstract Machine)环境下，使用SDL处理键盘输入
#ifndef CONFIG_TARGET_AM
#include <SDL2/SDL.h>

// Note that this is not the standard
// 定义NEMU支持的键盘按键列表
// 注意这不是标准键盘布局
#define NEMU_KEYS(f) \
  f(ESCAPE) f(F1) f(F2) f(F3) f(F4) f(F5) f(F6) f(F7) f(F8) f(F9) f(F10) f(F11) f(F12) \
f(GRAVE) f(1) f(2) f(3) f(4) f(5) f(6) f(7) f(8) f(9) f(0) f(MINUS) f(EQUALS) f(BACKSPACE) \
f(TAB) f(Q) f(W) f(E) f(R) f(T) f(Y) f(U) f(I) f(O) f(P) f(LEFTBRACKET) f(RIGHTBRACKET) f(BACKSLASH) \
f(CAPSLOCK) f(A) f(S) f(D) f(F) f(G) f(H) f(J) f(K) f(L) f(SEMICOLON) f(APOSTROPHE) f(RETURN) \
f(LSHIFT) f(Z) f(X) f(C) f(V) f(B) f(N) f(M) f(COMMA) f(PERIOD) f(SLASH) f(RSHIFT) \
f(LCTRL) f(APPLICATION) f(LALT) f(SPACE) f(RALT) f(RCTRL) \
f(UP) f(DOWN) f(LEFT) f(RIGHT) f(INSERT) f(DELETE) f(HOME) f(END) f(PAGEUP) f(PAGEDOWN)

// 生成NEMU键盘按键枚举值，格式为NEMU_KEY_<按键名>
#define NEMU_KEY_NAME(k) NEMU_KEY_ ## k,

// 定义NEMU键盘按键枚举
enum {
  NEMU_KEY_NONE = 0,              // 无按键
  MAP(NEMU_KEYS, NEMU_KEY_NAME)   // 展开所有按键定义
};

// 将SDL扫描码映射到NEMU按键码
#define SDL_KEYMAP(k) keymap[SDL_SCANCODE_ ## k] = NEMU_KEY_ ## k;
static uint32_t keymap[256] = {}; // SDL扫描码到NEMU按键码的映射表

// 初始化SDL扫描码到NEMU按键码的映射表
static void init_keymap() {
  MAP(NEMU_KEYS, SDL_KEYMAP)      // 展开所有按键映射
}

#define KEY_QUEUE_LEN 1024        // 键盘事件队列长度
static int key_queue[KEY_QUEUE_LEN] = {}; // 键盘事件队列
static int key_f = 0, key_r = 0;  // 队列头尾指针

// 将键盘事件加入队列
static void key_enqueue(uint32_t am_scancode) {
  key_queue[key_r] = am_scancode;  // 将扫描码存入队列尾部
  key_r = (key_r + 1) % KEY_QUEUE_LEN;            // 尾指针循环移动
  Assert(key_r != key_f, "key queue overflow!");  // 检查队列是否溢出
}

// 从队列中取出键盘事件
static uint32_t key_dequeue() {
  uint32_t key = NEMU_KEY_NONE;                   // 默认返回无按键
  if (key_f != key_r) {                           // 如果队列不为空
    key = key_queue[key_f];                       // 取出队列头部元素
    key_f = (key_f + 1) % KEY_QUEUE_LEN;          // 头指针循环移动
  }
  return key;
}

// 发送键盘事件到模拟器
void send_key(uint8_t scancode, bool is_keydown) {
  // 只有当模拟器在运行状态且扫描码有对应映射时才处理
  if (nemu_state.state == NEMU_RUNNING && keymap[scancode] != NEMU_KEY_NONE) {
    // 组合按键码和按下/释放标志
    uint32_t am_scancode = keymap[scancode] | (is_keydown ? KEYDOWN_MASK : 0);
    key_enqueue(am_scancode);                     // 将事件加入队列
  }
}
#else // !CONFIG_TARGET_AM 在AM环境下使用AM的键盘输入接口
#define NEMU_KEY_NONE 0

// 从AM获取键盘事件
static uint32_t key_dequeue() {
  AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);// 读取AM键盘事件
  uint32_t am_scancode = ev.keycode | (ev.keydown ? KEYDOWN_MASK : 0);// 组合按键码和状态
  return am_scancode;
}
#endif

// i8042键盘控制器数据端口基地址
static uint32_t *i8042_data_port_base = NULL;

// i8042数据端口IO处理函数
static void i8042_data_io_handler(uint32_t offset, int len, bool is_write) {
  assert(!is_write);                        // 确保是读操作
  assert(offset == 0);                      // 确保偏移量为0
  i8042_data_port_base[0] = key_dequeue();  // 从队列获取按键并写入数据端口
}

// 初始化i8042键盘控制器
void init_i8042() {
  i8042_data_port_base = (uint32_t *)new_space(4); // 分配4字节空间
  i8042_data_port_base[0] = NEMU_KEY_NONE;         // 初始化为无按键状态
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("keyboard", CONFIG_I8042_DATA_PORT, i8042_data_port_base, 4, i8042_data_io_handler);
#else
  add_mmio_map("keyboard", CONFIG_I8042_DATA_MMIO, i8042_data_port_base, 4, i8042_data_io_handler);
#endif
  // 如果不是在AM环境下，初始化键盘映射表
  IFNDEF(CONFIG_TARGET_AM, init_keymap());
}
