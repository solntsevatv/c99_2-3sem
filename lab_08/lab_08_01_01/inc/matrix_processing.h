#ifndef _MATRIX_PROCESSING_H_
#define _MATRIX_PROCESSING_H_

#include "const_errors.h"

void create_matrix(struct matrix *matr, int rows, int cols, status_codes *code);
void del_str_cols_in_matrix(struct matrix *matrix);
int max(int el_1, int el_2);
int **multiply_matr(struct matrix *matr_1, struct matrix *matr_2, status_codes *code);
void exponentiation_matrix(struct matrix *matrix_source, struct matrix *matrix_res, int pow, status_codes *code);
void fill_matrix_with_ones(struct matrix *matrix);
void copy_matrix(struct matrix *matrix_source, struct matrix *matrix_res);
void add_str_cols_to_matrix(int orig_n, int size, int **matrix);
void init_matrix(struct matrix *matrix);
void clean_struct_matrix(struct matrix *matrix);

#endif