#include <nvboard.h>
#include "VSeg.h"

void nvboard_bind_all_pins(VSeg* top) {
	nvboard_bind_pin( &top->io_in, 8, SW7, SW6, SW5, SW4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->io_sel, 1, SW8);
	nvboard_bind_pin( &top->io_out, 3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->io_seg, 7, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G);
	nvboard_bind_pin( &top->io_valid, 1, LD4);
}
