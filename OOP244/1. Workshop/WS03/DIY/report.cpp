/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File report.h

	¢º Name: Youjin An
	¢º Part: DIY
	¢º Date: 2019/09/28

***********************************************************************/

#include "MarksReport.h"

int main() {

   sdds::MarksReport mr;
   mr.initialize();
   mr.getMarks();
   mr.print();
   mr.terminate();

   return 0;

}