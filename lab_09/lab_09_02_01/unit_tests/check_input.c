#include "../inc/const_errors.h"
#include "../inc/input.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_input_check_input)
{
    int argc = 4;
    char **argv = NULL;
    status_codes code = ok;
    check_input(argc, &code, argv);
    ck_assert_int_eq(code, incorrect_input);
}
END_TEST

START_TEST(test_input_check_input_2)
{
    int argc = 1;
    char **argv = NULL;
    status_codes code = ok;
    check_input(argc, &code, argv);
    ck_assert_int_eq(code, incorrect_input);
}
END_TEST


Suite* input_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    //TCase *tc_pos;

    s = suite_create("matrix_processing");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_input_check_input);
    tcase_add_test(tc_neg, test_input_check_input_2);

    suite_add_tcase(s, tc_neg);

    return s;
}