#pragma once
#include<string>

using namespace std;


class Product {
public:
	Product() {}

	Product(std::string name, int year, float price) {
		this->name = name;
		this->year = year;
		this->price = price;
	}

	string getName() { return name; }
	void setName(string name) { this->name = name; }

	int getYear() { return year; }
	void setYear(int year) { this->year = year; }

	float getPrice() { return price; }
	void setPrice(float price) { this->price = price; }

	virtual void Read();
	virtual void Write();

protected:
	std::string name;
	int year;
	float price;
};
