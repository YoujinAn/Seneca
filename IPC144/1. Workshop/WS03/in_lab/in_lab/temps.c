/***********************************************************************
// IPC144 Workshop 3 Logic
// File temp.c

	▶ Name: Youjin An
	▶ Part: in_lab

***********************************************************************/

#include <stdio.h>

// 1. The declaration of main define NUMS as 3
#define NUMS 3

int main()
{	
	int i, high, low;

	// 2. Print the title of the application.
	printf("---=== IPC Temperature Analyzer ===---");

	// 3. Using a for loop, prompt the user to enter the high and low values for each of NUMS days.
	// The values entered must be between - 40 and 40, and high must be greater than low.
	for (i = 0; i < NUMS; i++)
	{
		printf("\nEnter the high value for day %d: ", i+1);
		scanf_s("%d", &high);
		printf("\nEnter the low value for day %d: ", i+1);
		scanf_s("%d", &low);

		while (high < low || high > 40 || low < -40)
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.");
			
			printf("\nEnter the high value for day %d: ", i+1);
			scanf_s("%d", &high);
			printf("\nEnter the low value for day %d: ", i+1);
			scanf_s("%d", &low);
		} // the end of 'while'
	} // the end of 'for'



	return 0;
}