/**
Удалить строку и столбец, на пересечении которых расположен элемент матрицы,
сумма цифр которого минимальна (предполагается, что такой элемент в матрице один)
*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef enum
{
    ok, input_matrix_e, input_n_e, input_m_e, many_min_e,
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

/// поиск суммы цифр
int sum_digits(int num)
{
    int sum = 0;
    while (abs(num) > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return abs(sum);
}

/// Функция поиска нужных индексов
statuscodes find_ind(int n, int m, int (*p)[N], int *str_ind, int *col_ind)
{
    statuscodes code = ok;
    int min_sum = sum_digits((*p)[0]);
    int count;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            count = sum_digits((*p)[j]);
            if (count < min_sum)
            {
                min_sum = count;
                *str_ind = i;
                *col_ind = j;
                code = ok;
            }
            else if (count == min_sum && (i + j) != 0)
                code = many_min_e;
        }
        p++;
    }
    return code;
}

/// Функция вывода матрицы
void output(int n, int m, int (*p)[N], int *str_ind, int *col_ind)
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        if (i != *str_ind)
        {
            for (int j = 0; j < m; j++)
            {
                if (j != *col_ind)
                {
                    printf("%d ", (*p)[j]);
                }
            }
            printf("\n");
        }
        p++;
    }
}

int main()
{
    int code = ok;
    int matr[N][N];
    int n, m;
    printf("Input n (number of lines), m (number of columns): ");
    if (scanf("%d", &n) != 1 || n > N || n <= 1)
        code = input_n_e;
    else if (scanf("%d", &m) != 1 || m > N || m <= 1)
        code = input_m_e;
    else
        code = input(n, m, &matr[0]);
    int str_ind = 0, col_ind = 0;
    if (code == ok)
        code = find_ind(n, m, &matr[0], &str_ind, &col_ind);
    switch (code)
    {
        case ok:
            output(n, m, &matr[0], &str_ind, &col_ind);
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
        case many_min_e:
            printf("Tne number with minimal sum of digits should be one!");
    }
    return code;
}
