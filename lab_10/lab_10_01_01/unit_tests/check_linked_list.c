#include "../inc/const_errors.h"
#include "../inc/linked_list.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_linked_list_pop_back)
{
    int *num_to_add = malloc(sizeof(int *));
    *num_to_add = 1423;
    int *popped_num = NULL;

    node_t *list = NULL;
    add_el_list(&list, num_to_add);
    popped_num = pop_back(&list);

    ck_assert_int_eq(*num_to_add, *popped_num);

    free(num_to_add);
    clean_list(&list);
}
END_TEST

Suite* linked_list_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("linked_list");


    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_linked_list_pop_back);

    suite_add_tcase(s, tc_pos);

    return s;
}