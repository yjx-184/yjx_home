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

# 包含上级目录的 Makefile文件 
-include $(NEMU_HOME)/../Makefile

# 包含NEMU的构建脚本
include $(NEMU_HOME)/scripts/build.mk

# 包含差分测试工具的Makefile
include $(NEMU_HOME)/tools/difftest.mk

# 编译时记录git提交信息
compile_git:
	$(call git_commit, "compile NEMU")

# 定义生成二进制文件的规则，并依赖于 compile_git
$(BINARY):: compile_git

# Some convenient rules一些方便的规则

# 设置默认的运行参数
override ARGS ?= --log=$(BUILD_DIR)/nemu-log.txt
override ARGS += $(ARGS_DIFF)

# Command to execute NEMU 定义运行NEMU命令
# 镜像文件路径（默认为空）     完整的 NEMU 执行命令
IMG ?=
NEMU_EXEC := $(BINARY) $(ARGS) $(IMG)

# 运行环境准备：编译二进制文件和差分测试工具
run-env: $(BINARY) $(DIFF_REF_SO)

# 运行 NEMU
run: run-env
	$(call git_commit, "run NEMU")
	$(NEMU_EXEC)

# 使用 GDB 调试 NEMU
gdb: run-env
	$(call git_commit, "gdb NEMU")
	gdb -s $(BINARY) --args $(NEMU_EXEC)

# 统计代码行数（包括空行）
count:
	@find $(NEMU_HOME) -type f \( -name "*.c" -o -name "*.h" \) | xargs cat | wc -l

# 统计代码行数（不包括空行）
count-nonempty:
	@find $(NEMU_HOME) -type f \( -name "*.c" -o -name "*.h" \) | xargs cat | grep -v '^\s*$$' | wc -l

# 清理工具目录
clean-tools = $(dir $(shell find ./tools -maxdepth 2 -mindepth 2 -name "Makefile"))
$(clean-tools):
	-@$(MAKE) -s -C $@ clean
clean-tools: $(clean-tools)

# 清理所有：包括普通清理、彻底清理和工具清理
clean-all: clean distclean clean-tools


# 声明伪目标
.PHONY: run gdb run-env clean-tools clean-all $(clean-tools)
.PHONY: count count-nonempty