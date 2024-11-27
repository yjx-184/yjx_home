#include <nvboard.h>
#include "Vfsm.h"

void nvboard_bind_all_pins(Vfsm* top) {
	nvboard_bind_pin( &top->reset, 1, SW0);
	nvboard_bind_pin( &top->w, 1, SW1);
	nvboard_bind_pin( &top->z, 1, LD0);
	nvboard_bind_pin( &top->y, 4, LD7, LD6, LD5, LD4);
	nvboard_bind_pin( &top->btn, 1, BTNC);
	nvboard_bind_pin( &top->btn, 1, LD2);
}
