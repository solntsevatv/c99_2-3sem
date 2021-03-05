/**
Вставить в исходный массив после каждого положительного элемента этот же элемент,
записанный наоборот
*/

#include <stdio.h>
#define N 20
typedef enum
{
    ok, input_array_e, input_n_e
} statuscodes;

/// Ввод массива
statuscodes input(int n, int arr[])
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
    }
    return code;
}

/// Переворот числа наоборот
int reverse(int a)
{
    int num = 0;
    while (a > 0)
    {
        num *= 10;
        num = num + (a % 10);
        a = a / 10;
    }
    return num;
}

/// Вывод массива
void output(int arr[], int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n;
    int code = ok;
    int num = 0;
    int arr[N];
    printf("Input n: ");
    if (scanf("%d", &n) != 1 || n > N / 2 || n <= 0)
        code = input_n_e;
    else
        code = input(n, arr);
    if (code == ok)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                num = reverse(arr[i]);
                for (int j = n; j > i + 1; j--)
                    arr[j] = arr[j - 1];
                arr[i + 1] = num;
                i = i + 1;
                n = n + 1;
            }
        }
    }
    switch (code)
    {
        case ok:
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
