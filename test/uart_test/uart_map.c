#include "map.h"


#define TESTING_ENV 1

void test_uart_in(const struct device *dev, char *byte)
{
    byte = dev->uart_in;
    byte++;
}

void test_uart_out(const struct device *dev, char up)
{
    dev->uart_out = up;
}