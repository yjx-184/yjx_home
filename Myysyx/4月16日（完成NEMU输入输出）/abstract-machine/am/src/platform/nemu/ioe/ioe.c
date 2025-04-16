#include <am.h>
#include <klib-macros.h>

// 声明各个设备初始化与操作函数
void __am_timer_init();                          // 初始化定时器
void __am_gpu_init();                            // 初始化图形设备
void __am_audio_init();                          // 初始化音频设备
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);     // 获取键盘输入
void __am_timer_rtc(AM_TIMER_RTC_T *);           // 获取实时时钟信息
void __am_timer_uptime(AM_TIMER_UPTIME_T *);     // 获取系统运行时间
void __am_gpu_config(AM_GPU_CONFIG_T *);         // 获取图形设备配置信息
void __am_gpu_status(AM_GPU_STATUS_T *);         // 获取图形设备状态
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *);         // 图像帧缓冲绘制
void __am_audio_config(AM_AUDIO_CONFIG_T *);     // 获取音频设备配置信息
void __am_audio_ctrl(AM_AUDIO_CTRL_T *);         // 控制音频设备
void __am_audio_status(AM_AUDIO_STATUS_T *);     // 获取音频状态
void __am_audio_play(AM_AUDIO_PLAY_T *);         // 播放音频数据
void __am_disk_config(AM_DISK_CONFIG_T *cfg);    // 获取磁盘设备配置
void __am_disk_status(AM_DISK_STATUS_T *stat);   // 获取磁盘状态
void __am_disk_blkio(AM_DISK_BLKIO_T *io);       // 读写磁盘块数据

// 配置定时器：支持且包含RTC
static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) {
  cfg->present = true;   // 表示设备存在
  cfg->has_rtc = true;   // 表示设备包含实时时钟
}

// 配置输入设备：支持
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) {
  cfg->present = true;   // 表示设备存在
}

// 配置串口设备：不支持
static void __am_uart_config(AM_UART_CONFIG_T *cfg) {
  cfg->present = false;  // 表示设备不存在
}

// 配置网络设备：不支持
static void __am_net_config(AM_NET_CONFIG_T *cfg) {
  cfg->present = false;  // 表示设备不存在
}

// 定义函数指针类型 handler_t，用于统一调用各设备函数
typedef void (*handler_t)(void *buf);
// 定义一个查找表（lookup table, LUT），用于根据寄存器编号调用对应的设备处理函数
static void *lut[128] = {
  [AM_TIMER_CONFIG] = __am_timer_config,
  [AM_TIMER_RTC   ] = __am_timer_rtc,
  [AM_TIMER_UPTIME] = __am_timer_uptime,
  [AM_INPUT_CONFIG] = __am_input_config,
  [AM_INPUT_KEYBRD] = __am_input_keybrd,
  [AM_GPU_CONFIG  ] = __am_gpu_config,
  [AM_GPU_FBDRAW  ] = __am_gpu_fbdraw,
  [AM_GPU_STATUS  ] = __am_gpu_status,
  [AM_UART_CONFIG ] = __am_uart_config,
  [AM_AUDIO_CONFIG] = __am_audio_config,
  [AM_AUDIO_CTRL  ] = __am_audio_ctrl,
  [AM_AUDIO_STATUS] = __am_audio_status,
  [AM_AUDIO_PLAY  ] = __am_audio_play,
  [AM_DISK_CONFIG ] = __am_disk_config,
  [AM_DISK_STATUS ] = __am_disk_status,
  [AM_DISK_BLKIO  ] = __am_disk_blkio,
  [AM_NET_CONFIG  ] = __am_net_config,
};

// 默认的处理函数：当寄存器号没有对应处理函数时调用
static void fail(void *buf) { panic("access nonexist register"); }  // 抛出错误

// 初始化 I/O 子系统
bool ioe_init() {
  // 遍历查找表，未赋值的项用 fail 函数填充，防止访问非法寄存器
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i]) lut[i] = fail;
  // 调用各设备的初始化函数
  __am_gpu_init();
  __am_timer_init();
  __am_audio_init();
  return true;    // 初始化成功
}

void ioe_read (int reg, void *buf) { ((handler_t)lut[reg])(buf); }// 读取设备寄存器（调用对应的设备读函数）
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }// 写入设备寄存器（调用对应的设备写函数）
