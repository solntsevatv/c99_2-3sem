#include "../inc/arr_lib.h"
#include <check.h>

int fibonacci(int num)
{
    if (num == 0)
        return 0;
    if (num == 1 || num == 2)
        return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

START_TEST(test_arr_lib_fill_fibonacci)
{
    int count = 1;
    int array[count];
    
    fill_fibonacci(array, count);

    ck_assert_int_eq(array[0], 0);
}
END_TEST

START_TEST(test_arr_lib_fill_fibonacci2)
{
    int count = 10;
    int array[count];
    
    fill_fibonacci(array, count);

    for (int i = 0; i < count; i++)
        ck_assert_int_eq(array[i], fibonacci(i));
}
END_TEST

START_TEST(test_arr_lib_transfer_nums)
{
    int count = 10;
    int array[count];
    int array2[count];
    
    fill_fibonacci(array, count);
    transfer_nums(array, array2, count);
    
    for (int i = 1; i < count - 1; i++)
        ck_assert_int_eq(array2[i], array[i + 1]);
}
END_TEST

START_TEST(test_arr_lib_transfer_nums2)
{
    int count = 10;
    int array[count];
    for (int i = 0; i < count; i++)
        array[i] = 5;

    int array2[count];
    for (int i = 0; i < count; i++)
        array2[i] = 0;
    
    transfer_nums(array, array2, count);
    
    ck_assert_int_eq(array[0], array2[0]);
    for (int i = 1; i < count; i++)
        ck_assert_int_eq(array2[i], 0);
}
END_TEST

Suite* arr_lib_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("arr_lib");
    
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_arr_lib_fill_fibonacci);
    tcase_add_test(tc_pos, test_arr_lib_fill_fibonacci2);
    tcase_add_test(tc_pos, test_arr_lib_transfer_nums);
    tcase_add_test(tc_pos, test_arr_lib_transfer_nums2);

    suite_add_tcase(s, tc_pos);

    return s;
}