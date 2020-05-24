/***********************************************************************
// OOP244 Workshop 8: Virtual Functions
//
// File Pen.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: in_lab
	¢º Date: 21 Nov 2019

***********************************************************************/

#ifndef SDDS_PEN_H__
#define SDDS_PEN_H__

#include "WriteInstrument.h"

namespace sdds {

	#define INK_MAX 50	// to set the maximum value of the ink data member

	class Pen : public WriteInstrument {
	private:
		char* style;
		int ink;
	public:
		Pen();
		Pen(const char* style_pen, int ink_pen);
		~Pen();

		void write(const char* test);
		void refill(int ink_pen);
		bool filled() const;

		ostream& display(ostream& os) const;
	};
}
#endif // !SDDS_PEN_H__
