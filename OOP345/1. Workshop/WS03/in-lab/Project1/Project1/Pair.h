// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:30 Jan, 2020

#ifndef SDDS_PAIR_H__
#define SDDS_PAIR_H__

#include <iostream>

namespace sdds {
	// `K`: the type of the key
	// `V`: the type of the value
	template <typename K, typename V>

	class Pair
	{
	protected:
		K _key{};
		V _val{};
	public:
		// default constructor
		Pair()
		{
			_key = "";
			_val = 0;
		}

		// copies the values received in the parameters into instance variables
		Pair(const K& key, const V& value)
		{
			_key = key;
			_val = value;
		}

		// returns the **key** component of the pair
		const K& key() const {
			return _key;
		}

		// returns the **value** component of the pair
		const V& value() const {
			return _val;
		}

		// inserts into the parameter the key and value of the pair in the following format
		void display(std::ostream& os) const
		{
			os << key() << " : " << value() << std::endl;
		}	
	};

	// calls the function `Pair<L, V>::display()` to insert a pair into the stream.
	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}
#endif // SDDS_PAIR_H__