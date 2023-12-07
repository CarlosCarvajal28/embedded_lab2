#include <stdint.h>
#include <unity.h>
#include "map.h"
#include <stdio.h>

void setUp(void) {}

void tearDown(void) {}

int add5(int x)
{
    return x + 5;
}


void test_map(void)
{
    printf("Made it to test_map");

    int input[4] = {2, 4, 6, 8};
    int output[4];
    map(&input[0], &output[0], 4, add5);
    int expected[4] = {7, 9, 11, 13};

    TEST_ASSERT_EQUAL_INT_ARRAY(output, expected, 4);
}

int main (void)
{
    UNITY_BEGIN();
    RUN_TEST(test_map);
    return UNITY_END();
}
