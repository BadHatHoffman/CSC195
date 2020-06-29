#pragma once
#include "product.h"
#include <string>

class Movie : public Product {
public:
	enum class eGenre {
		HORROR,
		COMEDY
	};

public:
	Movie() {}
	Movie(std::string name, int year, float price, int time) : Product(name, year, price) {
		this->time = time;
	}

	int getTime() { return time; }
	void setTime(int time) { this->time = time; }

	virtual void Read(std::istream& istream, std::ostream& ostream);
	virtual void Write(std::ostream& ostream);

	std::string getStingFromEnum(eGenre genre);

protected:
	int time;
	eGenre genre;

};