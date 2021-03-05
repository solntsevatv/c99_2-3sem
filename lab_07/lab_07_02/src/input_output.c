#include "../inc/const_errors.h"
#include "../inc/input_output.h"
#include <stdlib.h>
#include <stdio.h>

FILE *check_input(int argc, status_codes *code, char **argv)
{
    FILE *f = NULL;
    if (argc == 4 && (argv[3][0] != 'f' || argv[3][1] != '\0'))
        *code = incorrect_input;
    else if (argc == 3 || argc == 4)
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
            *code = file_error;
    }
    else
        *code = incorrect_input;
    return f;
}

int count_elements(FILE *f)
{
    int array_size = 0, num;
    while (fscanf(f, "%d", &num) == 1)
        array_size += 1;
    return array_size;
}

status_codes create_array(int **array, int arr_size)
{
    status_codes code = ok;
    *array = malloc(arr_size * sizeof(int));
    if (*array == NULL)
        code = memory_error;
    return code;
}

void read_array(int *array_start, int *array_end, FILE *f)
{
    int *array_curr = array_start;
    while (array_curr < array_end)
    {
        fscanf(f, "%d", array_curr);
        array_curr++;
    }
}

void print_array(FILE *f, int *array_start, int *array_end)
{
    while (array_start < array_end)
    {
        fprintf(f, "%d ", *array_start);
        array_start++;
    }
}