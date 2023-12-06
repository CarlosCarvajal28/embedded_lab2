#include <stdio.h>
#include <unity.h>
#include "uart_poly.h"


char *TEST_IN = "Hello World!\n";
char *TEST_OUT = "HELLO WORLD!\n";

char *mock_uart_in;
char *mock_uart_out;

int test_uart_in( const struct device* dev, char *byte)
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
    return 0;
}

void test_uart_out(const struct device *dev, char up)
{
    *mock_uart_out = up;
    mock_uart_out++;
}

void test_echo_ptr()
{
    // pass in struct, initializing everything to 0
    echo_uppercase_ptr((struct device *) 0, test_uart_in, test_uart_out);
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

    RUN_TEST(test_echo_ptr);

    return UNITY_END();
}