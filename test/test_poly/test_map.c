#include "map.h"

#define TESTING_ENV

void setUp(void) {}

void tearDown(void) {}

int add5(int x)
{
    return x + 5;
}


void test_map(void)
{
    const int length = 4;
    int input[length] = {2, 4, 6, 8};
    int output[length];
    map(&input[0], &output[0], length, add5);
    int expected[length] = {7, 9, 11, 13};

    TEST_ASSERT_EQUAL_INT_ARRAY(output, expected, length);
}

int main (void)
{
    UNITY_BEGIN();
    RUN_TEST(test_map);
    return UNITY_END();
}
