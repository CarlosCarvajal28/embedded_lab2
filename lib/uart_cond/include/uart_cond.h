#pragma once

#ifdef TESTING_ENV
    void test_uart_in(const struct mock_device *dev, char *byte);
    void test_uart_out(struct mock_device *dev, char up);
    struct mock_device {
        char uart_in;
        char uart_out;
    };
#else
    #include <drivers/uart.h>
    
    char uart_poll_in(const struct device *dev, char *byte);
    char uart_poll_out(const struct device *dev, char *byte);
#endif

void echo_uppercase(const struct device *dev);