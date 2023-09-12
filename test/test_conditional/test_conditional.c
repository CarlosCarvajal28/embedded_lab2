#include <stdio.h>
#include <unity.h>
#include "uart_cond.h"

#define TESTING_ENV 1

struct mock_device glbl_dev;
char *TEST_STRING = "HelloWorld!\n";

void test_uart_in(const struct mock_device *dev, char *byte)
{
    byte = dev->uart_in;
    byte++;
}

void test_uart_out(struct mock_device *dev, char up)
{
    dev->uart_out = up;
}

void setUp(void) 
{
}

void tearDown(void) {}

int main (void)
{
    UNITY_BEGIN();
    // todo: use TEST_STRING  instead of single character

    glbl_dev.uart_in = 'c';
    char byte = '1';
    RUN_TEST(test_uart_in(glbl_dev, &byte));
    TEST_ASSERT_EQUAL_CHAR(byte, 'c');

    RUN_TEST(test_uart_out(glbl_dev, byte));
    TEST_ASSERT_EQUAL_CHAR(glbl_dev0->uart_out, 'c');

    return UNITY_END();
}