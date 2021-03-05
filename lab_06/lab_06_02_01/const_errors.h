#ifndef _CONST_ERRORS_H_
#define _CONST_ERRORS_H_

#include <stdio.h>
#include <string.h>
#define MAX_NAME_LEN 25
#define MAX_ARR_LEN 15

struct thing
{
    char name[MAX_NAME_LEN + 1];
    double weight;
    double size;
};

typedef enum
{
    ok,
    file_not_transferred,
    reading_error,
    incorrect_data,
    size_error,
    incorrect_input,
    empty_output,
} status_codes;

#endif
