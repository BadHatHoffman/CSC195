#pragma once
#include "product.h"
#include <list>

class Products
{
public:
	Products() {}

	void Load(const std::string& filename);
	void Save(const std::string& filename);
	void Display();
	void Display(Product::eType type);
	void Display(int id);
	Product* Create(Product::eType type);
	void Add(Product* product);
	void Remove();
	void Remove(int id);

protected:
	std::list<class Product*> products;
};


