// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:14 March, 2020

// Utilities class is an object used to support the parsing of input files to setup and configure the assembly line simulation.

#ifndef SDDS_UILITIES_H
#define SDDS_UILITIES_H

class Utilities {
private:
	size_t m_widthField;
	static char m_delimiter;

public:
	Utilities();

	void setFieldWidth(size_t);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char);
	const char getDelimiter() const;
};

#endif // #ifndef SDDS_UILITIES_H