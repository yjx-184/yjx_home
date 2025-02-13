#include <nvboard.h>
#include "VAlu.h"

void nvboard_bind_all_pins(VAlu* top) {
	nvboard_bind_pin( &top->io_a, 4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->io_b, 4, SW7, SW6, SW5, SW4);
	nvboard_bind_pin( &top->io_op, 3, SW14, SW13, SW12);
	nvboard_bind_pin( &top->io_op, 3, LD14, LD13, LD12);
	nvboard_bind_pin( &top->io_result, 4, LD3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->io_carry, 1, LD5);
	nvboard_bind_pin( &top->io_zero, 1, LD6);
	nvboard_bind_pin( &top->io_overflow, 1, LD7);
}
