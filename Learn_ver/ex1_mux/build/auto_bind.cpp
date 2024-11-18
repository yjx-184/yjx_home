#include <nvboard.h>
#include "Vmy_mux41.h"

void nvboard_bind_all_pins(Vmy_mux41* top) {
	nvboard_bind_pin( &top->Y, 2, SW1, SW0);
	nvboard_bind_pin( &top->X0, 2, SW3, SW2);
	nvboard_bind_pin( &top->X1, 2, SW5, SW4);
	nvboard_bind_pin( &top->X2, 2, SW7, SW6);
	nvboard_bind_pin( &top->X3, 2, SW9, SW8);
	nvboard_bind_pin( &top->F, 2, LD1, LD0);
}
