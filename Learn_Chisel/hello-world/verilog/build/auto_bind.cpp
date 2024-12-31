#include <nvboard.h>
#include "Vhello_top.h"

void nvboard_bind_all_pins(Vhello_top* top) {
	nvboard_bind_pin( &top->led, 1, LD0);
}
