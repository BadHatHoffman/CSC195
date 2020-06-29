#include "book.h"
#include "product.h"
#include <iostream>

using namespace std;


void Book::Read(std::istream& istream, std::ostream& ostream) {

	Product::Read(cin, cout);
	
	ostream << "Pages: ";
	istream >> pages;
}


void Book::Write(std::ostream& ostream) {

	Product::Write(cout);

	ostream << "Pages: " << pages << "\n" << endl;

}
