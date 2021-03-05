#include "../inc/const_errors.h"
#include "../inc/matrix_processing.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_matrix_processing_max)
{
    int el1 = -1, el2 = 0;
    ck_assert_int_eq(max(el1, el2), 0);
}
END_TEST

START_TEST(test_matrix_processing_del_str_cols_in_matrix_str)
{
    struct matrix matr;
    init_matrix(&matr);
    status_codes code = ok;

    create_matrix(&matr, 3, 2, &code);
    for (int i = 0; i < matr.rows; i++)
        for (int j = 0; j < matr.cols; j++)
            matr.matrix[i][j] = 0;
    del_str_cols_in_matrix(&matr);
    
    ck_assert_int_eq(matr.rows, 2);
    ck_assert_int_eq(matr.cols, 2);
    for (int i = 0; i < matr.rows; i++)
        for (int j = 0; j < matr.cols; j++)
            ck_assert_int_eq(matr.matrix[i][j], 0);
    if (matr.matrix != NULL)
    {
        free(matr.start_matrix);
        free(matr.matrix);
    }
}
END_TEST


START_TEST(test_matrix_processing_del_str_cols_in_matrix_cols)
{
    struct matrix matr;
    status_codes code = ok;

    create_matrix(&matr, 3, 8, &code);
    for (int i = 0; i < matr.rows; i++)
        for (int j = 0; j < matr.cols; j++)
            matr.matrix[i][j] = 0;
    del_str_cols_in_matrix(&matr);
    
    ck_assert_int_eq(matr.rows, 3);
    ck_assert_int_eq(matr.cols, 3);
    for (int i = 0; i < matr.rows; i++)
        for (int j = 0; j < matr.cols; j++)
            ck_assert_int_eq(matr.matrix[i][j], 0);
    clean_struct_matrix(&matr);

}
END_TEST

START_TEST(test_matrix_processing_fill_matrix_with_ones)
{
    struct matrix matr;
    status_codes code = ok;

    create_matrix(&matr, 3, 3, &code);
    for (int i = 0; i < matr.rows; i++)
        for (int j = 0; j < matr.cols; j++)
            matr.matrix[i][j] = 0;
    fill_matrix_with_ones(&matr);
    
    for (int i = 0; i < matr.rows; i++)
        for (int j = 0; j < matr.cols; j++)
        {
            if (i == j)
                ck_assert_int_eq(matr.matrix[i][j], 1);
            else
                ck_assert_int_eq(matr.matrix[i][j], 0);
        }
    clean_struct_matrix(&matr);
}
END_TEST

START_TEST(test_matrix_processing_exponentation_matrix)
{
    struct matrix matr, matr2;
    status_codes code = ok;

    create_matrix(&matr, 3, 3, &code);
    create_matrix(&matr2, 3, 3, &code);
    for (int i = 0; i < matr.rows; i++)
        for (int j = 0; j < matr.cols; j++)
            matr.matrix[i][j] = 1;

    exponentiation_matrix(&matr, &matr2, 1, &code);
    
    for (int i = 0; i < matr.rows; i++)
        for (int j = 0; j < matr.cols; j++)
            ck_assert_int_eq(matr.matrix[i][j], matr2.matrix[i][j]);
    clean_struct_matrix(&matr);
    clean_struct_matrix(&matr2);
}
END_TEST

Suite* matrix_processing_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("matrix_processing");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_matrix_processing_max);
    tcase_add_test(tc_pos, test_matrix_processing_del_str_cols_in_matrix_str);
    tcase_add_test(tc_pos, test_matrix_processing_del_str_cols_in_matrix_cols);
    tcase_add_test(tc_pos, test_matrix_processing_fill_matrix_with_ones);
    tcase_add_test(tc_pos, test_matrix_processing_exponentation_matrix);

    suite_add_tcase(s, tc_pos);

    return s;
}