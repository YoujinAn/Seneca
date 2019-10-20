/***********************************************************************
// IPC144 Workshop 3 Logic
// File temp.c

	▶ Name: Youjin An
	▶ Part: at_home

***********************************************************************/

#include <stdio.h>

// 1. The declaration of main define NUMS as 3
#define NUMS 4

int main()
{	
	int i, high, low;
	double high_sum = 0, low_sum = 0;
	int highest = -40, hightest_day = 0, lowest = 40, lowest_day = 0;

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
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be great111er than low.\n");
			
			printf("\nEnter the high value for day %d: ", i+1);
			scanf_s("%d", &high);
			printf("\nEnter the low value for day %d: ", i+1);
			scanf_s("%d", &low);
		} // the end of 'while'

		high_sum += high;
		low_sum += low;

		if (highest < high) {
			highest = high;
			hightest_day = i+1;
		}
		if (lowest > low)
		{
			lowest = low;
			lowest_day = i+1;
		}
	} // the end of 'for'

	// Display the highest temperature
	printf("\nThe average (mean) LOW temperature was: %.2lf", low_sum / NUMS);
	printf("\nThe average (mean) HIGH temperature was: %.2lf", high_sum / NUMS);
	printf("\nThe average (mean) temperature was: %.2lf", (high_sum + low_sum) / (2.0 *NUMS));
	printf("\nThe highest temperature was %d, on day %d", highest, hightest_day);
	printf("\nThe lowest temperature was %d, on day %d\n", lowest, lowest_day);


	return 0;
}
	

