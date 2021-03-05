#include <stdio.h>
#include "my_functions.h"

int get_number_by_pos(FILE *f, long ind, int *sort_code)
{
    int num = 0;
    if (fseek(f, ind * sizeof(int), SEEK_SET) == 0)
        *sort_code = fread(&num, sizeof(int), 1, f);
    return num;
}

void put_number_by_pos(FILE *f, long ind, int num, int *sort_code)
{
    if (fseek(f, ind * sizeof(int), SEEK_SET) == 0)
        *sort_code = fwrite(&num, sizeof(int), 1, f);
}

void sort_numbers(FILE *f, status_codes *code)
{
    size_t left = 0, right = count_numbers(f, code);
    int swapped = 1, sort_code = 1;
    if (right == 0 && *code != ok)
        swapped = 0;
    else if (right == 0)
        *code = empty_file;
    int current_num = 0, next_num = 0;
    while (swapped == 1)
    {
        swapped = 0;

        for (size_t i = left; i < right; i++)
        {
            current_num = get_number_by_pos(f, i, &sort_code);
            if (sort_code)
                next_num = get_number_by_pos(f, i + 1, &sort_code);
            if (sort_code && current_num > next_num)
            {
                put_number_by_pos(f, i, next_num, &sort_code);
                if (sort_code)
                    put_number_by_pos(f, i + 1, current_num, &sort_code);
                swapped = 1;
            }
            else if (!sort_code)
                swapped = 1;
        }

        if (swapped == 0)
            break;

        swapped = 0;
        right--;

        for (size_t i = right; i > left; i--)
        {
            current_num = get_number_by_pos(f, i - 1, &sort_code);
            if (sort_code)
                next_num = get_number_by_pos(f, i, &sort_code);
            if (sort_code && current_num > next_num)
            {
                put_number_by_pos(f, i - 1, next_num, &sort_code);
                if (sort_code)
                    put_number_by_pos(f, i, current_num, &sort_code);
                swapped = 1;
            }
            else if (!sort_code)
                swapped = 1;
        }
        left++;
    }
}