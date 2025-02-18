/***********************************************************************
// OOP244 Workshop 4: read functions for foolproof integer and C string
//                    data entry
// FlowerTester.cpp

	�� Name: Youjin An
	�� Email : auj0827@gmail.com
	�� Part: in_lab
	�� Date: 2019/10/03

***********************************************************************/

#include <iostream>
#include "Flower.h"

using namespace std;
using namespace sdds;

ostream& line(int len, char ch) {
	for (int i = 0; i < len; i++, cout << ch);
	return cout;
}
ostream& number(int num) {
	cout << num;
	for (int i = 0; i < 9; i++) {
		cout << " - " << num;
	}
	return cout;
}

int main() {

	cout << "Testing Empty Flowers" << endl;
	line(64, '-') << endl;
	number(1) << endl;
	Flower f;
	f.display() << endl;

	cout << "Testing Empty Strings" << endl;
	line(64, '-') << endl;
	number(2) << endl;
	Flower f2[2]{ {"Rose", "", 7.5}, {"", "Ruby", 7.8 } };
	f2[0].display();
	f2[1].display() << endl;

	cout << "Testing Non Empty Flowers" << endl;
	line(64, '-') << endl;
	number(3) << endl;
	Flower f3[3]{ {"Rose", "Red", 2.25} ,{"Rose", "Blue", 9.99} , {"Sunflower", "Yellow", 1.25} };
	for (int i = 0; i < 3; i++)
		f3[i].display();

	cout << "\nTesting Setting an Empty Flower" << endl;
	line(64, '-') << endl;
	number(4) << endl;
	Flower f4;
	f4.display();
	f4.setFlower();

	cout << "\nTesting Destructor" << endl;
	line(64, '-') << endl;
	number(5) << endl;

	return 0;
}

/* Expected output

*/