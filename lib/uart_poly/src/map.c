#include "map.h"

void map(int* input, int* output, const int length, int (*func)(int))
{
    for(int i = 0; i < length; i++)
    {
        output[i] = func(input[i]);
    }
}