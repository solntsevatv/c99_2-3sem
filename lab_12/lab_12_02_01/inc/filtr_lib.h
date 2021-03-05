#ifndef _FILTR_LIB_H_
#define _FILTR_LIB_H_

int calc_filtered_size(const int *begin, const int *end);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif