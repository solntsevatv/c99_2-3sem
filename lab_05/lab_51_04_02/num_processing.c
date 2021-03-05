#include <stdio.h>
#include <math.h>
#include "num_processing.h"

void find_min_and_max_number(FILE *f, status_codes *code, double *min, double *max)
{
    double current_num = 0, eps = 1e-6;
    for (int i = 0; i < 3; i++)
    {
        if (fscanf(f, "%lf", &current_num) == 1)
        {
            if (current_num > *max)
                *max = current_num;
            if (current_num < *min)
                *min = current_num;
        }
        else
        {
            *code = too_few_numbers;
            break;
        }
    }
    if (*code == ok)
    {
        while (fscanf(f, "%lf", &current_num) == 1)
        {
            if (current_num > *max)
            {
                *max = current_num;
                *code = ok;
            }
            else if (current_num < *min)
            {
                *min = current_num;
                *code = ok;
            }
            else if (fabs(current_num - *max) < eps)
                *code = too_much_maximums;
        }
    }
    if (fabs(*max - *min) < eps)
        *code = same_min_max;
}

double find_average(FILE *f, status_codes *code, double min, double max)
{
    double num, eps = 1e-6;
    while (fscanf(f, "%lf", &num) == 1)
        if (fabs(num - min) < eps || fabs(num - max) < eps)
            break;
    int count = 0;
    double sum = 0;
    while (fscanf(f, "%lf", &num) == 1 && fabs(num - min) > eps && fabs(num - max) > eps)
    {
        sum += num;
        count += 1;
    }
    if (count == 0)
        *code = no_numbers_between_min_and_max;
    else
        sum = sum / count;
    return sum;
}