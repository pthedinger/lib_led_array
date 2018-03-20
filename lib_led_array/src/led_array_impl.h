//-----------------------------------------------------------
#ifndef __lib_led_array_impl_h__
#define __lib_led_array_impl_h__

#ifdef __XC__
extern "C" {
#endif

/*** Internal state required by the neopixel array
 */
typedef struct led_array_state_impl_t {
    int num_cols;
    int num_rows;
    int *pixel_data;
} led_array_state_impl_t;

/* A compile-time assertion that a constant expression is true
 * Note we need the 2 concats below because arguments to ##
 * are not expanded, so we need to expand __LINE__ with one indirection
 * before doing the actual concatenation.
 * From: http://www.pixelbeat.org/programming/gcc/static_assert.html
 */
#define ASSERT_CONCAT_(a, b) a##b
#define ASSERT_CONCAT(a, b) ASSERT_CONCAT_(a, b)
#define compile_time_assert(e) enum { ASSERT_CONCAT(assert_line_, __LINE__) = 1/(!!(e)) }

#ifdef __XC__
} // extern 'C'
#endif

#endif // __lib_led_array_impl_h__
