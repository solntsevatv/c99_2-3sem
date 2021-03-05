#include "../inc/output_lib.h"

void print_array(FILE *f, int *array_start, int *array_end)
{
    while (array_start < array_end)
    {
        fprintf(f, "%d ", *array_start);
        array_start++;
    }
}