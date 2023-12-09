#include "uart_hello.h"

void echo_uppercase(const struct device *dev)
{
    char byte, up;

    do {
        // Get Input
        if (uart_poll_in(dev, &byte) != 0) {
            continue;
        }

        // Make uppercase
        if (byte <= 'z' && byte >= 'a')
            up = byte - 'a' + 'A';
        else
            up = byte;

        // Set Output
        uart_poll_out(dev, up);
    } while(byte != '\n');
}