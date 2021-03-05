#include "../inc/const_errors.h"
#include "../inc/my_func.h"
#include <check.h>
#include <limits.h>


//////////////////////////////////
//           cccccc             //
//////////////////////////////////


START_TEST(test_my_func_my_snprintf_c)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, 10, "kdsldk %c", 'g'), my_snprintf(str2, 10, "kdsldk %c", 'g'));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_c2)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, STR_SIZE, "hhhhhhhhh%c", 'g'), my_snprintf(str2, STR_SIZE, "hhhhhhhhh%c", 'g'));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_c3)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, 10, "%c%c%c%c%c", 'a', 'b', 'c', 'd', 'e'), my_snprintf(str2, 10, "%c%c%c%c%c", 'a', 'b', 'c', 'd', 'e'));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_c4)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, 10, "%%c%c%c%c", 'a', 'b', 'c'), my_snprintf(str2, 10, "%%c%c%c%c", 'a', 'b', 'c'));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_c5)
{
    int size = 5;
    char str[size + 1];
    char str2[size + 1];

    ck_assert_int_eq(snprintf(str, size + 1, "%cdear%c", 'a', 'b'), my_snprintf(str2, size + 1, "%cdear%c", 'a', 'b'));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST


//////////////////////////////////
//           ssssss             //
//////////////////////////////////



START_TEST(test_my_func_my_snprintf_s)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, STR_SIZE, "%s", "Hello, world!!!"), my_snprintf(str2, STR_SIZE, "%s", "Hello, world!!!"));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_s2)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, STR_SIZE, "%s", "1234567890123456789012345"), my_snprintf(str2, STR_SIZE, "%s", "1234567890123456789012345"));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST


//////////////////////////////////
//           dddddd             //
//////////////////////////////////


START_TEST(test_my_func_my_snprintf_d)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, STR_SIZE, "kdsldk %d", 1092), my_snprintf(str2, STR_SIZE, "kdsldk %d", 1092));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_d2)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, STR_SIZE, "hhhhhhhhh%d", 4), my_snprintf(str2, STR_SIZE, "hhhhhhhhh%d", 4));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_d3)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, STR_SIZE, "6789023456789012345678%d", 567890), my_snprintf(str2, STR_SIZE, "6789023456789012345678%d", 567890));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_d4)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, 20, "%d%d%d%d%d", -1, -2, -3, -4, -5), my_snprintf(str2, 20, "%d%d%d%d%d", -1, -2, -3, -4, -5));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_d5)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, STR_SIZE, "%d", INT_MAX), my_snprintf(str2, STR_SIZE, "%d", INT_MAX));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_d6)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, STR_SIZE, "%d", INT_MIN), my_snprintf(str2, STR_SIZE, "%d", INT_MIN));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST


//////////////////////////////////
//           ldldld             //
//////////////////////////////////


START_TEST(test_my_func_my_snprintf_ld)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, STR_SIZE, "%ld", LONG_MIN), my_snprintf(str2, STR_SIZE, "%ld", LONG_MIN));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_ld2)
{
    char str[STR_SIZE * 2 + 1];
    char str2[STR_SIZE * 2 + 1];

    ck_assert_int_eq(snprintf(str, STR_SIZE * 2, "%ld%ld%ld", LONG_MIN, LONG_MAX, 0L), my_snprintf(str2, STR_SIZE * 2, "%ld%ld%ld", LONG_MIN, LONG_MAX, 0L));

    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_ld3)
{
    char str[STR_SIZE * 2 + 1];
    char str2[STR_SIZE * 2 + 1];

    ck_assert_int_eq(snprintf(str, STR_SIZE * 2, "%ld %ld %ld", LONG_MIN, LONG_MAX, 0L), my_snprintf(str2, STR_SIZE * 2, "%ld %ld %ld", LONG_MIN, LONG_MAX, 0L));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST


//////////////////////////////////
//           allall             //
//////////////////////////////////


START_TEST(test_my_func_my_snprintf_all)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, 10, "jjjjjjjjj"), my_snprintf(str2, 10, "jjjjjjjjj"));
    
    ck_assert_pstr_eq(str, str2);
}
END_TEST

START_TEST(test_my_func_my_snprintf_all2)
{
    char str[STR_SIZE + 1];
    char str2[STR_SIZE + 1];

    ck_assert_int_eq(snprintf(str, 3, "jj"), my_snprintf(str2, 3, "jj"));
    ck_assert_pstr_eq(str, str2);
}
END_TEST

Suite* my_func_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("my_func");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_my_func_my_snprintf_c);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_c2);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_c3);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_c4);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_c5);

    tcase_add_test(tc_pos, test_my_func_my_snprintf_s);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_s2);

    tcase_add_test(tc_pos, test_my_func_my_snprintf_d);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_d2);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_d3);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_d4);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_d5);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_d6);
    
    tcase_add_test(tc_pos, test_my_func_my_snprintf_ld);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_ld2);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_ld3);
    
    tcase_add_test(tc_pos, test_my_func_my_snprintf_all);
    tcase_add_test(tc_pos, test_my_func_my_snprintf_all2);

    suite_add_tcase(s, tc_pos);

    return s;
}