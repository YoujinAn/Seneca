// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion: 12 March, 2020

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace sdds
{
	struct Song {
		std::string s_artist;
		std::string s_title;
		std::string s_album;
		double m_price;
		std::string s_relYears;
		size_t s_length;
	};

	class SongCollection {
	private:
		std::vector<Song> s_Song;

	public:
		SongCollection(const char* is);
		void display(std::ostream& out) const;

		void sort(std::string str);
		void cleanAlbum();
		bool inCollection(std::string str) const;
		std::list<Song> getSongsForArtist(std::string str) const;
	};

	// Free Helpers
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONGCOLLECTION_H
