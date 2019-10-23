/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory

// File	School.cpp

	¢º Name: Youjin An
	¢º Part: at_home
	¢º Date: 2019/09/22

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

#include "School.h"
#include "utils.h"

namespace sdds {

	void read(School& Sch) {

		char school_name [61] = "";
		cout << "Please enter the name of the school:\n> ";
		read(school_name, 61, "Name is too long, only 60 characters allowed!\nRedo Entry: ");

		Sch.m_name = new char[ strlen(school_name) + 1] ; // dynamically memory for 'school_name'
		strcpy(Sch.m_name, school_name);

		cout << "Please enter the number of subjects offered by " << Sch.m_name << ": ";
		read(Sch.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ");

		Sch.m_subjects = new Subject [Sch.m_noOfSubjects]; // dynamically memory for 'm_subjects'

		for (int i = 0; i < Sch.m_noOfSubjects; i++) {
			cout << i+1 << ") ------------------------------" << endl;
			read(Sch.m_subjects[i]);
		}
	}

	int report(const School& Sch) {
		int Sch_total_enroll = 0, total_enroll = 0;

		cout << Sch.m_name << endl;

		cout << "Subject Enrollments" << endl;
		for (int i = 0; i < Sch.m_noOfSubjects; i++) {
			total_enroll = report(Sch.m_subjects[i]);
			Sch_total_enroll += total_enroll;
		}

		cout << "Total enrollment: " << Sch_total_enroll << endl;

		return total_enroll;

	}

	void freeMem(School& Sch) {
		delete[] Sch.m_name;
		delete[] Sch.m_subjects;
	}

}
