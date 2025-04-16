#include <utils.h>

NPCState npc_state = { .state = NPC_STOP };  //定义NEMU全局状态变量，并初始化NEMU_STOP

int is_exit_status_bad() {  //判断状态是否异常，以下是正常退出
  int good = (npc_state.state == NPC_END && npc_state.halt_ret == 0) ||  //1.程序正常结束
    (npc_state.state == NPC_QUIT);  //2.手动结束
  return !good; //正常状态返回0,否则返回非零
}

