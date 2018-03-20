#include <string.h>
#include "led_array.h"
#include "led_array_impl.h"

void led_array_init(
    led_array_state_t *s,
    int num_cols,
    int num_rows,
    int *pixel_data)
{
    // NEO_STATE_WORDS used to allocate enough space for the structure
    compile_time_assert(sizeof(led_array_state_impl_t)==(LED_ARRAY_STATE_WORDS*4));

    led_array_state_impl_t *state = (led_array_state_impl_t *)s;

    state->num_cols = num_cols;
    state->num_rows = num_rows;
    state->pixel_data = pixel_data;

    led_array_reset_pixels(s);
}

void led_array_reset_pixels(
    led_array_state_t *s)
{
    led_array_state_impl_t *state = (led_array_state_impl_t *)s;
    bzero(state->pixel_data, sizeof(pixel_t) * state->num_cols * state->num_rows);
}

void led_array_get_pixel_values(
    led_array_state_t *s,
    int *pixels)
{
    led_array_state_impl_t *state = (led_array_state_impl_t *)s;
    memcpy(pixels, state->pixel_data, sizeof(pixel_t) * state->num_cols * state->num_rows);
}

void led_array_change_pixel_rgb(
    led_array_state_t *s,
    size_t pixel_index,
    int delta_r,
    int delta_g,
    int delta_b)
{
    led_array_state_impl_t *state = (led_array_state_impl_t *)s;
    pixel_t *pixels = (pixel_t*)state->pixel_data;
    pixels[pixel_index].r += delta_r;
    pixels[pixel_index].g += delta_g;
    pixels[pixel_index].b += delta_b;
}
