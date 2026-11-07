#include <stdio.h>

void printHall1(int (*hall)[4], int rows);
int countVacantHall1(int (*hall)[4], int rows);
void printHall2(int *hall[], int sizes[], int rows);
int countVacantHall2(int *hall[], int sizes[], int rows);
int bookSeat(int *hall[], int sizes[], int rows);

int main(void)
{
    int hall1[3][4] = {
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {1, 1, 0, 0}};

    int row1[3] = {0, 1, 0};
    int row2[5] = {1, 0, 0, 0, 1};
    int row3[7] = {0, 0, 1, 1, 0, 0, 0};

    int *hall2[3] = {row1, row2, row3};
    int sizes[3] = {3, 5, 7};

    printf("Hall 1 (X = booked, O = vacant):\n");
    printHall1(hall1, 3);
    printf("Vacant seats in Hall 1: %i\n", countVacantHall1(hall1, 3));

    printf("\nHall 2 (X = booked, O = vacant):\n");
    printHall2(hall2, sizes, 3);
    printf("Vacant seats in Hall 2: %i\n", countVacantHall2(hall2, sizes, 3));

    printf("\nBook a seat in Hall 2\n");
    if (bookSeat(hall2, sizes, 3))
    {
        printf("\nUpdated Hall 2:\n");
        printHall2(hall2, sizes, 3);
        printf("Vacant seats in Hall 2: %i\n", countVacantHall2(hall2, sizes, 3));
    }

    return 0;
}

void printHall1(int (*hall)[4], int rows)
{
    for (int (*row)[4] = hall; row < hall + rows; row++)
    {
        for (int *seat = *row; seat < *row + 4; seat++)
        {
            printf("%c ", *seat ? 'X' : 'O');
        }
        printf("\n");
    }
}

int countVacantHall1(int (*hall)[4], int rows)
{
    int vacant = 0;

    for (int (*row)[4] = hall; row < hall + rows; row++)
    {
        for (int *seat = *row; seat < *row + 4; seat++)
        {
            if (*seat == 0)
            {
                vacant++;
            }
        }
    }
    return vacant;
}

void printHall2(int *hall[], int sizes[], int rows)
{
    for (int r = 0; r < rows; r++)
    {
        for (int s = 0; s < sizes[r]; s++)
        {
            printf("%c ", *(*(hall + r) + s) ? 'X' : 'O');
        }
        printf("\n");
    }
}

int countVacantHall2(int *hall[], int sizes[], int rows)
{
    int vacant = 0;

    for (int r = 0; r < rows; r++)
    {
        for (int s = 0; s < sizes[r]; s++)
        {
            if (*(*(hall + r) + s) == 0)
            {
                vacant++;
            }
        }
    }
    return vacant;
}

int bookSeat(int *hall[], int sizes[], int rows)
{
    int row, seat;

    printf("Enter row number (1-%i): ", rows);
    scanf("%i", &row);

    if (row < 1 || row > rows)
    {
        printf("Booking failed: row %i does not exist.\n", row);
        return 0;
    }

    printf("Enter seat number (1-%i): ", sizes[row - 1]);
    scanf("%i", &seat);

    if (seat < 1 || seat > sizes[row - 1])
    {
        printf("Booking failed: seat %i does not exist in row %i.\n", seat, row);
        return 0;
    }

    if (*(*(hall + row - 1) + seat - 1) == 1)
    {
        printf("Booking failed: row %i seat %i is already booked.\n", row, seat);
        return 0;
    }

    *(*(hall + row - 1) + seat - 1) = 1;
    printf("Row %i seat %i booked successfully.\n", row, seat);
    return 1;
}
