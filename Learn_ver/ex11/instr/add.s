    .text
    .globl _start

_start:
    # 加载立即数
    li    t0, 10        # t0 = 10
    li    t1, 20        # t1 = 20

    # 执行加法
    add   t2, t0, t1    # t2 = t0 + t1 (t2 = 10 + 20)

    # 结束程序（在某些模拟器上使用退出指令）
    li    a0, 0         # 设置返回值为0
    ecall               # 调用系统调用退出程序
