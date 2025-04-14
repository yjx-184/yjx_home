#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// 计算字符串的长度
size_t strlen(const char *s) {
  size_t len = 0;
  while (*s++) {
    len++;
  }
  return len;
}

// 复制字符串
char *strcpy(char *dst, const char *src) {
  char *orig = dst;
  while((*dst++ = *src++) != '\0');
  return orig;
}

// 复制字符串
char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;

  for (i = 0; i < n && src[i] != '\0'; i++)
    dst[i] = src[i];
  for ( ; i < n; i++)
    dst[i] = '\0';
  return dst;
}

// 连接两个字符串
char *strcat(char *dst, const char *src) {
  char *ptr = dst;

  while (*ptr != '\0') {  // 移动到dst末尾
    ptr++;
  }
  while (*src != '\0') {  // 复制src到dst末尾
    *ptr++ = *src++;
  }
  *ptr = '\0';            // 添加终止符

  return dst;
}

// 比较两个字符串
int strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return (unsigned char)(*s1) - (unsigned char)(*s2);
}

// 比较两个字符串的前n个字节
int strncmp(const char *s1, const char *s2, size_t n) {
  while (n && *s1 && (*s1 == *s2)) {
    s1++;
    s2++;
    n--;
  }
  return n ? (unsigned char)(*s1) - (unsigned char)(*s2) : 0;
}

// 用常量字节填充内存
void *memset(void *s, int c, size_t n) {
  unsigned char *ptr = s;
  while (n--) {
    *ptr = (unsigned char)c;
    ptr++;
  }
  return s;
}

// 复制内存区域
void *memmove(void *dst, const void *src, size_t n) {
  unsigned char *d = dst;
  const unsigned char *s = src;

  // 检查内存重叠
  if (d < s || d >= s + n) {
    // 如果dst在src前面或完全在src的后面，直接从头到尾复制
    while (n--) {
      *d++ = *s++;
    }
  } else {
    // 如果dst在src的范围内（存在重叠），需要从后往前复制
    d += n;
    s += n;
    while (n--) {
      *(--d) = *(--s);
    } 
  }
  return dst;
}

// 复制内存区域
void *memcpy(void *out, const void *in, size_t n) {
  // void * 类型不能直接进行字节访问，因此将 dest 和 src 转换为 char *。
  // 因为在 C 语言中，char 类型是 1 字节，所以可以通过它来逐字节复制。

  char *o = (char *)out;
  const char *i = (const char *)in;

  for (size_t m = 0; m < n; m++) {
    o[m] = i[m];
  }
  return out;
}

//  比较内存区域
int memcmp(const void *s1, const void *s2, size_t n) {
  unsigned char *p1 = (unsigned char *)s1;
  unsigned char *p2 = (unsigned char *)s2;

  for (size_t i = 0; i < n; i++) {
    if (p1[i] != p2[i]) {
      return p1[i] - p2[i];
    }
  }
  return 0;
}

#endif
