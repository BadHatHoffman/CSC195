#include "book.h"
#include "product.h"
#include <iostream>

using namespace std;


void Book::Read() {

	Product::Read();

	cout << "Pages: ";
	cin >> pages;

}


void Book::Write() {

	Product::Write();

	cout << "Pages: " << pages << "\n" << endl;

}


