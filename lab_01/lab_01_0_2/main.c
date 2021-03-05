/// Даны основания и высота равнобедренной трапеции. Программа рассчитывает её периметр.

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, h, rib;
    printf("Введите через пробел длину основания а, длину основания b и высоту h: ");
    scanf("%f %f %f", &a, &b, &h);
    rib = sqrtf(powf(((fabs(a - b)) / 2), 2) + h * h);
    printf("Периметр трапеции: %.5f", 2 * rib + a + b);
    return 0;
}
