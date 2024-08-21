#!/bin/bash

# 创建一个临时文件，用于存储测试输出
OUTPUT_FILE=$(mktemp)

# 定义一个函数来运行游戏并捕获输出
run_test() {
    echo "正在测试： $1"
    echo -e "$2" | ./ex19 > "$OUTPUT_FILE"
    grep "$3" "$OUTPUT_FILE" >/dev/null
    if [ $? -eq 0 ]; then
        echo "测试成功!"
    else
        echo "测试失败!"
        cat "$OUTPUT_FILE"
    fi
    echo
}

# 测试 1: 玩家向北移动并查看房间描述
run_test "向北移动" "n\n" "你前往北边"

# 测试 2: 玩家攻击房间里的怪物
run_test "攻击怪物" "a\n" "你攻击"

# 测试 3: 玩家列出可去的方向
run_test "列出方向" "l\n" "你可以去"

# 测试 4: 玩家输入无效指令
run_test "无效输入" "x\n" "什么?"

# 测试 5: 玩家向南移动并查看房间描述
run_test "向南移动" "s\n" "你前往南边"

# 测试 6: 玩家向东移动并查看房间描述
run_test "向东移动" "e\n" "你前往东边"

# 测试 7: 玩家向西移动并查看房间描述
run_test "向西移动" "w\n" "你前往西边"

# 清理临时文件
rm "$OUTPUT_FILE“