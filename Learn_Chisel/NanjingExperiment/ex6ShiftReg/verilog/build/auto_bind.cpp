#include <nvboard.h>
#include "VTop.h"

void nvboard_bind_all_pins(VTop* top) {
	nvboard_bind_pin( &top->io_btn, 1, BTNC);
	nvboard_bind_pin( &top->io_reset, 1, SW0);
	nvboard_bind_pin( &top->io_seg_out, 8, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G, DEC0P);
}
