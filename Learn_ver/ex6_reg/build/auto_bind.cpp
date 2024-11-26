#include <nvboard.h>
#include "Vreg_top.h"

void nvboard_bind_all_pins(Vreg_top* top) {
	nvboard_bind_pin( &top->reset, 1, BTNR);
	nvboard_bind_pin( &top->reset, 1, LD0);
	nvboard_bind_pin( &top->btn, 1, BTNC);
	nvboard_bind_pin( &top->btn, 1, LD4);
	nvboard_bind_pin( &top->seg_u, 8, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G, DEC0P);
	nvboard_bind_pin( &top->seg_t, 8, SEG1A, SEG1B, SEG1C, SEG1D, SEG1E, SEG1F, SEG1G, DEC1P);
}
