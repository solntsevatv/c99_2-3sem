#include "../inc/input_lib.h"

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

void read_array(int *array_start, int *array_end, FILE *f)
{
    int *array_curr = array_start;
    while (array_curr < array_end)
    {
        fscanf(f, "%d", array_curr);
        array_curr++;
    }
}