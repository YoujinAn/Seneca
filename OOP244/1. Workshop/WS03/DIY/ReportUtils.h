/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File ReportUtils.h

	�� Name: Youjin An
	�� Part: DIY
	�� Date: 2019/09/28

***********************************************************************/

#ifndef SDDS_REPORTUTILS_H__
#define SDDS_REPORTUTILS_H__

namespace sdds {

	// reads an integer from console the integer referenced by "val"
   // argument.
   // if the user enters an invalid integer or values outside of the 
   // boundries set by "min" or "max" , this function flushes the 
   //keyboard, prints the "errorMessage and reads again
   // untill user enters an acceptable integer

	void read(int& val, int min, int max, const char* errorMessage = "");


	// reads a C style string from console up to "len" characters into the
   // the string pointed by the "str" pointer
   // if the user enters more than "len" characters, this function
   // flushes the keyboard, prints the "errorMessage and reads again
   // untill user enters an acceptable string

	void read(char* str, int len, const char* errorMessage = "");

	ostream& line(int len, char ch);
	ostream& number(int num);
}
#endif