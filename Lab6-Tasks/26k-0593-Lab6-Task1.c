#include <stdio.h>

int main(void)
{
	int age, show_cat, day, bonus;
	float disc = 0, price, total;
	
	printf("Enter your age: ");
	scanf("%i", &age);
	while (age != 0)
	{
		printf("What show category would you like:\n1.Regular Movie\n2.3D Movie\n3.Premiere Movie\n");
		scanf("%i", &show_cat);
		
		switch(show_cat)
		{
			case 1:
				price = 500;
				break;
				
			case 2:
				price = 800;
				break;
				
			case 3:
				price = 1200;
				break;
			
			default:
				printf("Error! invalid input\n");
				break;
				
		}
		
		if (age < 13)
		{
			disc = 30;
		}
		else if (age >= 60)
		{
			disc = 20;
		}
		
		printf("Enter the day of the month: ");
		scanf("%i", &day);
		
		if ((day % 5 == 0) && (day > 0 && day <= 31))
		{
			bonus = 50;
		}
		
		total = price * ((100-disc)/100) - 50;
		
		if (total < 100)
		{
			total = 100;
		}
		
		printf("---------------Receipt---------------\nAge : %i\nShow Category: %i\nDay : %i\nPrice : %.2f\nDiscount : %.0f%%\nBonus Discount : %i\nTotal : %.2f\n-------------------------------------\n", age, show_cat, day, price, disc, bonus, total);
		
		printf("Enter your age: ");
		scanf("%i", &age);
	}

	
	
	
	
}
