#include <stdio.h>
#include <math.h>
#define MATRIX_SIZE 20

typedef enum
{
    ok, input_matrix_e, input_size_matrix_e,
} status_codes;

int input_matrix(int size_matrix, int matr[MATRIX_SIZE][MATRIX_SIZE])
{
    status_codes code = ok;
    for (int i = 0; i < size_matrix; i++)
    {
        for (int j = 0; j < size_matrix; j++)
            if (scanf("%d", &matr[i][j]) != 1)
            {
                code = input_matrix_e;
                break;
            }
    }
    return code;
}

int sum_numbers(int matr[MATRIX_SIZE][MATRIX_SIZE], int size_matrix)
{
    int sum = 0;
    for (int i = 0; i < size_matrix; i++)
    {
        for (int j = 0; j < size_matrix; j++)
            sum += matr[i][j];
    }
    return sum;
}

int check_matrix(int matr[MATRIX_SIZE][MATRIX_SIZE], int size_matrix)
{
    int up = 0;
    int sum = sum_numbers(matr, size_matrix);
    int down = sum;
    int ind = 0;
    for (int k = size_matrix - 1; k >= 0; k--)
    {
        down = sum;
        up = 0;
        for (int i = size_matrix - 1; i >= 0; i--)
        {
            for (int j = 0; j < size_matrix; j++)
            {
                if (j - i == k)
                {
                    down -= matr[i][j];
                }
                else if (j - i > k && i <= j)
                    up+=matr[i][j];
            }
        }
        down -= up;
        if (down == up)
            return ind;
        ind +=1;
    }
    for (int k = size_matrix - 1; k >= 0; k--)
    {
        down = sum;
        up = 0;
        for (int i = size_matrix - 1; i >= 0; i--)
        {
            for (int j = 0; j < size_matrix; j++)
            {
                if (j - i == -1 * k)
                {
                    down -= matr[i][j];
                }
                else if (j - i > -1 * k && i <= j)
                    up+=matr[i][j];
            }
        }
        down -= up;
        if (down == up)
            return ind;
        ind +=1;
    }
    if (ind == 9)
        return -1;
    else
    {
        return ind;
    }
    

}


int main()
{
    status_codes code = ok;
    int matr[MATRIX_SIZE][MATRIX_SIZE];
    int size_matrix;
    printf("Input size of matrix: ");
    if (scanf("%d", &size_matrix) != 1 || size_matrix > MATRIX_SIZE || input_matrix_e <= 0)
        code = input_size_matrix_e;
    else
        code = input_matrix(size_matrix, matr);
    switch (code)
    {
        case ok:
            printf("%d", check_matrix(matr, size_matrix));
            break;
        case input_matrix_e:
            printf("Please, input correct matrix!");
            break;
        case input_size_matrix_e:
            printf("Please, input correct n (number of lines)!");
            break;
    }
    return code;
}
