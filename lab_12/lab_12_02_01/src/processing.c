#include "../inc/processing.h"
#include <stdlib.h>

status_codes create_array(int **array, int arr_size)
{
    status_codes code = ok;
    *array = malloc(arr_size * sizeof(int));
    if (*array == NULL)
        code = memory_error;
    return code;
}

int count_elements(FILE *f)
{
    int array_size = 0, num;
    while (fscanf(f, "%d", &num) == 1)
        array_size += 1;
    return array_size;
}

int cmp_int_elems(const int *elem_1, const int *elem_2)
{
    return *elem_1 - *elem_2;
}

void assign(void *elem_1, void *elem_2, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        *((char*) elem_1 + i) = *((char*) elem_2 + i);
    }
}

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    char *arr_location, *new_elem = base;
    char new_elem_num[size + 1];
    for (size_t i = 1; i < num; i++)
    {
        new_elem += size;
        assign(new_elem_num, new_elem, size);
        arr_location = new_elem - size;
        while (arr_location >= (char *) base && compare(arr_location, new_elem_num) > 0)
        {
            assign(arr_location + size, arr_location, size);
            arr_location -= size;
        }
        assign(arr_location + size, new_elem_num, size);
    }
}