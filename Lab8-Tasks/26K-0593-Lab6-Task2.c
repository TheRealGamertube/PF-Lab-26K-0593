#include <stdio.h>

#define MAX 5

void readMatrix(int a[MAX][MAX], int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
}

int isZero(int a[MAX][MAX], int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (a[i][j] != 0)
                return 0;
    return 1;
}

/* off-diagonal elements all zero (square matrices only) */
int isDiagonal(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && a[i][j] != 0)
                return 0;
    return 1;
}

int isScalar(int a[MAX][MAX], int n)
{
    if (!isDiagonal(a, n))
        return 0;
    for (int i = 1; i < n; i++)
        if (a[i][i] != a[0][0])
            return 0;
    return 1;
}

int isIdentity(int a[MAX][MAX], int n)
{
    return isScalar(a, n) && a[0][0] == 1;
}

int isUpper(int a[MAX][MAX], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i][j] != 0)
                return 0;
    return 1;
}

int isLower(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i][j] != 0)
                return 0;
    return 1;
}

int isSymmetric(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != a[j][i])
                return 0;
    return 1;
}

int isSkewSymmetric(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != -a[j][i])
                return 0;
    return 1;
}

/* determinant by cofactor expansion along the first row */
long long determinant(int a[MAX][MAX], int n)
{
    if (n == 1)
        return a[0][0];
    if (n == 2)
        return (long long)a[0][0] * a[1][1] - (long long)a[0][1] * a[1][0];

    long long det = 0;
    int sign = 1;
    for (int col = 0; col < n; col++)
    {
        int minor[MAX][MAX];
        for (int i = 1; i < n; i++)
        {
            int mc = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == col)
                    continue;
                minor[i - 1][mc++] = a[i][j];
            }
        }
        det += sign * a[0][col] * determinant(minor, n - 1);
        sign = -sign;
    }
    return det;
}

void multiply(int x[MAX][MAX], int y[MAX][MAX], int res[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < n; k++)
                res[i][j] += x[i][k] * y[k][j];
        }
}

int isIdempotent(int a[MAX][MAX], int n)
{
    int sq[MAX][MAX];
    multiply(a, a, sq, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (sq[i][j] != a[i][j])
                return 0;
    return 1;
}

/* A is nilpotent if A^k = 0 for some k <= n */
int isNilpotent(int a[MAX][MAX], int n)
{
    int power[MAX][MAX], temp[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            power[i][j] = a[i][j];

    for (int k = 1; k <= n; k++)
    {
        if (isZero(power, n, n))
            return 1;
        multiply(power, a, temp, n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                power[i][j] = temp[i][j];
    }
    return 0;
}

int main(void)
{
    int a[MAX][MAX], b[MAX][MAX];
    int r, c;

    printf("Enter number of rows (1-%d): ", MAX);
    scanf("%d", &r);
    printf("Enter number of columns (1-%d): ", MAX);
    scanf("%d", &c);

    if (r < 1 || r > MAX || c < 1 || c > MAX)
    {
        printf("Invalid size. Rows and columns must be between 1 and %d.\n", MAX);
        return 1;
    }

    readMatrix(a, r, c);

    printf("\nMatrix entered:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    printf("\nMatrix types:\n");

    /* shape */
    if (r == c)
        printf("- Square Matrix\n");
    else
        printf("- Rectangular Matrix\n");
    if (r == 1)
        printf("- Row Matrix\n");
    if (c == 1)
        printf("- Column Matrix\n");

    /* works for any shape */
    if (isZero(a, r, c))
        printf("- Zero Matrix\n- Null Matrix\n");

    /* square-only properties */
    if (r == c)
    {
        int n = r;

        if (isIdentity(a, n))
            printf("- Identity Matrix\n");
        if (isDiagonal(a, n))
            printf("- Diagonal Matrix\n");
        if (isScalar(a, n))
            printf("- Scalar Matrix\n");
        if (isUpper(a, n))
            printf("- Upper Triangular Matrix\n");
        if (isLower(a, n))
            printf("- Lower Triangular Matrix\n");
        if (isSymmetric(a, n))
            printf("- Symmetric Matrix\n");
        if (isSkewSymmetric(a, n))
            printf("- Skew-Symmetric Matrix\n");

        if (determinant(a, n) == 0)
            printf("- Singular Matrix (determinant = 0)\n");
        else
            printf("- Non-Singular Matrix (determinant = %lld)\n", determinant(a, n));

        if (isIdempotent(a, n))
            printf("- Idempotent Matrix\n");
        if (isNilpotent(a, n))
            printf("- Nilpotent Matrix\n");
    }
    else
    {
        printf("(Identity, diagonal, scalar, triangular, symmetric, skew-symmetric,\n"
               " singular, idempotent and nilpotent apply only to square matrices.)\n");
    }

    /* equality with a second matrix */
    char choice;
    printf("\nCompare with another matrix? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        printf("Enter second matrix (%d x %d):\n", r, c);
        readMatrix(b, r, c);

        int equal = 1;
        for (int i = 0; i < r && equal; i++)
            for (int j = 0; j < c; j++)
                if (a[i][j] != b[i][j])
                {
                    equal = 0;
                    break;
                }

        if (equal)
            printf("- Equal Matrix: both matrices are equal.\n");
        else
            printf("- The matrices are not equal.\n");
    }

    return 0;
}