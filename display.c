#include "display.h"
#include "display_core.h"


/**
 *
 */
void display_init(const struct display_t * const display)
{
        display->init();
}


/**
 * @brief Write string to display
 */
void
display_write_string(const struct display_t * const display,
                     const char * const ch)
{
	if ('\0' != *ch) {
		display_write_char(display, *ch);
		display_write_string(display, ch + 1);
	}
}


/**
 * Clear display
 */
void clear_display(const struct display_t * const display)
{
        exec_command(display, 0x1);
}
