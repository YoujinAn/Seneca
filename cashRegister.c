//----------------------------------------------
// Name:           Youjin An
// Student Number: 140413188
// Email:          yan24@myseneca.ca
// Section:        SAA
// Workshop:       2 (in-lab)
//----------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include <stdio.h>

int main(void)
{
	double amount, balance;
	int loonies, quarter;

	/* Accept data from a user */
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);


	loonies = (int) amount;
	balance = amount - loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, balance);


	quarter = (int)(balance / 0.25);
	balance = balance - (quarter * 0.25);
	printf("Quarters required: %d, balance owing $%.2lf\n", quarter, balance);


	return 0;
}
