/**
Упорядочить строки матрицы по убыванию их наименьших элементов.
*/

#include <stdio.h>
#define N 10

typedef enum
{
    ok, input_matrix_e, input_n_e, input_m_e,
} statuscodes;

/// Функция ввода матрицы
statuscodes input(int n, int m, int (*p)[N + 1])
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

/// Функция поиска минимума в строках матрицы и минимального элемента матрицы
int minimum_str(int (*start)[N + 1], int n, int m)
{
    int min = (*start)[0];
    int min_matr = (*start)[0];
    for (int i = 0; i < n; i++)
    {
        min = (*start)[0];
        for (int j = 0; j < m; j++)
        {
            if ((*start)[j] < min)
                min = (*start)[j];
            if ((*start)[j] < min_matr)
                min_matr = (*start)[j];
        }
        (*start)[m] = min;
        start++;
    }
    return min_matr;
}

/// Функция поиска максимума в строках матрицы
int maximum_matr(int (*start)[N + 1], int n, int m)
{
    int max = (*start)[m];
    int ind = 0;
    for (int j = 0; j < n; j++)
        if ((*(start + j))[m] > max)
        {
            ind = j;
            max = (*(start + j))[m];
        }
    return ind;
}

/// Функция вывода строки
void output(int (*p)[N + 1], int m)
{
    for (int i = 0; i < m; i++)
        printf("%d ", (*p)[i]);
    printf("\n");
}

int main()
{
    int code = ok;
    int matr[N][N + 1];
    int n, m;
    printf("Input n (number of lines), m (number of columns): ");
    if (scanf("%d", &n) != 1 || n > N || n <= 0)
        code = input_n_e;
    else if (scanf("%d", &m) != 1 || m > N || m <= 0)
        code = input_m_e;
    else
        code = input(n, m, &matr[0]);
    int ind;
    switch (code)
    {
        case ok:
            printf("Matrix:\n");
            int min = minimum_str(&matr[0], n, m);
            for (int i = 0; i < n; i++)
            {
                ind = maximum_matr(&matr[0], n, m);
                output(&matr[ind], m);
                matr[ind][m] = min - 1;
            }
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
    }
    return code;
}
