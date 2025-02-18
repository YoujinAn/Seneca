/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File graph.cpp

	�� Name: Youjin An
	�� Email : yan24@myseneca.ca
	�� Part: in_lab
	�� Date: 2019/09/12

***********************************************************************/

#include <iostream>
#include <iomanip>

#include "tools.h"
#include "graph.h"

using namespace std;

// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples) {
	int i;
	for (i = 0; i < noOfSamples; i++) {
		line(28);
		cout << "\\ " << (i + 1) << "/" << setw(2) << setiosflags(ios::left) << noOfSamples << ":                    /";
		goBack(20);
		samples[i] = getInt(1, 1000000);
	}
}

// finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
// otherwise it will return GRAPH_WIDTH. 
int findMax(int samples[], int noOfSamples) {
	int max = samples[0];
	int i;
	for (i = 1; i < noOfSamples; i++) {
		if (max < samples[i]) max = samples[i];
	}
	return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
}

// prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max) {
	int i;
	int barlength = GRAPH_WIDTH * val / max;
	cout << "| ";
	for (i = 0; i < barlength; i++) {
		cout << "*";
	}
	cout << " " << setw(GRAPH_WIDTH + 6 - barlength) << setiosflags(ios::left) << val << "|" << endl;
}

// prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples) {
	int max = findMax(samples, noOfSamples);
	line(GRAPH_WIDTH + 10, " Graph ");
	for (int i = 0; i < noOfSamples; i++) {
		printBar(samples[i], max);
	}
	line(GRAPH_WIDTH + 10);
}