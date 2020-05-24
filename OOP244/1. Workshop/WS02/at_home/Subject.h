/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory

// File	Subject.h

	¢º Name: Youjin An
	¢º Part: at_home
	¢º Date: 2019/09/22

***********************************************************************/

#ifndef SDDS_SUBJECT_H
#define SDDS_SUBJECT_H

namespace sdds {

	struct Subject {
		int* m_noOfSections; // hold the number of sections of a subject in a school.
		int* m_noOfStdsInSecs; // store the number of students for each section.
		char* m_subjectName; // hold the name of the subject
	};

	void read(char*);
	void read(int&);
	void read(int[], int);
	void read(Subject&);
	int report(const Subject&);
	void freeMem(Subject&);

}

#endif