/**
Дано целое число а и натуральное число n.
Найти а^n.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int rc, a, n;
    printf("Input a, n: ");
    rc = scanf("%d %d", &a, &n);
    if (rc == 2 && n > 0)
    {
        printf("a^n = %d", (int) powf(a, n));
        return 0;
    }
    else
    {
        printf("Input error");
        return 1;
    }
}
