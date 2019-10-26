/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File MarksReport.cpp

	¢º Name: Youjin An
	¢º Part: DIY
	¢º Date: 2019/09/28

***********************************************************************/

#include <iostream>

using namespace std;

#include "MarksReport.h"
#include "ReportUtils.h"

namespace sdds {

	void MarksReport::initialize() {
		Marks = nullptr;
		Report_Title[0] = '\0';
		Num_Marks = 0;
	}

	void MarksReport::getMarks() {
		// Ask the user for the name of the report 
		cout << "Enter the report Name : " ;
		read(Report_Title, 61, "Name is too long, only 60 characters allowed!\nRedo Entry: ");

		// Ask the number of marks to be entered
		cout << "Enter the number of marks: ";
		read(Num_Marks, 1, 50, "Invalid Number of subjects, 1<=ENTRY<=50\nRedo Entry: ");

		// Receive all the marks
		Marks = new Mark[Num_Marks];
		cout << "Please enter " << Num_Marks << " marks:" << endl;
		for (int i = 0; i < Num_Marks; i++) {
			Marks[i].setEmpty();
			Marks[i].set(DSP_LETTER);
			cout << (i + 1) << ": ";

			while (!Marks[i].readName("Subject Name: ", 6) || !Marks[i].read("Mark (mark/outof): ")) {
				cout << "Invalid Entry, retry!" << endl;
				Marks[i].set(DSP_LETTER);
			}
		}
		cout << "Entry Completed!\n" << endl;
	}

	void MarksReport::print() {
		Mark result;
		result.setEmpty();

		double gpa = 0;
		int i, Highest = Marks[0].percent(), Lowest = Marks[0].percent(), Check = 0;

		// 1. Report name
		line(70, '-') << endl;
		cout << Report_Title << endl;
		line(70, '-') << endl;

		// 2. Marks entered:
		cout << "Marks entered:" << endl;

		for (i = 0; i < Num_Marks; i++) {
			Marks[i].display(66) << endl;;

			Check = Marks[i].percent();

			if (Check < Lowest) {
				Lowest = Check;
			}
			else if (Check > Highest) {
				Highest = Check;
			}

			gpa += Marks[i].letterBasedGPA();
		}

		line(70, '-') << endl;

		// 3. Lowest Mark
		result.set(Lowest, 100);
		result.set(DSP_PERCENT);
		result.set("Lowest Mark");
		line(30, ' ');
		result.display(36) << endl;

		// 4. Highest mark
		result.set(Highest, 100);
		result.set(DSP_PERCENT);
		result.set("Highest mark");
		line(30, ' ');
		result.display(36) << endl;

		// 5. GPA
		result.set(gpa / Num_Marks, 4);
		result.set(DSP_GPA);
		result.set("GPA");
		line(30, ' ');
		result.display(36) << endl;
	}

	void MarksReport::terminate() {
		delete[] Marks;
	}

}