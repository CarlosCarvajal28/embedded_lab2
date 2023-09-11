#pragma once

#ifdef TESTING_ENV
    test_uart_in();
    test_uart_out();
struct device {};
#else
    uart_poll_in();
    uart_poll_out();
#include <drivers/uart.h>
#endif

void echo_uppercase(const struct device *dev);