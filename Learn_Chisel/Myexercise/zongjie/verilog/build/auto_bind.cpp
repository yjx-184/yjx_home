#include <nvboard.h>
#include "VTop_top.h"

void nvboard_bind_all_pins(VTop_top* top) {
	nvboard_bind_pin( &top->led, 8, LD7, LD6, LD5, LD4, LD3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->btn, 1, BTNC);
	nvboard_bind_pin( &top->res, 1, SW0);
}
