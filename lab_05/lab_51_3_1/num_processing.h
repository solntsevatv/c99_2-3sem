#include <stdio.h>

typedef enum
{
    ok,
    empty_file,
    one_number,
} status_codes;

void check_num(int *num);
int changing_sign_count(FILE *f, status_codes *code);