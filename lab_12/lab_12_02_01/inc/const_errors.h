#ifndef _CONST_ERRORS_H_
#define _CONST_ERRORS_H_

#include <stdio.h>
#include <string.h>

typedef enum
{
    ok,
    filtring_error,
    incorrect_input,
    reading_error,
    empty_output,
    memory_error,
    file_error,
    lib_error,
} status_codes;

#endif