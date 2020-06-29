#include "product.h"
#include <iostream>
#include <string>

using namespace std;

int Product::uniqueId = 0;

void Product::Read(std::istream& istream, std::ostream& ostream)
{
	cin.ignore(255, '\n');
	ostream << "Enter Name: ";
	getline(istream, name);
	ostream << "Year: ";
	istream >> year;
	ostream << "Price: ";
	istream >> price;

}

void Product::Write(std::ostream& ostream)
{
	ostream << "Id: " << id << std::endl;
	ostream << "Name: " << name << std::endl;
	ostream << "Year: " << getYear() << std::endl;
	ostream << "Price: " << getPrice() << std::endl;

}

void Product::Read(std::ifstream& istream)
{
	istream >> id;
	istream.ignore(80, '\n');
	getline(istream, name);
}

void Product::Write(std::ofstream& ostream)
{
	ostream << id << std::endl;
	ostream << name << std::endl;
	ostream << year << std::endl;
	ostream << price << std::endl;
}

