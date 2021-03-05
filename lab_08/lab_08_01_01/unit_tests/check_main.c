#include "../inc/unit_tests.h"
#include <check.h>
#define PASS 0

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = matrix_processing_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
   
    srunner_free(runner);

    return (no_failed == 0) ? PASS : CK_FAILURE;
}