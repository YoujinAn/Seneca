//----------------------------------------------
// Name:           Youjin An
// Student Number: 140413188
// Email:          yan24@myseneca.ca
// Section:        SII
// Workshop:       2 (at-home)
//----------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
// Start your code below:

#include <stdio.h>

int main(void)
{
	double GTS;
	double amount;
	int loonies, quarter, dimes, nickels, pennies, total, balance;

	// Accept data from a user
	printf("Please enter the amount to be paid: $ ");
	scanf("%lf", &amount);

	// GST information
	GTS = (amount * 0.13) + 0.005;
	printf("GST: %.2lf\n", GTS); // 1.13
	total = (amount + GTS) * 100;
	printf("Balance owing: $ %.2f\n", amount); //

	// Loonies 
	loonies = total / 100;
	balance = total % 100;
	printf("Loonies required: %d, balance owing $ %.2lf\n", loonies, (float)balance / 100);

	// Quarters
	quarter = balance / 25;
	balance = balance % 25;
	printf("Quarters required: %d, balance owing $ %.2lf\n", quarter, (float)balance / 100);

	// Dimes
	dimes = balance / 5;
	balance = balance % 10;
	printf("Dimes required: %d, balance owing $ %.2lf\n", dimes, (float)balance / 100);

	// Nickels
	nickels = balance / 5;
	balance = balance % 5;
	printf("Nickels required: %d, balance owing $ %.2lf\n", nickels, (float)balance / 100);

	// Pennies
	pennies = balance / 1;
	balance = balance % 1;
	printf("Pennies required: %d, balance owing $ %.2lf\n", pennies, (float)balance / 100);


	return 0;
}