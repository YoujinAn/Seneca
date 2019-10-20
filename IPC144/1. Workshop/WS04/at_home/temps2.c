/***********************************************************************
// IPC144 Workshop 4 Arrys
// File temps2.c

	▶ Name: Youjin An
	▶ Part: at_home

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

// Place your code below

#include <stdio.h>

int main()
{
	int i, NUM, Hight[10], Low[10];
	int highest = -40, lowest = 40, highest_day, lowest_day;

	// 1. All temperatures entered by the user must be stored in matching (parallel) arrays.
	// 2. Print the title of the application
	printf("---=== IPC Temperature Calculator V2.0 ===---");

	// 3. Prompt the user to enter the number of days for which the temperature will
	// be tracked.The value entered must be between 3 and 10, inclusive
	printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &NUM);

	// 4. If the user does not enter a value in the correct range, print the following error message
	while (NUM < 3 || NUM > 10) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &NUM);
	}

	printf("\n");
	// 5. Using a for loop, prompt the user to enter the high and low temperature until
	// data is entered for the required number of days, store the values entered in
	// matching(parallel) arrays
	for (i = 0; i < NUM; i++) {
		printf("Day %d - High: ", i + 1);
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


		// ---------- highest / lowest ----------
		if (highest < Hight[i])
		{
			highest = Hight[i];
			highest_day = i + 1;
		}

		if (lowest > Low[i])
		{
			lowest = Low[i];
			lowest_day = i + 1;
		}
	} // end for

	printf("\n");
	// 6. When the process is finished, display the values entered
	printf("Day  Hi  Low\n");
	for (i = 0; i < NUM; i++) {
		printf("%d    %d    %d\n", i + 1, Hight[i], Low[i]);
	}

	printf("\n");

	// ---------------------------------------- at_home ----------------------------------------

	// 1. Display the highest temperature, and the day on which it occurred
	printf("The highest temperature was %d, on day %d\n", highest, highest_day);

	// 2. Display the lowest temperature, and the day on which it occurred
	printf("The lowest temperature was %d, on day %d\n", lowest, lowest_day);


	// 3. Calculate and display the mean (average) temperature for a period entered by the user, 
	// until the user enters - 1

	int stop = 0, nbdays;
	// int total_Low, total_High;
	double avgLow, avgHigh;

	while (stop == 0)
	{
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", NUM);
		scanf("%d", &nbdays); // use scanf to get nbdays

		if (nbdays < 0) // check if nbdays is negative and stop the loop
		{
			stop = 1; // if so put stop to 1
		}
		else {
			// whithin a while loop, keep prompting the user to enter nbdays in [1 NUM]
			while (1 > nbdays || nbdays > NUM) // as long as nbdays not in [1 5]
			{
				printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", NUM);
				scanf("%d", &nbdays); // use scanf to get nbdays
			}

			// at this point nbdays is valid
			// calculate the average low and high for the number of days given by the user
			// loop through LOW and HIGH arrays from i=0 up to nbdays

			avgLow = 0, avgHigh = 0;
			// total_Low = 0, total_High = 0;

			for (i = 0; i < nbdays; i++) {
				avgHigh += Hight[i];
				avgLow += Low[i];
			}

			printf("\nThe average temperature up to day %d is: %.2lf", nbdays, (avgHigh + avgLow) / (nbdays * 2));
			printf("\n");
		}
	} // end while

	printf("\n");
	printf("Goodbye!\n");

	return 0;
}