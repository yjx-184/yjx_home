#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  char buf[1024];                        // 临时缓冲区
  va_list args;
  va_start(args, fmt);
  int count = vsprintf(buf, fmt, args);  // 把格式化结果写到 buf
  va_end(args);

  for (int i = 0; i < count; i++) {
    putch(buf[i]);                       // 逐字符输出
  }

  return count;                          // 返回写入字符总数
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  int count = 0;  // 记录已输出的字符总数

  // 遍历格式字符串
  for (int i = 0; fmt[i] != '\0'; i++) {
    // 普通字符直接输出
    if (fmt[i] != '%') {
      *out++ = fmt[i];
      count++;
      continue;
    }

    i++;  // 跳过'%'，开始解析格式说明符

    // 解析格式修饰符
    int zero_pad = 0;  // 是否用0填充
    int width = 0;     // 最小输出宽度

    // 检查0填充标志（如%05d）
    if (fmt[i] == '0') {
      zero_pad = 1;
      i++;
    }

    // 解析宽度（支持多位数，如%10d）
    while (fmt[i] >= '0' && fmt[i] <= '9') {
      width = width * 10 + (fmt[i] - '0');
      i++;
    }

    char temp[32];  // 临时存储数字转换的字符（逆序）
    int len = 0;    // 临时字符长度

    // 根据格式说明符处理不同类型
    switch (fmt[i]) {
      case '%': {  // 处理%%转义（输出%字符）
        *out++ = '%';
        count++;
        break;
      }

      case 's': {  // 处理字符串输出
        char *str = va_arg(ap, char*);
        while (*str) {
          *out++ = *str++;
          count++;
        }
        break;
      }

      case 'd': {  // 处理整数输出
        int num = va_arg(ap, int);
        unsigned int unum;
        int negative = 0;  // 是否为负数

        // 处理负数（特殊处理INT_MIN避免溢出）
        if (num < 0) {
          negative = 1;
          unum = (unsigned int)(-num);
        } else {
          unum = num;
        }

        // 数字转字符串（逆序存储）
        if (unum == 0) {
          temp[len++] = '0';  // 处理0的特殊情况
        } else {
          while (unum > 0) {
            temp[len++] = '0' + (unum % 10);
            unum /= 10;
          }
        }

        // 计算需要填充的空格/0的数量
        // 总填充量 = 指定宽度 - 数字长度 - 负号占位
        int pad = width - len - negative;

        // 非0填充：先输出空格（右对齐）
        if (!zero_pad) {
          while (pad-- > 0) {
            *out++ = ' ';
            count++;
          }
        }

        // 输出负号（如果有）
        if (negative) {
          *out++ = '-';
          count++;
        }

        // 0填充：在数字前补0（如%05d）
        if (zero_pad) {
          while (pad-- > 0) {
            *out++ = '0';
            count++;
          }
        }

        // 将逆序的数字字符正序输出
        for (int j = len - 1; j >= 0; j--) {
          *out++ = temp[j];
          count++;
        }
        break;
      }

      default:  // 不支持的格式符直接跳过
        break;
    }
  }

  *out = '\0';  // 确保输出以NULL结尾
  return count;  // 返回总字符数
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int count = vsprintf(out, fmt, args);
  va_end(args);
  return count;

}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
