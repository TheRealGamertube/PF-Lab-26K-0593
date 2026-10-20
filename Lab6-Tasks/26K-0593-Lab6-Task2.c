#include <stdio.h>

int main(void)
{
	int comb_value, lights = 1, w_heater = 2, ac =4, camera =8, menu_choice;
	
	printf("Enter the resident's current combined appliance value: ");
	scanf("%i", &comb_value);
	
	while(comb_value != -1)
	{
		printf("Enter your choice:\n1.Turn water heater on\n2.Turn AC off\n3.Toggle the lights\n4.Camera status\n");
		scanf("%i", &menu_choice);
		
		switch(menu_choice)
		{
			case 1:
				comb_value = comb_value | 2;
				printf("New combined value: %i\n", comb_value);
				break;
				
			case 2:
				comb_value = comb_value &~ 4;
				printf("New combined value: %i\n", comb_value);
				break;
				
			case 3:
				comb_value = comb_value ^ 1;
				printf("New combined value: %i\n", comb_value);
				break;
				
			case 4:
				if (comb_value & 8)
				{
					printf("Camera is active\n");
				}
				else
				{
					printf("Camera is not active\n");
				}				
				
				break;
				
			default:
				printf("Invalid input! Please try again\n");
				break;
			
		}
		
		if ((comb_value & 2) && (comb_value & 4))
		{
			printf("AC and water heater both are on. Overload risk!\n");
		}
		
	printf("Enter the resident's current combined appliance value: ");
	scanf("%i", &comb_value);
		
	}
	
	
	
}
