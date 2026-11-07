#include <stdio.h>

void showLinked(int *linked);

int main(void)
{
    int readings[7];
    int *ptr = readings;
    int *linked = NULL;
    int total = 0, highest, highest_day = 1, threshold;

    for (int i = 0; i < 7; i++)
    {
        printf("Enter reading for day %i: ", i + 1);
        scanf("%i", ptr + i);
    }

    printf("\nDay  Reading  Address\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%-4i %-8i %p\n", i + 1, *(ptr + i), (void *)(ptr + i));
    }

    int gap = (int)((char *)(ptr + 1) - (char *)ptr);
    printf("\nDistance between consecutive addresses: %i bytes\n", gap);
    printf("Reason: each int occupies %i bytes, and ptr + 1 moves forward by one whole element, so consecutive addresses differ by sizeof(int) = %i bytes.\n", (int)sizeof(int), (int)sizeof(int));

    highest = *ptr;
    for (int i = 0; i < 7; i++)
    {
        total = total + *(ptr + i);
        if (*(ptr + i) > highest)
        {
            highest = *(ptr + i);
            highest_day = i + 1;
        }
    }
    printf("\nWeekly total: %i\n", total);
    printf("Highest consumption: %i on day %i\n", highest, highest_day);

    printf("\nEnter the peak-tariff threshold: ");
    scanf("%i", &threshold);

    for (int i = 0; i < 7; i++)
    {
        if (*(ptr + i) > threshold)
        {
            *(ptr + i) = *(ptr + i) * 2;
        }
    }

    printf("\nReadings after peak-tariff adjustment:\n");
    for (int i = 0; i < 7; i++)
    {
        printf("Day %i: %i\n", i + 1, *(ptr + i));
    }

    printf("\nLinked meter (unassigned):\n");
    showLinked(linked);

    linked = ptr + 2;
    printf("\nLinked meter (assigned to day 3):\n");
    showLinked(linked);

    return 0;
}

void showLinked(int *linked)
{
    if (linked == NULL)
    {
        printf("No linked meter assigned.\n");
    }
    else
    {
        printf("Linked meter reading: %i\n", *linked);
    }
}
