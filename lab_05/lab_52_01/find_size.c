#include <stdio.h>
#include "my_functions.h"

int file_size(FILE *f, size_t *size)
{
    long sz = 0;
    int code = 0;
    if (fseek(f, 0L, SEEK_END))
        code = 1;
    else
        sz = ftell(f);
    *size = sz;
    if (sz < 0)
        code = 1;
    else
        code = fseek(f, 0L, SEEK_SET);
    return code;
}

size_t count_students(FILE *f, status_codes *code)
{
    size_t size = 0;
    if (file_size(f, &size) != 0 || size % sizeof(struct student) != 0)
        *code = size_error;
    return size / sizeof(struct student);
}