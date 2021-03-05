/**
Найти среднее арифметическое отрицательных элементов массива
*/

#include <stdio.h>
#define N 10
typedef enum
{
    ok, input_array_e, input_n_e, incorrect_k
} statuscodes;

/// Ввод массива
statuscodes input(int n, int arr[], int *k, int *summ)
{
    int code = ok;
    printf("Input array: ");
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            code = input_array_e;
            break;
        }
        else
        {
            if (arr[i] < 0)
            {
                *summ = *summ + arr[i];
                *k = *k + 1;
            }
        }
    }

    return code;
}

int main()
{
    int n;
    statuscodes code = ok;
    int summ = 0;
    int k = 0;
    int arr[N];
    printf("Input n: ");
    if (scanf("%d", &n) != 1 || n > N || n <= 0)
        code = input_n_e;
    if (code == ok)
    {
        code = input(n, arr, &k, &summ);
        if (code == 0 && k == 0)
            code = incorrect_k;
    }
    switch (code)
    {
        case ok:
            printf("%f", (float) summ / k);
            break;
        case input_array_e:
            printf("Please, input correct array!");
            break;
        case input_n_e:
            printf("Please, input correct n!");
            break;
        case incorrect_k:
            printf("Please, input negative numbers.");
    }
    return code;
}
