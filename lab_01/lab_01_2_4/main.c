/**
Дано количество секунд. Перевести в часы, минуты, секунды.
*/

#include <stdio.h>

int main()
{
    int t;
    int hours, minutes, seconds;
    printf("Input seconds: ");
    scanf("%d", &t);
    hours = t / 3600;
    minutes = (t - hours * 3600) / 60;
    seconds = t - hours * 3600 - minutes * 60;
    printf("%d hours %d minutes %d seconds", hours, minutes, seconds);
}
