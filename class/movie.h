#pragma once
#include <string>

using namespace std;

class Movie {
public:
	enum class eGenre {
		NOGENRE,
		ACTION,
		DRAMA,
		COMEDY,
		HORROR
	};
public:
	Movie() {
		title = "Unknown";
		releaseDate = "Unknown";
		genre = static_cast<eGenre>(0);
	
	}

	Movie(std::string title_, string releaseDate_, eGenre genre_ ) {
		setTitle(title_);
		setReleaseDate(releaseDate_);
		genre = genre_;
	}

	void Write();
	void Read();

	void setTitle(string title);
	string getTitle();

	void setReleaseDate(string releaseDate);
	string getReleaseDate();

	string getGenre(eGenre);

private:
	string title;
	string releaseDate;
	eGenre genre;	
};
