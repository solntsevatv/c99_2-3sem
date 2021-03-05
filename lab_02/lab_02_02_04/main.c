/**
Упорядочить исходный массив по возрастанию выбором
*/

#include <stdio.h>
#define N 10
typedef enum
{
    ok, input_array_e, input_n_e
} statuscodes;

/// Функция ввода массива
statuscodes input(int n, int arr[])
{
    statuscodes code = ok;
    printf("Input array: ");
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            code = input_array_e;
            break;
        }
    }
    return code;
}

/// Функция вывода массива
void output(int arr[], int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

/// Фнукция поиска минимума в массиве
int minimum(int *start, int n, int i, int *ind_min)
{
    int min = *start;
    start++;
    for (int j = i; j < n; j++)
    {
        if (*start <= min)
        {
            min = *start;
            *ind_min = j;
        }
        start++;
    }
    return min;
}

/// Сортировка массива выбором
void selection(int arr[], int n)
{
    int ind_min = 0;
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        ind_min = i;
        min = minimum(&arr[i], n, i + 1, &ind_min);
        arr[ind_min] = arr[i];
        arr[i] = min;
    }
}

int main()
{
    int code = ok;
    int arr[N];
    int n;
    printf("Input n: ");
    if (scanf("%d", &n) != 1 || n > N || n <= 0)
        code = input_n_e;
    else
        code = input(n, arr);
    switch (code)
    {
        case ok:
            selection(arr, n);
            output(arr, n);
            break;
        case input_array_e:
            printf("Please, input correct array!");
            break;
        case input_n_e:
            printf("Please, input correct n!");
    }
    return code;
}
