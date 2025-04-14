#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  // 处理可变参数的标准机制
  va_list args;         // 定义一个va_list类型的变量，用于存储可变参数
  va_start(args, fmt);  // 初始化args，使其指向第一个可变参数

  int count = 0;        // 用于记录写入到out的字符数

  // 遍历格式字符串fmt
  for (int i = 0; fmt[i] != '\0'; i++) {
    if (fmt[i] == '%') {  // 如果遇到格式说明符的起始字符'%'
      i++;                // 跳过 '%'，指向格式说明符的具体字符
      switch (fmt[i]) {
        case 's': {                         // 处理 %s，表示要输出一个字符串
          char *str = va_arg(args, char*);  // 从可变参数中获取一个字符串指针
          while (*str) {                    // 遍历字符串中的每一个字符
            *out++ = *str++;                // 将字符串中的字符逐个复制到out中
            count++;
          }
          break;
        }

        case 'd': {                         // 处理 %d，表示要输出一个整数
          int num = va_arg(args,int);       // 从可变参数中获取一个整数
          char temp[20];                    // 临时数组，存整数的字符串
          int j = 0;                        // 记录临时字符数组的索引

          // 处理负数
          if (num < 0) {
            *out++ = '-';                   // 在out中添加负号
            count++;
            num = -num;                     // 将负数转换为正数，方便后续处理
          }

          // 将整数转换为字符串
          if (num == 0) {
            temp[j++] = '0';                // 直接将字符'0'存入临时数组
          } else {
            int k = 0;                      // 记录临时字符数组的索引
            while (num >0) {                // 将整数的每一位转换为字符
              temp[k++] = '0' + (num % 10); // 取整数的最后一位，并转换为字符
              num /= 10;                    // 去掉整数的最后一位
            }
            // 反转字符串,上一步处理是从最低位到最高位
            for (int m = k - 1; m >= 0; m--) {
              *out++ = temp[m];             // 将临时数组中的字符逐个复制到out中
              count++;
            }
          }
          break;
        }
        default:
          break;
      }
    } else {
      // 如果当前字符不是格式说明符的起始字符'%'，则直接将其复制到out中
      *out++ = fmt[i];
            count++; 
    }
  }
  *out = '\0';   // 在out的末尾添加null字符，表示字符串的结束
  va_end(args);  // 清理va_list变量
  return count;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
