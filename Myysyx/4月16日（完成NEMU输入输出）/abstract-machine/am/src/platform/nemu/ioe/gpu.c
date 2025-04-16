#include <am.h>
#include <nemu.h>

// 定义同步寄存器地址（VGACTL 控制寄存器地址 + 4，通常用于触发屏幕刷新）
#define SYNC_ADDR (VGACTL_ADDR + 4)

// GPU 初始化函数
void __am_gpu_init() {
  // AM_GPU_CONFIG_T info = io_read(AM_GPU_CONFIG);
  // int w = info.width, h = info.height;
  // int i;
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for (i = 0; i < w * h; i ++) fb[i] = i;
  // outl(SYNC_ADDR, 1);
}

//  AM显示控制器信息
void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t wh = inl(VGACTL_ADDR);
  uint32_t w  = wh >> 16;
  uint32_t h  = wh & 0xffff;

  *cfg = (AM_GPU_CONFIG_T) {
    .present = true,       // 表示 GPU 存在
    .has_accel = false,    // 不支持硬件加速
    .width = w,            // 屏幕宽度
    .height = h,           // 屏幕高度
    .vmemsz = w * h * 4    // 显存大小
  };
}

// AM帧缓冲控制器
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  // 获取帧缓冲区的起始地址，每个像素都是32位的
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;

  // 获取显存宽度(VGACTL 寄存器高 16 位是屏幕宽度）
  uint32_t wh = inl(VGACTL_ADDR);
  int screen_w = wh >> 16;

  //  向屏幕(x, y)坐标处绘制w*h的矩形图像（往坐标添加像素）
  for (int j = 0; j < ctl->h; j++) {
    for (int i = 0; i < ctl->w; i++) {
      int dst_x = ctl->x + i;
      int dst_y = ctl->y + j;

      // 越界检查（防止写入屏幕外）
      if (dst_x < 0 || dst_x >= screen_w) continue;
      if (dst_y < 0) continue;

      // 计算帧缓冲中一维数组的索引
      int offset = dst_y * screen_w + dst_x;

      // 图像像素按行优先方式存储在pixels中, 每个像素用32位整数以00RRGGBB的方式描述颜色
      uint32_t pixel = ((uint32_t *)ctl->pixels)[j * ctl->w + i];

      // 写入帧缓冲
      fb[offset] = pixel;
    }
  }

  // 如果 sync 为 true，则写入同步寄存器，触发屏幕刷新
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);    // 向 VGACTL 同步地址写 1，通知主控刷新屏幕
  }

}

// GPU 状态获取函数
void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;   // 表示 GPU 已就绪，可以处理绘图请求
}
