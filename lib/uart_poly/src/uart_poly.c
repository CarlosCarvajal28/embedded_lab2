#include "uart_poly.h"

void echo_uppercase_ptr(const struct device *dev,
                        int (*uart_in)(const struct device *, char *),
                        void (*uart_out)(const struct device *, char))
{
    char byte, up;

    do {
        // Get Input
        if (uart_in(dev, &byte) != 0) {
            continue;
        }

        // Make uppercase
        if (byte <= 'z' && byte >= 'a')
            up = byte - 'a' + 'A';
        else
            up = byte;

        // Set Output
        uart_out(dev, up);
    } while(byte != '\n');
}