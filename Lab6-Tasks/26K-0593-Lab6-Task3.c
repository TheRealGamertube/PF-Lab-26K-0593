#include <stdio.h>

int main(void)
{
	int i, st_count, marks1, marks2, marks3, avg;; 
	char grade;
	
	printf("Enter total number of students: ");
	scanf("%i", &st_count);
	
	for (i = 0; i < st_count; i++)
	{
		printf("Input marks 1 : ");
		scanf("%i", &marks1);
		printf("Input marks 2 : ");
		scanf("%i", &marks2);
		printf("Input marks 3 : ");
		scanf("%i", &marks3);
		
		if ((marks1 >= 0 && marks1 <= 100) && (marks2 >= 0 && marks2 <= 100) && (marks3 >= 0 && marks3 <= 100))
		{
			avg = (marks1 + marks2 + marks3) / 3;
			
			switch(avg/10)
			{
				case 9 ... 10:
					grade ='A';
					break;				
				case 8:
					grade = 'B';
					break;
				case 7:
					grade = 'C';
					break;
				case 6:
					grade = 'D';
					break;
				case 0 ... 5:
					grade = 'F';
					break;
			}
			
			printf("Average: %i\nGrade : %c\n", avg, grade);
			printf("%s", (avg >= 60 && marks1 >= 40 && marks2 >= 40 && marks3 >=40)? "PASS\n" : "FAIL\n");
			 
		}
		else
		{
			printf("Invalid input! Try again\n");
		}
		
	}
}
