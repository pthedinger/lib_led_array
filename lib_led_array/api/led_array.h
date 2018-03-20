//-----------------------------------------------------------
#ifndef __led_array_h__
#define __led_array_h__

#include <stdint.h>
#include <stddef.h>

#ifdef __XC__
extern "C" {
#endif


/* Opaque type for the user state required by the led array */
typedef void * led_array_state_t;

/* This define needs to be kept in sync with the internal structure defined
 * in the led_array_impl.h
 */
#define LED_ARRAY_STATE_WORDS 3

typedef struct pixel_t {
    int r;
    int g;
    int b;
} pixel_t;

void led_array_init(
    led_array_state_t *state,
    int num_cols,
    int num_rows,
    int *pixel_data);

void led_array_reset_pixels(
    led_array_state_t *s);

void led_array_get_pixel_values(
    led_array_state_t *state,
    int *pixels);

void led_array_change_pixel_rgb(
    led_array_state_t *state,
    size_t pixel_index,
    int delta_r,
    int delta_g,
    int delta_b);

#define LED_PIXEL_DATA_WORDS(NUM_COLS, NUM_ROWS) ((sizeof(pixel_t) * (NUM_COLS) * (NUM_ROWS)) / 4)

#ifdef __XC__
} // extern 'C'
#endif

#endif // __led_array_h__
