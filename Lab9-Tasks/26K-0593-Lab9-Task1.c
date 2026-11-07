#include <stdio.h>
#include <stdbool.h>

int isValid(float price1, int qty1, float price2, int qty2);
float lineTotal(float price, int quantity);
float calcDiscount(float subtotal);
float finalAmount(float subtotal, float discount);
int higherPrice(float price1, float price2);

int main(void)
{
    float Price_1, Price_2, total1, total2, subtotal, discount, final_Amount;
    int Quantity_1, Quantity_2;
    bool flag = true;

    while (flag)
    {
        printf("Enter price for item 1: ");
        scanf("%f", &Price_1);
        printf("Enter quantity for item 1: ");
        scanf("%i", &Quantity_1);
        printf("Enter price for item 2: ");
        scanf("%f", &Price_2);
        printf("Enter quantity for item 2: ");
        scanf("%i", &Quantity_2);

        if (isValid(Price_1, Quantity_1, Price_2, Quantity_2) == 1)
        {
            flag = false;
        }
        else
        {
            printf("Error! Please input values again\n");
        }
    }

    total1 = lineTotal(Price_1, Quantity_1);
    total2 = lineTotal(Price_2, Quantity_2);

    subtotal = total1 + total2;

    discount = calcDiscount(subtotal);

    final_Amount = finalAmount(subtotal, discount);

    printf("\n=========== FAST CANTEEN RECEIPT ===========\n");
    printf("%-8s %10s %5s %14s\n", "Item", "Unit Price", "Qty", "Line Total");
    printf("--------------------------------------------\n");
    printf("%-8s %10.2f %5d %14.2f\n", "Item 1", Price_1, Quantity_1, total1);
    printf("%-8s %10.2f %5d %14.2f\n", "Item 2", Price_2, Quantity_2, total2);
    printf("--------------------------------------------\n");
    printf("%-25s %18.2f\n", "Subtotal:", subtotal);
    printf("%-25s %18.2f\n", "Discount:", discount);
    printf("--------------------------------------------\n");
    printf("%-25s %18.2f\n", "Total Payable (Rs.):", final_Amount);
    printf("============================================\n");

    int higher = higherPrice(Price_1, Price_2);
    if (higher == 1)
        printf("Item 1 has the higher unit price.\n");
    else if (higher == 2)
        printf("Item 2 has the higher unit price.\n");
    else
        printf("Both items have the same unit price.\n");
}

int isValid(float price1, int qty1, float price2, int qty2)
{
    if (price1 >= 0 && qty1 >= 0 && price2 >= 0 && qty2 >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

float lineTotal(float price, int quantity)
{
    float total = 0;
    total = price * quantity;
    return total;
}

float calcDiscount(float subtotal)
{
    float discounted;

    if (subtotal > 1000)
    {
        discounted = subtotal * 0.1;
        return discounted;
    }
    else
    {
        return subtotal;
    }
}

float finalAmount(float subtotal, float discount)
{
    float final;

    final = subtotal - discount;
    return final;
}

int higherPrice(float price1, float price2)
{
    if (price1 > price2)
    {
        return 1;
    }
    else if (price2 > price1)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}