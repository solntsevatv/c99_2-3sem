#ifndef _CONST_ERRORS_H_
#define _CONST_ERRORS_H_
#define INIT_SIZE 5

#include <stdio.h>
#include <string.h>

struct thing
{
    char *name;
    double weight;
    double size;
};

struct dyn_arr_objects
{
    struct thing *objects;
    int len;
    int allocated;
    int step;
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
    memory_error,
} status_codes;

#endif
