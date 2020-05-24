// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:13 Feb, 2020

#ifndef SDDS_SPELLCHECKER_H__
#define SDDS_SPELLCHECKER_H__

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

namespace sdds {

	class SpellChecker {
		string m_badWords[5];	// an array with 5 misspelled words
		string m_goodWords[5];	// an array with the correct spelling of those 5 words

	public:
		// a constructor that receives as a parameter the name of the file that contains the misspelled words.
		SpellChecker(const char* filename);
		// search in text if any of the misspelled words appear and replace them with the correct version.
		void operator()(string& text) const;
	};
}
#endif // SDDS_SPELLCHECKER_H__