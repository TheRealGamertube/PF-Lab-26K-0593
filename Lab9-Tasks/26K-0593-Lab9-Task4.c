#include <stdio.h>

void repairWards(int *ward_a, int *ward_b);
void wrongSwap(int ward_a, int ward_b);
void summarise(int *week, int size, int *total, int *highest, int *lowest);

int main(void)
{
    int ward_a, ward_b, x, y;
    int week[7], total, highest, lowest;

    printf("Enter Ward A counter: ");
    scanf("%i", &ward_a);
    printf("Enter Ward B counter: ");
    scanf("%i", &ward_b);

    printf("\nBefore repair: A = %i, B = %i\n", ward_a, ward_b);
    printf("main: &ward_a = %p, &ward_b = %p\n", (void *)&ward_a, (void *)&ward_b);
    repairWards(&ward_a, &ward_b);
    printf("After repair: A = %i, B = %i\n", ward_a, ward_b);

    printf("\nEnter first test value: ");
    scanf("%i", &x);
    printf("Enter second test value: ");
    scanf("%i", &y);

    printf("\nBefore wrongSwap: x = %i, y = %i\n", x, y);
    printf("main: &x = %p, &y = %p\n", (void *)&x, (void *)&y);
    wrongSwap(x, y);
    printf("After wrongSwap: x = %i, y = %i\n", x, y);

    for (int i = 0; i < 7; i++)
    {
        printf("Enter occupancy for day %i: ", i + 1);
        scanf("%i", &week[i]);
    }

    printf("\nmain: week = %p, &total = %p, &highest = %p, &lowest = %p\n", (void *)week, (void *)&total, (void *)&highest, (void *)&lowest);
    summarise(week, 7, &total, &highest, &lowest);
    printf("Total: %i\n", total);
    printf("Highest: %i\n", highest);
    printf("Lowest: %i\n", lowest);

    return 0;
}

void repairWards(int *ward_a, int *ward_b)
{
    int temp;

    printf("repairWards: ward_a points to %p, ward_b points to %p\n", (void *)ward_a, (void *)ward_b);
    temp = *ward_a;
    *ward_a = *ward_b;
    *ward_b = temp;
}

void wrongSwap(int ward_a, int ward_b)
{
    int temp;

    printf("wrongSwap: &ward_a = %p, &ward_b = %p\n", (void *)&ward_a, (void *)&ward_b);
    temp = ward_a;
    ward_a = ward_b;
    ward_b = temp;
    printf("Inside wrongSwap after swapping: a = %i, b = %i\n", ward_a, ward_b);
}

void summarise(int *week, int size, int *total, int *highest, int *lowest)
{
    printf("summarise: week = %p, total = %p, highest = %p, lowest = %p\n", (void *)week, (void *)total, (void *)highest, (void *)lowest);

    *total = 0;
    *highest = week[0];
    *lowest = week[0];

    for (int i = 0; i < size; i++)
    {
        *total = *total + week[i];
        if (week[i] > *highest)
        {
            *highest = week[i];
        }
        if (week[i] < *lowest)
        {
            *lowest = week[i];
        }
    }
}
