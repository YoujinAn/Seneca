// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:01 Feb, 2020

// Add a new module called PairSummable that represents a Pair with summation and key alignment functionality.

#ifndef SDDS_PAIRSUMMABLE_H__
#define SDDS_PAIRSUMMABLE_H__

#include <iostream>
#include <string>
#include <iomanip>

#include "Pair.h"

using namespace std;

namespace sdds {
	// K: the type of the key
	// V: the type of the value
	template <typename K, typename V>

	class PairSummable : public Pair<K, V> {

		// holds the initial value for starting a summation
		static V init_val;
		// holds the minimum field width for pretty columnar output of key-value pairs (initialize it with 0)
		static size_t width_output;

	public:
		// Static Public Members
		static const V& getInitialValue() {
			return init_val;
		}

		// default constructor
		PairSummable() {
			width_output = 0;
		}

		// stores the pair in the collection, and updates the field width if necessary.
		PairSummable(const K& key, const V& value) : Pair<K, V>(key, value) {
			// size(): returns the number of characters required to display key
			if (width_output < key.size()) {
				width_output = key.size();
			}
		}

		V sum(const K& key, const V& val) const {
			if (Pair<K, V>::key() == key) {
				return Pair<K, V>::value() + val;
			}
			else {
				return val;
			}
		}

		// to set the alignment to left and the field width
		void display(std::ostream& os) const {
			os.setf(ios::left);
			os.width(width_output);
			Pair<K, V>::display(os);
			os.unsetf(ios::left);
		}
	};

	// Specializations
	template<typename K, typename V>
	size_t PairSummable<K, V>::width_output = 0;

	// the initial value for summation should be set to empty string ("").
	template<>
	string PairSummable<string, string> ::init_val = "";

	// the initial value for summation should be set to 0.
	template<>
	int PairSummable <string, int> ::init_val = 0;

	// The sum() should concatenate the values stored using ','
	// as separator (use operator + to concatenate strings).
	template<>
	string PairSummable<string, string> ::sum(const string& key, const string& val) const {
		if (val == "") {
			return Pair<string, string>::value();
		}
		else {
			return (val + ", " + Pair<string, string>::value());
		}
	}

}
#endif // SDDS_PAIRSUMMABLE_H__