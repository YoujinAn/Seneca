// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:30 Jan, 2020

#ifndef SDDS_SET_H__
#define SDDS_SET_H__

namespace sdds {
	// `T`: the type of any element in the array
	// `N`: the maximum number of elements in the array (an integer without sign)
	template <class T, int N>

	class Set {
		T a[N]{}; // the capacity of the array (`N`)
		size_t count{}; // Initially the set is empty.

	public:
		size_t size() const {
			return N; //returns the number of elements in the set
		}
		const T& operator[](size_t idx) const {
			return a[idx]; // returns the element at index `i`
		} 
		void operator+=(const T& item) {
			if (count < N) {
				a[count] = item;
				count++;
			}
		} // if the set didn't reach the capacity, add a copy of the parameter to the array. Otherwise, do nothing.
	};
}
#endif // SDDS_SET_H__