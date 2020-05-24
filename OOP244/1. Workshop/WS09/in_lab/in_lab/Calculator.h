/***********************************************************************
// OOP244 Workshop 9: Templates
//
// File Calculator.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: in_lab
	¢º Date: 28 Nov 2019

***********************************************************************/

#ifndef SDDS_CALCULATOR_H__
#define SDDS_CALCULATOR_H__

#include <iostream>
using namespace std;

namespace sdds {

	// Generic type, integer parameter
	template <typename T, int N>

	class Calculator {
	private:
		// array of the generic type with an array size of the integer parameter 
		T results[N];
	public:
		Calculator() {
			for (int i = 0; i < N; i++) {
				results[i] = 0;
			}
		}

		void add(const T* first_index, const T* second_index) {
			for (int i = 0; i < N; i++) {
				this->results[i] = first_index[i] + second_index[i];
			}
		}

		void subtract(const T* first_index, const T* second_index) {
			for (int i = 0; i < N; i++) {
				this->results[i] = first_index[i] - second_index[i];
			}
		}

		void multiply(const T* first_index, const T* second_index) {
			for (int i = 0; i < N; i++) {
				this->results[i] = first_index[i] * second_index[i];
			}
		}

		void divide(const T* first_index, const T* second_index) {
			for (int i = 0; i < N; i++) {
				this->results[i] = first_index[i] / second_index[i];
			}
		}

		ostream& display(ostream& os) const {
			for (int i = 0; i < N; i++) {
				os << this->results[i];
				if (i != N - 1) {
					os << ",";
				}
			}

			return os << endl;
		}

		Calculator& operator+=(const T* index) {
			add(this->results, index);
			return *this;
		}

		Calculator& operator-=(const T* index) {
			subtract(this->results, index);
			return *this;
		}

		Calculator& operator*=(const T* index) {
			multiply(this->results, index);
			return *this;
		}

		Calculator& operator/=(const T* index) {
			divide(this->results, index);
			return *this;
		}
	};
}
#endif // !SDDS_CALCULATOR_H__

