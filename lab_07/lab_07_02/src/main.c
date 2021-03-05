#include <stdio.h>
#include <stdlib.h>
#include "../inc/const_errors.h"
#include "../inc/input_output.h"
#include "../inc/processing.h"

int main(int argc, char **argv)
{
    status_codes code = ok;
    FILE *f;
    int *array = NULL, *filtred_arr_b = NULL, *filtred_arr_e = NULL;;
    int arr_size;

    // input
    f = check_input(argc, &code, argv);
    if (code == ok)
    {
        arr_size = count_elements(f);
        if (arr_size <= 0)
            code = reading_error;
        else
            code = create_array(&array, arr_size);
        if (code == ok)
        {
            rewind(f);
            read_array(array, array + arr_size, f);
        }
        fclose(f);
    }

    // processing
    if (argc == 4 && code == ok)
    {
        code = key(array, array + arr_size, &filtred_arr_b, &filtred_arr_e);
        arr_size = filtred_arr_e - filtred_arr_b;
    }
    if (code == ok && arr_size > 0)
        mysort(array, arr_size, sizeof(int), (int(*)(const void *, const void *)) cmp_int_elems);
    else if (code == ok && arr_size <= 0)
        code = empty_output;

    // output
    if (code == ok)
    {
        f = fopen(argv[2], "w");
        print_array(f, array, array + arr_size);
        fclose(f);
    }

    // memory cleaning
    if (array != NULL)
        free(array);
    if (filtred_arr_b != NULL)
        free(filtred_arr_b);

    return code;
}