#ifndef _CONST_ERRORS_H_
#define _CONST_ERRORS_H_

#define STR_SIZE 30

typedef enum
{
    ok,
    memory_error,
    reading_arg_error,
    incorrect_data,
    empty_string,
    row_not_found,
} status_codes;

typedef enum
{
    false,
    true,
} boolean;

#endif