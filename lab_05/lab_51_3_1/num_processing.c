#include <stdio.h>
#include <stdlib.h>
#include "num_processing.h"

void check_num(int *num)
{
    if (*num == 0)
        *num = 1;
    else
        *num = *num / abs(*num);
}

int changing_sign_count(FILE *f, status_codes *code)
{
    int previous_num, current_num = 0, count = 0;
    if (fscanf(f, "%d", &previous_num) == 1)
    {
        check_num(&previous_num);
        while (fscanf(f, "%d", &current_num) == 1)
        {
            check_num(&current_num);
            if (current_num != previous_num)
            {
                count += 1;
                previous_num = current_num;
            }
        }
        if (current_num == 0)
            *code = one_number;
    }
    else
        *code = empty_file;
    return count;
}