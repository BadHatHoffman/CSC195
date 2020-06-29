#include "Products.h"

void Products::Load(const std::string& filename)
{
    // read products from file
    std::ifstream ifile(filename);
    if (ifile.is_open())
    {
        while (!ifile.eof()) //eof means end of file
        {
            if (ifile.peek() == EOF) break;

            Product* product = new Product;
            product->Read(ifile);

            products.push_back(product); //push_back means add object to the list
        }
        ifile.close();
    }
}

void Products::Save(const std::string& filename)
{
    // write products to file
    std::ofstream ofile(filename);
    if (ofile.is_open())
    {
        for (Product* product : products)
        {
            product->Write(ofile);
        }
        ofile.close();
    }
}

void Products::Display()
{
    // write products to console
    for (Product* product : products)
    {
        product->Write(std::cout);
    }
}

void Products::Display(Product::eType type)
{
    // write products to console
    for (Product* product : products)
    {
        if (product->getType() == type)
        {
            product->Write(std::cout);
        }
    }
}

void Products::Display(int id)
{
    // write products to console
    for (Product* product : products)
    {
        if (product->getId() == id)
        {
            product->Write(std::cout);
        }
    }
}

Product* Products::Create(Product::eType type)
{
    Product* product = nullptr;

    switch (type)
    {
    case Product::eType::Album:
        product = new Product; //needs to be album
        break;
    case Product::eType::Movie:
        //product = new Movie;
        break;
    case Product::eType::Book:
        //product = new Book;
        break;
    default:
        break;
    }

    return product;
}

void Products::Add(Product* product)
{
    products.push_back(product);
}

void Products::Remove()
{
    // delete products on heap
    for (Product* product : products)
    {
        delete product;
    }

    // remove products in list
    products.clear();
}

void Products::Remove(int id)
{
    for (std::list<Product*>::iterator iter = products.begin(); iter != products.end(); iter++)
    {
        if ((*iter)->getId() == id)
        {
            delete* iter;

            iter = products.erase(iter);
        }
    }
}
