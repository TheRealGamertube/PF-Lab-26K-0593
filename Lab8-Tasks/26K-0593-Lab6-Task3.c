#include <stdio.h>
int main(void)
{
    int row1, col1, row2, col2;

    printf("Input rows and columns for matrix 1: ");
    scanf("%i %i", &row1, &col1);

    printf("Input rows and columns for matrix 2: ");
    scanf("%i %i", &row2, &col2);

    int matrix1[row1][col1],
        matrix2[row2][col2];

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("Input matrix 1 value at row %i col %i : ", i, j);
            scanf("%i", &matrix1[i][j]);
        }
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("Input matrix 2 value at row %i col %i : ", i, j);
            scanf("%i", &matrix2[i][j]);
        }
    }
    int result[row1][col2];

    if (col1 == row2)
    {
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < col1; k++)
                {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%i  ", result[i][j]);
        }
        printf("\n");
    }
}