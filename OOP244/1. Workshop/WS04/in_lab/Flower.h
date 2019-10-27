/***********************************************************************
// OOP244 Workshop 4: read functions for foolproof integer and C string
//                    data entry
// Flower.h

	¢º Name: Youjin An
	¢º Email : auj0827@gmail.com
	¢º Part: in_lab
	¢º Date: 2019/10/03

***********************************************************************/

#ifndef SDDS_FLOWER_H__
#define SDDS_FLOWER_H__

#include <iostream>

using namespace std;

namespace sdds {

	const int NAME_MAX_LEN = 25;
	const int COL_MAX_LEN = 15;

	class Flower {
		private:
			char* f_name;		// the name of the flower
			char* f_colour;		// the colour of the flower
			double f_price;		// the price of the flower

		public:
			Flower();			// Default constructor
			Flower(const char* fname, const char* fcolour, double fprice);	// 3 Argument Constructor
			~Flower();			// Default Destructor

			const char* name() const;
			const char* colour() const;
			double price() const;
			bool isEmpty()const;
			void setEmpty();
			void setName(const char* prompt);
			void setColour(const char* prompt);
			void setPrice(const char* prompt);
			void setFlower();
			std::ostream& display() const;

	}; // class Flower
}
#endif // SDDS_FLOWER_H__