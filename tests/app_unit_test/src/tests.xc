#include "unity.h"
#include "led_array.h"

#define num_cols 3
#define num_rows 3

void test_change_pixel_rgb()
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

        int expected[LED_PIXEL_DATA_WORDS(num_cols, num_rows)] = {
            10, 10, -10, 0, 0, 0, 0, 0, 0,
             0,  0,   0, 0, 0, 0, 0, 0, 0,
             0,  0,   0, 0, 0, 0, 0, 0, 0
         };

         TEST_ASSERT_EQUAL_INT32_ARRAY(
            (int*)result,
            (int*)expected,
            LED_PIXEL_DATA_WORDS(num_cols, num_rows));
    }
}
