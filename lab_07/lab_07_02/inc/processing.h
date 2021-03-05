#ifndef _PROCESSING_H_
#define _PROCESSING_H_

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
int cmp_int_elems(const int *elem_1, const int *elem_2);
void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif