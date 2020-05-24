// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion: 12 March, 2020

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <iostream>
#include <string>
#include <vector>

namespace sdds
{
	struct Song {
		std::string s_artist;
		std::string s_title;
		std::string s_album;
		double s_price;
		std::string s_relYears;
		std::string s_length;
	};

	class SongCollection {
	private:
		std::vector<Song> s_Song;

	public:
		SongCollection(const char* is);
		void display(std::ostream& out) const;
	};

	// Free Helpers
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONGCOLLECTION_H
