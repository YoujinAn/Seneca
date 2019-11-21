/***********************************************************************
// OOP244 Workshop 8: Virtual Functions
//
// File Pencil.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: in_lab
	¢º Date: 21 Nov 2019

***********************************************************************/

#ifndef SDDS_PENCIL_H__
#define SDDS_PENCIL_H__

#include "WriteInstrument.h"

namespace sdds {

	#define HB_MAX 2			// to set the maximum length of the HB_scale data member
	#define GRAPHITE_MAX 100	// to set the maximum value of the graphite data member.

	class Pencil : public WriteInstrument {
	private:
		char HB_scale[HB_MAX + 1];
		int graphite;
	public:
		Pencil();
		Pencil(const char* HB_scale_pencil, int graphite_pencil);
		~Pencil();

		void write(const char* text);
		void refill(int refill_graphite);
		bool filled() const;

		ostream& display(ostream& os) const;
	};
}
#endif // !SDDS_PENCIL_H__