#include "album.h"
#include "product.h"
#include <iostream>

using namespace std;


void Album::Read(std::istream& istream, std::ostream& ostream) {

	Product::Read(cin, cout);

	ostream << "Artist: ";
	istream >> artist;

	ostream << "Number of Songs: ";
	istream >> numberOfSongs;

}


void Album::Write(std::ostream& ostream) {

	Product::Write(cout);

	ostream << "Artist: " << artist << endl;
	ostream << "Number of Songs: " << numberOfSongs << "\n" << endl;

}
