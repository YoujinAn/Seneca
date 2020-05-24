// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:13 Feb, 2020

#ifndef SDDS_COLLECTION_H__
#define SDDS_COLLECTION_H__

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

namespace sdds {

	template<class T>
	class Collection {

		string nameOfcollection;
		T* arrOfItem;				// a dynamically allocated array of items T
		size_t arr_size;
		void (*c_observer)(const Collection<T>&, const T&);

	public:
		// sets the name of the collection to the parameter and 
		// all other attributes to their default value
		Collection(string name) {
			nameOfcollection = name;
			arrOfItem = nullptr;
			arr_size = 0;
			c_observer = nullptr;
		}

		~Collection() {
			delete[] arrOfItem;
		}

		// a query that returns the name of the collection.
		const string& name() const {
			return nameOfcollection;
		}

		// a query that returns how many items are in the collection.
		size_t size() const {
			return arr_size;
		}

		//Template function
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			c_observer = observer;
		}

		// adds a copy of item to the collection
		Collection<T>& operator+=(const T& item) {
			bool existed = false;
			for (size_t i = 0; i < arr_size && !existed; i++) {
				if (arrOfItem[i].title() == item.title()) {
					existed = true;
				}
			}
			if (!existed) {
				T* tmp = new T[arr_size + 1];
				for (size_t i = 0; i < arr_size; i++) {
					tmp[i] = arrOfItem[i];
				}
				delete[] arrOfItem;
				arrOfItem = tmp;

				arrOfItem[arr_size++] = item;
				if (c_observer != nullptr) {
					c_observer(*this, item);
				}
			}
			return *this;
		}

		// returns the item at index idx
		T& operator[](size_t idx) const {
			if (idx < arr_size)
				return arrOfItem[idx];
			throw std::out_of_range("Bad index [" + std::to_string(idx) +
				"]. Collection has [" + std::to_string(arr_size) + "] items.");
			// we can call use std::exception& e , e.what()
		}

		T* operator[](std::string title) const {
			for (size_t i = 0; i < arr_size; i++) {
				if (title == arrOfItem[i].title())
					return arrOfItem + i;
			}
			return nullptr;
		}
	};

	template <typename T>
	ostream& operator<<(ostream& os, const Collection<T>& obj) {
		for (size_t i = 0; i < obj.size(); i++) {
			os << obj[i];
		}
		return os;
	}
}
#endif // SDDS_COLLECTION_H__