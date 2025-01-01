#include <nvboard.h>
#include "VCombinational_top.h"

void nvboard_bind_all_pins(VCombinational_top* top) {
	nvboard_bind_pin( &top->in, 4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->seg, 8, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G, DEC0P);
}
