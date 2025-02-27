# 设置时钟端口名称为 “clock”，在顶层模块中定义的时钟信号
set clk_port_name clock

# 设置时钟频率为 500MHz, 可以根据情况修改
set CLK_FREQ_MHZ 500

# 如果环境变量中已经定义时钟频率，则使用其频率，否则使用默认的500MHz
if {[info exists env(CLK_FREQ_MHZ)]} {
  set CLK_FREQ_MHZ $::env(CLK_FREQ_MHZ)
} else {
  # 如果环境变量未定义时钟频率，输出警告并使用默认频率
  puts "Warning: Environment CLK_FREQ_MHZ is not defined. Use $CLK_FREQ_MHZ MHz by default."
}

# 设置时钟输入占空比（时钟高电平的时间比例），通常为 0.5，即 50%
set clk_io_pct 0.2

# 获取时钟端口对象
set clk_port [get_ports $clk_port_name]

# 创建时钟约束，设定时钟周期为 1/频率（500 MHz 时，周期为 2 ns）
create_clock -name core_clock -period [expr 1000 / $CLK_FREQ_MHZ] $clk_port
