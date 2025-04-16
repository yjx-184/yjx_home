#include <am.h>
#include <nemu.h>

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  // uptime->us = 0;

  // uint32_t hi = inl(RTC_ADDR + 4);
  // uint32_t lo = inl(RTC_ADDR);
  // uptime->us = ((uint64_t)hi << 32) | lo;

  uint32_t hi, lo;
  do {
    hi = inl(RTC_ADDR + 4);   // 先读取高32位
    lo = inl(RTC_ADDR);       // 再读取低32位
  } while (hi != inl(RTC_ADDR + 4)); // 再次检查高32位是否变化
  uptime->us = ((uint64_t)hi << 32) | lo;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
