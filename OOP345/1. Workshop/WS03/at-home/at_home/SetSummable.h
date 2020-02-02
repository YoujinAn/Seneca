// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:01 Feb, 2020

#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__

#include <iostream>
#include "Set.h"

namespace sdds {
	// T: the type of any element in the collection
	// N: the maximum number of elements in the collection(an integer without sign)
	// K : the type of a key
	// V : the type summation value
	template<typename T, unsigned int N, typename K, typename V>

	class SetSummable : public Set<T, N> {

	public:
		// accumulates all the values stored in the collection
		V accumulate(const K& key) const {\
			T init_t;
			V local_val = init_t.getInitialValue();

			for (size_t i = 0; i < ((Set<T, N>&)* this).size(); i++) {
				if (key == ((Set<T, N>&)* this)[i].key()) {
					local_val = (*this)[i].sum(key, local_val);
				}
			}

			return local_val;
		}
	};

}
#endif // SDDS_SETSUMMABLE_H__