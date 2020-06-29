// class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "movie.h"

using namespace std;


int main(){
    Movie movie;
    movie.Write();
    cout << endl;

    Movie Ghostbusters("Ghostbuster", "June 8, 1984", static_cast<Movie::eGenre>(3));
    Ghostbusters.Write();
    cout << endl;

    Movie readMovie;
    readMovie.Read();
    readMovie.Write();
    cout << endl;    
}


