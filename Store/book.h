#pragma once
#include "product.h"


class Book : public Product {

public:

	Book() {}
	Book(std::string name, int year, float price, int pages) : Product(name, year, price) {
		this->pages = pages;
	}

	int getPages() { return pages; }
	void setPages(int pages) { this->pages = pages; }

	virtual void Read(std::istream& istream, std::ostream& ostream);
	virtual void Write(std::ostream& ostream);

protected:
	int pages;
};
