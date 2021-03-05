#include "../inc/const_errors.h"
#include "../inc/linked_list.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_linked_list_list_is_empty)
{
    node_t *list = NULL;
    
    ck_assert_int_eq(list_is_empty(list), 1);
}
END_TEST

START_TEST(test_linked_list_list_is_empty_2)
{
    node_t *list = NULL;

    int *num = malloc(sizeof(int *));
    *num = 0;

    add_el_list(&list, num);

    ck_assert_int_eq(list_is_empty(list), 0);

    clean_list(&list);
}
END_TEST

Suite* linked_list_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("linked_list");


    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_linked_list_list_is_empty);
    tcase_add_test(tc_pos, test_linked_list_list_is_empty_2);

    suite_add_tcase(s, tc_pos);

    return s;
}