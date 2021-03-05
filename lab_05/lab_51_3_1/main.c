#include <stdio.h>
#include "num_processing.h"

int main(void)
{
    status_codes code = ok;
    int count = changing_sign_count(stdin, &code);
    if (code == ok)
        fprintf(stdout, "The number of sign changes is %d", count);
    else if (code == empty_file)
        fprintf(stdout, "Empty input!");
    else if (code == one_number)
        fprintf(stdout, "Input more numbers!");
    return code;
}