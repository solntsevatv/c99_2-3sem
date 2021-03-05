#include "../inc/matrix_processing.h"
#include <stdlib.h>
#include <math.h>
#define STRING 0
#define COLUMN 1

void create_matrix(struct matrix *matr, int rows, int cols, status_codes *code)
{
    int **ptrs = NULL, *matrix = NULL;

    matr->rows = rows;
    matr->cols = cols;

    ptrs = malloc(matr->rows * sizeof(int*));
    if (ptrs == NULL)
        *code = memory_error;
    else
    {
        matrix = malloc(matr->rows * matr->cols * sizeof(int));
        if (matrix == NULL)
        {
            *code = memory_error;
            free(ptrs);
        }
        else
        {
            for (int i = 0; i < matr->rows; i++)
                ptrs[i] = matrix + i * matr->cols;
            
            matr->matrix = ptrs;
            matr->start_matrix = ptrs[0];
        }
    }
}

int ind_for_max_el(struct matrix *matr, int flag)
{
    int max_el = matr->matrix[0][0], str_ind = 0, col_ind = 0;
    int result_ind = 0;
    for (int i = 0; i < matr->rows; i++)
        for (int j = 0; j < matr->cols; j++)
        {
            if (matr->matrix[i][j] > max_el)
            {
                max_el = matr->matrix[i][j];
                str_ind = i;
                col_ind = j;
            }
        }
    
    if (flag == STRING)
        result_ind = str_ind;
    else if (flag == COLUMN)
        result_ind = col_ind;
    
    return result_ind;
}

int find_average_in_col(int n, int ind, int **matrix) 
{
    float average = 0;
    for (int i = 0; i < n; i++)
        average += matrix[i][ind];
    average /= (float) n;
    return floor(average);
}

int find_max_in_str(int n, int ind, int **matrix)
{
    int max_el = matrix[ind][0];
    for (int i = 0; i < n; i++)
        max_el = max(max_el, matrix[ind][i]);
    return max_el;
}

void del_str_in_matrix(struct matrix *matr)
{
    int ind_str_to_del = ind_for_max_el(matr, STRING);
    for (int i = ind_str_to_del; i < matr->rows - 1; i++)
        matr->matrix[i] = matr->matrix[i + 1];
}

void del_col_in_matrix(struct matrix *matr)
{
    int ind_col_to_del = ind_for_max_el(matr, COLUMN);
    for (int i = 0; i < matr->rows; i++)
    {
        for (int j = ind_col_to_del; j < matr->cols - 1; j++)
            matr->matrix[i][j] = matr->matrix[i][j + 1];
    }
}

void del_str_cols_in_matrix(struct matrix *matrix)
{
    int n = 0;
    if (matrix->rows > matrix->cols)
    {
        n = matrix->rows - matrix->cols;
        for (int i = 0; i < n; i++)
        {
            del_str_in_matrix(matrix);
            matrix->rows = matrix->rows - 1;
        }
    }
    else if (matrix->rows < matrix->cols)
    {
        n = matrix->cols - matrix->rows;
        for (int i = 0; i < n; i++)
        {
            del_col_in_matrix(matrix);
            matrix->cols = matrix->cols - 1;
        }
    }
}

void add_str_cols_to_matrix(int orig_n, int size, int **matrix)
{
    for (int j = orig_n; j < size; j++)
        for (int i = 0; i < orig_n; i++)
            matrix[j][i] = find_average_in_col(orig_n, i, matrix);

    for (int j = orig_n; j < size; j++)
        for (int i = 0; i < size; i++)
            matrix[i][j] = find_max_in_str(orig_n, i, matrix);
}


void fill_matrix_with_ones(struct matrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->cols; j++)
        {
            if (i == j)
                matrix->matrix[i][j] = 1;
            else
                matrix->matrix[i][j] = 0;
        }
}

int get_multipl_elem(struct matrix *matrix_1, struct matrix *matrix_2, int str_ind, int col_ind)
{
    int result_elem = 0;
    for (int i = 0; i < matrix_2->rows; i++)
        result_elem += matrix_1->matrix[str_ind][i] * matrix_2->matrix[i][col_ind];
    return result_elem;
}

int **multiply_matr(struct matrix *matr_1, struct matrix *matr_2, status_codes *code)
{
    struct matrix matrix_res;
    init_matrix(&matrix_res);
    create_matrix(&matrix_res, matr_2->rows, matr_2->rows, code);

    if (*code == ok)
    {
        for (int i = 0; i < matr_2->rows; i++)
        {
            for (int j = 0; j < matr_2->rows; j++)
                matrix_res.matrix[i][j] = get_multipl_elem(matr_1, matr_2, i, j);
        }
        copy_matrix(&matrix_res, matr_1);
    }

    clean_struct_matrix(&matrix_res);

    return matr_1->matrix;
}

void exponentiation_matrix(struct matrix *matrix_source, struct matrix *matrix_res, int pow, status_codes *code)
{
    if (pow == 0)
        fill_matrix_with_ones(matrix_source);
    copy_matrix(matrix_source, matrix_res);
    for (int k = 0; k < pow - 1 && *code == ok; k++)
        matrix_res->matrix = multiply_matr(matrix_res, matrix_source, code);
}

void copy_matrix(struct matrix *matrix_source, struct matrix *matrix_res)
{
    for (int i = 0; i < matrix_source->rows; i++)
    {
        for (int j = 0; j < matrix_source->cols; j++)
            matrix_res->matrix[i][j] = matrix_source->matrix[i][j];
    }
}

void init_matrix(struct matrix *matrix)
{
    matrix->matrix = NULL;
    matrix->start_matrix = NULL;
    matrix->rows = 0;
    matrix->cols = 0;
}

void clean_struct_matrix(struct matrix *matrix)
{
    if (matrix->matrix != NULL)
    {
        free(matrix->start_matrix);
        free(matrix->matrix);
    }
}