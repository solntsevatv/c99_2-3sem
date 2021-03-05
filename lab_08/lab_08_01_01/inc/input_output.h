#ifndef _INPUT_OUTPUT_H_
#define _INPUT_OUTPUT_H_

#include "const_errors.h"

void read_matrix(struct matrix *matrix, status_codes *code);
void print_matrix(struct matrix matrix);

#endif