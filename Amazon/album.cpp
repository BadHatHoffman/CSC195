#include "album.h"
#include "product.h"
#include <iostream>

using namespace std;


void Album::Read() {

	Product::Read();

	cout << "Artist: ";
	cin >> artist;

	cout << "Number of Songs: ";
	cin >> numberOfSongs;

}


void Album::Write() {

	Product::Write();

	cout << "Artist: " << artist << endl;
	cout << "Number of Songs: " << numberOfSongs << "\n" << endl;

}