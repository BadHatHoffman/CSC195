#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Product
{
public:
	enum class eType
	{
		Album,
		Movie,
		Book
	};

public:
	Product()
	{
		id = uniqueId++;
		type = eType::Album;
	}

	Product(std::string name, int year, float price) {
		this->name = name;
		this->year = year;
		this->price = price;
	}

	eType getType() { return type; }
	int getId() { return id; }
	std::string getName() { return name; }
	void setName(std::string name) { this->name = name; }

	int getYear() { return year; }
	void setYear(int year) { this->year = year; }

	float getPrice() { return price; }
	void setPrice(float price) { this->price = price; }

	virtual void Read(std::istream& istream, std::ostream& ostream);
	virtual void Write(std::ostream& ostream);

	virtual void Read(std::ifstream& istream);
	virtual void Write(std::ofstream& ostream);



protected:
	eType type;
	std::string name;
	int year;
	int id;
	float price;
	static int uniqueId;
};

