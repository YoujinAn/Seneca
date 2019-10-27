/***********************************************************************
// OOP244 Workshop 4: Constructors, Destructors, Current Object AT HOME
// Bouquet.h

	¢º Name: Youjin An
	¢º Part: at_home
	¢º Date: 2019/10/05

***********************************************************************/

#ifndef SDDS_BOUQUET_H_
#define SDDS_BOUQUET_H_

#include "Flower.h"

namespace sdds {

	const int MESS_MAX_LEN = 30;
	const int MAX_FLOWERS = 3;

	class Bouquet {

	private:
		double b_price;
		char* b_message;
		Flower* b_flowers;
		int b_flowerCount;

	public:
		Bouquet();
		Bouquet(const Flower* bflower, int bflowerCount = MAX_FLOWERS, const char* bmessage = "Congratulations");
		~Bouquet();

		void flushKeyboard() const;

		const char* message() const;
		double price() const;
		bool isEmpty()const;
		void setMessage(const char* prompt);
		void setEmpty();
		void discardBouquet();
		void arrangeBouquet();
		ostream& display() const;
	};
}
#endif // SDDS_BOUQUET_H_