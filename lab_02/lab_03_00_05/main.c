/**
Элементы матрицы, которые являются простыми числами, поместить в одномерный
массив, обратить массив, и вернуть элементы из массива в матрицу в том же
порядке, в котором они помещались в массив. Если в матрице нет простых чисел,
ничего не выводить, вернуть код ошибки.
*/

#include <stdio.h>
#define N 10

typedef enum
{
    ok, input_matrix_e, input_n_e, input_m_e, no_simple_nums
} statuscodes;

/// Функция ввода матрицы
statuscodes input(int n, int m, int (*p)[N])
{
    statuscodes code = ok;
    printf("Input matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (scanf("%d", &(*p)[j]) != 1)
            {
                code = input_matrix_e;
                break;
            }
        }
        p++;
    }
    return code;
}

/// проверка, является ли число простым
int check(int num)
{
    int code = 0;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            code = 1;
            break;
        }
    }
    return code;
}

/// формирование массива простых чисел
statuscodes form_array(int n, int m, int (*matr)[N], int *start, int *count)
{
    statuscodes code = no_simple_nums;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check((*matr)[j]) == 0 && (*matr)[j] != 1)
            {
                *start = (*matr)[j];
                start++;
                *count = *count + 1;
                code = ok;
            }
        }
        matr++;
    }
    if (*count != 0)
        code = ok;
    return code;
}

/// Функция вывода матрицы
void output(int n, int m, int (*p)[N], int *start)
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check((*p)[j]) == 0 && (*p)[j] != 1)
            {
                printf("%d ", *start);
                start++;
            }
            else
                printf("%d ", (*p)[j]);
        }
        printf("\n");
        p++;
    }
}

int main()
{
    int code = ok;
    int matr[N][N];
    int arr[N * N];
    int n, m, num;
    int count = 0;
    printf("Input n (number of lines), m (number of columns): ");
    if (scanf("%d", &n) != 1 || n > N || n <= 0)
        code = input_n_e;
    else if (scanf("%d", &m) != 1 || m > N || m <= 0)
        code = input_m_e;
    else
        code = input(n, m, &matr[0]);
    if (code == ok)
    {
        code = form_array(n, m, &matr[0], arr, &count);
    }
    switch (code)
    {
        case ok:
            for (int i = 0; i < count / 2; i++)
            {
                num = arr[count - 1 - i];
                arr[count - 1 - i] = arr[i];
                arr[i] = num;
            }
            output(n, m, &matr[0], arr);
            break;
        case input_matrix_e:
            printf("Please, input correct matrix!");
            break;
        case input_n_e:
            printf("Please, input correct n (number of lines)!");
            break;
        case input_m_e:
            printf("Please, input correct m (number of columns)!");
            break;
        case no_simple_nums:
            printf("Please, input matrix with simple numbers!");
            break;
    }
    return code;
}
