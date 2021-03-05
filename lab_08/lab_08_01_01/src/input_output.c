#include "../inc/input_output.h"
#include "../inc/matrix_processing.h"
#include <stdio.h>
#include <stdlib.h>

void read_matrix(struct matrix *matrix, status_codes *code)
{
    int rows, cols;
    if (scanf("%d%d", &rows, &cols) != 2 || rows <= 0 || cols <= 0)
        *code = reading_count_error;
    else
        create_matrix(matrix, rows, cols, code);

    for (int i = 0; *code == ok && i < matrix->rows; i++)
    {
        for (int j = 0; *code == ok && j < matrix->cols; j++)
        {
            if (scanf("%d", &matrix->matrix[i][j]) != 1)
                *code = reading_matrix_error;
        }
    }
}

void print_matrix(struct matrix matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
            printf("%d ", matrix.matrix[i][j]);
        printf("\n");
    }
}