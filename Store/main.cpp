#include "Products.h"
#include "product.h"
#include "movie.h"
#include "book.h"
#include "album.h"
#include<vector>
#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

enum class eAction
{
    QUIT,
    LOAD,
    SAVE,
    DISPLAY_ALL,
    DISPLAY_TYPE,
    DISPLAY_ID,
    ADD,
    REMOVE,
    REMOVE_ALL
};

int main()
{
    bool quit = false;
    int select;
    eAction action;

    Products products;

    do
    {
        //Display Menu
        cout << "Menu" << endl;
        cout << "0 - Quit" << endl;
        cout << "1 - Load" << endl;
        cout << "2 - Save" << endl;
        cout << "3 - Display All" << endl;
        cout << "4 - Display Type" << endl;
        cout << "5 - Display ID" << endl;
        cout << "6 - Add" << endl;
        cout << "7 - Remove" << endl;
        cout << "8 - Remove All" << endl;
       

        //Get Action
        cin >> select;
        cin.ignore(80, '\n');

        action = static_cast<eAction>(select);

        switch (action)
        {
        case eAction::QUIT:
            quit = true;
            break;
        case eAction::LOAD:
        {
            string filename;
            cout << "Enter Filename : ";
            getline(cin, filename);

            products.Load(filename);
        }
        break;
        case eAction::SAVE:
        {
            string filename;
            cout << "Enter Filename : ";
            getline(cin, filename);

            products.Save(filename);
        }
        break;
        case eAction::DISPLAY_ALL:
            products.Display();
            break;
        case eAction::DISPLAY_TYPE:
        {
            int id;
            cout << "Enter Type: ";
            //0 - Album, ...
            cin >> id;
            cin.ignore(80, '\n');
            Product::eType type = static_cast<Product::eType>(id);
            products.Display(type);
        }
        break;
        case eAction::DISPLAY_ID:
        {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(80, '\n');
            products.Display(id);
        }
        break;
        case eAction::ADD:
            //create type
            cout << "Enter Product: 1 = Movie, 2 = Book, 3 = Album, 0 = Return to Main Menu \n";
            cin >> select;
            if (select == 0) {
               
                break;
            }
            else if (select == 1) {
                Movie* movie = new Movie;
                movie->Read(cin, cout);
                products.Add(movie);
            }
            else if (select == 2) {
                Book* book = new Book;
                book->Read(cin, cout);
                products.Add(book);
            }
            else if (select == 3) {
                Album* album = new Album;
                album->Read(cin, cout);
                products.Add(album);
            }
        case eAction::REMOVE:
        {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(80, '\n');
            products.Remove(id);
        }
        break;
        case eAction::REMOVE_ALL:
            products.Remove();
            break;
        default:
            break;
        }

    } while (!quit);
}


