/*
Delete strings/columns with max element in matrix. If max element is not one, delete strings/columns
with first max element with going by strings. At first, you should always add strings, then - columns.
Add to strings average by columns, to columns - maximums by strings. 
*/

#include "../inc/const_errors.h"
#include "../inc/input_output.h"
#include "../inc/matrix_processing.h"
#include "../inc/math_func.h"

int main(void)
{
    setbuf(stdout, NULL);

    status_codes code = ok;
    struct matrix matrix_1, matrix_2;
    int pow_1, pow_2;
    struct matrix result_matrix_1, result_matrix_2, multiple_matrix;
    int size;

    //initialization
    init_matrix(&matrix_1);
    init_matrix(&matrix_2);
    init_matrix(&result_matrix_1);
    init_matrix(&result_matrix_2);
    init_matrix(&multiple_matrix);

    //input
    read_matrix(&matrix_1, &code);
    if (code == ok)
        read_matrix(&matrix_2, &code);
    if (code == ok)
        if (scanf("%d%d", &pow_1, &pow_2) != 2 || pow_1 < 0 || pow_2 < 0)
            code = reading_count_error;
    
    //processing
    if (code == ok)
    {
        del_str_cols_in_matrix(&matrix_1);
        del_str_cols_in_matrix(&matrix_2);

        size = max(matrix_1.rows, matrix_2.rows);

        create_matrix(&result_matrix_1, size, size, &code);
        if (code == ok)
            create_matrix(&result_matrix_2, size, size, &code);
        if (code == ok)
            create_matrix(&multiple_matrix, size, size, &code);
            
        if (code == ok)
        {
            copy_matrix(&matrix_1, &result_matrix_1);
            copy_matrix(&matrix_2, &result_matrix_2);
            
            add_str_cols_to_matrix(matrix_1.rows, size, result_matrix_1.matrix);
            add_str_cols_to_matrix(matrix_2.rows, size, result_matrix_2.matrix);

            exponentiation_matrix(&result_matrix_1, &multiple_matrix, pow_1, &code);
            
            if (code == ok)
                exponentiation_matrix(&result_matrix_2, &result_matrix_1, pow_2, &code);
            if (code == ok)
                multiple_matrix.matrix = multiply_matr(&multiple_matrix, &result_matrix_1, &code);
        }
    }


    //output
    if (code == ok)
        print_matrix(multiple_matrix);

    //cleaning
    clean_struct_matrix(&matrix_1);
    clean_struct_matrix(&matrix_2);
    clean_struct_matrix(&result_matrix_1);
    clean_struct_matrix(&result_matrix_2);
    clean_struct_matrix(&multiple_matrix);
    
    return code;
}