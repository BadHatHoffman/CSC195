#include<iostream>
#include "movie.h"
#include "product.h"
using namespace std;


void Movie::Read() {

	Product::Read();
	
	cout << "Genre (0 = Horror, 1 = Comedy): ";
	int select;
	cin >> select;
	genre = eGenre(select);//static_cast<eGenre>(select);	void Read();
	
}


void Movie::Write(){

	Product::Write();

	cout << "Genre: " << getStingFromEnum(genre) << "\n" <<endl;

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




