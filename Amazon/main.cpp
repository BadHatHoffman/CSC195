// Amazon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "movie.h"
#include "product.h"
#include "book.h"
#include "album.h"
#include<vector>

using namespace std;

int main()
{
    int select;
    std::vector<Product*>products;
    do{
        cout << "Enter Product: 1 = Movie, 2 = Book, 3 = Album, 0 = Print all Products \n";
        cin >> select;
    if (select == 0) {
        
        break;
    }
    else if (select == 1) {
        Movie* movie = new Movie;
        movie->Read();
        products.push_back(movie);
    }
    else if (select == 2) {
        Book* book = new Book;
        book->Read();
        products.push_back(book);
    }
    else if (select == 3) {
        Album* album = new Album;
        album->Read();
        products.push_back(album);
    }
    
    } while (select != 0);
    for (Product* product : products) {
        product->Write();
    }

}