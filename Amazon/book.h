#pragma once
#include "product.h"


class Book : public Product{

public:

	Book() {}
	Book(std::string name, int year, float price, int pages) : Product(name, year, price) {
		this->pages = pages;
	}

	int getPages() { return pages; }
	void setPages(int pages) { this->pages = pages;}

	void Read();
	void Write();

protected:
	int pages;
};

