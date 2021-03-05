#include "../inc/const_errors.h"
#include "../inc/processing.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_processing_key_0)
{
    int array[] = {1, 2};
    int *pb_dst, *pe_dst, size = 2;

    key(array, array + 2, &pb_dst, &pe_dst);
    int rc = pe_dst - pb_dst;
    free(pb_dst);
    ck_assert_int_eq(rc, size);
}
END_TEST

START_TEST(test_processing_key_1)
{
    int array[] = {1, 2};
    int *pb_dst, *pe_dst, code = 1;

    int rc = key(array, NULL, &pb_dst, &pe_dst);
    
    ck_assert_int_eq(rc, code);
}
END_TEST

START_TEST(test_processing_key_2)
{
    int array[] = {1, 2};
    int *pb_dst, *pe_dst, code = 1;

    int rc = key(NULL, array, &pb_dst, &pe_dst);
    
    ck_assert_int_eq(rc, code);
}
END_TEST

START_TEST(test_processing_key_3)
{
    int array[] = {1, 2};
    int *pb_dst, *pe_dst, code = 1;

    int rc = key(array, array, &pb_dst, &pe_dst);
    
    ck_assert_int_eq(rc, code);
}
END_TEST

START_TEST(test_processing_cmp_int_elems_0)
{
    int elem_1 = 0, elem_2 = 0;

    int rc = cmp_int_elems(&elem_1, &elem_2);
    
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_processing_cmp_int_elems_1)
{
    int elem_1 = 0, elem_2 = 1;

    int rc = cmp_int_elems(&elem_1, &elem_2);
    
    ck_assert_int_lt(rc, 0);
}
END_TEST


START_TEST(test_processing_cmp_int_elems_2)
{
    int elem_1 = -1, elem_2 = -2;

    int rc = cmp_int_elems(&elem_1, &elem_2);
    
    ck_assert_int_lt(0, rc);
}
END_TEST

START_TEST(test_processing_mysort)
{
    int size = 10;
    int array[] = {1, 3, 2, 5, 4, 7, 6, 9, 8, 0};

    mysort(array, size, sizeof(int), (int(*) (const void *, const void *)) cmp_int_elems);
    
    for (int i = 0; i < size; i++)
        ck_assert_int_eq(array[i], i);
}
END_TEST

Suite* processing_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("processing");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_processing_key_1);
    tcase_add_test(tc_neg, test_processing_key_2);
    tcase_add_test(tc_neg, test_processing_key_3);

    suite_add_tcase(s, tc_neg);


    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_processing_key_0);
    tcase_add_test(tc_pos, test_processing_cmp_int_elems_0);
    tcase_add_test(tc_pos, test_processing_cmp_int_elems_1);
    tcase_add_test(tc_pos, test_processing_cmp_int_elems_2);
    tcase_add_test(tc_pos, test_processing_mysort);

    suite_add_tcase(s, tc_pos);

    return s;
}