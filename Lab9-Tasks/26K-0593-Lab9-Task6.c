#include <stdio.h>

void printGeneric(void *data, char type);
int add(int a, int b, float *result);
int subtract(int a, int b, float *result);
int multiply(int a, int b, float *result);
int divide(int a, int b, float *result);
int calculate(int a, int b, int (*operation)(int, int, float *), float *result);

int main(void)
{
    int num = 42;
    float dec = 3.14159f;
    char ch = 'A';

    int a, b, choice;
    float result;
    int (*ops[4])(int, int, float *) = {add, subtract, multiply, divide};

    printf("Generic printer test:\n");
    printGeneric(&num, 'i');
    printGeneric(&dec, 'f');
    printGeneric(&ch, 'c');

    printf("\nEnter first number: ");
    scanf("%i", &a);
    printf("Enter second number: ");
    scanf("%i", &b);

    printf("\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("Enter your choice: ");
    scanf("%i", &choice);

    if (choice < 1 || choice > 4)
    {
        printf("Invalid choice.\n");
        return 0;
    }

    if (calculate(a, b, ops[choice - 1], &result))
    {
        printf("Result: ");
        printGeneric(&result, 'f');
    }
    else
    {
        printf("Error: operation could not be performed (division by zero).\n");
    }

    return 0;
}

void printGeneric(void *data, char type)
{
    switch (type)
    {
    case 'i':
        printf("%i\n", *(int *)data);
        break;
    case 'f':
        printf("%.2f\n", *(float *)data);
        break;
    case 'c':
        printf("%c\n", *(char *)data);
        break;
    default:
        printf("Unknown type\n");
    }
}

int add(int a, int b, float *result)
{
    *result = (float)(a + b);
    return 1;
}

int subtract(int a, int b, float *result)
{
    *result = (float)(a - b);
    return 1;
}

int multiply(int a, int b, float *result)
{
    *result = (float)a * b;
    return 1;
}

int divide(int a, int b, float *result)
{
    if (b == 0)
    {
        return 0;
    }
    *result = (float)a / b;
    return 1;
}

int calculate(int a, int b, int (*operation)(int, int, float *), float *result)
{
    return operation(a, b, result);
}
