/***********************************************************************
// OOP244 Workshop 2: read functions for foolproof integer and C string
//                    data entry
// File	Subject.cpp

	¢º Name: Youjin An
	¢º Part: in_lab
	¢º Date: 2019/09/22

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Subject.h"
#include "utils.h"

using namespace std;

namespace sdds {

	void read(char* m_subjectName) {
		cout << "Enter subject name: ";
		read(m_subjectName, 71, "Name is too long, only 70 characters allowed!\nRedo Entry: ");
	}
	
	void read(int& m_noOfSections) {
		cout << "Enter number of sections: ";
		read(m_noOfSections, 1, 10, "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ");
	}

	void read(int m_noOfStdsInSecs[], int m_noOfSections) {
		cout << "Enter the number of students in each one of the " << m_noOfSections << " sections: " << endl;

		for (int i = 0; i < m_noOfSections; i++) {
			cout << i + 1 << ": ";
			read(m_noOfStdsInSecs[i], 5, 35, "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ");
		}
	}

	void read(Subject& Sub) {
		Sub.m_subjectName = new char[71];
		read(Sub.m_subjectName); // void read(char* sub_name)

		Sub.m_noOfSections = new int;
		read(*Sub.m_noOfSections); // void read(int& Num_sub_section)

		Sub.m_noOfStdsInSecs = new int[*Sub.m_noOfSections];
		read(Sub.m_noOfStdsInSecs, *Sub.m_noOfSections);  // void read(int m_noOfStdsInSecs[], int sections_num) 
	}

	int report(const Subject& Sub) {

		int total_enroll = 0;

		for (int i = 0; i < *Sub.m_noOfSections; i++) {
			
			if (i == *Sub.m_noOfSections - 1) {
				cout << Sub.m_noOfStdsInSecs[i] << endl;
			}
			else {
				cout << Sub.m_noOfStdsInSecs[i] << ", ";
			}
			total_enroll += Sub.m_noOfStdsInSecs[i];
		}

		cout << Sub.m_subjectName << ": " << total_enroll << endl;

		return total_enroll;
	}

	void freeMem(Subject& Sub) {
		delete Sub.m_noOfSections;
		delete[] Sub.m_noOfStdsInSecs;
		delete[] Sub.m_subjectName;
	}
}
