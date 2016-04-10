#ifndef DISPLAY_H
#define DISPLAY_H


typedef void (* display_action) (void);


/**
 * Most actions come in pairs
 */
struct set_reset_pair {
        const display_action set;
        const display_action reset;
};


/**
 * Abstraction over underlying hardware
 * and pins
 */
struct display_t {
        const display_action init;

        const struct set_reset_pair data_pins[8];

        const struct set_reset_pair enable;
        const struct set_reset_pair register_select;

        const display_action delay;

};


/**
 *
 */
void display_init(const struct display_t * const display);

/**
 * @brief Write a string to the display
 */
void display_write_string(const struct display_t * const display,
                          const char * const ch);


/**
 * @brief Clears the display
 */
void
clear_display(const struct display_t * const display);


#endif
