#include "unity.h"
#include "tests.h"

void setUp(void){}
void tearDown(void){}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_change_pixel_rgb);

    return UNITY_END();
}
