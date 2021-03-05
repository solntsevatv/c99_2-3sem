#include "../inc/const_errors.h"
#include "../inc/filtr_lib.h"

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
    int code = ok;
    if (pb_src == NULL || pe_src == NULL)
        code = filtring_error;
    else
    {
        int size_filtred_arr = calc_filtered_size(pb_src, pe_src);
        if (size_filtred_arr == 0)
            code = filtring_error;

        if (code == 0)
        {
            if (*pb_dst != NULL)
            {
                *pe_dst = *pb_dst;
                for (const int *iter = pb_src; iter != pb_src + size_filtred_arr; iter++, (*pe_dst)++)
                    **pe_dst = *iter;
            }
            else
                code = filtring_error;
        }
    }

    return code;
}