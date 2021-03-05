#ifndef _CONST_ERRORS_H_
#define _CONST_ERRORS_H_

#define SUBSTR_SIZE 4
#define ARG_SIZE 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

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