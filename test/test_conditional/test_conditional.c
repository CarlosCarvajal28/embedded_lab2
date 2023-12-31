#include <stdio.h>
#include <unity.h>
#include "uart_cond.h"

char *TEST_IN = "Hello World!\n";
char *TEST_OUT = "HELLO WORLD!\n";

char *mock_uart_in;
char *mock_uart_out;

void test_uart_in(char *byte)
{
    // byte is an output, so set the output and increment our input string.
    *byte = *mock_uart_in;
    if (*mock_uart_in == '\n')
    {
        mock_uart_in = TEST_IN;
    }
    else
    {
        mock_uart_in++;
    }
}

void test_uart_out(char up)
{
    TEST_ASSERT_EQUAL_CHAR(*mock_uart_out++, up);
}

void test_echo_cond()
{
    // pass in struct, initializing everything to 0
    echo_uppercase_conditional((struct device *) 0);
}

void setUp(void)
{
    mock_uart_in = TEST_IN;
    mock_uart_out = TEST_OUT;
}

void tearDown(void) {}

int main (void)
{
    UNITY_BEGIN();

    RUN_TEST(test_echo_cond);

    return UNITY_END();
}