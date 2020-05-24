/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory

// File	School.h

	¢º Name: Youjin An
	¢º Part: at_home
	¢º Date: 2019/09/22

***********************************************************************/

#ifndef SDDS_SCHOOL_H
#define SDDS_SCHOOL_H

#include "Subject.h"

namespace sdds { 

	struct School {
		int m_noOfSubjects; // hold the number of subjects offered in a school
		Subject* m_subjects; // store all the subjects offered by the School
		char* m_name; // hold the name of the School
	};

	void read(School&);
	int report(const School&);
	void freeMem(School&);

}

#endif // SDDS_SUBJECT_H

