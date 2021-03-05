#include <stdio.h>

typedef enum
{
    ok,
    file_not_transferred,
    too_few_numbers,
    too_much_maximums,
    same_min_max,
    no_numbers_between_min_and_max,
} status_codes;

void find_min_and_max_number(FILE *f, status_codes *code, double *min, double *max);
double find_average(FILE *f, status_codes *code, double min, double max);
