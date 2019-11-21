/***********************************************************************
// OOP244 Workshop 8: Virtual Functions
//
// File WriteTester.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: in_lab
	¢º Date: 21 Nov 2019

***********************************************************************/

#ifndef SDDS_WRITELNSTRUMENT_H__
#define SDDS_WRITELNSTRUMENT_H__

#include <iostream>
using namespace std;

namespace sdds {

	class WriteInstrument {
	public:
		virtual ~WriteInstrument() { }

		virtual void write(const char*) = 0;
		virtual void refill(int) = 0;
		virtual bool filled() const = 0;

		virtual ostream& display(ostream & os) const = 0;
	};
} // sdds

#endif // !SDDS_WRITELNSTRUMENT_H__