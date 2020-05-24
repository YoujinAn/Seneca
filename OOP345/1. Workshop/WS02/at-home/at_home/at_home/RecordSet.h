// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:25 Jan, 2020

#ifndef SDDS_RECORDSET_H__
#define SDDS_RECORDSET_H__

#include <iostream>
#include <string>
#include <fstream>

namespace sdds {

	// dynamically allocated array
	class RecordSet {
		std::string* records;
		size_t Record_num;

	public:
		RecordSet();							// no-argument default constructor
		RecordSet(const char*);					// 1-argument constructor
		RecordSet(const RecordSet&);			// copy constructor
		RecordSet& operator=(const RecordSet&);	// copy assignment operator
		~RecordSet();							// destructor

		// a query that returns the number of records stored in the current object.
		size_t size() const;
		// a query that returns the record at the index received as parameter.
		std::string getRecord(size_t);

		// move constructor
		RecordSet(RecordSet&& src);
		// move assignment operator
		RecordSet& operator=(RecordSet&& src);
	};
}
#endif // SDDS_RECORDSET_H__