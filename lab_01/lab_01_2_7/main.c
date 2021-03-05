/**
Программа вычисляет с точностью eps:

− приближенное значение функции s(x);
− точное значение функции f(x);
− абсолютную |f(x) -s(x)| и относительную |(f(x)-s(x))/f(x)| ошибки приближенного значения
*/

#include <stdio.h>
#include <math.h>

int main()
{
    float eps, x;
    float s, f, elem;
    float absolute, relative;
    int k, rc;
    printf("Input x, eps: ");
    rc = scanf("%f %e", &x, &eps);
    if (rc == 2 && fabs(x) < 1 && eps < 1 && x != 0)
    {
        f = asin(x);
        k = 3;
        elem = powf(x, 3) / 6;
        s = elem + x;
        while (fabs(elem) > eps)
        {
            elem = k * k * elem * x * x / (k + 1) / (k + 2);
            k = k + 2;
            s = s + elem;
        }
        absolute = fabs(f - s);
        relative = fabs((f - s) / f);
        printf("s(x) =  %.6lf\n", s);
        printf("f(x) = %.6lf\n", f);
        printf("|f(x)-s(x)| = %.6lf\n", absolute);
        printf("|(f(x)-s(x))/f(x)| = %.6lf\n", relative);
        printf("s(x) =  %.6lf\n", s);
        return 0;
    }
    else
    {
        printf("Input error");
        return 1;
    }
}