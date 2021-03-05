/**
Поменять местами элементы, расположенные в показанной на рисунке области
(первая строка меняется с последней, вторая – с предпоследней и т.д.).
Элементы, расположенные на главной и побочных диагоналях, включены в обмен.
*/

#include <stdio.h>
#define N 10

typedef enum
{
    ok, input_matrix_e, input_n_e, input_m_e, not_kvadr,
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

/// Функция вывода видоизменённой матрицы
void output(int n, int m, int (*p)[N])
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((j < i && i < n - 1 - j) || (i > n - 1 - j && j > i))
                printf("%d ", (*(p + i))[j]);
            else
                printf("%d ", (*(p + n - 1 - i))[j]);
        }
        printf("\n");
    }
}

int main()
{
    int code = ok;
    int matr[N][N];
    int n, m;
    printf("Input n (number of lines), m (number of columns): ");
    if (scanf("%d", &n) != 1 || n > N || n <= 0)
        code = input_n_e;
    else if (scanf("%d", &m) != 1 || m > N || m <= 0)
        code = input_m_e;
    else if (m != n)
        code = not_kvadr;
    else
        code = input(n, m, &matr[0]);
    switch (code)
    {
        case ok:
            output(n, m, &matr[0]);
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
        case not_kvadr:
            printf("Please, input m == n!");
            break;
    }
    return code;
}
