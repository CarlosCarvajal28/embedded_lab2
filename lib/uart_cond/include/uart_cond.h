#pragma once

#ifdef TESTING_ENV
    void test_uart_in(char *byte);
    void test_uart_out(char up);
    struct device {};
#else
    #include <drivers/uart.h>
#endif

void echo_uppercase_conditional(const struct device *dev);
