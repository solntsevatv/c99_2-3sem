#include "../inc/const_errors.h"
#include "../inc/arr_lib.h"

void fill_fibonacci(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i >= 3)
            array[i] = array[i - 1] + array[i - 2];
        else if (i == 2 || i == 1)
            array[i] = 1;
        else
            array[i] = 0;
    }
}

boolean find_num(int num, int *array, int size)
{
    boolean result = false;

    for (int i = 0; i < size && !result; i++)
        if (array[i] == num)
            result = true;
    
    return result;
}

int transfer_nums(int *array_1, int *array_2, int size)
{
    int ind = 0;
    for (int i = 0; i < size; i++)
    {
        if (!find_num(array_1[i], array_2, ind))
        {
            array_2[ind] = array_1[i];
            ind++;
        }
    }
    return ind;
}