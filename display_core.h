#ifndef DISPLAY_CORE_H
#define DISPLAY_CORE_H

#include "display.h"
#include <stdint.h>

static inline void
set_data_bit(const struct set_reset_pair * const data_pin,
             const uint8_t bits,
             const uint8_t pos)
{
	if (bits & (0x1 << pos))
		data_pin->set();
	else
		data_pin->reset();
}


static inline void
set_data(const struct display_t * const display,
         const uint8_t bits)
{
        for (int bit = 7; bit >= 0; bit--) {
                set_data_bit(&(display->data_pins[bit]), bits, bit);
        }
}


static inline void
display_write_char(const struct display_t * const display,
                   const char ch)
{
        // we are default in character mode
	set_data(display, ch);
	display->enable.set();
	display->delay();
	display->enable.reset();
}


static inline void
exec_command(const struct display_t * const display,
             const uint8_t command)
{
	// set the data pins
	set_data(display, command);

	// make sure the register select is logic 0
	display->register_select.reset();
	display->delay();

	// enable chip to accept the command
	display->enable.set();
	display->delay();
	display->enable.reset();

	// exit command mode
	display->register_select.set();
}



#endif // DISPLAY_CORE_H
