#include<iostream>
#include "movie.h"
#include "product.h"
using namespace std;


void Movie::Read(std::istream& istream, std::ostream& ostream) {

	Product::Read(cin, cout);

	ostream << "Genre (0 = Horror, 1 = Comedy): ";
	int select;
	istream >> select;
	genre = eGenre(select);//static_cast<eGenre>(select);	void Read();

}


void Movie::Write(std::ostream& ostream) {

	Product::Write(cout);

	ostream << "Genre: " << getStingFromEnum(genre) << "\n" << endl;

}

std::string Movie::getStingFromEnum(eGenre genre)
{
	switch (genre)
	{
	case Movie::eGenre::HORROR:
		return "Horror";
		break;
	case Movie::eGenre::COMEDY:
		return "Comedy";
		break;
	default:
		return "";
		break;
	}

	return std::string();
}
