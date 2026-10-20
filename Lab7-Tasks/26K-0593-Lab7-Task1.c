#include <stdio.h>

int main(void)
{
    int Temp[7] =
        {31, 33, 35, 34, 38, 36, 32};

    int highest = Temp[0], Lowest = Temp[0], sum = 0, size = sizeof(Temp) / sizeof(Temp[0]);
    float avg = 0;

    for (int i = 0; i < size; i++)
    {
        printf("Day %i: %i C\n", i + 1, Temp[i]);

        if (Temp[i] > highest)
        {
            highest = Temp[i];
        }
        if (Temp[i] < Lowest)
        {
            Lowest = Temp[i];
        }
        sum += Temp[i];
    }

    avg = sum / size;

    printf("Highest: %i\nLowest: %i\nAverage: %.2f\n", highest, Lowest, avg);

    Temp[2] = 37;

    sum = 0;
    avg = 0;
    highest = Temp[0];
    Lowest = Temp[0];

    for (int i = 0; i < size; i++)
    {
        printf("Day %i: %i C\n", i + 1, Temp[i]);

        if (Temp[i] > highest)
        {
            highest = Temp[i];
        }
        if (Temp[i] < Lowest)
        {
            Lowest = Temp[i];
        }
        sum += Temp[i];
        printf("Memory of address of index %i: %p\n", i, &Temp[i]);
    }

    avg = (float)sum / (float)size;
    printf("Highest: %i\nLowest: %i\nAverage: %.2f\N", highest, Lowest, avg);
    // Consecutive addressed differ by sizeof(int) bytes,
    // showing that array elements are store contigously in memory
}