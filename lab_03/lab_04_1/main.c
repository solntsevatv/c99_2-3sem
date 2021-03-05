#include <stdio.h>
#include <string.h>
#include "my_strrchr.h"

int main(void)
{
    char *p;
    p = my_strrchr("I don't know, how to do these tests.", 'I');
    printf(p);
    printf("\n");
    p = my_strrchr("I don't know, how to do these tests.", '.');
    printf(p);
    printf("\n");
    p = my_strrchr("I don't know, how to do these tests.", 'h');
    printf(p);
    printf("\n");
    p = my_strrchr("I don't know, how to do these tests.", '4');
    printf(p);
    p = my_strrchr("h", 'h');
    printf(p);
    printf("\n");
    if (my_strrchr("\0", '\0') == strrchr("\0", '\0'))
        printf("ok");
    return 0;
}