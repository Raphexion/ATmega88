#include <avr/io.h>
#include <util/delay.h>

#include "display.h"

static void init(void)
{
        DDRC |= 0b00111100;
        DDRD |= 0b11100011;
        DDRB |= 0b00000001;
}


// C5 - PIN 28
static void d7_set(void)   { PORTC |= (1 << 5); }
static void d7_reset(void) { PORTC &= ~(1 << 5); }

// C4 - PIN 27
static void d6_set(void)   { PORTC |= (1 << 4); }
static void d6_reset(void) { PORTC &= ~(1 << 4); }

// C3 - PIN 26
static void d5_set(void)   { PORTC |= (1 << 3); }
static void d5_reset(void) { PORTC &= ~(1 << 3); }

// C2 - PIN 25
static void d4_set(void)   { PORTC |= (1 << 2); }
static void d4_reset(void) { PORTC &= ~(1 << 2); }


// D5 - PIN 11
static void d3_set(void)   { PORTD |= (1 << 5); }
static void d3_reset(void) { PORTD &= ~(1 << 5); }

// D6 - PIN 12
static void d2_set(void)   { PORTD |= (1 << 6); }
static void d2_reset(void) { PORTD &= ~(1 << 6); }

// D7 - PIN 13
static void d1_set(void)   { PORTD |= (1 << 7); }
static void d1_reset(void) { PORTD &= ~(1 << 7); }


// B0 - PIN 14
static void d0_set(void)   { PORTB |= (1 << 0); }
static void d0_reset(void) { PORTB &= ~(1 << 0); }


// D0 - PIN 2
static void register_set(void)   { PORTD |= (1 << 0); }
static void register_reset(void) { PORTD &= ~(1 << 0); }


// D1 - PIN 3
static void enable_set(void)   { PORTD |= (1 << 1); }
static void enable_reset(void) { PORTD &= ~(1 << 1); }



static void delay(void) { _delay_ms(1000); }

static struct display_t my_display = {
        .init = init,
        .data_pins = {
                { .set = d0_set, .reset = d0_reset },
                { .set = d1_set, .reset = d1_reset },
                { .set = d2_set, .reset = d2_reset },
                { .set = d3_set, .reset = d3_reset },

                { .set = d4_set, .reset = d4_reset },
                { .set = d5_set, .reset = d5_reset },
                { .set = d6_set, .reset = d6_reset },
                { .set = d7_set, .reset = d7_reset }},
        .enable = {
                .set = enable_set, .reset = enable_reset},
        .register_select = {
                .set = register_set, .reset = register_reset},
        .delay = delay,
};


const struct display_t *
get_avr_display(void)
{
        return &my_display;
}
