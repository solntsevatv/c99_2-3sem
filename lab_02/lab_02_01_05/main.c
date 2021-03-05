/**
Вычислить значение x[0]*y[0] + x[1]*y[1] + ... + x[k]*y[k], где x[i] – отрицательные
элементы массива a из n элементов, взятые в порядке их следования; y[i] –
положительные элементы этого массива, взятые в обратном порядке; k = min(p,q), где
p – количество положительных элементов массива a, q – количество отрицательных
элементов этого массива.
*/

#include <stdio.h>
#define N 11
typedef enum
{
    ok, input_array_e, input_n_e, incorrect_k
} statuscodes;

/// Функция ввода массива и подсчета k
statuscodes input(int *start, int *end, int *k)
{
    statuscodes code = ok;
    int positive = 0;
    int negative = 0;
    printf("Input array: ");
    for (int *i = start; i < end; i++)
    {
        if (scanf("%d", i) != 1)
        {
            code = input_array_e;
            break;
        }
        else
        {
            if (*i > 0)
                positive++;
            else if (*i < 0)
                negative++;
        }
    }
    if (positive <= negative)
        *k = positive;
    else
        *k = negative;
    return code;
}

/// Функция вывода массива
void output(int *start, int *end)
{
    printf("Array: ");
    for (int *i = start; i < end; i++)
    {
        printf("%d ", *i);
    }
}

/// Функция подсчёта искомой суммы
int calculate(int k, int *start, int *end)
{
    int *last_positive = end;
    int summ = 0;
    int n = 0;
    for (int *i = start; i < end + 1 && n < k; i++)
    {
        if (*i < 0)
        {
            while (*last_positive <= 0)
                last_positive--;
            summ += *i * *last_positive;
            last_positive--;
            n++;
        }
    }
    return summ;
}

int main()
{
    int code = ok;
    int arr[N];
    int n, summ;
    int k = 0;
    printf("Input n: ");
    if (scanf("%d", &n) != 1 || n > N || n <= 0)
        code = input_n_e;
    else
        code = input(arr, arr + n, &k);
    if (code == 0 && k == 0)
        code = incorrect_k;
    switch (code)
    {
        case ok:
            summ = calculate(k, arr, arr + n - 1);
            printf("Sum = %d", summ);
            break;
        case input_array_e:
            printf("Please, input correct array!");
            break;
        case input_n_e:
            printf("Please, input correct n!");
            break;
        case incorrect_k:
            printf("Please, input both positive and negative numbers.");
    }
    return code;
}
