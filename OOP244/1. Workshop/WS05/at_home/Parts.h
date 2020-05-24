/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads IN LAB
//
// File Parts.h

	¢º Name: Youjin An
	¢º Email : auj0827@gmail.com
	¢º Part: at_home
	¢º Date: 2019/10/10

***********************************************************************/

#ifndef SDDS_PARTS_H
#define SDDS_PARTS_H

namespace sdds {

	const int MIN_FORCE = 50;	// to set the minimum force for the Arms
	const int MIN_SPEED = 25;	// to set the minimum speed for the Legs

	class Arms {
		private:
			int force;			// the amount of punch power

		public:
			Arms();				// Default constructor
			Arms(int A_force);	// 1 Argument Constructor

			int getForce() const;

			// Operator Overload Members
			Arms& operator++();
			Arms operator++(int);
			Arms& operator+=(int Passed_int);

	}; // class Arms

	class Legs {
		private:
			int speed;			// the amount speed in the Legs.
		public:
			Legs();				// Default constructor
			Legs(int L_speed);

			int getSpeed() const;

			Legs& operator-=(int Passed_int);
	};

	// Global Helper Operators (Arms, Legs)
	bool operator>(const Legs&, const Legs&);
	bool operator<(const Legs&, const Legs&);
	bool operator>(const Arms&, const Arms&);
	bool operator<(const Arms&, const Arms&);

}
#endif //SDDS_PARTS_H
