/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File tools.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: in_lab
	¢º Date: 2019/09/12

***********************************************************************/

#pragma once

// displays the user interface menu
int menu(int noOfSamples);
// moves the cursor backwards
void goBack(int n);
// Draws a line and adds a label if provided
void line(int n, const char* label = nullptr);
// Performs a fool-proof integer entry
int getInt(int min, int max);