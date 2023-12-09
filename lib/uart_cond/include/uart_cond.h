#pragma once

#ifndef TESTING_ENV
    #include <drivers/uart.h>
#else
void test_uart_in(char *byte);
void test_uart_out(char up);
struct device {};
#endif

void echo_uppercase_conditional(const struct device *dev);
