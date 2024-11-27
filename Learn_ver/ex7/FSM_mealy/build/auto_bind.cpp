#include <nvboard.h>
#include "Vfsm_mealy.h"

void nvboard_bind_all_pins(Vfsm_mealy* top) {
	nvboard_bind_pin( &top->reset, 1, SW0);
	nvboard_bind_pin( &top->in, 1, SW1);
	nvboard_bind_pin( &top->btn, 1, BTNC);
	nvboard_bind_pin( &top->out, 1, LD0);
	nvboard_bind_pin( &top->sta, 4, LD7, LD6, LD5, LD4);
}
