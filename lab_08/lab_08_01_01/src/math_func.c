#include "../inc/math_func.h"

int max(int el_1, int el_2)
{
    int max = el_1;
    if (el_2 > max)
        max = el_2;
    return max;
}