#***************************************************************************************
# Copyright (c) 2014-2024 Zihao Yu, Nanjing University
#
# NEMU is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2
#
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
# EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
# MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
#
# See the Mulan PSL v2 for more details.
#**************************************************************************************/
# 颜色定义
# 终端红色高亮
COLOR_RED := $(shell echo "\033[1;31m")
# 终端颜色重置
COLOR_END := $(shell echo "\033[0m")

# 检查 .config 文件是否存在
ifeq ($(wildcard .config),)
# 输出警告信息，提示 .config 文件缺失
$(warning $(COLOR_RED)Warning: .config does not exist!$(COLOR_END))
# 提示用户先运行 `make menuconfig
$(warning $(COLOR_RED)To build the project, first run 'make menuconfig'.$(COLOR_END))
endif

# 变量定义
# 取消 `make` 的命令回显
Q            := @
# kconfig 目录路径
KCONFIG_PATH := $(NEMU_HOME)/tools/kconfig
# fixdep 目录路径
FIXDEP_PATH  := $(NEMU_HOME)/tools/fixdep
# Kconfig 文件路径
Kconfig      := $(NEMU_HOME)/Kconfig
# `distclean` 目标需要删除的文件
rm-distclean += include/generated include/config .config .config.old
# 让 `make` 以静默模式运行
silent := -s

# Kconfig 和 fixdep 相关工具
CONF   := $(KCONFIG_PATH)/build/conf
# Kconfig 配置工具
MCONF  := $(KCONFIG_PATH)/build/mconf
# Kconfig 菜单配置工具
FIXDEP := $(FIXDEP_PATH)/build/fixdep

# 目标：编译 Kconfig 配置工具，进入 `KCONFIG_PATH` 目录编译 `conf`
$(CONF):
	$(Q)$(MAKE) $(silent) -C $(KCONFIG_PATH) NAME=conf

# 目标：编译 Kconfig 菜单配置工具，进入 `KCONFIG_PATH` 目录编译 `mconf`
$(MCONF):
	$(Q)$(MAKE) $(silent) -C $(KCONFIG_PATH) NAME=mconf

# 目标：编译 fixdep 依赖管理工具，进入 `FIXDEP_PATH` 目录编译 `fixdep`
$(FIXDEP):
	$(Q)$(MAKE) $(silent) -C $(FIXDEP_PATH)

# 目标：进入菜单配置界面，运行菜单配置界面， 同步配置
menuconfig: $(MCONF) $(CONF) $(FIXDEP)
	$(Q)$(MCONF) $(Kconfig)
	$(Q)$(CONF) $(silent) --syncconfig $(Kconfig)

# 目标：保存最小化配置（defconfig），保存当前配置为 `configs/defconfig`
savedefconfig: $(CONF)
	$(Q)$< $(silent) --$@=configs/defconfig $(Kconfig)

# 目标：加载默认配置文件
%defconfig: $(CONF) $(FIXDEP)
	$(Q)$< $(silent) --defconfig=configs/$@ $(Kconfig)
	$(Q)$< $(silent) --syncconfig $(Kconfig)

.PHONY: menuconfig savedefconfig defconfig

# Help text used by make help
help:
	@echo  '  menuconfig	  - Update current config utilising a menu based program'
	@echo  '  savedefconfig   - Save current config as configs/defconfig (minimal config)'

distclean: clean
	-@rm -rf $(rm-distclean)

.PHONY: help distclean

define call_fixdep
	@$(FIXDEP) $(1) $(2) unused > $(1).tmp
	@mv $(1).tmp $(1)
endef
