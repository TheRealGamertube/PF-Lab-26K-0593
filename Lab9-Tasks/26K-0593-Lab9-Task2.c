#include <stdio.h>
#include <stdbool.h>

int calcTotal(int marks[], int size);
float calcAverage(int total, int size);
int findHighest(int marks[], int size);
int findLowest(int marks[], int size);
int countPass(int marks[], int size, int threshold);
int countTopScorers(int marks[], int size, int highest);
void applyBonus(int marks[], int size, int bonus);
void printReport(int marks[], int size, int threshold);

int main(void)
{
    int marks[10], pass_thresh, bonus;

    printf("Enter the passing threshold: ");
    scanf("%i", &pass_thresh);

    printf("Enter the bonus marks to be awarded: ");
    scanf("%i", &bonus);

    for (int i = 0; i < 10; i++)
    {
        printf("Enter marks for student %i: ", i + 1);
        scanf("%i", &marks[i]);

        while (marks[i] < 0 || marks[i] > 100)
        {
            printf("Invalid mark. Enter marks (0-100) for student %i: ", i + 1);
            scanf("%i", &marks[i]);
        }
    }

    printf("\n--- Before Bonus ---");
    printReport(marks, 10, pass_thresh);

    applyBonus(marks, 10, bonus);

    printf("\n--- After Bonus ---");
    printReport(marks, 10, pass_thresh);

    return 0;
}

int calcTotal(int marks[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total = total + marks[i];
    }
    return total;
}

float calcAverage(int total, int size)
{
    float avg = 0;
    avg = (float)total / size;
    return avg;
}

int findHighest(int marks[], int size)
{
    int highest = marks[0];

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }
    return highest;
}

int findLowest(int marks[], int size)
{
    int lowest = marks[0];

    for (int i = 1; i < size; i++)
    {
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }
    return lowest;
}

int countPass(int marks[], int size, int threshold)
{
    int count_pass = 0;
    for (int i = 0; i < size; i++)
    {
        if (marks[i] >= threshold)
        {
            count_pass++;
        }
    }
    return count_pass;
}

int countTopScorers(int marks[], int size, int highest)
{
    int high_count = 0;
    for (int i = 0; i < size; i++)
    {
        if (marks[i] == highest)
        {
            high_count++;
        }
    }
    return high_count;
}

void applyBonus(int marks[], int size, int bonus)
{
    for (int i = 0; i < size; i++)
    {
        marks[i] += bonus;

        if (marks[i] > 100)
        {
            marks[i] = 100;
        }
        else if (marks[i] < 0)
        {
            marks[i] = 0;
        }
    }
}

void printReport(int marks[], int size, int threshold)
{
    int total = calcTotal(marks, size);
    int highest = findHighest(marks, size);

    printf("\n========== MARKS ANALYSIS ==========\n");
    printf("Total marks:        %d\n", total);
    printf("Average:            %.2f\n", calcAverage(total, size));
    printf("Highest mark:       %d\n", highest);
    printf("Lowest mark:        %d\n", findLowest(marks, size));
    printf("Passed (>= %d):     %d\n", threshold, countPass(marks, size, threshold));
    printf("Students with top mark: %d\n", countTopScorers(marks, size, highest));
    printf("====================================\n");
}