#ifndef __AMDEV_H__
#define __AMDEV_H__

// **MAY SUBJECT TO CHANGE IN THE FUTURE**
// **注意：这些定义未来可能会发生变化**

/* 
 * 设备寄存器宏定义
 *  id   设备ID
 *  reg  寄存器名称
 *  perm 访问权限(RD-只读/WR-只写)
 *  ...  寄存器字段定义
 */
#define AM_DEVREG(id, reg, perm, ...) \
  enum { AM_##reg = (id) }; /* 定义枚举值 AM_reg = id */\
  typedef struct { __VA_ARGS__; } AM_##reg##_T; // 定义对应结构体类型

// 定义所有设备寄存器（设备ID范围1-24）
AM_DEVREG( 1, UART_CONFIG,  RD, bool present);                               // 串口配置：是否存在
AM_DEVREG( 2, UART_TX,      WR, char data);                                  // 串口发送：数据字节
AM_DEVREG( 3, UART_RX,      RD, char data);                                  // 串口接收：数据字节
AM_DEVREG( 4, TIMER_CONFIG, RD, bool present, has_rtc);                      // 定时器配置：存在性+RTC支持
AM_DEVREG( 5, TIMER_RTC,    RD, int year, month, day, hour, minute, second); // RTC时间
AM_DEVREG( 6, TIMER_UPTIME, RD, uint64_t us);                                // 系统运行时间(微秒)
AM_DEVREG( 7, INPUT_CONFIG, RD, bool present);                               // 输入设备配置
AM_DEVREG( 8, INPUT_KEYBRD, RD, bool keydown; int keycode);                  // 键盘输入状态
AM_DEVREG( 9, GPU_CONFIG,   RD, bool present, has_accel; int width, height, vmemsz); // GPU配置
AM_DEVREG(10, GPU_STATUS,   RD, bool ready);                                  // GPU状态：是否就绪
AM_DEVREG(11, GPU_FBDRAW,   WR, int x, y; void *pixels; int w, h; bool sync); // 帧缓冲绘制
AM_DEVREG(12, GPU_MEMCPY,   WR, uint32_t dest; void *src; int size);          // GPU内存拷贝
AM_DEVREG(13, GPU_RENDER,   WR, uint32_t root);                               // GPU渲染根节点
AM_DEVREG(14, AUDIO_CONFIG, RD, bool present; int bufsize);                   // 音频配置
AM_DEVREG(15, AUDIO_CTRL,   WR, int freq, channels, samples);                 // 音频控制参数
AM_DEVREG(16, AUDIO_STATUS, RD, int count);                                   // 音频缓冲区计数
AM_DEVREG(17, AUDIO_PLAY,   WR, Area buf);                                    // 音频播放缓冲区
AM_DEVREG(18, DISK_CONFIG,  RD, bool present; int blksz, blkcnt);             // 磁盘配置
AM_DEVREG(19, DISK_STATUS,  RD, bool ready);                                  // 磁盘状态
AM_DEVREG(20, DISK_BLKIO,   WR, bool write; void *buf; int blkno, blkcnt);    // 磁盘块I/O
AM_DEVREG(21, NET_CONFIG,   RD, bool present);                                // 网络配置
AM_DEVREG(22, NET_STATUS,   RD, int rx_len, tx_len);                          // 网络状态
AM_DEVREG(23, NET_TX,       WR, Area buf);                                    // 网络发送缓冲区
AM_DEVREG(24, NET_RX,       WR, Area buf);                                    // 网络接收缓冲区

// Input
// ------------------------- 输入系统定义 -------------------------
#define AM_KEYS(_) \
  _(ESCAPE) _(F1) _(F2) _(F3) _(F4) _(F5) _(F6) _(F7) _(F8) _(F9) _(F10) _(F11) _(F12) \
  _(GRAVE) _(1) _(2) _(3) _(4) _(5) _(6) _(7) _(8) _(9) _(0) _(MINUS) _(EQUALS) _(BACKSPACE) \
  _(TAB) _(Q) _(W) _(E) _(R) _(T) _(Y) _(U) _(I) _(O) _(P) _(LEFTBRACKET) _(RIGHTBRACKET) _(BACKSLASH) \
  _(CAPSLOCK) _(A) _(S) _(D) _(F) _(G) _(H) _(J) _(K) _(L) _(SEMICOLON) _(APOSTROPHE) _(RETURN) \
  _(LSHIFT) _(Z) _(X) _(C) _(V) _(B) _(N) _(M) _(COMMA) _(PERIOD) _(SLASH) _(RSHIFT) \
  _(LCTRL) _(APPLICATION) _(LALT) _(SPACE) _(RALT) _(RCTRL) \
  _(UP) _(DOWN) _(LEFT) _(RIGHT) _(INSERT) _(DELETE) _(HOME) _(END) _(PAGEUP) _(PAGEDOWN)

// 生成按键枚举值(AM_KEY_前缀)
#define AM_KEY_NAMES(key) AM_KEY_##key,
enum {
  AM_KEY_NONE = 0,      // 无按键状态
  AM_KEYS(AM_KEY_NAMES) // 展开所有按键定义
};

// GPU
// ------------------------- GPU相关定义 -------------------------
// GPU节点类型定义
#define AM_GPU_TEXTURE  1           // 纹理节点
#define AM_GPU_SUBTREE  2           // 子树节点
#define AM_GPU_NULL     0xffffffff  // 空指针标识

typedef uint32_t gpuptr_t;          // GPU指针类型(32位)

/* 纹理描述结构体(紧凑排列) */
struct gpu_texturedesc {
  uint16_t w, h;                    // 纹理宽度和高度
  gpuptr_t pixels;                  // 像素数据指针
} __attribute__((packed));          // 禁止编译器填充对齐

/* GPU画布结构体(紧凑排列) */
struct gpu_canvas {
  uint16_t type, w, h, x1, y1, w1, h1; // 节点类型,画布宽高,子区域偏移,子区域尺寸,
  gpuptr_t sibling;                    // 兄弟节点指针
  union {                              // 联合体：根据类型不同使用不同字段
    gpuptr_t child;                    // SUBTREE类型的子节点指针
    struct gpu_texturedesc texture;    // TEXTURE类型的纹理描述
  };
} __attribute__((packed));             // 禁止编译器填充对齐

#endif
