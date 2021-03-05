#ifndef _INPUT_LIB_H_
#define _INPUT_LIB_H_

#include <stdio.h>
#include "const_errors.h"

FILE *check_input(int argc, status_codes *code, char **argv);
void read_array(int *array_start, int *array_end, FILE *f);

#endif