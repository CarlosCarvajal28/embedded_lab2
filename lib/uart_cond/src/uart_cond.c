#include "uart_cond.h"

void echo_uppercase_conditional(const struct device *dev)
{
    char byte, up;

    do {
        // Get Input
        #ifdef TESTING_ENV
        test_uart_in(&byte);
        #else
        if (uart_poll_in(dev, &byte) != 0) {
            continue;
        }
        #endif

        // Make uppercase
        if (byte <= 'z' && byte >= 'a')
            up = byte - 'a' + 'A';
        else
            up = byte;

        // Set Output
        #ifdef TESTING_ENV
        test_uart_out(up);
        #else
        uart_poll_out(dev, up);
        #endif

    } while(byte != '\n');
}