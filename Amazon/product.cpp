#include "product.h"
#include <iostream>
#include <string>

using namespace std;
string inputString;

void Product::Read(){

	cin.ignore(255, '\n');
	cout << "Name: ";
	getline(cin,name);

	cout << "Year: ";
	cin >> year;
	cout << "Price: ";
	cin >> price;

	cin.clear();


}

void Product::Write() {
	cout << "Name: " << getName() << endl;
	cout << "Year: " << getYear() << endl;
	cout << "Price: " << getPrice() << endl;
}






