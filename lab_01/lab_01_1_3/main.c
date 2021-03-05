/**
Заданы объем и температура воды в двух сосудах. 
Программа находит объём и температуру в смеси жидкостей из обоих сосудов
*/

#include <stdio.h>

int main()
{
    float v1, t1, v2, t2, v, t;
    printf("Input v1, t1: ");
    scanf("%f %f", &v1, &t1);
    printf("Input v2, t2: ");
    scanf("%f %f", &v2, &t2);
    v = v1 + v2;
    t = (v1 * t1 + v2 * t2) / v;
    printf("V = %.5f\n", v);
    printf("t = %.5f", t);
    return 0;
}
