#include <stdio.h>
#define LEN_ARR 20

typedef enum
{
    ok, input_array_e, input_n_e, input_num_e
} status_codes;

/// Функция ввода массива
status_codes input_array(int len_array, int arr[])
{
    status_codes code = ok;
    printf("Input array: ");
    for (int i = 0; i < len_array; i++)
    {
        if (scanf("%d", &arr[i]) != 1 && arr[i] >= 0)
        {
            code = input_array_e;
            break;
        }
    }
    return code;
}

void delete_numbers(int ind, int len_array, int arr[LEN_ARR])
{
    for (int i = ind; i < len_array - 1; i++)
        arr[i] = arr[i + 1];
}

int check_numbers(int len_array, int arr[LEN_ARR], int num)
{
    int count = 0;
    for (int i = 0; i < len_array; i ++)
    {
        if (arr[i] % num == 0)
        {
            count++;
            if (count % 2 == 0)
            {
                delete_numbers(i, len_array, arr);
                len_array--;
            }
        }
    }
    return len_array;
}

/// Функция вывода массива
void output_array(int arr[], int len_array)
{
    printf("Array: ");
    for (int i = 0; i < len_array; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int code = ok;
    int arr[LEN_ARR];
    int len_array, num;
    printf("Input n: ");
    if (scanf("%d", &len_array) != 1 || len_array > LEN_ARR || len_array <= 0)
        code = input_n_e;
    else
        code = input_array(len_array, arr);
    if (code == ok && scanf("%d", &num) != 1 && num > 0)
        code  = input_num_e;
    if (code == ok)
        len_array = check_numbers(len_array, arr, num);
    switch (code)
    {
        case ok:
            output_array(arr, len_array);
            break;
        case input_array_e:
            printf("Please, input correct array!");
            break;
        case input_n_e:
            printf("Please, input correct n!");
        case input_num_e:
            printf("Please, input correct number!");
    }
    return code;
}
