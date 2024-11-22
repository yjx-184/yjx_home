#include <nvboard.h>
#include "Valu_top.h"

void nvboard_bind_all_pins(Valu_top* top) {
	nvboard_bind_pin( &top->i_a, 4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->i_b, 4, SW7, SW6, SW5, SW4);
	nvboard_bind_pin( &top->i_op, 3, SW14, SW13, SW12);
	nvboard_bind_pin( &top->i_op, 3, LD14, LD13, LD12);
	nvboard_bind_pin( &top->o_result, 4, LD3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->o_cin, 1, LD5);
	nvboard_bind_pin( &top->o_carry, 1, LD6);
	nvboard_bind_pin( &top->o_overflow, 1, LD7);
	nvboard_bind_pin( &top->o_max, 1, LD8);
	nvboard_bind_pin( &top->o_equ, 1, LD9);
	nvboard_bind_pin( &top->o_zero, 1, LD10);
	nvboard_bind_pin( &top->o_signbit, 8, SEG1A, SEG1B, SEG1C, SEG1D, SEG1E, SEG1F, SEG1G, DEC1P);
	nvboard_bind_pin( &top->o_seg, 8, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G, DEC0P);
}
