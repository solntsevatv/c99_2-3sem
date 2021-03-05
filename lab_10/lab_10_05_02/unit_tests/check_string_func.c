#include "../inc/const_errors.h"
#include "../inc/string_func.h"
#include "../inc/linked_list.h"
#include <check.h>

START_TEST(test_string_func_delete_spases)
{
    char *str = malloc(sizeof(char) * SUBSTR_SIZE);
    for (int i = 0; i < SUBSTR_SIZE - 1; i++)
        str[i] = ' ';
    str[SUBSTR_SIZE - 1] = '\0';

    node_t *list = NULL;
    add_el_list(&list, str);
    delete_spases(&list);

    ck_assert_int_eq((int) strlen(str), 1);

    clean_list(&list);
}
END_TEST

START_TEST(test_string_func_find_substring)
{
    char *str = malloc(sizeof(char) * SUBSTR_SIZE);
    for (int i = 0; i < SUBSTR_SIZE - 1; i++)
        str[i] = ' ';
    str[SUBSTR_SIZE - 1] = '\0';

    char *str2 = malloc(sizeof(char) * SUBSTR_SIZE);
    for (int i = 1; i < SUBSTR_SIZE; i++)
        str2[i] = '\0';
    str2[0] = 'd';

    node_t *list = NULL;
    add_el_list(&list, str);

    node_t *list2 = NULL;
    add_el_list(&list2, str2);

    ck_assert_int_eq(find_substring(list, list2), -1);

    clean_list(&list);
    clean_list(&list2);
}
END_TEST

START_TEST(test_string_func_find_substring2)
{
    char *str = malloc(sizeof(char) * SUBSTR_SIZE);
    for (int i = 0; i < SUBSTR_SIZE - 1; i++)
        str[i] = 'q';
    str[SUBSTR_SIZE - 1] = '\0';

    char *str2 = malloc(sizeof(char) * SUBSTR_SIZE);
    for (int i = 1; i < SUBSTR_SIZE; i++)
        str2[i] = '\0';
    str2[0] = 'q';

    node_t *list = NULL;
    add_el_list(&list, str);

    node_t *list2 = NULL;
    add_el_list(&list2, str2);

    ck_assert_int_eq(find_substring(list, list2), 0);

    clean_list(&list);
    clean_list(&list2);
}
END_TEST

Suite* string_func_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("string_func");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_string_func_delete_spases);
    tcase_add_test(tc_pos, test_string_func_find_substring);
    tcase_add_test(tc_pos, test_string_func_find_substring2);

    suite_add_tcase(s, tc_pos);

    return s;
}