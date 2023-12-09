#include <unity.h>
#include "uart_hello.h"

void setUp(){};

void tearDown(){};

void test_echo_robot(){
    echo_uppercase((const struct device*)0);
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_echo_robot);
    return UNITY_END();
}