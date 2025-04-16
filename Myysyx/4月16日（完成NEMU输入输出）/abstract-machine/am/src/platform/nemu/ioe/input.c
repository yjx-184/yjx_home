#include <am.h>
#include <nemu.h>

// 按键按下的掩码，高位为 1 表示按下，0 表示释放
#define KEYDOWN_MASK 0x8000

// 键盘输入处理函数，读取键盘状态并填入 kbd 结构体中
void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {

  uint32_t key = inl(KBD_ADDR);                 // 从键盘地址读取当前键值（32 位）

  if (key != 0) {
    kbd->keydown = (key & KEYDOWN_MASK) != 0;   // 判断按键事件类型（按下或松开），keydown 为 1 表示按下
    kbd->keycode = key & ~KEYDOWN_MASK;         // 提取按键的键码（去掉高位的按下/释放标志位）
  } else {
    kbd->keydown = 0;
    kbd->keycode = AM_KEY_NONE;
  }
}
