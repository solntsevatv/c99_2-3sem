#ifndef _INPUT_OUTPUT_H_
#define _INPUT_OUTPUT_H_

#include "const_errors.h"

FILE *check_input(int argc, status_codes *code, char **argv);
int count_elements(FILE *f);
status_codes create_array(int **array, int arr_size);
void read_array(int *array_start, int *array_end, FILE *f);
void print_array(FILE *f, int *array_start, int *array_end);

#endif