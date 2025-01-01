#include <nvboard.h>
#include "VTop_top.h"

void nvboard_bind_all_pins(VTop_top* top) {
	nvboard_bind_pin( &top->seg, 8, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G, DEC0P);
}
