/**
 Написать программу, которая считывает из текстового файла вещественные числа и
выполняет над ними некоторые вычисления:найти среднее значение чисел, расположенных между минимальным и максимальным числами («между» - не по значению, а по расположению); предполагается, что
минимум и максимум один.
*/

#include <stdio.h>
#include "num_processing.h"

void print_errors(status_codes code)
{
    if (code == file_not_transferred)
        fprintf(stdout, "File wasn't transferred");
    else if (code == too_few_numbers)
        fprintf(stdout, "Please, input more numbers");
    else if (code == too_much_maximums)
        fprintf(stdout, "There were too much same maximums in this file");
    else if (code == same_min_max)
        fprintf(stdout, "Min and max numbers are identical");
    else if (code == no_numbers_between_min_and_max)
        fprintf(stdout, "Please, input other numbers between min and max");
}

int main(int argc, char **argv)
{
    status_codes code = ok;
    FILE *f;

    if (argc != 2)
        code = file_not_transferred;
    else
        f = fopen(argv[1], "r");

    double min = 1000000;
    double max = -1000000;

    if (code == ok)
        find_min_and_max_number(f, &code, &min, &max);

    double sr_arifm = 0;
    if (code == ok)
    {
        rewind(f);
        sr_arifm = find_average(f, &code, min, max);
    }

    if (code != file_not_transferred)
        fclose(f);

    if (code == ok)
        fprintf(stdout, "The average is %lf", sr_arifm);
    else
        print_errors(code);
    return code;
}