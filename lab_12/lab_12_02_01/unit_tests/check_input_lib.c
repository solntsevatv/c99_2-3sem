#include "../inc/input_lib.h"
#include <check.h>

START_TEST(test_input_lib_read_array)
{
    int count = 7;
    int array[count];
    FILE *f;
    f = fopen("unit_tests/test_read_array.txt", "r");

    read_array(array, array + count, f);
    fclose(f);
    for (int i = 0; i < count; i++)
        ck_assert_int_eq(array[i], i);
}
END_TEST

START_TEST(test_input_lib_check_input_0)
{
    status_codes code = ok;
    char *str[4] = {"./main.exe", "file_1", "file_2", "foo"};
    check_input(4, &code, str);
    ck_assert_int_eq(code, incorrect_input);
}
END_TEST

START_TEST(test_input_lib_check_input_1)
{
    status_codes code = ok;
    char *argv[3] = {"./main.exe", "file_1", "file_2"};
    check_input(3, &code, argv);
    ck_assert_int_eq(code, file_error);
}
END_TEST

START_TEST(test_input_lib_check_input_2)
{
    status_codes code = ok;
    char *argv[5] = {"./main.exe", "file_1", "file_2", "f", "f"};
    check_input(5, &code, argv);
    ck_assert_int_eq(code, incorrect_input);
}
END_TEST

Suite* input_lib_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("input_lib");
    
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_input_lib_read_array);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_input_lib_check_input_0);
    tcase_add_test(tc_neg, test_input_lib_check_input_1);
    tcase_add_test(tc_neg, test_input_lib_check_input_2);

    suite_add_tcase(s, tc_neg);

    return s;
}