/***********************************************************************
// IPC144 Workshop 4 Arrys
// File temps2.c

	▶ Name: Youjin An
	▶ Part: in_lab

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>

int main() 
{
	int i, NUM, Hight[10], Low[10];

	// 1. All temperatures entered by the user must be stored in matching (parallel) arrays.
	// 2. Print the title of the application
	printf("---=== IPC Temperature Calculator V2.0 ===---");

	// 3. Prompt the user to enter the number of days for which the temperature will
	// be tracked.The value entered must be between 3 and 10, inclusive
	printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &NUM);

	// 4. If the user does not enter a value in the correct range, print the following error message
	while ( NUM < 3 || NUM > 10) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &NUM);
	}

	printf("\n");
	// 5. Using a for loop, prompt the user to enter the high and low temperature until
	// data is entered for the required number of days, store the values entered in
	// matching(parallel) arrays
	for (i = 0; i < NUM; i++) {
		printf("Day %d - High: ", i+1);
		scanf("%d", &Hight[i]); // use sanf and get the value into Hight[i]

		printf("Day %d - Low: ", i + 1);
		scanf("%d", &Low[i]); // use sanf and get the value into Low[i]

		while (Hight[i] < Low[i] || Low[i] < -40 || Hight[i] > 40)
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high mush be greater than low.\n");

			printf("Day %d - High: ", i + 1);
			scanf("%d", &Hight[i]); // use sanf and get the value into Hight[i]

			printf("Day %d - Low: ", i + 1);
			scanf("%d", &Low[i]); // use sanf and get the value into Low[i]
		} // end while
	}

	printf("\n");
	// 6. When the process is finished, display the values entered
	printf("Day  Hi  Low\n");
	for (i = 0; i < NUM; i++) {
		printf("%d    %d    %d\n", i+1, Hight[i], Low[i]);
	}

	return 0;
}








