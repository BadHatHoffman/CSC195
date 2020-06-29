#include "movie.h"
#include <iostream>

using namespace std;

string stringInput;
int intInput;

void Movie::Write() {
	cout << "Title: " << getTitle() << endl;
	cout << "Date: " << getReleaseDate() << endl;
	cout << "Genre Type: " << getGenre(genre) << endl;
	
}

void Movie::Read() {
	cout << "Title: ";
	std::getline(std::cin, stringInput);
	setTitle(stringInput);

	cout << "Release Date: ";
	std::getline(std::cin, stringInput);
	setReleaseDate(stringInput);

	cout << "Genre: ";
	cout << "0 - No Genre" << endl;
	cout << "1 - Action" << endl;
	cout << "2 - Drama" << endl;
	cout << "3 - Comedy" << endl;
	cout << "4 - Horror" << endl;
	cin >> intInput;
	Movie::genre = static_cast<eGenre>(intInput);
	
}

void Movie::setTitle(string title){
	this->title = title;
}

string Movie::getTitle() {
	return title;
}

void Movie::setReleaseDate(string releaseDate){
	this->releaseDate = releaseDate;
}

string Movie::getReleaseDate() {
	return releaseDate;
}

string Movie::getGenre(Movie::eGenre) {
	switch (genre)
	{
	case Movie::eGenre::NOGENRE:
		return "No Genre";
		break;
	case Movie::eGenre::ACTION:
		return "Action";
		break;
	case Movie::eGenre::DRAMA:
		return "Drama";
		break;
	case Movie::eGenre::COMEDY:
		return "Comedy";
		break;
	case Movie::eGenre::HORROR:
		return "Horror";
		break;
	default:
		break;
	}
}