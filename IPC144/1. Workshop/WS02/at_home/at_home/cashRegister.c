/***********************************************************************
// IPC144 Workshop 2 Computations
// File cashRegister.c

	▶ Name: Youjin An
	▶ Part: at_home

***********************************************************************/

#include <stdio.h>

int main()
{
	double amount, GST;
	int loonies, quarter, dimes, nickel, pennies, balance;

	// Start the program by asking the user to enter the amount due.
	printf("Please enter the amount to be paid: $");
	// Assume the user enters 8.68. 
	// Read the amount due and store it as a double.
	scanf_s("%lf", &amount);

	// GST
	GST = (amount * 0.13) + 0.005; // 1.13
	balance = (amount + GST) * 100; // 9.81
	printf("GST: %.2lf\n", GST);
	printf("Balance owing: $%.2f\n", (float)balance / 100);

	// The subsequent operations must be done using integer division(/) and modulus(%).
	// Loonies (1 doller)
	loonies = balance / 100;
	balance = balance % 100;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, (float)balance / 100);

	// Quarters (25 cents)
	quarter = balance / 25;
	balance = balance % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", quarter, (float)balance / 100);

	// Dimes (10 cents)
	dimes = balance / 10;
	balance = balance % 10;
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, (float)balance / 100);

	// Nickels (5 cents)
	nickel = balance / 5;
	balance = balance % 5;
	printf("Nickels required: %d, balance owing $%.2lf\n", nickel, (float)balance / 100);

	// Pennies (1 cent)
	pennies = balance / 1;
	balance = balance % 1;
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, (float)balance / 100);

	return 0;
}