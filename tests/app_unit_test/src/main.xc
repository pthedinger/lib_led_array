#include "unity.h"
#include "led_array.h"

#define num_cols 10
#define num_rows 10

int main()
{
    /* Must have static state declarations */
    int s[LED_ARRAY_STATE_WORDS];
    int pixel_data[LED_PIXEL_DATA_WORDS(num_cols, num_rows)];

    unsafe {
        led_array_state_t * unsafe state = (led_array_state_t * unsafe)s;

        led_array_init(state, num_cols, num_rows, pixel_data);

        led_array_change_pixel_rgb(state, 0, 10, 10, -10);

        int result[LED_PIXEL_DATA_WORDS(num_cols, num_rows)];
        led_array_get_pixel_values(state, result);

        for (int i = 0; i < (num_cols * num_rows); ++i) {
            printf("%d: %d\n", i, result[i]);
        }
    }

    return 0;
}
