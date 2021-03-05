/**
Сформируйте новый массив из элементов исходного массива. При этом в новый массив
помещаются (копируются) элементы исходного массива, которые больше среднего арифметического его
элементов;
*/

#include <stdio.h>
#define N 10
typedef enum
{
    ok, input_array_e, input_n_e, incorrect_num
} statuscodes;

/// Ввод массива и поиск среднего арифметического
statuscodes input_sr_arifm(int n, int arr[], double *sr_arifm)
{
    int code = ok;
    int summ = 0;
    printf("Input array: ");
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) == 1)
            summ = summ + arr[i];
        else
        {
            code = input_array_e;
            break;
        }
    }
    *sr_arifm = (double) summ / n;
    return code;
}

/// создание нового массива
int new_arr(int arr1[], int arr2[], int n, double sr_arifm)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] > sr_arifm)
        {
            arr2[k] = arr1[i];
            k += 1;
        }
    }
    return k;
}

int main()
{
    int n;
    statuscodes code = ok;
    double sr_arifm = 0;
    int arr1[N];
    int arr2[N];
    printf("Input n: ");
    if (scanf("%d", &n) != 1 || n > N || n <= 0)
        code = input_n_e;
    else
    {
        code = input_sr_arifm(n, arr1, &sr_arifm);
        if (code == ok)
        {
            n = new_arr(arr1, arr2, n, sr_arifm);
            if (n == 0)
                code = incorrect_num;
        }
    }
    switch (code)
    {
        case ok:
            printf("Array: ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr2[i]);
            break;
        case input_array_e:
            printf("Please, input correct array!");
            break;
        case input_n_e:
            printf("Please, input correct n!");
            break;
        case incorrect_num:
            printf("Please, input different numbers.");
    }
    return code;
}
