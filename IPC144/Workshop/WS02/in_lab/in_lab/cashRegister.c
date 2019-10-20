/***********************************************************************
// IPC144 Workshop 2 Computations
// File cashRegister.c

	▶ Name: Youjin An
	▶ Part: in_lab

***********************************************************************/

#include <stdio.h>

int main()
{
	double amount, balance;
	int loonies = 1, quarter;

	// Start the program by asking the user to enter the amount due.
	printf("Please enter the amount to be paid: $");
	// Assume the user enters 8.68. 
	// Read the amount due and store it as a double.
	scanf("%lf", &amount);
	
	// Calculate the number of loonies and quarters required to pay the amount due and display
	// Loonies (1 doller)
	loonies = amount / loonies;
	balance = amount - loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, balance);

	// Quarters (25 cent)
	quarter = balance / 0.25;
	balance = balance - (quarter * 0.25);
	printf("Quarters required: %d, balance owing $%.2lf\n", quarter, balance);

	return 0;
}