/**
По матрице получить одномерный массив, присвоив его k-тому элементу значение 1, если
выполняется указанное ниже условие, и значение 0 иначе:
k-ая строка матрицы симметрична
*/

#include <stdio.h>
#define N 10

typedef enum
{
    ok, input_matrix_e, input_n_e, input_m_e,
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

/// Функция проверки строки на симметрию
int symmetry(int m, int (*p)[N])
{
    int code = 1;
    int middle = m / 2;
    for (int i = 0; i < middle; i++)
    {
        if ((*p)[i] != (*p)[m - 1 - i])
        {
            code = 0;
        }
    }
    return code;
}

/// Функция вывода массива
void output(int *start, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *start);
        start++;
    }
}

int main()
{
    int code = ok;
    int matr[N][N];
    int arr[N];
    int n, m;
    printf("Input n (number of lines), m (number of columns): ");
    if (scanf("%d", &n) != 1 || n > N || n <= 0)
        code = input_n_e;
    else if (scanf("%d", &m) != 1 || m > N || m <= 0)
        code = input_m_e;
    else
        code = input(n, m, &matr[0]);
    switch (code)
    {
        case ok:
            for (int i = 0; i < n; i++)
                arr[i] = symmetry(m, &matr[i]);
            output(arr, n);
            break;
        case input_matrix_e:
            printf("Please, input correct matrix!");
            break;
        case input_n_e:
            printf("Please, input correct n (number of lines)!");
            break;
        case input_m_e:
            printf("Please, input correct m (number of columns)!");
    }
    return code;
}
