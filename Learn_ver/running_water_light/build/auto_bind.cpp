#include <nvboard.h>
#include "Vlight.h"

void nvboard_bind_all_pins(Vlight* top) {
	nvboard_bind_pin( &top->clk, 1, PS2_CLK);
	nvboard_bind_pin( &top->rst, 1, PS2_DAT);
	nvboard_bind_pin( &top->led, 16, LD15, LD14, LD13, LD12, LD11, LD10, LD9, LD8, LD7, LD6, LD5, LD4, LD3, LD2, LD1, LD0);
}
