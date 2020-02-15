// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:13 Feb, 2020

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>  // file open&close

#include "SpellChecker.h"

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		string line;
		string temp[10];
		size_t index = 0;

		if (!file) { // open the file and if had error, throw error message
			throw "Bad file name!";
		}
		do {
			getline(file, line);
			if (line[0] != '\0') {
				temp[index] = line;
				index++;
			}
		} while (file);

		for (size_t i = 0; i < index; i++) {
			auto bad_field = temp[i].find(' '); // find the bad words
			m_badWords[i] = temp[i].substr(0, bad_field); // until white space
			m_badWords[i].erase(0, m_badWords[i].find_first_not_of(" "));
			m_badWords[i].erase(m_badWords[i].find_last_not_of(" ") + 1);


			auto good_field = temp[i].find('\r', bad_field + 1); // find the good words after white space
			m_goodWords[i] = temp[i].substr(bad_field + 1, good_field - bad_field - 1);
			m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(" "));
			m_goodWords[i].erase(m_goodWords[i].find_last_not_of(" ") + 1);
		}

		file.close();
	}

	void SpellChecker::operator()(string& text) const {
		size_t index;
		for (size_t i = 0; i < 5; i++) {
			index = text.find(m_badWords[i]); // find the bad words in the file
			while (index != std::string::npos) {
				text.replace(index, m_badWords[i].size(), m_goodWords[i]); // replace good words
				index = text.find(m_badWords[i]);
			}
		}
	}
}