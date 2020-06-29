#pragma once
#include "product.h"


class Album : public Product {

public:

	Album() {}
	Album(std::string name, int year, float price, int pages) : Product(name, year, price) {
		this->artist = artist;
	}

	std::string getArtist() { return artist; }
	void setPages(std::string artist) { this->artist = artist; }

	int getNumberOfSongs() { return numberOfSongs; }
	void setNumberOfSongs() { this->numberOfSongs = numberOfSongs; }


	virtual void Read(std::istream& istream, std::ostream& ostream);
	virtual void Write(std::ostream& ostream);


protected:
	std::string artist;
	int numberOfSongs;
};

