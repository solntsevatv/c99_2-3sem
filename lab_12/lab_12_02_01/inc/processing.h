#ifndef _PROCESSING_H_
#define _PROCESSING_H_

#include "const_errors.h"

int count_elements(FILE *f);
status_codes create_array(int **array, int arr_size);
int cmp_int_elems(const int *elem_1, const int *elem_2);
void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif