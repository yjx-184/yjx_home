#include <nvboard.h>
#include "Vclk_top.h"

void nvboard_bind_all_pins(Vclk_top* top) {
	nvboard_bind_pin( &top->led_o, 1, LD0);
	nvboard_bind_pin( &top->reset, 1, BTNR);
	nvboard_bind_pin( &top->sta, 1, SW0);
	nvboard_bind_pin( &top->seg_units, 8, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G, DEC0P);
	nvboard_bind_pin( &top->seg_tens, 8, SEG1A, SEG1B, SEG1C, SEG1D, SEG1E, SEG1F, SEG1G, DEC1P);
}
