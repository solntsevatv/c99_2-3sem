#ifndef _CONST_ERRORS_H_
#define _CONST_ERRORS_H_

#include <stdio.h>
#include <string.h>

typedef enum
{
    ok,
    reading_count_error,
    reading_matrix_error,
    memory_error,
} status_codes;

struct matrix
{
    int **matrix;
    int *start_matrix;
    int rows;
    int cols;
};


#endif