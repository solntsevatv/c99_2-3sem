#include "../inc/const_errors.h"
#include <stdlib.h>

int calc_filtered_size(const int *begin, const int *end)
{
    int size = 0;

    while (begin < end && *begin >= 0)
    {
        begin++;
        size++;
    }

    return size;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int code = 0;
    if (pb_src == NULL || pe_src == NULL)
        code = 1;
    else
    {
        int size_filtred_arr = calc_filtered_size(pb_src, pe_src);
        if (size_filtred_arr == 0)
            code = 1;

        if (code == 0)
        {
            *pb_dst = malloc(size_filtred_arr * sizeof(int));

            if (*pb_dst != NULL)
            {
                *pe_dst = *pb_dst;
                for (const int *iter = pb_src; iter != pb_src + size_filtred_arr; iter++, (*pe_dst)++)
                    **pe_dst = *iter;
            }
            else
                code = 1;
        }
    }

    return code;
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