#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "display.h"
#include "avr_display.h"

static const struct display_t *display = NULL;

int main(void)
{
         display = get_avr_display();
         display_init(display);

         display_write_string(display, "Fire Monkey");

         while (1) {
         }
         return (0);
}
