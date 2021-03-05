#ifndef _CONST_ERRORS_H_
#define _CONST_ERRORS_H_
#define INIT_SIZE 5

#include <stdio.h>
#include <string.h>

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
    incorrect_data,
} status_codes;

#endif