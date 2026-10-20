#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    float marks[10], sum = 0, avg = 0;
    bool flag = false;
    int counter = 0;

    for (int count = 0; count < 10; count++)
    {
        flag = false;
        while (!flag)
        {
            printf("Enter marks for student %i: ", count + 1);
            scanf("%f", &marks[count]);
            if (marks[count] >= 0 && marks[count] <= 20)
            {
                sum += marks[count];
                flag = true;
            }
            else
            {
                printf("Please input between 1-20\n");
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Student %i marks: %.2f", i + 1, marks[i]);

        if (marks[i] >= 18)
        {
            printf(" Remarks: Excellent\n");
        }
        else if (marks[i] >= 14 && marks[i] <= 17.99)
        {
            printf(" Remarks: Good\n");
        }
        else if (marks[i] >= 10 && marks[i] <= 13.99)
        {
            printf(" Remarks: Average\n");
        }
        else
        {
            printf(" Remarks: Needs Improvement\n");
        }
    }
    avg = sum / 10;
    printf("The class average is %.2f\n", avg);

    for (int j = 0; j < 10; j++)
    {
        if (marks[j] > avg)
        {
            counter += 1;
        }
    }
    printf("Students above avg: %i\n", counter);

    avg = 0;
    sum = 0;
    for (int x = 0; x < 10; x++)
    {
        if (marks[x] + 1.5 <= 20)
        {
            marks[x] += 1.5;
        }
        else
        {
            marks[x] = 20;
        }
        sum += marks[x];
        printf("Updated marks of student %i: %.2f\n", x + 1, marks[x]);
    }
    avg = sum / 10;
    printf("Updated Average: %.2f", avg);
}