/**
По заданным координатам вершин программа рассчтывает площадь треугольника.
*/

#include <stdio.h>
#include <math.h>

/// Функция рассчитывает длину стороны. Параметрами являются координаты начала и конца ребра.
float side(float x01, float x02, float y01, float y02) 
{
    return sqrt((x01 - x02) * (x01 - x02) + (y01 - y02) * (y01 - y02));
}

int main()
{
    float x1, y1, x2, y2, x3, y3;
    float p, s;                     /// half of perimetr and area
    float a, b, c;                  /// triangle sides
    int rc;
    const float eps = 1e-6;
    printf("Input x1, y1: ");
    rc = scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
    if (rc == 6)
    {
        a = side(x1, x2, y1, y2);
        b = side(x2, x3, y2, y3);
        c = side(x3, x1, y3, y1);
        p = (a + b + c) / 2;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        if (fabs(s) > eps)
        {
            printf("Area is %.6f", s);
            return 0;
        }
        else
        {
            printf("It is not triangle");
            return 1;
        }
    }
    else
    {
        printf("Input error");
        return 1;
    }
}